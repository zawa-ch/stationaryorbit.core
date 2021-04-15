//	stationaryorbit.core.test.bitmask:/test.endian.cpp
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
#include "stationaryorbit/core.bitoperation.hpp"
using namespace zawa_ch::StationaryOrbit;

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

	uint32_t deadbeef = 0xDEADBEEF;
	uint32be_t be_beef = deadbeef;
	uint32le_t le_beef = deadbeef;

	std::cout << "1. LE->BE(0xDEADBEEF) ->0xEFBEADDE?";
	if (EndianConverter<Endians::little, Endians::big>::Convert(deadbeef) == 0xEFBEADDE)
	{
		std::cout << "...OK" << std::endl;
	}
	else
	{
		std::cout << "...NG" << std::endl;
		throw std::runtime_error("test 1 failed");
	}

	std::cout << "2. BE->LE(0xEFBEADDE) ->0xDEADBEEF?";
	if (EndianConverter<Endians::little, Endians::big>::Convert(0xEFBEADDE) == 0xDEADBEEF)
	{
		std::cout << "...OK" << std::endl;
	}
	else
	{
		std::cout << "...NG" << std::endl;
		throw std::runtime_error("test 2 failed");
	}

	std::cout << "3. LE(0xDEADBEEF).Value() ->0xDEADBEEF?";
	if (le_beef.Value() == 0xDEADBEEF)
	{
		std::cout << "...OK" << std::endl;
	}
	else
	{
		std::cout << "...NG" << std::endl;
		throw std::runtime_error("test 3 failed");
	}

	std::cout << "4. BE(0xDEADBEEF).Value() ->0xDEADBEEF?";
	if (be_beef.Value() == 0xDEADBEEF)
	{
		std::cout << "...OK" << std::endl;
	}
	else
	{
		std::cout << "...NG" << std::endl;
		throw std::runtime_error("test 4 failed");
	}

	std::cout << "5. LE(0xDEADBEEF).Data() != BE(0xDEADBEEF).Data() ->true?";
	if (be_beef.Value() == 0xDEADBEEF)
	{
		std::cout << "...OK" << std::endl;
	}
	else
	{
		std::cout << "...NG" << std::endl;
		throw std::runtime_error("test 5 failed");
	}

	return 0;
}
