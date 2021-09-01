//	stationaryorbit.core.test.integer:/test.integer.cpp
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

std::array<std::function<int(void)>, 23> tests =
{
	[]()
	{
		std::cout << "1. Type Integer<std::byte> meets the traits IntegralType?";
		return check_if(NumericalTraits::IsIntegralType<Integer<std::byte>>);
	},
	[]()
	{
		std::cout << "2. Type Integer<uint8_t> meets the traits IntegralType?";
		return check_if(NumericalTraits::IsIntegralType<Integer<uint8_t>>);
	},
	[]()
	{
		std::cout << "3. Type Integer<uint16_t> meets the traits IntegralType?";
		return check_if(NumericalTraits::IsIntegralType<Integer<uint16_t>>);
	},
	[]()
	{
		std::cout << "4. Type Integer<uint32_t> meets the traits IntegralType?";
		return check_if(NumericalTraits::IsIntegralType<Integer<uint32_t>>);
	},
	[]()
	{
		std::cout << "5. Type Integer<uint64_t> meets the traits IntegralType?";
		return check_if(NumericalTraits::IsIntegralType<Integer<uint64_t>>);
	},
	[]()
	{
		std::cout << "6. Type SignedInteger<std::byte> meets the traits IntegralType?";
		return check_if(NumericalTraits::IsIntegralType<SignedInteger<std::byte>>);
	},
	[]()
	{
		std::cout << "7. Type SignedInteger<uint8_t> meets the traits IntegralType?";
		return check_if(NumericalTraits::IsIntegralType<SignedInteger<uint8_t>>);
	},
	[]()
	{
		std::cout << "8. Type SignedInteger<uint16_t> meets the traits IntegralType?";
		return check_if(NumericalTraits::IsIntegralType<SignedInteger<uint16_t>>);
	},
	[]()
	{
		std::cout << "9. Type SignedInteger<uint32_t> meets the traits IntegralType?";
		return check_if(NumericalTraits::IsIntegralType<SignedInteger<uint32_t>>);
	},
	[]()
	{
		std::cout << "10. Type SignedInteger<uint64_t> meets the traits IntegralType?";
		return check_if(NumericalTraits::IsIntegralType<SignedInteger<uint64_t>>);
	},
	[]()
	{
		std::cout << "v1 = Integer<std::byte>(12)" << std::endl;
		std::cout << "v2 = Integer<std::byte>(5)" << std::endl;
		auto v1 = Integer<std::byte>(uint8_t(12));
		auto v2 = Integer<std::byte>(uint8_t(5));
		std::cout << "11. v1 + v2 == 17?";
		return check_if((v1 + v2) == Integer<std::byte>(uint8_t(17)));
	},
	[]()
	{
		std::cout << "v1 = Integer<std::byte>(12)" << std::endl;
		std::cout << "v2 = Integer<std::byte>(5)" << std::endl;
		auto v1 = Integer<std::byte>(uint8_t(12));
		auto v2 = Integer<std::byte>(uint8_t(5));
		std::cout << "12. v1 - v2 == 7?";
		return check_if((v1 - v2) == Integer<std::byte>(uint8_t(7)));
	},
	[]()
	{
		std::cout << "v1 = Integer<std::byte>(12)" << std::endl;
		std::cout << "v2 = Integer<std::byte>(5)" << std::endl;
		auto v1 = Integer<std::byte>(uint8_t(12));
		auto v2 = Integer<std::byte>(uint8_t(5));
		std::cout << "13. v1 * v2 == 60?";
		return check_if((v1 * v2) == Integer<std::byte>(uint8_t(60)));
	},
	[]()
	{
		std::cout << "v1 = Integer<std::byte>(12)" << std::endl;
		std::cout << "v2 = Integer<std::byte>(5)" << std::endl;
		auto v1 = Integer<std::byte>(uint8_t(12));
		auto v2 = Integer<std::byte>(uint8_t(5));
		std::cout << "14. v1 / v2 == 2?";
		return check_if((v1 / v2) == Integer<std::byte>(uint8_t(2)));
	},
	[]()
	{
		std::cout << "v1 = Integer<std::byte>(12)" << std::endl;
		std::cout << "v2 = Integer<std::byte>(5)" << std::endl;
		auto v1 = Integer<std::byte>(uint8_t(12));
		auto v2 = Integer<std::byte>(uint8_t(5));
		std::cout << "15. v1 % v2 == 2?";
		return check_if((v1 % v2) == Integer<std::byte>(uint8_t(2)));
	},
	[]()
	{
		std::cout << "v1 = SignedInteger<std::byte>(12)" << std::endl;
		std::cout << "v2 = SignedInteger<std::byte>(5)" << std::endl;
		auto v1 = SignedInteger<std::byte>(int8_t(12));
		auto v2 = SignedInteger<std::byte>(int8_t(5));
		std::cout << "16. v1 + v2 == 17?";
		return check_if((v1 + v2) == SignedInteger<std::byte>(int8_t(17)));
	},
	[]()
	{
		std::cout << "v1 = SignedInteger<std::byte>(12)" << std::endl;
		std::cout << "v2 = SignedInteger<std::byte>(5)" << std::endl;
		auto v1 = SignedInteger<std::byte>(int8_t(12));
		auto v2 = SignedInteger<std::byte>(int8_t(5));
		std::cout << "17. v1 - v2 == 7?";
		return check_if((v1 - v2) == SignedInteger<std::byte>(int8_t(7)));
	},
	[]()
	{
		std::cout << "v1 = SignedInteger<std::byte>(12)" << std::endl;
		std::cout << "v2 = SignedInteger<std::byte>(5)" << std::endl;
		auto v1 = SignedInteger<std::byte>(int8_t(12));
		auto v2 = SignedInteger<std::byte>(int8_t(5));
		std::cout << "18. v2 - v1 == -7?";
		return check_if((v2 - v1) == SignedInteger<std::byte>(int8_t(-7)));
	},
	[]()
	{
		std::cout << "v1 = SignedInteger<std::byte>(12)" << std::endl;
		std::cout << "v2 = SignedInteger<std::byte>(5)" << std::endl;
		auto v1 = SignedInteger<std::byte>(int8_t(12));
		auto v2 = SignedInteger<std::byte>(int8_t(5));
		std::cout << "19. v1 * v2 == 60?";
		return check_if((v1 * v2) == SignedInteger<std::byte>(int8_t(60)));
	},
	[]()
	{
		std::cout << "v1 = SignedInteger<std::byte>(12)" << std::endl;
		std::cout << "v2 = SignedInteger<std::byte>(-5)" << std::endl;
		auto v1 = SignedInteger<std::byte>(int8_t(12));
		auto v2 = SignedInteger<std::byte>(int8_t(-5));
		std::cout << "20. v1 * v2 == -60?";
		return check_if((v1 * v2) == SignedInteger<std::byte>(int8_t(-60)));
	},
	[]()
	{
		std::cout << "v1 = SignedInteger<std::byte>(12)" << std::endl;
		std::cout << "v2 = SignedInteger<std::byte>(5)" << std::endl;
		auto v1 = SignedInteger<std::byte>(int8_t(12));
		auto v2 = SignedInteger<std::byte>(int8_t(5));
		std::cout << "21. v1 / v2 == 2?";
		return check_if((v1 / v2) == SignedInteger<std::byte>(int8_t(2)));
	},
	[]()
	{
		std::cout << "v1 = SignedInteger<std::byte>(-12)" << std::endl;
		std::cout << "v2 = SignedInteger<std::byte>(5)" << std::endl;
		auto v1 = SignedInteger<std::byte>(int8_t(-12));
		auto v2 = SignedInteger<std::byte>(int8_t(5));
		std::cout << "22. v1 / v2 == -2?";
		return check_if((v1 / v2) == SignedInteger<std::byte>(int8_t(-2)));
	},
	[]()
	{
		std::cout << "v1 = SignedInteger<std::byte>(12)" << std::endl;
		std::cout << "v2 = SignedInteger<std::byte>(5)" << std::endl;
		auto v1 = SignedInteger<std::byte>(int8_t(12));
		auto v2 = SignedInteger<std::byte>(int8_t(5));
		std::cout << "23. v1 % v2 == 2?";
		return check_if((v1 % v2) == SignedInteger<std::byte>(int8_t(2)));
	},
};


int main(int argc, char const *argv[])
{
	std::cout << "<--- Integer --->" << std::endl;
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
