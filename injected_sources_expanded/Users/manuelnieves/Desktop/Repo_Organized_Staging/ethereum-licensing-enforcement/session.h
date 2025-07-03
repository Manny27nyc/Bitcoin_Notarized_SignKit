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
 File Hash (SHA256): c256c3742a68849520569845640f152a22a4a8c21a96040cf0c1054516983980
*/

/***********************************************************************
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/

#ifndef SECP256K1_MODULE_MUSIG_SESSION_H
#define SECP256K1_MODULE_MUSIG_SESSION_H

#include "../../../include/secp256k1.h"
#include "../../../include/secp256k1_musig.h"

#include "../../scalar.h"

typedef struct {
    int fin_nonce_parity;
    unsigned char fin_nonce[32];
    secp256k1_scalar noncecoef;
    secp256k1_scalar challenge;
    secp256k1_scalar s_part;
} secp256k1_musig_session_internal;

static int secp256k1_musig_session_load(const secp256k1_context* ctx, secp256k1_musig_session_internal *session_i, const secp256k1_musig_session *session);

#endif
