
#pragma once

#include <boost/utility/string_ref.hpp>
#include <cstdint>

namespace epee
{
namespace net_utils
{
	enum class address_type : std::uint8_t
	{
		// Do not change values, this will break serialization
		invalid = 0,
		ipv4 = 1,
		ipv6 = 2,
		i2p = 3,
		tor = 4
	};

	enum class zone : std::uint8_t
	{
		invalid = 0,
		public_ = 1, // public is keyword
		i2p = 2,     // order from here changes priority of selection for origin TXes
		tor = 3
	};

	// implementations in src/net_utils_base.cpp

	//! \return String name of zone or "invalid" on error.
	const char* zone_to_string(zone value) noexcept;

	//! \return `zone` enum of `value` or `zone::invalid` on error.
	zone zone_from_string(boost::string_ref value) noexcept;
} // net_utils
} // epee

namespace std
{
	template<> struct hash<epee::net_utils::zone>
	{
		std::size_t operator()(const epee::net_utils::zone _z) const
		{
			return static_cast<std::size_t>(_z);
		}
	};
} // std
