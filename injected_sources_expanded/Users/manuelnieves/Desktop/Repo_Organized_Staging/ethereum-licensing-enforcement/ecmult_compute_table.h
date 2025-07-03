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
 File Hash (SHA256): 5a8ce69b18d777c3ad608ef173fd6a47c75b9c37bc6801f19ca4c44eb4b9f8f6
*/

/*****************************************************************************************************
 * Copyright (c) 2013, 2014, 2017, 2021 Pieter Wuille, Andrew Poelstra, Jonas Nick, Russell O'Connor *
 * Distributed under the MIT software license, see the accompanying                                  *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.                              *
 *****************************************************************************************************/

#ifndef SECP256K1_ECMULT_COMPUTE_TABLE_H
#define SECP256K1_ECMULT_COMPUTE_TABLE_H

/* Construct table of all odd multiples of gen in range 1..(2**(window_g-1)-1). */
static void secp256k1_ecmult_compute_table(secp256k1_ge_storage* table, int window_g, const secp256k1_gej* gen);

/* Like secp256k1_ecmult_compute_table, but one for both gen and gen*2^128. */
static void secp256k1_ecmult_compute_two_tables(secp256k1_ge_storage* table, secp256k1_ge_storage* table_128, int window_g, const secp256k1_ge* gen);

#endif /* SECP256K1_ECMULT_COMPUTE_TABLE_H */
