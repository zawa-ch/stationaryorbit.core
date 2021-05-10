//	stationaryorbit.core:/test/test-helper.hpp
//	Copyright 2021 zawa-ch.
//	GPLv3 (or later) license
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//	See the GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program.
//	If not, see <http://www.gnu.org/licenses/>.
//
#include <iostream>
#include <array>

constexpr int check_if(bool condition)
{
	if (condition)
	{
		std::cout << "...OK" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "...NG" << std::endl;
		return 1;
	}
}


template<size_t N>
std::ostream& dump(std::ostream& stream, const std::array<std::byte, N>& data)
{
	auto flags = stream.flags();
	auto width = stream.width();
	auto fill = stream.fill();
	size_t n = 0;
	for(auto i: data)
	{
		if(16 <= n)
		{
			n = 0;
			std::cout << std::endl;
		}
		stream.width(2);
		stream.fill('0');
		stream << std::hex << std::uppercase << uint16_t(i);
		++n;
	}
	stream.flags(flags);
	stream.width(width);
	stream.fill(fill);
	return stream;
}

std::ostream& dump(std::ostream& stream, const std::vector<std::byte>& data)
{
	auto flags = stream.flags();
	auto width = stream.width();
	auto fill = stream.fill();
	size_t n = 0;
	for(auto i: data)
	{
		if(16 <= n)
		{
			n = 0;
			std::cout << std::endl;
		}
		stream.width(2);
		stream.fill('0');
		stream << std::hex << std::uppercase << uint16_t(i);
		++n;
	}
	stream.flags(flags);
	stream.width(width);
	stream.fill(fill);
	return stream;
}
