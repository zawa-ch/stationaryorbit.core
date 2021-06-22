//	stationaryorbit.core.test.bitmask:/test.bitmask.cpp
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
#include "stationaryorbit/core.bitoperation.hpp"
using namespace zawa_ch::StationaryOrbit;

std::array<std::function<int(void)>, 40> tests =
{
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<uint32_t>(0xF0);
		std::cout << "1. mask ? ";
		std::cout << std::hex << mask.mask << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAA" << std::endl;
		auto mask = BitMask<uint32_t>(0xAA);
		std::cout << "2. mask ? ";
		std::cout << std::hex << mask.mask << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<uint32_t>(0xF0);
		std::cout << "3. mask.begin_index ? ";
		std::cout << mask.begin_index() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAA" << std::endl;
		auto mask = BitMask<uint32_t>(0xAA);
		std::cout << "4. mask.begin_index ? ";
		std::cout << mask.begin_index() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<uint32_t>(0xF0);
		std::cout << "5. mask.end_index ? ";
		std::cout << mask.end_index() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAA" << std::endl;
		auto mask = BitMask<uint32_t>(0xAA);
		std::cout << "6. mask.end_index ? ";
		std::cout << mask.end_index() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<uint32_t>(0xF0);
		std::cout << "7. mask.length ? ";
		std::cout << mask.length() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAA" << std::endl;
		auto mask = BitMask<uint32_t>(0xAA);
		std::cout << "8. mask.length ? ";
		std::cout << mask.length() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<uint32_t>(0xF0);
		std::cout << "9. mask.get_from(0x38) ? ";
		std::cout << std::hex << mask.get_from(0x38) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<uint32_t>(0xF0);
		std::cout << "10. mask.get_aligned_from(0x38) ? ";
		std::cout << std::hex << mask.get_aligned_from(0x38) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0x5555" << std::endl;
		auto mask = BitMask<uint32_t>(0x5555);
		std::cout << "11. mask.get_from(0x250) ? ";
		std::cout << std::hex << mask.get_from(0x250) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0x0040" << std::endl;
		auto mask = BitMask<uint32_t>(0x040);
		std::cout << "12. mask.get_aligned_from(0x250) ? ";
		std::cout << std::hex << mask.get_aligned_from(0x250) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<uint32_t>(0xF0);
		std::cout << "13. mask.set_to(0x00, 0xAA) ? ";
		std::cout << std::hex << mask.set_to(0x00, 0xAA) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<uint32_t>(0xF0);
		std::cout << "14. mask.set_aligned_to(0xAA, 3) ? ";
		std::cout << std::hex << mask.set_aligned_to(0xAA, 3) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAAAAAAAA" << std::endl;
		auto mask = BitMask<uint32_t>(0xAAAAAAAA);
		std::cout << "15. (~mask) ? ";
		std::cout << std::hex << (~mask).mask << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<uint32_t>(0xF0);
		std::cout << "16. (~mask).get_aligned_from(0x38) ? ";
		std::cout << std::hex << (~mask).get_aligned_from(0x38) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAAAAAAAA" << std::endl;
		auto mask = BitMask<uint32_t>(0xAAAAAAAA);
		std::cout << "17. (~mask | mask).get_from(0xFF00FF00) ? ";
		std::cout << std::hex << (~mask | mask).get_from(0xFF00FF00) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAAAAAAAA" << std::endl;
		auto mask = BitMask<uint32_t>(0xAAAAAAAA);
		std::cout << "18. (~mask & mask).get_from(0xFF00FF00) ? ";
		std::cout << std::hex << (~mask & mask).get_from(0xFF00FF00) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAAAAAAAA" << std::endl;
		auto mask = BitMask<uint32_t>(0xAAAAAAAA);
		std::cout << "19. (~mask ^ mask).get_from(0xFF00FF00) ? ";
		std::cout << std::hex << (~mask ^ mask).get_from(0xFF00FF00) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAAAAAAAA" << std::endl;
		auto mask = BitMask<uint32_t>(0xAAAAAAAA);
		std::cout << "20. (mask ^ mask).get_from(0xFF00FF00) ? ";
		std::cout << std::hex << (mask ^ mask).get_from(0xFF00FF00) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xF0);
		std::cout << "21. mask ? ";
		std::cout << std::hex << mask.mask << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAA" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xAA);
		std::cout << "22. mask ? ";
		std::cout << std::hex << mask.mask << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xF0);
		std::cout << "23. mask.begin_index ? ";
		std::cout << mask.begin_index() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAA" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xAA);
		std::cout << "24. mask.begin_index ? ";
		std::cout << mask.begin_index() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xF0);
		std::cout << "25. mask.end_index ? ";
		std::cout << mask.end_index() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAA" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xAA);
		std::cout << "26. mask.end_index ? ";
		std::cout << mask.end_index() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xF0);
		std::cout << "27. mask.length ? ";
		std::cout << mask.length() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAA" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xAA);
		std::cout << "28. mask.length ? ";
		std::cout << mask.length() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xF0);
		std::cout << "29. mask.get_from(0x38) ? ";
		std::cout << std::hex << mask.get_from(0x38) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xF0);
		std::cout << "30. mask.get_aligned_from(0x38) ? ";
		std::cout << std::hex << mask.get_aligned_from(0x38) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0x5555" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0x5555);
		std::cout << "31. mask.get_from(0x250) ? ";
		std::cout << std::hex << mask.get_from(0x250) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0x0040" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0x040);
		std::cout << "32. mask.get_aligned_from(0x250) ? ";
		std::cout << std::hex << mask.get_aligned_from(0x250) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xF0);
		std::cout << "33. mask.set_to(0x00, 0xAA) ? ";
		std::cout << std::hex << mask.set_to(0x00, 0xAA) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xF0);
		std::cout << "34. mask.set_aligned_to(0xAA, 3) ? ";
		std::cout << std::hex << mask.set_aligned_to(0xAA, 3) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAAAAAAAA" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xAAAAAAAA);
		std::cout << "35. (~mask) ? ";
		std::cout << std::hex << (~mask).mask << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xF0" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xF0);
		std::cout << "36. (~mask).get_aligned_from(0x38) ? ";
		std::cout << std::hex << (~mask).get_aligned_from(0x38) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAAAAAAAA" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xAAAAAAAA);
		std::cout << "37. (~mask | mask).get_from(0xFF00FF00) ? ";
		std::cout << std::hex << (~mask | mask).get_from(0xFF00FF00) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAAAAAAAA" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xAAAAAAAA);
		std::cout << "38. (~mask & mask).get_from(0xFF00FF00) ? ";
		std::cout << std::hex << (~mask & mask).get_from(0xFF00FF00) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAAAAAAAA" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xAAAAAAAA);
		std::cout << "39. (~mask ^ mask).get_from(0xFF00FF00) ? ";
		std::cout << std::hex << (~mask ^ mask).get_from(0xFF00FF00) << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "mask: 0xAAAAAAAA" << std::endl;
		auto mask = BitMask<std::bitset<32>>(0xAAAAAAAA);
		std::cout << "40. (mask ^ mask).get_from(0xFF00FF00) ? ";
		std::cout << std::hex << (mask ^ mask).get_from(0xFF00FF00) << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- BitMask --->" << std::endl;
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
