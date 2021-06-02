//	stationaryorbit/core/constprogression
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
#ifndef __stationaryorbit_core_constprogression__
#define __stationaryorbit_core_constprogression__
#include <cstddef>
#include "constarray.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	constexpr な関数によるオブジェクトを列挙するためのイテレータを識別します。
	template<class Iter, typename Tp = typename Iter::ValueType>
	class ConstexprIteratorTrait
	{
		ConstexprIteratorTrait() = delete;
		~ConstexprIteratorTrait() = delete;
	public:
		typedef Iter Iterator;
		typedef Tp ValueType;

		static constexpr Iter init = Iter();
		static constexpr ValueType init_value = init.current();
		[[nodiscard]] static constexpr Iter next(const Iter& iter)
		{
			Iter result = iter;
			result.next();
			return result;
		}
		[[nodiscard]] static constexpr ValueType current(const Iter& iter) { return iter.current(); }
	};
	template<class Tp, size_t I>
	class ConstProgression
	{
	public:
		static constexpr typename ConstexprIteratorTrait<Tp>::Iterator iter = ConstexprIteratorTrait<Tp>::next(ConstProgression<Tp, I - 1>::iter);
		static constexpr typename ConstexprIteratorTrait<Tp>::ValueType value = ConstexprIteratorTrait<Tp>::current(iter);
	};
	template<class Tp>
	class ConstProgression<Tp, 0>
	{
	public:
		static constexpr typename ConstexprIteratorTrait<Tp>::Iterator iter = ConstexprIteratorTrait<Tp>::init;
		static constexpr typename ConstexprIteratorTrait<Tp>::ValueType value = ConstexprIteratorTrait<Tp>::init_value;
	};
	template<class Tp, size_t N>
	struct ConstProgressionArray : ConstProgressionArray<Tp, N - 1>::template Concat<ConstProgression<Tp, N - 1>>::Type {};
	template<class Tp>
	struct ConstProgressionArray<Tp, 1> : ConstArray<ConstProgression<Tp, 0>> {};
	template<class Tp>
	struct ConstProgressionArray<Tp, 0> {};
}
#endif // __stationaryorbit_core_constprogression__
