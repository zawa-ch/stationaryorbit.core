//	stationaryorbit.core.test.fixedpoint:/test.fixedpoint.cpp
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
#include "stationaryorbit/core.numeral.hpp"
using namespace zawa_ch::StationaryOrbit;

std::array<std::function<int(void)>, 18> tests =
{
	[]()
	{
		std::cout << "1. Type FixedPoint8q7_t meets the traits IsNumericalType?";
		return check_if(Traits::IsNumericalType<FixedPoint8q7_t>);
	},
	[]()
	{
		std::cout << "2. Type FixedPoint16q8_t meets the traits IsNumericalType?";
		return check_if(Traits::IsNumericalType<FixedPoint16q8_t>);
	},
	[]()
	{
		std::cout << "3. Type FixedPoint16q15_t meets the traits IsNumericalType?";
		return check_if(Traits::IsNumericalType<FixedPoint16q15_t>);
	},
	[]()
	{
		std::cout << "4. Type FixedPoint32q16_t meets the traits IsNumericalType?";
		return check_if(Traits::IsNumericalType<FixedPoint32q16_t>);
	},
	[]()
	{
		std::cout << "5. Type FixedPoint32q31_t meets the traits IsNumericalType?";
		return check_if(Traits::IsNumericalType<FixedPoint32q31_t>);
	},
	[]()
	{
		std::cout << "6. Type FixedPoint64q32_t meets the traits IsNumericalType?";
		return check_if(Traits::IsNumericalType<FixedPoint64q32_t>);
	},
	[]()
	{
		std::cout << "7. Type FixedPoint64q63_t meets the traits IsNumericalType?";
		return check_if(Traits::IsNumericalType<FixedPoint64q63_t>);
	},
	[]()
	{
		auto f1 = FixedPoint16q8_t(16);
		std::cout << "f1 = FixedPoint16q8_t(16)" << std::endl;
		std::cout << "8. f1 == 16 ->true?";
		return check_if(double(f1) == 16);
	},
	[]()
	{
		auto f2 = FixedPoint16q8_t(0.125);
		std::cout << "f2 = FixedPoint16q8_t(0.125)" << std::endl;
		std::cout << "9. f2 == 0.125 ->true?";
		return check_if(double(f2) == 0.125);
	},
	[]()
	{
		auto f1 = FixedPoint16q8_t(16);
		auto f2 = FixedPoint16q8_t(0.125);
		std::cout << "f1 = FixedPoint16q8_t(16)" << std::endl;
		std::cout << "f2 = FixedPoint16q8_t(0.125)" << std::endl;
		std::cout << "10. f1 + f2 == 16.125 ->true?";
		return check_if(double(f1 + f2) == 16.125);
	},
	[]()
	{
		auto f1 = FixedPoint16q8_t(16);
		auto f2 = FixedPoint16q8_t(0.125);
		std::cout << "f1 = FixedPoint16q8_t(16)" << std::endl;
		std::cout << "f2 = FixedPoint16q8_t(0.125)" << std::endl;
		std::cout << "11. f1 - f2 == 15.875 ->true?";
		return check_if(double(f1 - f2) == 15.875);
	},
	[]()
	{
		auto f1 = FixedPoint16q8_t(16);
		auto f2 = FixedPoint16q8_t(0.125);
		std::cout << "f1 = FixedPoint16q8_t(16)" << std::endl;
		std::cout << "f2 = FixedPoint16q8_t(0.125)" << std::endl;
		std::cout << "12. f1 * f2 == 2 ->true?";
		return check_if(double(f1 * f2) == 2);
	},
	[]()
	{
		auto f1 = FixedPoint16q8_t(16);
		auto f2 = FixedPoint16q8_t(0.125);
		std::cout << "f1 = FixedPoint16q8_t(16)" << std::endl;
		std::cout << "f2 = FixedPoint16q8_t(0.125)" << std::endl;
		std::cout << "13. f1 / f2 == 128 ->true?";
		return check_if(double(f1 / f2) == 128);
	},
	[]()
	{
		auto f1 = FixedPoint16q8_t(16);
		std::cout << "f1 = FixedPoint16q8_t(16)" << std::endl;
		std::cout << "14. FixedPoint32q16_t(f1) == FixedPoint32q16_t(16) ->true?";
		return check_if(FixedPoint32q16_t(f1) == FixedPoint32q16_t(16));
	},
	[]()
	{
		std::cout << "15. FixedPoint32q16_t(Proportion16_t(3/4)) == FixedPoint32q16_t(0.75) ->true?";
		return check_if(FixedPoint16q15_t(Proportion16_t(3, 4)) == FixedPoint16q15_t(0.75));
	},
	[]()
	{
		std::cout << "16. FixedPoint16q8_t::Max() ? " << double(FixedPoint16q8_t::Max()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "17. FixedPoint16q8_t::Min() ? " << double(FixedPoint16q8_t::Min()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "18. FixedPoint16q8_t::Epsilon() ? " << double(FixedPoint16q8_t::Epsilon()) << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- FixedPoint --->" << std::endl;
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
