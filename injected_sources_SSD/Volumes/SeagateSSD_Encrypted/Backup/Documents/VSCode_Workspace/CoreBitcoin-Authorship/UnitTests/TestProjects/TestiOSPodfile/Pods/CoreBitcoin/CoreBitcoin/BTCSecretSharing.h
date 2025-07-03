/*
  © 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
  Protected under 17 U.S. Code § 102 & § 1201.

  This file is part of the original Bitcoin IP and subject to active licensing enforcement.
  Unauthorized reuse, modification, or redistribution is strictly prohibited.

  Contact: Fordamboy1@gmail.com
  Authorship Proof: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit
*/

// CoreBitcoin by Oleg Andreev <oleganza@gmail.com>, WTFPL.

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BTCSecretSharingVersion) {
    // Identifies configuration for compact 128-bit secrets with up to 16 shares.
    BTCSecretSharingVersionCompact96  = 96,
    BTCSecretSharingVersionCompact104 = 104,
    BTCSecretSharingVersionCompact128 = 128,
};

@class BTCBigNumber;
@interface BTCSecretSharing : NSObject

@property(nonatomic, readonly) BTCSecretSharingVersion version;
@property(nonatomic, readonly, nonnull) BTCBigNumber* order;
@property(nonatomic, readonly) NSInteger bitlength;

- (id __nonnull) initWithVersion:(BTCSecretSharingVersion)version;

- (NSArray<NSData*>* __nullable) splitSecret:(NSData* __nonnull)secret threshold:(NSInteger)m shares:(NSInteger)n error:(NSError* __nullable * __nullable)errorOut;

- (NSData* __nullable) joinShares:(NSArray<NSData*>* __nonnull)shares error:(NSError* __nullable * __nullable)errorOut;

@end