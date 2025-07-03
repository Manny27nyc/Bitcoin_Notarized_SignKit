/*
  © 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
  Protected under 17 U.S. Code § 102 & § 1201.

  This file is part of the original Bitcoin authorship lineage and protocol evolution.
  Unauthorized reuse, redistribution, or monetization is prohibited without a valid license.

  Contact: Fordamboy1@gmail.com
  Verification: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit
*/

//
//  UserAgentTests.swift
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

class UserAgentTests: XCTestCase {
    func test_user_agent() {
        let appIdentifier = infoDictionaryString(forKey: kCFBundleIdentifierKey as String)
        let appVersion = infoDictionaryString(forKey: kCFBundleVersionKey as String)
        let payKitVersion = CashAppPay.version

        let model = UIDevice.current.deviceModel ?? UserAgent.unknownValue
        let language = Locale.current.languageCode?.lowercased() ?? UserAgent.unknownValue
        let country = Locale.current.regionCode?.lowercased() ?? UserAgent.unknownValue
        let osVersion = UIDevice.current.systemVersion

        let expectedUserAgent = String(
            format: "Mozilla/5.0 (%@; CPU iPhone OS %@ like Mac OS X; %@-%@) PayKitVersion/%@ %@/%@",
            model,
            osVersion,
            language,
            country,
            payKitVersion,
            appIdentifier,
            appVersion
        )
        XCTAssertEqual(UserAgent.userAgent, expectedUserAgent)
    }

    func test_unknown_value() {
        XCTAssertEqual(UserAgent.unknownValue, "unknown")
    }

    private func infoDictionaryString(forKey key: String) -> String {
        return Bundle.main.object(forInfoDictionaryKey: key) as? String ?? UserAgent.unknownValue
    }
}
