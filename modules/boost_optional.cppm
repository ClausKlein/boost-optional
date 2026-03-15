module;

#include <boost/config.hpp>
#include <boost/assert.hpp>
#include <boost/throw_exception.hpp>
#include <boost/config/disable_module_warnings.hpp>

export module boost.optional;
import std;
import boost.core;
import boost.type_traits;

#define BOOST_OPTIONAL_INTERFACE_UNIT
#define BOOST_IN_MODULE_PURVIEW

#include <boost/optional.hpp>
