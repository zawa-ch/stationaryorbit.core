//	stationaryorbit/core/comparabletypetraits
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
#ifndef __stationaryorbit_core_comparabletypetraits__
#define __stationaryorbit_core_comparabletypetraits__
#include "traits.hpp"
namespace zawa_ch::StationaryOrbit
{
	class ComparableTypeTraits
	{
		ComparableTypeTraits() = delete;
		~ComparableTypeTraits() = delete;
	private:
		template<class T, class U>
		struct IsComparable_t : std::conjunction< std::bool_constant<Traits::LargerCompareResultIsConvertible<T, U, bool>>, std::bool_constant<Traits::SmallerCompareResultIsConvertible<T, U, bool>>, std::bool_constant<Traits::LeastCompareResultIsConvertible<T, U, bool>>, std::bool_constant<Traits::MostCompareResultIsConvertible<T, U, bool>> > {};
	public:
		///	型要件:Comparableを満たす型を識別します
		template<class T, class U = T> inline constexpr static bool IsComparable = IsComparable_t<T, U>::value;
	};
}
#endif // __stationaryorbit_core_comparabletypetraits__
