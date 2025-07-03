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

 Timestamp: 2025-07-01T22:57:46Z
 File Hash (SHA256): 6ec4d9799505dd3349240eee4676364c75a4842d9266abdfd801119cc4a21581
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
#define JSON_SPIRIT_ERROR_POSITION

//          Copyright John W. Wilkinson 2007 - 2009.
// Distributed under the MIT License, see accompanying file LICENSE.txt

// json spirit version 4.03

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <string>

namespace json_spirit
{
    // An Error_position exception is thrown by the "read_or_throw" functions below on finding an error.
    // Note the "read_or_throw" functions are around 3 times slower than the standard functions "read" 
    // functions that return a bool.
    //
    struct Error_position
    {
        Error_position();
        Error_position( unsigned int line, unsigned int column, const std::string& reason );
        bool operator==( const Error_position& lhs ) const;
        unsigned int line_;
        unsigned int column_;
        std::string reason_;
    };

    inline Error_position::Error_position()
    :   line_( 0 )
    ,   column_( 0 )
    {
    }

    inline Error_position::Error_position( unsigned int line, unsigned int column, const std::string& reason )
    :   line_( line )
    ,   column_( column )
    ,   reason_( reason )
    {
    }

    inline bool Error_position::operator==( const Error_position& lhs ) const
    {
        if( this == &lhs ) return true;

        return ( reason_ == lhs.reason_ ) &&
               ( line_   == lhs.line_ ) &&
               ( column_ == lhs.column_ ); 
}
}

#endif
