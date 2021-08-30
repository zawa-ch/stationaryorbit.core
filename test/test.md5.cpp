//	stationaryorbit.core.test.md5:/test.md5.cpp
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

///	MD5 test pattern (expects d41d8cd98f00b204e9800998ecf8427e)
std::string test_pattern_0 = "";
///	MD5 test pattern (expects 0cc175b9c0f1b6a831c399e269772661)
std::string test_pattern_1 = "a";
///	MD5 test pattern (expects 900150983cd24fb0d6963f7d28e17f72)
std::string test_pattern_2 = "abc";
///	MD5 test pattern (expects f96b697d7cb7938d525a2f31aaf161d0)
std::string test_pattern_3 = "message digest";
///	MD5 test pattern (expects c3fcd3d76192e4007dfb496cca67e13b)
std::string test_pattern_4 = "abcdefghijklmnopqrstuvwxyz";
///	MD5 test pattern (expects d174ab98d277d9f5a5611c2c9f419d9f)
std::string test_pattern_5 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
///	MD5 test pattern (expects 57edf4a22be3c955ac49da2e2107b67a)
std::string test_pattern_6 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
///	MD5 test pattern (expects e4d909c290d0fb1ca068ffaddf22cbd0)
std::string test_pattern_7 = "The quick brown fox jumps over the lazy dog.";
///	MD5 test pattern (expects 119b13e82eaa45291fe89b97fda96ba7)
///	Quoted from `fortune` Napoleon I
std::string test_pattern_8 = "Ten persons who speak make more noise than ten thousand who are silent.";
///	MD5 test pattern (expects d89f0c2e36ca332482c9c599d417f8dc)
///	Quoted from `fortune` T. Cheatham
std::string test_pattern_9 = "If a group of N persons implements a COBOL compiler, there will be N-1 passes.  Someone in the group has to be the manager.";
///	MD5 test pattern (expects c8c4cd8d771d0a6f7dc7d08de43d0e18)
///	Quoted from `fortune`
std::string test_pattern_10 = "The time was the 19th of May, 1780.  The place was Hartford, Connecticut. The day has gone down in New England history as a terrible foretaste of Judgement Day.  For at noon the skies turned from blue to grey and by mid-afternoon had blackened over so densely that, in that religious age, men fell on their knees and begged a final blessing before the end came. The Connecticut House of Representatives was in session.  And, as some of the men fell down and others clamored for an immediate adjournment, the Speaker of the House, one Col. Davenport, came to his feet.  He silenced them and said these words: \"The day of judgment is either approaching or it is not.  If it is not, there is no cause for adjournment.  If it is, I choose to be found doing my duty.  I wish therefore that candles may be brought.\"  -- Alistair Cooke";

std::array<std::function<int(void)>, 75> tests =
{
	[]()
	{
		std::cout << "1. MD5Table(1) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 1>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "2. MD5Table(2) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 2>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "3. MD5Table(3) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 3>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "4. MD5Table(4) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 4>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "5. MD5Table(5) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 5>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "6. MD5Table(6) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 6>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "7. MD5Table(7) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 7>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "8. MD5Table(8) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 8>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "9. MD5Table(9) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 9>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "10. MD5Table(10) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 10>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "11. MD5Table(11) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 11>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "12. MD5Table(12) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 12>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "13. MD5Table(13) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 13>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "14. MD5Table(14) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 14>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "15. MD5Table(15) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 15>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "16. MD5Table(16) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 16>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "17. MD5Table(17) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 17>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "18. MD5Table(18) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 18>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "19. MD5Table(19) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 19>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "20. MD5Table(20) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 20>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "21. MD5Table(21) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 21>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "22. MD5Table(22) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 22>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "23. MD5Table(23) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 23>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "24. MD5Table(24) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 24>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "25. MD5Table(25) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 25>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "26. MD5Table(26) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 26>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "27. MD5Table(27) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 27>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "28. MD5Table(28) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 28>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "29. MD5Table(29) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 29>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "30. MD5Table(30) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 30>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "31. MD5Table(31) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 31>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "32. MD5Table(32) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 32>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "33. MD5Table(33) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 33>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "34. MD5Table(34) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 34>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "35. MD5Table(35) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 35>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "36. MD5Table(36) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 36>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "37. MD5Table(37) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 37>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "38. MD5Table(38) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 38>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "39. MD5Table(39) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 39>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "40. MD5Table(40) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 40>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "41. MD5Table(41) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 41>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "42. MD5Table(42) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 42>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "43. MD5Table(43) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 43>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "44. MD5Table(44) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 44>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "45. MD5Table(45) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 45>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "46. MD5Table(46) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 46>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "47. MD5Table(47) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 47>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "48. MD5Table(48) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 48>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "49. MD5Table(49) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 49>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "50. MD5Table(50) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 50>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "51. MD5Table(51) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 51>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "52. MD5Table(52) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 52>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "53. MD5Table(53) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 53>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "54. MD5Table(54) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 54>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "55. MD5Table(55) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 55>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "56. MD5Table(56) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 56>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "57. MD5Table(57) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 57>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "58. MD5Table(58) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 58>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "59. MD5Table(59) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 59>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "60. MD5Table(60) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 60>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "61. MD5Table(61) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 61>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "62. MD5Table(62) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 62>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "63. MD5Table(63) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 63>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "64. MD5Table(64) ? ";
		std::cout << std::hex << ConstProgression<MD5TableBuilder, 64>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "65. MD5(test_pattern_0) ? ";
		auto hash = MD5Hash();
		for(auto i: test_pattern_0)
		{
			hash.insert(uint8_t(i));
		}
		dump(std::cout, hash.digest()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "66. MD5(test_pattern_1) ? ";
		auto hash = MD5Hash();
		for(auto i: test_pattern_1)
		{
			hash.insert(uint8_t(i));
		}
		dump(std::cout, hash.digest()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "67. MD5(test_pattern_2) ? ";
		auto hash = MD5Hash();
		for(auto i: test_pattern_2)
		{
			hash.insert(uint8_t(i));
		}
		dump(std::cout, hash.digest()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "68. MD5(test_pattern_3) ? ";
		auto hash = MD5Hash();
		for(auto i: test_pattern_3)
		{
			hash.insert(uint8_t(i));
		}
		dump(std::cout, hash.digest()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "69. MD5(test_pattern_4) ? ";
		auto hash = MD5Hash();
		for(auto i: test_pattern_4)
		{
			hash.insert(uint8_t(i));
		}
		dump(std::cout, hash.digest()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "70. MD5(test_pattern_5) ? ";
		auto hash = MD5Hash();
		for(auto i: test_pattern_5)
		{
			hash.insert(uint8_t(i));
		}
		dump(std::cout, hash.digest()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "71. MD5(test_pattern_6) ? ";
		auto hash = MD5Hash();
		for(auto i: test_pattern_6)
		{
			hash.insert(uint8_t(i));
		}
		dump(std::cout, hash.digest()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "72. MD5(test_pattern_7) ? ";
		auto hash = MD5Hash();
		for(auto i: test_pattern_7)
		{
			hash.insert(uint8_t(i));
		}
		dump(std::cout, hash.digest()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "73. MD5(test_pattern_8) ? ";
		auto hash = MD5Hash();
		for(auto i: test_pattern_8)
		{
			hash.insert(uint8_t(i));
		}
		dump(std::cout, hash.digest()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "74. MD5(test_pattern_9) ? ";
		auto hash = MD5Hash();
		for(auto i: test_pattern_9)
		{
			hash.insert(uint8_t(i));
		}
		dump(std::cout, hash.digest()) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "75. MD5(test_pattern_10) ? ";
		auto hash = MD5Hash();
		for(auto i: test_pattern_10)
		{
			hash.insert(uint8_t(i));
		}
		dump(std::cout, hash.digest()) << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- MD5 --->" << std::endl;
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
