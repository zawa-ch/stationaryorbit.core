//	stationaryorbit/core/algorithms
//	Copyright 2020 zawa-ch.
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
#ifndef __stationaryorbit__core_algorithms__
#define __stationaryorbit__core_algorithms__
#include <stdexcept>
#include "traits.hpp"
#include "constarray.hpp"
#include "basicmath.hpp"
#include "range.hpp"
#include "multiplelong.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	ライブラリで使用される基本的なアルゴリズムを実装します。
	///	このクラスは継承できません。
	class Algorithms final
	{
	public:
		///	整数の除算と乗算を行います。
		///	@param	numerator
		///	除算時の被除数。
		///	@param	denominator
		///	除算時の除数。
		///	@param	scale
		///	乗算時の乗数。
		///	@exception
		///	std::invalid_argument
		///	0で除算することはできません。
		template<class Tp>
		[[nodiscard]] static constexpr DivisionResult<Tp> IntegralFraction(const Tp& numerator, const Tp& denominator, const Tp& scale)
		{
			static_assert(std::is_same_v<Tp, bool> || Traits::IsIntegralType<Tp>, "テンプレート型 Tp は整数型またはboolである必要があります。");

			if constexpr (std::is_same_v<Tp, bool>)
			{
				if (denominator == false) { throw std::invalid_argument("分母に0を指定することはできません。"); }
				return { numerator&&scale, false };
			}
			if constexpr (Traits::IsIntegralType<Tp>)
			{
				if (denominator == Tp(0)) { throw std::invalid_argument("分母に0を指定することはできません。"); }
				if constexpr (!std::numeric_limits<Tp>::is_signed)
				{
					auto r = (MultipleULong<Tp, 2UL>(numerator) * scale).Divide(denominator);
					return { Tp(r.Value), Tp(r.Mod) };
				}
				else
				{
					bool s = (numerator < Tp(0)) ^ (denominator < Tp(0)) ^ (scale < Tp(0));
					auto r = IntegralFraction<std::make_unsigned_t<Tp>>((numerator >= Tp(0))?numerator:-numerator, (denominator >= Tp(0))?denominator:-denominator, (scale >= Tp(0))?scale:-scale);
					return { Tp((s)?(-Tp(r.Value)):(Tp(r.Value))), Tp((s)?(-Tp(r.Mod)):(Tp(r.Mod))) };
				}
			}
		}
		///	@a bool のand結合を行います。
		///	このメソッドはちょうど @a left&right に等しい操作を行います。
		[[nodiscard]] static constexpr bool And(const bool& left, const bool& right)
		{
			return left & right;
		}
		///	@a bool のand結合を行います。
		[[nodiscard]] static constexpr bool And(const std::initializer_list<bool>& list)
		{
			bool result = true;
			for(auto i: list)
			{
				result = And(result, i);
			}
			return result;
		}
		///	@a bool のor結合を行います。
		///	このメソッドはちょうど @a left|right に等しい操作を行います。
		[[nodiscard]] static constexpr bool Or(const bool& left, const bool& right)
		{
			return left | right;
		}
		///	@a bool のor結合を行います。
		[[nodiscard]] static constexpr bool Or(const std::initializer_list<bool>& list)
		{
			bool result = false;
			for(auto i: list)
			{
				result = Or(result, i);
			}
			return result;
		}
		///	@a bool のxor結合を行います。
		[[nodiscard]] static constexpr bool Xor(const bool& left, const bool& right)
		{
			return (left | right) & !(left & right);
		}
		///	@a bool のxor結合を行います。
		[[nodiscard]] static constexpr bool Xor(const std::initializer_list<bool>& list)
		{
			bool result = false;
			for(auto i: list)
			{
				result = Xor(result, i);
			}
			return result;
		}
		///	半角公式によるsin(x/2)の導出を行います。
		///	@param	cos
		///	cos(x)の値。
		template<class T>
		[[nodiscard]] static constexpr T HalfAngleSinFormula(const T& cos)
		{
			return BasicMathematics::Sqrt((T(1) - cos) / 2);
		}
		///	半角公式によるcos(x/2)の導出を行います。
		///	@param	cos
		///	cos(x)の値。
		template<class T>
		[[nodiscard]] static constexpr T HalfAngleCosFormula(const T& cos)
		{
			return BasicMathematics::Sqrt((T(1) + cos) / 2);
		}
		///	半角公式によるtan(x/2)の導出を行います。
		///	@param	sin
		///	sin(x)の値。
		///	@param	cos
		///	cos(x)の値。
		template<class T>
		[[nodiscard]] static constexpr T HalfAngleTanFormula(const T& sin, const T& cos)
		{
			return (1 - cos) / sin;
		}
	};

	extern template DivisionResult<bool> Algorithms::IntegralFraction<bool>(const bool& numerator, const bool& denominator, const bool& scale);
	extern template DivisionResult<uint8_t> Algorithms::IntegralFraction<uint8_t>(const uint8_t& numerator, const uint8_t& denominator, const uint8_t& scale);
	extern template DivisionResult<uint16_t> Algorithms::IntegralFraction<uint16_t>(const uint16_t& numerator, const uint16_t& denominator, const uint16_t& scale);
	extern template DivisionResult<uint32_t> Algorithms::IntegralFraction<uint32_t>(const uint32_t& numerator, const uint32_t& denominator, const uint32_t& scale);
	extern template DivisionResult<uint64_t> Algorithms::IntegralFraction<uint64_t>(const uint64_t& numerator, const uint64_t& denominator, const uint64_t& scale);
	extern template DivisionResult<int8_t> Algorithms::IntegralFraction<int8_t>(const int8_t& numerator, const int8_t& denominator, const int8_t& scale);
	extern template DivisionResult<int16_t> Algorithms::IntegralFraction<int16_t>(const int16_t& numerator, const int16_t& denominator, const int16_t& scale);
	extern template DivisionResult<int32_t> Algorithms::IntegralFraction<int32_t>(const int32_t& numerator, const int32_t& denominator, const int32_t& scale);
	extern template DivisionResult<int64_t> Algorithms::IntegralFraction<int64_t>(const int64_t& numerator, const int64_t& denominator, const int64_t& scale);

	template<class T>
	struct TrigonometricResult final
	{
		T Sin;
		T Cos;
	};
	template<class T, size_t N>
	class HalfAngleFormula :
		ConstProgression
		<
			TrigonometricResult<T>,
			[](const TrigonometricResult<T>& b) { return TrigonometricResult<T> { Algorithms::HalfAngleSinFormula(b.Cos), Algorithms::HalfAngleCosFormula(b.Cos) }; },
			TrigonometricResult<T> { 1, 0 },
			N
		>
	{};
}
#endif // __stationaryorbit__core_algorithms__