//	stationaryorbit/core/halfangleformula
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
#ifndef __stationaryorbit_core_halfangleformula__
#define __stationaryorbit_core_halfangleformula__
#include "algorithms.hpp"
#include "constprogression.hpp"
namespace zawa_ch::StationaryOrbit
{
	template<class Tp>
	struct TrigonometricResult final
	{
		Tp sin;
		Tp cos;
	};
	template<typename Tp>
	class HalfAngleFormulaIterator
	{
	public:
		typedef TrigonometricResult<Tp> ValueType;
	private:
		ValueType _value;
	public:
		constexpr HalfAngleFormulaIterator() : _value({ 1, 0 }) {}
		constexpr void next() { _value = halfangle(_value); }
		constexpr ValueType current() const noexcept { return _value; }

		[[nodiscard]] static constexpr ValueType halfangle(ValueType b) { return ValueType { Algorithms::halfangle_sin(b.cos), Algorithms::halfangle_cos(b.cos) }; }
	};
	template<typename Tp, size_t N>
	struct HalfAngleFormulaArray : ConstProgressionArray<HalfAngleFormulaIterator<Tp>, N> {};
}
#endif // __stationaryorbit_core_halfangleformula__
