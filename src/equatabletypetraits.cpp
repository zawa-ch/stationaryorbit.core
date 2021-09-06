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

static_assert(EquatableTypeTraits::IsEquatable<bool>, "bool が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<uint8_t>, "uint8_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<uint16_t>, "uint16_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<uint32_t>, "uint32_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<uint64_t>, "uint64_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<uintmax_t>, "uintmax_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<uintptr_t>, "uintptr_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<int8_t>, "int8_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<int16_t>, "int16_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<int32_t>, "int32_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<int64_t>, "int64_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<intmax_t>, "intmax_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<intptr_t>, "intptr_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<float>, "float が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<double>, "double が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<size_t>, "size_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<std::nullptr_t>, "std::nullptr_t が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<std::byte>, "std::byte が IsEquatable 型特性を満たしませんでした。");
static_assert(EquatableTypeTraits::IsEquatable<std::string>, "std::string が IsEquatable 型特性を満たしませんでした。");
