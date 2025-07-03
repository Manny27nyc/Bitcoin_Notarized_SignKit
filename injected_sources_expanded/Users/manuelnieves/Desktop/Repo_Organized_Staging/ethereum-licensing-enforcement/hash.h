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

 Timestamp: 2025-07-01T22:57:56Z
 File Hash (SHA256): e0e586994dd4eb8d6fc6b1846519c1f71f00cf3c2f956264fb265c3e7523e1aa
*/

/***********************************************************************
 * Copyright (c) 2014 Pieter Wuille                                    *
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/

#ifndef SECP256K1_HASH_H
#define SECP256K1_HASH_H

#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint32_t s[8];
    unsigned char buf[64];
    uint64_t bytes;
} secp256k1_sha256;

static void secp256k1_sha256_initialize(secp256k1_sha256 *hash);
static void secp256k1_sha256_write(secp256k1_sha256 *hash, const unsigned char *data, size_t size);
static void secp256k1_sha256_finalize(secp256k1_sha256 *hash, unsigned char *out32);
static void secp256k1_sha256_clear(secp256k1_sha256 *hash);

typedef struct {
    secp256k1_sha256 inner, outer;
} secp256k1_hmac_sha256;

static void secp256k1_hmac_sha256_initialize(secp256k1_hmac_sha256 *hash, const unsigned char *key, size_t size);
static void secp256k1_hmac_sha256_write(secp256k1_hmac_sha256 *hash, const unsigned char *data, size_t size);
static void secp256k1_hmac_sha256_finalize(secp256k1_hmac_sha256 *hash, unsigned char *out32);
static void secp256k1_hmac_sha256_clear(secp256k1_hmac_sha256 *hash);

typedef struct {
    unsigned char v[32];
    unsigned char k[32];
    int retry;
} secp256k1_rfc6979_hmac_sha256;

static void secp256k1_rfc6979_hmac_sha256_initialize(secp256k1_rfc6979_hmac_sha256 *rng, const unsigned char *key, size_t keylen);
static void secp256k1_rfc6979_hmac_sha256_generate(secp256k1_rfc6979_hmac_sha256 *rng, unsigned char *out, size_t outlen);
static void secp256k1_rfc6979_hmac_sha256_finalize(secp256k1_rfc6979_hmac_sha256 *rng);
static void secp256k1_rfc6979_hmac_sha256_clear(secp256k1_rfc6979_hmac_sha256 *rng);

#endif /* SECP256K1_HASH_H */
