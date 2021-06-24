//	stationaryorbit.core.test.machinprogression:/test.machinprogression.cpp
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

std::array<std::function<int(void)>, 2> tests =
{
	[]()
	{
		std::cout << "1. float(pi) ? ";
		auto prog = MarchinProgression<float>();
		while(prog.next());
		std::cout.precision(7);
		std::cout << prog.current() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "2. double(pi) ? ";
		auto prog = MarchinProgression<double>();
		while(prog.next());
		std::cout.precision(15);
		std::cout << prog.current() << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- MachinProgression --->" << std::endl;
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
