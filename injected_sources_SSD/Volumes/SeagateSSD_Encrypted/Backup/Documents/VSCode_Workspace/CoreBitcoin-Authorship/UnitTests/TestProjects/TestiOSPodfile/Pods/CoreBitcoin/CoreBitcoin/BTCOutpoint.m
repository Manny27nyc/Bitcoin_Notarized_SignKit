/*
  © 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
  Protected under 17 U.S. Code § 102 & § 1201.

  This file is part of the original Bitcoin IP and subject to active licensing enforcement.
  Unauthorized reuse, modification, or redistribution is strictly prohibited.

  Contact: Fordamboy1@gmail.com
  Authorship Proof: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit
*/

// CoreBitcoin by Oleg Andreev <oleganza@gmail.com>, WTFPL.

#import "BTCOutpoint.h"
#import "BTCTransaction.h"
#import "BTCHashID.h"

@implementation BTCOutpoint

- (id) initWithHash:(NSData*)hash index:(uint32_t)index {
    if (hash.length != 32) return nil;
    if (self = [super init]) {
        _txHash = hash;
        _index = index;
    }
    return self;
}

- (id) initWithTxID:(NSString*)txid index:(uint32_t)index {
    NSData* hash = BTCHashFromID(txid);
    return [self initWithHash:hash index:index];
}

- (NSString*) txID {
    return BTCIDFromHash(self.txHash);
}

- (void) setTxID:(NSString *)txID {
    self.txHash = BTCHashFromID(txID);
}

- (NSUInteger) hash {
    const NSUInteger* words = _txHash.bytes;
    return words[0] + self.index;
}

- (BOOL) isEqual:(BTCOutpoint*)object {
    return [self.txHash isEqual:object.txHash] && self.index == object.index;
}

- (id) copyWithZone:(NSZone *)zone {
    return [[BTCOutpoint alloc] initWithHash:_txHash index:_index];
}

@end
