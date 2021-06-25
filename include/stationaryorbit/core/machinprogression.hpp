//	stationaryorbit/core/marchinprogression
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
#ifndef __stationaryorbit_core_marchinprogression__
#define __stationaryorbit_core_marchinprogression__
#include "algorithms.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	@brief	マチンの公式を用いて円周率を導出するためのイテレータ
	///
	///	マチンの公式(Machin's formula)を用いて円周率を導出します。
	///	イテレータを進めることで反復計算を一度行い、円周率に近似させます。
	///	クラス内のすべての関数はconstexprであり、 名前付き要件:LiteralType を満たす型に対し、コンパイル時演算で円周率を求めることができます。
	///	このクラスは継承できません。
	///
	///	@param	Tp	円周率を導出するための値を格納する型。 型要件:NumericalType を満たす必要があります。
	template<typename Tp>
	class MarchinProgression final
	{
		static_assert(Traits::IsNumericalType<Tp>, "テンプレート引数型 Tp は、型要件:NumericalType を満たす必要があります。");
	public:
		typedef Tp ValueType;
	private:
		static constexpr Tp _x1 = Tp(1) / Tp(5);
		static constexpr Tp _x2 = Tp(1) / Tp(239);
		size_t _iteration;
		Algorithms::ArctanProgressionIterator<Tp> _f1;
		Algorithms::ArctanProgressionIterator<Tp> _f2;
		Tp _r1;
		Tp _c1;
		Tp _r2;
		Tp _c2;
		bool _cont;
	public:
		constexpr MarchinProgression() : _iteration(0), _f1(_x1), _f2(_x2), _r1(0), _c1(0), _r2(0), _c2(0), _cont(true) {}

		///	反復計算が可能であるかを取得します。
		[[nodiscard]] constexpr bool has_value() const noexcept { return _cont; }
		///	オブジェクトが指す現在の値を取得します。
		[[nodiscard]] constexpr Tp current() const noexcept { return ((_r1 - _c1) * Tp(16)) - ((_r2 - _c2) * (Tp(4))); }
		///	反復計算を一度行い、内部状態を更新します。
		constexpr bool next()
		{
			++_iteration;
			auto m = false;
			if (true)
			{
				_f1.next();
				auto b = _r1;
				auto d = _f1.current();
				_r1 += (d - _c1);
				_c1 = (_r1 - b) - d;
				m = m || ((_r1 - _c1) != b);
			}
			if ((_iteration % 4) == 0)
			{
				_f2.next();
				auto b = _r2;
				auto d = _f2.current();
				_r2 += (d - _c2);
				_c2 = (_r2 - b) - d;
				m = m || ((_r2 - _c2) != b);
			}
			else
			{
				m = true;
			}
			return _cont = m;
		}
	};
}
#endif // __stationaryorbit_core_marchinprogression__
