//	stationaryorbit/core/iteratoradapter
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
#ifndef __stationaryorbit_core_iteratoradapter__
#define __stationaryorbit_core_iteratoradapter__
#include <type_traits>
#include <utility>
#include <optional>
#include "iteratortraits.hpp"
#include "invalidoperation.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	このライブラリで使用されるイテレータをC++標準のイテレータに変換します。
	///	@param	T
	///	変換するイテレータの型。 @a IteratorTraits::is_iterator を満たす必要があります。
	template<class T, class = void>
	class IteratorAdapter
	{
		static_assert(IteratorTraits::is_iterator<T>, "テンプレート型 T は 型要件:Iterator を満たす必要があります。");
		template<class, class> friend class IteratorAdaptContainer;
	public:
		typedef IteratorTraits::ValueType<T> ValueType;
		typedef IteratorTraits::ValueType<T> Refernece;
		typedef const IteratorTraits::ValueType<T> ConstRefernece;
		typedef const IteratorTraits::ValueType<T>* Pointer;
		typedef IteratorTraits::IteratorDiff DifferenceType;
		typedef std::input_iterator_tag IteratorCategory;
	private:
		std::optional<T> _itr;
	public:
		///	イテレータを渡してオブジェクトを生成します。
		constexpr explicit IteratorAdapter(const T& itr) : _itr(itr) {}
	private:
		///	イテレータの持たないオブジェクトを生成します。
		constexpr explicit IteratorAdapter(const std::nullptr_t& itr) : _itr(std::nullopt) {}

	public:
		///	指定されたオブジェクトと等価であるか比較します。
		constexpr bool equals(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { return !other._itr.has_value(); }
			if (other._itr.has_value()) { return IteratorTraits::equals(_itr.value(), other._itr.value()); }
			else { return !IteratorTraits::has_value(_itr.value()); }
		}
		constexpr bool operator==(const IteratorAdapter<T>& other) const { return equals(other); }
		constexpr bool operator!=(const IteratorAdapter<T>& other) const { return !equals(other); }
		constexpr Refernece operator*() const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return IteratorTraits::current(_itr.value());
		}
		constexpr IteratorAdapter<T>& operator++()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)IteratorTraits::next(_itr.value());
			return *this;
		}
		constexpr IteratorAdapter<T> operator++(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)IteratorTraits::next(_itr.value());
			return result;
		}
	};
	///	このライブラリで使用されるイテレータをC++標準のイテレータに変換します。
	///	@param	T
	///	変換するイテレータの型。 @a IteratorTraits::is_bidirectional_order_iterator を満たす場合の拡張が存在します。
	template<class T>
	class IteratorAdapter<T, std::enable_if_t<BidirectionalOrderIteratorTraits::is_bidirectional_order_iterator<T> && !LinearOrderIteratorTraits::is_linear_order_iterator<T>>>
	{
		static_assert(BidirectionalOrderIteratorTraits::is_bidirectional_order_iterator<T>, "テンプレート型 T は 型要件:BidirectionalOrderIterator を満たす必要があります。");
		template<class, class> friend class IteratorAdaptContainer;
		template<class> friend class IteratorReverseAdaptContainer;
	public:
		typedef BidirectionalOrderIteratorTraits::ValueType<T> ValueType;
		typedef BidirectionalOrderIteratorTraits::ValueType<T> Refernece;
		typedef const BidirectionalOrderIteratorTraits::ValueType<T> ConstRefernece;
		typedef const BidirectionalOrderIteratorTraits::ValueType<T>* Pointer;
		typedef BidirectionalOrderIteratorTraits::IteratorDiff DifferenceType;
		typedef std::bidirectional_iterator_tag IteratorCategory;
	private:
		std::optional<T> _itr;
	public:
		///	イテレータを渡してオブジェクトを生成します。
		constexpr explicit IteratorAdapter(const T& itr) : _itr(itr) {}
	private:
		///	イテレータの持たないオブジェクトを生成します。
		constexpr explicit IteratorAdapter(const std::nullptr_t& itr) : _itr(std::nullopt) {}

	public:
		///	指定されたオブジェクトと等価であるか比較します。
		constexpr bool equals(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { return !other._itr.has_value(); }
			if (other._itr.has_value()) { return BidirectionalOrderIteratorTraits::equals(_itr.value(), other._itr.value()); }
			else { return !BidirectionalOrderIteratorTraits::has_value(_itr.value()); }
		}
		constexpr bool operator==(const IteratorAdapter<T>& other) const { return equals(other); }
		constexpr bool operator!=(const IteratorAdapter<T>& other) const { return !equals(other); }
		constexpr Refernece operator*() const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return BidirectionalOrderIteratorTraits::current(_itr.value());
		}
		constexpr IteratorAdapter<T>& operator++()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)BidirectionalOrderIteratorTraits::next(_itr.value());
			return *this;
		}
		constexpr IteratorAdapter<T> operator++(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)BidirectionalOrderIteratorTraits::next(_itr.value());
			return result;
		}
		constexpr IteratorAdapter<T>& operator--()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)BidirectionalOrderIteratorTraits::previous(_itr.value());
			return *this;
		}
		constexpr IteratorAdapter<T> operator--(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)BidirectionalOrderIteratorTraits::previous(_itr.value());
			return result;
		}
	};
	///	このライブラリで使用されるイテレータをC++標準のイテレータに変換します。
	///	@param	T
	///	変換するイテレータの型。 @a IteratorTraits::is_linear_order_iterator を満たす場合の拡張が存在します。
	template<class T>
	class IteratorAdapter<T, std::enable_if_t<LinearOrderIteratorTraits::is_linear_order_iterator<T>>>
	{
		static_assert(LinearOrderIteratorTraits::is_linear_order_iterator<T>, "テンプレート型 T は 型要件:LinearOrderIterator を満たす必要があります。");
		template<class, class> friend class IteratorAdaptContainer;
		template<class> friend class IteratorReverseAdaptContainer;
	public:
		typedef LinearOrderIteratorTraits::ValueType<T> ValueType;
		typedef LinearOrderIteratorTraits::ValueType<T> Refernece;
		typedef const LinearOrderIteratorTraits::ValueType<T> ConstRefernece;
		typedef const LinearOrderIteratorTraits::ValueType<T>* Pointer;
		typedef LinearOrderIteratorTraits::IteratorDiff DifferenceType;
		typedef std::random_access_iterator_tag IteratorCategory;
	private:
		std::optional<T> _itr;
	public:
		///	イテレータを渡してオブジェクトを生成します。
		constexpr explicit IteratorAdapter(const T& itr) : _itr(itr) {}
	private:
		///	イテレータの持たないオブジェクトを生成します。
		constexpr explicit IteratorAdapter(const std::nullptr_t& itr) : _itr(std::nullopt) {}

	public:
		///	指定されたオブジェクトと等価であるか比較します。
		constexpr bool equals(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { return !other._itr.has_value(); }
			if (other._itr.has_value()) { return LinearOrderIteratorTraits::equals(_itr.value(), other._itr.value()); }
			else { return !LinearOrderIteratorTraits::has_value(_itr.value()); }
		}
		constexpr bool operator==(const IteratorAdapter<T>& other) const { return equals(other); }
		constexpr bool operator!=(const IteratorAdapter<T>& other) const { return !equals(other); }
		constexpr Refernece operator*() const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return LinearOrderIteratorTraits::current(_itr.value());
		}
		constexpr IteratorAdapter<T>& operator++()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)LinearOrderIteratorTraits::next(_itr.value());
			return *this;
		}
		constexpr IteratorAdapter<T> operator++(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			IteratorAdapter<T> result = *this;
			(void)LinearOrderIteratorTraits::next(_itr.value());
			return result;
		}
		constexpr IteratorAdapter<T>& operator--()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)LinearOrderIteratorTraits::previous(_itr.value());
			return *this;
		}
		constexpr IteratorAdapter<T> operator--(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			IteratorAdapter<T> result = *this;
			(void)LinearOrderIteratorTraits::next(_itr.value());
			return result;
		}
		constexpr IteratorAdapter<T>& operator+=(const DifferenceType& count)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)LinearOrderIteratorTraits::next(_itr.value());
			return *this;
		}
		constexpr IteratorAdapter<T> operator+(const DifferenceType& count) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			IteratorAdapter<T> result = *this;
			(void)LinearOrderIteratorTraits::next(result._itr.value(), count);
			return result;
		}
		constexpr IteratorAdapter<T>& operator-=(const DifferenceType& count)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)LinearOrderIteratorTraits::previous(_itr.value(), count);
			return *this;
		}
		constexpr IteratorAdapter<T> operator-(const DifferenceType& count) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			IteratorAdapter<T> result = *this;
			(void)LinearOrderIteratorTraits::previous(result._itr.value(), count);
			return result;
		}
		constexpr DifferenceType operator-(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			if (!other._itr.has_value()) { throw InvalidOperationException("指定されたオブジェクトはイテレータを持ちません。"); }
			return LinearOrderIteratorTraits::distance(_itr.value(), other._itr.value());
		}
		constexpr Refernece operator[](const DifferenceType& count) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			IteratorAdapter<T> result = *this;
			(void)LinearOrderIteratorTraits::next(result._itr.value(), count);
			return LinearOrderIteratorTraits::current(result._itr.value());
		}
		constexpr bool operator<(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return LinearOrderIteratorTraits::compare(_itr.value(), other._itr.value()) < 0;
		}
		constexpr bool operator>(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return LinearOrderIteratorTraits::compare(_itr.value(), other._itr.value()) > 0;
		}
		constexpr bool operator<=(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return LinearOrderIteratorTraits::compare(_itr.value(), other._itr.value()) <= 0;
		}
		constexpr bool operator>=(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return LinearOrderIteratorTraits::compare(_itr.value(), other._itr.value()) >= 0;
		}
	};

	///	このライブラリで使用されるイテレータをC++標準の逆イテレータに変換します。
	///	@param	T
	///	変換するイテレータの型。 @a IteratorTraits::is_bidirectional_order_iterator を満たす必要があります。
	template<class T, class = void>
	class IteratorReverseAdapter
	{
		static_assert(BidirectionalOrderIteratorTraits::is_bidirectional_order_iterator<T>, "テンプレート型 T はIteratorTraits::IsBidirectionalOrderIteratorを満たす必要があります。");
		template<class, class> friend class IteratorAdaptContainer;
		template<class> friend class IteratorReverseAdaptContainer;
	private:
		std::optional<T> _itr;
	public:
		///	イテレータを渡してオブジェクトを生成します。
		constexpr explicit IteratorReverseAdapter(const T& itr) : _itr(itr) {}
	private:
		///	イテレータの持たないオブジェクトを生成します。
		constexpr explicit IteratorReverseAdapter(const std::nullptr_t& itr) : _itr(std::nullopt) {}

	public:
		///	指定されたオブジェクトと等価であるか比較します。
		constexpr bool equals(const IteratorReverseAdapter<T>& other) const
		{
			if (!_itr.has_value()) { return !other._itr.has_value(); }
			if (other._itr.has_value()) { return _itr->equals(*(other._itr)); }
			else { return !_itr->has_value(); }
		}
		constexpr bool operator==(const IteratorReverseAdapter<T>& other) const { return equals(other); }
		constexpr bool operator!=(const IteratorReverseAdapter<T>& other) const { return !equals(other); }
		constexpr typename std::iterator_traits<IteratorReverseAdapter<T>>::reference operator*() const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->current();
		}
		constexpr IteratorReverseAdapter<T>& operator++()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->previous();
			return *this;
		}
		constexpr IteratorReverseAdapter<T> operator++(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)_itr->previous();
			return result;
		}
		constexpr IteratorReverseAdapter<T>& operator--()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->next();
			return *this;
		}
		constexpr IteratorReverseAdapter<T> operator--(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)_itr->next();
			return result;
		}
	};
	///	このライブラリで使用されるイテレータをC++標準の逆イテレータに変換します。
	///	@param	T
	///	変換するイテレータの型。 @a IteratorTraits::is_linear_order_iterator を満たす場合の拡張が存在します。
	template<class T>
	class IteratorReverseAdapter<T, std::enable_if_t<LinearOrderIteratorTraits::is_linear_order_iterator<T>>>
	{
		static_assert(LinearOrderIteratorTraits::is_linear_order_iterator<T>, "テンプレート型 T はIteratorTraits::IsLinearOrderIteratorを満たす必要があります。");
		template<class, class> friend class IteratorAdaptContainer;
		template<class> friend class IteratorReverseAdaptContainer;
	private:
		std::optional<T> _itr;
	public:
		///	イテレータを渡してオブジェクトを生成します。
		constexpr explicit IteratorReverseAdapter(const T& itr) : _itr(itr) {}
	private:
		///	イテレータの持たないオブジェクトを生成します。
		constexpr explicit IteratorReverseAdapter(const std::nullptr_t& itr) : _itr(std::nullopt) {}

	public:
		///	指定されたオブジェクトと等価であるか比較します。
		constexpr bool equals(const IteratorReverseAdapter<T>& other) const
		{
			if (!_itr.has_value()) { return !other._itr.has_value(); }
			if (other._itr.has_value()) { return _itr->equals(*(other._itr)); }
			else { return !_itr->has_value(); }
		}
		constexpr bool operator==(const IteratorReverseAdapter<T>& other) const { return equals(other); }
		constexpr bool operator!=(const IteratorReverseAdapter<T>& other) const { return !equals(other); }
		constexpr typename std::iterator_traits<IteratorReverseAdapter<T>>::reference operator*() const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->current();
		}
		constexpr IteratorReverseAdapter<T>& operator++()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->previous();
			return *this;
		}
		constexpr IteratorReverseAdapter<T> operator++(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)_itr->previous();
			return result;
		}
		constexpr IteratorReverseAdapter<T>& operator--()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->next();
			return *this;
		}
		constexpr IteratorReverseAdapter<T> operator--(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)_itr->next();
			return result;
		}
		constexpr IteratorAdapter<T>& operator+=(const typename std::iterator_traits<IteratorAdapter<T>>::difference_type& count)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->previous(count);
			return *this;
		}
		constexpr IteratorAdapter<T> operator+(const typename std::iterator_traits<IteratorAdapter<T>>::difference_type& count) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)result._itr->previous(count);
			return result;
		}
		constexpr IteratorAdapter<T>& operator-=(const typename std::iterator_traits<IteratorAdapter<T>>::difference_type& count)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->next(count);
			return *this;
		}
		constexpr IteratorAdapter<T> operator-(const typename std::iterator_traits<IteratorAdapter<T>>::difference_type& count) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)result._itr->next(count);
			return result;
		}
		constexpr typename std::iterator_traits<IteratorAdapter<T>>::difference_type& operator-(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			if (!other._itr.has_value()) { throw InvalidOperationException("指定されたオブジェクトはイテレータを持ちません。"); }
			return other._itr->distance(_itr.value());
		}
		constexpr typename std::iterator_traits<IteratorAdapter<T>>::reference operator[](const typename std::iterator_traits<IteratorAdapter<T>>::difference_type& count) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)result._itr->previous(count);
			return result._itr->current();
		}
		constexpr bool operator<(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->compare(other._itr.value()) > 0;
		}
		constexpr bool operator>(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->compare(other._itr.value()) < 0;
		}
		constexpr bool operator<=(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->compare(other._itr.value()) >= 0;
		}
		constexpr bool operator>=(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->compare(other._itr.value()) <= 0;
		}
	};
}
namespace std
{
	template<class T>
	class iterator_traits<zawa_ch::StationaryOrbit::IteratorAdapter<T>>
	{
	public:
		typedef typename T::ValueType value_type;
		typedef zawa_ch::StationaryOrbit::IteratorTraits::IteratorDiff difference_type;
		typedef const value_type& reference;
		typedef const value_type* pointer;
		typedef std::input_iterator_tag iteretor_category;
	};
	template<class T>
	class iterator_traits<zawa_ch::StationaryOrbit::IteratorReverseAdapter<T>>
	{
	public:
		typedef typename T::ValueType value_type;
		typedef zawa_ch::StationaryOrbit::IteratorTraits::IteratorDiff difference_type;
		typedef const value_type& reference;
		typedef const value_type* pointer;
		typedef std::input_iterator_tag iteretor_category;
	};
}
#endif // __stationaryorbit_core_iteratoradapter__
