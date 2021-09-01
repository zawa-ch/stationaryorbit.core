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

static_assert(ValueTypeTraits::IsValueType<bool>, "bool が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<uint8_t>, "uint8_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<uint16_t>, "uint16_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<uint32_t>, "uint32_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<uint64_t>, "uint64_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<uintmax_t>, "uintmax_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<uintptr_t>, "uintptr_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<int8_t>, "int8_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<int16_t>, "int16_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<int32_t>, "int32_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<int64_t>, "int64_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<intmax_t>, "intmax_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<intptr_t>, "intptr_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<float>, "float が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<double>, "double が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<size_t>, "size_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<std::nullptr_t>, "std::nullptr_t が IsValueType 型特性を満たしませんでした。");
static_assert(ValueTypeTraits::IsValueType<std::byte>, "std::byte が IsValueType 型特性を満たしませんでした。");
static_assert(!ValueTypeTraits::IsValueType<std::string>, "std::string が IsValueType 型特性を満たしました。");
