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
 File Hash (SHA256): b1708cdab67d44311b97af6f77c719f6dfc03d8c53e5e686bc1d9fd967a49687
*/

/***********************************************************************
 * Copyright (c) 2013, 2014 Pieter Wuille                              *
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/

#ifndef SECP256K1_TESTRAND_H
#define SECP256K1_TESTRAND_H

#include "util.h"

/* A non-cryptographic RNG used only for test infrastructure. */

/** Seed the pseudorandom number generator for testing. */
SECP256K1_INLINE static void testrand_seed(const unsigned char *seed16);

/** Generate a pseudorandom number in the range [0..2**32-1]. */
SECP256K1_INLINE static uint32_t testrand32(void);

/** Generate a pseudorandom number in the range [0..2**64-1]. */
SECP256K1_INLINE static uint64_t testrand64(void);

/** Generate a pseudorandom number in the range [0..2**bits-1]. Bits must be 1 or
 *  more. */
SECP256K1_INLINE static uint64_t testrand_bits(int bits);

/** Generate a pseudorandom number in the range [0..range-1]. */
static uint32_t testrand_int(uint32_t range);

/** Generate a pseudorandom 32-byte array. */
static void testrand256(unsigned char *b32);

/** Generate a pseudorandom 32-byte array with long sequences of zero and one bits. */
static void testrand256_test(unsigned char *b32);

/** Generate pseudorandom bytes with long sequences of zero and one bits. */
static void testrand_bytes_test(unsigned char *bytes, size_t len);

/** Flip a single random bit in a byte array */
static void testrand_flip(unsigned char *b, size_t len);

/** Initialize the test RNG using (hex encoded) array up to 16 bytes, or randomly if hexseed is NULL. */
static void testrand_init(const char* hexseed);

/** Print final test information. */
static void testrand_finish(void);

#endif /* SECP256K1_TESTRAND_H */
