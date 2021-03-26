//	stationaryorbit.core.test:/bitoperation
//	Copyright 2020 zawa-ch.
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

void Test_BitMask();
void Test_Endian();

void Test_BitOperation()
{
	Test_BitMask();
	Test_Endian();
}

void Test_BitMask()
{
	std::cout << "<--- BitMask --->" << std::endl;
	auto mask = BitMask<uint32_t>(0xF0);
	if (mask.GetFrom(0x38) == 0x30) { std::cout << "mask(0xF0 | 0x38) -> 0x30" << std::endl; } else { throw std::exception(); }
	if (mask.GetAlignedFrom(0x38) == 0x3) { std::cout << "alignedmask(0xF0 | 0x38) -> 0x3" << std::endl; } else { throw std::exception(); }
	if (mask.GetFrom(0x250) == 0x50) { std::cout << "mask(0xF0 | 0x250) -> 0x50" << std::endl; } else { throw std::exception(); }
	if (mask.GetAlignedFrom(0x250) == 0x5) { std::cout << "alignedmask(0xF0 | 0x250) -> 0x5" << std::endl; } else { throw std::exception(); }
	if (BitMask<uint32_t>(0xFFFF).GetFrom(0xDEADBEEF) == 0xBEEF) { std::cout << "mask(0xFFFF | 0xDEADBEEF) -> 0xBEEF" << std::endl; } else { throw std::exception(); }
	if (BitMask<uint32_t>(0xFFFF0000).GetAlignedFrom(0xDEADBEEF) == 0xDEAD) { std::cout << "alignedmask(0xFFFF0000 | 0xDEADBEEF) -> 0xDEAD" << std::endl; } else { throw std::exception(); }
}

void Test_Endian()
{
	std::cout << "<--- Endian --->" << std::endl;
	uint32_t deadbeef = 0xDEADBEEF;
	auto fmtflg = std::cout.setf((std::ios_base::fmtflags)0, (std::ios_base::fmtflags)0);
	std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
	std::cout << "little endian: 0x" << LittleEndian::Convert(deadbeef) << std::endl;
	std::cout << "big endian: 0x" << BigEndian::Convert(deadbeef) << std::endl;
	uint32be_t bevalue = deadbeef;
	std::cout << "0x" << bevalue << std::endl;
	std::cout.setf(fmtflg, std::ios_base::basefield);
}
