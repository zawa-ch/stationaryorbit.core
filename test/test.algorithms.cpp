//	stationaryorbit.core.test.algorithms:/test.algorithms.cpp
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

std::array<std::function<int(void)>, 54> tests =
{
	[]()
	{
		std::cout << "n1 = uint32_t(143)" << std::endl;
		uint32_t n1 = 143;
		std::cout << "n2 = uint32_t(13)" << std::endl;
		uint32_t n2 = 13;
		std::cout << "n3 = uint32_t(7)" << std::endl;
		uint32_t n3 = 7;
		std::cout << "1. Algorithms::integral_fraction(n1, n2, n3).value ? ";
		auto result = Algorithms::integral_fraction(n1, n2, n3);
		std::cout << result.value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "n1 = uint32_t(143)" << std::endl;
		uint32_t n1 = 143;
		std::cout << "n2 = uint32_t(13)" << std::endl;
		uint32_t n2 = 13;
		std::cout << "n3 = uint32_t(7)" << std::endl;
		uint32_t n3 = 7;
		std::cout << "2. Algorithms::integral_fraction(n1, n2, n3).mod ? ";
		auto result = Algorithms::integral_fraction(n1, n2, n3);
		std::cout << result.mod << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "n1 = uint32_t(4)" << std::endl;
		uint32_t n1 = 4;
		std::cout << "n2 = uint32_t(5)" << std::endl;
		uint32_t n2 = 5;
		std::cout << "n3 = uint32_t(3)" << std::endl;
		uint32_t n3 = 3;
		std::cout << "3. Algorithms::integral_fraction(n1, n2, n3).value ? ";
		auto result = Algorithms::integral_fraction(n1, n2, n3);
		std::cout << result.value << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "n1 = uint32_t(4)" << std::endl;
		uint32_t n1 = 4;
		std::cout << "n2 = uint32_t(5)" << std::endl;
		uint32_t n2 = 5;
		std::cout << "n3 = uint32_t(3)" << std::endl;
		uint32_t n3 = 3;
		std::cout << "4. Algorithms::integral_fraction(n1, n2, n3).mod ? ";
		auto result = Algorithms::integral_fraction(n1, n2, n3);
		std::cout << result.mod << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "n1 = uint32_t(28)" << std::endl;
		uint32_t n1 = 28;
		std::cout << "n2 = uint32_t(0)" << std::endl;
		uint32_t n2 = 0;
		std::cout << "n3 = uint32_t(1)" << std::endl;
		uint32_t n3 = 1;
		std::cout << "5. Algorithms::integral_fraction(n1, n2, n3).value ? ";
		try
		{
			auto result = Algorithms::integral_fraction(n1, n2, n3);
			std::cout << result.value << std::endl;
		}
		catch (std::invalid_argument e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
		return 0;
	},
	[]()
	{
		std::cout << "n1 = uint32_t(28)" << std::endl;
		uint32_t n1 = 28;
		std::cout << "n2 = uint32_t(0)" << std::endl;
		uint32_t n2 = 0;
		std::cout << "n3 = uint32_t(1)" << std::endl;
		uint32_t n3 = 1;
		std::cout << "6. Algorithms::integral_fraction(n1, n2, n3).mod ? ";
		try
		{
			auto result = Algorithms::integral_fraction(n1, n2, n3);
			std::cout << result.mod << std::endl;
		}
		catch (std::invalid_argument e)
		{
			std::cout << "...NG (exception handled)" << std::endl << "what: " << e.what() << std::endl;
			return 1;
		}
		return 0;
	},
	[]()
	{
		std::cout << "7. Algorithms::boolean_and(true, true) ->true? ";
		return check_if(Algorithms::boolean_and(true, true));
	},
	[]()
	{
		std::cout << "8. Algorithms::boolean_and(false, true) ->false? ";
		return check_if(!Algorithms::boolean_and(false, true));
	},
	[]()
	{
		std::cout << "9. Algorithms::boolean_and(true, false) ->false? ";
		return check_if(!Algorithms::boolean_and(true, false));
	},
	[]()
	{
		std::cout << "10. Algorithms::boolean_and(false, false) ->false? ";
		return check_if(!Algorithms::boolean_and(false, false));
	},
	[]()
	{
		std::cout << "11. Algorithms::boolean_and({true, true, true, true}) ->true? ";
		return check_if(Algorithms::boolean_and({true, true, true, true}));
	},
	[]()
	{
		std::cout << "12. Algorithms::boolean_and({false, true, false, true}) ->false? ";
		return check_if(!Algorithms::boolean_and({false, true, false, true}));
	},
	[]()
	{
		std::cout << "13. Algorithms::boolean_and({true, false, true, false}) ->false? ";
		return check_if(!Algorithms::boolean_and({true, false, true, false}));
	},
	[]()
	{
		std::cout << "14. Algorithms::boolean_and({false, false, false, false}) ->false? ";
		return check_if(!Algorithms::boolean_and({false, false, false, false}));
	},
	[]()
	{
		std::cout << "15. Algorithms::boolean_or(true, true) ->true? ";
		return check_if(Algorithms::boolean_or(true, true));
	},
	[]()
	{
		std::cout << "16. Algorithms::boolean_or(false, true) ->true? ";
		return check_if(Algorithms::boolean_or(false, true));
	},
	[]()
	{
		std::cout << "17. Algorithms::boolean_or(true, false) ->true? ";
		return check_if(Algorithms::boolean_or(true, false));
	},
	[]()
	{
		std::cout << "18. Algorithms::boolean_or(false, false) ->false? ";
		return check_if(!Algorithms::boolean_or(false, false));
	},
	[]()
	{
		std::cout << "19. Algorithms::boolean_or({true, true, true, true}) ->true? ";
		return check_if(Algorithms::boolean_or({true, true, true, true}));
	},
	[]()
	{
		std::cout << "20. Algorithms::boolean_or({false, true, false, true}) ->true? ";
		return check_if(Algorithms::boolean_or({false, true, false, true}));
	},
	[]()
	{
		std::cout << "21. Algorithms::boolean_or({true, false, true, false}) ->true? ";
		return check_if(Algorithms::boolean_or({true, false, true, false}));
	},
	[]()
	{
		std::cout << "22. Algorithms::boolean_or({false, false, false, false}) ->false? ";
		return check_if(!Algorithms::boolean_or({false, false, false, false}));
	},
	[]()
	{
		std::cout << "23. Algorithms::boolean_xor(true, true) ->false? ";
		return check_if(!Algorithms::boolean_xor(true, true));
	},
	[]()
	{
		std::cout << "24. Algorithms::boolean_xor(false, true) ->true? ";
		return check_if(Algorithms::boolean_xor(false, true));
	},
	[]()
	{
		std::cout << "25. Algorithms::boolean_xor(true, false) ->true? ";
		return check_if(Algorithms::boolean_xor(true, false));
	},
	[]()
	{
		std::cout << "26. Algorithms::boolean_xor(false, false) ->false? ";
		return check_if(!Algorithms::boolean_xor(false, false));
	},
	[]()
	{
		std::cout << "27. Algorithms::boolean_xor({true, true, true, true}) ->false? ";
		return check_if(!Algorithms::boolean_xor({true, true, true, true}));
	},
	[]()
	{
		std::cout << "28. Algorithms::boolean_xor({false, true, false, true}) ->false? ";
		return check_if(!Algorithms::boolean_xor({false, true, false, true}));
	},
	[]()
	{
		std::cout << "29. Algorithms::boolean_xor({true, false, true, false}) ->false? ";
		return check_if(!Algorithms::boolean_xor({true, false, true, false}));
	},
	[]()
	{
		std::cout << "30. Algorithms::boolean_xor({false, false, false, false}) ->false? ";
		return check_if(!Algorithms::boolean_xor({false, false, false, false}));
	},
	[]()
	{
		std::cout << "31. Algorithms::boolean_xor({true, false, false, false}) ->true? ";
		return check_if(Algorithms::boolean_xor({true, false, false, false}));
	},
	[]()
	{
		std::cout << "32. Algorithms::boolean_xor({false, true, true, true}) ->true? ";
		return check_if(Algorithms::boolean_xor({false, true, true, true}));
	},
	[]()
	{
		std::cout << "33. Algorithms::halfangle_sin(0) ? ";
		std::cout.precision(15);
		std::cout << Algorithms::halfangle_sin<double>(0.0) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "34. Algorithms::halfangle_sin(0.5) ? ";
		std::cout.precision(15);
		std::cout << Algorithms::halfangle_sin<double>(0.5) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "35. Algorithms::halfangle_sin(1) ? ";
		std::cout.precision(15);
		std::cout << Algorithms::halfangle_sin<double>(1.0) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "36. Algorithms::halfangle_cos(0) ? ";
		std::cout.precision(15);
		std::cout << Algorithms::halfangle_cos<double>(0.0) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "37. Algorithms::halfangle_cos(0.5) ? ";
		std::cout.precision(15);
		std::cout << Algorithms::halfangle_cos<double>(0.5) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "38. Algorithms::halfangle_cos(1) ? ";
		std::cout.precision(15);
		std::cout << Algorithms::halfangle_cos<double>(1.0) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "39. Algorithms::halfangle_tan(1, 0) ? ";
		std::cout.precision(15);
		std::cout << Algorithms::halfangle_tan<double>(1.0, 0.0) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "40. Algorithms::halfangle_tan(0.86602540378443864676372317075294, 0.5) ? ";
		std::cout.precision(15);
		std::cout << Algorithms::halfangle_tan<double>(0.86602540378443864676372317075294, 0.5) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "41. atan(1) ? ";
		auto result = double(0);
		auto iter = Algorithms::ArctanProgressionSequenceIterator<double>(1.0);
		do
		{
			iter.next();
			auto b = result + iter.current();
			if (result == b) { break; }
			result = b;
		} while(true);
		std::cout.precision(15);
		std::cout << result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "42. atan(0.70710678118654752440084436210485) ? ";
		auto result = double(0);
		auto iter = Algorithms::ArctanProgressionSequenceIterator<double>(0.70710678118654752440084436210485);
		do
		{
			iter.next();
			auto b = result + iter.current();
			if (result == b) { break; }
			result = b;
		} while(true);
		std::cout.precision(15);
		std::cout << result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "43. asin(0) ? ";
		auto result = double(0);
		auto iter = Algorithms::ArcsinProgressionSequenceIterator<double>(0.0);
		do
		{
			iter.next();
			auto b = result + iter.current();
			if (result == b) { break; }
			result = b;
		} while(true);
		std::cout.precision(15);
		std::cout << result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "44. asin(0.29289321881345247559915563789515) ? ";
		auto result = double(0);
		auto iter = Algorithms::ArcsinProgressionSequenceIterator<double>(0.29289321881345247559915563789515);
		do
		{
			iter.next();
			auto b = result + iter.current();
			if (result == b) { break; }
			result = b;
		} while(true);
		std::cout.precision(15);
		std::cout << result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "45. asin(0.5) ? ";
		auto result = double(0);
		auto iter = Algorithms::ArcsinProgressionSequenceIterator<double>(0.5);
		do
		{
			iter.next();
			auto b = result + iter.current();
			if (result == b) { break; }
			result = b;
		} while(true);
		std::cout.precision(15);
		std::cout << result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "46. asin(0.70710678118654752440084436210485) ? ";
		auto result = double(0);
		auto iter = Algorithms::ArcsinProgressionSequenceIterator<double>(0.70710678118654752440084436210485);
		do
		{
			iter.next();
			auto b = result + iter.current();
			if (result == b) { break; }
			result = b;
		} while(true);
		std::cout.precision(15);
		std::cout << result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "47. sin(0) ? ";
		auto result = double(0);
		auto iter = Algorithms::SinProgressionSequenceIterator<double>(0.0);
		do
		{
			iter.next();
			auto b = result + iter.current();
			if (result == b) { break; }
			result = b;
		} while(true);
		std::cout.precision(15);
		std::cout << result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "48. sin(0.78539816339744830961566084581988) ? ";
		auto result = double(0);
		auto iter = Algorithms::SinProgressionSequenceIterator<double>(0.78539816339744830961566084581988);
		do
		{
			iter.next();
			auto b = result + iter.current();
			if (result == b) { break; }
			result = b;
		} while(true);
		std::cout.precision(15);
		std::cout << result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "49. sin(1.5707963267948966192313216916398) ? ";
		auto result = double(0);
		auto iter = Algorithms::SinProgressionSequenceIterator<double>(1.5707963267948966192313216916398);
		do
		{
			iter.next();
			auto b = result + iter.current();
			if (result == b) { break; }
			result = b;
		} while(true);
		std::cout.precision(15);
		std::cout << result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "50. cos(0) ? ";
		auto result = double(0);
		auto iter = Algorithms::CosProgressionSequenceIterator<double>(0.0);
		do
		{
			iter.next();
			auto b = result + iter.current();
			if (result == b) { break; }
			result = b;
		} while(true);
		std::cout.precision(15);
		std::cout << result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "51. cos(0.78539816339744830961566084581988) ? ";
		auto result = double(0);
		auto iter = Algorithms::CosProgressionSequenceIterator<double>(0.78539816339744830961566084581988);
		do
		{
			iter.next();
			auto b = result + iter.current();
			if (result == b) { break; }
			result = b;
		} while(true);
		std::cout.precision(15);
		std::cout << result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "52. cos(1.5707963267948966192313216916398) ? ";
		auto result = double(0);
		auto iter = Algorithms::CosProgressionSequenceIterator<double>(1.5707963267948966192313216916398);
		auto c = double(0);
		do
		{
			iter.next();
			auto b = result + iter.current();
			if (result == b) { break; }
			result = b;
		} while(true);
		std::cout.precision(15);
		std::cout << result << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "53. 12 mod 5 ? ";
		auto mod = Algorithms::ModuloIterator<uint32_t>(12, 5);
		while(mod.has_value())
		{
			mod.next();
		}
		std::cout << mod.current() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "54. 5.6 mod 0.3 ? ";
		auto mod = Algorithms::ModuloIterator<double>(5.6, 0.3);
		while(mod.has_value())
		{
			mod.next();
		}
		std::cout << mod.current() << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- Algorithms --->" << std::endl;
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
