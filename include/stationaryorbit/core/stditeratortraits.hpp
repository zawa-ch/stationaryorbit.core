//	stationaryorbit/core/stditeratortraits
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
#ifndef __stationaryorbit_core_stditeratortraits__
#define __stationaryorbit_core_stditeratortraits__
#include <type_traits>
#include <iterator>
#include "typetraitsbase.hpp"
#include "equatabletypetraits.hpp"
#include "comparabletypetraits.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	C++標準のイテレータを識別します。
	class StdIteratorTraits
	{
		StdIteratorTraits() = delete;
		~StdIteratorTraits() = delete;
	private:
		struct do_StdLegacyIterator_impl
		{
			template<class It, typename = typename std::iterator_traits<It>::value_type> static std::true_type test_has_value_type(int);
			template<class It> static std::false_type test_has_value_type(...);
			template<class It, typename = typename std::iterator_traits<It>::difference_type> static std::true_type test_has_difference_type(int);
			template<class It> static std::false_type test_has_difference_type(...);
			template<class It, typename = typename std::iterator_traits<It>::reference> static std::true_type test_has_reference(int);
			template<class It> static std::false_type test_has_reference(...);
			template<class It, typename = typename std::iterator_traits<It>::pointer> static std::true_type test_has_pointer(int);
			template<class It> static std::false_type test_has_pointer(...);
			template<class It, typename = typename std::iterator_traits<It>::iterator_category> static std::true_type test_has_iterator_category(int);
			template<class It> static std::false_type test_has_iterator_category(...);
		};
		template<class It>
		struct do_StdLegacyIterator_t : do_StdLegacyIterator_impl
		{
			typedef decltype(test_has_value_type<It>(0)) has_value_type;
			typedef decltype(test_has_difference_type<It>(0)) has_difference_type;
			typedef decltype(test_has_reference<It>(0)) has_reference;
			typedef decltype(test_has_pointer<It>(0)) has_pointer;
			typedef decltype(test_has_iterator_category<It>(0)) has_iterator_category;
		};
		struct do_StdLegacyInputIterator_impl
		{
			template<class It, typename R = decltype( *std::declval<It&>() ), typename C = typename std::iterator_traits<It>::reference> static std::is_same<R, C> test_dereference_is_same_reference(int);
			template<class It> static std::false_type test_dereference_is_same_reference(...);
			template<class It, typename R = decltype( *std::declval<It&>() ), typename C = typename std::iterator_traits<It>::value_type> static std::is_convertible<R, C> test_dereference_is_convertible_value_type(int);
			template<class It> static std::false_type test_dereference_is_convertible_value_type(...);
			template<class It, typename R = decltype( *std::declval<It&>()++ ), typename C = typename std::iterator_traits<It>::value_type> static std::is_convertible<R, C> test_incdereference_is_convertible_value_type(int);
			template<class It> static std::false_type test_incdereference_is_convertible_value_type(...);
		};
		template<class It>
		struct do_StdLegacyInputIterator_t : do_StdLegacyInputIterator_impl
		{
			typedef decltype(test_dereference_is_same_reference<It>(0)) dereference_is_same_reference;
			typedef decltype(test_dereference_is_convertible_value_type<It>(0)) dereference_is_convertible_value_type;
			typedef decltype(test_incdereference_is_convertible_value_type<It>(0)) incdereference_is_convertible_value_type;
		};
		struct do_StdLegacyOutputIterator_impl
		{
			template<class It, class O, typename = decltype( *std::declval<It&>() = std::declval<O&>() )> static std::true_type test_has_dereference_assign(int);
			template<class It> static std::false_type test_has_dereference_assign(...);
			template<class It, class O, typename = decltype( *std::declval<It&>()++ = std::declval<O&>() )> static std::true_type test_has_incdereference_assign(int);
			template<class It> static std::false_type test_has_incdereference_assign(...);
		};
		template<class It, class O>
		struct do_StdLegacyOutputIterator_t : do_StdLegacyOutputIterator_impl
		{
			typedef decltype(test_has_dereference_assign<It, O>(0)) has_dereference_assign;
			typedef decltype(test_has_incdereference_assign<It, O>(0)) has_incdereference_assign;
		};
		struct do_StdLegacyForwardIterator_impl
		{
			template<class It, typename R = typename std::iterator_traits<It>::reference, typename C = typename std::iterator_traits<It>::value_type&> static std::is_same<R, C> test_reference_is_same_value_type_lvalue(int);
			template<class It> static std::false_type test_reference_is_same_value_type_lvalue(...);
			template<class It, typename R = typename std::iterator_traits<It>::reference, typename C = const typename std::iterator_traits<It>::value_type&> static std::is_same<R, C> test_reference_is_same_value_type_const_lvalue(int);
			template<class It> static std::false_type test_reference_is_same_value_type_const_lvalue(...);
			template<class It, typename R = decltype( *std::declval<It&>()++ ), typename C = typename std::iterator_traits<It>::reference> static std::is_same<R, C> test_incdereference_is_same_reference(int);
			template<class It> static std::false_type test_incdereference_is_same_reference(...);
		};
		template<class It>
		struct do_StdLegacyForwardIterator_t : do_StdLegacyForwardIterator_impl
		{
			typedef decltype(test_reference_is_same_value_type_lvalue<It>(0)) reference_is_same_value_type_lvalue;
			typedef decltype(test_reference_is_same_value_type_const_lvalue<It>(0)) reference_is_same_value_type_const_lvalue;
			typedef decltype(test_incdereference_is_same_reference<It>(0)) incdereference_is_same_reference;
		};
		struct do_StdLegacyBidirectionalIterator_impl
		{
			template<class It, typename R = decltype( *std::declval<It&>()-- ), typename C = typename std::iterator_traits<It>::reference> static std::is_same<R, C> test_decdereference_is_same_reference(int);
			template<class It> static std::false_type test_decdereference_is_same_reference(...);
		};
		template<class It>
		struct do_StdLegacyBidirectionalIterator_t : do_StdLegacyBidirectionalIterator_impl
		{
			typedef decltype(test_decdereference_is_same_reference<It>(0)) decdereference_is_same_reference;
		};
		struct do_StdLegacyRandomAccessIterator_impl
		{
			template<class It, typename D = typename std::iterator_traits<It>::difference_type, typename R = decltype( std::declval<It&>() += std::declval<D&>() ), typename C = It&> static std::is_same<R, C> test_difference_type_addstitution_is_same_lvalue(int);
			template<class It> static std::false_type test_difference_type_addstitution_is_same_lvalue(...);
			template<class It, typename D = typename std::iterator_traits<It>::difference_type, typename R = decltype( std::declval<It&>() + std::declval<D&>() ), typename C = It> static std::is_same<R, C> test_difference_type_add_is_same_object(int);
			template<class It> static std::false_type test_difference_type_add_is_same_object(...);
			template<class It, typename D = typename std::iterator_traits<It>::difference_type, typename R = decltype( std::declval<It&>() -= std::declval<D&>() ), typename C = It&> static std::is_same<R, C> test_difference_type_subtractstitution_is_same_lvalue(int);
			template<class It> static std::false_type test_difference_type_subtractstitution_is_same_lvalue(...);
			template<class It, typename D = typename std::iterator_traits<It>::difference_type, typename R = decltype( std::declval<It&>() - std::declval<D&>() ), typename C = It> static std::is_same<R, C> test_difference_type_subtract_is_same_object(int);
			template<class It> static std::false_type test_difference_type_subtract_is_same_object(...);
			template<class It, typename R = decltype( std::declval<It&>() - std::declval<It&>() ), typename C = typename std::iterator_traits<It>::difference_type> static std::is_same<R, C> test_type_subtract_is_same_difference_type(int);
			template<class It> static std::false_type test_type_subtract_is_same_difference_type(...);
			template<class It, typename D = typename std::iterator_traits<It>::difference_type, typename R = decltype( std::declval<It&>() [ std::declval<D&>() ] ), typename C = typename std::iterator_traits<It>::reference> static std::is_convertible<R, C> test_difference_type_subscript_is_convertible_reference(int);
			template<class It> static std::false_type test_difference_type_subscript_is_convertible_reference(...);
		};
		template<class It>
		struct do_StdLegacyRandomAccessIterator_t : do_StdLegacyRandomAccessIterator_impl
		{
			typedef decltype(test_difference_type_addstitution_is_same_lvalue<It>(0)) difference_type_addstitution_is_same_lvalue;
			typedef decltype(test_difference_type_add_is_same_object<It>(0)) difference_type_add_is_same_object;
			typedef decltype(test_difference_type_subtractstitution_is_same_lvalue<It>(0)) difference_type_subtractstitution_is_same_lvalue;
			typedef decltype(test_difference_type_subtract_is_same_object<It>(0)) difference_type_subtract_is_same_object;
			typedef decltype(test_type_subtract_is_same_difference_type<It>(0)) type_subtract_is_same_difference_type;
			typedef decltype(test_difference_type_subscript_is_convertible_reference<It>(0)) difference_type_subscript_is_convertible_reference;
		};
		template<class It> struct IsStdLegacyIterator_t : std::conjunction
			<
				std::is_copy_constructible<It>,
				std::is_copy_assignable<It>,
				std::is_destructible<It>,
				std::is_swappable<It&>,
				typename do_StdLegacyIterator_t<It>::has_value_type,
				typename do_StdLegacyIterator_t<It>::has_difference_type,
				typename do_StdLegacyIterator_t<It>::has_reference,
				typename do_StdLegacyIterator_t<It>::has_pointer,
				typename do_StdLegacyIterator_t<It>::has_iterator_category,
				std::bool_constant<TypeTraitsBase::preincrement_result_is_same<It, It&>>,
				std::bool_constant<TypeTraitsBase::has_dereference<It>>
			>
		{};
		template<class It> struct IsStdLegacyInputIterator_t : std::conjunction
			<
				IsStdLegacyIterator_t<It>,
				std::bool_constant<EquatableTypeTraits::is_equatable<It, It>>,
				std::bool_constant<TypeTraitsBase::preincrement_result_is_same<It, It&>>,
				std::bool_constant<TypeTraitsBase::has_postincrement<It>>,
				typename do_StdLegacyInputIterator_t<It>::dereference_is_same_reference,
				typename do_StdLegacyInputIterator_t<It>::dereference_is_convertible_value_type,
				typename do_StdLegacyInputIterator_t<It>::incdereference_is_convertible_value_type
			>
		{};
		template<class It, class O> struct IsStdLegacyOutputIterator_t : std::conjunction
			<
				IsStdLegacyIterator_t<It>,
				std::disjunction
				<
					std::is_class<It>,
					std::is_pointer<It>
				>,
				typename do_StdLegacyOutputIterator_t<It, O>::has_dereference_assign,
				typename do_StdLegacyOutputIterator_t<It, O>::has_incdereference_assign,
				std::bool_constant<TypeTraitsBase::preincrement_result_is_same<It, It&>>,
				std::bool_constant<TypeTraitsBase::postdecrement_result_is_convertible<It, const It&>>
			>
		{};
		template<class It> struct IsStdLegacyForwardIterator_t : std::conjunction
			<
				IsStdLegacyInputIterator_t<It>,
				std::is_default_constructible<It>,
				std::disjunction
				<
					typename do_StdLegacyForwardIterator_t<It>::reference_is_same_value_type_lvalue,
					typename do_StdLegacyForwardIterator_t<It>::reference_is_same_value_type_const_lvalue
				>,
				std::bool_constant<TypeTraitsBase::postincrement_result_is_same<It, It>>,
				typename do_StdLegacyForwardIterator_t<It>::incdereference_is_same_reference
			>
		{};
		template<class It> struct IsStdLegacyBidirectionalIterator_t : std::conjunction
			<
				IsStdLegacyForwardIterator_t<It>,
				std::bool_constant<TypeTraitsBase::predecrement_result_is_same<It, It&>>,
				std::bool_constant<TypeTraitsBase::postdecrement_result_is_convertible<It, const It&>>,
				typename do_StdLegacyBidirectionalIterator_t<It>::decdereference_is_same_reference
			>
		{};
		template<class It> struct IsStdLegacyRandomAccessIterator_t : std::conjunction
			<
				IsStdLegacyBidirectionalIterator_t<It>,
				std::bool_constant<ComparableTypeTraits::is_comparable<It, It>>,
				typename do_StdLegacyRandomAccessIterator_t<It>::difference_type_addstitution_is_same_lvalue,
				typename do_StdLegacyRandomAccessIterator_t<It>::difference_type_add_is_same_object,
				typename do_StdLegacyRandomAccessIterator_t<It>::difference_type_subtractstitution_is_same_lvalue,
				typename do_StdLegacyRandomAccessIterator_t<It>::difference_type_subtract_is_same_object,
				typename do_StdLegacyRandomAccessIterator_t<It>::type_subtract_is_same_difference_type,
				typename do_StdLegacyRandomAccessIterator_t<It>::difference_type_subscript_is_convertible_reference
			>
		{};
	public:
		///	名前付き要件:LegacyIteratorを満たす型を識別します。
		template<class It> inline constexpr static bool IsStdLegacyIterator = IsStdLegacyIterator_t<It>::value;
		///	名前付き要件:LegacyInputIteratorを満たす型を識別します。
		template<class It> inline constexpr static bool IsStdLegacyInputIterator = IsStdLegacyInputIterator_t<It>::value;
		///	名前付き要件:LegacyForwardIteratorを満たす型を識別します。
		template<class It> inline constexpr static bool IsStdLegacyForwardIterator = IsStdLegacyForwardIterator_t<It>::value;
		///	名前付き要件:LegacyBidirectionalIteratorを満たす型を識別します。
		template<class It> inline constexpr static bool IsStdLegacyBidirectionalIterator = IsStdLegacyBidirectionalIterator_t<It>::value;
		///	名前付き要件:LegacyRandomAccessIteratorを満たす型を識別します。
		template<class It> inline constexpr static bool IsStdLegacyRandomAccessIterator = IsStdLegacyRandomAccessIterator_t<It>::value;
		///	名前付き要件:LegacyOutputIteratorを満たす型を識別します。
		template<class It, class O> inline constexpr static bool IsStdLegacyOutputIterator = IsStdLegacyOutputIterator_t<It, O>::value;

		template<typename It> using value_type = typename std::iterator_traits<It>::value_type;
		template<typename It> using difference_type = typename std::iterator_traits<It>::difference_type;
		template<typename It> using reference = typename std::iterator_traits<It>::reference;
		template<typename It> using pointer = typename std::iterator_traits<It>::pointer;
		template<typename It> using iterator_category = typename std::iterator_traits<It>::iterator_category;

		template<typename It> [[nodiscard]] static constexpr reference<It> dereference(const It& it) { static_assert(IsStdLegacyInputIterator<It>, "名前付き要件:LegacyInputIterator を満たす必要があります。"); return *it; }
		template<typename It> [[nodiscard]] static constexpr It& next(It& it) { static_assert(IsStdLegacyInputIterator<It>, "名前付き要件:LegacyInputIterator を満たす必要があります。"); return *it; }
	};
}
#endif // __stationaryorbit_core_stditeratortraits__
