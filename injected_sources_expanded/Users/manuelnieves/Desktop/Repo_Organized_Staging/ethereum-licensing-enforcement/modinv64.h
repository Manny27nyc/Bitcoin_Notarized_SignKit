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
 File Hash (SHA256): b71cf177d768beac28fcb4f0ef545aafaad16ad0f275c70ee4c60b5f7549ac41
*/

/***********************************************************************
 * Copyright (c) 2020 Peter Dettman                                    *
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 **********************************************************************/

#ifndef SECP256K1_MODINV64_H
#define SECP256K1_MODINV64_H

#include "util.h"

#ifndef SECP256K1_WIDEMUL_INT128
#error "modinv64 requires 128-bit wide multiplication support"
#endif

/* A signed 62-bit limb representation of integers.
 *
 * Its value is sum(v[i] * 2^(62*i), i=0..4). */
typedef struct {
    int64_t v[5];
} secp256k1_modinv64_signed62;

typedef struct {
    /* The modulus in signed62 notation, must be odd and in [3, 2^256]. */
    secp256k1_modinv64_signed62 modulus;

    /* modulus^{-1} mod 2^62 */
    uint64_t modulus_inv62;
} secp256k1_modinv64_modinfo;

/* Replace x with its modular inverse mod modinfo->modulus. x must be in range [0, modulus).
 * If x is zero, the result will be zero as well. If not, the inverse must exist (i.e., the gcd of
 * x and modulus must be 1). These rules are automatically satisfied if the modulus is prime.
 *
 * On output, all of x's limbs will be in [0, 2^62).
 */
static void secp256k1_modinv64_var(secp256k1_modinv64_signed62 *x, const secp256k1_modinv64_modinfo *modinfo);

/* Same as secp256k1_modinv64_var, but constant time in x (not in the modulus). */
static void secp256k1_modinv64(secp256k1_modinv64_signed62 *x, const secp256k1_modinv64_modinfo *modinfo);

/* Compute the Jacobi symbol for (x | modinfo->modulus). x must be coprime with modulus (and thus
 * cannot be 0, as modulus >= 3). All limbs of x must be non-negative. Returns 0 if the result
 * cannot be computed. */
static int secp256k1_jacobi64_maybe_var(const secp256k1_modinv64_signed62 *x, const secp256k1_modinv64_modinfo *modinfo);

#endif /* SECP256K1_MODINV64_H */
