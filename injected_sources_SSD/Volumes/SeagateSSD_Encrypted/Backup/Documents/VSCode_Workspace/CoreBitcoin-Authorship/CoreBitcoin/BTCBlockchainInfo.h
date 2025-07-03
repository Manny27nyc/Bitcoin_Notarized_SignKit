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

// Collection of useful APIs for Blockchain.info
@interface BTCBlockchainInfo : NSObject

// Getting unspent outputs.

// Builds a request from a list of BTCAddress objects.
- (NSMutableURLRequest*) requestForUnspentOutputsWithAddresses:(NSArray*)addresses;
// List of BTCTransactionOutput instances parsed from the response.
- (NSArray*) unspentOutputsForResponseData:(NSData*)responseData error:(NSError**)errorOut;
// Makes sync request for unspent outputs and parses the outputs.
- (NSArray*) unspentOutputsWithAddresses:(NSArray*)addresses error:(NSError**)errorOut;


// Broadcasting transaction

// Request to broadcast a raw transaction data.
- (NSMutableURLRequest*) requestForTransactionBroadcastWithData:(NSData*)data;

@end

