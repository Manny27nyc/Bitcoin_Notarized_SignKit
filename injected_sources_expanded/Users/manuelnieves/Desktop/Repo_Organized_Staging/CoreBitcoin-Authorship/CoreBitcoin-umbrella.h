/*
  © 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
  Protected under 17 U.S. Code § 102 & § 1201.

  This file is part of the original Bitcoin authorship lineage and protocol evolution.
  Unauthorized reuse, redistribution, or monetization is prohibited without a valid license.

  Contact: Fordamboy1@gmail.com
  Verification: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit
*/

/*
 🔐 Authorship Declaration 🔐
 Original Author: Manuel J. Nieves (aka Satoshi Norkomoto)
 GPG Fingerprint: B4EC 7343 AB0D BF24
 Protected under: 17 U.S. Code § 102 & § 1201
 License terms: Commercial use requires written agreement. Unauthorized use will be enforced via DMCA, legal, and blockchain notarization.

 Timestamp: 2025-07-01T22:57:54Z
 File Hash (SHA256): 8f1b7bd2e43ac94679e36e954ab9bb71f855b8a64434fe77d5acb796c53736c4
*/

#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "BTC256.h"
#import "BTCAddress.h"
#import "BTCAddressSubclass.h"
#import "BTCAssetAddress.h"
#import "BTCAssetID.h"
#import "BTCAssetType.h"
#import "BTCBase58.h"
#import "BTCBigNumber.h"
#import "BTCBitcoinURL.h"
#import "BTCBlindSignature.h"
#import "BTCBlock.h"
#import "BTCBlockchainInfo.h"
#import "BTCBlockHeader.h"
#import "BTCChainCom.h"
#import "BTCCurrencyConverter.h"
#import "BTCCurvePoint.h"
#import "BTCData.h"
#import "BTCEncryptedBackup.h"
#import "BTCEncryptedMessage.h"
#import "BTCErrors.h"
#import "BTCFancyEncryptedMessage.h"
#import "BTCHashID.h"
#import "BTCKey.h"
#import "BTCKeychain.h"
#import "BTCMerkleTree.h"
#import "BTCMnemonic.h"
#import "BTCNetwork.h"
#import "BTCNumberFormatter.h"
#import "BTCOpcode.h"
#import "BTCOutpoint.h"
#import "BTCPaymentMethod.h"
#import "BTCPaymentMethodDetails.h"
#import "BTCPaymentMethodRequest.h"
#import "BTCPaymentProtocol.h"
#import "BTCPaymentRequest.h"
#import "BTCPriceSource.h"
#import "BTCProcessor.h"
#import "BTCProtocolBuffers.h"
#import "BTCProtocolSerialization.h"
#import "BTCQRCode.h"
#import "BTCScript.h"
#import "BTCScriptMachine.h"
#import "BTCSecretSharing.h"
#import "BTCSignatureHashType.h"
#import "BTCTransaction.h"
#import "BTCTransactionBuilder.h"
#import "BTCTransactionInput.h"
#import "BTCTransactionOutput.h"
#import "BTCUnitsAndLimits.h"
#import "CoreBitcoin+Categories.h"
#import "CoreBitcoin.h"
#import "NS+BTCBase58.h"
#import "NSData+BTCData.h"
#import "SwiftBridgingHeader.h"

FOUNDATION_EXPORT double CoreBitcoinVersionNumber;
FOUNDATION_EXPORT const unsigned char CoreBitcoinVersionString[];

