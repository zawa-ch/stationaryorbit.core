//	stationaryorbit/core/point2d
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
#ifndef __stationaryorbit_core_point__
#define __stationaryorbit_core_point__
#include <cmath>
#include "numericaltypetraits.hpp"
#include "zerovalue.hpp"
#include "rect2dsize.hpp"
namespace zawa_ch::StationaryOrbit
{
	enum class Quadrants2D { UpRight, UpLeft, DownLeft, DownRight };
	template<Quadrants2D from, Quadrants2D to> class Quadrant2DConvertHelper;
	template<class T, Quadrants2D quad, class> struct Point2D;

	template<Quadrants2D from, Quadrants2D to>
	class Quadrant2DConvertHelper final
	{
	public:
		static constexpr bool invert_x = (((from==Quadrants2D::UpRight)||(from==Quadrants2D::DownRight))&&((to==Quadrants2D::UpLeft)||(to==Quadrants2D::DownLeft))) || (((from==Quadrants2D::UpLeft)||(from==Quadrants2D::DownLeft))&&((to==Quadrants2D::UpRight)||(to==Quadrants2D::DownRight)));
		static constexpr bool invert_y = (((from==Quadrants2D::UpRight)||(from==Quadrants2D::UpLeft))&&((to==Quadrants2D::DownRight)||(to==Quadrants2D::DownLeft))) || (((from==Quadrants2D::DownRight)||(from==Quadrants2D::DownLeft))&&((to==Quadrants2D::UpRight)||(to==Quadrants2D::UpLeft)));
		template<class T, std::enable_if_t< NumericalTypeTraits::IsNumericalType<T>, int> = 0>
		static constexpr T convert_x(const T& value) { if constexpr (invert_x) { return -value; } else { return value; } }
		template<class T, std::enable_if_t< NumericalTypeTraits::IsNumericalType<T>, int> = 0>
		static constexpr T convert_y(const T& value) { if constexpr (invert_y) { return -value; } else { return value; } }
	};
	///	二次元平面上におけるある一点を表します。
	template<class T, Quadrants2D quad, class = std::void_t<>>
	struct Point2D final
	{
		static_assert(NumericalTypeTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
		typedef T ValueType;
	private:
		ValueType _x;
		ValueType _y;
	public:
		constexpr Point2D() = default;
		constexpr Point2D(const ValueType& x, const ValueType& y) noexcept : _x(x), _y(y) {}
		template<Quadrants2D fromquad>
		constexpr Point2D(const Point2D<T, fromquad>& from) : _x(Quadrant2DConvertHelper<fromquad, quad>::convert_x(from.x())), _y(Quadrant2DConvertHelper<fromquad, quad>::convert_y(from.y())) {}
		template<class fromT, Quadrants2D fromquad, std::enable_if_t<std::is_convertible_v<fromT, T>, int> = 0>
		constexpr Point2D(const Point2D<fromT, fromquad>& from) : _x(Quadrant2DConvertHelper<fromquad, quad>::convert_x(T(from.x()))), _y(Quadrant2DConvertHelper<fromquad, quad>::convert_y(T(from.y()))) {}
		template<class fromT, Quadrants2D fromquad, std::enable_if_t<std::conjunction_v<std::negation<std::is_convertible<fromT, T>>, std::is_constructible<T, fromT>>, int> = 0>
		constexpr explicit Point2D(const Point2D<fromT, fromquad>& from) : _x(Quadrant2DConvertHelper<fromquad, quad>::convert_x(T(from.x()))), _y(Quadrant2DConvertHelper<fromquad, quad>::convert_y(T(from.y()))) {}
		constexpr Point2D(const ZeroValue_t&) : _x(Zero), _y(Zero) {}

		[[nodiscard]] constexpr const ValueType& x() const { return _x; }
		[[nodiscard]] constexpr const ValueType& y() const { return _y; }

		[[nodiscard]] constexpr Point2D<T, quad> operator+(const Point2D<T, quad>& other) const { return Point2D<T, quad>(_x + other._x, _y + other._y); }
		[[nodiscard]] constexpr Point2D<T, quad> operator-(const Point2D<T, quad>& other) const { return Point2D<T, quad>(_x - other._x, _y - other._y); }
		[[nodiscard]] constexpr Point2D<T, quad> operator*(const ValueType& other) const { return Point2D<T, quad>(_x * other, _y * other); }
		[[nodiscard]] constexpr Point2D<T, quad> operator/(const ValueType& other) const { return Point2D<T, quad>(_x / other, _y / other); }
		[[nodiscard]] constexpr Point2D<T, quad> operator+(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x + other.width(), _y + other.height()); }
		[[nodiscard]] constexpr Point2D<T, quad> operator-(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x - other.width(), _y - other.height()); }
		[[nodiscard]] constexpr Point2D<T, quad> operator*(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x * other.width(), _y * other.height()); }
		[[nodiscard]] constexpr Point2D<T, quad> operator/(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x / other.width(), _y / other.height()); }
		constexpr Point2D<T, quad>& operator+=(const Point2D<T, quad>& other) { return *this = *this + other; }
		constexpr Point2D<T, quad>& operator-=(const Point2D<T, quad>& other) { return *this = *this - other; }
		constexpr Point2D<T, quad>& operator*=(const ValueType& other) { return *this = *this * other; }
		constexpr Point2D<T, quad>& operator/=(const ValueType& other) { return *this = *this / other; }
		constexpr Point2D<T, quad>& operator+=(const Rect2DSize<T>& other) { return *this = *this + other; }
		constexpr Point2D<T, quad>& operator-=(const Rect2DSize<T>& other) { return *this = *this - other; }
		constexpr Point2D<T, quad>& operator*=(const Rect2DSize<T>& other) { return *this = *this * other; }
		constexpr Point2D<T, quad>& operator/=(const Rect2DSize<T>& other) { return *this = *this / other; }

		[[nodiscard]] constexpr bool Equals(const Point2D<T, quad>& value) const { return (_x == value._x)&&(_y == value._y); }
		[[nodiscard]] constexpr bool operator==(const Point2D<T, quad>& value) const { return Equals(value); }
		[[nodiscard]] constexpr bool operator!=(const Point2D<T, quad>& value) const { return !Equals(value); }
	};
	///	二次元平面上におけるある一点を表します。
	///	@note
	///	こちらは @a std::is_floting_point_v が @a true の場合の特殊化です。
	template<class T, Quadrants2D quad>
	struct Point2D<T, quad, std::void_t<std::enable_if_t<std::is_floating_point_v<T>>>> final
	{
		static_assert(NumericalTypeTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
		typedef T ValueType;
	private:
		ValueType _x;
		ValueType _y;
	public:
		constexpr Point2D() = default;
		constexpr Point2D(const ValueType& x, const ValueType& y) noexcept : _x(x), _y(y) {}
		template<Quadrants2D fromquad>
		constexpr Point2D(const Point2D<T, fromquad>& from) : _x(Quadrant2DConvertHelper<fromquad, quad>::convert_x(from.x())), _y(Quadrant2DConvertHelper<fromquad, quad>::convert_y(from.y())) {}
		template<class fromT, Quadrants2D fromquad, std::enable_if_t<std::is_convertible_v<fromT, T>, int> = 0>
		constexpr Point2D(const Point2D<fromT, fromquad>& from) : _x(Quadrant2DConvertHelper<fromquad, quad>::convert_x(T(from.x()))), _y(Quadrant2DConvertHelper<fromquad, quad>::convert_y(T(from.y()))) {}
		template<class fromT, Quadrants2D fromquad, std::enable_if_t<std::conjunction_v<std::negation<std::is_convertible<fromT, T>>, std::is_constructible<T, fromT>>, int> = 0>
		constexpr explicit Point2D(const Point2D<fromT, fromquad>& from) : _x(Quadrant2DConvertHelper<fromquad, quad>::convert_x(T(from.x()))), _y(Quadrant2DConvertHelper<fromquad, quad>::convert_y(T(from.y()))) {}
		constexpr Point2D(const ZeroValue_t&) : _x(Zero), _y(Zero) {}

		[[nodiscard]] constexpr const ValueType& x() const { return _x; }
		[[nodiscard]] constexpr const ValueType& y() const { return _y; }

		[[nodiscard]] constexpr Point2D<T, quad> operator+(const Point2D<T, quad>& other) const { return Point2D<T, quad>(_x + other._x, _y + other._y); }
		[[nodiscard]] constexpr Point2D<T, quad> operator-(const Point2D<T, quad>& other) const { return Point2D<T, quad>(_x - other._x, _y - other._y); }
		[[nodiscard]] constexpr Point2D<T, quad> operator*(const ValueType& other) const { return Point2D<T, quad>(_x * other, _y * other); }
		[[nodiscard]] constexpr Point2D<T, quad> operator/(const ValueType& other) const { return Point2D<T, quad>(_x / other, _y / other); }
		[[nodiscard]] constexpr Point2D<T, quad> operator+(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x + other.width(), _y + other.height()); }
		[[nodiscard]] constexpr Point2D<T, quad> operator-(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x - other.width(), _y - other.height()); }
		[[nodiscard]] constexpr Point2D<T, quad> operator*(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x * other.width(), _y * other.height()); }
		[[nodiscard]] constexpr Point2D<T, quad> operator/(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x / other.width(), _y / other.height()); }
		constexpr Point2D<T, quad>& operator+=(const Point2D<T, quad>& other) { return *this = *this + other; }
		constexpr Point2D<T, quad>& operator-=(const Point2D<T, quad>& other) { return *this = *this - other; }
		constexpr Point2D<T, quad>& operator*=(const ValueType& other) { return *this = *this * other; }
		constexpr Point2D<T, quad>& operator/=(const ValueType& other) { return *this = *this / other; }
		constexpr Point2D<T, quad>& operator+=(const Rect2DSize<T>& other) { return *this = *this + other; }
		constexpr Point2D<T, quad>& operator-=(const Rect2DSize<T>& other) { return *this = *this - other; }
		constexpr Point2D<T, quad>& operator*=(const Rect2DSize<T>& other) { return *this = *this * other; }
		constexpr Point2D<T, quad>& operator/=(const Rect2DSize<T>& other) { return *this = *this / other; }

		[[nodiscard]] constexpr bool Equals(const Point2D<T, quad>& value) const { return (_x == value._x)&&(_y == value._y); }
		[[nodiscard]] constexpr bool operator==(const Point2D<T, quad>& value) const { return Equals(value); }
		[[nodiscard]] constexpr bool operator!=(const Point2D<T, quad>& value) const { return !Equals(value); }

		///	@a Point2D<T, quad> の小数部を抜き出します。
		[[nodiscard]] Point2D<T, quad> extract() const { return Point2D<T, quad>(_x - trunc(_x), _y - trunc(_y)); }
		///	@a Point2D<T, quad> を切り捨て方向に丸めます。
		template<class intT = T, std::enable_if_t<std::is_constructible_v<intT, T>, int > = 0>
		[[nodiscard]] Point2D<intT, quad> floor() const { return Point2D<intT, quad>(intT(std::floor(x())), intT(std::floor(y()))); }
		///	@a Point2D<T, quad> を切り上げ方向に丸めます。
		template<class intT = T, std::enable_if_t<std::is_constructible_v<intT, T>, int > = 0>
		[[nodiscard]] Point2D<intT, quad> ceil() const { return Point2D<intT, quad>(intT(std::ceil(x())), intT(std::ceil(y()))); }
		/// @a Point2D<T, quad> を最も近い整数に丸めます。
		template<class intT = T, std::enable_if_t<std::is_constructible_v<intT, T>, int > = 0>
		[[nodiscard]] Point2D<intT, quad> round() const { return Point2D<intT, quad>(intT(std::round(x())), intT(std::round(y()))); }
	};

	extern template struct Point2D<uint8_t, Quadrants2D::UpRight>;
	extern template struct Point2D<uint8_t, Quadrants2D::UpLeft>;
	extern template struct Point2D<uint8_t, Quadrants2D::DownLeft>;
	extern template struct Point2D<uint8_t, Quadrants2D::DownRight>;
	extern template struct Point2D<uint16_t, Quadrants2D::UpRight>;
	extern template struct Point2D<uint16_t, Quadrants2D::UpLeft>;
	extern template struct Point2D<uint16_t, Quadrants2D::DownLeft>;
	extern template struct Point2D<uint16_t, Quadrants2D::DownRight>;
	extern template struct Point2D<uint32_t, Quadrants2D::UpRight>;
	extern template struct Point2D<uint32_t, Quadrants2D::UpLeft>;
	extern template struct Point2D<uint32_t, Quadrants2D::DownLeft>;
	extern template struct Point2D<uint32_t, Quadrants2D::DownRight>;
	extern template struct Point2D<uint64_t, Quadrants2D::UpRight>;
	extern template struct Point2D<uint64_t, Quadrants2D::UpLeft>;
	extern template struct Point2D<uint64_t, Quadrants2D::DownLeft>;
	extern template struct Point2D<uint64_t, Quadrants2D::DownRight>;
	extern template struct Point2D<int8_t, Quadrants2D::UpRight>;
	extern template struct Point2D<int8_t, Quadrants2D::UpLeft>;
	extern template struct Point2D<int8_t, Quadrants2D::DownLeft>;
	extern template struct Point2D<int8_t, Quadrants2D::DownRight>;
	extern template struct Point2D<int16_t, Quadrants2D::UpRight>;
	extern template struct Point2D<int16_t, Quadrants2D::UpLeft>;
	extern template struct Point2D<int16_t, Quadrants2D::DownLeft>;
	extern template struct Point2D<int16_t, Quadrants2D::DownRight>;
	extern template struct Point2D<int32_t, Quadrants2D::UpRight>;
	extern template struct Point2D<int32_t, Quadrants2D::UpLeft>;
	extern template struct Point2D<int32_t, Quadrants2D::DownLeft>;
	extern template struct Point2D<int32_t, Quadrants2D::DownRight>;
	extern template struct Point2D<int64_t, Quadrants2D::UpRight>;
	extern template struct Point2D<int64_t, Quadrants2D::UpLeft>;
	extern template struct Point2D<int64_t, Quadrants2D::DownLeft>;
	extern template struct Point2D<int64_t, Quadrants2D::DownRight>;
	extern template struct Point2D<float, Quadrants2D::UpRight>;
	extern template struct Point2D<float, Quadrants2D::UpLeft>;
	extern template struct Point2D<float, Quadrants2D::DownLeft>;
	extern template struct Point2D<float, Quadrants2D::DownRight>;
	extern template struct Point2D<double, Quadrants2D::UpRight>;
	extern template struct Point2D<double, Quadrants2D::UpLeft>;
	extern template struct Point2D<double, Quadrants2D::DownLeft>;
	extern template struct Point2D<double, Quadrants2D::DownRight>;

	typedef Point2D<int, Quadrants2D::UpRight> GeometricPoint;
	typedef Point2D<float, Quadrants2D::UpRight> GeometricPointF;
}
#endif // __stationaryorbit_core_point__