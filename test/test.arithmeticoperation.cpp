//	stationaryorbit.core.test.arithmeticoperation:/test.arithmeticoperation.cpp
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

constexpr uint32_t n1 = 143;
constexpr uint32_t n2 = 13;
constexpr uint32_t n3 = 4294921510;
constexpr uint32_t n4 = 71720;
constexpr int32_t n5 = 9780;
constexpr int32_t n6 = 7202;
constexpr int32_t n7 = 2147437862;
constexpr int32_t n8 = 71720;
constexpr int32_t n9 = 8585;
constexpr int32_t n10 = -10745;
constexpr int32_t n11 = -108708;
constexpr int32_t n12 = -2147429012;
constexpr int32_t n13 = -532;
constexpr int32_t n14 = -3248;
constexpr int32_t n15 = -6343;
constexpr int32_t n16 = 11923;

std::array<std::function<int(void)>, 160> tests =
{
	[]()
	{
		std::cout << "1. ArithmeticOperation::add(n1, n2).result ? " << ArithmeticOperation::add(n1, n2).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "2. ArithmeticOperation::add(n1, n2).status ? " << ArithmeticOperation::add(n1, n2).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "3. ArithmeticOperation::add(n3, n4).result ? " << ArithmeticOperation::add(n3, n4).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "4. ArithmeticOperation::add(n3, n4).status ? " << ArithmeticOperation::add(n3, n4).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "5. ArithmeticOperation::add(n5, n6).result ? " << ArithmeticOperation::add(n5, n6).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "6. ArithmeticOperation::add(n5, n6).status ? " << ArithmeticOperation::add(n5, n6).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "7. ArithmeticOperation::add(n7, n8).result ? " << ArithmeticOperation::add(n7, n8).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "8. ArithmeticOperation::add(n7, n8).status ? " << ArithmeticOperation::add(n7, n8).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "9. ArithmeticOperation::add(n9, n10).result ? " << ArithmeticOperation::add(n9, n10).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "10. ArithmeticOperation::add(n9, n10).status ? " << ArithmeticOperation::add(n9, n10).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "11. ArithmeticOperation::add(n11, n12).result ? " << ArithmeticOperation::add(n11, n12).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "12. ArithmeticOperation::add(n11, n12).status ? " << ArithmeticOperation::add(n11, n12).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "13. ArithmeticOperation::add(n13, n14).result ? " << ArithmeticOperation::add(n13, n14).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "14. ArithmeticOperation::add(n13, n14).status ? " << ArithmeticOperation::add(n13, n14).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "15. ArithmeticOperation::add(n15, n16).result ? " << ArithmeticOperation::add(n15, n16).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "16. ArithmeticOperation::add(n15, n16).status ? " << ArithmeticOperation::add(n15, n16).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "17. ArithmeticOperation::subtract(n1, n2).result ? " << ArithmeticOperation::subtract(n1, n2).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "18. ArithmeticOperation::subtract(n1, n2).status ? " << ArithmeticOperation::subtract(n1, n2).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "19. ArithmeticOperation::subtract(n4, n3).result ? " << ArithmeticOperation::subtract(n4, n3).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "20. ArithmeticOperation::subtract(n4, n3).status ? " << ArithmeticOperation::subtract(n4, n3).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "21. ArithmeticOperation::subtract(n5, n6).result ? " << ArithmeticOperation::subtract(n5, n6).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "22. ArithmeticOperation::subtract(n5, n6).status ? " << ArithmeticOperation::subtract(n5, n6).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "23. ArithmeticOperation::subtract(-n8, n7).result ? " << ArithmeticOperation::subtract(-n8, n7).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "24. ArithmeticOperation::subtract(-n8, n7).status ? " << ArithmeticOperation::subtract(-n8, n7).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "25. ArithmeticOperation::subtract(n9, n10).result ? " << ArithmeticOperation::subtract(n9, n10).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "26. ArithmeticOperation::subtract(n9, n10).status ? " << ArithmeticOperation::subtract(n9, n10).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "27. ArithmeticOperation::subtract(-n11, n12).result ? " << ArithmeticOperation::subtract(-n11, n12).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "28. ArithmeticOperation::subtract(-n11, n12).status ? " << ArithmeticOperation::subtract(-n11, n12).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "29. ArithmeticOperation::subtract(n13, n14).result ? " << ArithmeticOperation::subtract(n13, n14).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "30. ArithmeticOperation::subtract(n13, n14).status ? " << ArithmeticOperation::subtract(n13, n14).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "31. ArithmeticOperation::subtract(n15, n16).result ? " << ArithmeticOperation::subtract(n15, n16).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "32. ArithmeticOperation::subtract(n15, n16).status ? " << ArithmeticOperation::subtract(n15, n16).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "33. ArithmeticOperation::multiply(n1, n2).result ? " << ArithmeticOperation::multiply(n1, n2).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "34. ArithmeticOperation::multiply(n1, n2).status ? " << ArithmeticOperation::multiply(n1, n2).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "35. ArithmeticOperation::multiply(n3, n4).result ? " << ArithmeticOperation::multiply(n3, n4).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "36. ArithmeticOperation::multiply(n3, n4).status ? " << ArithmeticOperation::multiply(n3, n4).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "37. ArithmeticOperation::multiply(n5, n6).result ? " << ArithmeticOperation::multiply(n5, n6).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "38. ArithmeticOperation::multiply(n5, n6).status ? " << ArithmeticOperation::multiply(n5, n6).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "39. ArithmeticOperation::multiply(n7, n8).result ? " << ArithmeticOperation::multiply(n7, n8).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "40. ArithmeticOperation::multiply(n7, n8).status ? " << ArithmeticOperation::multiply(n7, n8).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "41. ArithmeticOperation::multiply(n9, n10).result ? " << ArithmeticOperation::multiply(n9, n10).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "42. ArithmeticOperation::multiply(n9, n10).status ? " << ArithmeticOperation::multiply(n9, n10).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "43. ArithmeticOperation::multiply(n11, n12).result ? " << ArithmeticOperation::multiply(n11, n12).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "44. ArithmeticOperation::multiply(n11, n12).status ? " << ArithmeticOperation::multiply(n11, n12).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "45. ArithmeticOperation::multiply(n13, n14).result ? " << ArithmeticOperation::multiply(n13, n14).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "46. ArithmeticOperation::multiply(n13, n14).status ? " << ArithmeticOperation::multiply(n13, n14).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "47. ArithmeticOperation::multiply(n15, n16).result ? " << ArithmeticOperation::multiply(n15, n16).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "48. ArithmeticOperation::multiply(n15, n16).status ? " << ArithmeticOperation::multiply(n15, n16).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "49. ArithmeticOperation::divide(n1, n2).result ? " << ArithmeticOperation::divide(n1, n2).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "50. ArithmeticOperation::divide(n1, n2).status ? " << ArithmeticOperation::divide(n1, n2).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "51. ArithmeticOperation::divide(n3, 0).result ? " << ArithmeticOperation::divide(n3, uint32_t(0)).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "52. ArithmeticOperation::divide(n3, 0).status ? " << ArithmeticOperation::divide(n3, uint32_t(0)).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "53. ArithmeticOperation::divide(n5, n6).result ? " << ArithmeticOperation::divide(n5, n6).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "54. ArithmeticOperation::divide(n5, n6).status ? " << ArithmeticOperation::divide(n5, n6).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "55. ArithmeticOperation::divide(n7, int32_t(0)).result ? " << ArithmeticOperation::divide(n7, int32_t(0)).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "56. ArithmeticOperation::divide(n7, int32_t(0)).status ? " << ArithmeticOperation::divide(n7, int32_t(0)).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "57. ArithmeticOperation::divide(n9, n10).result ? " << ArithmeticOperation::divide(n9, n10).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "58. ArithmeticOperation::divide(n9, n10).status ? " << ArithmeticOperation::divide(n9, n10).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "59. ArithmeticOperation::divide(n11, int32_t(0)).result ? " << ArithmeticOperation::divide(n11, int32_t(0)).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "60. ArithmeticOperation::divide(n11, int32_t(0)).status ? " << ArithmeticOperation::divide(n11, int32_t(0)).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "61. ArithmeticOperation::divide(n14, n13).result ? " << ArithmeticOperation::divide(n14, n13).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "62. ArithmeticOperation::divide(n14, n13).status ? " << ArithmeticOperation::divide(n14, n13).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "63. ArithmeticOperation::divide(n16, n15).result ? " << ArithmeticOperation::divide(n16, n15).result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "64. ArithmeticOperation::divide(n16, n15).status ? " << ArithmeticOperation::divide(n16, n15).status << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "65. ArithmeticOperation::add_saturate(n1, n2) ? " << ArithmeticOperation::add_saturate(n1, n2) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "66. ArithmeticOperation::add_saturate(n3, n4) ? " << ArithmeticOperation::add_saturate(n3, n4) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "67. ArithmeticOperation::add_saturate(n5, n6) ? " << ArithmeticOperation::add_saturate(n5, n6) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "68. ArithmeticOperation::add_saturate(n7, n8) ? " << ArithmeticOperation::add_saturate(n7, n8) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "69. ArithmeticOperation::add_saturate(n9, n10) ? " << ArithmeticOperation::add_saturate(n9, n10) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "70. ArithmeticOperation::add_saturate(n11, n12) ? " << ArithmeticOperation::add_saturate(n11, n12) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "71. ArithmeticOperation::add_saturate(n13, n14) ? " << ArithmeticOperation::add_saturate(n13, n14) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "72. ArithmeticOperation::add_saturate(n15, n16) ? " << ArithmeticOperation::add_saturate(n15, n16) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "73. ArithmeticOperation::subtract_saturate(n1, n2) ? " << ArithmeticOperation::subtract_saturate(n1, n2) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "74. ArithmeticOperation::subtract_saturate(n4, n3) ? " << ArithmeticOperation::subtract_saturate(n4, n3) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "75. ArithmeticOperation::subtract_saturate(n5, n6) ? " << ArithmeticOperation::subtract_saturate(n5, n6) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "76. ArithmeticOperation::subtract_saturate(-n8, n7) ? " << ArithmeticOperation::subtract_saturate(-n8, n7) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "77. ArithmeticOperation::subtract_saturate(n9, n10) ? " << ArithmeticOperation::subtract_saturate(n9, n10) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "78. ArithmeticOperation::subtract_saturate(-n11, n12) ? " << ArithmeticOperation::subtract_saturate(-n11, n12) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "79. ArithmeticOperation::subtract_saturate(n13, n14) ? " << ArithmeticOperation::subtract_saturate(n13, n14) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "80. ArithmeticOperation::subtract_saturate(n15, n16) ? " << ArithmeticOperation::subtract_saturate(n15, n16) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "81. ArithmeticOperation::multiply_saturate(n1, n2) ? " << ArithmeticOperation::multiply_saturate(n1, n2) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "82. ArithmeticOperation::multiply_saturate(n3, n4) ? " << ArithmeticOperation::multiply_saturate(n3, n4) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "83. ArithmeticOperation::multiply_saturate(n5, n6) ? " << ArithmeticOperation::multiply_saturate(n5, n6) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "84. ArithmeticOperation::multiply_saturate(n7, n8) ? " << ArithmeticOperation::multiply_saturate(n7, n8) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "85. ArithmeticOperation::multiply_saturate(n9, n10) ? " << ArithmeticOperation::multiply_saturate(n9, n10) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "86. ArithmeticOperation::multiply_saturate(n11, n12) ? " << ArithmeticOperation::multiply_saturate(n11, n12) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "87. ArithmeticOperation::multiply_saturate(n13, n14) ? " << ArithmeticOperation::multiply_saturate(n13, n14) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "88. ArithmeticOperation::multiply_saturate(n15, n16) ? " << ArithmeticOperation::multiply_saturate(n15, n16) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "89. ArithmeticOperation::divide_saturate(n1, n2) ? " << ArithmeticOperation::divide_saturate(n1, n2) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "90. ArithmeticOperation::divide_saturate(n3, 0) ? ";
		try
		{
			std::cout << ArithmeticOperation::divide_saturate(n3, uint32_t(0)) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "91. ArithmeticOperation::divide_saturate(n5, n6) ? " << ArithmeticOperation::divide_saturate(n5, n6) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "92. ArithmeticOperation::divide_saturate(n7, int32_t(0)) ? ";
		try
		{
			std::cout << ArithmeticOperation::divide_saturate(n7, int32_t(0)) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "93. ArithmeticOperation::divide_saturate(n9, n10) ? " << ArithmeticOperation::divide_saturate(n9, n10) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "94. ArithmeticOperation::divide_saturate(n11, int32_t(0)) ? ";
		try
		{
			std::cout << ArithmeticOperation::divide_saturate(n11, int32_t(0)) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "95. ArithmeticOperation::divide_saturate(n14, n13) ? " << ArithmeticOperation::divide_saturate(n14, n13) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "96. ArithmeticOperation::divide_saturate(n16, n15) ? " << ArithmeticOperation::divide_saturate(n16, n15) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "97. ArithmeticOperation::add_checked(n1, n2) ? " << ArithmeticOperation::add_checked(n1, n2) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "98. ArithmeticOperation::add_checked(n3, n4) ? ";
		try
		{
			std::cout << ArithmeticOperation::add_checked(n3, n4) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "99. ArithmeticOperation::add_checked(n5, n6) ? " << ArithmeticOperation::add_checked(n5, n6) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "100. ArithmeticOperation::add_checked(n7, n8) ? ";
		try
		{
			std::cout << ArithmeticOperation::add_checked(n7, n8) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "101. ArithmeticOperation::add_checked(n9, n10) ? " << ArithmeticOperation::add_checked(n9, n10) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "102. ArithmeticOperation::add_checked(n11, n12) ? ";
		try
		{
			std::cout << ArithmeticOperation::add_checked(n11, n12) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "103. ArithmeticOperation::add_checked(n13, n14) ? " << ArithmeticOperation::add_checked(n13, n14) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "104. ArithmeticOperation::add_checked(n15, n16) ? " << ArithmeticOperation::add_checked(n15, n16) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "105. ArithmeticOperation::subtract_checked(n1, n2) ? " << ArithmeticOperation::subtract_checked(n1, n2) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "106. ArithmeticOperation::subtract_checked(n4, n3) ? ";
		try
		{
			std::cout << ArithmeticOperation::subtract_checked(n4, n3) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "107. ArithmeticOperation::subtract_checked(n5, n6) ? " << ArithmeticOperation::subtract_checked(n5, n6) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "108. ArithmeticOperation::subtract_checked(-n8, n7) ? ";
		try
		{
			std::cout << ArithmeticOperation::subtract_checked(-n8, n7) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "109. ArithmeticOperation::subtract_checked(n9, n10) ? " << ArithmeticOperation::subtract_checked(n9, n10) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "110. ArithmeticOperation::subtract_checked(-n11, n12) ? ";
		try
		{
			std::cout << ArithmeticOperation::subtract_checked(-n11, n12) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "111. ArithmeticOperation::subtract_checked(n13, n14) ? " << ArithmeticOperation::subtract_checked(n13, n14) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "112. ArithmeticOperation::subtract_checked(n15, n16) ? " << ArithmeticOperation::subtract_checked(n15, n16) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "113. ArithmeticOperation::multiply_checked(n1, n2) ? " << ArithmeticOperation::multiply_checked(n1, n2) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "114. ArithmeticOperation::multiply_checked(n3, n4) ? ";
		try
		{
			std::cout << ArithmeticOperation::multiply_checked(n3, n4) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "115. ArithmeticOperation::multiply_checked(n5, n6) ? " << ArithmeticOperation::multiply_checked(n5, n6) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "116. ArithmeticOperation::multiply_checked(n7, n8) ? ";
		try
		{
			std::cout << ArithmeticOperation::multiply_checked(n7, n8) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "117. ArithmeticOperation::multiply_checked(n9, n10) ? " << ArithmeticOperation::multiply_checked(n9, n10) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "118. ArithmeticOperation::multiply_checked(n11, n12) ? ";
		try
		{
			std::cout << ArithmeticOperation::multiply_checked(n11, n12) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "119. ArithmeticOperation::multiply_checked(n13, n14) ? " << ArithmeticOperation::multiply_checked(n13, n14) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "120. ArithmeticOperation::multiply_checked(n15, n16) ? " << ArithmeticOperation::multiply_checked(n15, n16) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "121. ArithmeticOperation::divide_checked(n1, n2) ? " << ArithmeticOperation::divide_checked(n1, n2) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "122. ArithmeticOperation::divide_checked(n3, 0) ? ";
		try
		{
			std::cout << ArithmeticOperation::divide_checked(n3, uint32_t(0)) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "123. ArithmeticOperation::divide_checked(n5, n6) ? " << ArithmeticOperation::divide_checked(n5, n6) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "124. ArithmeticOperation::divide_checked(n7, int32_t(0)) ? ";
		try
		{
			std::cout << ArithmeticOperation::divide_checked(n7, int32_t(0)) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "125. ArithmeticOperation::divide_checked(n9, n10) ? " << ArithmeticOperation::divide_checked(n9, n10) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "126. ArithmeticOperation::divide_checked(n11, int32_t(0)) ? ";
		try
		{
			std::cout << ArithmeticOperation::divide_checked(n11, int32_t(0)) << std::endl;
			return 0;
		}
		catch (std::range_error e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
	},
	[]()
	{
		std::cout << "127. ArithmeticOperation::divide_checked(n14, n13) ? " << ArithmeticOperation::divide_checked(n14, n13) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "128. ArithmeticOperation::divide_checked(n16, n15) ? " << ArithmeticOperation::divide_checked(n16, n15) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "129. ArithmeticOperation::may_overflow_addition(n1, n2) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_addition(n1, n2));
	},
	[]()
	{
		std::cout << "130. ArithmeticOperation::may_overflow_addition(n3, n4) ->true?";
		return check_if(ArithmeticOperation::may_overflow_addition(n3, n4));
	},
	[]()
	{
		std::cout << "131. ArithmeticOperation::may_overflow_addition(n5, n6) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_addition(n5, n6));
	},
	[]()
	{
		std::cout << "132. ArithmeticOperation::may_overflow_addition(n7, n8) ->true?";
		return check_if(ArithmeticOperation::may_overflow_addition(n7, n8));
	},
	[]()
	{
		std::cout << "133. ArithmeticOperation::may_overflow_addition(n9, n10) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_addition(n9, n10));
	},
	[]()
	{
		std::cout << "134. ArithmeticOperation::may_overflow_addition(n11, n12) ->true?";
		return check_if(ArithmeticOperation::may_overflow_addition(n11, n12));
	},
	[]()
	{
		std::cout << "135. ArithmeticOperation::may_overflow_addition(n13, n14) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_addition(n13, n14));
	},
	[]()
	{
		std::cout << "136. ArithmeticOperation::may_overflow_addition(n15, n16) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_addition(n15, n16));
	},
	[]()
	{
		std::cout << "137. ArithmeticOperation::may_overflow_subtraction(n1, n2) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_subtraction(n1, n2));
	},
	[]()
	{
		std::cout << "138. ArithmeticOperation::may_overflow_subtraction(n4, n3) ->true?";
		return check_if(ArithmeticOperation::may_overflow_subtraction(n4, n3));
	},
	[]()
	{
		std::cout << "139. ArithmeticOperation::may_overflow_subtraction(n5, n6) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_subtraction(n5, n6));
	},
	[]()
	{
		std::cout << "140. ArithmeticOperation::may_overflow_subtraction(-n8, n7) ->true?";
		return check_if(ArithmeticOperation::may_overflow_subtraction(-n8, n7));
	},
	[]()
	{
		std::cout << "141. ArithmeticOperation::may_overflow_subtraction(n9, n10) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_subtraction(n9, n10));
	},
	[]()
	{
		std::cout << "142. ArithmeticOperation::may_overflow_subtraction(-n11, n12) ->true?";
		return check_if(ArithmeticOperation::may_overflow_subtraction(-n11, n12));
	},
	[]()
	{
		std::cout << "143. ArithmeticOperation::may_overflow_subtraction(n13, n14) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_subtraction(n13, n14));
	},
	[]()
	{
		std::cout << "144. ArithmeticOperation::may_overflow_subtraction(n15, n16) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_subtraction(n15, n16));
	},
	[]()
	{
		std::cout << "145. ArithmeticOperation::may_overflow_multiplication(n1, n2) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_multiplication(n1, n2));
	},
	[]()
	{
		std::cout << "146. ArithmeticOperation::may_overflow_multiplication(n3, n4) ->true?";
		return check_if(ArithmeticOperation::may_overflow_multiplication(n3, n4));
	},
	[]()
	{
		std::cout << "147. ArithmeticOperation::may_overflow_multiplication(n5, n6) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_multiplication(n5, n6));
	},
	[]()
	{
		std::cout << "148. ArithmeticOperation::may_overflow_multiplication(n7, n8) ->true?";
		return check_if(ArithmeticOperation::may_overflow_multiplication(n7, n8));
	},
	[]()
	{
		std::cout << "149. ArithmeticOperation::may_overflow_multiplication(n9, n10) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_multiplication(n9, n10));
	},
	[]()
	{
		std::cout << "150. ArithmeticOperation::may_overflow_multiplication(n11, n12) ->true?";
		return check_if(ArithmeticOperation::may_overflow_multiplication(n11, n12));
	},
	[]()
	{
		std::cout << "151. ArithmeticOperation::may_overflow_multiplication(n13, n14) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_multiplication(n13, n14));
	},
	[]()
	{
		std::cout << "152. ArithmeticOperation::may_overflow_multiplication(n15, n16) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_multiplication(n15, n16));
	},
	[]()
	{
		std::cout << "153. ArithmeticOperation::may_overflow_division(n1, n2) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_division(n1, n2));
	},
	[]()
	{
		std::cout << "154. ArithmeticOperation::may_overflow_division(n3, 0) ->true?";
		return check_if(ArithmeticOperation::may_overflow_division(n3, uint32_t(0)));
	},
	[]()
	{
		std::cout << "155. ArithmeticOperation::may_overflow_division(n5, n6) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_division(n5, n6));
	},
	[]()
	{
		std::cout << "156. ArithmeticOperation::may_overflow_division(n7, int32_t(0)) ->true?";
		return check_if(ArithmeticOperation::may_overflow_division(n7, int32_t(0)));
	},
	[]()
	{
		std::cout << "157. ArithmeticOperation::may_overflow_division(n9, n10) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_division(n9, n10));
	},
	[]()
	{
		std::cout << "158. ArithmeticOperation::may_overflow_division(n11, int32_t(0)) ->true?";
		return check_if(ArithmeticOperation::may_overflow_division(n11, int32_t(0)));
	},
	[]()
	{
		std::cout << "159. ArithmeticOperation::may_overflow_division(n14, n13) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_division(n14, n13));
	},
	[]()
	{
		std::cout << "160. ArithmeticOperation::may_overflow_division(n16, n15) ->false?";
		return check_if(!ArithmeticOperation::may_overflow_division(n16, n15));
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- ArithmeticOperation --->" << std::endl;
	std::cout << "n1 = uint32_t(" << n1 << ")" << std::endl;
	std::cout << "n2 = uint32_t(" << n2 << ")" << std::endl;
	std::cout << "n3 = uint32_t(" << n3 << ")" << std::endl;
	std::cout << "n4 = uint32_t(" << n4 << ")" << std::endl;
	std::cout << "n5 = int32_t(" << n5 << ")" << std::endl;
	std::cout << "n6 = int32_t(" << n6 << ")" << std::endl;
	std::cout << "n7 = int32_t(" << n7 << ")" << std::endl;
	std::cout << "n8 = int32_t(" << n8 << ")" << std::endl;
	std::cout << "n9 = int32_t(" << n9 << ")" << std::endl;
	std::cout << "n10 = int32_t(" << n10 << ")" << std::endl;
	std::cout << "n11 = int32_t(" << n11 << ")" << std::endl;
	std::cout << "n12 = int32_t(" << n12 << ")" << std::endl;
	std::cout << "n13 = int32_t(" << n13 << ")" << std::endl;
	std::cout << "n14 = int32_t(" << n14 << ")" << std::endl;
	std::cout << "n15 = int32_t(" << n15 << ")" << std::endl;
	std::cout << "n16 = int32_t(" << n16 << ")" << std::endl;
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
