//	stationaryorbit.core:/comparabletypetraits
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
#include "stationaryorbit/core/comparabletypetraits.hpp"
using namespace zawa_ch::StationaryOrbit;

static_assert(ComparableTypeTraits::IsComparable<uint8_t>, "uint8_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<uint16_t>, "uint16_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<uint32_t>, "uint32_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<uint64_t>, "uint64_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<uintmax_t>, "uintmax_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<uintptr_t>, "uintptr_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<int8_t>, "int8_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<int16_t>, "int16_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<int32_t>, "int32_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<int64_t>, "int64_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<intmax_t>, "intmax_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<intptr_t>, "intptr_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<float>, "float が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<double>, "double が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<size_t>, "size_t が IsComparable 型特性を満たしませんでした。");
static_assert(ComparableTypeTraits::IsComparable<std::string>, "std::string が IsComparable 型特性を満たしませんでした。");
