//	stationaryorbit/core/iteratoradaptcontainer
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
#ifndef __stationaryorbit_core_iteratoradaptcontainer__
#define __stationaryorbit_core_iteratoradaptcontainer__
#include <type_traits>
#include "iteratortraits.hpp"
#include "iteratoradapter.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	このライブラリで使用されるイテレータをC++範囲ベースforで使用できるようにします。
	///	@param	T
	///	変換するイテレータの型。 @a IteratorTraits::is_sequencial_order_iterator を満たす必要があります。
	template<class T, class = void>
	class IteratorAdaptContainer
	{
		static_assert(SequencialOrderIteratorTraits::is_sequencial_order_iterator<T>, "テンプレート型 T はIteratorTraits::IsSequencialOrderIteratorを満たす必要があります。");
	public:
		typedef typename T::ValueType value_type;
		typedef typename T::ValueType& reference;
		typedef const typename T::ValueType& const_reference;
		typedef IteratorAdapter<T> iterator;
		typedef IteratorAdapter<T> const_iterator;
		typedef typename SequencialOrderIteratorTraits::IteratorDiff difference_type;
		typedef size_t size_type;
	private:
		T _itr;
	public:
		explicit constexpr IteratorAdaptContainer(const T& itr) : _itr(itr) {}

		///	最初の要素を指すイテレータを取得します。
		constexpr iterator begin() const { auto result = _itr; result.reset(); return iterator(result); }
		///	最後の要素を指すイテレータを取得します。
		constexpr iterator end() const { return IteratorAdapter<T>(nullptr); }
		///	最初の要素を指すイテレータを取得します。
		constexpr const_iterator cbegin() const { return begin(); }
		///	最後の要素を指すイテレータを取得します。
		constexpr const_iterator cend() const { return end(); }
	};

	template<class T> class IteratorReverseAdaptContainer;

	///	このライブラリで使用されるイテレータをC++範囲ベースforで使用できるようにします。
	///	@param	T
	///	変換するイテレータの型。 @a IteratorTraits::is_bidirectional_order_iterator を満たす場合の拡張が存在します。
	template<class T>
	class IteratorAdaptContainer<T, std::enable_if_t<BidirectionalOrderIteratorTraits::is_bidirectional_order_iterator<T>>>
	{
		static_assert(BidirectionalOrderIteratorTraits::is_bidirectional_order_iterator<T>, "テンプレート型 T はIteratorTraits::IsBidirectionalOrderIteratorを満たす必要があります。");
	public:
		typedef typename T::ValueType value_type;
		typedef typename T::ValueType& reference;
		typedef const typename T::ValueType& const_reference;
		typedef IteratorAdapter<T> iterator;
		typedef IteratorAdapter<T> const_iterator;
		typedef IteratorReverseAdapter<T> reverse_iterator;
		typedef IteratorReverseAdapter<T> reverse_const_iterator;
		typedef typename BidirectionalOrderIteratorTraits::IteratorDiff difference_type;
		typedef size_t size_type;
	private:
		T _itr;
	public:
		explicit constexpr IteratorAdaptContainer(const T& itr) : _itr(itr) {}

		///	イテレータの方向を反転します。
		constexpr IteratorReverseAdaptContainer<T> Reverce() const { return IteratorReverseAdaptContainer(_itr); }

		///	最初の要素を指すイテレータを取得します。
		constexpr iterator begin() const { auto result = _itr; result.reset(); return iterator(result); }
		///	最後の要素を指すイテレータを取得します。
		constexpr iterator end() const { return iterator(nullptr); }
		///	最初の要素を指すイテレータを取得します。
		constexpr const_iterator cbegin() const { return begin(); }
		///	最後の要素を指すイテレータを取得します。
		constexpr const_iterator cend() const { return end(); }
		///	最初の要素を指す逆イテレータを取得します。
		constexpr reverse_iterator rbegin() const { auto result = _itr; result.reset(IteratorOrigin::End); return reverse_iterator(result); }
		///	最後の要素を指す逆イテレータを取得します。
		constexpr reverse_iterator rend() const { return reverse_iterator(nullptr); }
		///	最初の要素を指す逆イテレータを取得します。
		constexpr reverse_const_iterator crbegin() const { return rbegin(); }
		///	最後の要素を指す逆イテレータを取得します。
		constexpr reverse_const_iterator crend() const { return rend(); }
	};
	///	このライブラリで使用される逆方向のイテレータをC++範囲ベースforで使用できるようにします。
	template<class T>
	class IteratorReverseAdaptContainer
	{
		static_assert(BidirectionalOrderIteratorTraits::is_bidirectional_order_iterator<T>, "テンプレート型 T はIteratorTraits::IsBidirectionalOrderIteratorを満たす必要があります。");
	public:
		typedef typename T::ValueType value_type;
		typedef typename T::ValueType& reference;
		typedef const typename T::ValueType& const_reference;
		typedef IteratorReverseAdapter<T> iterator;
		typedef IteratorReverseAdapter<T> const_iterator;
		typedef IteratorAdapter<T> reverse_iterator;
		typedef IteratorAdapter<T> reverse_const_iterator;
		typedef typename BidirectionalOrderIteratorTraits::IteratorDiff difference_type;
		typedef size_t size_type;
	private:
		T _itr;
	public:
		explicit constexpr IteratorReverseAdaptContainer(const T& itr) : _itr(itr) {}

		///	イテレータの方向を反転します。
		constexpr IteratorAdaptContainer<T> Reverce() const { return IteratorAdaptContainer(_itr); }

		///	最初の要素を指すイテレータを取得します。
		constexpr iterator begin() const { auto result = _itr; result.reset(IteratorOrigin::End); return iterator(result); }
		///	最後の要素を指すイテレータを取得します。
		constexpr iterator end() const { return iterator(nullptr); }
		///	最初の要素を指すイテレータを取得します。
		constexpr const_iterator cbegin() const { return begin(); }
		///	最後の要素を指すイテレータを取得します。
		constexpr const_iterator cend() const { return end(); }
		///	最初の要素を指す逆イテレータを取得します。
		constexpr reverse_iterator rbegin() const { auto result = _itr; result.reset(); return reverse_iterator(result); }
		///	最後の要素を指す逆イテレータを取得します。
		constexpr reverse_iterator rend() const { return reverse_iterator(nullptr); }
		///	最初の要素を指す逆イテレータを取得します。
		constexpr reverse_const_iterator crbegin() const { return rbegin(); }
		///	最後の要素を指す逆イテレータを取得します。
		constexpr reverse_const_iterator crend() const { return rend(); }
	};
}
#endif // __stationaryorbit_core_iteratoradaptcontainer__
