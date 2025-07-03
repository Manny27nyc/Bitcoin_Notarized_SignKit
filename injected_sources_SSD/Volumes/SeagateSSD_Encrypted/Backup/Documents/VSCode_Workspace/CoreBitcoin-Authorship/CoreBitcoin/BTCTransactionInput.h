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

@class BTCScript;
@class BTCTransaction;

// Transaction input (aka "txin") represents a reference to another transaction's output.
// Reference is defined by tx hash + tx output index.
// Signature script is used to prove ownership of the corresponding tx output.
// Sequence is used to require different signatures when tx is updated. It is only relevant when tx lockTime > 0.
@interface BTCTransactionInput : NSObject <NSCopying>

// Hash of the previous transaction.
@property(nonatomic) NSData* previousHash;

// Index of the previous transaction's output.
@property(nonatomic) uint32_t previousIndex;

// Script that proves ownership of the previous transaction output.
@property(nonatomic) BTCScript* signatureScript;

// Input sequence. Default is maximum value 0xFFFFFFFF.
// Sequence is used to update a timelocked tx stored in memory of the nodes. It is only relevant when tx lockTime > 0.
// Currently, for DoS and security reasons, nodes do not store timelocked transactions making the sequence number meaningless.
@property(nonatomic) uint32_t sequence;

// Serialized binary representation of the txin.
@property(nonatomic, readonly) NSData* data;

// Set when input is added via [tx addInput:input]
@property(weak, nonatomic) BTCTransaction* transaction;

// Parses tx input from a data buffer.
- (id) initWithData:(NSData*)data;

// Read tx input from the stream.
- (id) initWithStream:(NSInputStream*)stream;

// Constructs transaction input from a dictionary representation
- (id) initWithDictionary:(NSDictionary*)dictionary;

// Returns a dictionary representation suitable for encoding in JSON or Plist.
- (NSDictionary*) dictionaryRepresentation;

// Returns YES if this txin generates new coins.
- (BOOL) isCoinbase;

@end
