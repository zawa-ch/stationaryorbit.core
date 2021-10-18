//	stationaryorbit.core.test.crc:/test.crc.cpp
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

///	MD5 test pattern (expects 00000000)
std::string test_pattern_0 = "";
///	MD5 test pattern (expects e8b7be43)
std::string test_pattern_1 = "a";
///	MD5 test pattern (expects 352441c2)
std::string test_pattern_2 = "abc";
///	MD5 test pattern (expects 20159d7f)
std::string test_pattern_3 = "message digest";
///	MD5 test pattern (expects 4c2750bd)
std::string test_pattern_4 = "abcdefghijklmnopqrstuvwxyz";
///	MD5 test pattern (expects 1fc2e6d2)
std::string test_pattern_5 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
///	MD5 test pattern (expects 7ca94a72)
std::string test_pattern_6 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
///	MD5 test pattern (expects 519025e9)
std::string test_pattern_7 = "The quick brown fox jumps over the lazy dog.";
///	MD5 test pattern (expects dfae50e1)
///	Quoted from `fortune` Napoleon I
std::string test_pattern_8 = "Ten persons who speak make more noise than ten thousand who are silent.";
///	MD5 test pattern (expects 36c33ba7)
///	Quoted from `fortune` T. Cheatham
std::string test_pattern_9 = "If a group of N persons implements a COBOL compiler, there will be N-1 passes.  Someone in the group has to be the manager.";
///	MD5 test pattern (expects d45e77f3)
///	Quoted from `fortune`
std::string test_pattern_10 = "The time was the 19th of May, 1780.  The place was Hartford, Connecticut. The day has gone down in New England history as a terrible foretaste of Judgement Day.  For at noon the skies turned from blue to grey and by mid-afternoon had blackened over so densely that, in that religious age, men fell on their knees and begged a final blessing before the end came. The Connecticut House of Representatives was in session.  And, as some of the men fell down and others clamored for an immediate adjournment, the Speaker of the House, one Col. Davenport, came to his feet.  He silenced them and said these words: \"The day of judgment is either approaching or it is not.  If it is not, there is no cause for adjournment.  If it is, I choose to be found doing my duty.  I wish therefore that candles may be brought.\"  -- Alistair Cooke";

std::array<std::function<int(void)>, 267> tests =
{
	[]()
	{
		std::cout << "1. CRC32Table(0) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 0>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "2. CRC32Table(1) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 1>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "3. CRC32Table(2) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 2>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "4. CRC32Table(3) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 3>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "5. CRC32Table(4) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 4>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "6. CRC32Table(5) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 5>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "7. CRC32Table(6) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 6>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "8. CRC32Table(7) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 7>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "9. CRC32Table(8) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 8>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "10. CRC32Table(9) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 9>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "11. CRC32Table(10) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 10>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "12. CRC32Table(11) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 11>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "13. CRC32Table(12) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 12>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "14. CRC32Table(13) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 13>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "15. CRC32Table(14) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 14>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "16. CRC32Table(15) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 15>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "17. CRC32Table(16) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 16>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "18. CRC32Table(17) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 17>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "19. CRC32Table(18) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 18>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "20. CRC32Table(19) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 19>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "21. CRC32Table(20) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 20>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "22. CRC32Table(21) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 21>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "23. CRC32Table(22) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 22>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "24. CRC32Table(23) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 23>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "25. CRC32Table(24) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 24>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "26. CRC32Table(25) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 25>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "27. CRC32Table(26) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 26>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "28. CRC32Table(27) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 27>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "29. CRC32Table(28) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 28>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "30. CRC32Table(29) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 29>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "31. CRC32Table(30) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 30>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "32. CRC32Table(31) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 31>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "33. CRC32Table(32) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 32>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "34. CRC32Table(33) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 33>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "35. CRC32Table(34) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 34>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "36. CRC32Table(35) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 35>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "37. CRC32Table(36) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 36>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "38. CRC32Table(37) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 37>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "39. CRC32Table(38) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 38>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "40. CRC32Table(39) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 39>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "41. CRC32Table(40) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 40>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "42. CRC32Table(41) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 41>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "43. CRC32Table(42) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 42>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "44. CRC32Table(43) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 43>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "45. CRC32Table(44) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 44>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "46. CRC32Table(45) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 45>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "47. CRC32Table(46) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 46>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "48. CRC32Table(47) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 47>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "49. CRC32Table(48) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 48>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "50. CRC32Table(49) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 49>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "51. CRC32Table(50) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 50>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "52. CRC32Table(51) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 51>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "53. CRC32Table(52) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 52>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "54. CRC32Table(53) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 53>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "55. CRC32Table(54) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 54>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "56. CRC32Table(55) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 55>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "57. CRC32Table(56) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 56>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "58. CRC32Table(57) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 57>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "59. CRC32Table(58) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 58>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "60. CRC32Table(59) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 59>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "61. CRC32Table(60) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 60>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "62. CRC32Table(61) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 61>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "63. CRC32Table(62) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 62>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "64. CRC32Table(63) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 63>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "65. CRC32Table(64) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 64>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "66. CRC32Table(65) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 65>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "67. CRC32Table(66) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 66>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "68. CRC32Table(67) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 67>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "69. CRC32Table(68) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 68>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "70. CRC32Table(69) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 69>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "71. CRC32Table(70) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 70>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "72. CRC32Table(71) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 71>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "73. CRC32Table(72) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 72>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "74. CRC32Table(73) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 73>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "75. CRC32Table(74) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 74>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "76. CRC32Table(75) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 75>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "77. CRC32Table(76) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 76>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "78. CRC32Table(77) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 77>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "79. CRC32Table(78) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 78>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "80. CRC32Table(79) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 79>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "81. CRC32Table(80) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 80>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "82. CRC32Table(81) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 81>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "83. CRC32Table(82) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 82>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "84. CRC32Table(83) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 83>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "85. CRC32Table(84) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 84>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "86. CRC32Table(85) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 85>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "87. CRC32Table(86) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 86>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "88. CRC32Table(87) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 87>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "89. CRC32Table(88) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 88>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "90. CRC32Table(89) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 89>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "91. CRC32Table(90) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 90>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "92. CRC32Table(91) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 91>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "93. CRC32Table(92) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 92>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "94. CRC32Table(93) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 93>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "95. CRC32Table(94) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 94>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "96. CRC32Table(95) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 95>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "97. CRC32Table(96) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 96>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "98. CRC32Table(97) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 97>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "99. CRC32Table(98) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 98>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "100. CRC32Table(99) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 99>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "101. CRC32Table(100) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 100>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "102. CRC32Table(101) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 101>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "103. CRC32Table(102) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 102>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "104. CRC32Table(103) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 103>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "105. CRC32Table(104) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 104>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "106. CRC32Table(105) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 105>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "107. CRC32Table(106) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 106>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "108. CRC32Table(107) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 107>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "109. CRC32Table(108) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 108>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "110. CRC32Table(109) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 109>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "111. CRC32Table(110) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 110>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "112. CRC32Table(111) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 111>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "113. CRC32Table(112) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 112>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "114. CRC32Table(113) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 113>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "115. CRC32Table(114) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 114>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "116. CRC32Table(115) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 115>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "117. CRC32Table(116) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 116>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "118. CRC32Table(117) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 117>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "119. CRC32Table(118) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 118>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "120. CRC32Table(119) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 119>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "121. CRC32Table(120) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 120>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "122. CRC32Table(121) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 121>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "123. CRC32Table(122) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 122>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "124. CRC32Table(123) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 123>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "125. CRC32Table(124) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 124>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "126. CRC32Table(125) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 125>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "127. CRC32Table(126) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 126>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "128. CRC32Table(127) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 127>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "129. CRC32Table(128) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 128>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "130. CRC32Table(129) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 129>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "131. CRC32Table(130) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 130>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "132. CRC32Table(131) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 131>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "133. CRC32Table(132) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 132>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "134. CRC32Table(133) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 133>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "135. CRC32Table(134) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 134>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "136. CRC32Table(135) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 135>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "137. CRC32Table(136) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 136>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "138. CRC32Table(137) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 137>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "139. CRC32Table(138) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 138>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "140. CRC32Table(139) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 139>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "141. CRC32Table(140) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 140>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "142. CRC32Table(141) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 141>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "143. CRC32Table(142) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 142>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "144. CRC32Table(143) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 143>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "145. CRC32Table(144) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 144>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "146. CRC32Table(145) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 145>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "147. CRC32Table(146) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 146>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "148. CRC32Table(147) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 147>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "149. CRC32Table(148) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 148>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "150. CRC32Table(149) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 149>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "151. CRC32Table(150) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 150>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "152. CRC32Table(151) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 151>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "153. CRC32Table(152) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 152>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "154. CRC32Table(153) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 153>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "155. CRC32Table(154) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 154>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "156. CRC32Table(155) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 155>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "157. CRC32Table(156) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 156>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "158. CRC32Table(157) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 157>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "159. CRC32Table(158) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 158>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "160. CRC32Table(159) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 159>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "161. CRC32Table(160) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 160>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "162. CRC32Table(161) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 161>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "163. CRC32Table(162) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 162>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "164. CRC32Table(163) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 163>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "165. CRC32Table(164) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 164>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "166. CRC32Table(165) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 165>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "167. CRC32Table(166) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 166>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "168. CRC32Table(167) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 167>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "169. CRC32Table(168) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 168>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "170. CRC32Table(169) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 169>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "171. CRC32Table(170) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 170>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "172. CRC32Table(171) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 171>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "173. CRC32Table(172) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 172>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "174. CRC32Table(173) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 173>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "175. CRC32Table(174) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 174>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "176. CRC32Table(175) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 175>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "177. CRC32Table(176) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 176>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "178. CRC32Table(177) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 177>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "179. CRC32Table(178) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 178>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "180. CRC32Table(179) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 179>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "181. CRC32Table(180) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 180>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "182. CRC32Table(181) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 181>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "183. CRC32Table(182) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 182>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "184. CRC32Table(183) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 183>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "185. CRC32Table(184) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 184>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "186. CRC32Table(185) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 185>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "187. CRC32Table(186) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 186>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "188. CRC32Table(187) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 187>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "189. CRC32Table(188) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 188>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "190. CRC32Table(189) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 189>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "191. CRC32Table(190) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 190>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "192. CRC32Table(191) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 191>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "193. CRC32Table(192) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 192>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "194. CRC32Table(193) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 193>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "195. CRC32Table(194) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 194>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "196. CRC32Table(195) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 195>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "197. CRC32Table(196) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 196>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "198. CRC32Table(197) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 197>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "199. CRC32Table(198) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 198>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "200. CRC32Table(199) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 199>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "201. CRC32Table(200) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 200>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "202. CRC32Table(201) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 201>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "203. CRC32Table(202) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 202>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "204. CRC32Table(203) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 203>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "205. CRC32Table(204) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 204>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "206. CRC32Table(205) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 205>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "207. CRC32Table(206) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 206>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "208. CRC32Table(207) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 207>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "209. CRC32Table(208) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 208>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "210. CRC32Table(209) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 209>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "211. CRC32Table(210) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 210>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "212. CRC32Table(211) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 211>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "213. CRC32Table(212) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 212>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "214. CRC32Table(213) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 213>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "215. CRC32Table(214) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 214>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "216. CRC32Table(215) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 215>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "217. CRC32Table(216) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 216>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "218. CRC32Table(217) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 217>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "219. CRC32Table(218) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 218>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "220. CRC32Table(219) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 219>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "221. CRC32Table(220) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 220>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "222. CRC32Table(221) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 221>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "223. CRC32Table(222) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 222>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "224. CRC32Table(223) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 223>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "225. CRC32Table(224) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 224>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "226. CRC32Table(225) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 225>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "227. CRC32Table(226) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 226>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "228. CRC32Table(227) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 227>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "229. CRC32Table(228) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 228>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "230. CRC32Table(229) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 229>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "231. CRC32Table(230) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 230>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "232. CRC32Table(231) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 231>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "233. CRC32Table(232) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 232>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "234. CRC32Table(233) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 233>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "235. CRC32Table(234) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 234>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "236. CRC32Table(235) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 235>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "237. CRC32Table(236) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 236>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "238. CRC32Table(237) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 237>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "239. CRC32Table(238) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 238>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "240. CRC32Table(239) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 239>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "241. CRC32Table(240) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 240>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "242. CRC32Table(241) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 241>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "243. CRC32Table(242) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 242>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "244. CRC32Table(243) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 243>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "245. CRC32Table(244) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 244>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "246. CRC32Table(245) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 245>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "247. CRC32Table(246) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 246>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "248. CRC32Table(247) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 247>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "249. CRC32Table(248) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 248>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "250. CRC32Table(249) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 249>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "251. CRC32Table(250) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 250>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "252. CRC32Table(251) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 251>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "253. CRC32Table(252) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 252>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "254. CRC32Table(253) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 253>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "255. CRC32Table(254) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 254>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "256. CRC32Table(255) ? ";
		std::cout << std::hex << ConstProgression<CRC32TableBuilder, 255>::value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "257. CRC32(test_pattern_0) ? ";
		auto hash = CRC32();
		for(auto i: test_pattern_0)
		{
			hash.insert(uint8_t(i));
		}
		std::cout << std::hex << hash.digest() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "258. CRC32(test_pattern_1) ? ";
		auto hash = CRC32();
		for(auto i: test_pattern_1)
		{
			hash.insert(uint8_t(i));
		}
		std::cout << std::hex << hash.digest() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "259. CRC32(test_pattern_2) ? ";
		auto hash = CRC32();
		for(auto i: test_pattern_2)
		{
			hash.insert(uint8_t(i));
		}
		std::cout << std::hex << hash.digest() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "260. CRC32(test_pattern_3) ? ";
		auto hash = CRC32();
		for(auto i: test_pattern_3)
		{
			hash.insert(uint8_t(i));
		}
		std::cout << std::hex << hash.digest() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "261. CRC32(test_pattern_4) ? ";
		auto hash = CRC32();
		for(auto i: test_pattern_4)
		{
			hash.insert(uint8_t(i));
		}
		std::cout << std::hex << hash.digest() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "262. CRC32(test_pattern_5) ? ";
		auto hash = CRC32();
		for(auto i: test_pattern_5)
		{
			hash.insert(uint8_t(i));
		}
		std::cout << std::hex << hash.digest() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "263. CRC32(test_pattern_6) ? ";
		auto hash = CRC32();
		for(auto i: test_pattern_6)
		{
			hash.insert(uint8_t(i));
		}
		std::cout << std::hex << hash.digest() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "264. CRC32(test_pattern_7) ? ";
		auto hash = CRC32();
		for(auto i: test_pattern_7)
		{
			hash.insert(uint8_t(i));
		}
		std::cout << std::hex << hash.digest() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "265. CRC32(test_pattern_8) ? ";
		auto hash = CRC32();
		for(auto i: test_pattern_8)
		{
			hash.insert(uint8_t(i));
		}
		std::cout << std::hex << hash.digest() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "266. CRC32(test_pattern_9) ? ";
		auto hash = CRC32();
		for(auto i: test_pattern_9)
		{
			hash.insert(uint8_t(i));
		}
		std::cout << std::hex << hash.digest() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "267. CRC32(test_pattern_10) ? ";
		auto hash = CRC32();
		for(auto i: test_pattern_10)
		{
			hash.insert(uint8_t(i));
		}
		std::cout << std::hex << hash.digest() << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- CRC --->" << std::endl;
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
