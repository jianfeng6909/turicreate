/*==============================================================================
    Copyright (c) 2006 Peter Dimov
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/config.hpp>

#if defined(BOOST_MSVC)
#pragma warning(disable: 4786)  // identifier truncated in debug info
#pragma warning(disable: 4710)  // function not inlined
#pragma warning(disable: 4711)  // function selected for automatic inline expansion
#pragma warning(disable: 4514)  // unreferenced inline removed
#endif

#include <boost/phoenix/core.hpp>
#include <boost/phoenix/bind.hpp>

#if defined(BOOST_MSVC) && (BOOST_MSVC < 1300)
#pragma warning(push, 3)
#endif

#include <iostream>

#if defined(BOOST_MSVC) && (BOOST_MSVC < 1300)
#pragma warning(pop)
#endif

#include <boost/detail/lightweight_test.hpp>
#include <boost/shared_ptr.hpp>

struct X
{
    int v_;

    X( int v ): v_( v )
    {
    }

    int f()
    {
        return v_;
    }
};

struct Y
{
    boost::shared_ptr<X> f()
    {
        return boost::shared_ptr<X>( new X( 42 ) );
    }
};

int main()
{
    using boost::phoenix::bind;
    //using boost::phoenix::placeholders::_1;

    Y y;

    // Change bind_rv_sp_test.cpp to bind to _1. Renamed f to g in y
    //BOOST_TEST( bind( &X::f, _1) ( bind( &Y::g, &y )()) == 42 );
    //boost::shared_ptr<X> xp = bind( &Y::f, &y )();
    boost::shared_ptr<X> xp = y.f();
    // BOOST_TEST( bind( &X::f, xp)()  == 42 );
    BOOST_TEST( (*xp).f() == 42 );
    return boost::report_errors();
}
