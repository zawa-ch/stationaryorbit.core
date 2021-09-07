//	stationaryorbit.core:/bitsequencetypetraits
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
#include <cstddef>
#include <string>
#include "stationaryorbit/core/bitsequencetypetraits.hpp"
using namespace zawa_ch::StationaryOrbit;

static_assert(BitSequenceTypeTraits::IsBitSequenceType<bool>, "bool が IsBitSequenceType 型特性を満たしませんでした。");
static_assert(BitSequenceTypeTraits::IsBitSequenceType<uint8_t>, "uint8_t が IsBitSequenceType 型特性を満たしませんでした。");
static_assert(BitSequenceTypeTraits::IsBitSequenceType<uint16_t>, "uint16_t が IsBitSequenceType 型特性を満たしませんでした。");
static_assert(BitSequenceTypeTraits::IsBitSequenceType<uint32_t>, "uint32_t が IsBitSequenceType 型特性を満たしませんでした。");
static_assert(BitSequenceTypeTraits::IsBitSequenceType<uint64_t>, "uint64_t が IsBitSequenceType 型特性を満たしませんでした。");
static_assert(BitSequenceTypeTraits::IsBitSequenceType<uintmax_t>, "uintmax_t が IsBitSequenceType 型特性を満たしませんでした。");
static_assert(!BitSequenceTypeTraits::IsBitSequenceType<int8_t>, "int8_t が IsBitSequenceType 型特性を満たしました。");
static_assert(!BitSequenceTypeTraits::IsBitSequenceType<int16_t>, "int16_t が IsBitSequenceType 型特性を満たしました。");
static_assert(!BitSequenceTypeTraits::IsBitSequenceType<int32_t>, "int32_t が IsBitSequenceType 型特性を満たしました。");
static_assert(!BitSequenceTypeTraits::IsBitSequenceType<int64_t>, "int64_t が IsBitSequenceType 型特性を満たしました。");
static_assert(!BitSequenceTypeTraits::IsBitSequenceType<intmax_t>, "intmax_t が IsBitSequenceType 型特性を満たしませんでした。");
static_assert(!BitSequenceTypeTraits::IsBitSequenceType<float>, "float が IsBitSequenceType 型特性を満たしました。");
static_assert(!BitSequenceTypeTraits::IsBitSequenceType<double>, "double が IsBitSequenceType 型特性を満たしました。");
static_assert(BitSequenceTypeTraits::IsBitSequenceType<std::byte>, "std::byte が IsBitSequenceType 型特性を満たしませんでした。");
static_assert(!BitSequenceTypeTraits::IsBitSequenceType<std::string>, "std::string が IsBitSequenceType 型特性を満たしました。");
