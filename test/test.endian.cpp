//	stationaryorbit.core.test.endian:/test.endian.cpp
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
#include "stationaryorbit/core.bitoperation.hpp"
using namespace zawa_ch::StationaryOrbit;

constexpr int check_if(bool condition)
{
	if (condition)
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

template<size_t N>
std::ostream& dump(std::ostream& stream, const std::array<std::byte, N>& data)
{
	auto flags = stream.flags();
	auto width = stream.width();
	auto fill = stream.fill();
	size_t n = 0;
	for(auto i: data)
	{
		if(16 <= n)
		{
			n = 0;
			std::cout << std::endl;
		}
		stream.width(2);
		stream.fill('0');
		stream << std::hex << std::uppercase << uint16_t(i);
		++n;
	}
	stream.flags(flags);
	stream.width(width);
	stream.fill(fill);
	return stream;
}

constexpr std::array<std::byte, 4> ledata = { std::byte{0xEF}, std::byte{0xBE}, std::byte{0xAD}, std::byte{0xDE} };
constexpr std::array<std::byte, 4> bedata = { std::byte{0xDE}, std::byte{0xAD}, std::byte{0xBE}, std::byte{0xEF} };

std::array<std::function<int(void)>, 6> tests =
{
	[]()
	{
		std::cout << "ledata = ";
		dump(std::cout, ledata) << std::endl;
		std::cout << "1. LE->BE ? ";
		dump(std::cout, EndianConverter<Endians::little, Endians::big>::convert(ledata)) << std::endl;;
		return 0;
	},
	[]()
	{
		std::cout << "bedata = ";
		dump(std::cout, ledata) << std::endl;
		std::cout << "2. BE->LE ? ";
		dump(std::cout, EndianConverter<Endians::little, Endians::big>::convert(bedata)) << std::endl;;
		return 0;
	},
	[]()
	{
		uint32_t deadbeef = 0xDEADBEEF;
		uint32le_t le_beef = deadbeef;

		std::cout << "3. LE(0xDEADBEEF).value() ->0xDEADBEEF?";
		return check_if(le_beef.value() == deadbeef);
	},
	[]()
	{
		uint32_t deadbeef = 0xDEADBEEF;
		uint32be_t be_beef = deadbeef;

		std::cout << "4. BE(0xDEADBEEF).value() ->0xDEADBEEF?";
		return check_if(be_beef.value() == deadbeef);
	},
	[]()
	{
		uint32_t deadbeef = 0xDEADBEEF;
		uint32le_t le_beef = deadbeef;

		std::cout << "5. LE(0xDEADBEEF).data() ? ";
		dump(std::cout, le_beef.data()) << std::endl;
		return 0;
	},
	[]()
	{
		uint32_t deadbeef = 0xDEADBEEF;
		uint32be_t be_beef = deadbeef;

		std::cout << "6. BE(0xDEADBEEF).data() ? ";
		dump(std::cout, be_beef.data()) << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- Endian --->" << std::endl;
	std::cout << "Current Endian: ";
	if (Endians::native == Endians::little)
	{
		std::cout << "Little endian" << std::endl;
		std::cout << "0xDEADBEEF -> [ EF BE AD DE ]";
	}
	else if (Endians::native == Endians::big)
	{
		std::cout << "Big endian" << std::endl;
		std::cout << "0xDEADBEEF -> [ DE AD BE EF ]";
	}
	else
	{
		std::cout << "not specified" << std::endl;
	}
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
