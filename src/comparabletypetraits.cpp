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

static_assert(ComparableTypeTraits::is_comparable<uint8_t>, "uint8_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<uint16_t>, "uint16_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<uint32_t>, "uint32_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<uint64_t>, "uint64_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<uintmax_t>, "uintmax_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<uintptr_t>, "uintptr_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<int8_t>, "int8_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<int16_t>, "int16_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<int32_t>, "int32_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<int64_t>, "int64_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<intmax_t>, "intmax_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<intptr_t>, "intptr_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<float>, "float が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<double>, "double が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<size_t>, "size_t が 型要件:Comparable を満たしませんでした。");
static_assert(ComparableTypeTraits::is_comparable<std::string>, "std::string が 型要件:Comparable を満たしませんでした。");
