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
#include "traits.hpp"
namespace zawa_ch::StationaryOrbit
{
	class NumericalTraits
	{
		NumericalTraits() = delete;
		~NumericalTraits() = delete;
	private:
		template<class, class = std::void_t<>> struct HasArithmeticTypeOperation_t : std::false_type {};
		template<class T> struct HasArithmeticTypeOperation_t<T, std::void_t< Traits::PromotionResult<T> >> : std::conjunction
			<
				std::bool_constant<Traits::PromotionResultIsConvertible<T, T>>,
				std::bool_constant<Traits::InverseResultIsSame<T, Traits::PromotionResult<T>>>,
				std::bool_constant<Traits::AdditionResultIsSame<T, T, Traits::PromotionResult<T>>>,
				std::bool_constant<Traits::SubtractionResultIsSame<T, T, Traits::PromotionResult<T>>>,
				std::bool_constant<Traits::MultiplicationResultIsSame<T, T, Traits::PromotionResult<T>>>,
				std::bool_constant<Traits::DivisionResultIsSame<T, T, Traits::PromotionResult<T>>>,
				std::bool_constant<Traits::SubstitutionAddResultIsSame<T, T, T&>>,
				std::bool_constant<Traits::SubstitutionSubtractResultIsSame<T, T, T&>>,
				std::bool_constant<Traits::SubstitutionMultipleResultIsSame<T, T, T&>>,
				std::bool_constant<Traits::SubstitutionDivideResultIsSame<T, T, T&>>,
				std::bool_constant<Traits::IsEquatable<T, T>>
			>
		{};
		template<class T> struct HasNumericalTypeOperation_t : std::conjunction
			<
				HasArithmeticTypeOperation_t<T>,
				std::bool_constant<Traits::IsComparable<T, T>>
			>
		{};
		template<class, class = std::void_t<>> struct HasIntegralTypeOperation_t : std::false_type {};
		template<class T> struct HasIntegralTypeOperation_t<T, std::void_t< Traits::PromotionResult<T> >> : std::conjunction
			<
				std::bool_constant<Traits::PreincrementResultIsSame<T, T&>>,
				std::bool_constant<Traits::PredecrementResultIsSame<T, T&>>,
				HasNumericalTypeOperation_t<T>,
				std::bool_constant<Traits::SubstitutionModulateResultIsSame<T, T, T&>>,
				std::bool_constant<Traits::ModulationResultIsSame<T, T, Traits::PromotionResult<T>>>
			>
		{};
		template<class T> struct IsArithmeticType_t : std::conjunction< std::bool_constant<Traits::IsValueType<T>>, HasArithmeticTypeOperation_t<T> > {};
		template<class T> struct IsNumericalType_t : std::conjunction< IsArithmeticType_t<T>, HasNumericalTypeOperation_t<T>, std::bool_constant<std::numeric_limits<T>::is_specialized> > {};
		template<class T> struct IsIntegralType_t : std::conjunction< IsNumericalType_t<T>, HasIntegralTypeOperation_t<T> > {};
	public:
		///	基本的な算術演算子の実装を識別します
		template<class T> static constexpr bool HasArithmeticOperation = HasArithmeticTypeOperation_t<T>::value;
		///	型要件:ArithmeticTypeを満たす型を識別します
		template<class T> static constexpr bool IsArithmeticType = IsArithmeticType_t<T>::value;
		///	型要件:NumericalTypeを満たす型を識別します
		template<class T> static constexpr bool IsNumericalType = IsNumericalType_t<T>::value;
		///	型要件:IntegralTypeを満たす型を識別します
		template<class T> static constexpr bool IsIntegralType = IsIntegralType_t<T>::value;
	};
}
#endif // __stationaryorbit_core_numericaltraits__
