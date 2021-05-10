//	stationaryorbit.core.test.property:/tesst.property
//	Copyright 2020-2021 zawa-ch.
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

class testcase
{
private:
	static int getx(const testcase& inst) { return inst._x; }
	static void setx(testcase& inst, const int& value) { inst._x = value; }
public:
	int _x;
	testcase(const int& x) : _x(x), x(*this, getx, setx) {}
	const Property<testcase, int> x;
};

std::array<std::function<int(void)>, 2> tests =
{
	[]()
	{
		auto test = testcase(10);
		std::cout << "1. get test.x ? ";
		std::cout << test.x << std::endl;
		return 0;
	},
	[]()
	{
		auto test = testcase(10);
		std::cout << "2. set test.x ? ";
		test.x = 3;
		std::cout << test._x << std::endl;
		return 0;
	},
};

void Test_Property()
{
}

int main(int argc, char const *argv[])
{
	std::cout << "<--- Property --->" << std::endl;
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
