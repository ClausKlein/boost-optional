// Copyright (C) 2003, 2008 Fernando Luis Cacciola Carballal.
// Copyright (C) 2016 Andrzej Krzemienski
//
// Use, modification, and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/optional for documentation.
//
// You are welcome to contact the author at:
//  fernando_cacciola@hotmail.com
//
// Revisions:
// 10 May 2008 (added swap related forward declaration) Niels Dekker
//
#ifndef BOOST_OPTIONAL_OPTIONAL_FWD_FLC_19NOV2002_HPP
#define BOOST_OPTIONAL_OPTIONAL_FWD_FLC_19NOV2002_HPP

#if defined(BOOST_USE_MODULES) && !defined(BOOST_OPTIONAL_INTERFACE_UNIT)

#ifndef BOOST_IN_MODULE_PURVIEW
import boost.optional;
#endif

#else

#include "boost/optional/detail/config.hpp"
#include <boost/config.hpp>
#include <boost/core/invoke_swap.hpp>
#include <boost/optional/detail/optional_select_implementation.hpp>
#include <boost/config/std/type_traits.hpp>


namespace boost {

BOOST_OPTIONAL_MODULE_EXPORT template<class T> class optional ;

// This forward is needed to refer to namespace scope swap from the member swap
#ifdef BOOST_OPTIONAL_USES_UNION_IMPLEMENTATION
  BOOST_OPTIONAL_MODULE_EXPORT
  template<class T> BOOST_OPTIONAL_CXX20_CONSTEXPR void swap ( optional<T>& lhs, optional<T>& rhs )
    noexcept(::std::is_nothrow_move_constructible<T>::value && noexcept(boost::core::invoke_swap(*lhs, *rhs)));
#else
  BOOST_OPTIONAL_MODULE_EXPORT
  template<class T> void swap ( optional<T>& , optional<T>& ) ;
#endif // BOOST_OPTIONAL_USES_UNION_IMPLEMENTATION


BOOST_OPTIONAL_MODULE_EXPORT template<class T> struct optional_swap_should_use_default_constructor ;


#ifndef BOOST_OPTIONAL_CONFIG_DONT_SPECIALIZE_OPTIONAL_REFS

  template<class T> class optional<T&> ;

  BOOST_OPTIONAL_MODULE_EXPORT template<class T> BOOST_CXX14_CONSTEXPR void swap ( optional<T&>& , optional<T&>& ) BOOST_NOEXCEPT;

#endif

} // namespace boost

#endif // BOOST_USE_MODULES

#endif
