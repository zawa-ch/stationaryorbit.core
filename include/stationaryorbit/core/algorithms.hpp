//	stationaryorbit/core/algorithms
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
#ifndef __stationaryorbit__core_algorithms__
#define __stationaryorbit__core_algorithms__
#include <stdexcept>
#include "numericaltypetraits.hpp"
#include "divisionresult.hpp"
#include "range.hpp"
#include "multiplelong.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	@brief	このライブラリで使用するアルゴリズムを定義します
	///
	///	ライブラリで使用される基本的なアルゴリズムを実装します。
	///	このクラスのインスタンスを作成することはできません。また、継承することもできません。
	class Algorithms final
	{
		Algorithms() = delete;
		~Algorithms() = delete;
	public:
		///	@brief	整数の除算と乗算を同時に行います。
		///	@param	Tp
		///	演算を行う整数型。型要件:IntegralType を満たす型か、 bool のどちらかである必要があります。
		///	@param	numerator
		///	除算時の被除数。
		///	@param	denominator
		///	除算時の除数。
		///	@param	scale
		///	乗算時の乗数。
		///	@exception	std::invalid_argument	除数に0を指定された場合にスローされます。
		template<class Tp>
		[[nodiscard]] static constexpr DivisionResult<Tp> integral_fraction(const Tp& numerator, const Tp& denominator, const Tp& scale)
		{
			static_assert(std::is_same_v<Tp, bool> || IntegralTypeTraits::is_integraltype<Tp>, "テンプレート型 Tp は 型要件:IntegralType を満たす型またはboolである必要があります。");

			if constexpr (std::is_same_v<Tp, bool>)
			{
				if (denominator == false) { throw std::invalid_argument("分母に0を指定することはできません。"); }
				return { numerator&&scale, false };
			}
			if constexpr (IntegralTypeTraits::is_integraltype<Tp>)
			{
				if (denominator == Tp(0)) { throw std::invalid_argument("分母に0を指定することはできません。"); }
				if constexpr (!std::numeric_limits<Tp>::is_signed)
				{
					auto r = (MultipleULong<Tp, 2UL>(numerator) * scale).Divide(denominator);
					return { Tp(r.value), Tp(r.mod) };
				}
				else
				{
					bool s = (numerator < Tp(0)) ^ (denominator < Tp(0)) ^ (scale < Tp(0));
					auto r = integral_fraction<std::make_unsigned_t<Tp>>((numerator >= Tp(0))?numerator:-numerator, (denominator >= Tp(0))?denominator:-denominator, (scale >= Tp(0))?scale:-scale);
					return { Tp((s)?(-Tp(r.value)):(Tp(r.value))), Tp((s)?(-Tp(r.mod)):(Tp(r.mod))) };
				}
			}
		}

		///	@brief	bool のand結合を行います。
		///
		///	このメソッドはちょうど @a left&amp;right に等しい操作を行います。
		[[nodiscard]] static constexpr bool boolean_and(const bool& left, const bool& right) noexcept
		{
			return left & right;
		}

		///	@brief	bool のand結合を行います。
		///
		///	このメソッドは std::initializer_list&lt;bool&gt;&amp; 内のすべての値をand結合します。
		[[nodiscard]] static constexpr bool boolean_and(const std::initializer_list<bool>& list) noexcept
		{
			bool result = true;
			for(auto i: list)
			{
				result = boolean_and(result, i);
			}
			return result;
		}

		///	@brief	bool のor結合を行います。
		///
		///	このメソッドはちょうど @a left|right に等しい操作を行います。
		[[nodiscard]] static constexpr bool boolean_or(const bool& left, const bool& right) noexcept
		{
			return left | right;
		}

		///	@brief	bool のor結合を行います。
		///
		///	このメソッドは std::initializer_list&lt;bool&gt;&amp; 内のすべての値をor結合します。
		[[nodiscard]] static constexpr bool boolean_or(const std::initializer_list<bool>& list) noexcept
		{
			bool result = false;
			for(auto i: list)
			{
				result = boolean_or(result, i);
			}
			return result;
		}

		///	@brief	bool のxor結合を行います。
		///
		///	このメソッドはちょうど @a left^right に等しい操作を行います。
		[[nodiscard]] static constexpr bool boolean_xor(const bool& left, const bool& right) noexcept
		{
			return (left | right) & !(left & right);
		}

		///	@brief	bool のxor結合を行います。
		///
		///	このメソッドは std::initializer_list&lt;bool&gt;&amp; 内のすべての値をxor結合します。
		[[nodiscard]] static constexpr bool boolean_xor(const std::initializer_list<bool>& list) noexcept
		{
			bool result = false;
			for(auto i: list)
			{
				result = boolean_xor(result, i);
			}
			return result;
		}

		///	@brief	指定された数値の平方根を導出します。
		///
		///	このメソッドは std::sqrt(Tp) の constexpr な代替であるほか、 BasicMathematics::square_root(const Tp&) で有効な実装が存在しない場合のフォールバック実装としても用いられます。
		template<class Tp>
		[[nodiscard]] static constexpr Tp square_root(const Tp& value) noexcept
		{
			static_assert(NumericalTypeTraits::is_numericaltype<Tp>, "テンプレート型 Tp は数値型である必要があります。");
			auto result = value;
			auto b = value;
			auto c = Tp(0);
			do	// X[n+1] = (X[N] + a / X[N]) / 2
			{
				// 0除算の回避(sqrt(0) = 0)
				if (result == Tp(0)) { break; }
				// 前回値(X[N])保持
				b = result;
				// a / X[N] の導出
				auto delta = value / b;
				if constexpr (IntegralTypeTraits::is_integraltype<Tp>)
				{
					// X[N] / 2
					result /= Tp(2);
					// 剰余分の計算
					result += ((result % Tp(2)) + (delta % Tp(2))) / Tp(2);
					// (a / X[n]) / 2
					result += delta / Tp(2);
					if (((result < b)?(b-result):(result - b)) <= Tp(2)) { break; }
				}
				else
				{
					delta = (delta - b) / 2;
					delta -= c;
					result += delta;
					c = (result - b) - delta;
					if ((((0 <= delta)?(delta):(-delta)) <= (std::numeric_limits<Tp>::epsilon() * b))) { break; }
				}
			} while (true);
			return result;
		}

		///	@brief	半角公式によるsin(x/2)の導出を行います。
		///	@param	cos
		///	cos(x)の値。
		template<class T>
		[[nodiscard]] static constexpr T halfangle_sin(const T& cos) noexcept
		{
			return square_root((T(1) - cos) / 2);
		}

		///	@brief	半角公式によるcos(x/2)の導出を行います。
		///	@param	cos
		///	cos(x)の値。
		template<class T>
		[[nodiscard]] static constexpr T halfangle_cos(const T& cos) noexcept
		{
			return square_root((T(1) + cos) / 2);
		}

		///	@brief	半角公式によるtan(x/2)の導出を行います。
		///	@param	sin
		///	sin(x)の値。
		///	@param	cos
		///	cos(x)の値。
		template<class T>
		[[nodiscard]] static constexpr T halfangle_tan(const T& sin, const T& cos) noexcept
		{
			return sin / (1 + cos);
		}

		///	@brief	剰余の導出を行います。
		///	@param	Tp
		///	剰余を導出する値の型。型要件:NumericalType を満たす必要があります。
		template<typename Tp>
		class ModuloIterator
		{
			static_assert(NumericalTypeTraits::is_numericaltype<Tp>, "テンプレート引数型 Tp は、 型要件:NumericalType を満たす必要があります。");
			static_assert(std::numeric_limits<Tp>::radix > 0, "テンプレート引数型 Tp の基数が正しい値ではありません。");
		public:
			typedef Tp ValueType;
		private:
			size_t _p;
			Tp _cur;
			Tp _div;
			Tp _c;
			bool _s;
		public:
			constexpr ModuloIterator(const Tp& x, const Tp& div) : _p(Zero), _cur(abstract(x)), _div(abstract(div)), _c(Zero), _s(is_signed(x)) {}

			[[nodiscard]] constexpr bool has_value() const noexcept { return _div <= _cur; }
			[[nodiscard]] constexpr Tp current() const noexcept { return _s?(_c - _cur):(_cur - _c); }
			constexpr bool next()
			{
				if (_div <= _cur)
				{
					Tp d = _div;
					while (power(_div, _p + 1) <= _cur)
					{
						++_p;
						d = power(_div, _p);
					}
					auto b = _cur;
					_cur -= d - _c;
					_c = (_cur - b) + d;
				}
				return has_value();
			}
		private:
			[[nodiscard]] constexpr static bool is_signed(const Tp& x) noexcept { return x < Tp(Zero); }
			[[nodiscard]] constexpr static Tp abstract(const Tp& x) noexcept { return is_signed(x)?(-x):(x); }
			[[nodiscard]] constexpr static Tp power(const Tp& x, size_t n) noexcept
			{
				auto result = x;
				for(auto i: Range<size_t>(0, n).get_std_iterator()) { result *= std::numeric_limits<Tp>::radix; }
				return result;
			}
		};

		///	@brief	正弦関数の導出を行うためのイテレータです。
		///	@param	Tp
		///	正弦関数を導出する値の型。型要件:NumericalType を満たす必要があります。
		template<typename Tp>
		class SinProgressionSequenceIterator
		{
			static_assert(NumericalTypeTraits::is_numericaltype<Tp>, "テンプレート引数型 Tp は、 型要件:NumericalType を満たす必要があります。");
		public:
			typedef Tp ValueType;
		private:
			size_t _iteration;
			Tp _x;
			Tp _p;
			Tp _current;
		public:
			constexpr SinProgressionSequenceIterator(const Tp& x) : _iteration(0), _x(x), _p(x), _current() {}

			[[nodiscard]] constexpr bool has_value() const noexcept { return true; }
			[[nodiscard]] constexpr Tp current() const noexcept { return _current; }
			constexpr bool next()
			{
				_current = _p;
				++_iteration;
				_p *= _x / Tp(_iteration * 2);
				_p *= _x / Tp(_iteration * 2 + 1);
				_p *= Tp(-1);
				return has_value();
			}
		};

		///	@brief	余弦関数の導出を行うためのイテレータです。
		///	@param	Tp
		///	余弦関数を導出する値の型。型要件:NumericalType を満たす必要があります。
		template<typename Tp>
		class CosProgressionSequenceIterator
		{
			static_assert(NumericalTypeTraits::is_numericaltype<Tp>, "テンプレート引数型 Tp は、 型要件:NumericalType を満たす必要があります。");
		public:
			typedef Tp ValueType;
		private:
			size_t _iteration;
			Tp _x;
			Tp _p;
			Tp _current;
		public:
			constexpr CosProgressionSequenceIterator(const Tp& x) : _iteration(0), _x(x), _p(1), _current() {}

			[[nodiscard]] constexpr bool has_value() const noexcept { return true; }
			[[nodiscard]] constexpr Tp current() const noexcept { return _current; }
			constexpr bool next()
			{
				_current = _p;
				++_iteration;
				_p *= _x / Tp(_iteration * 2 - 1);
				_p *= _x / Tp(_iteration * 2);
				_p *= Tp(-1);
				return has_value();
			}
		};

		///	@brief	逆正接関数の導出を行うためのイテレータです。
		///	@param	Tp
		///	逆正接関数を導出する値の型。型要件:NumericalType を満たす必要があります。
		template<typename Tp>
		class ArctanProgressionSequenceIterator
		{
			static_assert(NumericalTypeTraits::is_numericaltype<Tp>, "テンプレート引数型 Tp は、 型要件:NumericalType を満たす必要があります。");
		public:
			typedef Tp ValueType;
		private:
			size_t _iteration;
			Tp _x;
			Tp _x2;
			Tp _p;
			Tp _current;
		public:
			constexpr ArctanProgressionSequenceIterator(const Tp& x) : _iteration(0), _x(x), _x2(x * x + 1), _p(1), _current() {}

			[[nodiscard]] constexpr bool has_value() const noexcept { return true; }
			[[nodiscard]] constexpr Tp current() const noexcept { return _current * _x / _x2; }
			constexpr bool next()
			{
				_current = _p;
				++_iteration;
				Tp pn = Tp(_iteration) * Tp(2);
				Tp pd = Tp(_iteration) * Tp(2) + Tp(1);
				_p *= pn / pd;
				_p *= _x * _x / _x2;
				return true;
			}
		};

		///	@brief	逆正弦関数の導出を行うためのイテレータです。
		///	@param	Tp
		///	逆正弦関数を導出する値の型。型要件:NumericalType を満たす必要があります。
		template<typename Tp>
		class ArcsinProgressionSequenceIterator
		{
			static_assert(NumericalTypeTraits::is_numericaltype<Tp>, "テンプレート引数型 Tp は、 型要件:NumericalType を満たす必要があります。");
		public:
			typedef Tp ValueType;
		private:
			size_t _iteration;
			Tp _x;
			Tp _p1;
			Tp _p2;
			Tp _p3;
			Tp _current;
		public:
			constexpr ArcsinProgressionSequenceIterator(const Tp& x) : _iteration(0), _x(x), _p1(1), _p2(x), _p3(1), _current() {}

			[[nodiscard]] constexpr bool has_value() const noexcept { return true; }
			[[nodiscard]] constexpr Tp current() const noexcept { return _current; }
			constexpr bool next()
			{
				_current = _p1 * _p2 / _p3;
				++_iteration;
				_p1 *= (Tp(_iteration) * Tp(2) - Tp(1)) / (Tp(_iteration) * Tp(2));
				_p2 *= _x * _x;
				_p3 += Tp(2);
				return true;
			}
		};
	};

	extern template DivisionResult<bool> Algorithms::integral_fraction<bool>(const bool& numerator, const bool& denominator, const bool& scale);
	extern template DivisionResult<uint8_t> Algorithms::integral_fraction<uint8_t>(const uint8_t& numerator, const uint8_t& denominator, const uint8_t& scale);
	extern template DivisionResult<uint16_t> Algorithms::integral_fraction<uint16_t>(const uint16_t& numerator, const uint16_t& denominator, const uint16_t& scale);
	extern template DivisionResult<uint32_t> Algorithms::integral_fraction<uint32_t>(const uint32_t& numerator, const uint32_t& denominator, const uint32_t& scale);
	extern template DivisionResult<uint64_t> Algorithms::integral_fraction<uint64_t>(const uint64_t& numerator, const uint64_t& denominator, const uint64_t& scale);
	extern template DivisionResult<int8_t> Algorithms::integral_fraction<int8_t>(const int8_t& numerator, const int8_t& denominator, const int8_t& scale);
	extern template DivisionResult<int16_t> Algorithms::integral_fraction<int16_t>(const int16_t& numerator, const int16_t& denominator, const int16_t& scale);
	extern template DivisionResult<int32_t> Algorithms::integral_fraction<int32_t>(const int32_t& numerator, const int32_t& denominator, const int32_t& scale);
	extern template DivisionResult<int64_t> Algorithms::integral_fraction<int64_t>(const int64_t& numerator, const int64_t& denominator, const int64_t& scale);
}
#endif // __stationaryorbit__core_algorithms__