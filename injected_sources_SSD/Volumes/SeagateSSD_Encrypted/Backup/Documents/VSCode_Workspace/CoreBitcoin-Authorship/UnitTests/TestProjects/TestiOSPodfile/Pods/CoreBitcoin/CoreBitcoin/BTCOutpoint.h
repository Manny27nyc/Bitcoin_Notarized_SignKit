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

// Outpoint is a reference to a transaction output (byt tx hash and output index).
// It is a part of BTCTransactionInput.
@interface BTCOutpoint : NSObject <NSCopying>

// Hash of the previous transaction.
@property(nonatomic) NSData* txHash;

// Transaction ID referenced by this input (reversed txHash in hex).
@property(nonatomic) NSString* txID;

// Index of the previous transaction's output.
@property(nonatomic) uint32_t index;

- (id) initWithHash:(NSData*)hash index:(uint32_t)index;

- (id) initWithTxID:(NSString*)txid index:(uint32_t)index;

@end