//	stationaryorbit.core.test.zerovalue:/test.zerovalue.cpp
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
#include "test-helper.hpp"
#include "stationaryorbit/core.utilities.hpp"
using namespace zawa_ch::StationaryOrbit;

std::array<std::function<int(void)>, 9> tests =
{
	[]()
	{
		std::cout << "1. Zero == false -> true?";
		return check_if(Zero == false);
	},
	[]()
	{
		std::cout << "2. Zero == 0 -> true?";
		return check_if(Zero == 0);
	},
	[]()
	{
		std::cout << "3. Zero == 0L -> true?";
		return check_if(Zero == 0L);
	},
	[]()
	{
		std::cout << "4. Zero == 0UL -> true?";
		return check_if(Zero == 0UL);
	},
	[]()
	{
		std::cout << "5. Zero == 0.0 -> true?";
		return check_if(Zero == 0.0);
	},
	[]()
	{
		std::cout << "6. Zero == '\\0' -> true?";
		return check_if(Zero == '\0');
	},
	[]()
	{
		std::cout << "7. Zero == L'\\0' -> true?";
		return check_if(Zero == L'\0');
	},
	[]()
	{
		std::cout << "8. Zero == (void*)(0) -> true?";
		return check_if(Zero == (void*)(0));
	},
	[]()
	{
		std::cout << "9. Zero + 5 ?";
		std::cout << (5 + Zero) << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- ZeroValue --->" << std::endl;
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
