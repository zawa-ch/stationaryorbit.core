//	stationaryorbit.core:/numericaltraits
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
#include "stationaryorbit/core/numericaltraits.hpp"
using namespace zawa_ch::StationaryOrbit;

static_assert(NumericalTraits::IsNumericalType<bool>, "bool が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<uint8_t>, "uint8_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<uint16_t>, "uint16_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<uint32_t>, "uint32_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<uint64_t>, "uint64_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<uintmax_t>, "uintmax_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<uintptr_t>, "uintptr_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<int8_t>, "int8_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<int16_t>, "int16_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<int32_t>, "int32_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<int64_t>, "int64_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<intmax_t>, "intmax_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<intptr_t>, "intptr_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<float>, "float が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<double>, "double が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsNumericalType<size_t>, "size_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(!NumericalTraits::IsNumericalType<std::byte>, "std::byte が IsNumericalType 型特性を満たしました。");
static_assert(!NumericalTraits::IsNumericalType<std::string>, "std::string が IsNumericalType 型特性を満たしました。");

static_assert(!NumericalTraits::IsIntegralType<bool>, "bool が IsIntegralType 型特性を満たしました。");
static_assert(NumericalTraits::IsIntegralType<uint8_t>, "uint8_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsIntegralType<uint16_t>, "uint16_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsIntegralType<uint32_t>, "uint32_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsIntegralType<uint64_t>, "uint64_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsIntegralType<uintmax_t>, "uintmax_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsIntegralType<uintptr_t>, "uintptr_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsIntegralType<int8_t>, "int8_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsIntegralType<int16_t>, "int16_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsIntegralType<int32_t>, "int32_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsIntegralType<int64_t>, "int64_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsIntegralType<intmax_t>, "intmax_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(NumericalTraits::IsIntegralType<intptr_t>, "intptr_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(!NumericalTraits::IsIntegralType<float>, "float が IsIntegralType 型特性を満たしました。");
static_assert(!NumericalTraits::IsIntegralType<double>, "double が IsIntegralType 型特性を満たしました。");
static_assert(NumericalTraits::IsIntegralType<size_t>, "size_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(!NumericalTraits::IsIntegralType<std::byte>, "std::byte が IsIntegralType 型特性を満たしました。");
static_assert(!NumericalTraits::IsIntegralType<std::string>, "std::string が IsIntegralType 型特性を満たしました。");
