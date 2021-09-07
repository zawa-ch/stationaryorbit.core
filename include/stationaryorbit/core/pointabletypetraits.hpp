//	stationaryorbit/core/pointabletypetraits
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
#ifndef __stationaryorbit_core_pointabletypetraits__
#define __stationaryorbit_core_pointabletypetraits__
#include <type_traits>
#include "typetraitsbase.hpp"
#include "equatabletypetraits.hpp"
#include "valuetypetraits.hpp"
namespace zawa_ch::StationaryOrbit
{
	class PointableTypeTraits
	{
		PointableTypeTraits() = delete;
		~PointableTypeTraits() = delete;
	private:
		template<class, class, class = void> struct HasPointableTypeOperation_t : std::false_type {};
		template<class T, class U> struct HasPointableTypeOperation_t<T, U, std::enable_if_t< ValueTypeTraits::IsValueType<U> >> : std::conjunction
			<
				std::bool_constant<TypeTraitsBase::substitution_add_result_is_same<T, U, T&>>,
				std::bool_constant<TypeTraitsBase::substitution_subtract_result_is_same<T, U, T&>>,
				std::bool_constant<TypeTraitsBase::addition_result_is_same<T, U, T>>,
				std::bool_constant<TypeTraitsBase::subtraction_result_is_same<T, U, T>>,
				std::bool_constant<TypeTraitsBase::subtraction_result_is_same<T, T, U>>,
				std::bool_constant<EquatableTypeTraits::is_equatable<T, T>>
			>
		{};
		template<class T, class U> struct IsPointableType_t : std::conjunction< std::bool_constant<ValueTypeTraits::IsValueType<T>>, HasPointableTypeOperation_t<T, U> > {};
	public:
		///	型要件:PointableTypeを満たす型を識別します
		template<class T, class U> static constexpr bool IsPointableType = IsPointableType_t<T, U>::value;
	};
}
#endif // __stationaryorbit_core_pointabletypetraits__
