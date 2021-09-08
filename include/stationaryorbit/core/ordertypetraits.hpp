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
	class OrderTypeTraits
	{
		OrderTypeTraits() = delete;
		~OrderTypeTraits() = delete;
	private:
		template<class T> struct HasSequencialOrderTypeOperation_t : std::conjunction
			<
				std::bool_constant<TypeTraitsBase::preincrement_result_is_same<T, T&>>,
				std::bool_constant<EquatableTypeTraits::is_equatable<T, T>>
			>
		{};
		template<class T> struct HasBidirectionalOrderTypeOperation_t : std::conjunction
			<
				HasSequencialOrderTypeOperation_t<T>,
				std::bool_constant<TypeTraitsBase::predecrement_result_is_same<T, T&>>
			>
		{};
		template<class, class, class = void> struct HasLinearOrderTypeOperation_t : std::false_type {};
		template<class T, class N> struct HasLinearOrderTypeOperation_t<T, N, std::enable_if_t< IntegralTypeTraits::IsIntegralType<N> >> : std::conjunction
			<
				HasBidirectionalOrderTypeOperation_t<T>,
				std::bool_constant<TypeTraitsBase::addition_result_is_same<T, N, T>>,
				std::bool_constant<TypeTraitsBase::subtraction_result_is_same<T, N, T>>,
				std::bool_constant<TypeTraitsBase::substitution_add_result_is_same<T, N, T&>>,
				std::bool_constant<TypeTraitsBase::substitution_subtract_result_is_same<T, N, T&>>,
				std::bool_constant<ComparableTypeTraits::is_comparable<T, T>>
			>
		{};
		template<class T> struct IsSequencialOrderType_t : std::conjunction< HasSequencialOrderTypeOperation_t<T> > {};
		template<class T> struct IsBidirectionalOrderType_t : std::conjunction< IsSequencialOrderType_t<T>, HasBidirectionalOrderTypeOperation_t<T> > {};
		template<class T, class N> struct IsLinearOrderType_t : std::conjunction< IsBidirectionalOrderType_t<T>, HasLinearOrderTypeOperation_t<T, N> > {};
	public:
		///	型要件:SequencialOrderTypeを満たす型を識別します
		template<class T> static constexpr bool IsSequencialOrderType = IsSequencialOrderType_t<T>::value;
		///	型要件:BidirectionalOrderTypeを満たす型を識別します
		template<class T> static constexpr bool IsBidirectionalOrderType = IsBidirectionalOrderType_t<T>::value;
		///	型要件:LinearOrderTypeを満たす型を識別します
		template<class T, class N = int> static constexpr bool IsLinearOrderType = IsLinearOrderType_t<T, N>::value;
	};
}
#endif // __stationaryorbit_core_ordertypetraits__
