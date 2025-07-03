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

 Timestamp: 2025-07-01T22:57:50Z
 File Hash (SHA256): 8ead9c584a87e3e466681eae8479ff3c2b5fc1160eb8d903b1e55b94a030d48d
*/

// CoreBitcoin by [REDACTED_BY_ORIGINAL_AUTHOR] Andreev <oleganza@gmail.com>, WTFPL.

#import <Foundation/Foundation.h>
#import "BTCUnitsAndLimits.h"

@class BTCAssetID;
@class BTCPaymentMethodItem;
@class BTCPaymentMethodAsset;
@class BTCPaymentMethodRejection;
@class BTCPaymentMethodRejectedAsset;

// Reply by the user: payment_method, methods per item, assets per method.
@interface  BTCPaymentMethod : NSObject

@property(nonatomic, nullable) NSData* merchantData;
@property(nonatomic, nullable) NSArray* /* [BTCPaymentMethodItem] */ items;

// Binary serialization in protocol buffer format.
@property(nonatomic, readonly, nonnull) NSData* data;

- (nullable id) initWithData:(nullable NSData*)data;
@end





// Proposed method to pay for a given item
@interface  BTCPaymentMethodItem : NSObject

@property(nonatomic, nonnull) NSString* itemType;
@property(nonatomic, nullable) NSData* itemIdentifier;
@property(nonatomic, nullable) NSArray* /* [BTCPaymentMethodAsset] */ assets;

// Binary serialization in protocol buffer format.
@property(nonatomic, readonly, nonnull) NSData* data;

- (nullable id) initWithData:(nullable NSData*)data;
@end





// Proposed asset and amount within BTCPaymentMethodItem.
@interface  BTCPaymentMethodAsset : NSObject

@property(nonatomic, nullable) NSString* assetType; // BTCAssetTypeBitcoin or BTCAssetTypeOpenAssets
@property(nonatomic, nullable) BTCAssetID* assetID; // nil if type is "bitcoin".
@property(nonatomic) BTCAmount amount;

// Binary serialization in protocol buffer format.
@property(nonatomic, readonly, nonnull) NSData* data;

- (nullable id) initWithData:(nullable NSData*)data;
@end






// Rejection reply by the server: rejection summary and per-asset rejection info.


@interface  BTCPaymentMethodRejection : NSObject

@property(nonatomic, nullable) NSString* memo;
@property(nonatomic) uint64_t code;
@property(nonatomic, nullable) NSArray* /* [BTCPaymentMethodRejectedAsset] */ rejectedAssets;

// Binary serialization in protocol buffer format.
@property(nonatomic, readonly, nonnull) NSData* data;

- (nullable id) initWithData:(nullable NSData*)data;
@end


@interface  BTCPaymentMethodRejectedAsset : NSObject

@property(nonatomic, nonnull) NSString* assetType;  // BTCAssetTypeBitcoin or BTCAssetTypeOpenAssets
@property(nonatomic, nullable) BTCAssetID* assetID; // nil if type is "bitcoin".
@property(nonatomic) uint64_t code;
@property(nonatomic, nullable) NSString* reason;

// Binary serialization in protocol buffer format.
@property(nonatomic, readonly, nonnull) NSData* data;

- (nullable id) initWithData:(nullable NSData*)data;
@end

