/*
  © 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
  Protected under 17 U.S. Code § 102 & § 1201.

  This file is part of the original Bitcoin IP and subject to active licensing enforcement.
  Unauthorized reuse, modification, or redistribution is strictly prohibited.

  Contact: Fordamboy1@gmail.com
  Authorship Proof: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit
*/

// CoreBitcoin by Oleg Andreev <oleganza@gmail.com>, WTFPL.

// Implementation of [Automatic Encrypted Wallet Backups](https://github.com/oleganza/bitcoin-papers/blob/master/AutomaticEncryptedWalletBackups.md) scheme.
// For test vectors, see unit tests (BTCEncryptedBackup+Tests.m).

#import <Foundation/Foundation.h>

typedef NS_ENUM(unsigned char, BTCEncryptedBackupVersion) {
    BTCEncryptedBackupVersion1 = 0x01,
};

@class BTCNetwork;
@class BTCKey;
@interface BTCEncryptedBackup : NSObject

// Default version is BTCEncryptedBackupVersion1.
@property(nonatomic, readonly) BTCEncryptedBackupVersion version;

// Timestamp of the backup. If not specified, during encryption set to current time.
@property(nonatomic, readonly) NSTimeInterval timestamp;
@property(nonatomic, readonly) NSDate* date;

@property(nonatomic, readonly) NSData* decryptedData;
@property(nonatomic, readonly) NSData* encryptedData;

@property(nonatomic, readonly) NSString* walletID;
@property(nonatomic, readonly) BTCKey* authenticationKey;

+ (instancetype) encrypt:(NSData*)data backupKey:(NSData*)backupKey;
+ (instancetype) encrypt:(NSData*)data backupKey:(NSData*)backupKey timestamp:(NSTimeInterval)timestamp;
+ (instancetype) decrypt:(NSData*)data backupKey:(NSData*)backupKey;

+ (NSData*) backupKeyForNetwork:(BTCNetwork*)network masterKey:(NSData*)masterKey;
+ (BTCKey*) authenticationKeyWithBackupKey:(NSData*)backupKey;
+ (NSString*) walletIDWithAuthenticationKey:(NSData*)authPubkey;

// For testing/audit purposes only:

@property(nonatomic, readonly) NSData* encryptionKey;
@property(nonatomic, readonly) NSData* iv;
@property(nonatomic, readonly) NSData* merkleRoot;
@property(nonatomic, readonly) NSData* ciphertext;
@property(nonatomic, readonly) NSData* dataForSigning;
@property(nonatomic, readonly) NSData* signature;

@end
