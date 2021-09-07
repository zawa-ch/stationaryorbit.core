//	stationaryorbit/core/valuetypetraits
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
#ifndef __stationaryorbit_core_valuetypetraits__
#define __stationaryorbit_core_valuetypetraits__
#include <type_traits>
#include "equatabletypetraits.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	型要件:ValueType を満たす型を識別します
	class ValueTypeTraits : public EquatableTypeTraits
	{
		ValueTypeTraits() = delete;
		ValueTypeTraits(const ValueTypeTraits&) = delete;
		ValueTypeTraits(ValueTypeTraits&&) = delete;
		ValueTypeTraits& operator=(const ValueTypeTraits&) = delete;
		ValueTypeTraits& operator=(ValueTypeTraits&&) = delete;
		~ValueTypeTraits() = delete;
	private:
		template<typename T> struct IsValueType_impl : std::conjunction
			<
				std::is_default_constructible<T>,
				std::is_trivially_default_constructible<T>,
				std::is_nothrow_default_constructible<T>,
				std::is_destructible<T>,
				std::is_nothrow_destructible<T>,
				std::is_trivially_destructible<T>,
				std::is_copy_constructible<T>,
				std::is_nothrow_copy_constructible<T>,
				std::is_trivially_copy_constructible<T>,
				std::is_move_constructible<T>,
				std::is_nothrow_move_constructible<T>,
				std::is_trivially_move_constructible<T>,
				std::is_copy_assignable<T>,
				std::is_nothrow_copy_assignable<T>,
				std::is_trivially_copy_assignable<T>,
				std::is_move_assignable<T>,
				std::is_nothrow_move_assignable<T>,
				std::is_trivially_move_assignable<T>,
				std::bool_constant<is_equatable<T, T>>
			>
		{};
	public:
		///	指定された型が 型要件:ValueType を満たすかを識別します。
		template<typename T> static constexpr bool is_valuetype = IsValueType_impl<T>::value;
	};
}
#endif // __stationaryorbit_core_valuetypetraits__
