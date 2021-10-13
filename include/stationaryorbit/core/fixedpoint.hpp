//	stationaryorbit/core/fixedpoint
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
#ifndef __stationaryorbit_core_fixedpoint__
#define __stationaryorbit_core_fixedpoint__
#include <cstddef>
#include <cstdint>
#include <cmath>
#include <type_traits>
#include "arithmetic.hpp"
#include "fundamental.hpp"
#include "range.hpp"
#include "zerovalue.hpp"
#include "proportion.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	固定小数点数を表します。
	///	@param	Tp
	///	値の格納に用いる型。
	///	@param	Ql
	///	小数部分のビット長。
	///	@note
	///	小数部分のビット長 @a Ql は現在型 @a Tp のビット長を超えることはできませんが、今後の拡張によって実装される可能性はあります。
	///	テンプレート型 @a Tp は符号付きの整数型を使用することはできませんが、今後の拡張によって実装される可能性はあります。
	///	端数処理は現在行われていません。すべて切り捨てで実装されています。
	template<class Tp, size_t Ql>
	class FixedPoint final
	{
		static_assert(std::is_integral_v<Tp>, "テンプレート型 Tp は整数型である必要があります。");
		static_assert(std::is_unsigned_v<Tp>, "テンプレート型 Tp は符号なし算術型である必要があります。");
		static_assert(Ql <= (sizeof(Tp) * 8U), "小数のビット長は型のビット長を超えることはできません。");
	public:
		///	この型の値の表現のために内部で使用されている型。
		typedef Tp ValueType;
		constexpr static const size_t QLength = Ql;
	private:
		ValueType _value;
		constexpr FixedPoint(const Tp& value, const Unit&) : _value(value) {}
	public:
		///	既定の @a FixedPoint オブジェクトを作成します。
		constexpr FixedPoint() noexcept = default;
		constexpr explicit FixedPoint(const Tp& value) : _value(convertFromInteger(value)) {}
		constexpr explicit FixedPoint(const int& value) : _value(convertFromInteger(Tp(value))) {}
		constexpr explicit FixedPoint(const double& value) : _value(convertFromFloat(value)) {}
		///	ほかの @a FixedPoint テンプレート型から変換します。
		template<class fromTp, size_t fromQ>
		constexpr explicit FixedPoint(const FixedPoint<fromTp, fromQ>& from) : FixedPoint(from.template CastTo<Tp, Ql>()) {}
		template<class fromTp>
		constexpr explicit FixedPoint(const Proportion<fromTp>& from)
			: _value
			(
				[](const auto& i) -> ValueType
				{
					const auto n = Proportion<Tp>(i).Data();
					const auto d = Proportion<Tp>::Max().Data();
					auto v = Algorithms::integral_fraction<Tp>(n, d, Tp(1) << Ql);
					return v.value + (((d/2) <= v.mod)?(1):(0));
				}(from)
			)
		{}
		constexpr FixedPoint(const ZeroValue_t&) : _value(0) {}
		constexpr FixedPoint(const FixedPoint<Tp, Ql>&) = default;
		constexpr FixedPoint(FixedPoint<Tp, Ql>&&) = default;
		~FixedPoint() = default;
	public:
		[[nodiscard]] constexpr FixedPoint<Tp, Ql> operator+() const { return *this; }
		[[nodiscard]] constexpr FixedPoint<Tp, Ql> operator-() const { return DirectConstruct(-_value); }
		[[nodiscard]] constexpr FixedPoint<Tp, Ql> operator+(const FixedPoint<Tp, Ql>& other) const { return DirectConstruct(_value + other._value); }
		[[nodiscard]] constexpr FixedPoint<Tp, Ql> operator-(const FixedPoint<Tp, Ql>& other) const { return DirectConstruct(_value - other._value); }
		[[nodiscard]] constexpr FixedPoint<Tp, Ql> operator*(const FixedPoint<Tp, Ql>& other) const
		{
			const size_t width = sizeof(Tp) * 8U;
			const size_t point = width - Ql;
			auto result = Tp();
			for (auto i : Range<size_t>(0U, width).get_std_iterator())
			{
				result |=
					((other._value & (1U << (width - 1U - i))) != 0U)
					? (
						(0 <= std::make_signed_t<size_t>(point - 1 - i))
						? (_value << (point - 1U - i))
						: (_value >> (i + 1U - point))
					)
					: (0U);
			}
			return DirectConstruct(result);
		}
		[[nodiscard]] constexpr FixedPoint<Tp, Ql> operator/(const FixedPoint<Tp, Ql>& other) const
		{
			auto result = Tp(_value / other._value);
			auto remain = Tp(_value % other._value);
			for (auto i : Range<size_t>(0U, QLength).get_std_iterator())
			{
				remain *= 2U;
				result = (result * 2U) + (remain / other._value);
				remain %= other._value;
			}
			// TODO: 端数処理が必要な場合ここに記述する(何も記述しなかった場合端数は切り捨てられる)
			return DirectConstruct(result);
		}
		constexpr FixedPoint<Tp, Ql>& operator+=(const FixedPoint<Tp, Ql>& other) { return *this = *this + other; }
		constexpr FixedPoint<Tp, Ql>& operator-=(const FixedPoint<Tp, Ql>& other) { return *this = *this - other; }
		constexpr FixedPoint<Tp, Ql>& operator*=(const FixedPoint<Tp, Ql>& other) { return *this = *this * other; }
		constexpr FixedPoint<Tp, Ql>& operator/=(const FixedPoint<Tp, Ql>& other) { return *this = *this / other; }

		constexpr bool Equals(const FixedPoint<Tp, Ql>& other) const { return _value == other._value; }
		constexpr bool operator==(const FixedPoint<Tp, Ql>& other) const { return Equals(other); }
		constexpr bool operator!=(const FixedPoint<Tp, Ql>& other) const { return !Equals(other); }

		constexpr int Compare(const FixedPoint<Tp, Ql>& other) const
		{
			if (_value > other._value) { return 1; }
			else if (_value < other._value) { return -1; }
			else { return 0; }
		}
		constexpr bool operator<(const FixedPoint<Tp, Ql>& other) const { return Compare(other) < 0; }
		constexpr bool operator>(const FixedPoint<Tp, Ql>& other) const { return Compare(other) > 0; }
		constexpr bool operator<=(const FixedPoint<Tp, Ql>& other) const { return Compare(other) <= 0; }
		constexpr bool operator>=(const FixedPoint<Tp, Ql>& other) const { return Compare(other) >= 0; }

		FixedPoint<Tp, Ql>& operator=(const FixedPoint<Tp, Ql>& value) = default;
		FixedPoint<Tp, Ql>& operator=(FixedPoint<Tp, Ql>&& value) = default;

		template<class castT, size_t castQ> [[nodiscard]] constexpr FixedPoint<castT, castQ> CastTo() const
		{
			if constexpr (castQ == Ql) { return FixedPoint<castT, castQ>::DirectConstruct(castT(_value)); }
			if constexpr (castQ < Ql) { return FixedPoint<castT, castQ>::DirectConstruct(castT(_value >> (Ql - castQ))); }
			if constexpr (castQ > Ql) { return FixedPoint<castT, castQ>::DirectConstruct(castT(_value << (castQ - Ql))); }
		}
		[[nodiscard]] constexpr explicit operator float() const { return convertToFloat<float>(); }
		[[nodiscard]] constexpr explicit operator double() const { return convertToFloat<double>(); }
		template<class castTp>
		[[nodiscard]] constexpr explicit operator Proportion<castTp>() const
		{
			if (One() < *this) { throw InvalidOperationException("現在のオブジェクトの値が大きすぎるため、Proportionに変換できません。"); }
			return Proportion<castTp>(Proportion<Tp>(_value, 1 << Ql));
		}

	public:
		///	この型で表すことのできる最大の値を取得します。
		[[nodiscard]] constexpr static FixedPoint<Tp, Ql> Max() noexcept { return DirectConstruct(std::numeric_limits<Tp>::max()); }
		///	この型で表すことのできる最小の値を取得します。
		[[nodiscard]] constexpr static FixedPoint<Tp, Ql> Min() noexcept { return DirectConstruct(std::numeric_limits<Tp>::min()); }
		///	この型で表すことのできる1.0の値を取得します。
		[[nodiscard]] constexpr static FixedPoint<Tp, Ql> One() noexcept { return DirectConstruct(Tp(1) << Ql); }
		///	この型で表すことのできる最小の刻み幅を取得します。
		[[nodiscard]] constexpr static FixedPoint<Tp, Ql> Epsilon() noexcept { return DirectConstruct(1); }
		///	空の @a FixedPoint を取得します。
		[[nodiscard]] constexpr static FixedPoint<Tp, Ql> Empty() noexcept { return FixedPoint<Tp, Ql> {}; }
		///	@a FixedPoint を直接構築します。
		[[nodiscard]] constexpr static FixedPoint<Tp, Ql> DirectConstruct(const ValueType& value) noexcept { return FixedPoint<Tp, Ql>(value, UnitValue); }

	private:
		template<class fromT> constexpr static Tp convertFromInteger(const fromT& from)
		{
			if (from <= (std::numeric_limits<Tp>::max() >> Ql)) { return Tp(from << Ql); }
			else { throw std::overflow_error("指定された値がこの型で表せる範囲を超えています。"); }
		}
		template<class fromT> constexpr static Tp convertFromFloat(const fromT& from)
		{
			if ((from == std::numeric_limits<fromT>::quiet_NaN()) || (from == std::numeric_limits<fromT>::signaling_NaN())) { throw std::invalid_argument("指定する値はNaNであってはなりません。"); }
			if ((fromT(Min()) <= from) && (from <= fromT(Max()))) { return Tp(from * std::exp2(QLength)); }
			else { throw std::overflow_error("指定された値がこの型で表せる範囲を超えています。"); }
		}
		template<class castT> constexpr castT convertToFloat() const
		{
			return castT(castT(_value) / std::exp2(QLength));
		}
	};

	extern template class FixedPoint<uint8_t, 7>;
	extern template class FixedPoint<uint16_t, 8>;
	extern template class FixedPoint<uint16_t, 15>;
	extern template class FixedPoint<uint32_t, 16>;
	extern template class FixedPoint<uint32_t, 31>;
	extern template class FixedPoint<uint64_t, 32>;
	extern template class FixedPoint<uint64_t, 63>;

	typedef FixedPoint<uint8_t, 7> FixedPoint8q7_t;
	typedef FixedPoint<uint16_t, 8> FixedPoint16q8_t;
	typedef FixedPoint<uint16_t, 15> FixedPoint16q15_t;
	typedef FixedPoint<uint32_t, 16> FixedPoint32q16_t;
	typedef FixedPoint<uint32_t, 31> FixedPoint32q31_t;
	typedef FixedPoint<uint64_t, 32> FixedPoint64q32_t;
	typedef FixedPoint<uint64_t, 63> FixedPoint64q63_t;

	extern template ArithmeticOperation::AdditionResult<FixedPoint8q7_t> ArithmeticOperation::add<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint16q8_t> ArithmeticOperation::add<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint16q15_t> ArithmeticOperation::add<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint32q16_t> ArithmeticOperation::add<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint32q31_t> ArithmeticOperation::add<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint64q32_t> ArithmeticOperation::add<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint64q63_t> ArithmeticOperation::add<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint8q7_t> ArithmeticOperation::subtract<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint16q8_t> ArithmeticOperation::subtract<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint16q15_t> ArithmeticOperation::subtract<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint32q16_t> ArithmeticOperation::subtract<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint32q31_t> ArithmeticOperation::subtract<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint64q32_t> ArithmeticOperation::subtract<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template ArithmeticOperation::AdditionResult<FixedPoint64q63_t> ArithmeticOperation::subtract<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint8q7_t> ArithmeticOperation::multiply<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint16q8_t> ArithmeticOperation::multiply<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint16q15_t> ArithmeticOperation::multiply<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint32q16_t> ArithmeticOperation::multiply<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint32q31_t> ArithmeticOperation::multiply<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint64q32_t> ArithmeticOperation::multiply<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint64q63_t> ArithmeticOperation::multiply<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint8q7_t> ArithmeticOperation::divide<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint16q8_t> ArithmeticOperation::divide<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint16q15_t> ArithmeticOperation::divide<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint32q16_t> ArithmeticOperation::divide<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint32q31_t> ArithmeticOperation::divide<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint64q32_t> ArithmeticOperation::divide<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template ArithmeticOperation::MultiplicationResult<FixedPoint64q63_t> ArithmeticOperation::divide<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template FixedPoint8q7_t ArithmeticOperation::add_saturate<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template FixedPoint16q8_t ArithmeticOperation::add_saturate<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template FixedPoint16q15_t ArithmeticOperation::add_saturate<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template FixedPoint32q16_t ArithmeticOperation::add_saturate<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template FixedPoint32q31_t ArithmeticOperation::add_saturate<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template FixedPoint64q32_t ArithmeticOperation::add_saturate<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template FixedPoint64q63_t ArithmeticOperation::add_saturate<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template FixedPoint8q7_t ArithmeticOperation::subtract_saturate<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template FixedPoint16q8_t ArithmeticOperation::subtract_saturate<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template FixedPoint16q15_t ArithmeticOperation::subtract_saturate<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template FixedPoint32q16_t ArithmeticOperation::subtract_saturate<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template FixedPoint32q31_t ArithmeticOperation::subtract_saturate<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template FixedPoint64q32_t ArithmeticOperation::subtract_saturate<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template FixedPoint64q63_t ArithmeticOperation::subtract_saturate<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template FixedPoint8q7_t ArithmeticOperation::multiply_saturate<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template FixedPoint16q8_t ArithmeticOperation::multiply_saturate<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template FixedPoint16q15_t ArithmeticOperation::multiply_saturate<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template FixedPoint32q16_t ArithmeticOperation::multiply_saturate<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template FixedPoint32q31_t ArithmeticOperation::multiply_saturate<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template FixedPoint64q32_t ArithmeticOperation::multiply_saturate<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template FixedPoint64q63_t ArithmeticOperation::multiply_saturate<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template FixedPoint8q7_t ArithmeticOperation::divide_saturate<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template FixedPoint16q8_t ArithmeticOperation::divide_saturate<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template FixedPoint16q15_t ArithmeticOperation::divide_saturate<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template FixedPoint32q16_t ArithmeticOperation::divide_saturate<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template FixedPoint32q31_t ArithmeticOperation::divide_saturate<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template FixedPoint64q32_t ArithmeticOperation::divide_saturate<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template FixedPoint64q63_t ArithmeticOperation::divide_saturate<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template FixedPoint8q7_t ArithmeticOperation::add_checked<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template FixedPoint16q8_t ArithmeticOperation::add_checked<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template FixedPoint16q15_t ArithmeticOperation::add_checked<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template FixedPoint32q16_t ArithmeticOperation::add_checked<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template FixedPoint32q31_t ArithmeticOperation::add_checked<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template FixedPoint64q32_t ArithmeticOperation::add_checked<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template FixedPoint64q63_t ArithmeticOperation::add_checked<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template FixedPoint8q7_t ArithmeticOperation::subtract_checked<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template FixedPoint16q8_t ArithmeticOperation::subtract_checked<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template FixedPoint16q15_t ArithmeticOperation::subtract_checked<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template FixedPoint32q16_t ArithmeticOperation::subtract_checked<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template FixedPoint32q31_t ArithmeticOperation::subtract_checked<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template FixedPoint64q32_t ArithmeticOperation::subtract_checked<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template FixedPoint64q63_t ArithmeticOperation::subtract_checked<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template FixedPoint8q7_t ArithmeticOperation::multiply_checked<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template FixedPoint16q8_t ArithmeticOperation::multiply_checked<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template FixedPoint16q15_t ArithmeticOperation::multiply_checked<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template FixedPoint32q16_t ArithmeticOperation::multiply_checked<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template FixedPoint32q31_t ArithmeticOperation::multiply_checked<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template FixedPoint64q32_t ArithmeticOperation::multiply_checked<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template FixedPoint64q63_t ArithmeticOperation::multiply_checked<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template FixedPoint8q7_t ArithmeticOperation::divide_checked<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template FixedPoint16q8_t ArithmeticOperation::divide_checked<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template FixedPoint16q15_t ArithmeticOperation::divide_checked<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template FixedPoint32q16_t ArithmeticOperation::divide_checked<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template FixedPoint32q31_t ArithmeticOperation::divide_checked<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template FixedPoint64q32_t ArithmeticOperation::divide_checked<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template FixedPoint64q63_t ArithmeticOperation::divide_checked<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template bool ArithmeticOperation::may_overflow_addition<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template bool ArithmeticOperation::may_overflow_addition<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template bool ArithmeticOperation::may_overflow_addition<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template bool ArithmeticOperation::may_overflow_addition<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template bool ArithmeticOperation::may_overflow_addition<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template bool ArithmeticOperation::may_overflow_addition<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template bool ArithmeticOperation::may_overflow_addition<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
	extern template bool ArithmeticOperation::may_overflow_division<FixedPoint8q7_t>(const FixedPoint8q7_t&, const FixedPoint8q7_t&);
	extern template bool ArithmeticOperation::may_overflow_division<FixedPoint16q8_t>(const FixedPoint16q8_t&, const FixedPoint16q8_t&);
	extern template bool ArithmeticOperation::may_overflow_division<FixedPoint16q15_t>(const FixedPoint16q15_t&, const FixedPoint16q15_t&);
	extern template bool ArithmeticOperation::may_overflow_division<FixedPoint32q16_t>(const FixedPoint32q16_t&, const FixedPoint32q16_t&);
	extern template bool ArithmeticOperation::may_overflow_division<FixedPoint32q31_t>(const FixedPoint32q31_t&, const FixedPoint32q31_t&);
	extern template bool ArithmeticOperation::may_overflow_division<FixedPoint64q32_t>(const FixedPoint64q32_t&, const FixedPoint64q32_t&);
	extern template bool ArithmeticOperation::may_overflow_division<FixedPoint64q63_t>(const FixedPoint64q63_t&, const FixedPoint64q63_t&);
}
namespace std
{
	template<class T, size_t Ql>
	class numeric_limits<zawa_ch::StationaryOrbit::FixedPoint<T, Ql>> : public numeric_limits<void>
	{
	public:
		static constexpr bool is_specialized = true;
		static constexpr bool is_signed = false;
		static constexpr bool is_integer = false;
		static constexpr bool is_exact = true;
		static constexpr bool has_infinity = false;
		static constexpr bool has_quiet_NaN = false;
		static constexpr bool has_signaling_NaN = false;
		static constexpr float_denorm_style has_denorm = denorm_absent;
		static constexpr bool has_denorm_loss = false;
		static constexpr float_round_style round_style = round_toward_zero;
		static constexpr bool is_iec559 = false;
		static constexpr bool is_bounded = true;
		static constexpr bool is_modulo = true;
		static constexpr int digits = numeric_limits<T>::digits;
		static constexpr int digits10 = numeric_limits<T>::digits10;
		static constexpr int max_digits10 = numeric_limits<T>::max_digits10;
		static constexpr int radix = 2;
		static constexpr int min_exponent = 0;
		static constexpr int min_exponent10 = 0;
		static constexpr int max_exponent = 0;
		static constexpr int max_exponent10 = 0;
		static constexpr bool traps = true;
		static constexpr bool tinyness_before = true;
		static constexpr zawa_ch::StationaryOrbit::FixedPoint<T, Ql> min() noexcept { return zawa_ch::StationaryOrbit::FixedPoint<T, Ql>::Min(); }
		static constexpr zawa_ch::StationaryOrbit::FixedPoint<T, Ql> lowest() noexcept { return zawa_ch::StationaryOrbit::FixedPoint<T, Ql>::Min(); }
		static constexpr zawa_ch::StationaryOrbit::FixedPoint<T, Ql> max() noexcept { return zawa_ch::StationaryOrbit::FixedPoint<T, Ql>::Max(); }
		static constexpr zawa_ch::StationaryOrbit::FixedPoint<T, Ql> epsilon() noexcept { return zawa_ch::StationaryOrbit::FixedPoint<T, Ql>::Epsilon(); }
		static constexpr zawa_ch::StationaryOrbit::FixedPoint<T, Ql> round_error() noexcept { return zawa_ch::StationaryOrbit::FixedPoint<T, Ql>::DirectConstruct((T(1) << Ql) - 1); }
	};
}
#endif // __stationaryorbit_core_fixedpoint__
