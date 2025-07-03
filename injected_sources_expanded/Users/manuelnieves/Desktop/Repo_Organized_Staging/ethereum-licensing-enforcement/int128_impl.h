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
 File Hash (SHA256): 5683c02dfc495639da259d80624711c1c449bbaee6186729e399e713a28b4719
*/

#ifndef SECP256K1_INT128_IMPL_H
#define SECP256K1_INT128_IMPL_H

#include "util.h"

#include "int128.h"

#if defined(SECP256K1_WIDEMUL_INT128)
#  if defined(SECP256K1_INT128_NATIVE)
#    include "int128_native_impl.h"
#  elif defined(SECP256K1_INT128_STRUCT)
#    include "int128_struct_impl.h"
#  else
#    error "Please select int128 implementation"
#  endif
#endif

#endif
