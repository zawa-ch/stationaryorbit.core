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

static_assert(BitSequenceTypeTraits::is_bitsequence_type<bool>, "bool が 型要件:BitSequenceType を満たしませんでした。");
static_assert(BitSequenceTypeTraits::is_bitsequence_type<uint8_t>, "uint8_t が 型要件:BitSequenceType を満たしませんでした。");
static_assert(BitSequenceTypeTraits::is_bitsequence_type<uint16_t>, "uint16_t が 型要件:BitSequenceType を満たしませんでした。");
static_assert(BitSequenceTypeTraits::is_bitsequence_type<uint32_t>, "uint32_t が 型要件:BitSequenceType を満たしませんでした。");
static_assert(BitSequenceTypeTraits::is_bitsequence_type<uint64_t>, "uint64_t が 型要件:BitSequenceType を満たしませんでした。");
static_assert(BitSequenceTypeTraits::is_bitsequence_type<uintmax_t>, "uintmax_t が 型要件:BitSequenceType を満たしませんでした。");
static_assert(!BitSequenceTypeTraits::is_bitsequence_type<int8_t>, "int8_t が 型要件:BitSequenceType を満たしました。");
static_assert(!BitSequenceTypeTraits::is_bitsequence_type<int16_t>, "int16_t が 型要件:BitSequenceType を満たしました。");
static_assert(!BitSequenceTypeTraits::is_bitsequence_type<int32_t>, "int32_t が 型要件:BitSequenceType を満たしました。");
static_assert(!BitSequenceTypeTraits::is_bitsequence_type<int64_t>, "int64_t が 型要件:BitSequenceType を満たしました。");
static_assert(!BitSequenceTypeTraits::is_bitsequence_type<intmax_t>, "intmax_t が 型要件:BitSequenceType を満たしませんでした。");
static_assert(!BitSequenceTypeTraits::is_bitsequence_type<float>, "float が 型要件:BitSequenceType を満たしました。");
static_assert(!BitSequenceTypeTraits::is_bitsequence_type<double>, "double が 型要件:BitSequenceType を満たしました。");
static_assert(BitSequenceTypeTraits::is_bitsequence_type<std::byte>, "std::byte が 型要件:BitSequenceType を満たしませんでした。");
static_assert(!BitSequenceTypeTraits::is_bitsequence_type<std::string>, "std::string が 型要件:BitSequenceType を満たしました。");
