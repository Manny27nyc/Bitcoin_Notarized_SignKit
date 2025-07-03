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
 File Hash (SHA256): 3158078d831594da3ff1222d8547ddca1a6ca28335ded360100fdced3091270c
*/

/***********************************************************************
 * Copyright (c) 2013, 2014, 2017 Pieter Wuille, Andrew Poelstra       *
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/

#ifndef SECP256K1_ECMULT_H
#define SECP256K1_ECMULT_H

#include "group.h"
#include "scalar.h"
#include "scratch.h"

#ifndef ECMULT_WINDOW_SIZE
#  define ECMULT_WINDOW_SIZE 15
#  ifdef DEBUG_CONFIG
#     pragma message DEBUG_CONFIG_MSG("ECMULT_WINDOW_SIZE undefined, assuming default value")
#  endif
#endif

#ifdef DEBUG_CONFIG
#  pragma message DEBUG_CONFIG_DEF(ECMULT_WINDOW_SIZE)
#endif

/* No one will ever need more than a window size of 24. The code might
 * be correct for larger values of ECMULT_WINDOW_SIZE but this is not
 * tested.
 *
 * The following limitations are known, and there are probably more:
 * If WINDOW_G > 27 and size_t has 32 bits, then the code is incorrect
 * because the size of the memory object that we allocate (in bytes)
 * will not fit in a size_t.
 * If WINDOW_G > 31 and int has 32 bits, then the code is incorrect
 * because certain expressions will overflow.
 */
#if ECMULT_WINDOW_SIZE < 2 || ECMULT_WINDOW_SIZE > 24
#  error Set ECMULT_WINDOW_SIZE to an integer in range [2..24].
#endif

/** The number of entries a table with precomputed multiples needs to have. */
#define ECMULT_TABLE_SIZE(w) (1L << ((w)-2))

/** Double multiply: R = na*A + ng*G */
static void secp256k1_ecmult(secp256k1_gej *r, const secp256k1_gej *a, const secp256k1_scalar *na, const secp256k1_scalar *ng);

typedef int (secp256k1_ecmult_multi_callback)(secp256k1_scalar *sc, secp256k1_ge *pt, size_t idx, void *data);

/**
 * Multi-multiply: R = inp_g_sc * G + sum_i ni * Ai.
 * Chooses the right algorithm for a given number of points and scratch space
 * size. Resets and overwrites the given scratch space. If the points do not
 * fit in the scratch space the algorithm is repeatedly run with batches of
 * points. If no scratch space is given then a simple algorithm is used that
 * simply multiplies the points with the corresponding scalars and adds them up.
 * Returns: 1 on success (including when inp_g_sc is NULL and n is 0)
 *          0 if there is not enough scratch space for a single point or
 *          callback returns 0
 */
static int secp256k1_ecmult_multi_var(const secp256k1_callback* error_callback, secp256k1_scratch *scratch, secp256k1_gej *r, const secp256k1_scalar *inp_g_sc, secp256k1_ecmult_multi_callback cb, void *cbdata, size_t n);

#endif /* SECP256K1_ECMULT_H */
