//	stationaryorbit/core/arithmetic
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
#include "invalidoperation.hpp"
#include "numericaltraits.hpp"
#ifndef __stationaryorbit_core_arithmetic__
#define __stationaryorbit_core_arithmetic__
namespace zawa_ch::StationaryOrbit
{
	///	@brief	数値型による数値演算の拡張を行います
	///
	///	数値型(型要件:NumericalType を満たす型)の演算の拡張を行います。
	///	このクラスのインスタンスを作成することはできません。また、継承することもできません。
	class ArithmeticOperation
	{
	private:
		ArithmeticOperation() = delete;
		~ArithmeticOperation() = delete;
	public:
		///	@brief	加算を行った結果の状態を示すフラグ
		///
		///	加減算を行った結果がどのような状態になっているかを表すためのフラグです。
		enum class AdditionResultStatus
		{
			///	正しく加減算が行われたことを示す定数。
			no_error = 0,
			///	正方向のオーバーフローが発生したことを示す定数。
			overflow_positive = 1,
			///	負方向のオーバーフローが発生したことを示す定数。
			overflow_negative = -1
		};

		///	@brief	加算を行った結果を格納する構造体
		///
		///	加減算を行った結果を格納します。
		///	このクラスは継承できません。
		///	@param	Tp
		///	加減算を行う型。型要件:NumericalType を満たす必要があります。
		template<typename Tp, typename R = typename Traits::PromotionResult<Tp>>
		struct AdditionResult final
		{
			///	演算結果の内容
			R result;
			///	演算結果の状態
			AdditionResultStatus status;
		};

		///	@brief	乗算を行った結果の状態を示すフラグ
		///
		///	乗除算を行った結果がどのような状態になっているかを表すためのフラグです。
		enum class MultiplicationResultStatus
		{
			///	正しく乗除算が行われたことを示す定数。
			no_error = 0,
			///	オーバーフローが発生したことを示す定数。
			overflow = 1,
			///	0除算が行われたことを示す定数。
			divide_by_zero = -1
		};

		///	@brief	乗算を行った結果を格納する構造体
		///
		///	乗除算を行った結果を格納します。
		///	このクラスは継承できません。
		///	@param	Tp
		///	乗除算を行う型。型要件:NumericalType を満たす必要があります。
		template<typename T, typename Tp = typename Traits::PromotionResult<T>>
		struct MultiplicationResult final
		{
			///	演算結果の内容
			Tp result;
			///	演算結果の状態
			MultiplicationResultStatus status;
		};

		///	演算時のエラーをレポートする加算を行います。
		///
		///	加算を行い、その結果を演算時に検出したエラーとともに返します。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		template<typename T>
		static constexpr AdditionResult<T> add(const T& left, const T& right) noexcept
		{
			static_assert(NumericalTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
			static_assert(std::is_constructible_v<T, int>, "テンプレート引数型 T は (int) を引数に取るコンストラクタを持つ必要があります。");
			if constexpr (std::numeric_limits<T>::is_signed)
			{
				if (right < T(0))
				{
					auto eval = std::numeric_limits<T>::lowest() - right;
					if (left < eval) { return AdditionResult<T>{ left + right, AdditionResultStatus::overflow_negative }; }
				}
				else
				{
					auto eval = std::numeric_limits<T>::max() - right;
					if (eval < left) { return AdditionResult<T>{ left + right, AdditionResultStatus::overflow_positive }; }
				}
			}
			else
			{
				auto eval = std::numeric_limits<T>::max() - right;
				if (eval < left) { return AdditionResult<T>{ left + right, AdditionResultStatus::overflow_positive }; }
			}
			return AdditionResult<T>{ left + right, AdditionResultStatus::no_error };
		}

		///	演算時のエラーをレポートする減算を行います。
		///
		///	減算を行い、その結果を演算時に検出したエラーとともに返します。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		template<typename T>
		static constexpr AdditionResult<T> subtract(const T& left, const T& right) noexcept
		{
			static_assert(NumericalTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
			static_assert(std::is_constructible_v<T, int>, "テンプレート引数型 T は (int) を引数に取るコンストラクタを持つ必要があります。");
			if constexpr (std::numeric_limits<T>::is_signed)
			{
				if (right < T(0))
				{
					auto eval = std::numeric_limits<T>::max() + right;
					if (eval < left) { return AdditionResult<T>{ left - right, AdditionResultStatus::overflow_positive }; }
				}
				else
				{
					auto eval = std::numeric_limits<T>::lowest() + right;
					if (left < eval) { return AdditionResult<T>{ left - right, AdditionResultStatus::overflow_negative }; }
				}
			}
			else
			{
				auto eval = std::numeric_limits<T>::lowest() + right;
				if (left < eval) { return AdditionResult<T>{ left - right, AdditionResultStatus::overflow_negative }; }
			}
			return AdditionResult<T>{ left - right, AdditionResultStatus::no_error };
		}

		///	演算時のエラーをレポートする乗算を行います。
		///
		///	乗算を行い、その結果を演算時に検出したエラーとともに返します。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		template<typename T>
		static MultiplicationResult<T> multiply(const T& left, const T& right) noexcept
		{
			static_assert(NumericalTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
			static_assert(std::is_constructible_v<T, int>, "テンプレート引数型 T は (int) を引数に取るコンストラクタを持つ必要があります。");
			if constexpr (std::numeric_limits<T>::is_signed)
			{
				if ( ( (T(-1) < left)&&(left <= T(1)) )||( (T(-1) < right)&&(right <= T(1)) ) )
				{
					// 一方のオペランドの絶対値が1より小さい(あるいは1に等しい)場合、演算結果はオーバーフローすることはない
					return MultiplicationResult<T>{ left * right, MultiplicationResultStatus::no_error };
				}
				if (right == T(-1))
				{
					if constexpr (std::numeric_limits<T>::lowest() + std::numeric_limits<T>::max() != T(0))
					{
						if constexpr (std::numeric_limits<T>::lowest() + std::numeric_limits<T>::max() < T(0))
						{ return MultiplicationResult<T>{ left * right, (left < -std::numeric_limits<T>::max())?(MultiplicationResultStatus::overflow):(MultiplicationResultStatus::no_error) }; }
						else
						{ return MultiplicationResult<T>{ left * right, (-std::numeric_limits<T>::lowest() < left)?(MultiplicationResultStatus::overflow):(MultiplicationResultStatus::no_error) }; }
					}
					else
					{
						return MultiplicationResult<T>{ left * right, MultiplicationResultStatus::no_error };
					}
				}
			}
			else
			{
				if ( (left <= T(1))||(right <= T(1)) )
				{
					// 一方のオペランドが1より小さい(あるいは1に等しい)場合、演算結果はオーバーフローすることはない
					return MultiplicationResult<T>{ left * right, MultiplicationResultStatus::no_error };
				}
			}
			auto evalc = std::numeric_limits<T>::max() / right;
			auto evalf = std::numeric_limits<T>::lowest() / right;
			return MultiplicationResult<T>{ left * right, ((left < std::min(evalc, evalf))||(std::max(evalc, evalf) < left))?(MultiplicationResultStatus::overflow):(MultiplicationResultStatus::no_error) };
		}

		///	演算時のエラーをレポートする除算を行います。
		///
		///	除算を行い、その結果を演算時に検出したエラーとともに返します。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		template<typename T>
		static MultiplicationResult<T> divide(const T& left, const T& right) noexcept
		{
			static_assert(NumericalTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
			static_assert(std::is_constructible_v<T, int>, "テンプレート引数型 T は (int) を引数に取るコンストラクタを持つ必要があります。");
			if (right == T(0))
			{
				if constexpr (std::numeric_limits<T>::is_iec559) { return MultiplicationResult<T>{ left / right , MultiplicationResultStatus::divide_by_zero }; }
				else { return MultiplicationResult<T>{ T() , MultiplicationResultStatus::divide_by_zero }; }
			}
			if constexpr (std::numeric_limits<T>::is_signed)
			{
				if ((right < T(-1))||(T(1) <= right)) { return MultiplicationResult<T>{ left / right, MultiplicationResultStatus::no_error }; }
			}
			else
			{
				if (T(1) <= right) { return MultiplicationResult<T>{ left / right, MultiplicationResultStatus::no_error }; }
			}
			auto evalc = std::numeric_limits<T>::max() * right;
			auto evalf = std::numeric_limits<T>::lowest() * right;
			return MultiplicationResult<T>{ left / right, ((left < std::min(evalc, evalf))||(std::max(evalc, evalf) < left))?(MultiplicationResultStatus::overflow):(MultiplicationResultStatus::no_error) };
		}

		///	演算後の結果を値域内に丸める加算を行います。
		///
		///	加算を行い、その結果を値域内に丸めて返します。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		///	@exception	InvalidOperationException	演算結果のステータスが未定義の状態になった場合にスローされます。
		template<typename T>
		static constexpr T add_saturate(const T& left, const T& right)
		{
			static_assert(NumericalTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
			static_assert(std::is_constructible_v<T, int>, "テンプレート引数型 T は (int) を引数に取るコンストラクタを持つ必要があります。");
			auto result = add(left, right);
			switch(result.status)
			{
				case AdditionResultStatus::no_error: { return T(result.result); }
				case AdditionResultStatus::overflow_positive: { return std::numeric_limits<T>::max(); }
				case AdditionResultStatus::overflow_negative: { return std::numeric_limits<T>::lowest(); }
				default: { throw InvalidOperationException("計算結果の状態が定義されていない状態になりました。"); }
			}
		}

		///	演算後の結果を値域内に丸める減算を行います。
		///
		///	減算を行い、その結果を値域内に丸めて返します。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		///	@exception	InvalidOperationException	演算結果のステータスが未定義の状態になった場合にスローされます。
		template<typename T>
		static constexpr T subtract_saturate(const T& left, const T& right)
		{
			static_assert(NumericalTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
			static_assert(std::is_constructible_v<T, int>, "テンプレート引数型 T は (int) を引数に取るコンストラクタを持つ必要があります。");
			auto result = subtract(left, right);
			switch(result.status)
			{
				case AdditionResultStatus::no_error: { return T(result.result); }
				case AdditionResultStatus::overflow_positive: { return std::numeric_limits<T>::max(); }
				case AdditionResultStatus::overflow_negative: { return std::numeric_limits<T>::lowest(); }
				default: { throw InvalidOperationException("計算結果の状態が定義されていない状態になりました。"); }
			}
		}

		///	演算後の結果を値域内に丸める乗算を行います。
		///
		///	乗算を行い、その結果を値域内に丸めて返します。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		///	@exception	std::range_error	除数に0を指定した場合、NaNを丸めることはできないためにスローされます。
		///	@exception	InvalidOperationException	演算結果のステータスが未定義の状態になった場合にスローされます。
		template<typename T>
		static constexpr T multiply_saturate(const T& left, const T& right)
		{
			static_assert(NumericalTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
			static_assert(std::is_constructible_v<T, int>, "テンプレート引数型 T は (int) を引数に取るコンストラクタを持つ必要があります。");
			auto result = multiply(left, right);
			switch(result.status)
			{
				case MultiplicationResultStatus::no_error: { return T(result.result); }
				case MultiplicationResultStatus::overflow:
				{
					if constexpr (std::numeric_limits<T>::is_signed)
					{
						if ( ( (left < T(0))||(right < T(0)) ) && !( (left < T(0))&&(right < T(0)) ) ) { return std::numeric_limits<T>::lowest(); }
						else { return std::numeric_limits<T>::max(); }
					}
					else { return std::numeric_limits<T>::max(); }
				}
				case MultiplicationResultStatus::divide_by_zero: { throw std::range_error("除数に0が指定されました。丸め先が定義されないため、丸めを行うことができません。"); }
				default: { throw InvalidOperationException("計算結果の状態が定義されていない状態になりました。"); }
			}
		}

		///	演算後の結果を値域内に丸める除算を行います。
		///
		///	除算を行い、その結果を値域内に丸めて返します。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		///	@exception	std::range_error	除数に0を指定した場合、NaNを丸めることはできないためにスローされます。
		///	@exception	InvalidOperationException	演算結果のステータスが未定義の状態になった場合にスローされます。
		template<typename T>
		static constexpr T divide_saturate(const T& left, const T& right)
		{
			static_assert(NumericalTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
			static_assert(std::is_constructible_v<T, int>, "テンプレート引数型 T は (int) を引数に取るコンストラクタを持つ必要があります。");
			auto result = divide(left, right);
			switch(result.status)
			{
				case MultiplicationResultStatus::no_error: { return T(result.result); }
				case MultiplicationResultStatus::overflow:
				{
					if constexpr (std::numeric_limits<T>::is_signed)
					{
						if ( ( (left < T(0))||(right < T(0)) ) && !( (left < T(0))&&(right < T(0)) ) ) { return std::numeric_limits<T>::lowest(); }
						else { return std::numeric_limits<T>::max(); }
					}
					else { return std::numeric_limits<T>::max(); }
				}
				case MultiplicationResultStatus::divide_by_zero: { throw std::range_error("除数に0が指定されました。丸め先が定義されないため、丸めを行うことができません。"); }
				default: { throw InvalidOperationException("計算結果の状態が定義されていない状態になりました。"); }
			}
		}

		///	演算結果が値域に収まらない場合に例外をスローする加算を行います。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		///	@exception	std::range_error	演算時に演算結果が値域に収まらないことを検出した場合にスローされます。
		///	@exception	InvalidOperationException	演算結果のステータスが未定義の状態になった場合にスローされます。
		template<typename T>
		static constexpr T add_checked(const T& left, const T& right)
		{
			static_assert(NumericalTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
			static_assert(std::is_constructible_v<T, int>, "テンプレート引数型 T は (int) を引数に取るコンストラクタを持つ必要があります。");
			auto result = add(left, right);
			switch(result.status)
			{
				case AdditionResultStatus::no_error: { return T(result.result); }
				case AdditionResultStatus::overflow_positive:
				case AdditionResultStatus::overflow_negative:
				{ throw std::range_error("計算結果がこの型で表せる値域を超えています。"); }
				default: { throw InvalidOperationException("計算結果の状態が定義されていない状態になりました。"); }
			}
		}

		///	演算結果が値域に収まらない場合に例外をスローする減算を行います。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		///	@exception	std::range_error	演算時に演算結果が値域に収まらないことを検出した場合にスローされます。
		///	@exception	InvalidOperationException	演算結果のステータスが未定義の状態になった場合にスローされます。
		template<typename T>
		static constexpr T subtract_checked(const T& left, const T& right)
		{
			static_assert(NumericalTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
			static_assert(std::is_constructible_v<T, int>, "テンプレート引数型 T は (int) を引数に取るコンストラクタを持つ必要があります。");
			auto result = subtract(left, right);
			switch(result.status)
			{
				case AdditionResultStatus::no_error: { return T(result.result); }
				case AdditionResultStatus::overflow_positive:
				case AdditionResultStatus::overflow_negative:
				{ throw std::range_error("計算結果がこの型で表せる値域を超えています。"); }
				default: { throw InvalidOperationException("計算結果の状態が定義されていない状態になりました。"); }
			}
		}

		///	演算結果が値域に収まらない場合に例外をスローする乗算を行います。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		///	@exception	std::range_error	演算時に演算結果が値域に収まらないことを検出した場合にスローされます。
		///	@exception	InvalidOperationException	演算結果のステータスが未定義の状態になった場合にスローされます。
		template<typename T>
		static constexpr T multiply_checked(const T& left, const T& right)
		{
			static_assert(NumericalTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
			static_assert(std::is_constructible_v<T, int>, "テンプレート引数型 T は (int) を引数に取るコンストラクタを持つ必要があります。");
			auto result = multiply(left, right);
			switch(result.status)
			{
				case MultiplicationResultStatus::no_error: { return T(result.result); }
				case MultiplicationResultStatus::overflow:
				case MultiplicationResultStatus::divide_by_zero:
				{ throw std::range_error("計算結果がこの型で表せる値域を超えています。"); }
				default: { throw InvalidOperationException("計算結果の状態が定義されていない状態になりました。"); }
			}
		}

		///	演算結果が値域に収まらない場合に例外をスローする除算を行います。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		///	@exception	std::range_error	演算時に演算結果が値域に収まらないことを検出した場合にスローされます。
		///	@exception	InvalidOperationException	演算結果のステータスが未定義の状態になった場合にスローされます。
		template<typename T>
		static constexpr T divide_checked(const T& left, const T& right)
		{
			static_assert(NumericalTraits::IsNumericalType<T>, "テンプレート引数型 T は数値型である必要があります。");
			static_assert(std::is_constructible_v<T, int>, "テンプレート引数型 T は (int) を引数に取るコンストラクタを持つ必要があります。");
			auto result = divide(left, right);
			switch(result.status)
			{
				case MultiplicationResultStatus::no_error: { return T(result.result); }
				case MultiplicationResultStatus::overflow:
				case MultiplicationResultStatus::divide_by_zero:
				{ throw std::range_error("計算結果がこの型で表せる値域を超えています。"); }
				default: { throw InvalidOperationException("計算結果の状態が定義されていない状態になりました。"); }
			}
		}

		///	加算の演算結果が値域外となるかを取得します。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		template<class Tp>
		static constexpr bool may_overflow_addition(const Tp& left, const Tp& right) noexcept
		{
			static_assert(NumericalTraits::IsNumericalType<Tp>, "テンプレート引数型 Tp は数値型である必要があります。");
			static_assert(std::is_constructible_v<Tp, int>, "テンプレート引数型 Tp は (int) を引数に取るコンストラクタを持つ必要があります。");
			if constexpr (std::numeric_limits<Tp>::is_signed)
			{
				if (right < Tp(0))
				{
					auto eval = std::numeric_limits<Tp>::lowest() - right;
					if (left < eval)
					{
						return true;
					}
				}
				else
				{
					auto eval = std::numeric_limits<Tp>::max() - right;
					if (eval < left)
					{
						return true;
					}
				}
			}
			else
			{
				auto eval = std::numeric_limits<Tp>::max() - right;
				if (eval < left)
				{
					return true;
				}
			}
			return false;
		}

		///	減算の演算結果が値域外となるかを取得します。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		template<class Tp>
		static constexpr bool may_overflow_subtraction(const Tp& left, const Tp& right) noexcept
		{
			static_assert(NumericalTraits::IsNumericalType<Tp>, "テンプレート引数型 Tp は数値型である必要があります。");
			static_assert(std::is_constructible_v<Tp, int>, "テンプレート引数型 Tp は (int) を引数に取るコンストラクタを持つ必要があります。");
			if constexpr (std::numeric_limits<Tp>::is_signed)
			{
				if (right < Tp(0))
				{
					auto eval = std::numeric_limits<Tp>::max() + right;
					if (eval < left)
					{
						return true;
					}
				}
				else
				{
					auto eval = std::numeric_limits<Tp>::lowest() + right;
					if (left < eval)
					{
						return true;
					}
				}
			}
			else
			{
				auto eval = std::numeric_limits<Tp>::lowest() + right;
				if (left < eval)
				{
					return true;
				}
			}
			return false;
		}

		///	乗算の演算結果が値域外となるかを取得します。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		template<class Tp>
		static constexpr bool may_overflow_multiplication(const Tp& left, const Tp& right) noexcept
		{
			static_assert(NumericalTraits::IsNumericalType<Tp>, "テンプレート引数型 Tp は数値型である必要があります。");
			static_assert(std::is_constructible_v<Tp, int>, "テンプレート引数型 Tp は (int) を引数に取るコンストラクタを持つ必要があります。");
			if constexpr (std::numeric_limits<Tp>::is_signed)
			{
				if ( ( (Tp(-1) < left)&&(left <= Tp(1)) )||( (Tp(-1) < right)&&(right <= Tp(1)) ) )
				{
					// 一方のオペランドの絶対値が1より小さい(あるいは1に等しい)場合、演算結果はオーバーフローすることはない
					return false;
				}
				if (right == Tp(-1))
				{
					if constexpr (std::numeric_limits<Tp>::lowest() + std::numeric_limits<Tp>::max() != Tp(0))
					{
						if constexpr (std::numeric_limits<Tp>::lowest() + std::numeric_limits<Tp>::max() < Tp(0))
						{ return left < -std::numeric_limits<Tp>::max(); }
						else
						{ return -std::numeric_limits<Tp>::lowest() < left; }
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				if ( (left <= Tp(1))||(right <= Tp(1)) )
				{
					// 一方のオペランドが1より小さい(あるいは1に等しい)場合、演算結果はオーバーフローすることはない
					return false;
				}
			}
			auto evalc = std::numeric_limits<Tp>::max() / right;
			auto evalf = std::numeric_limits<Tp>::lowest() / right;
			return (left < std::min(evalc, evalf))||(std::max(evalc, evalf) < left);
		}

		///	除算の演算結果が値域外となるかを取得します。
		///	@param	left	演算子の左辺に代入される値。
		///	@param	right	演算子の右辺に代入される値。
		template<class Tp>
		static constexpr bool may_overflow_division(const Tp& left, const Tp& right) noexcept
		{
			static_assert(NumericalTraits::IsNumericalType<Tp>, "テンプレート引数型 Tp は数値型である必要があります。");
			static_assert(std::is_constructible_v<Tp, int>, "テンプレート引数型 Tp は (int) を引数に取るコンストラクタを持つ必要があります。");
			if (right == Tp(0))
			{
				return true;
			}
			if constexpr (std::numeric_limits<Tp>::is_signed)
			{
				if ((right < Tp(-1))||(Tp(1) <= right)) { return false; }
			}
			else
			{
				if (Tp(1) <= right) { return false; }
			}
			auto evalc = std::numeric_limits<Tp>::max() * right;
			auto evalf = std::numeric_limits<Tp>::lowest() * right;
			return (left < std::min(evalc, evalf))||(std::max(evalc, evalf) < left);
		}
	};

	template<class CharT>
	std::basic_ostream<CharT>& operator<<(std::basic_ostream<CharT>& stream, ArithmeticOperation::AdditionResultStatus value)
	{
		switch(value)
		{
			case ArithmeticOperation::AdditionResultStatus::no_error: { return stream << "no_error"; }
			case ArithmeticOperation::AdditionResultStatus::overflow_positive: { return stream << "overflow_positive"; }
			case ArithmeticOperation::AdditionResultStatus::overflow_negative: { return stream << "overflow_negative"; }
			default: { return stream << "<undefined>"; }
		}
	}
	template<class CharT>
	std::basic_ostream<CharT>& operator<<(std::basic_ostream<CharT>& stream, ArithmeticOperation::MultiplicationResultStatus value)
	{
		switch(value)
		{
			case ArithmeticOperation::MultiplicationResultStatus::no_error: { return stream << "no_error"; }
			case ArithmeticOperation::MultiplicationResultStatus::overflow: { return stream << "overflow"; }
			case ArithmeticOperation::MultiplicationResultStatus::divide_by_zero: { return stream << "divide_by_zero"; }
			default: { return stream << "<undefined>"; }
		}
	}

	extern template ArithmeticOperation::AdditionResult<bool> ArithmeticOperation::add<bool>(const bool&, const bool&);
	extern template ArithmeticOperation::AdditionResult<char> ArithmeticOperation::add<char>(const char&, const char&);
	extern template ArithmeticOperation::AdditionResult<signed char> ArithmeticOperation::add<signed char>(const signed char&, const signed char&);
	extern template ArithmeticOperation::AdditionResult<unsigned char> ArithmeticOperation::add<unsigned char>(const unsigned char&, const unsigned char&);
	extern template ArithmeticOperation::AdditionResult<wchar_t> ArithmeticOperation::add<wchar_t>(const wchar_t&, const wchar_t&);
	extern template ArithmeticOperation::AdditionResult<short> ArithmeticOperation::add<short>(const short&, const short&);
	extern template ArithmeticOperation::AdditionResult<unsigned short> ArithmeticOperation::add<unsigned short>(const unsigned short&, const unsigned short&);
	extern template ArithmeticOperation::AdditionResult<int> ArithmeticOperation::add<int>(const int&, const int&);
	extern template ArithmeticOperation::AdditionResult<unsigned int> ArithmeticOperation::add<unsigned int>(const unsigned int&, const unsigned int&);
	extern template ArithmeticOperation::AdditionResult<long> ArithmeticOperation::add<long>(const long&, const long&);
	extern template ArithmeticOperation::AdditionResult<unsigned long> ArithmeticOperation::add<unsigned long>(const unsigned long&, const unsigned long&);
	extern template ArithmeticOperation::AdditionResult<long long> ArithmeticOperation::add<long long>(const long long&, const long long&);
	extern template ArithmeticOperation::AdditionResult<unsigned long long> ArithmeticOperation::add<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template ArithmeticOperation::AdditionResult<float> ArithmeticOperation::add<float>(const float&, const float&);
	extern template ArithmeticOperation::AdditionResult<double> ArithmeticOperation::add<double>(const double&, const double&);
	extern template ArithmeticOperation::AdditionResult<long double> ArithmeticOperation::add<long double>(const long double&, const long double&);
	extern template ArithmeticOperation::AdditionResult<char16_t> ArithmeticOperation::add<char16_t>(const char16_t&, const char16_t&);
	extern template ArithmeticOperation::AdditionResult<char32_t> ArithmeticOperation::add<char32_t>(const char32_t&, const char32_t&);
	extern template ArithmeticOperation::AdditionResult<bool> ArithmeticOperation::subtract<bool>(const bool&, const bool&);
	extern template ArithmeticOperation::AdditionResult<char> ArithmeticOperation::subtract<char>(const char&, const char&);
	extern template ArithmeticOperation::AdditionResult<signed char> ArithmeticOperation::subtract<signed char>(const signed char&, const signed char&);
	extern template ArithmeticOperation::AdditionResult<unsigned char> ArithmeticOperation::subtract<unsigned char>(const unsigned char&, const unsigned char&);
	extern template ArithmeticOperation::AdditionResult<wchar_t> ArithmeticOperation::subtract<wchar_t>(const wchar_t&, const wchar_t&);
	extern template ArithmeticOperation::AdditionResult<short> ArithmeticOperation::subtract<short>(const short&, const short&);
	extern template ArithmeticOperation::AdditionResult<unsigned short> ArithmeticOperation::subtract<unsigned short>(const unsigned short&, const unsigned short&);
	extern template ArithmeticOperation::AdditionResult<int> ArithmeticOperation::subtract<int>(const int&, const int&);
	extern template ArithmeticOperation::AdditionResult<unsigned int> ArithmeticOperation::subtract<unsigned int>(const unsigned int&, const unsigned int&);
	extern template ArithmeticOperation::AdditionResult<long> ArithmeticOperation::subtract<long>(const long&, const long&);
	extern template ArithmeticOperation::AdditionResult<unsigned long> ArithmeticOperation::subtract<unsigned long>(const unsigned long&, const unsigned long&);
	extern template ArithmeticOperation::AdditionResult<long long> ArithmeticOperation::subtract<long long>(const long long&, const long long&);
	extern template ArithmeticOperation::AdditionResult<unsigned long long> ArithmeticOperation::subtract<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template ArithmeticOperation::AdditionResult<float> ArithmeticOperation::subtract<float>(const float&, const float&);
	extern template ArithmeticOperation::AdditionResult<double> ArithmeticOperation::subtract<double>(const double&, const double&);
	extern template ArithmeticOperation::AdditionResult<long double> ArithmeticOperation::subtract<long double>(const long double&, const long double&);
	extern template ArithmeticOperation::AdditionResult<char16_t> ArithmeticOperation::subtract<char16_t>(const char16_t&, const char16_t&);
	extern template ArithmeticOperation::AdditionResult<char32_t> ArithmeticOperation::subtract<char32_t>(const char32_t&, const char32_t&);
	extern template ArithmeticOperation::MultiplicationResult<bool> ArithmeticOperation::multiply<bool>(const bool&, const bool&);
	extern template ArithmeticOperation::MultiplicationResult<char> ArithmeticOperation::multiply<char>(const char&, const char&);
	extern template ArithmeticOperation::MultiplicationResult<signed char> ArithmeticOperation::multiply<signed char>(const signed char&, const signed char&);
	extern template ArithmeticOperation::MultiplicationResult<unsigned char> ArithmeticOperation::multiply<unsigned char>(const unsigned char&, const unsigned char&);
	extern template ArithmeticOperation::MultiplicationResult<wchar_t> ArithmeticOperation::multiply<wchar_t>(const wchar_t&, const wchar_t&);
	extern template ArithmeticOperation::MultiplicationResult<short> ArithmeticOperation::multiply<short>(const short&, const short&);
	extern template ArithmeticOperation::MultiplicationResult<unsigned short> ArithmeticOperation::multiply<unsigned short>(const unsigned short&, const unsigned short&);
	extern template ArithmeticOperation::MultiplicationResult<int> ArithmeticOperation::multiply<int>(const int&, const int&);
	extern template ArithmeticOperation::MultiplicationResult<unsigned int> ArithmeticOperation::multiply<unsigned int>(const unsigned int&, const unsigned int&);
	extern template ArithmeticOperation::MultiplicationResult<long> ArithmeticOperation::multiply<long>(const long&, const long&);
	extern template ArithmeticOperation::MultiplicationResult<unsigned long> ArithmeticOperation::multiply<unsigned long>(const unsigned long&, const unsigned long&);
	extern template ArithmeticOperation::MultiplicationResult<long long> ArithmeticOperation::multiply<long long>(const long long&, const long long&);
	extern template ArithmeticOperation::MultiplicationResult<unsigned long long> ArithmeticOperation::multiply<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template ArithmeticOperation::MultiplicationResult<float> ArithmeticOperation::multiply<float>(const float&, const float&);
	extern template ArithmeticOperation::MultiplicationResult<double> ArithmeticOperation::multiply<double>(const double&, const double&);
	extern template ArithmeticOperation::MultiplicationResult<long double> ArithmeticOperation::multiply<long double>(const long double&, const long double&);
	extern template ArithmeticOperation::MultiplicationResult<char16_t> ArithmeticOperation::multiply<char16_t>(const char16_t&, const char16_t&);
	extern template ArithmeticOperation::MultiplicationResult<char32_t> ArithmeticOperation::multiply<char32_t>(const char32_t&, const char32_t&);
	extern template ArithmeticOperation::MultiplicationResult<bool> ArithmeticOperation::divide<bool>(const bool&, const bool&);
	extern template ArithmeticOperation::MultiplicationResult<char> ArithmeticOperation::divide<char>(const char&, const char&);
	extern template ArithmeticOperation::MultiplicationResult<signed char> ArithmeticOperation::divide<signed char>(const signed char&, const signed char&);
	extern template ArithmeticOperation::MultiplicationResult<unsigned char> ArithmeticOperation::divide<unsigned char>(const unsigned char&, const unsigned char&);
	extern template ArithmeticOperation::MultiplicationResult<wchar_t> ArithmeticOperation::divide<wchar_t>(const wchar_t&, const wchar_t&);
	extern template ArithmeticOperation::MultiplicationResult<short> ArithmeticOperation::divide<short>(const short&, const short&);
	extern template ArithmeticOperation::MultiplicationResult<unsigned short> ArithmeticOperation::divide<unsigned short>(const unsigned short&, const unsigned short&);
	extern template ArithmeticOperation::MultiplicationResult<int> ArithmeticOperation::divide<int>(const int&, const int&);
	extern template ArithmeticOperation::MultiplicationResult<unsigned int> ArithmeticOperation::divide<unsigned int>(const unsigned int&, const unsigned int&);
	extern template ArithmeticOperation::MultiplicationResult<long> ArithmeticOperation::divide<long>(const long&, const long&);
	extern template ArithmeticOperation::MultiplicationResult<unsigned long> ArithmeticOperation::divide<unsigned long>(const unsigned long&, const unsigned long&);
	extern template ArithmeticOperation::MultiplicationResult<long long> ArithmeticOperation::divide<long long>(const long long&, const long long&);
	extern template ArithmeticOperation::MultiplicationResult<unsigned long long> ArithmeticOperation::divide<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template ArithmeticOperation::MultiplicationResult<float> ArithmeticOperation::divide<float>(const float&, const float&);
	extern template ArithmeticOperation::MultiplicationResult<double> ArithmeticOperation::divide<double>(const double&, const double&);
	extern template ArithmeticOperation::MultiplicationResult<long double> ArithmeticOperation::divide<long double>(const long double&, const long double&);
	extern template ArithmeticOperation::MultiplicationResult<char16_t> ArithmeticOperation::divide<char16_t>(const char16_t&, const char16_t&);
	extern template ArithmeticOperation::MultiplicationResult<char32_t> ArithmeticOperation::divide<char32_t>(const char32_t&, const char32_t&);
	extern template bool ArithmeticOperation::add_saturate<bool>(const bool&, const bool&);
	extern template char ArithmeticOperation::add_saturate<char>(const char&, const char&);
	extern template signed char ArithmeticOperation::add_saturate<signed char>(const signed char&, const signed char&);
	extern template unsigned char ArithmeticOperation::add_saturate<unsigned char>(const unsigned char&, const unsigned char&);
	extern template wchar_t ArithmeticOperation::add_saturate<wchar_t>(const wchar_t&, const wchar_t&);
	extern template short ArithmeticOperation::add_saturate<short>(const short&, const short&);
	extern template unsigned short ArithmeticOperation::add_saturate<unsigned short>(const unsigned short&, const unsigned short&);
	extern template int ArithmeticOperation::add_saturate<int>(const int&, const int&);
	extern template unsigned int ArithmeticOperation::add_saturate<unsigned int>(const unsigned int&, const unsigned int&);
	extern template long ArithmeticOperation::add_saturate<long>(const long&, const long&);
	extern template unsigned long ArithmeticOperation::add_saturate<unsigned long>(const unsigned long&, const unsigned long&);
	extern template long long ArithmeticOperation::add_saturate<long long>(const long long&, const long long&);
	extern template unsigned long long ArithmeticOperation::add_saturate<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template float ArithmeticOperation::add_saturate<float>(const float&, const float&);
	extern template double ArithmeticOperation::add_saturate<double>(const double&, const double&);
	extern template long double ArithmeticOperation::add_saturate<long double>(const long double&, const long double&);
	extern template char16_t ArithmeticOperation::add_saturate<char16_t>(const char16_t&, const char16_t&);
	extern template char32_t ArithmeticOperation::add_saturate<char32_t>(const char32_t&, const char32_t&);
	extern template bool ArithmeticOperation::subtract_saturate<bool>(const bool&, const bool&);
	extern template char ArithmeticOperation::subtract_saturate<char>(const char&, const char&);
	extern template signed char ArithmeticOperation::subtract_saturate<signed char>(const signed char&, const signed char&);
	extern template unsigned char ArithmeticOperation::subtract_saturate<unsigned char>(const unsigned char&, const unsigned char&);
	extern template wchar_t ArithmeticOperation::subtract_saturate<wchar_t>(const wchar_t&, const wchar_t&);
	extern template short ArithmeticOperation::subtract_saturate<short>(const short&, const short&);
	extern template unsigned short ArithmeticOperation::subtract_saturate<unsigned short>(const unsigned short&, const unsigned short&);
	extern template int ArithmeticOperation::subtract_saturate<int>(const int&, const int&);
	extern template unsigned int ArithmeticOperation::subtract_saturate<unsigned int>(const unsigned int&, const unsigned int&);
	extern template long ArithmeticOperation::subtract_saturate<long>(const long&, const long&);
	extern template unsigned long ArithmeticOperation::subtract_saturate<unsigned long>(const unsigned long&, const unsigned long&);
	extern template long long ArithmeticOperation::subtract_saturate<long long>(const long long&, const long long&);
	extern template unsigned long long ArithmeticOperation::subtract_saturate<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template float ArithmeticOperation::subtract_saturate<float>(const float&, const float&);
	extern template double ArithmeticOperation::subtract_saturate<double>(const double&, const double&);
	extern template long double ArithmeticOperation::subtract_saturate<long double>(const long double&, const long double&);
	extern template char16_t ArithmeticOperation::subtract_saturate<char16_t>(const char16_t&, const char16_t&);
	extern template char32_t ArithmeticOperation::subtract_saturate<char32_t>(const char32_t&, const char32_t&);
	extern template bool ArithmeticOperation::multiply_saturate<bool>(const bool&, const bool&);
	extern template char ArithmeticOperation::multiply_saturate<char>(const char&, const char&);
	extern template signed char ArithmeticOperation::multiply_saturate<signed char>(const signed char&, const signed char&);
	extern template unsigned char ArithmeticOperation::multiply_saturate<unsigned char>(const unsigned char&, const unsigned char&);
	extern template wchar_t ArithmeticOperation::multiply_saturate<wchar_t>(const wchar_t&, const wchar_t&);
	extern template short ArithmeticOperation::multiply_saturate<short>(const short&, const short&);
	extern template unsigned short ArithmeticOperation::multiply_saturate<unsigned short>(const unsigned short&, const unsigned short&);
	extern template int ArithmeticOperation::multiply_saturate<int>(const int&, const int&);
	extern template unsigned int ArithmeticOperation::multiply_saturate<unsigned int>(const unsigned int&, const unsigned int&);
	extern template long ArithmeticOperation::multiply_saturate<long>(const long&, const long&);
	extern template unsigned long ArithmeticOperation::multiply_saturate<unsigned long>(const unsigned long&, const unsigned long&);
	extern template long long ArithmeticOperation::multiply_saturate<long long>(const long long&, const long long&);
	extern template unsigned long long ArithmeticOperation::multiply_saturate<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template float ArithmeticOperation::multiply_saturate<float>(const float&, const float&);
	extern template double ArithmeticOperation::multiply_saturate<double>(const double&, const double&);
	extern template long double ArithmeticOperation::multiply_saturate<long double>(const long double&, const long double&);
	extern template char16_t ArithmeticOperation::multiply_saturate<char16_t>(const char16_t&, const char16_t&);
	extern template char32_t ArithmeticOperation::multiply_saturate<char32_t>(const char32_t&, const char32_t&);
	extern template bool ArithmeticOperation::divide_saturate<bool>(const bool&, const bool&);
	extern template char ArithmeticOperation::divide_saturate<char>(const char&, const char&);
	extern template signed char ArithmeticOperation::divide_saturate<signed char>(const signed char&, const signed char&);
	extern template unsigned char ArithmeticOperation::divide_saturate<unsigned char>(const unsigned char&, const unsigned char&);
	extern template wchar_t ArithmeticOperation::divide_saturate<wchar_t>(const wchar_t&, const wchar_t&);
	extern template short ArithmeticOperation::divide_saturate<short>(const short&, const short&);
	extern template unsigned short ArithmeticOperation::divide_saturate<unsigned short>(const unsigned short&, const unsigned short&);
	extern template int ArithmeticOperation::divide_saturate<int>(const int&, const int&);
	extern template unsigned int ArithmeticOperation::divide_saturate<unsigned int>(const unsigned int&, const unsigned int&);
	extern template long ArithmeticOperation::divide_saturate<long>(const long&, const long&);
	extern template unsigned long ArithmeticOperation::divide_saturate<unsigned long>(const unsigned long&, const unsigned long&);
	extern template long long ArithmeticOperation::divide_saturate<long long>(const long long&, const long long&);
	extern template unsigned long long ArithmeticOperation::divide_saturate<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template float ArithmeticOperation::divide_saturate<float>(const float&, const float&);
	extern template double ArithmeticOperation::divide_saturate<double>(const double&, const double&);
	extern template long double ArithmeticOperation::divide_saturate<long double>(const long double&, const long double&);
	extern template char16_t ArithmeticOperation::divide_saturate<char16_t>(const char16_t&, const char16_t&);
	extern template char32_t ArithmeticOperation::divide_saturate<char32_t>(const char32_t&, const char32_t&);
	extern template bool ArithmeticOperation::add_checked<bool>(const bool&, const bool&);
	extern template char ArithmeticOperation::add_checked<char>(const char&, const char&);
	extern template signed char ArithmeticOperation::add_checked<signed char>(const signed char&, const signed char&);
	extern template unsigned char ArithmeticOperation::add_checked<unsigned char>(const unsigned char&, const unsigned char&);
	extern template wchar_t ArithmeticOperation::add_checked<wchar_t>(const wchar_t&, const wchar_t&);
	extern template short ArithmeticOperation::add_checked<short>(const short&, const short&);
	extern template unsigned short ArithmeticOperation::add_checked<unsigned short>(const unsigned short&, const unsigned short&);
	extern template int ArithmeticOperation::add_checked<int>(const int&, const int&);
	extern template unsigned int ArithmeticOperation::add_checked<unsigned int>(const unsigned int&, const unsigned int&);
	extern template long ArithmeticOperation::add_checked<long>(const long&, const long&);
	extern template unsigned long ArithmeticOperation::add_checked<unsigned long>(const unsigned long&, const unsigned long&);
	extern template long long ArithmeticOperation::add_checked<long long>(const long long&, const long long&);
	extern template unsigned long long ArithmeticOperation::add_checked<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template float ArithmeticOperation::add_checked<float>(const float&, const float&);
	extern template double ArithmeticOperation::add_checked<double>(const double&, const double&);
	extern template long double ArithmeticOperation::add_checked<long double>(const long double&, const long double&);
	extern template char16_t ArithmeticOperation::add_checked<char16_t>(const char16_t&, const char16_t&);
	extern template char32_t ArithmeticOperation::add_checked<char32_t>(const char32_t&, const char32_t&);
	extern template bool ArithmeticOperation::subtract_checked<bool>(const bool&, const bool&);
	extern template char ArithmeticOperation::subtract_checked<char>(const char&, const char&);
	extern template signed char ArithmeticOperation::subtract_checked<signed char>(const signed char&, const signed char&);
	extern template unsigned char ArithmeticOperation::subtract_checked<unsigned char>(const unsigned char&, const unsigned char&);
	extern template wchar_t ArithmeticOperation::subtract_checked<wchar_t>(const wchar_t&, const wchar_t&);
	extern template short ArithmeticOperation::subtract_checked<short>(const short&, const short&);
	extern template unsigned short ArithmeticOperation::subtract_checked<unsigned short>(const unsigned short&, const unsigned short&);
	extern template int ArithmeticOperation::subtract_checked<int>(const int&, const int&);
	extern template unsigned int ArithmeticOperation::subtract_checked<unsigned int>(const unsigned int&, const unsigned int&);
	extern template long ArithmeticOperation::subtract_checked<long>(const long&, const long&);
	extern template unsigned long ArithmeticOperation::subtract_checked<unsigned long>(const unsigned long&, const unsigned long&);
	extern template long long ArithmeticOperation::subtract_checked<long long>(const long long&, const long long&);
	extern template unsigned long long ArithmeticOperation::subtract_checked<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template float ArithmeticOperation::subtract_checked<float>(const float&, const float&);
	extern template double ArithmeticOperation::subtract_checked<double>(const double&, const double&);
	extern template long double ArithmeticOperation::subtract_checked<long double>(const long double&, const long double&);
	extern template char16_t ArithmeticOperation::subtract_checked<char16_t>(const char16_t&, const char16_t&);
	extern template char32_t ArithmeticOperation::subtract_checked<char32_t>(const char32_t&, const char32_t&);
	extern template bool ArithmeticOperation::multiply_checked<bool>(const bool&, const bool&);
	extern template char ArithmeticOperation::multiply_checked<char>(const char&, const char&);
	extern template signed char ArithmeticOperation::multiply_checked<signed char>(const signed char&, const signed char&);
	extern template unsigned char ArithmeticOperation::multiply_checked<unsigned char>(const unsigned char&, const unsigned char&);
	extern template wchar_t ArithmeticOperation::multiply_checked<wchar_t>(const wchar_t&, const wchar_t&);
	extern template short ArithmeticOperation::multiply_checked<short>(const short&, const short&);
	extern template unsigned short ArithmeticOperation::multiply_checked<unsigned short>(const unsigned short&, const unsigned short&);
	extern template int ArithmeticOperation::multiply_checked<int>(const int&, const int&);
	extern template unsigned int ArithmeticOperation::multiply_checked<unsigned int>(const unsigned int&, const unsigned int&);
	extern template long ArithmeticOperation::multiply_checked<long>(const long&, const long&);
	extern template unsigned long ArithmeticOperation::multiply_checked<unsigned long>(const unsigned long&, const unsigned long&);
	extern template long long ArithmeticOperation::multiply_checked<long long>(const long long&, const long long&);
	extern template unsigned long long ArithmeticOperation::multiply_checked<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template float ArithmeticOperation::multiply_checked<float>(const float&, const float&);
	extern template double ArithmeticOperation::multiply_checked<double>(const double&, const double&);
	extern template long double ArithmeticOperation::multiply_checked<long double>(const long double&, const long double&);
	extern template char16_t ArithmeticOperation::multiply_checked<char16_t>(const char16_t&, const char16_t&);
	extern template char32_t ArithmeticOperation::multiply_checked<char32_t>(const char32_t&, const char32_t&);
	extern template bool ArithmeticOperation::divide_checked<bool>(const bool&, const bool&);
	extern template char ArithmeticOperation::divide_checked<char>(const char&, const char&);
	extern template signed char ArithmeticOperation::divide_checked<signed char>(const signed char&, const signed char&);
	extern template unsigned char ArithmeticOperation::divide_checked<unsigned char>(const unsigned char&, const unsigned char&);
	extern template wchar_t ArithmeticOperation::divide_checked<wchar_t>(const wchar_t&, const wchar_t&);
	extern template short ArithmeticOperation::divide_checked<short>(const short&, const short&);
	extern template unsigned short ArithmeticOperation::divide_checked<unsigned short>(const unsigned short&, const unsigned short&);
	extern template int ArithmeticOperation::divide_checked<int>(const int&, const int&);
	extern template unsigned int ArithmeticOperation::divide_checked<unsigned int>(const unsigned int&, const unsigned int&);
	extern template long ArithmeticOperation::divide_checked<long>(const long&, const long&);
	extern template unsigned long ArithmeticOperation::divide_checked<unsigned long>(const unsigned long&, const unsigned long&);
	extern template long long ArithmeticOperation::divide_checked<long long>(const long long&, const long long&);
	extern template unsigned long long ArithmeticOperation::divide_checked<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template float ArithmeticOperation::divide_checked<float>(const float&, const float&);
	extern template double ArithmeticOperation::divide_checked<double>(const double&, const double&);
	extern template long double ArithmeticOperation::divide_checked<long double>(const long double&, const long double&);
	extern template char16_t ArithmeticOperation::divide_checked<char16_t>(const char16_t&, const char16_t&);
	extern template char32_t ArithmeticOperation::divide_checked<char32_t>(const char32_t&, const char32_t&);
	extern template bool ArithmeticOperation::may_overflow_addition<bool>(const bool&, const bool&);
	extern template bool ArithmeticOperation::may_overflow_addition<char>(const char&, const char&);
	extern template bool ArithmeticOperation::may_overflow_addition<signed char>(const signed char&, const signed char&);
	extern template bool ArithmeticOperation::may_overflow_addition<unsigned char>(const unsigned char&, const unsigned char&);
	extern template bool ArithmeticOperation::may_overflow_addition<wchar_t>(const wchar_t&, const wchar_t&);
	extern template bool ArithmeticOperation::may_overflow_addition<short>(const short&, const short&);
	extern template bool ArithmeticOperation::may_overflow_addition<unsigned short>(const unsigned short&, const unsigned short&);
	extern template bool ArithmeticOperation::may_overflow_addition<int>(const int&, const int&);
	extern template bool ArithmeticOperation::may_overflow_addition<unsigned int>(const unsigned int&, const unsigned int&);
	extern template bool ArithmeticOperation::may_overflow_addition<long>(const long&, const long&);
	extern template bool ArithmeticOperation::may_overflow_addition<unsigned long>(const unsigned long&, const unsigned long&);
	extern template bool ArithmeticOperation::may_overflow_addition<long long>(const long long&, const long long&);
	extern template bool ArithmeticOperation::may_overflow_addition<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template bool ArithmeticOperation::may_overflow_addition<float>(const float&, const float&);
	extern template bool ArithmeticOperation::may_overflow_addition<double>(const double&, const double&);
	extern template bool ArithmeticOperation::may_overflow_addition<long double>(const long double&, const long double&);
	extern template bool ArithmeticOperation::may_overflow_addition<char16_t>(const char16_t&, const char16_t&);
	extern template bool ArithmeticOperation::may_overflow_addition<char32_t>(const char32_t&, const char32_t&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<bool>(const bool&, const bool&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<char>(const char&, const char&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<signed char>(const signed char&, const signed char&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<unsigned char>(const unsigned char&, const unsigned char&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<wchar_t>(const wchar_t&, const wchar_t&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<short>(const short&, const short&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<unsigned short>(const unsigned short&, const unsigned short&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<int>(const int&, const int&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<unsigned int>(const unsigned int&, const unsigned int&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<long>(const long&, const long&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<unsigned long>(const unsigned long&, const unsigned long&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<long long>(const long long&, const long long&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<float>(const float&, const float&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<double>(const double&, const double&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<long double>(const long double&, const long double&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<char16_t>(const char16_t&, const char16_t&);
	extern template bool ArithmeticOperation::may_overflow_subtraction<char32_t>(const char32_t&, const char32_t&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<bool>(const bool&, const bool&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<char>(const char&, const char&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<signed char>(const signed char&, const signed char&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<unsigned char>(const unsigned char&, const unsigned char&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<wchar_t>(const wchar_t&, const wchar_t&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<short>(const short&, const short&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<unsigned short>(const unsigned short&, const unsigned short&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<int>(const int&, const int&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<unsigned int>(const unsigned int&, const unsigned int&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<long>(const long&, const long&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<unsigned long>(const unsigned long&, const unsigned long&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<long long>(const long long&, const long long&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<float>(const float&, const float&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<double>(const double&, const double&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<long double>(const long double&, const long double&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<char16_t>(const char16_t&, const char16_t&);
	extern template bool ArithmeticOperation::may_overflow_multiplication<char32_t>(const char32_t&, const char32_t&);
	extern template bool ArithmeticOperation::may_overflow_division<bool>(const bool&, const bool&);
	extern template bool ArithmeticOperation::may_overflow_division<char>(const char&, const char&);
	extern template bool ArithmeticOperation::may_overflow_division<signed char>(const signed char&, const signed char&);
	extern template bool ArithmeticOperation::may_overflow_division<unsigned char>(const unsigned char&, const unsigned char&);
	extern template bool ArithmeticOperation::may_overflow_division<wchar_t>(const wchar_t&, const wchar_t&);
	extern template bool ArithmeticOperation::may_overflow_division<short>(const short&, const short&);
	extern template bool ArithmeticOperation::may_overflow_division<unsigned short>(const unsigned short&, const unsigned short&);
	extern template bool ArithmeticOperation::may_overflow_division<int>(const int&, const int&);
	extern template bool ArithmeticOperation::may_overflow_division<unsigned int>(const unsigned int&, const unsigned int&);
	extern template bool ArithmeticOperation::may_overflow_division<long>(const long&, const long&);
	extern template bool ArithmeticOperation::may_overflow_division<unsigned long>(const unsigned long&, const unsigned long&);
	extern template bool ArithmeticOperation::may_overflow_division<long long>(const long long&, const long long&);
	extern template bool ArithmeticOperation::may_overflow_division<unsigned long long>(const unsigned long long&, const unsigned long long&);
	extern template bool ArithmeticOperation::may_overflow_division<float>(const float&, const float&);
	extern template bool ArithmeticOperation::may_overflow_division<double>(const double&, const double&);
	extern template bool ArithmeticOperation::may_overflow_division<long double>(const long double&, const long double&);
	extern template bool ArithmeticOperation::may_overflow_division<char16_t>(const char16_t&, const char16_t&);
	extern template bool ArithmeticOperation::may_overflow_division<char32_t>(const char32_t&, const char32_t&);
}
#endif // __stationaryorbit_core_arithmetic__
