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
int test19();
int test20();
int test21();
int test22();
int test23();
int test24();
int test25();
int test26();
int test27();
int test28();
int test29();
int test30();
int test31();
int test32();
int test33();
int test34();
int test35();
int test36();
int test37();
int test38();
int test39();
int test40();
int test41();
int test42();
int test43();
int test44();

int main(int argc, char const *argv[])
{
	std::cout << "<--- Logic --->" << std::endl;
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
		case 19: { return test19(); }
		case 20: { return test20(); }
		case 21: { return test21(); }
		case 22: { return test22(); }
		case 23: { return test23(); }
		case 24: { return test24(); }
		case 25: { return test25(); }
		case 26: { return test26(); }
		case 27: { return test27(); }
		case 28: { return test28(); }
		case 29: { return test29(); }
		case 30: { return test30(); }
		case 31: { return test31(); }
		case 32: { return test32(); }
		case 33: { return test33(); }
		case 34: { return test34(); }
		case 35: { return test35(); }
		case 36: { return test36(); }
		case 37: { return test37(); }
		case 38: { return test38(); }
		case 39: { return test39(); }
		case 40: { return test40(); }
		case 41: { return test41(); }
		case 42: { return test42(); }
		case 43: { return test43(); }
		case 44: { return test44(); }
		default:
		{
			std::cerr << "Invalid test index";
			return 2;
		}
	}
}

int test1()
{
	std::cout << "2. T ? " << Logic::True() << std::endl;
	return 0;
}

int test2()
{
	std::cout << "3. F ? " << Logic::False() << std::endl;
	return 0;
}

int test3()
{
	std::cout << "4. I ? " << Logic::Indefinited() << std::endl;
	return 0;
}

int test4()
{
	std::cout << "5. U ? " << Logic::Undefined() << std::endl;
	return 0;
}

int test5()
{
	std::cout << "6. T | T ? " << (Logic::True() || Logic::True()) << std::endl;
	return 0;
}

int test6()
{
	std::cout << "7. T | F ? " << (Logic::True() || Logic::False()) << std::endl;
	return 0;
}

int test7()
{
	std::cout << "8. T | I ? " << (Logic::True() || Logic::Indefinited()) << std::endl;
	return 0;
}

int test8()
{
	std::cout << "9. T | U ? " << (Logic::True() || Logic::Undefined()) << std::endl;
	return 0;
}

int test9()
{
	std::cout << "10. F | T ? " << (Logic::False() || Logic::True()) << std::endl;
	return 0;
}

int test10()
{
	std::cout << "11. F | F ? " << (Logic::False() || Logic::False()) << std::endl;
	return 0;
}

int test11()
{
	std::cout << "12. F | I ? " << (Logic::False() || Logic::Indefinited()) << std::endl;
	return 0;
}

int test12()
{
	std::cout << "13. F | U ? " << (Logic::False() || Logic::Undefined()) << std::endl;
	return 0;
}

int test13()
{
	std::cout << "14. I | T ? " << (Logic::Indefinited() || Logic::True()) << std::endl;
	return 0;
}

int test14()
{
	std::cout << "15. I | F ? " << (Logic::Indefinited() || Logic::False()) << std::endl;
	return 0;
}
int test15()
{
	std::cout << "16. I | I ? " << (Logic::Indefinited() || Logic::Indefinited()) << std::endl;
	return 0;
}

int test16()
{
	std::cout << "17. I | U ? " << (Logic::Indefinited() || Logic::Undefined()) << std::endl;
	return 0;
}

int test17()
{
	std::cout << "18. U | T ? " << (Logic::Undefined() || Logic::True()) << std::endl;
	return 0;
}

int test18()
{
	std::cout << "19. U | F ? " << (Logic::Undefined() || Logic::False()) << std::endl;
	return 0;
}

int test19()
{
	std::cout << "20. U | I ? " << (Logic::Undefined() || Logic::Indefinited()) << std::endl;
	return 0;
}

int test20()
{
	std::cout << "21. U | U ? " << (Logic::Undefined() || Logic::Undefined()) << std::endl;
	return 0;
}

int test21()
{
	std::cout << "22. T & T ? " << (Logic::True() && Logic::True()) << std::endl;
	return 0;
}

int test22()
{
	std::cout << "23. T & F ? " << (Logic::True() && Logic::False()) << std::endl;
	return 0;
}

int test23()
{
	std::cout << "24. T & I ? " << (Logic::True() && Logic::Indefinited()) << std::endl;
	return 0;
}

int test24()
{
	std::cout << "25. T & U ? " << (Logic::True() && Logic::Undefined()) << std::endl;
	return 0;
}

int test25()
{
	std::cout << "26. F & T ? " << (Logic::False() && Logic::True()) << std::endl;
	return 0;
}

int test26()
{
	std::cout << "27. F & F ? " << (Logic::False() && Logic::False()) << std::endl;
	return 0;
}

int test27()
{
	std::cout << "28. F & I ? " << (Logic::False() && Logic::Indefinited()) << std::endl;
	return 0;
}

int test28()
{
	std::cout << "29. F & U ? " << (Logic::False() && Logic::Undefined()) << std::endl;
	return 0;
}

int test29()
{
	std::cout << "30. I & T ? " << (Logic::Indefinited() && Logic::True()) << std::endl;
	return 0;
}

int test30()
{
	std::cout << "31. I & F ? " << (Logic::Indefinited() && Logic::False()) << std::endl;
	return 0;
}

int test31()
{
	std::cout << "32. I & I ? " << (Logic::Indefinited() && Logic::Indefinited()) << std::endl;
	return 0;
}

int test32()
{
	std::cout << "33. I & U ? " << (Logic::Indefinited() && Logic::Undefined()) << std::endl;
	return 0;
}

int test33()
{
	std::cout << "34. U & T ? " << (Logic::Undefined() && Logic::True()) << std::endl;
	return 0;
}

int test34()
{
	std::cout << "35. U & F ? " << (Logic::Undefined() && Logic::False()) << std::endl;
	return 0;
}

int test35()
{
	std::cout << "36. U & I ? " << (Logic::Undefined() && Logic::Indefinited()) << std::endl;
	return 0;
}

int test36()
{
	std::cout << "37. U & U ? " << (Logic::Undefined() && Logic::Undefined()) << std::endl;
	return 0;
}

int test37()
{
	std::cout << "38. !T ? " << (!Logic::True()) << std::endl;
	return 0;
}

int test38()
{
	std::cout << "39. !F ? " << (!Logic::False()) << std::endl;
	return 0;
}

int test39()
{
	std::cout << "40. !I ? " << (!Logic::Indefinited()) << std::endl;
	return 0;
}

int test40()
{
	std::cout << "41. !U ? " << (!Logic::Undefined()) << std::endl;
	return 0;
}

int test41()
{
	std::cout << "42. T == T -> true?";
	if (Logic::True() == Logic::True())
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

int test42()
{
	std::cout << "43. F == F -> true?";
	if (Logic::False() == Logic::False())
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

int test43()
{
	std::cout << "44. I == I -> true?";
	if (Logic::Indefinited() == Logic::Indefinited())
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

int test44()
{
	std::cout << "45. U != U -> true?";
	if (Logic::Undefined() != Logic::Undefined())
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
