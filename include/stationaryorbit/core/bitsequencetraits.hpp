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
#include "traits.hpp"
namespace zawa_ch::StationaryOrbit
{
	class BitSequenceTraits
	{
	private:
		template<class, class, class = void> struct HasBitSequenceTypeOperation_t : std::false_type {};
		template<class T, class N> struct HasBitSequenceTypeOperation_t<T, N, std::enable_if_t< Traits::IsIntegralType<N> >> : std::conjunction
			<
				std::bool_constant<Traits::ArithmeticNotResultIsConvertible<T, T>>,
				std::bool_constant<Traits::ArithmeticAndResultIsConvertible<T, T, T>>,
				std::bool_constant<Traits::ArithmeticOrResultIsConvertible<T, T, T>>,
				std::bool_constant<Traits::ArithmeticXorResultIsConvertible<T, T, T>>,
				std::bool_constant<Traits::LShiftResultIsConvertible<T, N, T>>,
				std::bool_constant<Traits::RShiftResultIsConvertible<T, N, T>>,
				std::bool_constant<Traits::SubstitutionArithmeticAndResultIsSame<T, T, T&>>,
				std::bool_constant<Traits::SubstitutionArithmeticOrResultIsSame<T, T, T&>>,
				std::bool_constant<Traits::SubstitutionArithmeticXorResultIsSame<T, T, T&>>,
				std::bool_constant<Traits::SubstitutionLShiftResultIsSame<T, N, T&>>,
				std::bool_constant<Traits::SubstitutionRShiftResultIsSame<T, N, T&>>,
				std::bool_constant<Traits::IsEquatable<T, T>>
			>
		{};
		template<class T, class N> struct IsBitSequenceType_t : std::conjunction< std::bool_constant<Traits::IsValueType<T>>, HasBitSequenceTypeOperation_t<T, N>, std::disjunction< std::is_constructible<T, uint8_t>, std::bool_constant<Traits::IsAggregatable<T, uint8_t>> >, std::negation<std::is_signed<T>>, std::bool_constant<(!std::numeric_limits<T>::is_specialized) || (!std::numeric_limits<T>::is_signed)> > {};
	public:
		///	基本的なビット演算子の実装を識別します
		template<class T, class N = int> static constexpr bool HasBitSequenceOperation = HasBitSequenceTypeOperation_t<T, N>::value;
		///	型要件:BitSequenceTypeを満たす型を識別します
		template<class T, class N = int> static constexpr bool IsBitSequenceType = IsBitSequenceType_t<T, N>::value;
	};
}
#endif // __stationaryorbit_core_bitsequencetraits__
