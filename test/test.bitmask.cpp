//	stationaryorbit.core.test.bitmask:/test.bitmask.cpp
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

std::array<std::function<int(void)>, 4> tests =
{
	[]()
	{
		auto mask = BitMask<uint32_t>(0xF0);
		std::cout << "mask: 0xF0" << std::endl;

		std::cout << "1. mask.GetFrom(0x38) ->0x30?";
		if (mask.GetFrom(0x38) == 0x30)
		{
			std::cout << "...OK" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "...NG" << std::endl;
			return 1;
		}
	},
	[]()
	{
		auto mask = BitMask<uint32_t>(0xF0);
		std::cout << "mask: 0xF0" << std::endl;

		std::cout << "2. mask.GetAlignedFrom(0x38) ->0x03?";
		if (mask.GetAlignedFrom(0x38) == 0x03)
		{
			std::cout << "...OK" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "...NG" << std::endl;
			return 1;
		}
	},
	[]()
	{
		auto mask = BitMask<uint32_t>(0x5555);
		std::cout << "mask: 0x5555" << std::endl;

		std::cout << "3. mask.GetFrom(0x250) ->0x050?";
		if (mask.GetFrom(0x250) == 0x50)
		{
			std::cout << "...OK" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "...NG" << std::endl;
			return 1;
		}
	},
	[]()
	{
		auto mask = BitMask<uint32_t>(0x040);
		std::cout << "mask: 0x0040" << std::endl;

		std::cout << "4. mask.GetFrom(0x250) ->0x01?";
		if (mask.GetAlignedFrom(0x250) == 0x1)
		{
			std::cout << "...OK" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "...NG" << std::endl;
			return 1;
		}
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- BitMask --->" << std::endl;
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
