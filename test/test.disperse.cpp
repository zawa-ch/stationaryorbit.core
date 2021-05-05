//	stationaryorbit.core.test.disperse:/test.disperse.cpp
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
#include <functional>
#include "stationaryorbit/core.bitoperation.hpp"
#include "stationaryorbit/core.utilities.hpp"
using namespace zawa_ch::StationaryOrbit;

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

std::array<std::function<int(void)>, 2> tests =
{
	[]()
	{
		uint32_t n1;
		if (Endians::native == Endians::little)
		{
			std::cout << "uint32_t n1 = 0x78563412" << std::endl;
			n1 = 0x78563412;
		}
		else if (Endians::native == Endians::big)
		{
			std::cout << "uint32_t n1 = 0x12345678" << std::endl;
			n1 = 0x12345678;
		}
		else
		{
			std::cerr << "";
			return 255;
		}
		std::cout << "1. to_binary(n1) ? ";
		dump(std::cout, Disperse::to_binary(n1));
		return 0;
	},
	[]()
	{
		std::cout << "a1 = std::array<a1>{ 0x55, 0x55, 0x55, 0x55 }";
		std::array<std::byte, 4> a1 = { std::byte{0x55}, std::byte{0x55}, std::byte{0x55}, std::byte{0x55} };
		std::cout << "2. perse<uint32_t>(a1) ? ";
		std::cout << Disperse::perse<uint32_t>(a1) << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- Disperse --->" << std::endl;
	int test_index;
	if (2 <= argc)
	{
		test_index = std::stoi(argv[1]);
	}
	else
	{
		std::cerr << "W: No test# specified" << std::endl;
		std::cout << "Test#? ";
		std::cin >> test_index;
	}
	if (0 < test_index && test_index <= tests.size() )
	{
		return tests[test_index - 1]();
	}
	else
	{
		std::cerr << "E: Invalid test index" << std::endl;
		return 2;
	}
}
