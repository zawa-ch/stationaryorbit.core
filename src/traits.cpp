//	stationaryorbit.core:/traits
//	Copyright 2020-2021 zawa-ch.
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
#include <array>
#include "stationaryorbit/core/traits.hpp"
using namespace zawa_ch::StationaryOrbit;

//	コンパイル時型特性アサーション
static_assert(Traits::IsEquatable<bool>, "bool が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<uint8_t>, "uint8_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<uint16_t>, "uint16_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<uint32_t>, "uint32_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<uint64_t>, "uint64_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<uintmax_t>, "uintmax_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<uintptr_t>, "uintptr_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<int8_t>, "int8_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<int16_t>, "int16_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<int32_t>, "int32_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<int64_t>, "int64_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<intmax_t>, "intmax_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<intptr_t>, "intptr_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<float>, "float が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<double>, "double が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<size_t>, "size_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<std::nullptr_t>, "std::nullptr_t が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<std::byte>, "std::byte が IsEquatable 型特性を満たしませんでした。");
static_assert(Traits::IsEquatable<std::string>, "std::string が IsEquatable 型特性を満たしませんでした。");

static_assert(Traits::IsComparable<uint8_t>, "uint8_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<uint16_t>, "uint16_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<uint32_t>, "uint32_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<uint64_t>, "uint64_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<uintmax_t>, "uintmax_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<uintptr_t>, "uintptr_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<int8_t>, "int8_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<int16_t>, "int16_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<int32_t>, "int32_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<int64_t>, "int64_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<intmax_t>, "intmax_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<intptr_t>, "intptr_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<float>, "float が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<double>, "double が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<size_t>, "size_t が IsComparable 型特性を満たしませんでした。");
static_assert(Traits::IsComparable<std::string>, "std::string が IsComparable 型特性を満たしませんでした。");

static_assert(Traits::IsValueType<bool>, "bool が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<uint8_t>, "uint8_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<uint16_t>, "uint16_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<uint32_t>, "uint32_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<uint64_t>, "uint64_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<uintmax_t>, "uintmax_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<uintptr_t>, "uintptr_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<int8_t>, "int8_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<int16_t>, "int16_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<int32_t>, "int32_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<int64_t>, "int64_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<intmax_t>, "intmax_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<intptr_t>, "intptr_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<float>, "float が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<double>, "double が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<size_t>, "size_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<std::nullptr_t>, "std::nullptr_t が IsValueType 型特性を満たしませんでした。");
static_assert(Traits::IsValueType<std::byte>, "std::byte が IsValueType 型特性を満たしませんでした。");
static_assert(!Traits::IsValueType<std::string>, "std::string が IsValueType 型特性を満たしました。");

static_assert(Traits::SubscriptResultIsConvertible<std::array<uint8_t, 20>, size_t, uint8_t>, "std::array<uint8_t, 20> に operator[](size_t) -> uint8_t がありません");
static_assert(Traits::DereferenceResultIsConvertible<int*, int>, "int* に operator*() -> int がありません");
