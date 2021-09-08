//	stationaryorbit/core/numericaltraits
//	Copyright 2021 zawa-ch.
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
#ifndef __stationaryorbit_core_numericaltraits__
#define __stationaryorbit_core_numericaltraits__
#include <type_traits>
#include "typetraitsbase.hpp"
#include "equatabletypetraits.hpp"
#include "comparabletypetraits.hpp"
#include "valuetypetraits.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	型要件:ArithmeticType を満たす型を識別します
	class ArithmeticTypeTraits : public ValueTypeTraits
	{
		ArithmeticTypeTraits() = delete;
		ArithmeticTypeTraits(const ArithmeticTypeTraits&) = delete;
		ArithmeticTypeTraits(ArithmeticTypeTraits&&) = delete;
		ArithmeticTypeTraits& operator=(const ArithmeticTypeTraits&) = delete;
		ArithmeticTypeTraits& operator=(ArithmeticTypeTraits&&) = delete;
		~ArithmeticTypeTraits() = delete;
	protected:
		template<typename, typename = std::void_t<>> struct HasArithmeticTypeOperation_impl : std::false_type {};
		template<typename T> struct HasArithmeticTypeOperation_impl<T, std::void_t< TypeTraitsBase::PromotionResult<T> >> : std::conjunction
			<
				std::bool_constant<TypeTraitsBase::promotion_result_is_convertible<T, T>>,
				std::bool_constant<TypeTraitsBase::inverse_result_is_same<T, TypeTraitsBase::PromotionResult<T>>>,
				std::bool_constant<TypeTraitsBase::addition_result_is_same<T, T, TypeTraitsBase::PromotionResult<T>>>,
				std::bool_constant<TypeTraitsBase::subtraction_result_is_same<T, T, TypeTraitsBase::PromotionResult<T>>>,
				std::bool_constant<TypeTraitsBase::multiplication_result_is_same<T, T, TypeTraitsBase::PromotionResult<T>>>,
				std::bool_constant<TypeTraitsBase::division_result_is_same<T, T, TypeTraitsBase::PromotionResult<T>>>,
				std::bool_constant<TypeTraitsBase::substitution_add_result_is_same<T, T, T&>>,
				std::bool_constant<TypeTraitsBase::substitution_subtract_result_is_same<T, T, T&>>,
				std::bool_constant<TypeTraitsBase::substitution_multiply_result_is_same<T, T, T&>>,
				std::bool_constant<TypeTraitsBase::substitution_divide_result_is_same<T, T, T&>>
			>
		{};
		template<typename T> struct IsArithmeticType_impl : std::conjunction< std::bool_constant<ValueTypeTraits::is_valuetype<T>>, HasArithmeticTypeOperation_impl<T> > {};
	public:
		///	指定された型が 型要件:ArithmeticType を満たすかを識別します。
		template<typename T> static constexpr bool is_arithmetictype = IsArithmeticType_impl<T>::value;

		///	値の型を昇格します。
		template<typename T> [[nodiscard]] static constexpr TypeTraitsBase::PromotionResult<T> promote(const T& value) { static_assert(is_arithmetictype<T>, "型 T は 型要件:ArithmeticType を満たしません。"); return TypeTraitsBase::promotion(value); }
		///	負の値を取得します。
		template<typename T> [[nodiscard]] static constexpr TypeTraitsBase::PromotionResult<T> invert(const T& value) { static_assert(is_arithmetictype<T>, "型 T は 型要件:ArithmeticType を満たしません。"); return TypeTraitsBase::inverse(value); }
		///	加算を行います。
		template<typename T> [[nodiscard]] static constexpr TypeTraitsBase::PromotionResult<T> add(const T& value, const T& other) { static_assert(is_arithmetictype<T>, "型 T は 型要件:ArithmeticType を満たしません。"); return TypeTraitsBase::addition(value, other); }
		///	減算を行います。
		template<typename T> [[nodiscard]] static constexpr TypeTraitsBase::PromotionResult<T> subtract(const T& value, const T& other) { static_assert(is_arithmetictype<T>, "型 T は 型要件:ArithmeticType を満たしません。"); return TypeTraitsBase::subtraction(value, other); }
		///	乗算を行います。
		template<typename T> [[nodiscard]] static constexpr TypeTraitsBase::PromotionResult<T> multiply(const T& value, const T& other) { static_assert(is_arithmetictype<T>, "型 T は 型要件:ArithmeticType を満たしません。"); return TypeTraitsBase::multiplication(value, other); }
		///	除算を行います。
		template<typename T> [[nodiscard]] static constexpr TypeTraitsBase::PromotionResult<T> divide(const T& value, const T& other) { static_assert(is_arithmetictype<T>, "型 T は 型要件:ArithmeticType を満たしません。"); return TypeTraitsBase::division(value, other); }
		///	加算を行い、代入します。
		template<typename T> [[nodiscard]] static constexpr T& substitute_add(T& value, const T& other) { static_assert(is_arithmetictype<T>, "型 T は 型要件:ArithmeticType を満たしません。"); return TypeTraitsBase::substitution_add(value, other); }
		///	減算を行い、代入します。
		template<typename T> [[nodiscard]] static constexpr T& substitute_subtract(T& value, const T& other) { static_assert(is_arithmetictype<T>, "型 T は 型要件:ArithmeticType を満たしません。"); return TypeTraitsBase::substitution_subtract(value, other); }
		///	乗算を行い、代入します。
		template<typename T> [[nodiscard]] static constexpr T& substitute_multiply(T& value, const T& other) { static_assert(is_arithmetictype<T>, "型 T は 型要件:ArithmeticType を満たしません。"); return TypeTraitsBase::substitution_multiply(value, other); }
		///	除算を行い、代入します。
		template<typename T> [[nodiscard]] static constexpr T& substitute_divide(T& value, const T& other) { static_assert(is_arithmetictype<T>, "型 T は 型要件:ArithmeticType を満たしません。"); return TypeTraitsBase::substitution_divide(value, other); }
	};

	///	型要件:NumericalType を満たす型を識別します
	class NumericalTypeTraits : public ArithmeticTypeTraits
	{
		NumericalTypeTraits() = delete;
		NumericalTypeTraits(const NumericalTypeTraits&) = delete;
		NumericalTypeTraits(NumericalTypeTraits&&) = delete;
		NumericalTypeTraits& operator=(const NumericalTypeTraits&) = delete;
		NumericalTypeTraits& operator=(NumericalTypeTraits&&) = delete;
		~NumericalTypeTraits() = delete;
	protected:
		template<class T> struct HasNumericalTypeOperation_impl : std::conjunction
			<
				HasArithmeticTypeOperation_impl<T>,
				std::bool_constant<ComparableTypeTraits::is_comparable<T, T>>
			>
		{};
		template<class T> struct IsNumericalType_impl : std::conjunction< IsArithmeticType_impl<T>, HasNumericalTypeOperation_impl<T>, std::bool_constant<std::numeric_limits<T>::is_specialized> > {};
	public:
		///	指定された型が 型要件:NumericalType を満たすかを識別します。
		template<class T> static constexpr bool IsNumericalType = IsNumericalType_impl<T>::value;
	};
	///	型要件:IntegralType を満たす型を識別します
	class IntegralTypeTraits : public NumericalTypeTraits
	{
		IntegralTypeTraits() = delete;
		IntegralTypeTraits(const IntegralTypeTraits&) = delete;
		IntegralTypeTraits(IntegralTypeTraits&&) = delete;
		IntegralTypeTraits& operator=(const IntegralTypeTraits&) = delete;
		IntegralTypeTraits& operator=(IntegralTypeTraits&&) = delete;
		~IntegralTypeTraits() = delete;
	protected:
		template<class, class = std::void_t<>> struct HasIntegralTypeOperation_impl : std::false_type {};
		template<class T> struct HasIntegralTypeOperation_impl<T, std::void_t< TypeTraitsBase::PromotionResult<T> >> : std::conjunction
			<
				std::bool_constant<TypeTraitsBase::preincrement_result_is_same<T, T&>>,
				std::bool_constant<TypeTraitsBase::predecrement_result_is_same<T, T&>>,
				HasNumericalTypeOperation_impl<T>,
				std::bool_constant<TypeTraitsBase::substitution_modulate_result_is_same<T, T, T&>>,
				std::bool_constant<TypeTraitsBase::modulation_result_is_same<T, T, TypeTraitsBase::PromotionResult<T>>>
			>
		{};
		template<class T> struct IsIntegralType_impl : std::conjunction< IsNumericalType_impl<T>, HasIntegralTypeOperation_impl<T> > {};
	public:
		///	指定された型が 型要件:IntegralType を満たすかを識別します。
		template<class T> static constexpr bool IsIntegralType = IsIntegralType_impl<T>::value;
	};
}
#endif // __stationaryorbit_core_numericaltraits__
