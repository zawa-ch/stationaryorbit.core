//	stationaryorbit.core:/numericaltypetraits
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
#include "stationaryorbit/core/numericaltypetraits.hpp"
using namespace zawa_ch::StationaryOrbit;

static_assert(NumericalTypeTraits::is_numericaltype<bool>, "bool が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<uint8_t>, "uint8_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<uint16_t>, "uint16_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<uint32_t>, "uint32_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<uint64_t>, "uint64_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<uintmax_t>, "uintmax_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<uintptr_t>, "uintptr_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<int8_t>, "int8_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<int16_t>, "int16_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<int32_t>, "int32_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<int64_t>, "int64_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<intmax_t>, "intmax_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<intptr_t>, "intptr_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<float>, "float が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<double>, "double が IsNumericalType 型特性を満たしませんでした。");
static_assert(NumericalTypeTraits::is_numericaltype<size_t>, "size_t が IsNumericalType 型特性を満たしませんでした。");
static_assert(!NumericalTypeTraits::is_numericaltype<std::byte>, "std::byte が IsNumericalType 型特性を満たしました。");
static_assert(!NumericalTypeTraits::is_numericaltype<std::string>, "std::string が IsNumericalType 型特性を満たしました。");

static_assert(!IntegralTypeTraits::is_integraltype<bool>, "bool が IsIntegralType 型特性を満たしました。");
static_assert(IntegralTypeTraits::is_integraltype<uint8_t>, "uint8_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(IntegralTypeTraits::is_integraltype<uint16_t>, "uint16_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(IntegralTypeTraits::is_integraltype<uint32_t>, "uint32_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(IntegralTypeTraits::is_integraltype<uint64_t>, "uint64_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(IntegralTypeTraits::is_integraltype<uintmax_t>, "uintmax_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(IntegralTypeTraits::is_integraltype<uintptr_t>, "uintptr_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(IntegralTypeTraits::is_integraltype<int8_t>, "int8_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(IntegralTypeTraits::is_integraltype<int16_t>, "int16_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(IntegralTypeTraits::is_integraltype<int32_t>, "int32_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(IntegralTypeTraits::is_integraltype<int64_t>, "int64_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(IntegralTypeTraits::is_integraltype<intmax_t>, "intmax_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(IntegralTypeTraits::is_integraltype<intptr_t>, "intptr_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(!IntegralTypeTraits::is_integraltype<float>, "float が IsIntegralType 型特性を満たしました。");
static_assert(!IntegralTypeTraits::is_integraltype<double>, "double が IsIntegralType 型特性を満たしました。");
static_assert(IntegralTypeTraits::is_integraltype<size_t>, "size_t が IsIntegralType 型特性を満たしませんでした。");
static_assert(!IntegralTypeTraits::is_integraltype<std::byte>, "std::byte が IsIntegralType 型特性を満たしました。");
static_assert(!IntegralTypeTraits::is_integraltype<std::string>, "std::string が IsIntegralType 型特性を満たしました。");
