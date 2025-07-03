/*
  © 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
  Protected under 17 U.S. Code § 102 & § 1201.

  This file is part of the original Bitcoin authorship lineage and protocol evolution.
  Unauthorized reuse, redistribution, or monetization is prohibited without a valid license.

  Contact: Fordamboy1@gmail.com
  Verification: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit
*/

//
//  StateMachineTests.swift
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

@testable import PayKit
import XCTest

class StateMachineTests: XCTestCase {

    // MARK: - State Changes + Network Calls
    func test_state_creatingCustomerRequest() throws {
        let mockNetworkManager = MockNetworkManager()
        let stateMachine = StateMachine(networkManager: mockNetworkManager, analyticsService: MockAnalytics())
        stateMachine.state = .creatingCustomerRequest(TestValues.createCustomerRequestParams)
        XCTAssertEqual(mockNetworkManager.createCustomerRequestCount, 1)
    }

    func test_state_updatingCustomerRequest() throws {
        let mockNetworkManager = MockNetworkManager()
        let stateMachine = StateMachine(networkManager: mockNetworkManager, analyticsService: MockAnalytics())
        stateMachine.state = .updatingCustomerRequest(
            request: TestValues.customerRequest,
            params: TestValues.updateCustomerRequestParams
        )
        XCTAssertEqual(mockNetworkManager.updateCustomerRequestCount, 1)
    }

    func test_state_polling() throws {
        let mockNetworkManager = MockNetworkManager()
        let stateMachine = StateMachine(networkManager: mockNetworkManager, analyticsService: MockAnalytics())
        stateMachine.state = .polling(TestValues.customerRequest)
        XCTAssertEqual(mockNetworkManager.retrieveCustomerRequestCount, 1)
    }

    func test_refresh_retrieveCustomerRequest() {
        let mockNetworkManager = MockNetworkManager()
        let stateMachine = StateMachine(networkManager: mockNetworkManager, analyticsService: MockAnalytics())
        stateMachine.state = .refreshing(TestValues.customerRequest)
        XCTAssertEqual(mockNetworkManager.retrieveCustomerRequestCount, 1)
    }

    // MARK: - Setting State for Errors
    func test_setStateForError() throws {
        let stateMachine = StateMachine(networkManager: MockNetworkManager(), analyticsService: MockAnalytics())

        XCTAssertEqual(stateMachine.state, .notStarted)

        let apiError = APIError(category: .API_ERROR, code: .INTERNAL_SERVER_ERROR, detail: nil, field: nil)
        stateMachine.setErrorState(apiError)
        XCTAssertEqual(stateMachine.state, .apiError(apiError))

        let integrationError = IntegrationError(
            category: .AUTHENTICATION_ERROR,
            code: .UNAUTHORIZED,
            detail: nil,
            field: nil
        )
        stateMachine.setErrorState(integrationError)
        XCTAssertEqual(stateMachine.state, .integrationError(integrationError))

        let networkError = NetworkError.noResponse
        stateMachine.setErrorState(networkError)
        XCTAssertEqual(stateMachine.state, .networkError(networkError))

        let unexpectedError = UnexpectedError.emptyErrorArray
        stateMachine.setErrorState(unexpectedError)
        XCTAssertEqual(stateMachine.state, .unexpectedError(unexpectedError))
    }

    // MARK: - Redirect Notification Handling
    func test_handleRedirectNotification() throws {
        let stateMachine = StateMachine(networkManager: MockNetworkManager(), analyticsService: MockAnalytics())
        let customerRequest = TestValues.customerRequest

        // The state machine should advance to .polling if we're in .redirecting.
        stateMachine.state = .redirecting(customerRequest)
        NotificationCenter.default.post(name: CashAppPay.RedirectNotification, object: nil)
        XCTAssertEqual(stateMachine.state, .polling(customerRequest))

        // The state machine should also advance to .polling if we're in .readyToAuthorize;
        // it's unexpected, but we can continue.
        stateMachine.state = .readyToAuthorize(customerRequest)
        NotificationCenter.default.post(name: CashAppPay.RedirectNotification, object: nil)
        XCTAssertEqual(stateMachine.state, .polling(customerRequest))

        // If we're in any other state, we shouldn't advance.
        stateMachine.state = .notStarted
        NotificationCenter.default.post(name: CashAppPay.RedirectNotification, object: nil)
        XCTAssertEqual(stateMachine.state, .notStarted)

        stateMachine.state = .creatingCustomerRequest(TestValues.createCustomerRequestParams)
        NotificationCenter.default.post(name: CashAppPay.RedirectNotification, object: nil)
        XCTAssertEqual(stateMachine.state, .creatingCustomerRequest(TestValues.createCustomerRequestParams))
    }

    // MARK: - Polling Timer
    func test_polling_timer() throws {
        let stateMachine = StateMachine(networkManager: MockNetworkManager(), analyticsService: MockAnalytics())
        stateMachine.state = .redirecting(TestValues.customerRequest)
        XCTAssertNil(stateMachine.pollingTimer)

        stateMachine.state = .polling(TestValues.customerRequest)
        XCTAssertNotNil(stateMachine.pollingTimer)

        stateMachine.state = .declined(TestValues.customerRequest)
        XCTAssertNil(stateMachine.pollingTimer)
    }

    // MARK: - Refresh
    func test_whenRefreshSucceeds_thenTransitionsToRedirect() {
        let refreshedCustomerRequest = TestValues.customerRequest
        let networkManager = MockNetworkManager { _, retryPolicy, response in
            self.XCTAssertEqual(retryPolicy, .exponential(delay: 3, maximumNumberOfAttempts: 3))
            response(.success(refreshedCustomerRequest))
        }

        let stateMachine = StateMachine(networkManager: networkManager, analyticsService: MockAnalytics())
        stateMachine.state = .refreshing(TestValues.customerRequest)

        XCTAssertEqual(stateMachine.state, .redirecting(refreshedCustomerRequest))
    }

    func test_whenRefreshFails_thenTransitionsToError() {
        let networkManager = MockNetworkManager { _, _, response in
            response(.failure(TestValues.internalServerError))
        }

        let stateMachine = StateMachine(networkManager: networkManager, analyticsService: MockAnalytics())
        stateMachine.state = .refreshing(TestValues.customerRequest)

        XCTAssertEqual(stateMachine.state, .apiError(TestValues.internalServerError))
    }

    // MARK: - Foreground Handling
    func test_foregroundHandling() throws {
        let stateMachine = StateMachine(networkManager: MockNetworkManager(), analyticsService: MockAnalytics())

        stateMachine.state = .readyToAuthorize(TestValues.customerRequest)
        XCTAssertNil(stateMachine.notificationObserver)

        // If we're in .redirecting, we should be handling foreground notifications.
        stateMachine.state = .redirecting(TestValues.customerRequest)
        XCTAssertNotNil(stateMachine.notificationObserver)

        stateMachine.state = .polling(TestValues.customerRequest)
        XCTAssertNil(stateMachine.notificationObserver)

        stateMachine.state = .declined(TestValues.customerRequest)
        XCTAssertNil(stateMachine.notificationObserver)
    }
}

class MockAnalytics: AnalyticsService {
    var trackStub: ((AnalyticsEvent) throws -> Void)

    init(trackStub: @escaping (AnalyticsEvent) throws -> Void = { _ in }) {
        self.trackStub = trackStub
    }

    func track(_ event: AnalyticsEvent) {
        do {
            try trackStub(event)
        } catch {
            XCTFail("Unexpectedly threw an error")
        }
    }
}

class MockNetworkManager: NetworkManager {
    typealias Response = (String, RetryPolicy?, (Result<CustomerRequest, Error>) -> Void) -> Void

    var retrieveCustomerRequest: Response = { _, _, _  in }

    var createCustomerRequestCount: Int = 0
    var updateCustomerRequestCount: Int = 0
    var retrieveCustomerRequestCount: Int = 0

    convenience init(retrieveCustomerRequest: @escaping Response = { _, _, _ in }) {
        self.init(clientID: "test_client", endpoint: .sandbox)
        self.retrieveCustomerRequest = retrieveCustomerRequest
    }

    override func createCustomerRequest(
        params: CreateCustomerRequestParams,
        completionHandler: @escaping (Result<CustomerRequest, Error>) -> Void
    ) {
        createCustomerRequestCount += 1
    }

    override func updateCustomerRequest(
        _ request: CustomerRequest,
        with params: UpdateCustomerRequestParams,
        completionHandler: @escaping (Result<CustomerRequest, Error>) -> Void
    ) {
        updateCustomerRequestCount += 1
    }

    override func retrieveCustomerRequest(
        id: String,
        retryPolicy: RetryPolicy?,
        completionHandler: @escaping (Result<CustomerRequest, Error>) -> Void
    ) {
        retrieveCustomerRequest(id, retryPolicy, completionHandler)
        retrieveCustomerRequestCount += 1
    }
}
