//	stationaryorbit.core.test.rotation:/test.rotation.cpp
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

Rotation32_t rot1 = Rotation32_t::from_degree(30);
Rotation32_t rot2 = Rotation32_t::from_radian(0.5 * M_PI);
Rotation32_t rot3 = Rotation32_t::from_degree(60);

std::array<std::function<int(void)>, 44> tests =
{
	[]()
	{
		std::cout << "1. rot1.radian ? " << rot1.radian() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "2. rot2.degree ? " << rot2.degree() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "3. rot1 + rot2 ? " << (rot1 + rot2).degree() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "4. rot1 - rot2 ? " << (rot1 - rot2).degree() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "5. rot2 * 2.0 ? " << (rot2 * 2.0).degree() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "6. rot1 / 2.0 ? " << (rot1 / 2.0).degree() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "7. rot1 == 30 deg -> true?";
		return check_if(rot1 == Rotation32_t::from_degree(30));
	},
	[]()
	{
		std::cout << "8. rot1 != 90 deg -> true?";
		return check_if(rot1 != Rotation32_t::from_degree(90));
	},
	[]()
	{
		std::cout << "9. rot1 < rot2 ->true?";
		return check_if(rot1 < rot2);
	},
	[]()
	{
		std::cout << "10. rot2 > rot3 ->true?";
		return check_if(rot2 > rot3);
	},
	[]()
	{
		std::cout << "11. rot1 >= 30 deg -> true?";
		return check_if(rot1 >= Rotation32_t::from_degree(30));
	},
	[]()
	{
		std::cout << "12. rot1 <= 30 deg -> true?";
		return check_if(rot1 <= Rotation32_t::from_degree(30));
	},
	[]()
	{
		std::cout << "13. 0deg.sin ? " << Rotation32_t::from_degree(0).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "14. 30deg.sin ? " << Rotation32_t::from_degree(30).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "15. 45deg.sin ? " << Rotation32_t::from_degree(45).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "16. 60deg.sin ? " << Rotation32_t::from_degree(60).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "17. 90deg.sin ? " << Rotation32_t::from_degree(90).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "18. 120deg.sin ? " << Rotation32_t::from_degree(120).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "19. 135deg.sin ? " << Rotation32_t::from_degree(135).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "20. 150deg.sin ? " << Rotation32_t::from_degree(150).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "21. 180deg.sin ? " << Rotation32_t::from_degree(180).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "22. 210deg.sin ? " << Rotation32_t::from_degree(210).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "23. 225deg.sin ? " << Rotation32_t::from_degree(225).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "24. 240deg.sin ? " << Rotation32_t::from_degree(240).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "25. 270deg.sin ? " << Rotation32_t::from_degree(270).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "26. 300deg.sin ? " << Rotation32_t::from_degree(300).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "27. 315deg.sin ? " << Rotation32_t::from_degree(315).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "28. 330deg.sin ? " << Rotation32_t::from_degree(330).sin() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "29. 0deg.cos ? " << Rotation32_t::from_degree(0).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "30. 30deg.cos ? " << Rotation32_t::from_degree(30).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "31. 45deg.cos ? " << Rotation32_t::from_degree(45).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "32. 60deg.cos ? " << Rotation32_t::from_degree(60).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "33. 90deg.cos ? " << Rotation32_t::from_degree(90).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "34. 120deg.cos ? " << Rotation32_t::from_degree(120).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "35. 135deg.cos ? " << Rotation32_t::from_degree(135).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "36. 150deg.cos ? " << Rotation32_t::from_degree(150).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "37. 180deg.cos ? " << Rotation32_t::from_degree(180).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "38. 210deg.cos ? " << Rotation32_t::from_degree(210).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "39. 225deg.cos ? " << Rotation32_t::from_degree(225).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "40. 240deg.cos ? " << Rotation32_t::from_degree(240).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "41. 270deg.cos ? " << Rotation32_t::from_degree(270).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "42. 300deg.cos ? " << Rotation32_t::from_degree(300).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "43. 315deg.cos ? " << Rotation32_t::from_degree(315).cos() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "44. 330deg.cos ? " << Rotation32_t::from_degree(330).cos() << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- Rotation --->" << std::endl;
	std::cout << "rot1 = 30 deg" << std::endl;
	std::cout << "rot2 = 0.5 PI rad" << std::endl;
	std::cout << "rot3 = 60 deg" << std::endl;
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
