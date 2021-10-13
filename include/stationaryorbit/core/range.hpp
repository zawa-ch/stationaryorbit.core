//	stationaryorbit/core/range
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
#ifndef __stationaryorbit_core_range__
#define __stationaryorbit_core_range__
#include <limits>
#include <type_traits>
#include <stdexcept>
#include "numericaltypetraits.hpp"
#include "ordertypetraits.hpp"
#include "iteratortraits.hpp"
#include "iteratoradaptcontainer.hpp"
#include "arithmetic.hpp"
namespace zawa_ch::StationaryOrbit
{
	template<class T, bool floor_included, bool ceiling_included, typename> class Range;
	template<class T, bool floor_included, bool ceiling_included> class RangeIterator;

	///	二つの値に囲まれた範囲を表します。
	///	@param	T
	///	値を表現する型。
	///	@param	floor_included
	///	範囲に下限値そのものを含むかどうか。
	///	@param	ceiling_included
	///	範囲に上限値そのものを含むかどうか。
	template<typename T, bool floor_included = true, bool ceiling_included = false, typename = std::void_t<>>
	struct Range final
	{
		static_assert(NumericalTypeTraits::is_numericaltype<T>, "この型のテンプレート T は 型要件:NumericalType を満たす必要があります。");
	public:
		///	値の表現に使用されている型。
		typedef T ValueType;
		///	この @a Range の型。
		typedef Range<T, floor_included, ceiling_included> RangeType;
		///	この @a Range のイテレータ。
		typedef RangeIterator<T, floor_included, ceiling_included> IteratorType;

	private:
		ValueType _bottom;
		ValueType _top;

	public:
		///	オブジェクトを既定の値で初期化します。
		constexpr Range() = default;
		///	値を指定してオブジェクトを構築します。
		constexpr Range(const T& bottom, const T& top) noexcept : _bottom(bottom), _top(top) {}

		///	範囲の下限値を取得します。
		[[nodiscard]] constexpr ValueType bottom() const noexcept { return _bottom; }
		///	範囲の上限値を取得します。
		[[nodiscard]] constexpr ValueType top() const noexcept { return _top; }
		///	範囲の長さを求めます。
		[[nodiscard]] constexpr ValueType length() const { return ArithmeticOperation::subtract_checked(_top, _bottom); }

		///	指定された値が範囲に含まれているかを検査します。
		///	@param	value
		///	検査を行う値
		///	@return
		///	範囲に含まれれば @a true を返します。そうでなければ @a false を返します。
		[[nodiscard]] constexpr bool is_included(const T& value) const noexcept { return is_over_bottom(value) && is_under_top(value); }

		///	指定された値が範囲より大きいかを検査します。
		///	@param	value
		///	検査を行う値
		///	@return
		///	範囲より大きければ @a true を返します。そうでなければ @a false を返します。
		[[nodiscard]] constexpr bool is_over_top(const T& value) const noexcept { return is_over_bottom(value) && !is_under_top(value); }
		[[nodiscard]] constexpr bool operator<(const T& value) const noexcept { return is_over_top(value); }

		///	指定された値が範囲より小さいかを検査します。
		///	@param	value
		///	検査を行う値
		///	@return
		///	範囲より小さければ @a true を返します。そうでなければ @a false を返します。
		[[nodiscard]] constexpr bool is_under_bottom(const ValueType& value) const noexcept { return !is_over_bottom(value) && is_under_top(value); }
		[[nodiscard]] constexpr bool operator>(const ValueType& value) const noexcept { return is_under_bottom(value); }

		///	指定された値が範囲の下限より大きいかを検査します。
		///	@param	value
		///	検査を行う値
		///	@return
		///	下限より大きければ @a true を返します。そうでなければ @a false を返します。
		[[nodiscard]] constexpr bool is_over_bottom(const ValueType& value) const noexcept { if constexpr (floor_included) { return NumericalTypeTraits::compare_smaller_or_equal(_bottom, value); } else { return NumericalTypeTraits::compare_smaller(_bottom, value); } }

		///	指定された値が範囲の上限より小さいかを検査します。
		///	@param	value
		///	検査を行う値
		///	@return
		///	上限より小さければ @a true を返します。そうでなければ @a false を返します。
		[[nodiscard]] constexpr bool is_under_top(const ValueType& value) const noexcept { if constexpr (ceiling_included) { return NumericalTypeTraits::compare_smaller_or_equal(value, _top); } else { return NumericalTypeTraits::compare_smaller(value, _top); } }

		///	指定されたオブジェクトがこのオブジェクトと等価であることを判定します。
		[[nodiscard]] constexpr bool equals(const RangeType& value) const noexcept { return NumericalTypeTraits::equals(_bottom, value._bottom)&&NumericalTypeTraits::equals(_top, value._top); }
		[[nodiscard]] constexpr bool operator==(const RangeType& value) const noexcept { return equals(value); }
		[[nodiscard]] constexpr bool operator!=(const RangeType& value) const noexcept { return !equals(value); }
	};
	///	二つの値に囲まれた範囲を表します。
	///	@param	T
	///	値を表現する型。型要件:IntegralType を満たす場合の特殊化が存在します。
	///	@param	floor_included
	///	範囲に下限値そのものを含むかどうか。
	///	@param	ceiling_included
	///	範囲に上限値そのものを含むかどうか。
	template<typename T, bool floor_included, bool ceiling_included>
	struct Range<T, floor_included, ceiling_included, std::enable_if_t<IntegralTypeTraits::is_integraltype<T>>> final
	{
	public:
		///	値の表現に使用されている型。
		typedef T ValueType;
		///	この @a Range の型。
		typedef Range<T, floor_included, ceiling_included> RangeType;
		///	この @a Range のイテレータ。
		typedef RangeIterator<T, floor_included, ceiling_included> IteratorType;

	private:
		ValueType _bottom;
		ValueType _top;

	public:
		///	オブジェクトを既定の値で初期化します。
		constexpr Range() = default;
		///	値を指定してオブジェクトを構築します。
		constexpr Range(const T& bottom, const T& top) noexcept : _bottom(bottom), _top(top) {}

		///	範囲の下限値を取得します。
		[[nodiscard]] constexpr ValueType bottom() const noexcept { return _bottom; }
		///	範囲の上限値を取得します。
		[[nodiscard]] constexpr ValueType top() const noexcept { return _top; }
		///	範囲の長さを求めます。
		[[nodiscard]] constexpr ValueType length() const { return ArithmeticOperation::subtract_checked(_top, _bottom); }

		///	指定された値が範囲に含まれているかを検査します。
		///	@param	value
		///	検査を行う値
		///	@return
		///	範囲に含まれれば @a true を返します。そうでなければ @a false を返します。
		[[nodiscard]] constexpr bool is_included(const T& value) const noexcept { return is_over_bottom(value) && is_under_top(value); }

		///	指定された値が範囲より大きいかを検査します。
		///	@param	value
		///	検査を行う値
		///	@return
		///	範囲より大きければ @a true を返します。そうでなければ @a false を返します。
		[[nodiscard]] constexpr bool is_over_top(const T& value) const noexcept { return is_over_bottom(value) && !is_under_top(value); }
		[[nodiscard]] constexpr bool operator<(const T& value) const noexcept { return is_over_top(value); }

		///	指定された値が範囲より小さいかを検査します。
		///	@param	value
		///	検査を行う値
		///	@return
		///	範囲より小さければ @a true を返します。そうでなければ @a false を返します。
		[[nodiscard]] constexpr bool is_under_bottom(const ValueType& value) const noexcept { return !is_over_bottom(value) && is_under_top(value); }
		[[nodiscard]] constexpr bool operator>(const ValueType& value) const noexcept { return is_under_bottom(value); }

		///	指定された値が範囲の下限より大きいかを検査します。
		///	@param	value
		///	検査を行う値
		///	@return
		///	下限より大きければ @a true を返します。そうでなければ @a false を返します。
		[[nodiscard]] constexpr bool is_over_bottom(const ValueType& value) const noexcept { if constexpr (floor_included) { return NumericalTypeTraits::compare_smaller_or_equal(_bottom, value); } else { return NumericalTypeTraits::compare_smaller(_bottom, value); } }

		///	指定された値が範囲の上限より小さいかを検査します。
		///	@param	value
		///	検査を行う値
		///	@return
		///	上限より小さければ @a true を返します。そうでなければ @a false を返します。
		[[nodiscard]] constexpr bool is_under_top(const ValueType& value) const noexcept { if constexpr (ceiling_included) { return NumericalTypeTraits::compare_smaller_or_equal(value, _top); } else { return NumericalTypeTraits::compare_smaller(value, _top); } }

		[[nodiscard]] constexpr IteratorType get_iterator_begin() const noexcept { return IteratorType(*this, IteratorOrigin::Begin); }
		[[nodiscard]] constexpr IteratorType get_iterator_end() const noexcept { return IteratorType(*this, IteratorOrigin::End); }
		[[nodiscard]] constexpr IteratorAdaptContainer<IteratorType> get_std_iterator() const noexcept { return IteratorAdaptContainer<IteratorType>(get_iterator_begin()); }
		[[nodiscard]] constexpr IteratorReverseAdaptContainer<IteratorType> get_std_reverse_iterator() const noexcept { return IteratorReverseAdaptContainer<IteratorType>(get_iterator_end()); }

		///	指定されたオブジェクトがこのオブジェクトと等価であることを判定します。
		[[nodiscard]] constexpr bool equals(const RangeType& value) const noexcept { return NumericalTypeTraits::equals(_bottom, value._bottom)&&NumericalTypeTraits::equals(_top, value._top); }
		[[nodiscard]] constexpr bool operator==(const RangeType& value) const noexcept { return equals(value); }
		[[nodiscard]] constexpr bool operator!=(const RangeType& value) const noexcept { return !equals(value); }
	};

	///	@a Range の区間内を反復するためのイテレータを提供します。
	template<class T, bool floor_included = true, bool ceiling_included = false>
	class RangeIterator
	{
		static_assert(IntegralTypeTraits::is_integraltype<T>, "この型のテンプレート T は 型要件:IntegralType を満たす必要があります。");
	public:

		///	値の表現に使用されている型。
		typedef T ValueType;
		///	元の @a Range の型。
		typedef Range<T, floor_included, ceiling_included> RangeType;
		typedef RangeIterator<T, floor_included, ceiling_included> IteratorType;

	private:

		RangeType _range;
		ValueType _value;

	public:

		constexpr RangeIterator(const RangeType& range) noexcept : RangeIterator(range, IteratorOrigin::Begin) {}
		constexpr RangeIterator(const RangeType& range, const IteratorOrigin& origin) : _range(range), _value(get_origin(range, origin)) {}

		///	このイテレータの現在示している値を取得します。
		[[nodiscard]] constexpr const ValueType& current() const noexcept { return _value; }
		///	このイテレータが示している値を取得できるかを返します。
		[[nodiscard]] constexpr bool has_value() const noexcept { return _range.is_included(_value); }
		///	このイテレータが最初の位置より前にあるかを取得します。
		[[nodiscard]] constexpr bool is_before_begin() const noexcept { return !_range.is_over_bottom(_value); }
		///	このイテレータが最後の位置より後にあるかを取得します。
		[[nodiscard]] constexpr bool is_after_end() const noexcept { return !_range.is_under_top(_value); }
		///	このイテレータを次に進めます。
		constexpr bool next() noexcept { return _range.is_under_top(_range.is_under_top(_value)?(IntegralTypeTraits::pre_increment(_value)):(_value)); }
		constexpr IteratorType& operator++() { next(); return *this; }
		constexpr IteratorType operator++(int) { IteratorType result = *this; next(); return result; }
		///	このイテレータを前に進めます。
		constexpr bool previous() noexcept { return _range.is_over_bottom(_range.is_over_bottom(_value)?(IntegralTypeTraits::pre_decrement(_value)):(_value)); }
		constexpr IteratorType& operator--() { previous(); return *this; }
		constexpr IteratorType operator--(int) { IteratorType result = *this; previous(); return result; }
		///	このイテレータを初期位置に進めます。
		constexpr void reset() { reset(IteratorOrigin::Begin); }
		///	このイテレータを初期位置に進めます。
		///	@param	origin
		///	進める初期位置の場所。
		constexpr void reset(const IteratorOrigin& origin) { _value = get_origin(_range, origin); }
		///	指定されたオブジェクトがこのオブジェクトと等価であることを判定します。
		[[nodiscard]] constexpr bool equals(const IteratorType& other) const noexcept { return _range.equals(other._range)&&IntegralTypeTraits::equals(_value, other._value); }
		[[nodiscard]] constexpr bool operator==(const IteratorType& other) const noexcept { return equals(other); }
		[[nodiscard]] constexpr bool operator!=(const IteratorType& other) const noexcept { return !equals(other); }

	private:
		[[nodiscard]] constexpr static ValueType get_origin(const RangeType& range, const IteratorOrigin& origin)
		{
			switch(origin)
			{
			case IteratorOrigin::Begin:
				return floor_included?(range.bottom()):(IntegralTypeTraits::add(range.bottom(), T(1)));
			case IteratorOrigin::End:
				return ceiling_included?(range.top()):(IntegralTypeTraits::subtract(range.top(), T(1)));
			default:
				throw std::invalid_argument("origin に無効な値が設定されています。");
			}
		}
	};

}
#endif // __stationaryorbit_core_range__
