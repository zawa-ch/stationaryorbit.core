//	stationaryorbit.core.test.constprogression:/test.constprogression
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

template<int Init>
class SuccessorIterator
{
public:
	typedef int ValueType;
private:
	int _value;
public:
	constexpr SuccessorIterator() : _value(Init) {}
	constexpr bool has_value() const noexcept { return true; }
	constexpr ValueType current() const noexcept { return _value; }
	constexpr bool next() noexcept { _value += 1; return has_value(); }
};
class Stop10Iterator
{
public:
	typedef size_t ValueType;
private:
	size_t _value;
public:
	constexpr Stop10Iterator() : _value(0) {}
	constexpr bool has_value() const noexcept { return _value <= 10; }
	constexpr ValueType current() const noexcept { return _value; }
	constexpr bool next() noexcept { ++_value; return has_value(); }
};

std::array<std::function<int(void)>, 2> tests =
{
	[]()
	{
		std::cout << "1. ConstProgression<int, Suc, 1, 10>::values ? ";
		for (auto i: Range<size_t>(0, 10).GetStdIterator())
		{
			std::cout << ConstProgressionArray<SuccessorIterator<1>, 10>::values[i] << " ";
		}
		std::cout << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "2. ConstProgressionLastValue<Stop10Iterator>::value ? ";
		std::cout << ConstProgressionLastValue<Stop10Iterator>::value << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- ConstProgression --->" << std::endl;
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
