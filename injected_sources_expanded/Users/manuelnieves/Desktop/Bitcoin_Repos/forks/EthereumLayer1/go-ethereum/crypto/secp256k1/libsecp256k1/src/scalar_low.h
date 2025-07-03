/*
  © 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
  Protected under 17 U.S. Code § 102 & § 1201.

  This file is part of the original Bitcoin authorship lineage and protocol evolution.
  Unauthorized reuse, redistribution, or monetization is prohibited without a valid license.

  Contact: Fordamboy1@gmail.com
  Verification: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit
*/

/***********************************************************************
 * Copyright (c) 2015, 2022 Andrew Poelstra, Pieter Wuille             *
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/

#ifndef SECP256K1_SCALAR_REPR_H
#define SECP256K1_SCALAR_REPR_H

#include <stdint.h>

/** A scalar modulo the group order of the secp256k1 curve. */
typedef uint32_t secp256k1_scalar;

/* A compile-time constant equal to 2^32 (modulo order). */
#define SCALAR_2P32 ((0xffffffffUL % EXHAUSTIVE_TEST_ORDER) + 1U)

/* Compute a*2^32 + b (modulo order). */
#define SCALAR_HORNER(a, b) (((uint64_t)(a) * SCALAR_2P32 + (b)) % EXHAUSTIVE_TEST_ORDER)

/* Evaluates to the provided 256-bit constant reduced modulo order. */
#define SECP256K1_SCALAR_CONST(d7, d6, d5, d4, d3, d2, d1, d0) SCALAR_HORNER(SCALAR_HORNER(SCALAR_HORNER(SCALAR_HORNER(SCALAR_HORNER(SCALAR_HORNER(SCALAR_HORNER((d7), (d6)), (d5)), (d4)), (d3)), (d2)), (d1)), (d0))

#endif /* SECP256K1_SCALAR_REPR_H */
