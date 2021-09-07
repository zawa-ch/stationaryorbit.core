//	stationaryorbit/core/typetraitsbase
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
#ifndef __stationaryorbit_core_traits__
#define __stationaryorbit_core_traits__
#include <type_traits>
#include <limits>
#include <cstdint>
namespace zawa_ch::StationaryOrbit
{
	///	このライブラリで用いられる型特性の識別を行うための基本クラスです。
	///
	///	@a Traits は、このライブラリで定義されるオブジェクトの期待を実装するものです。
	///	このクラスのインスタンスを作成することはできません。また、継承することもできません。
	class TypeTraitsBase final
	{
	private:
		TypeTraitsBase() = delete;
		TypeTraitsBase(const TypeTraitsBase&) = delete;
		TypeTraitsBase& operator=(const TypeTraitsBase&) = delete;
		TypeTraitsBase&& operator=(TypeTraitsBase&&) = delete;
		TypeTraitsBase(TypeTraitsBase&&) = delete;
		~TypeTraitsBase() = delete;

		template<class T, class U, class R = decltype( std::declval<T&>() = std::declval<U&>() )> struct SubstitutionResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() += std::declval<U&>() )> struct SubstitutionAddResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() -= std::declval<U&>() )> struct SubstitutionSubtractResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() *= std::declval<U&>() )> struct SubstitutionMultiplyResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() /= std::declval<U&>() )> struct SubstitutionDivideResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() %= std::declval<U&>() )> struct SubstitutionModulateResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() &= std::declval<U&>() )> struct SubstitutionArithmeticAndResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() |= std::declval<U&>() )> struct SubstitutionArithmeticOrResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() ^= std::declval<U&>() )> struct SubstitutionArithmeticXorResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() <<= std::declval<U&>() )> struct SubstitutionLShiftResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() >>= std::declval<U&>() )> struct SubstitutionRShiftResult_impl { typedef R type; };
		template<class T, class R = decltype( ++std::declval<T&>() )> struct PreincrementResult_impl { typedef R type; };
		template<class T, class R = decltype( --std::declval<T&>() )> struct PredecrementResult_impl { typedef R type; };
		template<class T, class R = decltype( std::declval<T&>()++ )> struct PostincrementResult_impl { typedef R type; };
		template<class T, class R = decltype( std::declval<T&>()-- )> struct PostdecrementResult_impl { typedef R type; };
		template<class T, class R = decltype( +std::declval<T&>() )> struct PromotionResult_impl { typedef R type; };
		template<class T, class R = decltype( -std::declval<T&>() )> struct InverseResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() + std::declval<U&>() )> struct AdditionResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() - std::declval<U&>() )> struct SubtractionResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() * std::declval<U&>() )> struct MultiplicationResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() / std::declval<U&>() )> struct DivisionResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() % std::declval<U&>() )> struct ModulationResult_impl { typedef R type; };
		template<class T, class R = decltype( ~std::declval<T&>() )> struct ArithmeticNotResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() & std::declval<U&>() )> struct ArithmeticOrResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() | std::declval<U&>() )> struct ArithmeticAndResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() ^ std::declval<U&>() )> struct ArithmeticXorResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() << std::declval<U&>() )> struct LShiftResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() >> std::declval<U&>() )> struct RShiftResult_impl { typedef R type; };
		template<class T, class R = decltype( !std::declval<T&>() )> struct LogicalNotResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() && std::declval<U&>() )> struct LogicalAndResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() || std::declval<U&>() )> struct LogicalOrResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() == std::declval<U&>() )> struct EqualResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() != std::declval<U&>() )> struct NotEqualResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() > std::declval<U&>() )> struct CompareLargerResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() < std::declval<U&>() )> struct CompareSmallerResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() >= std::declval<U&>() )> struct CompareLeastResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>() <= std::declval<U&>() )> struct CompareMostResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>()[ std::declval<U&>() ] )> struct SubscriptResult_impl { typedef R type; };
		template<class T, class R = decltype( *std::declval<T&>() )> struct DereferenceResult_impl { typedef R type; };
		template<class T, class R = decltype( &std::declval<T&>() )> struct ReferenceResult_impl { typedef R type; };
		template<class T, class U, class R = decltype( std::declval<T&>(), std::declval<U&>() )> struct CommaResult_impl { typedef R type; };
	public:
		///	代入演算子 @a T::operator=(U) の結果を表す型
		template<class T, class U> using SubstitutionResult = typename SubstitutionResult_impl<T, U>::type;
		///	複合代入演算子 @a T::operator+=(U) の結果を表す型
		template<class T, class U> using SubstitutionAddResult = typename SubstitutionAddResult_impl<T, U>::type;
		///	複合代入演算子 @a T::operator-=(U) の結果を表す型
		template<class T, class U> using SubstitutionSubtractResult = typename SubstitutionSubtractResult_impl<T, U>::type;
		///	複合代入演算子 @a T::operator*=(U) の結果を表す型
		template<class T, class U> using SubstitutionMultiplyResult = typename SubstitutionMultiplyResult_impl<T, U>::type;
		///	複合代入演算子 @a T::operator/=(U) の結果を表す型
		template<class T, class U> using SubstitutionDivideResult = typename SubstitutionDivideResult_impl<T, U>::type;
		///	複合代入演算子 @a T::operator%=(U) の結果を表す型
		template<class T, class U> using SubstitutionModulateResult = typename SubstitutionModulateResult_impl<T, U>::type;
		///	複合代入演算子 @a T::operator&=(U) の結果を表す型
		template<class T, class U> using SubstitutionArithmeticAndResult = typename SubstitutionArithmeticAndResult_impl<T, U>::type;
		///	複合代入演算子 @a T::operator|=(U) の結果を表す型
		template<class T, class U> using SubstitutionArithmeticOrResult = typename SubstitutionArithmeticOrResult_impl<T, U>::type;
		///	複合代入演算子 @a T::operator^=(U) の結果を表す型
		template<class T, class U> using SubstitutionArithmeticXorResult = typename SubstitutionArithmeticXorResult_impl<T, U>::type;
		///	複合代入演算子 @a T::operator<<=(U) の結果を表す型
		template<class T, class U> using SubstitutionLShiftResult = typename SubstitutionLShiftResult_impl<T, U>::type;
		///	複合代入演算子 @a T::operator>>=(U) の結果を表す型
		template<class T, class U> using SubstitutionRShiftResult = typename SubstitutionRShiftResult_impl<T, U>::type;
		///	前置インクリメント演算子 @a T::operator++() の結果を表す型
		template<class T> using PreincrementResult = typename PreincrementResult_impl<T>::type;
		///	前置デクリメント演算子 @a T::operator--() の結果を表す型
		template<class T> using PredecrementResult = typename PredecrementResult_impl<T>::type;
		///	後置インクリメント演算子 @a T::operator++(int) の結果を表す型
		template<class T> using PostincrementResult = typename PostincrementResult_impl<T>::type;
		///	後置デクリメント演算子 @a T::operator--(int) の結果を表す型
		template<class T> using PostdecrementResult = typename PostdecrementResult_impl<T>::type;
		///	算術演算子 @a T::operator+() の結果を表す型
		template<class T> using PromotionResult = typename PromotionResult_impl<T>::type;
		///	算術演算子 @a T::operator-() の結果を表す型
		template<class T> using InverseResult = typename InverseResult_impl<T>::type;
		///	算術演算子 @a T::operator+(U) の結果を表す型
		template<class T, class U> using AdditionResult = typename AdditionResult_impl<T, U>::type;
		///	算術演算子 @a T::operator-(U) の結果を表す型
		template<class T, class U> using SubtractionResult = typename SubtractionResult_impl<T, U>::type;
		///	算術演算子 @a T::operator*(U) の結果を表す型
		template<class T, class U> using MultiplicationResult = typename MultiplicationResult_impl<T, U>::type;
		///	算術演算子 @a T::operator/(U) の結果を表す型
		template<class T, class U> using DivisionResult = typename DivisionResult_impl<T, U>::type;
		///	算術演算子 @a T::operator%(U) の結果を表す型
		template<class T, class U> using ModulationResult = typename ModulationResult_impl<T, U>::type;
		///	ビット演算子 @a T::operator~() の結果を表す型
		template<class T> using ArithmeticNotResult = typename ArithmeticNotResult_impl<T>::type;
		///	ビット演算子 @a T::operator&(U) の結果を表す型
		template<class T, class U> using ArithmeticAndResult = typename ArithmeticAndResult_impl<T, U>::type;
		///	ビット演算子 @a T::operator|(U) の結果を表す型
		template<class T, class U> using ArithmeticOrResult = typename ArithmeticOrResult_impl<T, U>::type;
		///	ビット演算子 @a T::operator^(U) の結果を表す型
		template<class T, class U> using ArithmeticXorResult = typename ArithmeticXorResult_impl<T, U>::type;
		///	ビット演算子 @a T::operator<<(U) の結果を表す型
		template<class T, class U> using LShiftResult = typename LShiftResult_impl<T, U>::type;
		///	ビット演算子 @a T::operator>>(U) の結果を表す型
		template<class T, class U> using RShiftResult = typename RShiftResult_impl<T, U>::type;
		///	論理演算子 @a T::operator!() の結果を表す型
		template<class T> using LogicalNotResult = typename LogicalNotResult_impl<T>::type;
		///	論理演算子 @a T::operator||(U) の結果を表す型
		template<class T, class U> using LogicalOrResult = typename LogicalOrResult_impl<T, U>::type;
		///	論理演算子 @a T::operator&&(U) の結果を表す型
		template<class T, class U> using LogicalAndResult = typename LogicalAndResult_impl<T, U>::type;
		///	比較演算子 @a T::operator==(U) の結果を表す型
		template<class T, class U> using EqualResult = typename EqualResult_impl<T, U>::type;
		///	比較演算子 @a T::operator!=(U) の結果を表す型
		template<class T, class U> using NotEqualResult = typename NotEqualResult_impl<T, U>::type;
		///	比較演算子 @a T::operator>(U) の結果を表す型
		template<class T, class U> using CompareLargerResult = typename CompareLargerResult_impl<T, U>::type;
		///	比較演算子 @a T::operator<(U) の結果を表す型
		template<class T, class U> using CompareSmallerResult = typename CompareSmallerResult_impl<T, U>::type;
		///	比較演算子 @a T::operator>=(U) の結果を表す型
		template<class T, class U> using CompareLeastResult = typename CompareLeastResult_impl<T, U>::type;
		///	比較演算子 @a T::operator<=(U) の結果を表す型
		template<class T, class U> using CompareMostResult = typename CompareMostResult_impl<T, U>::type;
		///	添字演算子 @a T::operator[](U) の結果を表す型
		template<class T, class U> using SubscriptResult = typename SubscriptResult_impl<T, U>::type;
		///	間接参照演算子 @a T::operator*() の結果を表す型
		template<class T> using DereferenceResult = typename DereferenceResult_impl<T>::type;
		///	アドレス取得演算子 @a T::operator&() の結果を表す型
		template<class T> using ReferenceResult = typename ReferenceResult_impl<T>::type;
		///	カンマ演算子 @a T::operator,(U) の結果を表す型
		template<class T, class U> using CommaResult = typename CommaResult_impl<T, U>::type;
	private:
		template<class, class, class = std::void_t<>> struct HasSubstitution_impl : std::false_type {};
		template<class T, class U> struct HasSubstitution_impl<T, U, std::void_t< SubstitutionResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasSubstitutionAdd_impl : std::false_type {};
		template<class T, class U> struct HasSubstitutionAdd_impl<T, U, std::void_t< SubstitutionAddResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasSubstitutionSubtract_impl : std::false_type {};
		template<class T, class U> struct HasSubstitutionSubtract_impl<T, U, std::void_t< SubstitutionSubtractResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasSubstitutionMultiply_impl : std::false_type {};
		template<class T, class U> struct HasSubstitutionMultiply_impl<T, U, std::void_t< SubstitutionMultiplyResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasSubstitutionDivide_impl : std::false_type {};
		template<class T, class U> struct HasSubstitutionDivide_impl<T, U, std::void_t< SubstitutionDivideResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasSubstitutionModulate_impl : std::false_type {};
		template<class T, class U> struct HasSubstitutionModulate_impl<T, U, std::void_t< SubstitutionModulateResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasSubstitutionArithmeticAnd_impl : std::false_type {};
		template<class T, class U> struct HasSubstitutionArithmeticAnd_impl<T, U, std::void_t< SubstitutionArithmeticAndResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasSubstitutionArithmeticOr_impl : std::false_type {};
		template<class T, class U> struct HasSubstitutionArithmeticOr_impl<T, U, std::void_t< SubstitutionArithmeticOrResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasSubstitutionArithmeticXor_impl : std::false_type {};
		template<class T, class U> struct HasSubstitutionArithmeticXor_impl<T, U, std::void_t< SubstitutionArithmeticXorResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasSubstitutionLShift_impl : std::false_type {};
		template<class T, class U> struct HasSubstitutionLShift_impl<T, U, std::void_t< SubstitutionLShiftResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasSubstitutionRShift_impl : std::false_type {};
		template<class T, class U> struct HasSubstitutionRShift_impl<T, U, std::void_t< SubstitutionRShiftResult<T, U> > > : std::true_type {};
		template<class, class = std::void_t<>> struct HasPreincrement_impl : std::false_type {};
		template<class T> struct HasPreincrement_impl<T, std::void_t< PreincrementResult<T> > > : std::true_type {};
		template<class, class = std::void_t<>> struct HasPredecrement_impl : std::false_type {};
		template<class T> struct HasPredecrement_impl<T, std::void_t< PredecrementResult<T> > > : std::true_type {};
		template<class, class = std::void_t<>> struct HasPostincrement_impl : std::false_type {};
		template<class T> struct HasPostincrement_impl<T, std::void_t< PostincrementResult<T> > > : std::true_type {};
		template<class, class = std::void_t<>> struct HasPostdecrement_impl : std::false_type {};
		template<class T> struct HasPostdecrement_impl<T, std::void_t< PostdecrementResult<T> > > : std::true_type {};
		template<class, class = std::void_t<>> struct HasPromotion_impl : std::false_type {};
		template<class T> struct HasPromotion_impl<T, std::void_t< PromotionResult<T> > > : std::true_type {};
		template<class, class = std::void_t<>> struct HasInverse_impl : std::false_type {};
		template<class T> struct HasInverse_impl<T, std::void_t< InverseResult<T> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasAddition_impl : std::false_type {};
		template<class T, class U> struct HasAddition_impl<T, U, std::void_t< AdditionResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasSubtraction_impl : std::false_type {};
		template<class T, class U> struct HasSubtraction_impl<T, U, std::void_t< SubtractionResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasMultiplication_impl : std::false_type {};
		template<class T, class U> struct HasMultiplication_impl<T, U, std::void_t< MultiplicationResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasDivision_impl : std::false_type {};
		template<class T, class U> struct HasDivision_impl<T, U, std::void_t< DivisionResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasModulation_impl : std::false_type {};
		template<class T, class U> struct HasModulation_impl<T, U, std::void_t< ModulationResult<T, U> > > : std::true_type {};
		template<class, class = std::void_t<>> struct HasArithmeticNot_impl : std::false_type {};
		template<class T> struct HasArithmeticNot_impl<T, std::void_t< ArithmeticNotResult<T> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasArithmeticAnd_impl : std::false_type {};
		template<class T, class U> struct HasArithmeticAnd_impl<T, U, std::void_t< ArithmeticAndResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasArithmeticOr_impl : std::false_type {};
		template<class T, class U> struct HasArithmeticOr_impl<T, U, std::void_t< ArithmeticOrResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasArithmeticXor_impl : std::false_type {};
		template<class T, class U> struct HasArithmeticXor_impl<T, U, std::void_t< ArithmeticXorResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasLShift_impl : std::false_type {};
		template<class T, class U> struct HasLShift_impl<T, U, std::void_t< LShiftResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasRShift_impl : std::false_type {};
		template<class T, class U> struct HasRShift_impl<T, U, std::void_t< RShiftResult<T, U> > > : std::true_type {};
		template<class, class = std::void_t<>> struct HasLogicalNot_impl : std::false_type {};
		template<class T> struct HasLogicalNot_impl<T, std::void_t< LogicalNotResult<T> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasLogicalOr_impl : std::false_type {};
		template<class T, class U> struct HasLogicalOr_impl<T, U, std::void_t< LogicalOrResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasLogicalAnd_impl : std::false_type {};
		template<class T, class U> struct HasLogicalAnd_impl<T, U, std::void_t< LogicalAndResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasEqual_impl : std::false_type {};
		template<class T, class U> struct HasEqual_impl<T, U, std::void_t< EqualResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasNotEqual_impl : std::false_type {};
		template<class T, class U> struct HasNotEqual_impl<T, U, std::void_t< NotEqualResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasCompareLarger_impl : std::false_type {};
		template<class T, class U> struct HasCompareLarger_impl<T, U, std::void_t< CompareLargerResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasCompareSmaller_impl : std::false_type {};
		template<class T, class U> struct HasCompareSmaller_impl<T, U, std::void_t< CompareSmallerResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasCompareLeast_impl : std::false_type {};
		template<class T, class U> struct HasCompareLeast_impl<T, U, std::void_t< CompareLeastResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasCompareMost_impl : std::false_type {};
		template<class T, class U> struct HasCompareMost_impl<T, U, std::void_t< CompareMostResult<T, U> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasSubscript_impl : std::false_type {};
		template<class T, class U> struct HasSubscript_impl<T, U, std::void_t< SubscriptResult<T, U> > > : std::true_type {};
		template<class, class = std::void_t<>> struct HasDereference_impl : std::false_type {};
		template<class T> struct HasDereference_impl<T, std::void_t< DereferenceResult<T> > > : std::true_type {};
		template<class, class = std::void_t<>> struct HasReference_impl : std::false_type {};
		template<class T> struct HasReference_impl<T, std::void_t< ReferenceResult<T> > > : std::true_type {};
		template<class, class, class = std::void_t<>> struct HasComma_impl : std::false_type {};
		template<class T, class U> struct HasComma_impl<T, U, std::void_t< CommaResult<T, U> > > : std::true_type {};
	public:
		///	代入演算子 @a T::operator=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_substitution = HasSubstitution_impl<T, U>::value;
		///	複合代入演算子 @a T::operator+=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_substitution_add = HasSubstitutionAdd_impl<T, U>::value;
		///	複合代入演算子 @a T::operator-=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_substitution_subtract = HasSubstitutionSubtract_impl<T, U>::value;
		///	複合代入演算子 @a T::operator*=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_substitution_multiply = HasSubstitutionMultiply_impl<T, U>::value;
		///	複合代入演算子 @a T::operator/=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_substitution_divide = HasSubstitutionDivide_impl<T, U>::value;
		///	複合代入演算子 @a T::operator%=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_substitution_modulate = HasSubstitutionModulate_impl<T, U>::value;
		///	複合代入演算子 @a T::operator&=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_substitution_arithmetic_and = HasSubstitutionArithmeticAnd_impl<T, U>::value;
		///	複合代入演算子 @a T::operator|=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_substitution_arithmetic_or = HasSubstitutionArithmeticOr_impl<T, U>::value;
		///	複合代入演算子 @a T::operator^=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_substitution_arithmetic_xor = HasSubstitutionArithmeticXor_impl<T, U>::value;
		///	複合代入演算子 @a T::operator<<=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_substitution_lshift = HasSubstitutionLShift_impl<T, U>::value;
		///	複合代入演算子 @a T::operator>>=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_substitution_rshift = HasSubstitutionRShift_impl<T, U>::value;
		///	前置インクリメント演算子 @a T::operator++() を実装しているかを識別します
		template<class T> static constexpr bool has_preincrement = HasPreincrement_impl<T>::value;
		///	前置インクリメント演算子 @a T::operator--() を実装しているかを識別します
		template<class T> static constexpr bool has_predecrement = HasPredecrement_impl<T>::value;
		///	後置インクリメント演算子 @a T::operator++(int) を実装しているかを識別します
		template<class T> static constexpr bool has_postincrement = HasPostincrement_impl<T>::value;
		///	後置インクリメント演算子 @a T::operator--(int) を実装しているかを識別します
		template<class T> static constexpr bool has_postdecrement = HasPostdecrement_impl<T>::value;
		///	算術演算子 @a T::operator+() を実装しているかを識別します
		template<class T> static constexpr bool has_promotion = HasPromotion_impl<T>::value;
		///	算術演算子 @a T::operator-() を実装しているかを識別します
		template<class T> static constexpr bool has_inverse = HasInverse_impl<T>::value;
		///	算術演算子 @a T::operator+(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_addition = HasAddition_impl<T, U>::value;
		///	算術演算子 @a T::operator-(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_subtraction = HasSubtraction_impl<T, U>::value;
		///	算術演算子 @a T::operator*(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_multiplication = HasMultiplication_impl<T, U>::value;
		///	算術演算子 @a T::operator/(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_division = HasDivision_impl<T, U>::value;
		///	算術演算子 @a T::operator%(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_modulation = HasModulation_impl<T, U>::value;
		///	ビット演算子 @a T::operator~() を実装しているかを識別します
		template<class T> static constexpr bool has_arithmetic_not = HasArithmeticNot_impl<T>::value;
		///	ビット演算子 @a T::operator&(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_arithmetic_and = HasArithmeticAnd_impl<T, U>::value;
		///	ビット演算子 @a T::operator|(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_arithmetic_or = HasArithmeticOr_impl<T, U>::value;
		///	ビット演算子 @a T::operator^(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_arithmetic_xor = HasArithmeticXor_impl<T, U>::value;
		///	ビット演算子 @a T::operator<<(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_lshift = HasLShift_impl<T, U>::value;
		///	ビット演算子 @a T::operator>>(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_rshift = HasRShift_impl<T, U>::value;
		///	論理演算子 @a T::operator!() を実装しているかを識別します
		template<class T> static constexpr bool has_logical_not = HasLogicalNot_impl<T>::value;
		///	論理演算子 @a T::operator||(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_logical_or = HasLogicalOr_impl<T, U>::value;
		///	論理演算子 @a T::operator&&(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_logical_and = HasLogicalAnd_impl<T, U>::value;
		///	比較演算子 @a T::operator==(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_equal = HasEqual_impl<T, U>::value;
		///	比較演算子 @a T::operator!=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_not_equal = HasNotEqual_impl<T, U>::value;
		///	比較演算子 @a T::operator>(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_compare_larger = HasCompareLarger_impl<T, U>::value;
		///	比較演算子 @a T::operator<(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_compare_smaller = HasCompareSmaller_impl<T, U>::value;
		///	比較演算子 @a T::operator>=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_compare_least = HasCompareLeast_impl<T, U>::value;
		///	比較演算子 @a T::operator<=(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_compare_most = HasCompareMost_impl<T, U>::value;
		///	添字演算子 @a T::operator[](U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_subscript = HasSubscript_impl<T, U>::value;
		///	間接参照演算子 @a T::operator*() を実装しているかを識別します
		template<class T> static constexpr bool has_dereference = HasDereference_impl<T>::value;
		///	アドレス取得演算子 @a T::operator&() を実装しているかを識別します
		template<class T> static constexpr bool has_reference = HasReference_impl<T>::value;
		///	カンマ演算子 @a T::operator,(U) を実装しているかを識別します
		template<class T, class U> static constexpr bool has_comma = HasComma_impl<T, U>::value;
	private:
		template<class, class, class, class = std::void_t<>> struct SubstitutionResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionResultIsSame_impl<T, U, R, std::void_t< SubstitutionResult<T, U> > > : std::is_same<SubstitutionResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionAddResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionAddResultIsSame_impl<T, U, R, std::void_t< SubstitutionAddResult<T, U> > > : std::is_same<SubstitutionAddResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionSubtractResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionSubtractResultIsSame_impl<T, U, R, std::void_t< SubstitutionSubtractResult<T, U> > > : std::is_same<SubstitutionSubtractResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionMultiplyResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionMultiplyResultIsSame_impl<T, U, R, std::void_t< SubstitutionMultiplyResult<T, U> > > : std::is_same<SubstitutionMultiplyResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionDivideResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionDivideResultIsSame_impl<T, U, R, std::void_t< SubstitutionDivideResult<T, U> > > : std::is_same<SubstitutionDivideResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionModulateResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionModulateResultIsSame_impl<T, U, R, std::void_t< SubstitutionModulateResult<T, U> > > : std::is_same<SubstitutionModulateResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionArithmeticAndResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionArithmeticAndResultIsSame_impl<T, U, R, std::void_t< SubstitutionArithmeticAndResult<T, U> > > : std::is_same<SubstitutionArithmeticAndResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionArithmeticOrResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionArithmeticOrResultIsSame_impl<T, U, R, std::void_t< SubstitutionArithmeticOrResult<T, U> > > : std::is_same<SubstitutionArithmeticOrResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionArithmeticXorResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionArithmeticXorResultIsSame_impl<T, U, R, std::void_t< SubstitutionArithmeticXorResult<T, U> > > : std::is_same<SubstitutionArithmeticXorResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionLShiftResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionLShiftResultIsSame_impl<T, U, R, std::void_t< SubstitutionLShiftResult<T, U> > > : std::is_same<SubstitutionLShiftResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionRShiftResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionRShiftResultIsSame_impl<T, U, R, std::void_t< SubstitutionRShiftResult<T, U> > > : std::is_same<SubstitutionRShiftResult<T, U>, R> {};
		template<class, class, class = std::void_t<>> struct PreincrementResultIsSame_impl : std::false_type {};
		template<class T, class R> struct PreincrementResultIsSame_impl<T, R, std::void_t< PreincrementResult<T> > > : std::is_same<PreincrementResult<T>, R> {};
		#if 201703L <= __cplusplus
		// Clang C++17でコンパイルするとbool::operator++()を実体化しようとしてエラーを吐くため
		// boolによるインクリメントトレイトは強制的にfalseで実体化する
		template<class R> struct PreincrementResultIsSame_impl<bool, R> : std::false_type {};
		#endif
		template<class, class, class = std::void_t<>> struct PredecrementResultIsSame_impl : std::false_type {};
		template<class T, class R> struct PredecrementResultIsSame_impl<T, R, std::void_t< PredecrementResult<T> > > : std::is_same<PredecrementResult<T>, R> {};
		template<class, class, class = std::void_t<>> struct PostincrementResultIsSame_impl : std::false_type {};
		template<class T, class R> struct PostincrementResultIsSame_impl<T, R, std::void_t< PostincrementResult<T> > > : std::is_same<PostincrementResult<T>, R> {};
		#if 201703L <= __cplusplus
		// Clang C++17でコンパイルするとbool::operator++(int)を実体化しようとしてエラーを吐くため
		// boolによるインクリメントトレイトは強制的にfalseで実体化する
		template<class R> struct PostincrementResultIsSame_impl<bool, R> : std::false_type {};
		#endif
		template<class, class, class = std::void_t<>> struct PostdecrementResultIsSame_impl : std::false_type {};
		template<class T, class R> struct PostdecrementResultIsSame_impl<T, R, std::void_t< PostdecrementResult<T> > > : std::is_same<PostdecrementResult<T>, R> {};
		template<class, class, class = std::void_t<>> struct PromotionResultIsSame_impl : std::false_type {};
		template<class T, class R> struct PromotionResultIsSame_impl<T, R, std::void_t< PromotionResult<T> > > : std::is_same<PromotionResult<T>, R> {};
		template<class, class, class = std::void_t<>> struct InverseResultIsSame_impl : std::false_type {};
		template<class T, class R> struct InverseResultIsSame_impl<T, R, std::void_t< InverseResult<T> > > : std::is_same<InverseResult<T>, R> {};
		template<class, class, class, class = std::void_t<>> struct AdditionResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct AdditionResultIsSame_impl<T, U, R, std::void_t< AdditionResult<T, U> > > : std::is_same<AdditionResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubtractionResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubtractionResultIsSame_impl<T, U, R, std::void_t< SubtractionResult<T, U> > > : std::is_same<SubtractionResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct MultiplicationResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct MultiplicationResultIsSame_impl<T, U, R, std::void_t< MultiplicationResult<T, U> > > : std::is_same<MultiplicationResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct DivisionResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct DivisionResultIsSame_impl<T, U, R, std::void_t< DivisionResult<T, U> > > : std::is_same<DivisionResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct ModulationResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct ModulationResultIsSame_impl<T, U, R, std::void_t< ModulationResult<T, U> > > : std::is_same<ModulationResult<T, U>, R> {};
		template<class, class, class = std::void_t<>> struct ArithmeticNotResultIsSame_impl : std::false_type {};
		template<class T, class R> struct ArithmeticNotResultIsSame_impl<T, R, std::void_t< ArithmeticNotResult<T> > > : std::is_same<ArithmeticNotResult<T>, R> {};
		template<class, class, class, class = std::void_t<>> struct ArithmeticAndResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct ArithmeticAndResultIsSame_impl<T, U, R, std::void_t< ArithmeticAndResult<T, U> > > : std::is_same<ArithmeticAndResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct ArithmeticOrResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct ArithmeticOrResultIsSame_impl<T, U, R, std::void_t< ArithmeticOrResult<T, U> > > : std::is_same<ArithmeticOrResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct ArithmeticXorResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct ArithmeticXorResultIsSame_impl<T, U, R, std::void_t< ArithmeticXorResult<T, U> > > : std::is_same<ArithmeticXorResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct LShiftResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct LShiftResultIsSame_impl<T, U, R, std::void_t< LShiftResult<T, U> > > : std::is_same<LShiftResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct RShiftResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct RShiftResultIsSame_impl<T, U, R, std::void_t< RShiftResult<T, U> > > : std::is_same<RShiftResult<T, U>, R> {};
		template<class, class, class = std::void_t<>> struct LogicalNotResultIsSame_impl : std::false_type {};
		template<class T, class R> struct LogicalNotResultIsSame_impl<T, R, std::void_t< LogicalNotResult<T> > > : std::is_same<LogicalNotResult<T>, R> {};
		template<class, class, class, class = std::void_t<>> struct LogicalOrResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct LogicalOrResultIsSame_impl<T, U, R, std::void_t< LogicalOrResult<T, U> > > : std::is_same<LogicalOrResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct LogicalAndResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct LogicalAndResultIsSame_impl<T, U, R, std::void_t< LogicalAndResult<T, U> > > : std::is_same<LogicalAndResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct EqualResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct EqualResultIsSame_impl<T, U, R, std::void_t< EqualResult<T, U> > > : std::is_same<EqualResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct NotEqualResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct NotEqualResultIsSame_impl<T, U, R, std::void_t< NotEqualResult<T, U> > > : std::is_same<NotEqualResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct CompareLargerResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct CompareLargerResultIsSame_impl<T, U, R, std::void_t< CompareLargerResult<T, U> > > : std::is_same<CompareLargerResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct CompareSmallerResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct CompareSmallerResultIsSame_impl<T, U, R, std::void_t< CompareSmallerResult<T, U> > > : std::is_same<CompareSmallerResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct CompareLeastResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct CompareLeastResultIsSame_impl<T, U, R, std::void_t< CompareLeastResult<T, U> > > : std::is_same<CompareLeastResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct CompareMostResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct CompareMostResultIsSame_impl<T, U, R, std::void_t< CompareMostResult<T, U> > > : std::is_same<CompareMostResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubscriptResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubscriptResultIsSame_impl<T, U, R, std::void_t< SubscriptResult<T, U> > > : std::is_same<SubscriptResult<T, U>, R> {};
		template<class, class, class = std::void_t<>> struct DereferenceResultIsSame_impl : std::false_type {};
		template<class T, class R> struct DereferenceResultIsSame_impl<T, R, std::void_t< DereferenceResult<T> > > : std::is_same<DereferenceResult<T>, R> {};
		template<class, class, class = std::void_t<>> struct ReferenceResultIsSame_impl : std::false_type {};
		template<class T, class R> struct ReferenceResultIsSame_impl<T, R, std::void_t< ReferenceResult<T> > > : std::is_same<ReferenceResult<T>, R> {};
		template<class, class, class, class = std::void_t<>> struct CommaResultIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct CommaResultIsSame_impl<T, U, R, std::void_t< CommaResult<T, U> > > : std::is_same<CommaResult<T, U>, R> {};
	public:
		///	代入演算子 @a T::operator=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_result_is_same = SubstitutionResultIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator+=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_add_result_is_same = SubstitutionAddResultIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator-=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_subtract_result_is_same = SubstitutionSubtractResultIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator*=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_multiply_result_is_same = SubstitutionMultiplyResultIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator/=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_divide_result_is_same = SubstitutionDivideResultIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator%=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_modulate_result_is_same = SubstitutionModulateResultIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator&=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_arithmetic_and_result_is_same = SubstitutionArithmeticAndResultIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator|=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_arithmetic_or_result_is_same = SubstitutionArithmeticOrResultIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator^=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_arithmetic_xor_result_is_same = SubstitutionArithmeticXorResultIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator<<=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_lshift_result_is_same = SubstitutionLShiftResultIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator>>=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_rshift_result_is_same = SubstitutionRShiftResultIsSame_impl<T, U, R>::value;
		///	前置インクリメント演算子 @a T::operator++() の返却値型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool preincrement_result_is_same = PreincrementResultIsSame_impl<T, R>::value;
		///	前置インクリメント演算子 @a T::operator--() の返却値型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool predecrement_result_is_same = PredecrementResultIsSame_impl<T, R>::value;
		///	後置インクリメント演算子 @a T::operator++(int) の返却値型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool postincrement_result_is_same = PostincrementResultIsSame_impl<T, R>::value;
		///	後置インクリメント演算子 @a T::operator--(int) の返却値型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool postdecrement_result_is_same = PostdecrementResultIsSame_impl<T, R>::value;
		///	算術演算子 @a T::operator+() の返却値型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool promotion_result_is_same = PromotionResultIsSame_impl<T, R>::value;
		///	算術演算子 @a T::operator-() の返却値型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool inverse_result_is_same = InverseResultIsSame_impl<T, R>::value;
		///	算術演算子 @a T::operator+(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool addition_result_is_same = AdditionResultIsSame_impl<T, U, R>::value;
		///	算術演算子 @a T::operator-(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool subtraction_result_is_same = SubtractionResultIsSame_impl<T, U, R>::value;
		///	算術演算子 @a T::operator*(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool multiplication_result_is_same = MultiplicationResultIsSame_impl<T, U, R>::value;
		///	算術演算子 @a T::operator/(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool division_result_is_same = DivisionResultIsSame_impl<T, U, R>::value;
		///	算術演算子 @a T::operator%(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool modulation_result_is_same = ModulationResultIsSame_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator~() の返却値型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool arithmetic_not_result_is_same = ArithmeticNotResultIsSame_impl<T, R>::value;
		///	ビット演算子 @a T::operator&(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool arithmetic_and_result_is_same = ArithmeticAndResultIsSame_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator|(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool arithmetic_or_result_is_same = ArithmeticOrResultIsSame_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator^(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool arithmetic_xor_result_is_same = ArithmeticXorResultIsSame_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator<<(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool lshift_result_is_same = LShiftResultIsSame_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator>>(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool rshift_result_is_same = RShiftResultIsSame_impl<T, U, R>::value;
		///	論理演算子 @a T::operator!() の返却値型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool logical_not_result_is_same = LogicalNotResultIsSame_impl<T, R>::value;
		///	論理演算子 @a T::operator||(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool logical_or_result_is_same = LogicalOrResultIsSame_impl<T, U, R>::value;
		///	論理演算子 @a T::operator&&(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool logical_and_result_is_same = LogicalAndResultIsSame_impl<T, U, R>::value;
		///	比較演算子 @a T::operator==(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool equal_result_is_same = EqualResultIsSame_impl<T, U, R>::value;
		///	比較演算子 @a T::operator!=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool not_equal_result_is_same = NotEqualResultIsSame_impl<T, U, R>::value;
		///	比較演算子 @a T::operator>(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool compare_larger_result_is_same = CompareLargerResultIsSame_impl<T, U, R>::value;
		///	比較演算子 @a T::operator<(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool compare_smaller_result_is_same = CompareSmallerResultIsSame_impl<T, U, R>::value;
		///	比較演算子 @a T::operator>=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool compare_least_result_is_same = CompareLeastResultIsSame_impl<T, U, R>::value;
		///	比較演算子 @a T::operator<=(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool compare_most_result_is_same = CompareMostResultIsSame_impl<T, U, R>::value;
		///	添字演算子 @a T::operator[](U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool subscript_result_is_same = SubscriptResultIsSame_impl<T, U, R>::value;
		///	間接参照演算子 @a T::operator*() の返却値型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool dereference_result_is_same = DereferenceResultIsSame_impl<T, R>::value;
		///	アドレス取得演算子 @a T::operator&() の返却値型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool reference_result_is_same = ReferenceResultIsSame_impl<T, R>::value;
		///	カンマ演算子 @a T::operator,(U) の返却値型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool comma_result_is_same = CommaResultIsSame_impl<T, U, R>::value;
	private:
		template<class, class, class, class = std::void_t<>> struct SubstitutionResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionResultIsConvertible_impl<T, U, R, std::void_t< SubstitutionResult<T, U> > > : std::is_convertible<SubstitutionResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionAddResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionAddResultIsConvertible_impl<T, U, R, std::void_t< SubstitutionAddResult<T, U> > > : std::is_convertible<SubstitutionAddResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionSubtractResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionSubtractResultIsConvertible_impl<T, U, R, std::void_t< SubstitutionSubtractResult<T, U> > > : std::is_convertible<SubstitutionSubtractResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionMultiplyResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionMultiplyResultIsConvertible_impl<T, U, R, std::void_t< SubstitutionMultiplyResult<T, U> > > : std::is_convertible<SubstitutionMultiplyResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionDivideResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionDivideResultIsConvertible_impl<T, U, R, std::void_t< SubstitutionDivideResult<T, U> > > : std::is_convertible<SubstitutionDivideResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionModulateResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionModulateResultIsConvertible_impl<T, U, R, std::void_t< SubstitutionModulateResult<T, U> > > : std::is_convertible<SubstitutionModulateResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionArithmeticAndResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionArithmeticAndResultIsConvertible_impl<T, U, R, std::void_t< SubstitutionArithmeticAndResult<T, U> > > : std::is_convertible<SubstitutionArithmeticAndResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionArithmeticOrResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionArithmeticOrResultIsConvertible_impl<T, U, R, std::void_t< SubstitutionArithmeticOrResult<T, U> > > : std::is_convertible<SubstitutionArithmeticOrResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionArithmeticXorResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionArithmeticXorResultIsConvertible_impl<T, U, R, std::void_t< SubstitutionArithmeticXorResult<T, U> > > : std::is_convertible<SubstitutionArithmeticXorResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionLShiftResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionLShiftResultIsConvertible_impl<T, U, R, std::void_t< SubstitutionLShiftResult<T, U> > > : std::is_convertible<SubstitutionLShiftResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionRShiftResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionRShiftResultIsConvertible_impl<T, U, R, std::void_t< SubstitutionRShiftResult<T, U> > > : std::is_convertible<SubstitutionRShiftResult<T, U>, R> {};
		template<class, class, class = std::void_t<>> struct PreincrementResultIsConvertible_impl : std::false_type {};
		template<class T, class R> struct PreincrementResultIsConvertible_impl<T, R, std::void_t< PreincrementResult<T> > > : std::is_convertible<PreincrementResult<T>, R> {};
		#if 201703L <= __cplusplus
		// Clang C++17でコンパイルするとbool::operator++()を実体化しようとしてエラーを吐くため
		// boolによるインクリメントトレイトは強制的にfalseで実体化する
		template<class R> struct PreincrementResultIsConvertible_impl<bool, R> : std::false_type {};
		#endif
		template<class, class, class = std::void_t<>> struct PredecrementResultIsConvertible_impl : std::false_type {};
		template<class T, class R> struct PredecrementResultIsConvertible_impl<T, R, std::void_t< PredecrementResult<T> > > : std::is_convertible<PredecrementResult<T>, R> {};
		template<class, class, class = std::void_t<>> struct PostincrementResultIsConvertible_impl : std::false_type {};
		template<class T, class R> struct PostincrementResultIsConvertible_impl<T, R, std::void_t< PostincrementResult<T> > > : std::is_convertible<PostincrementResult<T>, R> {};
		#if 201703L <= __cplusplus
		// Clang C++17でコンパイルするとbool::operator++(int)を実体化しようとしてエラーを吐くため
		// boolによるインクリメントトレイトは強制的にfalseで実体化する
		template<class R> struct PostincrementResultIsConvertible_impl<bool, R> : std::false_type {};
		#endif
		template<class, class, class = std::void_t<>> struct PostdecrementResultIsConvertible_impl : std::false_type {};
		template<class T, class R> struct PostdecrementResultIsConvertible_impl<T, R, std::void_t< PostdecrementResult<T> > > : std::is_convertible<PostdecrementResult<T>, R> {};
		template<class, class, class = std::void_t<>> struct PromotionResultIsConvertible_impl : std::false_type {};
		template<class T, class R> struct PromotionResultIsConvertible_impl<T, R, std::void_t< PromotionResult<T> > > : std::is_convertible<PromotionResult<T>, R> {};
		template<class, class, class = std::void_t<>> struct InverseResultIsConvertible_impl : std::false_type {};
		template<class T, class R> struct InverseResultIsConvertible_impl<T, R, std::void_t< InverseResult<T> > > : std::is_convertible<InverseResult<T>, R> {};
		template<class, class, class, class = std::void_t<>> struct AdditionResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct AdditionResultIsConvertible_impl<T, U, R, std::void_t< AdditionResult<T, U> > > : std::is_convertible<AdditionResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubtractionResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubtractionResultIsConvertible_impl<T, U, R, std::void_t< SubtractionResult<T, U> > > : std::is_convertible<SubtractionResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct MultiplicationResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct MultiplicationResultIsConvertible_impl<T, U, R, std::void_t< MultiplicationResult<T, U> > > : std::is_convertible<MultiplicationResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct DivisionResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct DivisionResultIsConvertible_impl<T, U, R, std::void_t< DivisionResult<T, U> > > : std::is_convertible<DivisionResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct ModulationResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct ModulationResultIsConvertible_impl<T, U, R, std::void_t< ModulationResult<T, U> > > : std::is_convertible<ModulationResult<T, U>, R> {};
		template<class, class, class = std::void_t<>> struct ArithmeticNotResultIsConvertible_impl : std::false_type {};
		template<class T, class R> struct ArithmeticNotResultIsConvertible_impl<T, R, std::void_t< ArithmeticNotResult<T> > > : std::is_convertible<ArithmeticNotResult<T>, R> {};
		template<class, class, class, class = std::void_t<>> struct ArithmeticAndResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct ArithmeticAndResultIsConvertible_impl<T, U, R, std::void_t< ArithmeticAndResult<T, U> > > : std::is_convertible<ArithmeticAndResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct ArithmeticOrResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct ArithmeticOrResultIsConvertible_impl<T, U, R, std::void_t< ArithmeticOrResult<T, U> > > : std::is_convertible<ArithmeticOrResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct ArithmeticXorResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct ArithmeticXorResultIsConvertible_impl<T, U, R, std::void_t< ArithmeticXorResult<T, U> > > : std::is_convertible<ArithmeticXorResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct LShiftResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct LShiftResultIsConvertible_impl<T, U, R, std::void_t< LShiftResult<T, U> > > : std::is_convertible<LShiftResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct RShiftResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct RShiftResultIsConvertible_impl<T, U, R, std::void_t< RShiftResult<T, U> > > : std::is_convertible<RShiftResult<T, U>, R> {};
		template<class, class, class = std::void_t<>> struct LogicalNotResultIsConvertible_impl : std::false_type {};
		template<class T, class R> struct LogicalNotResultIsConvertible_impl<T, R, std::void_t< LogicalNotResult<T> > > : std::is_convertible<LogicalNotResult<T>, R> {};
		template<class, class, class, class = std::void_t<>> struct LogicalOrResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct LogicalOrResultIsConvertible_impl<T, U, R, std::void_t< LogicalOrResult<T, U> > > : std::is_convertible<LogicalOrResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct LogicalAndResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct LogicalAndResultIsConvertible_impl<T, U, R, std::void_t< LogicalAndResult<T, U> > > : std::is_convertible<LogicalAndResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct EqualResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct EqualResultIsConvertible_impl<T, U, R, std::void_t< EqualResult<T, U> > > : std::is_convertible<EqualResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct NotEqualResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct NotEqualResultIsConvertible_impl<T, U, R, std::void_t< NotEqualResult<T, U> > > : std::is_convertible<NotEqualResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct CompareLargerResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct CompareLargerResultIsConvertible_impl<T, U, R, std::void_t< CompareLargerResult<T, U> > > : std::is_convertible<CompareLargerResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct CompareSmallerResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct CompareSmallerResultIsConvertible_impl<T, U, R, std::void_t< CompareSmallerResult<T, U> > > : std::is_convertible<CompareSmallerResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct CompareLeastResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct CompareLeastResultIsConvertible_impl<T, U, R, std::void_t< CompareLeastResult<T, U> > > : std::is_convertible<CompareLeastResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct CompareMostResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct CompareMostResultIsConvertible_impl<T, U, R, std::void_t< CompareMostResult<T, U> > > : std::is_convertible<CompareMostResult<T, U>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubscriptResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct SubscriptResultIsConvertible_impl<T, U, R, std::void_t< SubscriptResult<T, U> > > : std::is_convertible<SubscriptResult<T, U>, R> {};
		template<class, class, class = std::void_t<>> struct DereferenceResultIsConvertible_impl : std::false_type {};
		template<class T, class R> struct DereferenceResultIsConvertible_impl<T, R, std::void_t< DereferenceResult<T> > > : std::is_convertible<DereferenceResult<T>, R> {};
		template<class, class, class = std::void_t<>> struct ReferenceResultIsConvertible_impl : std::false_type {};
		template<class T, class R> struct ReferenceResultIsConvertible_impl<T, R, std::void_t< ReferenceResult<T> > > : std::is_convertible<ReferenceResult<T>, R> {};
		template<class, class, class, class = std::void_t<>> struct CommaResultIsConvertible_impl : std::false_type {};
		template<class T, class U, class R> struct CommaResultIsConvertible_impl<T, U, R, std::void_t< CommaResult<T, U> > > : std::is_convertible<CommaResult<T, U>, R> {};
	public:
		///	代入演算子 @a T::operator=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool substitution_result_is_convertible = SubstitutionResultIsConvertible_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator+=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool substitution_add_result_is_convertible = SubstitutionAddResultIsConvertible_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator-=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool substitution_subtract_result_is_convertible = SubstitutionSubtractResultIsConvertible_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator*=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool substitution_multiply_result_is_convertible = SubstitutionMultiplyResultIsConvertible_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator/=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool substitution_divide_result_is_convertible = SubstitutionDivideResultIsConvertible_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator%=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool substitution_modulate_result_is_convertible = SubstitutionModulateResultIsConvertible_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator&=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool substitution_arithmetic_and_result_is_convertible = SubstitutionArithmeticAndResultIsConvertible_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator|=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool substitution_arithmetic_or_result_is_convertible = SubstitutionArithmeticOrResultIsConvertible_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator^=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool substitution_arithmetic_xor_result_is_convertible = SubstitutionArithmeticXorResultIsConvertible_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator<<=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool substitution_lshift_result_is_convertible = SubstitutionLShiftResultIsConvertible_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator>>=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool substitution_rshift_result_is_convertible = SubstitutionRShiftResultIsConvertible_impl<T, U, R>::value;
		///	前置インクリメント演算子 @a T::operator++() の返却値型が @a R に変換可能かを識別します
		template<class T, class R> static constexpr bool preincrement_result_is_convertible = PreincrementResultIsConvertible_impl<T, R>::value;
		///	前置インクリメント演算子 @a T::operator--() の返却値型が @a R に変換可能かを識別します
		template<class T, class R> static constexpr bool predecrement_result_is_convertible = PredecrementResultIsConvertible_impl<T, R>::value;
		///	後置インクリメント演算子 @a T::operator++(int) の返却値型が @a R に変換可能かを識別します
		template<class T, class R> static constexpr bool postincrement_result_is_convertible = PostincrementResultIsConvertible_impl<T, R>::value;
		///	後置インクリメント演算子 @a T::operator--(int) の返却値型が @a R に変換可能かを識別します
		template<class T, class R> static constexpr bool postdecrement_result_is_convertible = PostdecrementResultIsConvertible_impl<T, R>::value;
		///	算術演算子 @a T::operator+() の返却値型が @a R に変換可能かを識別します
		template<class T, class R> static constexpr bool promotion_result_is_convertible = PromotionResultIsConvertible_impl<T, R>::value;
		///	算術演算子 @a T::operator-() の返却値型が @a R に変換可能かを識別します
		template<class T, class R> static constexpr bool inverse_result_is_convertible = InverseResultIsConvertible_impl<T, R>::value;
		///	算術演算子 @a T::operator+(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool addition_result_is_convertible = AdditionResultIsConvertible_impl<T, U, R>::value;
		///	算術演算子 @a T::operator-(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool subtraction_result_is_convertible = SubtractionResultIsConvertible_impl<T, U, R>::value;
		///	算術演算子 @a T::operator*(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool multiplication_result_is_convertible = MultiplicationResultIsConvertible_impl<T, U, R>::value;
		///	算術演算子 @a T::operator/(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool division_result_is_convertible = DivisionResultIsConvertible_impl<T, U, R>::value;
		///	算術演算子 @a T::operator%(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool modulation_result_is_convertible = ModulationResultIsConvertible_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator~() の返却値型が @a R に変換可能かを識別します
		template<class T, class R> static constexpr bool arithmetic_not_result_is_convertible = ArithmeticNotResultIsConvertible_impl<T, R>::value;
		///	ビット演算子 @a T::operator&(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool arithmetic_and_result_is_convertible = ArithmeticAndResultIsConvertible_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator|(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool arithmetic_or_result_is_convertible = ArithmeticOrResultIsConvertible_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator^(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool arithmetic_xor_result_is_convertible = ArithmeticXorResultIsConvertible_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator<<(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool lshift_result_is_convertible = LShiftResultIsConvertible_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator>>(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool rshift_result_is_convertible = RShiftResultIsConvertible_impl<T, U, R>::value;
		///	論理演算子 @a T::operator!() の返却値型が @a R に変換可能かを識別します
		template<class T, class R> static constexpr bool logical_not_result_is_convertible = LogicalNotResultIsConvertible_impl<T, R>::value;
		///	論理演算子 @a T::operator||(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool logical_or_result_is_convertible = LogicalOrResultIsConvertible_impl<T, U, R>::value;
		///	論理演算子 @a T::operator&&(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool logical_and_result_is_convertible = LogicalAndResultIsConvertible_impl<T, U, R>::value;
		///	比較演算子 @a T::operator==(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool equal_result_is_convertible = EqualResultIsConvertible_impl<T, U, R>::value;
		///	比較演算子 @a T::operator!=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool not_equal_result_is_convertible = NotEqualResultIsConvertible_impl<T, U, R>::value;
		///	比較演算子 @a T::operator>(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool compare_larger_result_is_convertible = CompareLargerResultIsConvertible_impl<T, U, R>::value;
		///	比較演算子 @a T::operator<(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool compare_smaller_result_is_convertible = CompareSmallerResultIsConvertible_impl<T, U, R>::value;
		///	比較演算子 @a T::operator>=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool compare_least_result_is_convertible = CompareLeastResultIsConvertible_impl<T, U, R>::value;
		///	比較演算子 @a T::operator<=(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool compare_most_result_is_convertible = CompareMostResultIsConvertible_impl<T, U, R>::value;
		///	添字演算子 @a T::operator[](U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool subscript_result_is_convertible = SubscriptResultIsConvertible_impl<T, U, R>::value;
		///	間接参照演算子 @a T::operator*() の返却値型が @a R に変換可能かを識別します
		template<class T, class R> static constexpr bool dereference_result_is_convertible = DereferenceResultIsConvertible_impl<T, R>::value;
		///	アドレス取得演算子 @a T::operator&() の返却値型が @a R に変換可能かを識別します
		template<class T, class R> static constexpr bool reference_result_is_convertible = ReferenceResultIsConvertible_impl<T, R>::value;
		///	カンマ演算子 @a T::operator,(U) の返却値型が @a R に変換可能かを識別します
		template<class T, class U, class R> static constexpr bool comma_result_is_convertible = CommaResultIsConvertible_impl<T, U, R>::value;
	private:
		template<class, class, class, class = std::void_t<>> struct SubstitutionResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubstitutionResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubstitutionResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionAddResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionAddResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubstitutionAddResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubstitutionAddResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionSubtractResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionSubtractResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubstitutionSubtractResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubstitutionSubtractResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionMultiplyResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionMultiplyResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubstitutionMultiplyResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubstitutionMultiplyResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionDivideResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionDivideResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubstitutionDivideResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubstitutionDivideResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionModulateResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionModulateResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubstitutionModulateResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubstitutionModulateResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionArithmeticAndResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionArithmeticAndResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubstitutionArithmeticAndResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubstitutionArithmeticAndResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionArithmeticOrResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionArithmeticOrResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubstitutionArithmeticOrResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubstitutionArithmeticOrResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionArithmeticXorResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionArithmeticXorResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubstitutionArithmeticXorResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubstitutionArithmeticXorResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionLShiftResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionLShiftResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubstitutionLShiftResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubstitutionLShiftResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubstitutionRShiftResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubstitutionRShiftResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubstitutionRShiftResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubstitutionRShiftResult<T, U>>>, R> {};
		template<class, class, class = std::void_t<>> struct PreincrementResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class R> struct PreincrementResultRemoveCVRefIsSame_impl<T, R, std::void_t< PreincrementResult<T> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<PreincrementResult<T>>>, R> {};
		#if 201703L <= __cplusplus
		// Clang C++17でコンパイルするとbool::operator++()を実体化しようとしてエラーを吐くため
		// boolによるインクリメントトレイトは強制的にfalseで実体化する
		template<class R> struct PreincrementResultRemoveCVRefIsSame_impl<bool, R> : std::false_type {};
		#endif
		template<class, class, class = std::void_t<>> struct PredecrementResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class R> struct PredecrementResultRemoveCVRefIsSame_impl<T, R, std::void_t< PredecrementResult<T> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<PredecrementResult<T>>>, R> {};
		template<class, class, class = std::void_t<>> struct PostincrementResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class R> struct PostincrementResultRemoveCVRefIsSame_impl<T, R, std::void_t< PostincrementResult<T> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<PostincrementResult<T>>>, R> {};
		#if 201703L <= __cplusplus
		// Clang C++17でコンパイルするとbool::operator++(int)を実体化しようとしてエラーを吐くため
		// boolによるインクリメントトレイトは強制的にfalseで実体化する
		template<class R> struct PostincrementResultRemoveCVRefIsSame_impl<bool, R> : std::false_type {};
		#endif
		template<class, class, class = std::void_t<>> struct PostdecrementResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class R> struct PostdecrementResultRemoveCVRefIsSame_impl<T, R, std::void_t< PostdecrementResult<T> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<PostdecrementResult<T>>>, R> {};
		template<class, class, class = std::void_t<>> struct PromotionResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class R> struct PromotionResultRemoveCVRefIsSame_impl<T, R, std::void_t< PromotionResult<T> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<PromotionResult<T>>>, R> {};
		template<class, class, class = std::void_t<>> struct InverseResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class R> struct InverseResultRemoveCVRefIsSame_impl<T, R, std::void_t< InverseResult<T> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<InverseResult<T>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct AdditionResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct AdditionResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< AdditionResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<AdditionResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubtractionResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubtractionResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubtractionResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubtractionResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct MultiplicationResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct MultiplicationResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< MultiplicationResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<MultiplicationResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct DivisionResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct DivisionResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< DivisionResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<DivisionResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct ModulationResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct ModulationResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< ModulationResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<ModulationResult<T, U>>>, R> {};
		template<class, class, class = std::void_t<>> struct ArithmeticNotResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class R> struct ArithmeticNotResultRemoveCVRefIsSame_impl<T, R, std::void_t< ArithmeticNotResult<T> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<ArithmeticNotResult<T>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct ArithmeticAndResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct ArithmeticAndResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< ArithmeticAndResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<ArithmeticAndResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct ArithmeticOrResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct ArithmeticOrResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< ArithmeticOrResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<ArithmeticOrResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct ArithmeticXorResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct ArithmeticXorResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< ArithmeticXorResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<ArithmeticXorResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct LShiftResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct LShiftResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< LShiftResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<LShiftResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct RShiftResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct RShiftResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< RShiftResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<RShiftResult<T, U>>>, R> {};
		template<class, class, class = std::void_t<>> struct LogicalNotResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class R> struct LogicalNotResultRemoveCVRefIsSame_impl<T, R, std::void_t< LogicalNotResult<T> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<LogicalNotResult<T>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct LogicalOrResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct LogicalOrResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< LogicalOrResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<LogicalOrResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct LogicalAndResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct LogicalAndResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< LogicalAndResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<LogicalAndResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct EqualResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct EqualResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< EqualResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<EqualResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct NotEqualResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct NotEqualResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< NotEqualResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<NotEqualResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct LargerCompareResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct LargerCompareResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< CompareLargerResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<CompareLargerResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SmallerCompareResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SmallerCompareResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< CompareSmallerResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<CompareSmallerResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct LeastCompareResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct LeastCompareResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< CompareLeastResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<CompareLeastResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct MostCompareResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct MostCompareResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< CompareMostResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<CompareMostResult<T, U>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct SubscriptResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct SubscriptResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< SubscriptResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<SubscriptResult<T, U>>>, R> {};
		template<class, class, class = std::void_t<>> struct DereferenceResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class R> struct DereferenceResultRemoveCVRefIsSame_impl<T, R, std::void_t< DereferenceResult<T> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<DereferenceResult<T>>>, R> {};
		template<class, class, class = std::void_t<>> struct ReferenceResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class R> struct ReferenceResultRemoveCVRefIsSame_impl<T, R, std::void_t< ReferenceResult<T> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<ReferenceResult<T>>>, R> {};
		template<class, class, class, class = std::void_t<>> struct CommaResultRemoveCVRefIsSame_impl : std::false_type {};
		template<class T, class U, class R> struct CommaResultRemoveCVRefIsSame_impl<T, U, R, std::void_t< CommaResult<T, U> > > : std::is_same<std::remove_cv_t<std::remove_reference_t<CommaResult<T, U>>>, R> {};
	public:
		///	代入演算子 @a T::operator=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_result_remove_cvref_is_same = SubstitutionResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator+=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_add_result_remove_cvref_is_same = SubstitutionAddResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator-=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_subtract_result_remove_cvref_is_same = SubstitutionSubtractResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator*=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_multiply_result_remove_cvref_is_same = SubstitutionMultiplyResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator/=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_divide_result_remove_cvref_is_same = SubstitutionDivideResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator%=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_modulate_result_remove_cvref_is_same = SubstitutionModulateResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator&=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_arithmetic_and_result_remove_cvref_is_same = SubstitutionArithmeticAndResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator|=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_arithmetic_or_result_remove_cvref_is_same = SubstitutionArithmeticOrResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator^=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_arithmetic_xor_result_remove_cvref_is_same = SubstitutionArithmeticXorResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator<<=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_lshift_result_remove_cvref_is_same = SubstitutionLShiftResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	複合代入演算子 @a T::operator>>=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool substitution_rshift_result_remove_cvref_is_same = SubstitutionRShiftResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	前置インクリメント演算子 @a T::operator++() の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool preincrement_result_remove_cvref_is_same = PreincrementResultRemoveCVRefIsSame_impl<T, R>::value;
		///	前置インクリメント演算子 @a T::operator--() の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool predecrement_result_remove_cvref_is_same = PredecrementResultRemoveCVRefIsSame_impl<T, R>::value;
		///	後置インクリメント演算子 @a T::operator++(int) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool postincrement_result_remove_cvref_is_same = PostincrementResultRemoveCVRefIsSame_impl<T, R>::value;
		///	後置インクリメント演算子 @a T::operator--(int) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool postdecrement_result_remove_cvref_is_same = PostdecrementResultRemoveCVRefIsSame_impl<T, R>::value;
		///	算術演算子 @a T::operator+() の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool promotion_result_remove_cvref_is_same = PromotionResultRemoveCVRefIsSame_impl<T, R>::value;
		///	算術演算子 @a T::operator-() の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool inverse_result_remove_cvref_is_same = InverseResultRemoveCVRefIsSame_impl<T, R>::value;
		///	算術演算子 @a T::operator+(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool addition_result_remove_cvref_is_same = AdditionResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	算術演算子 @a T::operator-(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool subtraction_result_remove_cvref_is_same = SubtractionResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	算術演算子 @a T::operator*(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool multiplication_result_remove_cvref_is_same = MultiplicationResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	算術演算子 @a T::operator/(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool division_result_remove_cvref_is_same = DivisionResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	算術演算子 @a T::operator%(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool modulation_result_remove_cvref_is_same = ModulationResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator~() の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool arithmetic_not_result_remove_cvref_is_same = ArithmeticNotResultRemoveCVRefIsSame_impl<T, R>::value;
		///	ビット演算子 @a T::operator&(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool arithmetic_and_result_remove_cvref_is_same = ArithmeticAndResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator|(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool arithmetic_or_result_remove_cvref_is_same = ArithmeticOrResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator^(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool arithmetic_xor_result_remove_cvref_is_same = ArithmeticXorResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator<<(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool lshift_result_remove_cvref_is_same = LShiftResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	ビット演算子 @a T::operator>>(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool rshift_result_remove_cvref_is_same = RShiftResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	論理演算子 @a T::operator!() の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool logical_not_result_remove_cvref_is_same = LogicalNotResultRemoveCVRefIsSame_impl<T, R>::value;
		///	論理演算子 @a T::operator||(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool logical_or_result_remove_cvref_is_same = LogicalOrResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	論理演算子 @a T::operator&&(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool logical_and_result_remove_cvref_is_same = LogicalAndResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	比較演算子 @a T::operator==(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool equal_result_remove_cvref_is_same = EqualResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	比較演算子 @a T::operator!=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool not_equal_result_remove_cvref_is_same = NotEqualResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	比較演算子 @a T::operator>(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool compare_larger_result_remove_cvref_is_same = LargerCompareResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	比較演算子 @a T::operator<(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool compare_smaller_result_remove_cvref_is_same = SmallerCompareResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	比較演算子 @a T::operator>=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool compare_least_result_remove_cvref_is_same = LeastCompareResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	比較演算子 @a T::operator<=(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool compare_most_result_remove_cvref_is_same = MostCompareResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	添字演算子 @a T::operator[](U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool subscript_result_remove_cvref_is_same = SubscriptResultRemoveCVRefIsSame_impl<T, U, R>::value;
		///	間接参照演算子 @a T::operator*() の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool dereference_result_remove_cvref_is_same = DereferenceResultRemoveCVRefIsSame_impl<T, R>::value;
		///	アドレス取得演算子 @a T::operator&() の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class R> static constexpr bool reference_result_remove_cvref_is_same = ReferenceResultRemoveCVRefIsSame_impl<T, R>::value;
		///	カンマ演算子 @a T::operator,(U) の返却値(CVRef除去)型が @a R に一致するかを識別します
		template<class T, class U, class R> static constexpr bool comma_result_remove_cvref_is_same = CommaResultRemoveCVRefIsSame_impl<T, U, R>::value;
	private:
		template<class, class, class = std::void_t<>>
		struct HasArrowOverload_impl : std::false_type {};
		template<class T, class R>
		struct HasArrowOverload_impl<T, R, std::void_t< decltype( std::declval<T&>().operator->() ) > >
			: std::is_convertible< decltype( std::declval<T&>().operator->() ), R> {};
		template<class, class, class = std::void_t<>>
		struct HasArrowDereferenceOverload_impl : std::false_type {};
		template<class T, class R>
		struct HasArrowDereferenceOverload_impl<T, R, std::void_t< decltype( std::declval<T&>().operator->*() ) > >
			: std::is_convertible< decltype( std::declval<T&>().operator->*() ), R> {};
	public:
		///	アロー演算子 @a -> のオーバーロード実装を識別します
		template<class T, class R = T*> inline constexpr static bool has_arrow = HasArrowOverload_impl<T, R>::value;
		///	アロー間接参照演算子 @a ->* のオーバーロード実装を識別します
		template<class T, class R> inline constexpr static bool has_arrow_dereference = HasArrowDereferenceOverload_impl<T, R>::value;
	private:
		struct do_Aggrigation_t
		{
			template<class T, class... Targs, typename = decltype( T{ ( std::declval<Targs&>() )... } )>
			static std::true_type do_Aggrigation(int);
			template<class T, class... Targs>
			static std::false_type do_Aggrigation(...);
		};
		template<class T, class... Targs>
		struct Aggregatable_impl : public do_Aggrigation_t
		{
			typedef decltype(do_Aggrigation<T, Targs ...>(0)) type;
		};
		template<class T, class... Targs>
		struct IsAggregatable_t : public Aggregatable_impl<T, Targs ...>::type {};
	public:
		///	指定された型の波括弧による初期化が可能な型を識別します
		template<class T, class... Targs> inline constexpr static bool is_aggregatable = IsAggregatable_t<T, Targs...>::value;

		///	代入演算 @a T::operator=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionResult<T, U> substitution(T& left, const U& right) { static_assert(has_substitution<T, U>, "この型は代入演算をサポートしません"); return left = right; }
		///	代入演算 @a T::operator=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionResult<T, U> substitution(T& left, U& right) { static_assert(has_substitution<T, U>, "この型は代入演算をサポートしません"); return left = right; }
		///	代入演算 @a T::operator=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionResult<T, U> substitution(T& left, U&& right) { static_assert(has_substitution<T, U>, "この型は代入演算をサポートしません"); return left = right; }
		///	加算複合代入演算 @a T::operator+=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionAddResult<T, U> substitution_add(T& left, const U& right) { static_assert(has_substitution_add<T, U>, "この型は加算複合代入演算をサポートしません"); return left += right; }
		///	加算複合代入演算 @a T::operator+=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionAddResult<T, U> substitution_add(T& left, U& right) { static_assert(has_substitution_add<T, U>, "この型は加算複合代入演算をサポートしません"); return left += right; }
		///	加算複合代入演算 @a T::operator+=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionAddResult<T, U> substitution_add(T& left, U&& right) { static_assert(has_substitution_add<T, U>, "この型は加算複合代入演算をサポートしません"); return left += right; }
		///	減算複合代入演算 @a T::operator-=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionSubtractResult<T, U> substitution_subtract(T& left, const U& right) { static_assert(has_substitution_subtract<T, U>, "この型は減算複合代入演算をサポートしません"); return left -= right; }
		///	減算複合代入演算 @a T::operator-=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionSubtractResult<T, U> substitution_subtract(T& left, U& right) { static_assert(has_substitution_subtract<T, U>, "この型は減算複合代入演算をサポートしません"); return left -= right; }
		///	減算複合代入演算 @a T::operator-=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionSubtractResult<T, U> substitution_subtract(T& left, U&& right) { static_assert(has_substitution_subtract<T, U>, "この型は減算複合代入演算をサポートしません"); return left -= right; }
		///	乗算複合代入演算 @a T::operator*=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionMultiplyResult<T, U> substitution_multiply(T& left, const U& right) { static_assert(has_substitution_multiply<T, U>, "この型は乗算複合代入演算をサポートしません"); return left *= right; }
		///	乗算複合代入演算 @a T::operator*=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionMultiplyResult<T, U> substitution_multiply(T& left, U& right) { static_assert(has_substitution_multiply<T, U>, "この型は乗算複合代入演算をサポートしません"); return left *= right; }
		///	乗算複合代入演算 @a T::operator*=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionMultiplyResult<T, U> substitution_multiply(T& left, U&& right) { static_assert(has_substitution_multiply<T, U>, "この型は乗算複合代入演算をサポートしません"); return left *= right; }
		///	除算複合代入演算 @a T::operator/=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionDivideResult<T, U> substitution_divide(T& left, const U& right) { static_assert(has_substitution_divide<T, U>, "この型は除算複合代入演算をサポートしません"); return left /= right; }
		///	除算複合代入演算 @a T::operator/=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionDivideResult<T, U> substitution_divide(T& left, U& right) { static_assert(has_substitution_divide<T, U>, "この型は除算複合代入演算をサポートしません"); return left /= right; }
		///	除算複合代入演算 @a T::operator/=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionDivideResult<T, U> substitution_divide(T& left, U&& right) { static_assert(has_substitution_divide<T, U>, "この型は除算複合代入演算をサポートしません"); return left /= right; }
		///	剰余複合代入演算 @a T::operator%=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionModulateResult<T, U> substitution_modulate(T& left, const U& right) { static_assert(has_substitution_modulate<T, U>, "この型は剰余複合代入演算をサポートしません"); return left %= right; }
		///	剰余複合代入演算 @a T::operator%=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionModulateResult<T, U> substitution_modulate(T& left, U& right) { static_assert(has_substitution_modulate<T, U>, "この型は剰余複合代入演算をサポートしません"); return left %= right; }
		///	剰余複合代入演算 @a T::operator%=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionModulateResult<T, U> substitution_modulate(T& left, U&& right) { static_assert(has_substitution_modulate<T, U>, "この型は剰余複合代入演算をサポートしません"); return left %= right; }
		///	ビットAND複合代入演算 @a T::operator&=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionArithmeticAndResult<T, U> substitution_arithmetic_and(T& left, const U& right) { static_assert(has_substitution_arithmetic_and<T, U>, "この型はビットAND複合代入演算をサポートしません"); return left &= right; }
		///	ビットAND複合代入演算 @a T::operator&=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionArithmeticAndResult<T, U> substitution_arithmetic_and(T& left, U& right) { static_assert(has_substitution_arithmetic_and<T, U>, "この型はビットAND複合代入演算をサポートしません"); return left &= right; }
		///	ビットAND複合代入演算 @a T::operator&=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionArithmeticAndResult<T, U> substitution_arithmetic_and(T& left, U&& right) { static_assert(has_substitution_arithmetic_and<T, U>, "この型はビットAND複合代入演算をサポートしません"); return left &= right; }
		///	ビットOR複合代入演算 @a T::operator|=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionArithmeticOrResult<T, U> substitution_arithmetic_or(T& left, const U& right) { static_assert(has_substitution_arithmetic_or<T, U>, "この型はビットOR複合代入演算をサポートしません"); return left |= right; }
		///	ビットOR複合代入演算 @a T::operator|=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionArithmeticOrResult<T, U> substitution_arithmetic_or(T& left, U& right) { static_assert(has_substitution_arithmetic_or<T, U>, "この型はビットOR複合代入演算をサポートしません"); return left |= right; }
		///	ビットOR複合代入演算 @a T::operator|=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionArithmeticOrResult<T, U> substitution_arithmetic_or(T& left, U&& right) { static_assert(has_substitution_arithmetic_or<T, U>, "この型はビットOR複合代入演算をサポートしません"); return left |= right; }
		///	ビットXOR複合代入演算 @a T::operator^=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionArithmeticXorResult<T, U> substitution_arithmetic_xor(T& left, const U& right) { static_assert(has_substitution_arithmetic_xor<T, U>, "この型はビットXOR複合代入演算をサポートしません"); return left ^= right; }
		///	ビットXOR複合代入演算 @a T::operator^=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionArithmeticXorResult<T, U> substitution_arithmetic_xor(T& left, U& right) { static_assert(has_substitution_arithmetic_xor<T, U>, "この型はビットXOR複合代入演算をサポートしません"); return left ^= right; }
		///	ビットXOR複合代入演算 @a T::operator^=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionArithmeticXorResult<T, U> substitution_arithmetic_xor(T& left, U&& right) { static_assert(has_substitution_arithmetic_xor<T, U>, "この型はビットXOR複合代入演算をサポートしません"); return left ^= right; }
		///	ビット左シフト複合代入演算 @a T::operator<<=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionLShiftResult<T, U> substitution_lshift(T& left, const U& right) { static_assert(has_substitution_lshift<T, U>, "この型はビット左シフト複合代入演算をサポートしません"); return left <<= right; }
		///	ビット左シフト複合代入演算 @a T::operator<<=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionLShiftResult<T, U> substitution_lshift(T& left, U& right) { static_assert(has_substitution_lshift<T, U>, "この型はビット左シフト複合代入演算をサポートしません"); return left <<= right; }
		///	ビット左シフト複合代入演算 @a T::operator<<=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionLShiftResult<T, U> substitution_lshift(T& left, U&& right) { static_assert(has_substitution_lshift<T, U>, "この型はビット左シフト複合代入演算をサポートしません"); return left <<= right; }
		///	ビット右シフト複合代入演算 @a T::operator>>=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionRShiftResult<T, U> substitution_rshift(T& left, const U& right) { static_assert(has_substitution_rshift<T, U>, "この型はビット右シフト複合代入演算をサポートしません"); return left >>= right; }
		///	ビット右シフト複合代入演算 @a T::operator>>=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionRShiftResult<T, U> substitution_rshift(T& left, U& right) { static_assert(has_substitution_rshift<T, U>, "この型はビット右シフト複合代入演算をサポートしません"); return left >>= right; }
		///	ビット右シフト複合代入演算 @a T::operator>>=(U) を行います。
		template<typename T, typename U> static constexpr SubstitutionRShiftResult<T, U> substitution_rshift(T& left, U&& right) { static_assert(has_substitution_rshift<T, U>, "この型はビット右シフト複合代入演算をサポートしません"); return left >>= right; }
		///	前置インクリメント演算 @a T::operator++() を行います。
		template<typename T> static constexpr PreincrementResult<T> preincrement(T& value) { static_assert(has_preincrement<T>, "この型は前置インクリメント演算をサポートしません"); return ++value; }
		///	前置デクリメント演算 @a T::operator--() を行います。
		template<typename T> static constexpr PredecrementResult<T> predecrement(T& value) { static_assert(has_predecrement<T>, "この型は前置デクリメント演算をサポートしません"); return --value; }
		///	後置インクリメント演算 @a T::operator++(int) を行います。
		template<typename T> static constexpr PostincrementResult<T> postincrement(T& value) { static_assert(has_postincrement<T>, "この型は後置インクリメント演算をサポートしません"); return value++; }
		///	後置デクリメント演算 @a T::operator--(int) を行います。
		template<typename T> static constexpr PostdecrementResult<T> postdecrement(T& value) { static_assert(has_postdecrement<T>, "この型は後置デクリメント演算をサポートしません"); return value--; }
		///	昇格演算 @a T::operator+() を行います。
		template<typename T> static constexpr PromotionResult<T> promotion(T& value) { static_assert(has_promotion<T>, "この型は昇格演算をサポートしません"); return +value; }
		///	昇格演算 @a T::operator+() を行います。
		template<typename T> static constexpr PromotionResult<T> promotion(const T& value) { static_assert(has_promotion<T>, "この型は昇格演算をサポートしません"); return +value; }
		///	反数演算 @a T::operator-() を行います。
		template<typename T> static constexpr InverseResult<T> inverse(T& value) { static_assert(has_inverse<T>, "この型は反数演算をサポートしません"); return -value; }
		///	反数演算 @a T::operator-() を行います。
		template<typename T> static constexpr InverseResult<T> inverse(const T& value) { static_assert(has_inverse<T>, "この型は反数演算をサポートしません"); return -value; }
		///	算術加算 @a T::operator+(U) を行います。
		template<typename T, typename U> static constexpr AdditionResult<T, U> addition(const T& left, const U& right) { static_assert(has_addition<T, U>, "この型は算術加算をサポートしません"); return left + right; }
		///	算術加算 @a T::operator+(U) を行います。
		template<typename T, typename U> static constexpr AdditionResult<T, U> addition(const T& left, U& right) { static_assert(has_addition<T, U>, "この型は算術加算をサポートしません"); return left + right; }
		///	算術加算 @a T::operator+(U) を行います。
		template<typename T, typename U> static constexpr AdditionResult<T, U> addition(const T& left, U&& right) { static_assert(has_addition<T, U>, "この型は算術加算をサポートしません"); return left + right; }
		///	算術加算 @a T::operator+(U) を行います。
		template<typename T, typename U> static constexpr AdditionResult<T, U> addition(T& left, const U& right) { static_assert(has_addition<T, U>, "この型は算術加算をサポートしません"); return left + right; }
		///	算術加算 @a T::operator+(U) を行います。
		template<typename T, typename U> static constexpr AdditionResult<T, U> addition(T& left, U& right) { static_assert(has_addition<T, U>, "この型は算術加算をサポートしません"); return left + right; }
		///	算術加算 @a T::operator+(U) を行います。
		template<typename T, typename U> static constexpr AdditionResult<T, U> addition(T& left, U&& right) { static_assert(has_addition<T, U>, "この型は算術加算をサポートしません"); return left + right; }
		///	算術減算 @a T::operator-(U) を行います。
		template<typename T, typename U> static constexpr SubtractionResult<T, U> subtraction(const T& left, const U& right) { static_assert(has_subtraction<T, U>, "この型は算術減算をサポートしません"); return left - right; }
		///	算術減算 @a T::operator-(U) を行います。
		template<typename T, typename U> static constexpr SubtractionResult<T, U> subtraction(const T& left, U& right) { static_assert(has_subtraction<T, U>, "この型は算術減算をサポートしません"); return left - right; }
		///	算術減算 @a T::operator-(U) を行います。
		template<typename T, typename U> static constexpr SubtractionResult<T, U> subtraction(const T& left, U&& right) { static_assert(has_subtraction<T, U>, "この型は算術減算をサポートしません"); return left - right; }
		///	算術減算 @a T::operator-(U) を行います。
		template<typename T, typename U> static constexpr SubtractionResult<T, U> subtraction(T& left, const U& right) { static_assert(has_subtraction<T, U>, "この型は算術減算をサポートしません"); return left - right; }
		///	算術減算 @a T::operator-(U) を行います。
		template<typename T, typename U> static constexpr SubtractionResult<T, U> subtraction(T& left, U& right) { static_assert(has_subtraction<T, U>, "この型は算術減算をサポートしません"); return left - right; }
		///	算術減算 @a T::operator-(U) を行います。
		template<typename T, typename U> static constexpr SubtractionResult<T, U> subtraction(T& left, U&& right) { static_assert(has_subtraction<T, U>, "この型は算術減算をサポートしません"); return left - right; }
		///	算術乗算 @a T::operator*(U) を行います。
		template<typename T, typename U> static constexpr MultiplicationResult<T, U> multiplication(const T& left, const U& right) { static_assert(has_multiplication<T, U>, "この型は算術乗算をサポートしません"); return left * right; }
		///	算術乗算 @a T::operator*(U) を行います。
		template<typename T, typename U> static constexpr MultiplicationResult<T, U> multiplication(const T& left, U& right) { static_assert(has_multiplication<T, U>, "この型は算術乗算をサポートしません"); return left * right; }
		///	算術乗算 @a T::operator*(U) を行います。
		template<typename T, typename U> static constexpr MultiplicationResult<T, U> multiplication(const T& left, U&& right) { static_assert(has_multiplication<T, U>, "この型は算術乗算をサポートしません"); return left * right; }
		///	算術乗算 @a T::operator*(U) を行います。
		template<typename T, typename U> static constexpr MultiplicationResult<T, U> multiplication(T& left, const U& right) { static_assert(has_multiplication<T, U>, "この型は算術乗算をサポートしません"); return left * right; }
		///	算術乗算 @a T::operator*(U) を行います。
		template<typename T, typename U> static constexpr MultiplicationResult<T, U> multiplication(T& left, U& right) { static_assert(has_multiplication<T, U>, "この型は算術乗算をサポートしません"); return left * right; }
		///	算術乗算 @a T::operator*(U) を行います。
		template<typename T, typename U> static constexpr MultiplicationResult<T, U> multiplication(T& left, U&& right) { static_assert(has_multiplication<T, U>, "この型は算術乗算をサポートしません"); return left * right; }
		///	算術除算 @a T::operator/(U) を行います。
		template<typename T, typename U> static constexpr DivisionResult<T, U> division(const T& left, const U& right) { static_assert(has_division<T, U>, "この型は算術除算をサポートしません"); return left / right; }
		///	算術除算 @a T::operator/(U) を行います。
		template<typename T, typename U> static constexpr DivisionResult<T, U> division(const T& left, U& right) { static_assert(has_division<T, U>, "この型は算術除算をサポートしません"); return left / right; }
		///	算術除算 @a T::operator/(U) を行います。
		template<typename T, typename U> static constexpr DivisionResult<T, U> division(const T& left, U&& right) { static_assert(has_division<T, U>, "この型は算術除算をサポートしません"); return left / right; }
		///	算術除算 @a T::operator/(U) を行います。
		template<typename T, typename U> static constexpr DivisionResult<T, U> division(T& left, const U& right) { static_assert(has_division<T, U>, "この型は算術除算をサポートしません"); return left / right; }
		///	算術除算 @a T::operator/(U) を行います。
		template<typename T, typename U> static constexpr DivisionResult<T, U> division(T& left, U& right) { static_assert(has_division<T, U>, "この型は算術除算をサポートしません"); return left / right; }
		///	算術除算 @a T::operator/(U) を行います。
		template<typename T, typename U> static constexpr DivisionResult<T, U> division(T& left, U&& right) { static_assert(has_division<T, U>, "この型は算術除算をサポートしません"); return left / right; }
		///	剰余演算 @a T::operator%(U) を行います。
		template<typename T, typename U> static constexpr ModulationResult<T, U> modulation(const T& left, const U& right) { static_assert(has_modulation<T, U>, "この型は剰余演算をサポートしません"); return left % right; }
		///	剰余演算 @a T::operator%(U) を行います。
		template<typename T, typename U> static constexpr ModulationResult<T, U> modulation(const T& left, U& right) { static_assert(has_modulation<T, U>, "この型は剰余演算をサポートしません"); return left % right; }
		///	剰余演算 @a T::operator%(U) を行います。
		template<typename T, typename U> static constexpr ModulationResult<T, U> modulation(const T& left, U&& right) { static_assert(has_modulation<T, U>, "この型は剰余演算をサポートしません"); return left % right; }
		///	剰余演算 @a T::operator%(U) を行います。
		template<typename T, typename U> static constexpr ModulationResult<T, U> modulation(T& left, const U& right) { static_assert(has_modulation<T, U>, "この型は剰余演算をサポートしません"); return left % right; }
		///	剰余演算 @a T::operator%(U) を行います。
		template<typename T, typename U> static constexpr ModulationResult<T, U> modulation(T& left, U& right) { static_assert(has_modulation<T, U>, "この型は剰余演算をサポートしません"); return left % right; }
		///	剰余演算 @a T::operator%(U) を行います。
		template<typename T, typename U> static constexpr ModulationResult<T, U> modulation(T& left, U&& right) { static_assert(has_modulation<T, U>, "この型は剰余演算をサポートしません"); return left % right; }
		///	ビットNOT演算 @a T::operator~() を行います。
		template<typename T> static constexpr ArithmeticNotResult<T> arithmetic_not(const T& value) { static_assert(has_arithmetic_not<T>, "この型はビットNOT演算をサポートしません"); return ~value; }
		///	ビットNOT演算 @a T::operator~() を行います。
		template<typename T> static constexpr ArithmeticNotResult<T> arithmetic_not(T& value) { static_assert(has_arithmetic_not<T>, "この型はビットNOT演算をサポートしません"); return ~value; }
		///	ビットAND演算 @a T::operator&(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticAndResult<T, U> arithmetic_and(const T& left, const U& right) { static_assert(has_arithmetic_and<T, U>, "この型はビットAND演算をサポートしません"); return left & right; }
		///	ビットAND演算 @a T::operator&(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticAndResult<T, U> arithmetic_and(const T& left, U& right) { static_assert(has_arithmetic_and<T, U>, "この型はビットAND演算をサポートしません"); return left & right; }
		///	ビットAND演算 @a T::operator&(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticAndResult<T, U> arithmetic_and(const T& left, U&& right) { static_assert(has_arithmetic_and<T, U>, "この型はビットAND演算をサポートしません"); return left & right; }
		///	ビットAND演算 @a T::operator&(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticAndResult<T, U> arithmetic_and(T& left, const U& right) { static_assert(has_arithmetic_and<T, U>, "この型はビットAND演算をサポートしません"); return left & right; }
		///	ビットAND演算 @a T::operator&(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticAndResult<T, U> arithmetic_and(T& left, U& right) { static_assert(has_arithmetic_and<T, U>, "この型はビットAND演算をサポートしません"); return left & right; }
		///	ビットAND演算 @a T::operator&(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticAndResult<T, U> arithmetic_and(T& left, U&& right) { static_assert(has_arithmetic_and<T, U>, "この型はビットAND演算をサポートしません"); return left & right; }
		///	ビットOR演算 @a T::operator|(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticOrResult<T, U> arithmetic_or(const T& left, const U& right) { static_assert(has_arithmetic_or<T, U>, "この型はビットOR演算をサポートしません"); return left | right; }
		///	ビットOR演算 @a T::operator|(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticOrResult<T, U> arithmetic_or(const T& left, U& right) { static_assert(has_arithmetic_or<T, U>, "この型はビットOR演算をサポートしません"); return left | right; }
		///	ビットOR演算 @a T::operator|(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticOrResult<T, U> arithmetic_or(const T& left, U&& right) { static_assert(has_arithmetic_or<T, U>, "この型はビットOR演算をサポートしません"); return left | right; }
		///	ビットOR演算 @a T::operator|(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticOrResult<T, U> arithmetic_or(T& left, const U& right) { static_assert(has_arithmetic_or<T, U>, "この型はビットOR演算をサポートしません"); return left | right; }
		///	ビットOR演算 @a T::operator|(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticOrResult<T, U> arithmetic_or(T& left, U& right) { static_assert(has_arithmetic_or<T, U>, "この型はビットOR演算をサポートしません"); return left | right; }
		///	ビットOR演算 @a T::operator|(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticOrResult<T, U> arithmetic_or(T& left, U&& right) { static_assert(has_arithmetic_or<T, U>, "この型はビットOR演算をサポートしません"); return left | right; }
		///	ビットXOR演算 @a T::operator^(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticXorResult<T, U> arithmetic_xor(const T& left, const U& right) { static_assert(has_arithmetic_xor<T, U>, "この型はビットXOR演算をサポートしません"); return left ^ right; }
		///	ビットXOR演算 @a T::operator^(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticXorResult<T, U> arithmetic_xor(const T& left, U& right) { static_assert(has_arithmetic_xor<T, U>, "この型はビットXOR演算をサポートしません"); return left ^ right; }
		///	ビットXOR演算 @a T::operator^(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticXorResult<T, U> arithmetic_xor(const T& left, U&& right) { static_assert(has_arithmetic_xor<T, U>, "この型はビットXOR演算をサポートしません"); return left ^ right; }
		///	ビットXOR演算 @a T::operator^(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticXorResult<T, U> arithmetic_xor(T& left, const U& right) { static_assert(has_arithmetic_xor<T, U>, "この型はビットXOR演算をサポートしません"); return left ^ right; }
		///	ビットXOR演算 @a T::operator^(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticXorResult<T, U> arithmetic_xor(T& left, U& right) { static_assert(has_arithmetic_xor<T, U>, "この型はビットXOR演算をサポートしません"); return left ^ right; }
		///	ビットXOR演算 @a T::operator^(U) を行います。
		template<typename T, typename U> static constexpr ArithmeticXorResult<T, U> arithmetic_xor(T& left, U&& right) { static_assert(has_arithmetic_xor<T, U>, "この型はビットXOR演算をサポートしません"); return left ^ right; }
		///	ビット左シフト演算 @a T::operator<<(U) を行います。
		template<typename T, typename U> static constexpr LShiftResult<T, U> lshift(const T& left, const U& right) { static_assert(has_lshift<T, U>, "この型はビット左シフト演算をサポートしません"); return left << right; }
		///	ビット左シフト演算 @a T::operator<<(U) を行います。
		template<typename T, typename U> static constexpr LShiftResult<T, U> lshift(const T& left, U& right) { static_assert(has_lshift<T, U>, "この型はビット左シフト演算をサポートしません"); return left << right; }
		///	ビット左シフト演算 @a T::operator<<(U) を行います。
		template<typename T, typename U> static constexpr LShiftResult<T, U> lshift(const T& left, U&& right) { static_assert(has_lshift<T, U>, "この型はビット左シフト演算をサポートしません"); return left << right; }
		///	ビット左シフト演算 @a T::operator<<(U) を行います。
		template<typename T, typename U> static constexpr LShiftResult<T, U> lshift(T& left, const U& right) { static_assert(has_lshift<T, U>, "この型はビット左シフト演算をサポートしません"); return left << right; }
		///	ビット左シフト演算 @a T::operator<<(U) を行います。
		template<typename T, typename U> static constexpr LShiftResult<T, U> lshift(T& left, U& right) { static_assert(has_lshift<T, U>, "この型はビット左シフト演算をサポートしません"); return left << right; }
		///	ビット左シフト演算 @a T::operator<<(U) を行います。
		template<typename T, typename U> static constexpr LShiftResult<T, U> lshift(T& left, U&& right) { static_assert(has_lshift<T, U>, "この型はビット左シフト演算をサポートしません"); return left << right; }
		///	ビット右シフト演算 @a T::operator>>(U) を行います。
		template<typename T, typename U> static constexpr RShiftResult<T, U> rshift(const T& left, const U& right) { static_assert(has_rshift<T, U>, "この型はビット右シフト演算をサポートしません"); return left >> right; }
		///	ビット右シフト演算 @a T::operator>>(U) を行います。
		template<typename T, typename U> static constexpr RShiftResult<T, U> rshift(const T& left, U& right) { static_assert(has_rshift<T, U>, "この型はビット右シフト演算をサポートしません"); return left >> right; }
		///	ビット右シフト演算 @a T::operator>>(U) を行います。
		template<typename T, typename U> static constexpr RShiftResult<T, U> rshift(const T& left, U&& right) { static_assert(has_rshift<T, U>, "この型はビット右シフト演算をサポートしません"); return left >> right; }
		///	ビット右シフト演算 @a T::operator>>(U) を行います。
		template<typename T, typename U> static constexpr RShiftResult<T, U> rshift(T& left, const U& right) { static_assert(has_rshift<T, U>, "この型はビット右シフト演算をサポートしません"); return left >> right; }
		///	ビット右シフト演算 @a T::operator>>(U) を行います。
		template<typename T, typename U> static constexpr RShiftResult<T, U> rshift(T& left, U& right) { static_assert(has_rshift<T, U>, "この型はビット右シフト演算をサポートしません"); return left >> right; }
		///	ビット右シフト演算 @a T::operator>>(U) を行います。
		template<typename T, typename U> static constexpr RShiftResult<T, U> rshift(T& left, U&& right) { static_assert(has_rshift<T, U>, "この型はビット右シフト演算をサポートしません"); return left >> right; }
		///	論理NOT演算 @a T::operator!() を行います。
		template<typename T> static constexpr LogicalNotResult<T> logical_not(const T& value) { static_assert(has_logical_not<T>, "この型は論理NOT演算をサポートしません"); return !value; }
		///	論理NOT演算 @a T::operator!() を行います。
		template<typename T> static constexpr LogicalNotResult<T> logical_not(T& value) { static_assert(has_logical_not<T>, "この型は論理NOT演算をサポートしません"); return !value; }
		///	論理OR演算 @a T::operator||(U) を行います。
		template<typename T, typename U> static constexpr LogicalOrResult<T, U> logical_or(const T& left, const U& right) { static_assert(has_logical_or<T, U>, "この型は論理OR演算をサポートしません"); return left || right; }
		///	論理OR演算 @a T::operator||(U) を行います。
		template<typename T, typename U> static constexpr LogicalOrResult<T, U> logical_or(const T& left, U& right) { static_assert(has_logical_or<T, U>, "この型は論理OR演算をサポートしません"); return left || right; }
		///	論理OR演算 @a T::operator||(U) を行います。
		template<typename T, typename U> static constexpr LogicalOrResult<T, U> logical_or(const T& left, U&& right) { static_assert(has_logical_or<T, U>, "この型は論理OR演算をサポートしません"); return left || right; }
		///	論理OR演算 @a T::operator||(U) を行います。
		template<typename T, typename U> static constexpr LogicalOrResult<T, U> logical_or(T& left, const U& right) { static_assert(has_logical_or<T, U>, "この型は論理OR演算をサポートしません"); return left || right; }
		///	論理OR演算 @a T::operator||(U) を行います。
		template<typename T, typename U> static constexpr LogicalOrResult<T, U> logical_or(T& left, U& right) { static_assert(has_logical_or<T, U>, "この型は論理OR演算をサポートしません"); return left || right; }
		///	論理OR演算 @a T::operator||(U) を行います。
		template<typename T, typename U> static constexpr LogicalOrResult<T, U> logical_or(T& left, U&& right) { static_assert(has_logical_or<T, U>, "この型は論理OR演算をサポートしません"); return left || right; }
		///	論理AND演算 @a T::operator&&(U) を行います。
		template<typename T, typename U> static constexpr LogicalAndResult<T, U> logical_and(const T& left, const U& right) { static_assert(has_logical_and<T, U>, "この型は論理演算ANDをサポートしません"); return left && right; }
		///	論理AND演算 @a T::operator&&(U) を行います。
		template<typename T, typename U> static constexpr LogicalAndResult<T, U> logical_and(const T& left, U& right) { static_assert(has_logical_and<T, U>, "この型は論理演算ANDをサポートしません"); return left && right; }
		///	論理AND演算 @a T::operator&&(U) を行います。
		template<typename T, typename U> static constexpr LogicalAndResult<T, U> logical_and(const T& left, U&& right) { static_assert(has_logical_and<T, U>, "この型は論理演算ANDをサポートしません"); return left && right; }
		///	論理AND演算 @a T::operator&&(U) を行います。
		template<typename T, typename U> static constexpr LogicalAndResult<T, U> logical_and(T& left, const U& right) { static_assert(has_logical_and<T, U>, "この型は論理演算ANDをサポートしません"); return left && right; }
		///	論理AND演算 @a T::operator&&(U) を行います。
		template<typename T, typename U> static constexpr LogicalAndResult<T, U> logical_and(T& left, U& right) { static_assert(has_logical_and<T, U>, "この型は論理演算ANDをサポートしません"); return left && right; }
		///	論理AND演算 @a T::operator&&(U) を行います。
		template<typename T, typename U> static constexpr LogicalAndResult<T, U> logical_and(T& left, U&& right) { static_assert(has_logical_and<T, U>, "この型は論理演算ANDをサポートしません"); return left && right; }
		///	等価比較演算 @a T::operator==(U) を行います。
		template<typename T, typename U> static constexpr EqualResult<T, U> equal(const T& left, const U& right) { static_assert(has_equal<T, U>, "この型は等価比較演算をサポートしません"); return left == right; }
		///	相違比較演算 @a T::operator!=(U) を行います。
		template<typename T, typename U> static constexpr NotEqualResult<T, U> not_equal(const T& left, const U& right) { static_assert(has_not_equal<T, U>, "この型は相違比較演算をサポートしません"); return left != right; }
		///	大なり比較演算 @a T::operator>(U) を行います。
		template<typename T, typename U> static constexpr CompareLargerResult<T, U> compare_larger(const T& left, const U& right) { static_assert(has_compare_larger<T, U>, "この型は大なり比較演算をサポートしません"); return left > right; }
		///	小なり比較演算 @a T::operator<(U) を行います。
		template<typename T, typename U> static constexpr CompareSmallerResult<T, U> compare_smaller(const T& left, const U& right) { static_assert(has_compare_smaller<T, U>, "この型は小なり比較演算をサポートしません"); return left < right; }
		///	大なりイコール比較演算 @a T::operator>=(U) を行います。
		template<typename T, typename U> static constexpr CompareLeastResult<T, U> compare_least(const T& left, const U& right) { static_assert(has_compare_least<T, U>, "この型は大なりイコール比較演算をサポートしません"); return left >= right; }
		///	小なりイコール比較演算 @a T::operator<=(U) を行います。
		template<typename T, typename U> static constexpr CompareMostResult<T, U> compare_most(const T& left, const U& right) { static_assert(has_compare_most<T, U>, "この型は小なりイコール比較演算をサポートしません"); return left <= right; }
		///	添字演算 @a T::operator[](U) を行います。
		template<typename T, typename U> static constexpr SubscriptResult<T, U> subscript(T& left, const U& right) { static_assert(has_subscript<T, U>, "この型は添字演算をサポートしません"); return left[right]; }
		///	添字演算 @a T::operator[](U) を行います。
		template<typename T, typename U> static constexpr SubscriptResult<T, U> subscript(const T& left, const U& right) { static_assert(has_subscript<T, U>, "この型は添字演算をサポートしません"); return left[right]; }
		///	間接参照演算 @a T::operator*() を行います。
		template<typename T> static constexpr DereferenceResult<T> dereference(T& value) { static_assert(has_dereference<T>, "この型は間接参照演算をサポートしません"); return *value; }
		///	間接参照演算 @a T::operator*() を行います。
		template<typename T> static constexpr DereferenceResult<T> dereference(const T& value) { static_assert(has_dereference<T>, "この型は間接参照演算をサポートしません"); return *value; }
		///	アドレス取得演算 @a T::operator&() を行います。
		template<typename T> static constexpr ReferenceResult<T> reference(T& value) { static_assert(has_reference<T>, "この型はアドレス取得演算をサポートしません"); return &value; }
		///	アドレス取得演算 @a T::operator&() を行います。
		template<typename T> static constexpr ReferenceResult<T> reference(const T& value) { static_assert(has_reference<T>, "この型はアドレス取得演算をサポートしません"); return &value; }
		///	カンマ演算 @a T::operator,(U) を行います。
		template<typename T, typename U> static constexpr CommaResult<T, U> comma(const T& left, const U& right) { static_assert(has_comma<T, U>, "この型はカンマ演算をサポートしません"); return left , right; }
		///	カンマ演算 @a T::operator,(U) を行います。
		template<typename T, typename U> static constexpr CommaResult<T, U> comma(T& left, U& right) { static_assert(has_comma<T, U>, "この型はカンマ演算をサポートしません"); return left , right; }
	};
	#if 201703L <= __cplusplus
	// Clang C++17でコンパイルするとbool::operator++()を実体化しようとしてエラーを吐くため
	// boolによるインクリメントトレイトは強制的にfalseで実体化する
	template<> struct TypeTraitsBase::HasPreincrement_impl<bool> : std::false_type {};
	// Clang C++17でコンパイルするとbool::operator++(int)を実体化しようとしてエラーを吐くため
	// boolによるインクリメントトレイトは強制的にfalseで実体化する
	template<> struct TypeTraitsBase::HasPostincrement_impl<bool> : std::false_type {};
	#endif
}
#endif // __stationaryorbit_core_traits__