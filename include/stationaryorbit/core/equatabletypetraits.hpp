//	stationaryorbit/core/equatabletypetraits
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
#ifndef __stationaryorbit_core_equatabletypetraits__
#define __stationaryorbit_core_equatabletypetraits__
#include "typetraitsbase.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	型要件:Equatableを満たす型を識別します
	class EquatableTypeTraits
	{
		EquatableTypeTraits() = delete;
		EquatableTypeTraits(const EquatableTypeTraits&) = delete;
		EquatableTypeTraits(EquatableTypeTraits&&) = delete;
		EquatableTypeTraits& operator=(const EquatableTypeTraits&) = delete;
		EquatableTypeTraits& operator=(EquatableTypeTraits&&) = delete;
		~EquatableTypeTraits() = delete;
	private:
		template<class T, class U>
		struct IsEquatable_impl :
			std::conjunction
			<
				std::bool_constant<TypeTraitsBase::equal_result_is_convertible<T, U, bool>>,
				std::bool_constant<TypeTraitsBase::not_equal_result_is_convertible<T, U, bool>>
			>
		{};
	public:
		///	指定された型が 型要件:Equatable を満たすかを識別します。
		template<class T, class U = T> inline constexpr static bool is_equatable = IsEquatable_impl<T, U>::value;

		///	指定されたオブジェクトの等価比較を行います。
		template<typename T, typename U = T> [[nodiscard]] static constexpr bool equals(const T& object, const U& other) { static_assert(is_equatable<T, U>, "型 T は 型要件:Equatable を満たしません。"); return TypeTraitsBase::equal(object, other); }
		///	指定されたオブジェクトの否定等価比較を行います。
		template<typename T, typename U = T> [[nodiscard]] static constexpr bool not_equals(const T& object, const U& other) { static_assert(is_equatable<T, U>, "型 T は 型要件:Equatable を満たしません。"); return TypeTraitsBase::not_equal(object, other); }
	};
}
#endif // __stationaryorbit_core_equatabletypetraits__
