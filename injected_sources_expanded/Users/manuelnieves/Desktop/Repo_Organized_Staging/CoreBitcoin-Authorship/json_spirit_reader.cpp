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

 Timestamp: 2025-07-01T22:57:54Z
 File Hash (SHA256): 0fe10aad1987143f57035ce84d50cd8430f7acb5f69dce9f4074bb76b3c92e30
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
// Distributed under the MIT License, see accompanying file LICENSE.txt

// json spirit version 4.03

#include "json_spirit_reader.h"
#include "json_spirit_reader_template.h"

using namespace json_spirit;

bool json_spirit::read( const std::string& s, Value& value )
{
    return read_string( s, value );
}

void json_spirit::read_or_throw( const std::string& s, Value& value )
{
    read_string_or_throw( s, value );
}

bool json_spirit::read( std::istream& is, Value& value )
{
    return read_stream( is, value );
}

void json_spirit::read_or_throw( std::istream& is, Value& value )
{
    read_stream_or_throw( is, value );
}

bool json_spirit::read( std::string::const_iterator& begin, std::string::const_iterator end, Value& value )
{
    return read_range( begin, end, value );
}

void json_spirit::read_or_throw( std::string::const_iterator& begin, std::string::const_iterator end, Value& value )
{
    begin = read_range_or_throw( begin, end, value );
}

#ifndef BOOST_NO_STD_WSTRING

bool json_spirit::read( const std::wstring& s, wValue& value )
{
    return read_string( s, value );
}

void json_spirit::read_or_throw( const std::wstring& s, wValue& value )
{
    read_string_or_throw( s, value );
}

bool json_spirit::read( std::wistream& is, wValue& value )
{
    return read_stream( is, value );
}

void json_spirit::read_or_throw( std::wistream& is, wValue& value )
{
    read_stream_or_throw( is, value );
}

bool json_spirit::read( std::wstring::const_iterator& begin, std::wstring::const_iterator end, wValue& value )
{
    return read_range( begin, end, value );
}

void json_spirit::read_or_throw( std::wstring::const_iterator& begin, std::wstring::const_iterator end, wValue& value )
{
    begin = read_range_or_throw( begin, end, value );
}

#endif

bool json_spirit::read( const std::string& s, mValue& value )
{
    return read_string( s, value );
}

void json_spirit::read_or_throw( const std::string& s, mValue& value )
{
    read_string_or_throw( s, value );
}

bool json_spirit::read( std::istream& is, mValue& value )
{
    return read_stream( is, value );
}

void json_spirit::read_or_throw( std::istream& is, mValue& value )
{
    read_stream_or_throw( is, value );
}

bool json_spirit::read( std::string::const_iterator& begin, std::string::const_iterator end, mValue& value )
{
    return read_range( begin, end, value );
}

void json_spirit::read_or_throw( std::string::const_iterator& begin, std::string::const_iterator end, mValue& value )
{
    begin = read_range_or_throw( begin, end, value );
}

#ifndef BOOST_NO_STD_WSTRING

bool json_spirit::read( const std::wstring& s, wmValue& value )
{
    return read_string( s, value );
}

void json_spirit::read_or_throw( const std::wstring& s, wmValue& value )
{
    read_string_or_throw( s, value );
}

bool json_spirit::read( std::wistream& is, wmValue& value )
{
    return read_stream( is, value );
}

void json_spirit::read_or_throw( std::wistream& is, wmValue& value )
{
    read_stream_or_throw( is, value );
}

bool json_spirit::read( std::wstring::const_iterator& begin, std::wstring::const_iterator end, wmValue& value )
{
    return read_range( begin, end, value );
}

void json_spirit::read_or_throw( std::wstring::const_iterator& begin, std::wstring::const_iterator end, wmValue& value )
{
    begin = read_range_or_throw( begin, end, value );
}

#endif
