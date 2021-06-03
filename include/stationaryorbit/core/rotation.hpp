//	stationaryorbit/core/rotation
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
#ifndef __StationaryOrbit_Rotation__
#define __StationaryOrbit_Rotation__
#include "traits.hpp"
#include "range.hpp"
#include "halfangleformula.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	0[deg]以上360[deg]未満の角度を保持します。
	template<typename Tp>
	struct Rotation
	{
		static_assert(Traits::IsIntegralType<Tp> && Traits::IsBitSequenceType<Tp>, "テンプレート引数 Tp は、型要件:IntegralType と型要件:BitSequenceType をともに満たす必要があります。");
	private:
		Tp _value;

		static constexpr long double pi2 = 6.28318530717958647692528676655900577l;

		constexpr explicit Rotation(const Tp& value) : _value(value) {}
	public:
		Rotation() = default;

		template<typename valueT, std::enable_if_t<Traits::IsNumericalType<valueT>, int> = 0>
		[[nodiscard]] static constexpr Rotation<Tp> from_degree(const valueT& value)
		{
			const long double den = 360.0l / (double(std::numeric_limits<Tp>::max()) + 1);
			return Rotation( Tp( value / den ) );
		}
		template<typename valueT, std::enable_if_t<Traits::IsNumericalType<valueT>, int> = 0>
		[[nodiscard]] static constexpr Rotation<Tp> from_radian(const valueT& value)
		{
			const long double den = pi2 / (double(std::numeric_limits<Tp>::max()) + 1);
			return Rotation( Tp( value / den ) );
		}

		[[nodiscard]] constexpr int quadrant() const noexcept { return (_value >> (bitwidth<Tp> - 2)) + 1; }

		template<typename valueT = long double, std::enable_if_t<Traits::IsNumericalType<valueT>, int> = 0>
		[[nodiscard]] constexpr valueT degree() const noexcept
		{
			const long double scale = 360.0l / (double(std::numeric_limits<Tp>::max()) + 1);
			return valueT(scale * _value);
		}
		template<typename valueT = long double, std::enable_if_t<Traits::IsNumericalType<valueT>, int> = 0>
		[[nodiscard]] constexpr valueT radian() const noexcept
		{
			const long double scale = pi2 / (double(std::numeric_limits<Tp>::max()) + 1);
			return valueT(scale * _value);
		}

		template<typename valueT = long double, std::enable_if_t<Traits::IsNumericalType<valueT>, int> = 0>
		[[nodiscard]] constexpr valueT sin() const { return trigonometric_inner<valueT>().sin; }
		template<typename valueT = long double, std::enable_if_t<Traits::IsNumericalType<valueT>, int> = 0>
		[[nodiscard]] constexpr valueT cos() const { return trigonometric_inner<valueT>().cos; }
		template<typename valueT = long double, std::enable_if_t<Traits::IsNumericalType<valueT>, int> = 0>
		[[nodiscard]] constexpr valueT tan() const { return sin() / cos(); }

		[[nodiscard]] constexpr Rotation<Tp> operator+() const noexcept { return *this; }
		[[nodiscard]] constexpr Rotation<Tp> operator-() const noexcept { return Rotation(-_value); }
		[[nodiscard]] constexpr Rotation<Tp> operator+(const Rotation<Tp>& other) const noexcept { return Rotation(_value + other._value); }
		[[nodiscard]] constexpr Rotation<Tp> operator-(const Rotation<Tp>& other) const noexcept { return Rotation(_value - other._value); }
		template<typename valueT = long double, std::enable_if_t<Traits::IsNumericalType<valueT>, int> = 0>
		[[nodiscard]] constexpr Rotation<Tp> operator*(const valueT& other) const noexcept { return Rotation(Tp(_value * other)); }
		template<typename valueT = long double, std::enable_if_t<Traits::IsNumericalType<valueT>, int> = 0>
		[[nodiscard]] constexpr Rotation<Tp> operator/(const valueT& other) const noexcept { return Rotation(Tp(_value / other)); }

		[[nodiscard]] constexpr bool equals(const Rotation<Tp>& other) const noexcept { return _value == other._value; }
		[[nodiscard]] constexpr bool operator==(const Rotation<Tp>& other) const noexcept { return equals(other); }
		[[nodiscard]] constexpr bool operator!=(const Rotation<Tp>& other) const noexcept { return !equals(other); }
		[[nodiscard]] constexpr bool operator>(const Rotation<Tp>& other) const noexcept { return _value > other._value; }
		[[nodiscard]] constexpr bool operator<(const Rotation<Tp>& other) const noexcept { return _value < other._value; }
		[[nodiscard]] constexpr bool operator>=(const Rotation<Tp>& other) const noexcept { return _value >= other._value; }
		[[nodiscard]] constexpr bool operator<=(const Rotation<Tp>& other) const noexcept { return _value <= other._value; }

	private:
		template<typename valueT = long double, std::enable_if_t<Traits::IsNumericalType<valueT>, int> = 0>
		[[nodiscard]] constexpr TrigonometricResult<valueT> trigonometric_inner() const
		{
			auto result = TrigonometricResult<valueT>{ valueT(0), valueT(1) };
			Tp w = ( ((quadrant() % 2) == 1)?(_value & ~(1 << (bitwidth<Tp> - 1))):((1 << (bitwidth<Tp> - 1)) - (_value & ~(1 << (bitwidth<Tp> - 1)))) );
			for(auto i: Range<size_t>(0, bitwidth<Tp> - 1).GetStdIterator())
			{
				if ((w & (1 << (bitwidth<Tp> - 2 - i))) != 0)
				{
					auto d = HalfAngleFormulaArray<valueT, bitwidth<Tp> - 1>::values[i];
					result = TrigonometricResult<valueT>{ (result.sin * d.cos) + (result.cos * d.sin), (result.cos * d.cos) - (result.sin * d.sin) };
				}
			}
			switch(quadrant())
			{
				case 1: { return result; }
				case 2: { return TrigonometricResult<valueT>{ result.sin, -result.cos }; }
				case 3: { return TrigonometricResult<valueT>{ -result.sin, -result.cos }; }
				case 4: { return TrigonometricResult<valueT>{ -result.sin, result.cos }; }
			}
			return TrigonometricResult<valueT>{};
		}
	};

	typedef Rotation<uint8_t> Rotation8_t;
	typedef Rotation<uint16_t> Rotation16_t;
	typedef Rotation<uint32_t> Rotation32_t;
	typedef Rotation<uint64_t> Rotation64_t;

	extern template struct Rotation<uint8_t>;
	extern template struct Rotation<uint16_t>;
	extern template struct Rotation<uint32_t>;
	extern template struct Rotation<uint64_t>;
}
#endif // __StationaryOrbit_Rotation__