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

/*!
 * Converts string transaction or block ID (reversed tx hash in hex format) to binary hash.
 */
NSData* BTCHashFromID(NSString* identifier);

/*!
 * Converts hash of the transaction or block to its string ID (reversed hash in hex format).
 */
NSString* BTCIDFromHash(NSData* hash);
