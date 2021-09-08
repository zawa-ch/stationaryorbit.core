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
		template<class T> struct HasBidirectionalOrderTypeOperation_impl : std::conjunction
			<
				HasSequencialOrderTypeOperation_impl<T>,
				std::bool_constant<TypeTraitsBase::predecrement_result_is_same<T, T&>>
			>
		{};
		template<class T> struct IsBidirectionalOrderType_impl :
			std::conjunction
			<
				IsSequencialOrderType_impl<T>,
				HasBidirectionalOrderTypeOperation_impl<T>
			>
		{};
	public:
		template<class T> static constexpr bool IsBidirectionalOrderType = IsBidirectionalOrderType_impl<T>::value;
	};

	///	型要件:LinearOrderType を満たす型を識別します
	class LinearOrderTypeTraits : public BidirectionalOrderTypeTraits
	{
		LinearOrderTypeTraits() = delete;
		LinearOrderTypeTraits(const LinearOrderTypeTraits&) = delete;
		LinearOrderTypeTraits(LinearOrderTypeTraits&&) = delete;
		LinearOrderTypeTraits& operator=(const LinearOrderTypeTraits&) = delete;
		LinearOrderTypeTraits& operator=(LinearOrderTypeTraits&&) = delete;
		~LinearOrderTypeTraits() = delete;
	protected:
		template<class, class, class = void> struct HasLinearOrderTypeOperation_t : std::false_type {};
		template<class T, class N> struct HasLinearOrderTypeOperation_t<T, N, std::enable_if_t< IntegralTypeTraits::IsIntegralType<N> >> : std::conjunction
			<
				HasBidirectionalOrderTypeOperation_impl<T>,
				std::bool_constant<TypeTraitsBase::addition_result_is_same<T, N, T>>,
				std::bool_constant<TypeTraitsBase::subtraction_result_is_same<T, N, T>>,
				std::bool_constant<TypeTraitsBase::substitution_add_result_is_same<T, N, T&>>,
				std::bool_constant<TypeTraitsBase::substitution_subtract_result_is_same<T, N, T&>>,
				std::bool_constant<ComparableTypeTraits::is_comparable<T, T>>
			>
		{};
		template<class T, class N> struct IsLinearOrderType_t :
			std::conjunction
			<
				IsBidirectionalOrderType_impl<T>,
				HasLinearOrderTypeOperation_t<T, N>
			>
		{};
	public:
		template<class T, class N = int> static constexpr bool IsLinearOrderType = IsLinearOrderType_t<T, N>::value;
	};
}
#endif // __stationaryorbit_core_ordertypetraits__
