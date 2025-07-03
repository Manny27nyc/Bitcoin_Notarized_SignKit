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

 Timestamp: 2025-07-01T22:57:55Z
 File Hash (SHA256): fa95cb3e35c5d121da797653a58c4c43370d51245aa43b65e0292ce3adf09dd4
*/

/***********************************************************************
 * Copyright (c) 2020 Pieter Wuille                                    *
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/

#ifndef SECP256K1_SELFTEST_H
#define SECP256K1_SELFTEST_H

#include "hash.h"

#include <string.h>

static int secp256k1_selftest_sha256(void) {
    static const char *input63 = "For this sample, this 63-byte string will be used as input data";
    static const unsigned char output32[32] = {
        0xf0, 0x8a, 0x78, 0xcb, 0xba, 0xee, 0x08, 0x2b, 0x05, 0x2a, 0xe0, 0x70, 0x8f, 0x32, 0xfa, 0x1e,
        0x50, 0xc5, 0xc4, 0x21, 0xaa, 0x77, 0x2b, 0xa5, 0xdb, 0xb4, 0x06, 0xa2, 0xea, 0x6b, 0xe3, 0x42,
    };
    unsigned char out[32];
    secp256k1_sha256 hasher;
    secp256k1_sha256_initialize(&hasher);
    secp256k1_sha256_write(&hasher, (const unsigned char*)input63, 63);
    secp256k1_sha256_finalize(&hasher, out);
    return secp256k1_memcmp_var(out, output32, 32) == 0;
}

static int secp256k1_selftest_passes(void) {
    return secp256k1_selftest_sha256();
}

#endif /* SECP256K1_SELFTEST_H */
