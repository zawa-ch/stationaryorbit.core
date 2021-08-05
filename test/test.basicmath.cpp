//	stationaryorbit.core.test.basicmath:/test.basicmath
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

std::array<std::function<int(void)>, 5> tests =
{
	[]()
	{
		std::cout << "1. pi<float> ? ";
		std::cout.precision(7);
		std::cout << BasicMathematics::pi<float> << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "2. pi<double> ? ";
		std::cout.precision(15);
		std::cout << BasicMathematics::pi<double> << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "3. sin(0) ? ";
		std::cout.precision(15);
		std::cout << BasicMathematics::sin(0.0) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "4. sin(0.78539816339744830961566084581988) ? ";
		std::cout.precision(15);
		std::cout << BasicMathematics::sin(0.78539816339744830961566084581988) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "5. sin(1.5707963267948966192313216916398) ? ";
		std::cout.precision(15);
		std::cout << BasicMathematics::sin(1.5707963267948966192313216916398) << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- BasicMath --->" << std::endl;
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
		std::cerr << "Invalid test index" << std::endl;
		return 2;
	}
}
