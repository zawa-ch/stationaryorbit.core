//	stationaryorbit/core/iterator
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
#ifndef __stationaryorbit_core_iteratortraits__
#define __stationaryorbit_core_iteratortraits__
#include <cstddef>
#include <type_traits>
namespace zawa_ch::StationaryOrbit
{
	///	イテレータの初期位置。
	enum class IteratorOrigin
	{
		///	範囲の先頭。
		Begin = 0,
		///	範囲の末尾。
		End = -1,
	};

	///	型要件:Iterator を満たす型を識別します。
	class IteratorTraits
	{
		IteratorTraits() = delete;
		IteratorTraits(const IteratorTraits&) = delete;
		IteratorTraits(IteratorTraits&&) = delete;
		IteratorTraits& operator=(const IteratorTraits&) = delete;
		IteratorTraits&& operator=(IteratorTraits&&) = delete;
		~IteratorTraits() = delete;
	public:
		///	イテレータの間隔を表すために用いる型。
		using IteratorDiff = std::make_signed_t<size_t>;
	public:
		struct DoIsIterator_impl
		{
			template<typename T, typename = typename T::ValueType> static std::true_type test_type_value_type(int);
			template<typename T> static std::false_type test_type_value_type(...);
			template<typename T, typename R = decltype( std::declval<const T&>().equals(std::declval<const T&>()) )> static std::is_convertible<R, bool> test_func_equals(int);
			template<typename T> static std::false_type test_func_equals(...);
			template<typename T, typename R = decltype( std::declval<const T&>().has_value() )> static std::is_convertible<R, bool> test_func_has_value(int);
			template<typename T> static std::false_type test_func_has_value(...);
			template<typename T, typename R = decltype( std::declval<const T&>().current() ), typename V = typename T::ValueType> static std::is_convertible<R, V> test_func_current(int);
			template<typename T> static std::false_type test_func_current(...);
			template<typename T, typename R = decltype( std::declval<T&>().next() )> static std::is_convertible<R, bool> test_func_next(int);
			template<typename T> static std::false_type test_func_next(...);
		};
		template<typename T>
		struct DoIsIterator_t : DoIsIterator_impl
		{
			typedef decltype(test_type_value_type<T>(0)) passed_type_value_type;
			typedef decltype(test_func_equals<T>(0)) passed_func_equals;
			typedef decltype(test_func_has_value<T>(0)) passed_func_has_value;
			typedef decltype(test_func_current<T>(0)) passed_func_current;
			typedef decltype(test_func_next<T>(0)) passed_func_next;
		};
	protected:
		template<typename T>
		struct IsIterator_t
			: std::conjunction
			<
				std::is_copy_constructible<T>,
				typename DoIsIterator_t<T>::passed_type_value_type,
				typename DoIsIterator_t<T>::passed_func_equals,
				typename DoIsIterator_t<T>::passed_func_has_value,
				typename DoIsIterator_t<T>::passed_func_current,
				typename DoIsIterator_t<T>::passed_func_next
			>
		{};
	public:
		template<typename T> static constexpr bool is_iterator = IsIterator_t<T>::value;

		template<typename T> using ValueType = typename T::ValueType;
		template<typename T> [[nodiscard]] static constexpr bool equals(const T& obj, const T& other)
		{
			static_assert(is_iterator<T>, "テンプレート引数型 T は 型要件:Iterator を満たしません。");
			return obj.equals(other);
		}
		template<typename T> [[nodiscard]] static constexpr bool has_value(const T& obj)
		{
			static_assert(is_iterator<T>, "テンプレート引数型 T は 型要件:Iterator を満たしません。");
			return obj.has_value();
		}
		template<typename T> [[nodiscard]] static constexpr ValueType<T> current(const T& obj)
		{
			static_assert(is_iterator<T>, "テンプレート引数型 T は 型要件:Iterator を満たしません。");
			return obj.current();
		}
		template<typename T> static constexpr bool next(T& obj)
		{
			static_assert(is_iterator<T>, "テンプレート引数型 T は 型要件:Iterator を満たしません。");
			return obj.next();
		}
	};

	///	型要件:SequencialOrderIterator を満たす型を識別します。
	class SequencialOrderIteratorTraits : public IteratorTraits
	{
		SequencialOrderIteratorTraits() = delete;
		SequencialOrderIteratorTraits(const SequencialOrderIteratorTraits&) = delete;
		SequencialOrderIteratorTraits(SequencialOrderIteratorTraits&&) = delete;
		SequencialOrderIteratorTraits& operator=(const SequencialOrderIteratorTraits&) = delete;
		SequencialOrderIteratorTraits& operator=(SequencialOrderIteratorTraits&&) = delete;
		~SequencialOrderIteratorTraits() = delete;
	private:
		struct DoIsSequencialOrderIterator_impl
		{
			template<typename T, typename = decltype( std::declval<T&>().reset() )> static std::true_type test_func_reset(int);
			template<typename T> static std::false_type test_func_reset(...);
		};
		template<typename T>
		struct DoIsSequencialOrderIterator_t : DoIsSequencialOrderIterator_impl
		{
			typedef decltype(test_func_reset<T>(0)) passed_func_reset;
		};
	protected:
		template<class T>
		struct IsSequencialOrderIterator_t
			: std::conjunction
			<
				IsIterator_t<T>,
				typename DoIsSequencialOrderIterator_t<T>::passed_func_reset
			>
		{};
	public:
		template<class T> constexpr static bool is_sequencial_order_iterator = IsSequencialOrderIterator_t<T>::value;

		template<typename T> static constexpr void reset(T& obj)
		{
			static_assert(is_sequencial_order_iterator<T>, "テンプレート引数型 T は 型要件:SequencialOrderIterator を満たしません。");
			obj.reset();
		}
	};

	///	型要件:BidirectionalOrderIterator を満たす型を識別します。
	class BidirectionalOrderIteratorTraits : public SequencialOrderIteratorTraits
	{
		BidirectionalOrderIteratorTraits() = delete;
		BidirectionalOrderIteratorTraits(const BidirectionalOrderIteratorTraits&) = delete;
		BidirectionalOrderIteratorTraits(BidirectionalOrderIteratorTraits&&) = delete;
		BidirectionalOrderIteratorTraits& operator=(const BidirectionalOrderIteratorTraits&) = delete;
		BidirectionalOrderIteratorTraits& operator=(BidirectionalOrderIteratorTraits&&) = delete;
		~BidirectionalOrderIteratorTraits() = delete;
	private:
		struct DoIsBidirectionalOrderIterator_impl
		{
			template<typename T, typename R = decltype( std::declval<T&>().previous() )> static std::is_convertible<R, bool> test_func_previous(int);
			template<typename T> static std::false_type test_func_previous(...);
			template<typename T, typename = decltype( std::declval<T&>().reset(std::declval<const IteratorOrigin&>()) )> static std::true_type test_func_reset(int);
			template<typename T> static std::false_type test_func_reset(...);
			template<typename T, typename R = decltype( std::declval<const T&>().is_before_begin() )> static std::is_convertible<R, bool> test_func_is_before_begin(int);
			template<typename T> static std::false_type test_func_is_before_begin(...);
			template<typename T, typename R = decltype( std::declval<const T&>().is_after_end() )> static std::is_convertible<R, bool> test_func_is_after_end(int);
			template<typename T> static std::false_type test_func_is_after_end(...);
		};
		template<typename T>
		struct DoIsBidirectionalOrderIterator_t : DoIsBidirectionalOrderIterator_impl
		{
			typedef decltype(test_func_previous<T>(0)) passed_func_previous;
			typedef decltype(test_func_reset<T>(0)) passed_func_reset;
			typedef decltype(test_func_is_before_begin<T>(0)) passed_func_is_before_begin;
			typedef decltype(test_func_is_after_end<T>(0)) passed_func_is_after_end;
		};
	protected:
		template<class T>
		struct IsBidirectionalOrderIterator_t
			: std::conjunction
			<
				IsSequencialOrderIterator_t<T>,
				typename DoIsBidirectionalOrderIterator_t<T>::passed_func_previous,
				typename DoIsBidirectionalOrderIterator_t<T>::passed_func_reset,
				typename DoIsBidirectionalOrderIterator_t<T>::passed_func_is_before_begin,
				typename DoIsBidirectionalOrderIterator_t<T>::passed_func_is_after_end
			>
		{};
	public:
		template<class T> inline constexpr static bool is_bidirectional_order_iterator = IsBidirectionalOrderIterator_t<T>::value;
	};

	///	型要件:LinearOrderIterator を満たす型を識別します。
	class LinearOrderIteratorTraits : public BidirectionalOrderIteratorTraits
	{
		LinearOrderIteratorTraits() = delete;
		LinearOrderIteratorTraits(const LinearOrderIteratorTraits&) = delete;
		LinearOrderIteratorTraits(LinearOrderIteratorTraits&&) = delete;
		LinearOrderIteratorTraits& operator=(const LinearOrderIteratorTraits&) = delete;
		LinearOrderIteratorTraits& operator=(LinearOrderIteratorTraits&&) = delete;
		~LinearOrderIteratorTraits() = delete;
	private:
		struct DoIsLinearOrderIterator_impl
		{
			template<typename T, typename R = decltype( std::declval<T&>().next(std::declval<const IteratorDiff&>()) )> static std::is_convertible<R, bool> test_func_next(int);
			template<typename T> static std::false_type test_func_next(...);
			template<typename T, typename R = decltype( std::declval<T&>().previous(std::declval<const IteratorDiff&>()) )> static std::is_convertible<R, bool> test_func_previous(int);
			template<typename T> static std::false_type test_func_previous(...);
			template<typename T, typename R = decltype( std::declval<const T&>().distance(std::declval<const T&>()) )> static std::is_convertible<R, IteratorDiff> test_func_distance(int);
			template<typename T> static std::false_type test_func_distance(...);
			template<typename T, typename R = decltype( std::declval<const T&>().compare(std::declval<const T&>()) )> static std::is_convertible<R, int> test_func_compare(int);
			template<typename T> static std::false_type test_func_compare(...);
		};
		template<typename T>
		struct DoIsLinearOrderIterator_t : DoIsLinearOrderIterator_impl
		{
			typedef decltype(test_func_next<T>(0)) passed_func_next;
			typedef decltype(test_func_previous<T>(0)) passed_func_previous;
			typedef decltype(test_func_distance<T>(0)) passed_func_distance;
			typedef decltype(test_func_compare<T>(0)) passed_func_compare;
		};
	protected:
		template<class T>
		struct IsLinearOrderIterator_t
			: std::conjunction
			<
				IsBidirectionalOrderIterator_t<T>,
				typename DoIsLinearOrderIterator_t<T>::passed_func_next,
				typename DoIsLinearOrderIterator_t<T>::passed_func_previous,
				typename DoIsLinearOrderIterator_t<T>::passed_func_distance,
				typename DoIsLinearOrderIterator_t<T>::passed_func_compare
			>
		{};
	public:
		template<class T> inline constexpr static bool is_linear_order_iterator = IsLinearOrderIterator_t<T>::value;
	};
}
#endif // __stationaryorbit_core_iteratortraits__
