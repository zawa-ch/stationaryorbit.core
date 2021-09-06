//	stationaryorbit.core:/typetraitsbase
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
#include <array>
#include "stationaryorbit/core/typetraitsbase.hpp"
using namespace zawa_ch::StationaryOrbit;

//	コンパイル時型特性アサーション

static_assert(TypeTraitsBase::subscript_result_is_convertible<std::array<uint8_t, 20>, size_t, uint8_t>, "std::array<uint8_t, 20> に operator[](size_t) -> uint8_t がありません");
static_assert(TypeTraitsBase::dereference_result_is_convertible<int*, int>, "int* に operator*() -> int がありません");
