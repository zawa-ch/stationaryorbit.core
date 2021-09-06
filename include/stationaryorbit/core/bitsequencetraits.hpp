//	stationaryorbit/core/bitsequencetraits
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
#ifndef __stationaryorbit_core_bitsequencetraits__
#define __stationaryorbit_core_bitsequencetraits__
#include <limits>
#include "typetraitsbase.hpp"
#include "equatabletypetraits.hpp"
#include "valuetypetraits.hpp"
#include "numericaltraits.hpp"
namespace zawa_ch::StationaryOrbit
{
	class BitSequenceTraits
	{
	private:
		template<class, class, class = void> struct HasBitSequenceTypeOperation_t : std::false_type {};
		template<class T, class N> struct HasBitSequenceTypeOperation_t<T, N, std::enable_if_t< NumericalTraits::IsIntegralType<N> >> : std::conjunction
			<
				std::bool_constant<TypeTraitsBase::arithmetic_not_result_is_convertible<T, T>>,
				std::bool_constant<TypeTraitsBase::arithmetic_and_result_is_convertible<T, T, T>>,
				std::bool_constant<TypeTraitsBase::arithmetic_or_result_is_convertible<T, T, T>>,
				std::bool_constant<TypeTraitsBase::arithmetic_xor_result_is_convertible<T, T, T>>,
				std::bool_constant<TypeTraitsBase::lshift_result_is_convertible<T, N, T>>,
				std::bool_constant<TypeTraitsBase::rshift_result_is_convertible<T, N, T>>,
				std::bool_constant<TypeTraitsBase::substitution_arithmetic_and_result_is_same<T, T, T&>>,
				std::bool_constant<TypeTraitsBase::substitution_arithmetic_or_result_is_same<T, T, T&>>,
				std::bool_constant<TypeTraitsBase::substitution_arithmetic_xor_result_is_same<T, T, T&>>,
				std::bool_constant<TypeTraitsBase::substitution_lshift_result_is_same<T, N, T&>>,
				std::bool_constant<TypeTraitsBase::substitution_rshift_result_is_same<T, N, T&>>,
				std::bool_constant<EquatableTypeTraits::IsEquatable<T, T>>
			>
		{};
		template<class T, class N> struct IsBitSequenceType_t : std::conjunction< std::bool_constant<ValueTypeTraits::IsValueType<T>>, HasBitSequenceTypeOperation_t<T, N>, std::disjunction< std::is_constructible<T, uint8_t>, std::bool_constant<TypeTraitsBase::is_aggregatable<T, uint8_t>> >, std::negation<std::is_signed<T>>, std::bool_constant<(!std::numeric_limits<T>::is_specialized) || (!std::numeric_limits<T>::is_signed)> > {};
	public:
		///	基本的なビット演算子の実装を識別します
		template<class T, class N = int> static constexpr bool HasBitSequenceOperation = HasBitSequenceTypeOperation_t<T, N>::value;
		///	型要件:BitSequenceTypeを満たす型を識別します
		template<class T, class N = int> static constexpr bool IsBitSequenceType = IsBitSequenceType_t<T, N>::value;
	};
}
#endif // __stationaryorbit_core_bitsequencetraits__
