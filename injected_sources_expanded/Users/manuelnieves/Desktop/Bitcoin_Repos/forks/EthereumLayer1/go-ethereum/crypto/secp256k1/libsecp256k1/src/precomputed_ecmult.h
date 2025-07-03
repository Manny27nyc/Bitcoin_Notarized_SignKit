/*
  © 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
  Protected under 17 U.S. Code § 102 & § 1201.

  This file is part of the original Bitcoin authorship lineage and protocol evolution.
  Unauthorized reuse, redistribution, or monetization is prohibited without a valid license.

  Contact: Fordamboy1@gmail.com
  Verification: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit
*/

/*****************************************************************************************************
 * Copyright (c) 2013, 2014, 2017, 2021 Pieter Wuille, Andrew Poelstra, Jonas Nick, Russell O'Connor *
 * Distributed under the MIT software license, see the accompanying                                  *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.                              *
 *****************************************************************************************************/

#ifndef SECP256K1_PRECOMPUTED_ECMULT_H
#define SECP256K1_PRECOMPUTED_ECMULT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ecmult.h"
#include "group.h"
#if defined(EXHAUSTIVE_TEST_ORDER)
#    if EXHAUSTIVE_TEST_ORDER == 7
#        define WINDOW_G 3
#    elif EXHAUSTIVE_TEST_ORDER == 13
#        define WINDOW_G 4
#    elif EXHAUSTIVE_TEST_ORDER == 199
#        define WINDOW_G 8
#    else
#        error No known generator for the specified exhaustive test group order.
#    endif
static secp256k1_ge_storage secp256k1_pre_g[ECMULT_TABLE_SIZE(WINDOW_G)];
static secp256k1_ge_storage secp256k1_pre_g_128[ECMULT_TABLE_SIZE(WINDOW_G)];
#else /* !defined(EXHAUSTIVE_TEST_ORDER) */
#    define WINDOW_G ECMULT_WINDOW_SIZE
extern const secp256k1_ge_storage secp256k1_pre_g[ECMULT_TABLE_SIZE(WINDOW_G)];
extern const secp256k1_ge_storage secp256k1_pre_g_128[ECMULT_TABLE_SIZE(WINDOW_G)];
#endif /* defined(EXHAUSTIVE_TEST_ORDER) */

#ifdef __cplusplus
}
#endif

#endif /* SECP256K1_PRECOMPUTED_ECMULT_H */
