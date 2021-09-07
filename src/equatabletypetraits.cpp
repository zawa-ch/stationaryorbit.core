//	stationaryorbit.core:/equatabletypetraits
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
#include "stationaryorbit/core/equatabletypetraits.hpp"
using namespace zawa_ch::StationaryOrbit;

static_assert(EquatableTypeTraits::is_equatable<bool>, "bool が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<uint8_t>, "uint8_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<uint16_t>, "uint16_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<uint32_t>, "uint32_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<uint64_t>, "uint64_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<uintmax_t>, "uintmax_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<uintptr_t>, "uintptr_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<int8_t>, "int8_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<int16_t>, "int16_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<int32_t>, "int32_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<int64_t>, "int64_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<intmax_t>, "intmax_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<intptr_t>, "intptr_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<float>, "float が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<double>, "double が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<size_t>, "size_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<std::nullptr_t>, "std::nullptr_t が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<std::byte>, "std::byte が 型要件:Equatable を満たしませんでした。");
static_assert(EquatableTypeTraits::is_equatable<std::string>, "std::string が 型要件:Equatable を満たしませんでした。");
