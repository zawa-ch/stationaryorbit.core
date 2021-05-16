//	stationaryorbit/core/rectangle2d
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
#ifndef __stationaryorbit_core_rectangle__
#define __stationaryorbit_core_rectangle__
#include "range.hpp"
#include "rect2dsize.hpp"
#include "point2d.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	@a Point2D と @a Rect2DSize によって表される矩形範囲を表します。
	template<class T, Quadrants2D quad, class = void>
	struct Rectangle2D final
	{
		static_assert(Traits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
	public:
		typedef T ValueType;
		typedef Point2D<T, quad> PointType;
		typedef Rect2DSize<T> SizeType;
	private:
		PointType _o;
		SizeType _s;
	public:
		constexpr Rectangle2D() = default;
		constexpr Rectangle2D(const PointType& origin, const SizeType& size) : _o(origin), _s(size) {}
		constexpr Rectangle2D(const ValueType& originx, const ValueType& originy, const ValueType& width, const ValueType& height) : _o(originx, originy), _s(width, height) {}
		template<Quadrants2D fromquad>
		constexpr Rectangle2D(const Rectangle2D<T, fromquad>& from) : _o(from.origin()), _s(from.size()) {}
		template<class fromT, Quadrants2D fromquad, std::enable_if_t<std::is_convertible_v<fromT, T>, int> = 0>
		constexpr Rectangle2D(const Rectangle2D<fromT, fromquad>& from) : _o(from.origin()), _s(from.size()) {}
		template<class fromT, Quadrants2D fromquad, std::enable_if_t<std::conjunction_v<std::negation<std::is_convertible<fromT, T>>, std::is_constructible<T, fromT>>, int> = 0>
		constexpr explicit Rectangle2D(const Rectangle2D<fromT, fromquad>& from) : _o(from.origin()), _s(from.size()) {}
		constexpr Rectangle2D(const ZeroValue_t&) : _o(Zero), _s(Zero) {}

		///	@a Rectangle2D の原点を表す @a PointType を取得します。
		[[nodiscard]] constexpr const PointType& origin() const noexcept { return _o; }
		///	@a Rectangle2D の大きさを表す @a SizeType を取得します。
		[[nodiscard]] constexpr const SizeType& size() const noexcept { return _s; }

		///	@a Rectangle2D の左端のx座標の値を取得します。
		[[nodiscard]] constexpr ValueType left() const { if constexpr ((quad==Quadrants2D::UpLeft)||(quad==Quadrants2D::DownLeft)) { return (_o + _s).x(); } else { return _o.x(); } }
		///	@a Rectangle2D の右端のx座標の値を取得します。
		[[nodiscard]] constexpr ValueType right() const { if constexpr ((quad==Quadrants2D::UpRight)||(quad==Quadrants2D::DownRight)) { return (_o + _s).x(); } else { return _o.x(); } }
		///	@a Rectangle2D の上端のy座標の値を取得します。
		[[nodiscard]] constexpr ValueType top() const { if constexpr ((quad==Quadrants2D::UpRight)||(quad==Quadrants2D::UpLeft)) { return (_o + _s).y(); } else { return _o.y(); } }
		///	@a Rectangle2D の下端のy座標の値を取得します。
		[[nodiscard]] constexpr ValueType bottom() const { if constexpr ((quad==Quadrants2D::DownRight)||(quad==Quadrants2D::DownLeft)) { return (_o + _s).y(); } else { return _o.y(); } }
		///	@a Rectangle2D の示す矩形の幅を取得します。
		[[nodiscard]] constexpr ValueType width() const { return _s.width(); }
		///	@a Rectangle2D の示す矩形の高さを取得します。
		[[nodiscard]] constexpr ValueType height() const { return _s.height(); }
		///	水平軸コンポーネントの値の範囲を示す @a Range を取得します。
		[[nodiscard]] constexpr Range<ValueType> range_x() const { return Range<ValueType>(_o.x(), _o.x() + _s.width()); }
		///	垂直軸コンポーネントの値の範囲を示す @a Range を取得します。
		[[nodiscard]] constexpr Range<ValueType> range_y() const { return Range<ValueType>(_o.y(), _o.y() + _s.height()); }

		///	指定された点が @a Rectangle2D の領域に含まれるかをテストします。
		[[nodiscard]] constexpr bool contains(const PointType& point) const { return (_o.x() <= point.x())&&(_o.y() <= point.y())&&(point.x() <= (_o + _s).x())&&(point.y() <= (_o + _s).y()); }
		///	指定された @a Rectangle2D の領域すべてが @a Rectangle2D の領域に含まれるかをテストします。
		[[nodiscard]] constexpr bool contains(const Rectangle2D<T, quad>& rect) const { return (_o.x() <= rect._o.x())&&(_o.y() <= rect._o.y())&&(rect._s.width() <= _s.width())&&(rect._s.height() <= _s.height()); }

		///	@a Rectangle2D の位置を @a offset 分移動します。
		[[nodiscard]] constexpr Rectangle2D<T, quad> offset(const PointType& offset) const { return Rectangle2D<T, quad>(_o + offset, _s); }
		///	@a Rectangle2D の大きさを @a size 分拡げます。
		[[nodiscard]] constexpr Rectangle2D<T, quad> inflate(const SizeType& size) const { return Rectangle2D<T, quad>(_o, _s + size); }

		[[nodiscard]] constexpr bool Equals(const Rectangle2D<T, quad>& other) const { return (_o == other._o)&&(_s == other._s); }
		[[nodiscard]] constexpr bool operator==(const Rectangle2D<T, quad>& other) const { return Equals(other); }
		[[nodiscard]] constexpr bool operator!=(const Rectangle2D<T, quad>& other) const { return !Equals(other); }

		///	四辺の座標から @a Rectangle2D オブジェクトを作成します。
		///	@param	left
		///	矩形の左端に位置する辺のx座標。
		///	@param	right
		///	矩形の右端に位置する辺のx座標。
		///	@param	top
		///	矩形の上端に位置する辺のy座標。
		///	@param	bottom
		///	矩形の下端に位置する辺のy座標。
		[[nodiscard]] constexpr static Rectangle2D<T, quad> from_edge(const ValueType& left, const ValueType& right, const ValueType& top, const ValueType& bottom)
		{
			if constexpr (quad == Quadrants2D::UpRight) { return Rectangle2D<T, quad>(left, bottom, right - left, top - bottom); }
			if constexpr (quad == Quadrants2D::UpLeft) { return Rectangle2D<T, quad>(right, bottom, left - right, top - bottom); }
			if constexpr (quad == Quadrants2D::DownLeft) { return Rectangle2D<T, quad>(right, top, left - right, bottom - top); }
			if constexpr (quad == Quadrants2D::DownRight) { return Rectangle2D<T, quad>(left, top, right - left, bottom - top); }
		}
	private:
		template<class fromT, Quadrants2D fromquad, std::enable_if_t<std::is_constructible_v<T, fromT>, int> = 0>
		[[nodiscard]] constexpr static PointType convert_point(const Rectangle2D<fromT, fromquad>& from)
		{
			if constexpr (quad == Quadrants2D::UpRight) { return PointType(T(from.left()), T(from.bottom())); }
			if constexpr (quad == Quadrants2D::UpLeft) { return PointType(T(from.right()), T(from.bottom())); }
			if constexpr (quad == Quadrants2D::DownLeft) { return PointType(T(from.right()), T(from.top())); }
			if constexpr (quad == Quadrants2D::DownRight) { return PointType(T(from.left()), T(from.top())); }
		}
	};
	///	@a Point2D と @a Rect2DSize によって表される矩形範囲を表します。
	///	@note
	///	こちらは @a std::is_floting_point_v が @a true の場合の特殊化です。
	template<class T, Quadrants2D quad>
	struct Rectangle2D<T, quad, std::enable_if_t<std::is_floating_point_v<T>>> final
	{
		static_assert(Traits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
	public:
		typedef T ValueType;
		typedef Point2D<T, quad> PointType;
		typedef Rect2DSize<T> SizeType;
	private:
		PointType _o;
		SizeType _s;
	public:
		constexpr Rectangle2D() = default;
		constexpr Rectangle2D(const PointType& origin, const SizeType& size) : _o(origin), _s(size) {}
		constexpr Rectangle2D(const ValueType& originx, const ValueType& originy, const ValueType& width, const ValueType& height) : _o(originx, originy), _s(width, height) {}
		template<Quadrants2D fromquad>
		constexpr Rectangle2D(const Rectangle2D<T, fromquad>& from) : _o(from.origin()), _s(from.size()) {}
		template<class fromT, Quadrants2D fromquad, std::enable_if_t<std::is_convertible_v<fromT, T>, int> = 0>
		constexpr Rectangle2D(const Rectangle2D<fromT, fromquad>& from) : _o(from.origin()), _s(from.size()) {}
		template<class fromT, Quadrants2D fromquad, std::enable_if_t<std::conjunction_v<std::negation<std::is_convertible<fromT, T>>, std::is_constructible<T, fromT>>, int> = 0>
		constexpr explicit Rectangle2D(const Rectangle2D<fromT, fromquad>& from) : _o(from.origin()), _s(from.size()) {}
		constexpr Rectangle2D(const ZeroValue_t&) : _o(Zero), _s(Zero) {}

		///	@a Rectangle2D の原点を表す @a PointType を取得します。
		[[nodiscard]] constexpr const PointType& origin() const noexcept { return _o; }
		///	@a Rectangle2D の大きさを表す @a SizeType を取得します。
		[[nodiscard]] constexpr const SizeType& size() const noexcept { return _s; }

		///	@a Rectangle2D の左端のx座標の値を取得します。
		[[nodiscard]] constexpr ValueType left() const { if constexpr ((quad==Quadrants2D::UpLeft)||(quad==Quadrants2D::DownLeft)) { return (_o + _s).x(); } else { return _o.x(); } }
		///	@a Rectangle2D の右端のx座標の値を取得します。
		[[nodiscard]] constexpr ValueType right() const { if constexpr ((quad==Quadrants2D::UpRight)||(quad==Quadrants2D::DownRight)) { return (_o + _s).x(); } else { return _o.x(); } }
		///	@a Rectangle2D の上端のy座標の値を取得します。
		[[nodiscard]] constexpr ValueType top() const { if constexpr ((quad==Quadrants2D::UpRight)||(quad==Quadrants2D::UpLeft)) { return (_o + _s).y(); } else { return _o.y(); } }
		///	@a Rectangle2D の下端のy座標の値を取得します。
		[[nodiscard]] constexpr ValueType bottom() const { if constexpr ((quad==Quadrants2D::DownRight)||(quad==Quadrants2D::DownLeft)) { return (_o + _s).y(); } else { return _o.y(); } }
		///	@a Rectangle2D の示す矩形の幅を取得します。
		[[nodiscard]] constexpr ValueType width() const { return _s.width(); }
		///	@a Rectangle2D の示す矩形の高さを取得します。
		[[nodiscard]] constexpr ValueType height() const { return _s.height(); }
		///	水平軸コンポーネントの値の範囲を示す @a Range を取得します。
		[[nodiscard]] constexpr Range<ValueType> range_x() const { return Range<ValueType>(_o.x(), _o.x() + _s.width()); }
		///	垂直軸コンポーネントの値の範囲を示す @a Range を取得します。
		[[nodiscard]] constexpr Range<ValueType> range_y() const { return Range<ValueType>(_o.y(), _o.y() + _s.height()); }

		///	指定された点が @a Rectangle2D の領域に含まれるかをテストします。
		[[nodiscard]] constexpr bool contains(const PointType& point) const { return (_o.x() <= point.x())&&(_o.y() <= point.y())&&(point.x() <= (_o + _s).x())&&(point.y() <= (_o + _s).y()); }
		///	指定された @a Rectangle2D の領域すべてが @a Rectangle2D の領域に含まれるかをテストします。
		[[nodiscard]] constexpr bool contains(const Rectangle2D<T, quad>& rect) const { return (_o.x() <= rect._o.x())&&(_o.y() <= rect._o.y())&&(rect._s.width() <= _s.width())&&(rect._s.height() <= _s.height()); }

		///	@a Rectangle2D の位置を @a offset 分移動します。
		[[nodiscard]] constexpr Rectangle2D<T, quad> offset(const PointType& offset) const { return Rectangle2D<T, quad>(_o + offset, _s); }
		///	@a Rectangle2D の大きさを @a size 分拡げます。
		[[nodiscard]] constexpr Rectangle2D<T, quad> inflate(const SizeType& size) const { return Rectangle2D<T, quad>(_o, _s + size); }

		///	@a RectangleF を切り捨て方向に丸め、 @a Rectangle2D に変換します。
		[[nodiscard]] Rectangle2D<T, quad> Floor() const { return Rectangle2D<T, quad>(_o.floor(), _s.floor()); }
		///	@a RectangleF を切り上げ方向に丸め、 @a Rectangle2D に変換します。
		[[nodiscard]] Rectangle2D<T, quad> Ceiling() const { return Rectangle2D<T, quad>(_o.ceil(), _s.ceil()); }
		/// @a RectangleF を最も近い @a Rectangle2D に変換します。
		[[nodiscard]] Rectangle2D<T, quad> Round() const { return Rectangle2D<T, quad>(_o.round(), _s.round()); }

		[[nodiscard]] constexpr bool Equals(const Rectangle2D<T, quad>& other) const { return (_o == other._o)&&(_s == other._s); }
		[[nodiscard]] constexpr bool operator==(const Rectangle2D<T, quad>& other) const { return Equals(other); }
		[[nodiscard]] constexpr bool operator!=(const Rectangle2D<T, quad>& other) const { return !Equals(other); }

		///	四辺の座標から @a Rectangle2D オブジェクトを作成します。
		///	@param	left
		///	矩形の左端に位置する辺のx座標。
		///	@param	right
		///	矩形の右端に位置する辺のx座標。
		///	@param	top
		///	矩形の上端に位置する辺のy座標。
		///	@param	bottom
		///	矩形の下端に位置する辺のy座標。
		[[nodiscard]] constexpr static Rectangle2D<T, quad> from_edge(const ValueType& left, const ValueType& right, const ValueType& top, const ValueType& bottom)
		{
			if constexpr (quad == Quadrants2D::UpRight) { return Rectangle2D<T, quad>(left, bottom, right - left, top - bottom); }
			if constexpr (quad == Quadrants2D::UpLeft) { return Rectangle2D<T, quad>(right, bottom, left - right, top - bottom); }
			if constexpr (quad == Quadrants2D::DownLeft) { return Rectangle2D<T, quad>(right, top, left - right, bottom - top); }
			if constexpr (quad == Quadrants2D::DownRight) { return Rectangle2D<T, quad>(left, top, right - left, bottom - top); }
		}
	private:
		template<class fromT, Quadrants2D fromquad, std::enable_if_t<std::is_constructible_v<T, fromT>, int> = 0>
		[[nodiscard]] constexpr static PointType convert_point(const Rectangle2D<fromT, fromquad>& from)
		{
			if constexpr (quad == Quadrants2D::UpRight) { return PointType(T(from.left()), T(from.bottom())); }
			if constexpr (quad == Quadrants2D::UpLeft) { return PointType(T(from.right()), T(from.bottom())); }
			if constexpr (quad == Quadrants2D::DownLeft) { return PointType(T(from.right()), T(from.top())); }
			if constexpr (quad == Quadrants2D::DownRight) { return PointType(T(from.left()), T(from.top())); }
		}
	};

	extern template struct Rectangle2D<uint8_t, Quadrants2D::UpRight>;
	extern template struct Rectangle2D<uint8_t, Quadrants2D::UpLeft>;
	extern template struct Rectangle2D<uint8_t, Quadrants2D::DownLeft>;
	extern template struct Rectangle2D<uint8_t, Quadrants2D::DownRight>;
	extern template struct Rectangle2D<uint16_t, Quadrants2D::UpRight>;
	extern template struct Rectangle2D<uint16_t, Quadrants2D::UpLeft>;
	extern template struct Rectangle2D<uint16_t, Quadrants2D::DownLeft>;
	extern template struct Rectangle2D<uint16_t, Quadrants2D::DownRight>;
	extern template struct Rectangle2D<uint32_t, Quadrants2D::UpRight>;
	extern template struct Rectangle2D<uint32_t, Quadrants2D::UpLeft>;
	extern template struct Rectangle2D<uint32_t, Quadrants2D::DownLeft>;
	extern template struct Rectangle2D<uint32_t, Quadrants2D::DownRight>;
	extern template struct Rectangle2D<uint64_t, Quadrants2D::UpRight>;
	extern template struct Rectangle2D<uint64_t, Quadrants2D::UpLeft>;
	extern template struct Rectangle2D<uint64_t, Quadrants2D::DownLeft>;
	extern template struct Rectangle2D<uint64_t, Quadrants2D::DownRight>;
	extern template struct Rectangle2D<int8_t, Quadrants2D::UpRight>;
	extern template struct Rectangle2D<int8_t, Quadrants2D::UpLeft>;
	extern template struct Rectangle2D<int8_t, Quadrants2D::DownLeft>;
	extern template struct Rectangle2D<int8_t, Quadrants2D::DownRight>;
	extern template struct Rectangle2D<int16_t, Quadrants2D::UpRight>;
	extern template struct Rectangle2D<int16_t, Quadrants2D::UpLeft>;
	extern template struct Rectangle2D<int16_t, Quadrants2D::DownLeft>;
	extern template struct Rectangle2D<int16_t, Quadrants2D::DownRight>;
	extern template struct Rectangle2D<int32_t, Quadrants2D::UpRight>;
	extern template struct Rectangle2D<int32_t, Quadrants2D::UpLeft>;
	extern template struct Rectangle2D<int32_t, Quadrants2D::DownLeft>;
	extern template struct Rectangle2D<int32_t, Quadrants2D::DownRight>;
	extern template struct Rectangle2D<int64_t, Quadrants2D::UpRight>;
	extern template struct Rectangle2D<int64_t, Quadrants2D::UpLeft>;
	extern template struct Rectangle2D<int64_t, Quadrants2D::DownLeft>;
	extern template struct Rectangle2D<int64_t, Quadrants2D::DownRight>;
	extern template struct Rectangle2D<float, Quadrants2D::UpRight>;
	extern template struct Rectangle2D<float, Quadrants2D::UpLeft>;
	extern template struct Rectangle2D<float, Quadrants2D::DownLeft>;
	extern template struct Rectangle2D<float, Quadrants2D::DownRight>;
	extern template struct Rectangle2D<double, Quadrants2D::UpRight>;
	extern template struct Rectangle2D<double, Quadrants2D::UpLeft>;
	extern template struct Rectangle2D<double, Quadrants2D::DownLeft>;
	extern template struct Rectangle2D<double, Quadrants2D::DownRight>;

	///	幾何学的な座標軸上で表される @a Rectangle 。
	typedef Rectangle2D<int, Quadrants2D::UpRight> GeometricRectangle;
	///	幾何学的な座標軸上で表される @a RectangleF 。
	typedef Rectangle2D<float, Quadrants2D::UpRight> GeometricRectangleF;

}
#endif // __stationaryorbit_core_rectangle__