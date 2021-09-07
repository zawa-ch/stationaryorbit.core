//	stationaryorbit.core:/valuetypetraits
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
#include <cstdint>
#include <string>
#include "stationaryorbit/core/valuetypetraits.hpp"
using namespace zawa_ch::StationaryOrbit;

static_assert(ValueTypeTraits::is_valuetype<bool>, "bool が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<uint8_t>, "uint8_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<uint16_t>, "uint16_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<uint32_t>, "uint32_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<uint64_t>, "uint64_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<uintmax_t>, "uintmax_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<uintptr_t>, "uintptr_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<int8_t>, "int8_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<int16_t>, "int16_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<int32_t>, "int32_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<int64_t>, "int64_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<intmax_t>, "intmax_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<intptr_t>, "intptr_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<float>, "float が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<double>, "double が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<size_t>, "size_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<std::nullptr_t>, "std::nullptr_t が 型要件:ValueType を満たしませんでした。");
static_assert(ValueTypeTraits::is_valuetype<std::byte>, "std::byte が 型要件:ValueType を満たしませんでした。");
static_assert(!ValueTypeTraits::is_valuetype<std::string>, "std::string が 型要件:ValueType を満たしました。");
