/*
  © 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
  Protected under 17 U.S. Code § 102 & § 1201.

  This file is part of the original Bitcoin authorship lineage and protocol evolution.
  Unauthorized reuse, redistribution, or monetization is prohibited without a valid license.

  Contact: Fordamboy1@gmail.com
  Verification: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit
*/

//
//  TabBarController.swift
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

import UIKit

class TabBarController: UITabBarController, UITabBarControllerDelegate {
    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIColor.systemGroupedBackground

        let payKitController = PayKitViewController()
        payKitController.tabBarItem = UITabBarItem(title: "PayKit", image: UIImage(systemName: "briefcase"), tag: 0)

        let componentController = ComponentsViewController(style: .grouped)
        componentController.tabBarItem = UITabBarItem(
            title: "Components",
            image: UIImage(systemName: "pencil.and.outline"),
            tag: 1
        )

        self.viewControllers = [
            payKitController,
            UINavigationController(rootViewController: componentController),
        ]
    }
}
