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
#include "traits.hpp"
#include "zerovalue.hpp"
#include "rect2dsize.hpp"
namespace zawa_ch::StationaryOrbit
{
	enum class Quadrants { UpRight, UpLeft, DownLeft, DownRight };
	template<Quadrants from, Quadrants to> class QuadrantConvertHelper;
	template<class T, Quadrants quad, class> struct Point2D;
	template<Quadrants quad> struct Point;
	template<Quadrants quad> struct PointF;

	template<Quadrants from, Quadrants to>
	class QuadrantConvertHelper final
	{
	public:
		static constexpr bool InvertX = (((from==Quadrants::UpRight)||(from==Quadrants::DownRight))&&((to==Quadrants::UpLeft)||(to==Quadrants::DownLeft))) || (((from==Quadrants::UpLeft)||(from==Quadrants::DownLeft))&&((to==Quadrants::UpRight)||(to==Quadrants::DownRight)));
		static constexpr bool InvertY = (((from==Quadrants::UpRight)||(from==Quadrants::UpLeft))&&((to==Quadrants::DownRight)||(to==Quadrants::DownLeft))) || (((from==Quadrants::DownRight)||(from==Quadrants::DownLeft))&&((to==Quadrants::UpRight)||(to==Quadrants::UpLeft)));
		template<class T, std::enable_if_t< Traits::IsNumericalType<T>, int> = 0>
		static constexpr T ConvertX(const T& value) { if constexpr (InvertX) { return -value; } else { return value; } }
		template<class T, std::enable_if_t< Traits::IsNumericalType<T>, int> = 0>
		static constexpr T ConvertY(const T& value) { if constexpr (InvertY) { return -value; } else { return value; } }
	};
	///	二次元平面上におけるある一点を表します。
	template<class T, Quadrants quad, class = std::void_t<>>
	struct Point2D final
	{
		static_assert(Traits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
		typedef T ValueType;
	private:
		ValueType _x;
		ValueType _y;
	public:
		constexpr Point2D() = default;
		constexpr Point2D(const ValueType& x, const ValueType& y) noexcept : _x(x), _y(y) {}
		template<Quadrants fromquad>
		constexpr Point2D(const Point2D<T, fromquad>& from) : _x(QuadrantConvertHelper<fromquad, quad>::ConvertX(from.X())), _y(QuadrantConvertHelper<fromquad, quad>::ConvertY(from.Y())) {}
		template<class fromT, Quadrants fromquad, std::enable_if_t<std::is_convertible_v<fromT, T>, int> = 0>
		constexpr Point2D(const Point2D<fromT, fromquad>& from) : _x(QuadrantConvertHelper<fromquad, quad>::ConvertX(T(from.X()))), _y(QuadrantConvertHelper<fromquad, quad>::ConvertY(T(from.Y()))) {}
		template<class fromT, Quadrants fromquad, std::enable_if_t<std::conjunction_v<std::negation<std::is_convertible<fromT, T>>, std::is_constructible<T, fromT>>, int> = 0>
		constexpr explicit Point2D(const Point2D<fromT, fromquad>& from) : _x(QuadrantConvertHelper<fromquad, quad>::ConvertX(T(from.X()))), _y(QuadrantConvertHelper<fromquad, quad>::ConvertY(T(from.Y()))) {}
		constexpr Point2D(const ZeroValue_t&) : _x(Zero), _y(Zero) {}

		[[nodiscard]] constexpr const ValueType& X() const { return _x; }
		[[nodiscard]] constexpr const ValueType& Y() const { return _y; }

		[[nodiscard]] constexpr Point2D<T, quad> operator+(const Point2D<T, quad>& other) const { return Point2D<T, quad>(_x + other._x, _y + other._y); }
		[[nodiscard]] constexpr Point2D<T, quad> operator-(const Point2D<T, quad>& other) const { return Point2D<T, quad>(_x - other._x, _y - other._y); }
		[[nodiscard]] constexpr Point2D<T, quad> operator*(const ValueType& other) const { return Point2D<T, quad>(_x * other, _y * other); }
		[[nodiscard]] constexpr Point2D<T, quad> operator/(const ValueType& other) const { return Point2D<T, quad>(_x / other, _y / other); }
		[[nodiscard]] constexpr Point2D<T, quad> operator+(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x + other.Width(), _y + other.Height()); }
		[[nodiscard]] constexpr Point2D<T, quad> operator-(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x - other.Width(), _y - other.Height()); }
		[[nodiscard]] constexpr Point2D<T, quad> operator*(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x * other.Width(), _y * other.Height()); }
		[[nodiscard]] constexpr Point2D<T, quad> operator/(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x / other.Width(), _y / other.Height()); }
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

		[[nodiscard]] static constexpr Point2D<T, quad> Empty() { return Point2D<T, quad>{}; }
	};
	///	二次元平面上におけるある一点を表します。
	///	@note
	///	こちらは @a std::is_floting_point_v が @a true の場合の特殊化です。
	template<class T, Quadrants quad>
	struct Point2D<T, quad, std::void_t<std::enable_if_t<std::is_floating_point_v<T>>>> final
	{
		static_assert(Traits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
		typedef T ValueType;
	private:
		ValueType _x;
		ValueType _y;
	public:
		constexpr Point2D() = default;
		constexpr Point2D(const ValueType& x, const ValueType& y) noexcept : _x(x), _y(y) {}
		template<Quadrants fromquad>
		constexpr Point2D(const Point2D<T, fromquad>& from) : _x(QuadrantConvertHelper<fromquad, quad>::ConvertX(from.X())), _y(QuadrantConvertHelper<fromquad, quad>::ConvertY(from.Y())) {}
		template<class fromT, Quadrants fromquad, std::enable_if_t<std::is_convertible_v<fromT, T>, int> = 0>
		constexpr Point2D(const Point2D<fromT, fromquad>& from) : _x(QuadrantConvertHelper<fromquad, quad>::ConvertX(T(from.X()))), _y(QuadrantConvertHelper<fromquad, quad>::ConvertY(T(from.Y()))) {}
		template<class fromT, Quadrants fromquad, std::enable_if_t<std::conjunction_v<std::negation<std::is_convertible<fromT, T>>, std::is_constructible<T, fromT>>, int> = 0>
		constexpr explicit Point2D(const Point2D<fromT, fromquad>& from) : _x(QuadrantConvertHelper<fromquad, quad>::ConvertX(T(from.X()))), _y(QuadrantConvertHelper<fromquad, quad>::ConvertY(T(from.Y()))) {}
		constexpr Point2D(const ZeroValue_t&) : _x(Zero), _y(Zero) {}

		[[nodiscard]] constexpr const ValueType& X() const { return _x; }
		[[nodiscard]] constexpr const ValueType& Y() const { return _y; }

		[[nodiscard]] constexpr Point2D<T, quad> operator+(const Point2D<T, quad>& other) const { return Point2D<T, quad>(_x + other._x, _y + other._y); }
		[[nodiscard]] constexpr Point2D<T, quad> operator-(const Point2D<T, quad>& other) const { return Point2D<T, quad>(_x - other._x, _y - other._y); }
		[[nodiscard]] constexpr Point2D<T, quad> operator*(const ValueType& other) const { return Point2D<T, quad>(_x * other, _y * other); }
		[[nodiscard]] constexpr Point2D<T, quad> operator/(const ValueType& other) const { return Point2D<T, quad>(_x / other, _y / other); }
		[[nodiscard]] constexpr Point2D<T, quad> operator+(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x + other.Width(), _y + other.Height()); }
		[[nodiscard]] constexpr Point2D<T, quad> operator-(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x - other.Width(), _y - other.Height()); }
		[[nodiscard]] constexpr Point2D<T, quad> operator*(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x * other.Width(), _y * other.Height()); }
		[[nodiscard]] constexpr Point2D<T, quad> operator/(const Rect2DSize<T>& other) const { return Point2D<T, quad>(_x / other.Width(), _y / other.Height()); }
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
		[[nodiscard]] Point2D<T, quad> Extract() const { return Point2D<T, quad>(_x - trunc(_x), _y - trunc(_y)); }
		///	@a Point2D<T, quad> を切り捨て方向に丸めます。
		template<class intT = T, std::enable_if_t<std::is_constructible_v<intT, T>, int > = 0>
		[[nodiscard]] Point2D<intT, quad> Floor() const { return Point2D<intT, quad>(intT(floor(X())), intT(floor(Y()))); }
		///	@a Point2D<T, quad> を切り上げ方向に丸めます。
		template<class intT = T, std::enable_if_t<std::is_constructible_v<intT, T>, int > = 0>
		[[nodiscard]] Point2D<intT, quad> Ceiling() const { return Point2D<intT, quad>(intT(ceil(X())), intT(ceil(Y()))); }
		/// @a Point2D<T, quad> を最も近い整数に丸めます。
		template<class intT = T, std::enable_if_t<std::is_constructible_v<intT, T>, int > = 0>
		[[nodiscard]] Point2D<intT, quad> Round() const { return Point2D<intT, quad>(intT(round(X())), intT(round(Y()))); }

		[[nodiscard]] static constexpr Point2D<T, quad> Empty() { return Point2D<T, quad>{}; }
	};

	extern template struct Point2D<uint8_t, Quadrants::UpRight>;
	extern template struct Point2D<uint8_t, Quadrants::UpLeft>;
	extern template struct Point2D<uint8_t, Quadrants::DownLeft>;
	extern template struct Point2D<uint8_t, Quadrants::DownRight>;
	extern template struct Point2D<uint16_t, Quadrants::UpRight>;
	extern template struct Point2D<uint16_t, Quadrants::UpLeft>;
	extern template struct Point2D<uint16_t, Quadrants::DownLeft>;
	extern template struct Point2D<uint16_t, Quadrants::DownRight>;
	extern template struct Point2D<uint32_t, Quadrants::UpRight>;
	extern template struct Point2D<uint32_t, Quadrants::UpLeft>;
	extern template struct Point2D<uint32_t, Quadrants::DownLeft>;
	extern template struct Point2D<uint32_t, Quadrants::DownRight>;
	extern template struct Point2D<uint64_t, Quadrants::UpRight>;
	extern template struct Point2D<uint64_t, Quadrants::UpLeft>;
	extern template struct Point2D<uint64_t, Quadrants::DownLeft>;
	extern template struct Point2D<uint64_t, Quadrants::DownRight>;
	extern template struct Point2D<int8_t, Quadrants::UpRight>;
	extern template struct Point2D<int8_t, Quadrants::UpLeft>;
	extern template struct Point2D<int8_t, Quadrants::DownLeft>;
	extern template struct Point2D<int8_t, Quadrants::DownRight>;
	extern template struct Point2D<int16_t, Quadrants::UpRight>;
	extern template struct Point2D<int16_t, Quadrants::UpLeft>;
	extern template struct Point2D<int16_t, Quadrants::DownLeft>;
	extern template struct Point2D<int16_t, Quadrants::DownRight>;
	extern template struct Point2D<int32_t, Quadrants::UpRight>;
	extern template struct Point2D<int32_t, Quadrants::UpLeft>;
	extern template struct Point2D<int32_t, Quadrants::DownLeft>;
	extern template struct Point2D<int32_t, Quadrants::DownRight>;
	extern template struct Point2D<int64_t, Quadrants::UpRight>;
	extern template struct Point2D<int64_t, Quadrants::UpLeft>;
	extern template struct Point2D<int64_t, Quadrants::DownLeft>;
	extern template struct Point2D<int64_t, Quadrants::DownRight>;
	extern template struct Point2D<float, Quadrants::UpRight>;
	extern template struct Point2D<float, Quadrants::UpLeft>;
	extern template struct Point2D<float, Quadrants::DownLeft>;
	extern template struct Point2D<float, Quadrants::DownRight>;
	extern template struct Point2D<double, Quadrants::UpRight>;
	extern template struct Point2D<double, Quadrants::UpLeft>;
	extern template struct Point2D<double, Quadrants::DownLeft>;
	extern template struct Point2D<double, Quadrants::DownRight>;

	typedef Point2D<int, Quadrants::UpRight> GeometricPoint;
	typedef Point2D<float, Quadrants::UpRight> GeometricPointF;
}
#endif // __stationaryorbit_core_point__