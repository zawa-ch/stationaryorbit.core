//	stationaryorbit/core/basicmath
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
#ifndef __stationaryorbit_core_basicmath__
#define __stationaryorbit_core_basicmath__
#include <cmath>
#include "notimplemented.hpp"
#include "fundamental.hpp"
#include "traits.hpp"
#include "algorithms.hpp"
namespace zawa_ch::StationaryOrbit
{
	class BasicMathematics
	{
	private:
		BasicMathematics() = delete;
		BasicMathematics(const BasicMathematics&) = delete;
		BasicMathematics(BasicMathematics&&) = delete;
		~BasicMathematics() = delete;

		template<class Tp, class R = decltype( std::sqrt(std::declval<const Tp&>()) )> struct StdSqrtResultImpl { typedef R type; };
		template<class Tp, class R = decltype( std::ceil(std::declval<const Tp&>()) )> struct StdCeilResultImpl { typedef R type; };
		template<class Tp, class R = decltype( std::floor(std::declval<const Tp&>()) )> struct StdFloorResultImpl { typedef R type; };
		template<class Tp, class R = decltype( std::trunc(std::declval<const Tp&>()) )> struct StdTruncResultImpl { typedef R type; };
		template<class Tp, class R = decltype( std::round(std::declval<const Tp&>()) )> struct StdRoundResultImpl { typedef R type; };
		template<class Tp, class R = decltype( std::declval<const Tp&>().Sqrt() )> struct SqrtResultImpl { typedef R type; };
		template<class Tp, class = void> struct IsStdSqrtCallableImpl : std::false_type {};
		template<class Tp> struct IsStdSqrtCallableImpl<Tp, std::void_t< typename StdSqrtResultImpl<Tp>::type >> : std::true_type {};
		template<class Tp, class = void> struct IsStdCeilCallableImpl : std::false_type {};
		template<class Tp> struct IsStdCeilCallableImpl<Tp, std::void_t< typename StdCeilResultImpl<Tp>::type >> : std::true_type {};
		template<class Tp, class = void> struct IsStdFloorCallableImpl : std::false_type {};
		template<class Tp> struct IsStdFloorCallableImpl<Tp, std::void_t< typename StdFloorResultImpl<Tp>::type >> : std::true_type {};
		template<class Tp, class = void> struct IsStdTruncCallableImpl : std::false_type {};
		template<class Tp> struct IsStdTruncCallableImpl<Tp, std::void_t< typename StdTruncResultImpl<Tp>::type >> : std::true_type {};
		template<class Tp, class = void> struct IsStdRoundCallableImpl : std::false_type {};
		template<class Tp> struct IsStdRoundCallableImpl<Tp, std::void_t< typename StdRoundResultImpl<Tp>::type >> : std::true_type {};
		template<class Tp, class = void> struct HasSqrtImpl : std::false_type {};
		template<class Tp> struct HasSqrtImpl<Tp, std::void_t< typename StdSqrtResultImpl<Tp>::type >> : std::true_type {};

		template<class Tp> static constexpr bool is_std_sqrt_callable = IsStdSqrtCallableImpl<Tp>::value;
		template<class Tp> static constexpr bool is_std_ceil_callable = IsStdCeilCallableImpl<Tp>::value;
		template<class Tp> static constexpr bool is_std_floor_callable = IsStdFloorCallableImpl<Tp>::value;
		template<class Tp> static constexpr bool is_std_trunc_callable = IsStdTruncCallableImpl<Tp>::value;
		template<class Tp> static constexpr bool is_std_round_callable = IsStdRoundCallableImpl<Tp>::value;
		template<class Tp> static constexpr bool has_sqrt = HasSqrtImpl<Tp>::value;
	public:
		template<class Tp>
		[[nodiscard]] static constexpr std::enable_if_t<Traits::IsNumericalType<Tp>, Tp> abstract(const Tp& value) noexcept
		{
			return ( value < Tp(0) )?(-value):(value);
		}
		template<class Tp, class = decltype( std::abs( std::declval<Tp&>() ))>
		[[nodiscard]] static constexpr Tp abstract(const Tp& value) noexcept { return std::abs(value); }

		///	この値の平方根を取得します。
		template<class Tp, std::enable_if_t<(!is_std_sqrt_callable<Tp>) && (!has_sqrt<Tp>), int> = 0>
		[[nodiscard]] static constexpr Tp square_root(const Tp& value) noexcept { return Algorithms::square_root<Tp>(value); }
		template<class Tp, std::enable_if_t<(is_std_sqrt_callable<Tp>), int> = 0>
		[[nodiscard]] static constexpr Tp square_root(const Tp& value) noexcept { return std::sqrt(value); }
		template<class Tp, std::enable_if_t<(!is_std_sqrt_callable<Tp>) && (has_sqrt<Tp>), int> = 0>
		[[nodiscard]] static constexpr decltype( std::declval<const Tp&>().Sqrt() ) square_root(const Tp& value) noexcept { return value.Sqrt(); }

		template<class Tp, std::enable_if_t<(Traits::IsIntegralType<Tp>), int> = 0>
		[[nodiscard]] static constexpr Tp ceil(const Tp& value) { return value; }
		template<class Tp, std::enable_if_t<!(Traits::IsIntegralType<Tp>) && (is_std_ceil_callable<Tp>), int> = 0>
		[[nodiscard]] static constexpr Tp ceil(const Tp& value) { return std::ceil(value); }

		template<class Tp, std::enable_if_t<(Traits::IsIntegralType<Tp>), int> = 0>
		[[nodiscard]] static constexpr Tp floor(const Tp& value) { return value; }
		template<class Tp, std::enable_if_t<!(Traits::IsIntegralType<Tp>) && (is_std_floor_callable<Tp>), int> = 0>
		[[nodiscard]] static constexpr Tp floor(const Tp& value) { return std::floor(value); }

		template<class Tp, std::enable_if_t<(Traits::IsIntegralType<Tp>), int> = 0>
		[[nodiscard]] static constexpr Tp truncate(const Tp& value) { return value; }
		template<class Tp, std::enable_if_t<!(Traits::IsIntegralType<Tp>) && (is_std_trunc_callable<Tp>), int> = 0>
		[[nodiscard]] static constexpr Tp truncate(const Tp& value) { return std::trunc(value); }

		template<class Tp, std::enable_if_t<(Traits::IsIntegralType<Tp>), int> = 0>
		[[nodiscard]] static constexpr Tp round(const Tp& value) { return value; }
		template<class Tp, std::enable_if_t<!(Traits::IsIntegralType<Tp>) && (is_std_round_callable<Tp>), int> = 0>
		[[nodiscard]] static constexpr Tp round(const Tp& value) { return std::round(value); }

		template<class Tp>
		[[nodiscard]] static constexpr std::enable_if_t<Traits::IsNumericalType<Tp>, Tp> mod(const Tp& left, const Tp& right)
		{
			// TODO: フォールバック実装の実装
			throw NotImplementedException();
		}
		template<class Tp, class = decltype( std::fmod( std::declval<Tp&>(), std::declval<Tp&>() ))>
		[[nodiscard]] static constexpr Tp mod(const Tp& value) noexcept { return std::fmod(value); }
	};
}
#endif // __stationaryorbit_core_basicmath__
