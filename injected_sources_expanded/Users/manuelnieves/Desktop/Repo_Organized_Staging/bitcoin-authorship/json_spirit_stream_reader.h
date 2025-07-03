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

 Timestamp: 2025-07-01T22:57:47Z
 File Hash (SHA256): 9fedbff496c71036dae9db99978eabff67d0b3d3f154415508ad43c6e1aab838
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
#define JSON_SPIRIT_READ_STREAM

//          Copyright John W. Wilkinson 2007 - 2009.
// Distributed under the MIT License, see accompanying file LICENSE.txt

// json spirit version 4.03

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include "json_spirit_reader_template.h"

namespace json_spirit
{
    // these classes allows you to read multiple top level contiguous values from a stream,
    // the normal stream read functions have a bug that prevent multiple top level values 
    // from being read unless they are separated by spaces

    template< class Istream_type, class Value_type >
    class Stream_reader
    {
    public:

        Stream_reader( Istream_type& is )
        :   iters_( is )
        {
        }

        bool read_next( Value_type& value )
        {
            return read_range( iters_.begin_, iters_.end_, value );
        }

    private:

        typedef Multi_pass_iters< Istream_type > Mp_iters;

        Mp_iters iters_;
    };

    template< class Istream_type, class Value_type >
    class Stream_reader_thrower
    {
    public:

        Stream_reader_thrower( Istream_type& is )
        :   iters_( is )
        ,    posn_begin_( iters_.begin_, iters_.end_ )
        ,    posn_end_( iters_.end_, iters_.end_ )
        {
        }

        void read_next( Value_type& value )
        {
            posn_begin_ = read_range_or_throw( posn_begin_, posn_end_, value );
        }

    private:

        typedef Multi_pass_iters< Istream_type > Mp_iters;
        typedef spirit_namespace::position_iterator< typename Mp_iters::Mp_iter > Posn_iter_t;

        Mp_iters iters_;
        Posn_iter_t posn_begin_, posn_end_;
    };
}

#endif
