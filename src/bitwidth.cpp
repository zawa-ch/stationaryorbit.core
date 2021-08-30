//	stationaryorbit.core:/bitwidth
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
#include <cstdint>
#include "stationaryorbit/core/bitwidth.hpp"
using namespace zawa_ch::StationaryOrbit;

static_assert(bitwidth<bool> == 1UL, "bool のビット幅が 1 ではありません");
static_assert(bitwidth<uint8_t> == 8UL, "uint8_t のビット幅が 8 ではありません");
static_assert(bitwidth<uint16_t> == 16UL, "uint16_t のビット幅が 16 ではありません");
static_assert(bitwidth<uint32_t> == 32UL, "uint32_t のビット幅が 32 ではありません");
static_assert(bitwidth<uint64_t> == 64UL, "uint64_t のビット幅が 64 ではありません");
static_assert(bitwidth<std::bitset<14>> == 14UL, "std::bitset<14> のビット幅が 14 ではありません");
