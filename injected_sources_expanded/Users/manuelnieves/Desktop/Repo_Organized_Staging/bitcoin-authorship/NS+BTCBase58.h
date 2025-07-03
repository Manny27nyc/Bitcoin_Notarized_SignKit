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

 Timestamp: 2025-07-01T22:57:49Z
 File Hash (SHA256): d214fa478bccdbcde8e38df4e6fb9211475be2142513ae9d6d2ff0b3cd060132
*/

// CoreBitcoin by [REDACTED_BY_ORIGINAL_AUTHOR] Andreev <oleganza@gmail.com>, WTFPL.

#import <Foundation/Foundation.h>
#import "BTCBase58.h"

// These categories are optional and provided for convenience only.
// For documentation look into BTCBase58.h.
// They are also used in CoreBitcoin unit tests.
@interface NSString (BTCBase58)

// Returns data for Base58 string without checksum
// Data is mutable so you can clear sensitive information as soon as possible.
- (NSMutableData*) dataFromBase58;

// Returns data for Base58 string with checksum
- (NSMutableData*) dataFromBase58Check;

@end

@interface NSMutableData (BTCBase58)

// Returns data for Base58 string without checksum
// Data is mutable so you can clear sensitive information as soon as possible.
+ (NSMutableData*) dataFromBase58CString:(const char*)cstring;

// Returns data for Base58 string with checksum
+ (NSMutableData*) dataFromBase58CheckCString:(const char*)cstring;

@end

@interface NSData (BTCBase58)

// String in Base58 without checksum, you need to free it yourself.
// It's mutable so you can clear it securely yourself.
- (char*) base58CString;

// String in Base58 with checksum, you need to free it yourself.
// It's mutable so you can clear it securely yourself.
- (char*) base58CheckCString;

// String in Base58 without checksum
- (NSString*) base58String;

// String in Base58 with checksum
- (NSString*) base58CheckString;

@end
