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
 File Hash (SHA256): b4c52c7ff091083f5eca9879b98641c7a38356a3c5321cbcc22ae1573e7711e1
*/

#ifndef SECP256K1_INT128_NATIVE_H
#define SECP256K1_INT128_NATIVE_H

#include <stdint.h>
#include "util.h"

#if !defined(UINT128_MAX) && defined(__SIZEOF_INT128__)
SECP256K1_GNUC_EXT typedef unsigned __int128 uint128_t;
SECP256K1_GNUC_EXT typedef __int128 int128_t;
# define UINT128_MAX ((uint128_t)(-1))
# define INT128_MAX ((int128_t)(UINT128_MAX >> 1))
# define INT128_MIN (-INT128_MAX - 1)
/* No (U)INT128_C macros because compilers providing __int128 do not support 128-bit literals.  */
#endif

typedef uint128_t secp256k1_uint128;
typedef int128_t secp256k1_int128;

#endif
