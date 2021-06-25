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
	///	@brief	constexpr な関数によるオブジェクトを列挙するためのイテレータを識別します
	///
	///	constexpr な関数を実行するイテレータを識別します。
	///	このクラスのインスタンスを作成することはできません。
	///
	///	@param	Iter	constexprな関数を実行するイテレータ。 型要件:Iterator を満たし、すべてのメンバ関数が constexpr である必要があります。
	template<class Iter, typename Tp = typename Iter::ValueType>
	class ConstexprIteratorTrait
	{
		ConstexprIteratorTrait() = delete;
		~ConstexprIteratorTrait() = delete;
	public:
		///	イテレータの型。
		typedef Iter Iterator;
		///	イテレータが渡すオブジェクトの型。
		typedef Tp ValueType;

		///	初期値を表すイテレータ。
		static constexpr Iterator init = Iterator();
		///	初期値を示すオブジェクト。
		static constexpr ValueType init_value = init.current();
		///	指定されたイテレータが値を持つかを取得します。
		[[nodiscard]] static constexpr bool has_value(const Iterator& iter) { return iter.has_value(); }
		///	指定されたイテレータの次の値を持つイテレータを取得します。
		[[nodiscard]] static constexpr Iterator next(const Iterator& iter)
		{
			Iterator result = iter;
			result.next();
			return result;
		}
		///	指定されたイテレータの保持している値を取得します。
		[[nodiscard]] static constexpr ValueType current(const Iterator& iter) { return iter.current(); }
	};

	///	constexpr なイテレータを指定回数実行します
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

	///	@brief	constexpr なイテレータを最後まで実行します
	///
	///	constexpr なイテレータを @a has_value() が @a false になるまで実行します。
	///	このクラスは継承できません。また、インスタンスを作成することもできません。
	template<class Tp>
	class ConstProgressionLastValue final
	{
		ConstProgressionLastValue() = delete;
		~ConstProgressionLastValue() = delete;

		static constexpr typename ConstexprIteratorTrait<Tp>::Iterator _i()
		{
			auto i = ConstexprIteratorTrait<Tp>::init;
			do
			{
				auto j = ConstexprIteratorTrait<Tp>::next(i);
				if (ConstexprIteratorTrait<Tp>::has_value(j)) { i = j; }
				else { break; }
			} while (true);
			return i;
		}
	public:
		static constexpr typename ConstexprIteratorTrait<Tp>::Iterator iter = _i();
		static constexpr typename ConstexprIteratorTrait<Tp>::ValueType value = ConstexprIteratorTrait<Tp>::current(iter);
	};

	///	constexpr なイテレータを列挙した @a ConstArray
	template<class Tp, size_t N>
	struct ConstProgressionArray : ConstProgressionArray<Tp, N - 1>::template Concat<ConstProgression<Tp, N - 1>>::Type {};
	template<class Tp>
	struct ConstProgressionArray<Tp, 1> : ConstArray<ConstProgression<Tp, 0>> {};
	template<class Tp>
	struct ConstProgressionArray<Tp, 0> {};
}
#endif // __stationaryorbit_core_constprogression__
