//	stationaryorbit.core.test.proportion:/test.proportion.cpp
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

std::array<std::function<int(void)>, 37> tests =
{
	[]()
	{
		std::cout << "1. Type Proportion1_t meets the traits NumericalType?";
		return check_if(NumericalTraits::IsNumericalType<Proportion1_t>);
	},
	[]()
	{
		std::cout << "2. Type Proportion1_t not meets the traits BitSequenceType?";
		return check_if(!BitSequenceTypeTraits::IsBitSequenceType<Proportion1_t>);
	},
	[]()
	{
		std::cout << "3. Type Proportion1_t not meets the traits IntegralType?";
		return check_if(!NumericalTraits::IsIntegralType<Proportion1_t>);
	},
	[]()
	{
		std::cout << "4. Type Proportion1_t meets the traits Comparable?";
		return check_if(ComparableTypeTraits::is_comparable<Proportion1_t>);
	},
	[]()
	{
		std::cout << "5. Type Proportion1_t meets the traits Equatable?";
		return check_if(EquatableTypeTraits::is_equatable<Proportion1_t>);
	},
	[]()
	{
		std::cout << "6. Type Proportion8_t meets the traits NumericalType?";
		return check_if(NumericalTraits::IsNumericalType<Proportion8_t>);
	},
	[]()
	{
		std::cout << "7. Type Proportion8_t not meets the traits BitSequenceType?";
		return check_if(!BitSequenceTypeTraits::IsBitSequenceType<Proportion8_t>);
	},
	[]()
	{
		std::cout << "8. Type Proportion8_t not meets the traits IntegralType?";
		return check_if(!NumericalTraits::IsIntegralType<Proportion8_t>);
	},
	[]()
	{
		std::cout << "9. Type Proportion8_t meets the traits Comparable?";
		return check_if(ComparableTypeTraits::is_comparable<Proportion8_t>);
	},
	[]()
	{
		std::cout << "10. Type Proportion8_t meets the traits Equatable?";
		return check_if(EquatableTypeTraits::is_equatable<Proportion8_t>);
	},
	[]()
	{
		std::cout << "11. Type Proportion16_t meets the traits NumericalType?";
		return check_if(NumericalTraits::IsNumericalType<Proportion16_t>);
	},
	[]()
	{
		std::cout << "12. Type Proportion16_t not meets the traits BitSequenceType?";
		return check_if(!BitSequenceTypeTraits::IsBitSequenceType<Proportion16_t>);
	},
	[]()
	{
		std::cout << "13. Type Proportion16_t not meets the traits IntegralType?";
		return check_if(!NumericalTraits::IsIntegralType<Proportion16_t>);
	},
	[]()
	{
		std::cout << "14. Type Proportion16_t meets the traits Comparable?";
		return check_if(ComparableTypeTraits::is_comparable<Proportion16_t>);
	},
	[]()
	{
		std::cout << "15. Type Proportion16_t meets the traits Equatable?";
		return check_if(EquatableTypeTraits::is_equatable<Proportion16_t>);
	},
	[]()
	{
		std::cout << "16. Type Proportion32_t meets the traits NumericalType?";
		return check_if(NumericalTraits::IsNumericalType<Proportion32_t>);
	},
	[]()
	{
		std::cout << "17. Type Proportion32_t not meets the traits BitSequenceType?";
		return check_if(!BitSequenceTypeTraits::IsBitSequenceType<Proportion32_t>);
	},
	[]()
	{
		std::cout << "18. Type Proportion32_t not meets the traits IntegralType?";
		return check_if(!NumericalTraits::IsIntegralType<Proportion32_t>);
	},
	[]()
	{
		std::cout << "19. Type Proportion32_t meets the traits Comparable?";
		return check_if(ComparableTypeTraits::is_comparable<Proportion32_t>);
	},
	[]()
	{
		std::cout << "20. Type Proportion32_t meets the traits Equatable?";
		return check_if(EquatableTypeTraits::is_equatable<Proportion32_t>);
	},
	[]()
	{
		std::cout << "21. Type Proportion64_t meets the traits NumericalType?";
		return check_if(NumericalTraits::IsNumericalType<Proportion64_t>);
	},
	[]()
	{
		std::cout << "22. Type Proportion64_t not meets the traits BitSequenceType?";
		return check_if(!BitSequenceTypeTraits::IsBitSequenceType<Proportion64_t>);
	},
	[]()
	{
		std::cout << "23. Type Proportion64_t not meets the traits IntegralType?";
		return check_if(!NumericalTraits::IsIntegralType<Proportion64_t>);
	},
	[]()
	{
		std::cout << "24. Type Proportion64_t meets the traits Comparable?";
		return check_if(ComparableTypeTraits::is_comparable<Proportion64_t>);
	},
	[]()
	{
		std::cout << "25. Type Proportion64_t meets the traits Equatable?";
		return check_if(EquatableTypeTraits::is_equatable<Proportion64_t>);
	},
	[]()
	{
		std::cout << "p1 = Proportion8_t(0.5)" << std::endl;
		auto p1 = Proportion8_t(0.5);
		std::cout.precision(16);
		std::cout << "26. p1 ? " << double(p1) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "p2 = Proportion8_t(0.25)" << std::endl;
		auto p2 = Proportion8_t(0.25);
		std::cout.precision(16);
		std::cout << "27. p2 ? " << double(p2) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "p1 = Proportion8_t(0.5)" << std::endl;
		std::cout << "p2 = Proportion8_t(0.25)" << std::endl;
		auto p1 = Proportion8_t(0.5);
		auto p2 = Proportion8_t(0.25);
		std::cout << "28. p1 > p2 -> true?";
		return check_if(p1 > p2);
	},
	[]()
	{
		std::cout << "p1 = Proportion8_t(0.5)" << std::endl;
		std::cout << "p2 = Proportion8_t(0.25)" << std::endl;
		auto p1 = Proportion8_t(0.5);
		auto p2 = Proportion8_t(0.25);
		std::cout << "29. p1 + p2 == Proportion8_t::DirectConstruct(192) -> true?";
		return check_if((p1 + p2) == Proportion8_t::DirectConstruct(192));
	},
	[]()
	{
		std::cout << "p1 = Proportion8_t(0.5)" << std::endl;
		std::cout << "p2 = Proportion8_t(0.25)" << std::endl;
		auto p1 = Proportion8_t(0.5);
		auto p2 = Proportion8_t(0.25);
		std::cout << "30. p1 - p2 == p2 -> true?";
		return check_if((p1 - p2) == p2);
	},
	[]()
	{
		std::cout << "p1 = Proportion8_t(0.5)" << std::endl;
		std::cout << "p2 = Proportion8_t(0.25)" << std::endl;
		auto p1 = Proportion8_t(0.5);
		auto p2 = Proportion8_t(0.25);
		std::cout << "31. p1 * p2 == Proportion8_t(0.125) -> true?";
		return check_if((p1 * p2) == Proportion8_t(0.125));
	},
	[]()
	{
		std::cout << "p1 = Proportion8_t(0.5)" << std::endl;
		std::cout << "p2 = Proportion8_t(0.25)" << std::endl;
		auto p1 = Proportion8_t(0.5);
		auto p2 = Proportion8_t(0.25);
		std::cout << "32. p2 / p1 == Proportion8_t::DirectConstruct(127) -> true?";
		return check_if((p2 / p1) == Proportion8_t::DirectConstruct(127));
	},
	[]()
	{
		std::cout << "p1 = Proportion8_t(0.5)" << std::endl;
		std::cout << "p3 = Proportion32_t(0.5)" << std::endl;
		auto p1 = Proportion8_t(0.5);
		auto p3 = Proportion32_t(0.5);
		std::cout << "33. Proportion8_t(p3) == p1 -> true?";
		return check_if(Proportion8_t(p3) == p1);
	},
	[]()
	{
		std::cout << "p2 = Proportion8_t(0.25)" << std::endl;
		auto p2 = Proportion8_t(0.25);
		std::cout.precision(16);
		std::cout << "34. Proportion64_t(p2) ? " << double(Proportion64_t(p2)) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "p2 = Proportion8_t(0.25)" << std::endl;
		auto p2 = Proportion8_t(0.25);
		std::cout.precision(16);
		std::cout << "35. Proportion64_t(p2).Data ? " << (Proportion64_t(p2).Data()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "p4 = Proportion16_t(0.125)" << std::endl;
		std::cout << "f1 = FixedPoint16q15_t(0.125)" << std::endl;
		auto p4 = Proportion16_t(0.125);
		auto f1 = FixedPoint16q15_t(0.125);
		std::cout << "36. Proportion16_t(f1) == p4 -> true?";
		return check_if(Proportion16_t(f1) == p4);
	},
	[]()
	{
		std::cout << "p5 = Proportion1_t::Max()" << std::endl;
		std::cout << "p6 = Proportion8_t::Max()" << std::endl;
		auto p5 = Proportion1_t::Max();
		auto p6 = Proportion8_t::Max();
		std::cout << "37. Proportion8_t(p5) == p6 -> true?";
		return check_if(Proportion8_t(p5) == p6);
	},
};


int main(int argc, char const *argv[])
{
	std::cout << "<--- Proportion --->" << std::endl;
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
