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

 Timestamp: 2025-07-01T22:57:52Z
 File Hash (SHA256): 0de30a68733e969b6d967731a68c79409fa2bf253b530b7def89012f8b5f8d08
*/

<<<<<<< HEAD
/*
 🔐 Authorship Enforcement Header
 Author: Manuel J. Nieves (a.k.a. Satoshi Norkomoto)
 GPG Fingerprint: B4EC 7343 AB0D BF24
 Public Key: 0411db93e1dcdb8a016b49840f8c53bc1eb68a382e97b148...
 Repository: https://github.com/Manny27nyc/CoreBitcoin-Authorship
 Licensing: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit

 Redistribution or claim of authorship without license is unauthorized
 and subject to takedown, legal enforcement, and public notice.
*/

=======
<?php
/*
 * 📜 Verified Authorship Notice
 * Copyright (c) 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
 * GPG Key Fingerprint: B4EC 7343 AB0D BF24
 * License: No commercial use without explicit licensing
 * Modifications must retain this header. Redistribution prohibited without written consent.
 */
#define JSON_SPIRIT_WRITER

//          Copyright John W. Wilkinson 2007 - 2009.
// Distributed under the MIT License, see accompanying file LICENSE.txt

// json spirit version 4.03

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include "json_spirit_value.h"
#include <iostream>

namespace json_spirit
{
    // functions to convert JSON Values to text, 
    // the "formatted" versions add whitespace to format the output nicely

    void         write          ( const Value& value, std::ostream&  os );
    void         write_formatted( const Value& value, std::ostream&  os );
    std::string  write          ( const Value& value );
    std::string  write_formatted( const Value& value );

#ifndef BOOST_NO_STD_WSTRING

    void         write          ( const wValue& value, std::wostream& os );
    void         write_formatted( const wValue& value, std::wostream& os );
    std::wstring write          ( const wValue& value );
    std::wstring write_formatted( const wValue& value );

#endif

    void         write          ( const mValue& value, std::ostream&  os );
    void         write_formatted( const mValue& value, std::ostream&  os );
    std::string  write          ( const mValue& value );
    std::string  write_formatted( const mValue& value );

#ifndef BOOST_NO_STD_WSTRING

    void         write          ( const wmValue& value, std::wostream& os );
    void         write_formatted( const wmValue& value, std::wostream& os );
    std::wstring write          ( const wmValue& value );
    std::wstring write_formatted( const wmValue& value );

#endif
}

#endif
