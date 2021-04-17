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
#include "stationaryorbit/core.numeral.hpp"
using namespace zawa_ch::StationaryOrbit;

int test1();
int test2();
int test3();
int test4();
int test5();
int test6();
int test7();
int test8();
int test9();
int test10();
int test11();
int test12();
int test13();
int test14();
int test15();
int test16();
int test17();
int test18();

int main(int argc, char const *argv[])
{
	std::cout << "<--- FixedPoint --->" << std::endl;
	if (argc < 2)
	{
		std::cerr << "E: At least 1 argument is required";
		return 2;
	}

	auto test_index = std::stoi(argv[1]);
	switch(test_index)
	{
		case 1: { return test1(); }
		case 2: { return test2(); }
		case 3: { return test3(); }
		case 4: { return test4(); }
		case 5: { return test5(); }
		case 6: { return test6(); }
		case 7: { return test7(); }
		case 8: { return test8(); }
		case 9: { return test9(); }
		case 10: { return test10(); }
		case 11: { return test11(); }
		case 12: { return test12(); }
		case 13: { return test13(); }
		case 14: { return test14(); }
		case 15: { return test15(); }
		case 16: { return test16(); }
		case 17: { return test17(); }
		case 18: { return test18(); }
		default:
		{
			std::cerr << "Invalid test index";
			return 2;
		}
	}
	return 0;
}

int test1()
{
	std::cout << "1. Type FixedPoint8q7_t meets the traits IsNumericalType?";
	if (Traits::IsNumericalType<FixedPoint8q7_t>)
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

int test2()
{
	std::cout << "2. Type FixedPoint16q8_t meets the traits IsNumericalType?";
	if (Traits::IsNumericalType<FixedPoint16q8_t>)
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

int test3()
{
	std::cout << "3. Type FixedPoint16q15_t meets the traits IsNumericalType?";
	if (Traits::IsNumericalType<FixedPoint16q15_t>)
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

int test4()
{
	std::cout << "4. Type FixedPoint32q16_t meets the traits IsNumericalType?";
	if (Traits::IsNumericalType<FixedPoint32q16_t>)
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

int test5()
{
	std::cout << "5. Type FixedPoint32q31_t meets the traits IsNumericalType?";
	if (Traits::IsNumericalType<FixedPoint32q31_t>)
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

int test6()
{
	std::cout << "6. Type FixedPoint64q32_t meets the traits IsNumericalType?";
	if (Traits::IsNumericalType<FixedPoint64q32_t>)
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

int test7()
{
	std::cout << "7. Type FixedPoint64q63_t meets the traits IsNumericalType?";
	if (Traits::IsNumericalType<FixedPoint64q63_t>)
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

int test8()
{
	auto f1 = FixedPoint16q8_t(16);
	std::cout << "f1 = FixedPoint16q8_t(16)" << std::endl;
	std::cout << "8. f1 == 16 ->true?";
	if (double(f1) == 16)
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

int test9()
{
	auto f2 = FixedPoint16q8_t(0.125);
	std::cout << "f2 = FixedPoint16q8_t(0.125)" << std::endl;
	std::cout << "9. f2 == 0.125 ->true?";
	if (double(f2) == 0.125)
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

int test10()
{
	auto f1 = FixedPoint16q8_t(16);
	auto f2 = FixedPoint16q8_t(0.125);
	std::cout << "f1 = FixedPoint16q8_t(16)" << std::endl;
	std::cout << "f2 = FixedPoint16q8_t(0.125)" << std::endl;
	std::cout << "10. f1 + f2 == 16.125 ->true?";
	if (double(f1 + f2) == 16.125)
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

int test11()
{
	auto f1 = FixedPoint16q8_t(16);
	auto f2 = FixedPoint16q8_t(0.125);
	std::cout << "f1 = FixedPoint16q8_t(16)" << std::endl;
	std::cout << "f2 = FixedPoint16q8_t(0.125)" << std::endl;
	std::cout << "11. f1 - f2 == 15.875 ->true?";
	if (double(f1 - f2) == 15.875)
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

int test12()
{
	auto f1 = FixedPoint16q8_t(16);
	auto f2 = FixedPoint16q8_t(0.125);
	std::cout << "f1 = FixedPoint16q8_t(16)" << std::endl;
	std::cout << "f2 = FixedPoint16q8_t(0.125)" << std::endl;
	std::cout << "12. f1 * f2 == 2 ->true?";
	if (double(f1 * f2) == 2)
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

int test13()
{
	auto f1 = FixedPoint16q8_t(16);
	auto f2 = FixedPoint16q8_t(0.125);
	std::cout << "f1 = FixedPoint16q8_t(16)" << std::endl;
	std::cout << "f2 = FixedPoint16q8_t(0.125)" << std::endl;
	std::cout << "13. f1 / f2 == 128 ->true?";
	if (double(f1 / f2) == 128)
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

int test14()
{
	auto f1 = FixedPoint16q8_t(16);
	std::cout << "f1 = FixedPoint16q8_t(16)" << std::endl;
	std::cout << "14. FixedPoint32q16_t(f1) == FixedPoint32q16_t(16) ->true?";
	if (FixedPoint32q16_t(f1) == FixedPoint32q16_t(16))
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

int test15()
{
	std::cout << "15. FixedPoint32q16_t(Proportion16_t(3/4)) == FixedPoint32q16_t(0.75) ->true?";
	if (FixedPoint16q15_t(Proportion16_t(3, 4)) == FixedPoint16q15_t(0.75))
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

int test16()
{
	std::cout << "16. FixedPoint16q8_t::Max() ? " << double(FixedPoint16q8_t::Max()) << std::endl;
	return 0;
}

int test17()
{
	std::cout << "17. FixedPoint16q8_t::Min() ? " << double(FixedPoint16q8_t::Min()) << std::endl;
	return 0;
}

int test18()
{
	std::cout << "18. FixedPoint16q8_t::Epsilon() ? " << double(FixedPoint16q8_t::Epsilon()) << std::endl;
	return 0;
}

