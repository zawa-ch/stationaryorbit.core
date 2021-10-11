//	stationaryorbit/core/stdcontainertraits
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
#ifndef __stationaryorbit_core_stdcontainertraits
#define __stationaryorbit_core_stdcontainertraits
#include <type_traits>
#include "stditeratortraits.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	名前付き要件:Container を満たす型を識別します。
	class StdContainerTraits
	{
		StdContainerTraits() = delete;
		StdContainerTraits(const StdContainerTraits&) = delete;
		StdContainerTraits(StdContainerTraits&&) = delete;
		StdContainerTraits& operator=(const StdContainerTraits&) = delete;
		StdContainerTraits& operator=(StdContainerTraits&&) = delete;
		~StdContainerTraits() = delete;
	public:
		struct DoIsStdContainer_impl
		{
			template<typename Tp, typename = typename Tp::value_type> static std::true_type test_type_value_type(int);
			template<typename Tp> static std::false_type test_type_value_type(...);
			template<typename Tp, typename R = typename Tp::reference, typename C = typename Tp::value_type&> static std::is_same<R, C> test_type_reference(int);
			template<typename Tp> static std::false_type test_type_reference(...);
			template<typename Tp, typename R = typename Tp::const_reference, typename C = const typename Tp::value_type&> static std::is_same<R, C> test_type_const_reference(int);
			template<typename Tp> static std::false_type test_type_const_reference(...);
			template<typename Tp, typename It = typename Tp::iterator, typename V = typename Tp::value_type> static std::conjunction<std::bool_constant<StdLegacyForwardIteratorTraits::is_std_legacy_forward_iterator<It>>, std::is_same<typename std::iterator_traits<It>::value_type, V>> test_type_iterator(int);
			template<typename Tp> static std::false_type test_type_iterator(...);
			template<typename Tp, typename It = typename Tp::const_iterator, typename V = typename Tp::value_type> static std::conjunction<std::bool_constant<StdLegacyForwardIteratorTraits::is_std_legacy_forward_iterator<It>>, std::is_same<typename std::iterator_traits<It>::value_type, V>> test_type_const_iterator(int);
			template<typename Tp> static std::false_type test_type_const_iterator(...);
			template<typename Tp, typename R = typename Tp::difference_type, typename C1 = typename Tp::iterator, typename C2 = typename Tp::const_iterator> static std::conjunction<std::is_same<R, typename std::iterator_traits<C1>::difference_type>, std::is_same<R, typename std::iterator_traits<C2>::difference_type>> test_type_difference_type(int);
			template<typename Tp> static std::false_type test_type_difference_type(...);
			template<typename Tp, typename It = typename Tp::iterator, typename Itc = typename Tp::const_iterator> static std::is_convertible<It, Itc> iterator_test_convert_const_iterator(...);
			template<typename Tp, typename R = typename Tp::size_type> static std::true_type test_type_size_type(int);
			template<typename Tp> static std::false_type test_type_size_type(...);
			template<typename Tp> static std::is_default_constructible<Tp> test_default_construct(...);
			template<typename Tp> static std::is_copy_constructible<Tp> test_copy_construct(...);
			template<typename Tp> static std::is_move_constructible<Tp> test_move_construct(...);
			template<typename Tp> static std::is_copy_assignable<Tp> test_copy_assign(...);
			template<typename Tp> static std::is_move_assignable<Tp> test_move_assign(...);
			template<typename Tp> static std::is_destructible<Tp> test_destruct(...);
			template<typename Tp, typename R = decltype(std::declval<Tp&>().begin()), typename It = typename Tp::iterator> static std::is_same<R, It> test_func_begin(int);
			template<typename Tp> static std::false_type test_func_begin(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>().begin()), typename It = typename Tp::const_iterator> static std::is_same<R, It> test_const_func_begin(int);
			template<typename Tp> static std::false_type test_const_func_begin(...);
			template<typename Tp, typename R = decltype(std::declval<Tp&>().end()), typename It = typename Tp::iterator> static std::is_same<R, It> test_func_end(int);
			template<typename Tp> static std::false_type test_func_end(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>().end()), typename It = typename Tp::const_iterator> static std::is_same<R, It> test_const_func_end(int);
			template<typename Tp> static std::false_type test_const_func_end(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>().cbegin()), typename It = typename Tp::const_iterator> static std::is_same<R, It> test_func_cbegin(int);
			template<typename Tp> static std::false_type test_func_cbegin(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>().cend()), typename It = typename Tp::const_iterator> static std::is_same<R, It> test_func_cend(int);
			template<typename Tp> static std::false_type test_func_cend(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>() == std::declval<const Tp&>())> static std::is_convertible<R, bool> test_operator_equals(int);
			template<typename Tp> static std::false_type test_operator_equals(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>() != std::declval<const Tp&>())> static std::is_convertible<R, bool> test_operator_not_equals(int);
			template<typename Tp> static std::false_type test_operator_not_equals(...);
			template<typename Tp> static std::is_swappable<Tp> test_swappable(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>().size()), typename C = typename Tp::size_type> static std::is_same<R, C> test_func_size(int);
			template<typename Tp> static std::false_type test_func_size(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>().max_size()), typename C = typename Tp::size_type> static std::is_same<R, C> test_func_max_size(int);
			template<typename Tp> static std::false_type test_func_max_size(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>().empty())> static std::is_convertible<R, bool> test_func_empty(int);
			template<typename Tp> static std::false_type test_func_empty(...);
		};
		template<typename Tp>
		struct DoIsStdContainer_t : DoIsStdContainer_impl
		{
			//	value_type -> T
			//	Eraseable
			typedef decltype(test_type_value_type<Tp>(0)) passed_type_value_type;
			//	reference -> T&
			typedef decltype(test_type_reference<Tp>(0)) passed_type_reference;
			//	const_reference -> const T&
			typedef decltype(test_type_const_reference<Tp>(0)) passed_type_const_reference;
			//	iterator -> Tを指すイテレータ
			//	LegacyForwardIterator
			typedef decltype(test_type_iterator<Tp>(0)) passed_type_iterator;
			//	iterator: const_iterator に変換可能
			typedef decltype(iterator_test_convert_const_iterator<Tp>(0)) iterator_passed_convert_const_iterator;
			//	const_iterator (Tを指すconstイテレータ)
			//	LegacyForwardIterator
			typedef decltype(test_type_const_iterator<Tp>(0)) passed_type_const_iterator;
			//	difference_type (符号付き整数)
			//	iterator および const_iterator に対する iterator_traits::difference_type と同じでなければならない
			typedef decltype(test_type_difference_type<Tp>(0)) passed_type_difference_type;
			//	size_type (符号なし整数)
			//	difference_typeのすべての正の値を表現するのに十分大きい
			typedef decltype(test_type_size_type<Tp>(0)) passed_type_size_type;
			//	C() -> C
			//	空のコンテナを作成する
			//	事後条件: C().empty() == true
			//	定数時間
			typedef decltype(test_default_construct<Tp>(0)) passed_default_construct;
			//	C(a) -> C
			//	a のコピーを作成する
			//	事前条件: T は CopyInsertable でなければならない
			//	事後条件: a == C(a)
			//	線形時間
			typedef decltype(test_copy_construct<Tp>(0)) passed_copy_construct;
			//	C(rv) -> C (C++11以上)
			//	rv をムーブする
			//	事後条件: この構築を行う前の値 rv と等しい
			//	定数時間(std::array の場合は線形時間)
			typedef decltype(test_move_construct<Tp>(0)) passed_move_construct;
			//	a = b -> C&
			//	a のすべての要素を破棄または b の要素からコピー代入する
			//	事後条件: a == b
			//	線形時間
			typedef decltype(test_copy_assign<Tp>(0)) passed_copy_assign;
			//	a = rv -> C&
			//	a のすべての要素を破棄または rv の要素からムーブ代入する
			//	事後条件: a がこの代入を行う前の値 rv と等しい
			//	線形時間
			typedef decltype(test_move_assign<Tp>(0)) passed_move_assign;
			//	a.~C() -> void
			//	a のすべての要素を破棄しすべてのメモリを解放する
			//	線形時間
			typedef decltype(test_destruct<Tp>(0)) passed_destruct;
			//	a.begin() -> iterator
			//	a の最初の要素を指すイテレータ
			//	定数時間
			typedef decltype(test_func_begin<Tp>(0)) passed_func_begin;
			//	a.begin() -> const_iterator
			//	a の最初の要素を指すイテレータ
			//	定数時間
			typedef decltype(test_const_func_begin<Tp>(0)) passed_const_func_begin;
			//	a.end() -> iterator
			//	a の最後の要素の次を指すイテレータ
			//	定数時間
			typedef decltype(test_func_end<Tp>(0)) passed_func_end;
			//	a.end() -> const_iterator
			//	a の最後の要素の次を指すイテレータ
			//	定数時間
			typedef decltype(test_const_func_end<Tp>(0)) passed_const_func_end;
			//	a.cbegin() -> const_iterator (C++11以上)
			//	const_cast<const C&>(a).begin()
			//	定数時間
			typedef decltype(test_func_cbegin<Tp>(0)) passed_func_cbegin;
			//	a.cend() -> const_iterator (C++11以上)
			//	const_cast<const C&>(a).end()
			//	定数時間
			typedef decltype(test_func_cend<Tp>(0)) passed_func_cend;
			//	a == b -> bool に変換可能
			//	std::equal(a.begin(), a.end(), b.begin(), b.end())(C++14以上)
			//	事前条件: T は　EqualityComparable でなければならない
			//	a.size() != b.size() の場合は定数時間(std::forward_list の場合は常に線形時間です)、そうでなければ線形時間
			typedef decltype(test_operator_equals<Tp>(0)) passed_operator_equals;
			//	a != b -> bool に変換可能
			//	!(a == b)
			//	線形時間
			typedef decltype(test_operator_not_equals<Tp>(0)) passed_operator_not_equals;
			//	a.swap(b) -> void
			//	a と b の値を交換する
			//	定数時間(std::array の場合は線形時間)((C++11未満)厳密な定数時間ではありません)
			//	swap(a, b) -> void
			//	a.swap(b)
			//	定数時間(std::array の場合は線形時間)
			typedef decltype(test_swappable<Tp>(0)) passed_swappable;
			//	a.size() -> size_type
			//	distance(a.begin(), a.end())
			//	定数時間((C++11未満)厳密な定数時間ではありません)
			typedef decltype(test_func_size<Tp>(0)) passed_func_size;
			//	a.max_size() -> size_type
			//	b.size()、ただし b は有り得る最も大きなコンテナ
			//	定数時間((C++11未満)厳密な定数時間ではありません)
			typedef decltype(test_func_max_size<Tp>(0)) passed_func_max_size;
			//	a.empty() -> bool に変換可能
			//	a.begin() == a.end()
			//	定数時間 
			typedef decltype(test_func_empty<Tp>(0)) passed_func_empty;
		};
	protected:
		template<typename Tp>
		struct IsStdContainer_t :
			std::conjunction
			<
				typename DoIsStdContainer_t<Tp>::passed_type_value_type,
				typename DoIsStdContainer_t<Tp>::passed_type_reference,
				typename DoIsStdContainer_t<Tp>::passed_type_const_reference,
				typename DoIsStdContainer_t<Tp>::passed_type_iterator,
				typename DoIsStdContainer_t<Tp>::iterator_passed_convert_const_iterator,
				typename DoIsStdContainer_t<Tp>::passed_type_const_iterator,
				typename DoIsStdContainer_t<Tp>::passed_type_difference_type,
				typename DoIsStdContainer_t<Tp>::passed_type_size_type,
				typename DoIsStdContainer_t<Tp>::passed_default_construct,
				typename DoIsStdContainer_t<Tp>::passed_copy_construct,
				typename DoIsStdContainer_t<Tp>::passed_move_construct,
				typename DoIsStdContainer_t<Tp>::passed_copy_assign,
				typename DoIsStdContainer_t<Tp>::passed_move_assign,
				typename DoIsStdContainer_t<Tp>::passed_destruct,
				typename DoIsStdContainer_t<Tp>::passed_func_begin,
				typename DoIsStdContainer_t<Tp>::passed_const_func_begin,
				typename DoIsStdContainer_t<Tp>::passed_func_end,
				typename DoIsStdContainer_t<Tp>::passed_const_func_end,
				typename DoIsStdContainer_t<Tp>::passed_func_cbegin,
				typename DoIsStdContainer_t<Tp>::passed_func_cend,
				typename DoIsStdContainer_t<Tp>::passed_operator_equals,
				typename DoIsStdContainer_t<Tp>::passed_operator_not_equals,
				typename DoIsStdContainer_t<Tp>::passed_swappable,
				typename DoIsStdContainer_t<Tp>::passed_func_size,
				typename DoIsStdContainer_t<Tp>::passed_func_max_size,
				typename DoIsStdContainer_t<Tp>::passed_func_empty
			>
		{};
	public:
		template<typename Tp> static constexpr bool is_container = IsStdContainer_t<Tp>::value;

		template<typename Tp> using ValueType = typename Tp::value_type;
		template<typename Tp> using Reference = typename Tp::reference;
		template<typename Tp> using ConstReference = typename Tp::const_reference;
		template<typename Tp> using Iterator = typename Tp::iterator;
		template<typename Tp> using ConstIterator = typename Tp::const_iterator;
		template<typename Tp> using DifferenceType = typename Tp::difference_type;
		template<typename Tp> using SizeType = typename Tp::size_type;
		template<typename Tp> static constexpr Iterator<Tp> begin(Tp& cont)
		{
			static_assert(is_container<Tp>, "テンプレート引数型 Tp は 名前付き要件:Container を満たしません。");
			return cont.begin();
		}
		template<typename Tp> static constexpr ConstIterator<Tp> begin(const Tp& cont)
		{
			static_assert(is_container<Tp>, "テンプレート引数型 Tp は 名前付き要件:Container を満たしません。");
			return cont.begin();
		}
		template<typename Tp> static constexpr Iterator<Tp> end(Tp& cont)
		{
			static_assert(is_container<Tp>, "テンプレート引数型 Tp は 名前付き要件:Container を満たしません。");
			return cont.end();
		}
		template<typename Tp> static constexpr ConstIterator<Tp> end(const Tp& cont)
		{
			static_assert(is_container<Tp>, "テンプレート引数型 Tp は 名前付き要件:Container を満たしません。");
			return cont.end();
		}
		template<typename Tp> static constexpr ConstIterator<Tp> cbegin(const Tp& cont)
		{
			static_assert(is_container<Tp>, "テンプレート引数型 Tp は 名前付き要件:Container を満たしません。");
			return cont.cbegin();
		}
		template<typename Tp> static constexpr ConstIterator<Tp> cend(const Tp& cont)
		{
			static_assert(is_container<Tp>, "テンプレート引数型 Tp は 名前付き要件:Container を満たしません。");
			return cont.cend();
		}
		template<typename Tp> static constexpr bool equals(const Tp& cont, const Tp& other)
		{
			static_assert(is_container<Tp>, "テンプレート引数型 Tp は 名前付き要件:Container を満たしません。");
			return cont == other;
		}
		template<typename Tp> static constexpr bool not_equals(const Tp& cont, const Tp& other)
		{
			static_assert(is_container<Tp>, "テンプレート引数型 Tp は 名前付き要件:Container を満たしません。");
			return cont != other;
		}
		template<typename Tp> static constexpr SizeType<Tp> size(const Tp& cont)
		{
			static_assert(is_container<Tp>, "テンプレート引数型 Tp は 名前付き要件:Container を満たしません。");
			return cont.size();
		}
		template<typename Tp> static constexpr SizeType<Tp> max_size(const Tp& cont)
		{
			static_assert(is_container<Tp>, "テンプレート引数型 Tp は 名前付き要件:Container を満たしません。");
			return cont.max_size();
		}
		template<typename Tp> static constexpr bool empty(const Tp& cont)
		{
			static_assert(is_container<Tp>, "テンプレート引数型 Tp は 名前付き要件:Container を満たしません。");
			return cont.empty();
		}
	};

	///	名前付き要件:ReversibleContainer を満たす型を識別します。
	class StdReversibleContainerTraits : public StdContainerTraits
	{
		StdReversibleContainerTraits() = delete;
		StdReversibleContainerTraits(const StdReversibleContainerTraits&) = delete;
		StdReversibleContainerTraits(StdReversibleContainerTraits&&) = delete;
		StdReversibleContainerTraits& operator=(const StdReversibleContainerTraits&) = delete;
		StdReversibleContainerTraits& operator=(StdReversibleContainerTraits&&) = delete;
		~StdReversibleContainerTraits() = delete;
	public:
		struct DoIsStdReversibleContainer_impl
		{
			template<typename Tp, typename It = typename Tp::iterator, typename V = typename Tp::value_type> static std::conjunction<std::bool_constant<StdLegacyBidirectionalIteratorTraits::is_std_legacy_bidirectional_iterator<It>>, std::is_same<typename std::iterator_traits<It>::value_type, V>> test_type_iterator(int);
			template<typename Tp> static std::false_type test_type_iterator(...);
			template<typename Tp, typename It = typename Tp::const_iterator, typename V = typename Tp::value_type> static std::conjunction<std::bool_constant<StdLegacyBidirectionalIteratorTraits::is_std_legacy_bidirectional_iterator<It>>, std::is_same<typename std::iterator_traits<It>::value_type, V>> test_type_const_iterator(int);
			template<typename Tp> static std::false_type test_type_const_iterator(...);
			template<typename Tp, typename It = typename Tp::iterator, typename Itc = typename Tp::const_iterator> static std::is_convertible<It, Itc> iterator_test_convert_const_iterator(...);
			template<typename Tp, typename It = typename Tp::reverse_iterator, typename V = typename Tp::value_type> static std::conjunction<std::bool_constant<StdLegacyBidirectionalIteratorTraits::is_std_legacy_bidirectional_iterator<It>>, std::is_same<typename std::iterator_traits<It>::value_type, V>> test_type_reverse_iterator(int);
			template<typename Tp> static std::false_type test_type_reverse_iterator(...);
			template<typename Tp, typename It = typename Tp::const_reverse_iterator, typename V = typename Tp::value_type> static std::conjunction<std::bool_constant<StdLegacyBidirectionalIteratorTraits::is_std_legacy_bidirectional_iterator<It>>, std::is_same<typename std::iterator_traits<It>::value_type, V>> test_type_const_reverse_iterator(int);
			template<typename Tp> static std::false_type test_type_const_reverse_iterator(...);
			template<typename Tp, typename It = typename Tp::reverse_iterator, typename Itc = typename Tp::const_reverse_iterator> static std::is_convertible<It, Itc> reverse_iterator_test_convert_const_reverse_iterator(...);
			template<typename Tp, typename R = decltype(std::declval<Tp&>().rbegin()), typename It = typename Tp::reverse_iterator> static std::is_same<R, It> test_func_rbegin(int);
			template<typename Tp> static std::false_type test_func_rbegin(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>().rbegin()), typename It = typename Tp::const_reverse_iterator> static std::is_same<R, It> test_const_func_rbegin(int);
			template<typename Tp> static std::false_type test_const_func_rbegin(...);
			template<typename Tp, typename R = decltype(std::declval<Tp&>().rend()), typename It = typename Tp::reverse_iterator> static std::is_same<R, It> test_func_rend(int);
			template<typename Tp> static std::false_type test_func_rend(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>().rend()), typename It = typename Tp::const_reverse_iterator> static std::is_same<R, It> test_const_func_rend(int);
			template<typename Tp> static std::false_type test_const_func_rend(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>().crbegin()), typename It = typename Tp::const_reverse_iterator> static std::is_same<R, It> test_func_crbegin(int);
			template<typename Tp> static std::false_type test_func_crbegin(...);
			template<typename Tp, typename R = decltype(std::declval<const Tp&>().crend()), typename It = typename Tp::const_reverse_iterator> static std::is_same<R, It> test_func_crend(int);
			template<typename Tp> static std::false_type test_func_crend(...);
		};
		template<typename Tp>
		struct DoIsStdReversibleContainer_t : DoIsStdReversibleContainer_impl
		{
			typedef decltype(test_type_iterator<Tp>(0)) passed_type_iterator;
			typedef decltype(test_type_const_iterator<Tp>(0)) passed_type_const_iterator;
			typedef decltype(iterator_test_convert_const_iterator<Tp>(0)) iterator_passed_convert_const_iterator;
			typedef decltype(test_type_reverse_iterator<Tp>(0)) passed_type_reverse_iterator;
			typedef decltype(test_type_const_reverse_iterator<Tp>(0)) passed_type_const_reverse_iterator;
			typedef decltype(reverse_iterator_test_convert_const_reverse_iterator<Tp>(0)) reverse_iterator_passed_convert_const_reverse_iterator;
			typedef decltype(test_func_rbegin<Tp>(0)) passed_func_rbegin;
			typedef decltype(test_const_func_rbegin<Tp>(0)) passed_const_func_rbegin;
			typedef decltype(test_func_rend<Tp>(0)) passed_func_rend;
			typedef decltype(test_const_func_rend<Tp>(0)) passed_const_func_rend;
			typedef decltype(test_func_crbegin<Tp>(0)) passed_func_crbegin;
			typedef decltype(test_func_crend<Tp>(0)) passed_func_crend;
		};
	protected:
		template<typename Tp>
		struct IsStdReversibleContainer_t :
			std::conjunction
			<
				IsStdContainer_t<Tp>,
				typename DoIsStdReversibleContainer_t<Tp>::passed_type_iterator,
				typename DoIsStdReversibleContainer_t<Tp>::passed_type_const_iterator,
				typename DoIsStdReversibleContainer_t<Tp>::iterator_passed_convert_const_iterator,
				typename DoIsStdReversibleContainer_t<Tp>::passed_type_reverse_iterator,
				typename DoIsStdReversibleContainer_t<Tp>::passed_type_const_reverse_iterator,
				typename DoIsStdReversibleContainer_t<Tp>::reverse_iterator_passed_convert_const_reverse_iterator,
				typename DoIsStdReversibleContainer_t<Tp>::passed_func_rbegin,
				typename DoIsStdReversibleContainer_t<Tp>::passed_const_func_rbegin,
				typename DoIsStdReversibleContainer_t<Tp>::passed_func_rend,
				typename DoIsStdReversibleContainer_t<Tp>::passed_const_func_rend,
				typename DoIsStdReversibleContainer_t<Tp>::passed_func_crbegin,
				typename DoIsStdReversibleContainer_t<Tp>::passed_func_crend
			>
		{};
	public:
		template<typename Tp> static constexpr bool is_reversible_container = IsStdReversibleContainer_t<Tp>::value;
	};
}
#endif // __stationaryorbit_core_stdcontainertraits
