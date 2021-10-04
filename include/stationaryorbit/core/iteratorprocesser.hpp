//	stationaryorbit/core/iteratorprocesser
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
#ifndef __stationaryorbit_core_iteratorprocesser__
#define __stationaryorbit_core_iteratorprocesser__
#include <functional>
namespace zawa_ch::StationaryOrbit
{
	///	イテレータを使用した処理を行います。
	class IteratorProcesser
	{
	public:
		///	イテレータで列挙されるすべての要素に対して、指定された述語を適用します。
		///	@note
		///	計算時間はイテレータの要素数に比例。
		template<class It, class resultT = typename It::ValueType, class predT = std::function<void(resultT)>>
		constexpr static void ForEach(It iter, const predT& pred)
		{
			iter.reset();
			while(iter.has_value()) { pred(iter.current()); (void)iter.next(); }
		}
	};
}
#endif // __stationaryorbit_core_iteratorprocesser__
