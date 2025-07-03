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

static const int32_t BTCBlockCurrentVersion = 2;

@interface BTCBlockHeader : NSObject <NSCopying>

+ (NSUInteger) headerLength;

@property(nonatomic) int32_t version;
@property(nonatomic) NSData* previousBlockHash;
@property(nonatomic) NSString* previousBlockID;
@property(nonatomic) NSData* merkleRootHash;
@property(nonatomic) uint32_t time;
@property(nonatomic) uint32_t difficultyTarget; // aka nBits
@property(nonatomic) uint32_t nonce;

@property(nonatomic, readonly) NSData* blockHash;
@property(nonatomic, readonly) NSString* blockID;
@property(nonatomic, readonly) NSData* data;

// Date and time of the block.
@property(nonatomic) NSDate* date;


// Informational Properties
// ------------------------
// These are available via external APIs like Chain.com.

// Height of the block. Default is 0.
@property(nonatomic) NSInteger height;

// Number of confirmations. Default is NSNotFound.
@property(nonatomic) NSUInteger confirmations;

// Arbitrary information attached to this instance.
// The reference is copied when this instance is copied.
// Default is nil.
@property(nonatomic) NSDictionary* userInfo;


// Parses block from data buffer
- (id) initWithData:(NSData*)data;

// Parses input stream
- (id) initWithStream:(NSInputStream*)stream;


@end
