//	stationaryorbit/core/ordertypetraits
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
#ifndef __stationaryorbit_core_ordertypetraits__
#define __stationaryorbit_core_ordertypetraits__
#include "typetraitsbase.hpp"
#include "equatabletypetraits.hpp"
#include "comparabletypetraits.hpp"
#include "numericaltypetraits.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	型要件:SequencialOrderType を満たす型を識別します
	class SequencialOrderTypeTraits : public EquatableTypeTraits
	{
		SequencialOrderTypeTraits() = delete;
		SequencialOrderTypeTraits(const SequencialOrderTypeTraits&) = delete;
		SequencialOrderTypeTraits(SequencialOrderTypeTraits&&) = delete;
		SequencialOrderTypeTraits& operator=(const SequencialOrderTypeTraits&) = delete;
		SequencialOrderTypeTraits& operator=(SequencialOrderTypeTraits&&) = delete;
		~SequencialOrderTypeTraits() = delete;
	protected:
		template<typename T> struct HasSequencialOrderTypeOperation_impl : std::conjunction
			<
				std::bool_constant<TypeTraitsBase::preincrement_result_is_same<T, T&>>
			>
		{};
		template<typename T> struct IsSequencialOrderType_impl :
			std::conjunction
			<
				HasSequencialOrderTypeOperation_impl<T>,
				std::bool_constant<is_equatable<T, T>>
			>
		{};
	public:
		///	指定された型が 型要件:SequencialOrderType を満たすかを識別します。
		template<typename T> static constexpr bool is_sequencialordertype = IsSequencialOrderType_impl<T>::value;

		///	指定したオブジェクトの値を次の値にします。
		template<typename T> static constexpr T& next(T& object) { static_assert(is_sequencialordertype<T>, "型 T は 型要件:SequencialOrderType を満たしません。"); return TypeTraitsBase::preincrement(object); }
	};

	///	型要件:BidirectionalOrderType を満たす型を識別します
	class BidirectionalOrderTypeTraits : public SequencialOrderTypeTraits
	{
		BidirectionalOrderTypeTraits() = delete;
		BidirectionalOrderTypeTraits(const BidirectionalOrderTypeTraits&) = delete;
		BidirectionalOrderTypeTraits(BidirectionalOrderTypeTraits&&) = delete;
		BidirectionalOrderTypeTraits& operator=(const BidirectionalOrderTypeTraits&) = delete;
		BidirectionalOrderTypeTraits& operator=(BidirectionalOrderTypeTraits&&) = delete;
		~BidirectionalOrderTypeTraits() = delete;
	protected:
		template<typename T> struct HasBidirectionalOrderTypeOperation_impl : std::conjunction
			<
				HasSequencialOrderTypeOperation_impl<T>,
				std::bool_constant<TypeTraitsBase::predecrement_result_is_same<T, T&>>
			>
		{};
		template<typename T> struct IsBidirectionalOrderType_impl :
			std::conjunction
			<
				IsSequencialOrderType_impl<T>,
				HasBidirectionalOrderTypeOperation_impl<T>
			>
		{};
	public:
		///	指定された型が 型要件:BidirectionalOrderType を満たすかを識別します。
		template<typename T> static constexpr bool is_bidirectionalordertype = IsBidirectionalOrderType_impl<T>::value;

		///	指定したオブジェクトの値を前の値にします。
		template<typename T> static constexpr T& previous(T& object) { static_assert(is_bidirectionalordertype<T>, "型 T は 型要件:BidirectionalOrderType を満たしません。"); return TypeTraitsBase::predecrement(object); }
	};

	///	型要件:LinearOrderType を満たす型を識別します
	class LinearOrderTypeTraits : public BidirectionalOrderTypeTraits, public ComparableTypeTraits
	{
		LinearOrderTypeTraits() = delete;
		LinearOrderTypeTraits(const LinearOrderTypeTraits&) = delete;
		LinearOrderTypeTraits(LinearOrderTypeTraits&&) = delete;
		LinearOrderTypeTraits& operator=(const LinearOrderTypeTraits&) = delete;
		LinearOrderTypeTraits& operator=(LinearOrderTypeTraits&&) = delete;
		~LinearOrderTypeTraits() = delete;
	protected:
		template<typename, typename, typename = void> struct HasLinearOrderTypeOperation_impl : std::false_type {};
		template<typename T, typename N> struct HasLinearOrderTypeOperation_impl<T, N, std::enable_if_t< IntegralTypeTraits::is_integraltype<N> >> : std::conjunction
			<
				HasBidirectionalOrderTypeOperation_impl<T>,
				std::bool_constant<TypeTraitsBase::substitution_add_result_is_same<T, N, T&>>,
				std::bool_constant<TypeTraitsBase::substitution_subtract_result_is_same<T, N, T&>>
			>
		{};
		template<typename T, typename N> struct IsLinearOrderType_impl :
			std::conjunction
			<
				IsBidirectionalOrderType_impl<T>,
				HasLinearOrderTypeOperation_impl<T, N>,
				std::bool_constant<is_comparable<T, T>>
			>
		{};
	public:
		///	指定された型が 型要件:LinearOrderType を満たすかを識別します。
		template<typename T, typename N = int> static constexpr bool is_linearordertype = IsLinearOrderType_impl<T, N>::value;

		///	指定したオブジェクトの値を指定された数だけ進めます。
		template<typename T, typename N = int> static constexpr T& forward(T& object, const N& count) { static_assert(is_linearordertype<T, N>, "型 T は 型要件:LinearOrderType を満たしません。"); return TypeTraitsBase::substitution_add(object, count); }
		///	指定したオブジェクトの値を指定された数だけ戻します。
		template<typename T, typename N = int> static constexpr T& backward(T& object, const N& count) { static_assert(is_linearordertype<T, N>, "型 T は 型要件:LinearOrderType を満たしません。"); return TypeTraitsBase::substitution_subtract(object, count); }
	};
}
#endif // __stationaryorbit_core_ordertypetraits__
