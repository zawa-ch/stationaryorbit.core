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
#include "traits.hpp"
namespace zawa_ch::StationaryOrbit
{
	class EquatableTypeTraits
	{
		EquatableTypeTraits() = delete;
		~EquatableTypeTraits() = delete;
	private:
		template<class T, class U>
		struct IsEquatable_t : std::conjunction< std::bool_constant<Traits::EqualResultIsConvertible<T, U, bool>>, std::bool_constant<Traits::NotEqualResultIsConvertible<T, U, bool>> > {};
	public:
		///	型要件:Equatableを満たす型を識別します
		template<class T, class U = T> inline constexpr static bool IsEquatable = IsEquatable_t<T, U>::value;
	};
}
#endif // __stationaryorbit_core_equatabletypetraits__
