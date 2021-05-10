//	stationaryorbit.core.test.logic:/test.logic.cpp
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

std::array<std::function<int(void)>, 45> tests =
{
	[]()
	{
		std::cout << "2. T ? " << Logic::True() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "3. F ? " << Logic::False() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "4. I ? " << Logic::Indefinited() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "5. U ? " << Logic::Undefined() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "6. T | T ? " << (Logic::True() || Logic::True()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "7. T | F ? " << (Logic::True() || Logic::False()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "8. T | I ? " << (Logic::True() || Logic::Indefinited()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "9. T | U ? " << (Logic::True() || Logic::Undefined()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "10. F | T ? " << (Logic::False() || Logic::True()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "11. F | F ? " << (Logic::False() || Logic::False()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "12. F | I ? " << (Logic::False() || Logic::Indefinited()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "13. F | U ? " << (Logic::False() || Logic::Undefined()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "14. I | T ? " << (Logic::Indefinited() || Logic::True()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "15. I | F ? " << (Logic::Indefinited() || Logic::False()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "16. I | I ? " << (Logic::Indefinited() || Logic::Indefinited()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "17. I | U ? " << (Logic::Indefinited() || Logic::Undefined()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "18. U | T ? " << (Logic::Undefined() || Logic::True()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "19. U | F ? " << (Logic::Undefined() || Logic::False()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "20. U | I ? " << (Logic::Undefined() || Logic::Indefinited()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "21. U | U ? " << (Logic::Undefined() || Logic::Undefined()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "22. T & T ? " << (Logic::True() && Logic::True()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "23. T & F ? " << (Logic::True() && Logic::False()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "24. T & I ? " << (Logic::True() && Logic::Indefinited()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "25. T & U ? " << (Logic::True() && Logic::Undefined()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "26. F & T ? " << (Logic::False() && Logic::True()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "27. F & F ? " << (Logic::False() && Logic::False()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "28. F & I ? " << (Logic::False() && Logic::Indefinited()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "29. F & U ? " << (Logic::False() && Logic::Undefined()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "30. I & T ? " << (Logic::Indefinited() && Logic::True()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "31. I & F ? " << (Logic::Indefinited() && Logic::False()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "32. I & I ? " << (Logic::Indefinited() && Logic::Indefinited()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "33. I & U ? " << (Logic::Indefinited() && Logic::Undefined()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "34. U & T ? " << (Logic::Undefined() && Logic::True()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "35. U & F ? " << (Logic::Undefined() && Logic::False()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "36. U & I ? " << (Logic::Undefined() && Logic::Indefinited()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "37. U & U ? " << (Logic::Undefined() && Logic::Undefined()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "38. !T ? " << (!Logic::True()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "39. !F ? " << (!Logic::False()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "40. !I ? " << (!Logic::Indefinited()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "41. !U ? " << (!Logic::Undefined()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "42. T == T -> true?";
		return check_if(Logic::True() == Logic::True());
	},
	[]()
	{
		std::cout << "43. F == F -> true?";
		return check_if(Logic::False() == Logic::False());
	},
	[]()
	{
		std::cout << "44. I == I -> true?";
		return check_if(Logic::Indefinited() == Logic::Indefinited());
	},
	[]()
	{
		std::cout << "45. U != U -> true?";
		return check_if(Logic::Undefined() != Logic::Undefined());
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- Logic --->" << std::endl;
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
