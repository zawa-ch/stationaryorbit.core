//	stationaryorbit/core/bitsequencetypetraits
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
#ifndef __stationaryorbit_core_bitsequencetypetraits__
#define __stationaryorbit_core_bitsequencetypetraits__
#include <limits>
#include "typetraitsbase.hpp"
#include "valuetypetraits.hpp"
#include "numericaltypetraits.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	型要件:BitSequenceType を満たす型を識別します
	class BitSequenceTypeTraits : public ValueTypeTraits
	{
		BitSequenceTypeTraits() = delete;
		BitSequenceTypeTraits(const BitSequenceTypeTraits&) = delete;
		BitSequenceTypeTraits(BitSequenceTypeTraits&&) = delete;
		BitSequenceTypeTraits& operator=(const BitSequenceTypeTraits&) = delete;
		BitSequenceTypeTraits& operator=(BitSequenceTypeTraits&&) = delete;
		~BitSequenceTypeTraits() = delete;
	private:
		template<typename, typename, typename = std::void_t<>> struct HasBitSequenceTypeOperation_impl : std::false_type {};
		template<typename T, typename N> struct HasBitSequenceTypeOperation_impl<T, N, std::enable_if_t<IntegralTypeTraits::is_integraltype<N>>> :
			std::conjunction
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
				std::bool_constant<TypeTraitsBase::substitution_rshift_result_is_same<T, N, T&>>
			>
		{};
		template<typename T, typename N> struct IsBitSequenceType_impl :
			std::conjunction
			<
				std::bool_constant<ValueTypeTraits::is_valuetype<T>>,
				HasBitSequenceTypeOperation_impl<T, N>,
				std::disjunction
				<
					std::is_constructible<T, uint8_t>,
					std::bool_constant<TypeTraitsBase::is_aggregatable<T, uint8_t>>
				>,
				std::negation<std::is_signed<T>>,
				std::bool_constant<(!std::numeric_limits<T>::is_specialized) || (!std::numeric_limits<T>::is_signed)>
			>
		{};
	public:
		///	指定された型が 型要件:BitSequenceType を満たすかを識別します。
		template<typename T, typename N = int> static constexpr bool is_bitsequence_type = IsBitSequenceType_impl<T, N>::value;

		///	ビット単位の論理否定演算を行います。
		template<typename T, typename N = int> static constexpr T bitwise_not(const T& object) { static_assert(is_bitsequence_type<T, N>, "型 T, N の組み合わせは 型要件:BitSequenceType を満たしません。"); return TypeTraitsBase::arithmetic_not(object); }
		///	ビット単位の論理積演算を行います。
		template<typename T, typename N = int> static constexpr T bitwise_and(const T& object, const T& other) { static_assert(is_bitsequence_type<T, N>, "型 T, N の組み合わせは 型要件:BitSequenceType を満たしません。"); return TypeTraitsBase::arithmetic_and(object, other); }
		///	ビット単位の論理和演算を行います。
		template<typename T, typename N = int> static constexpr T bitwise_or(const T& object, const T& other) { static_assert(is_bitsequence_type<T, N>, "型 T, N の組み合わせは 型要件:BitSequenceType を満たしません。"); return TypeTraitsBase::arithmetic_or(object, other); }
		///	ビット単位の排他的論理和演算を行います。
		template<typename T, typename N = int> static constexpr T bitwise_xor(const T& object, const T& other) { static_assert(is_bitsequence_type<T, N>, "型 T, N の組み合わせは 型要件:BitSequenceType を満たしません。"); return TypeTraitsBase::arithmetic_xor(object, other); }
		///	ビットの左シフトを行います。
		template<typename T, typename N = int> static constexpr T lshift(const T& object, const N& bits) { static_assert(is_bitsequence_type<T, N>, "型 T, N の組み合わせは 型要件:BitSequenceType を満たしません。"); return TypeTraitsBase::lshift(object, bits); }
		///	ビットの右シフトを行います。
		template<typename T, typename N = int> static constexpr T rshift(const T& object, const N& bits) { static_assert(is_bitsequence_type<T, N>, "型 T, N の組み合わせは 型要件:BitSequenceType を満たしません。"); return TypeTraitsBase::rshift(object, bits); }
		///	ビット単位の論理積演算を行い、代入します。
		template<typename T, typename N = int> static constexpr T& substitution_bitwise_and(T& object, const T& other) { static_assert(is_bitsequence_type<T, N>, "型 T, N の組み合わせは 型要件:BitSequenceType を満たしません。"); return TypeTraitsBase::substitution_arithmetic_and(object, other); }
		///	ビット単位の論理和演算を行い、代入します。
		template<typename T, typename N = int> static constexpr T& substitution_bitwise_or(T& object, const T& other) { static_assert(is_bitsequence_type<T, N>, "型 T, N の組み合わせは 型要件:BitSequenceType を満たしません。"); return TypeTraitsBase::substitution_arithmetic_or(object, other); }
		///	ビット単位の排他的論理和演算を行い、代入します。
		template<typename T, typename N = int> static constexpr T& substitution_bitwise_xor(T& object, const T& other) { static_assert(is_bitsequence_type<T, N>, "型 T, N の組み合わせは 型要件:BitSequenceType を満たしません。"); return TypeTraitsBase::substitution_arithmetic_xor(object, other); }
		///	ビットの左シフトを行い、代入します。
		template<typename T, typename N = int> static constexpr T& substitution_lshift(T& object, const N& bits) { static_assert(is_bitsequence_type<T, N>, "型 T, N の組み合わせは 型要件:BitSequenceType を満たしません。"); return TypeTraitsBase::substitution_lshift(object, bits); }
		///	ビットの右シフトを行い、代入します。
		template<typename T, typename N = int> static constexpr T& substitution_rshift(T& object, const N& bits) { static_assert(is_bitsequence_type<T, N>, "型 T, N の組み合わせは 型要件:BitSequenceType を満たしません。"); return TypeTraitsBase::substitution_rshift(object, bits); }
	};
}
#endif // __stationaryorbit_core_bitsequencetypetraits__
