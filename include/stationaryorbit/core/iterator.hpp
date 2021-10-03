//	stationaryorbit/core/iterator
//	Copyright 2020 zawa-ch.
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
#ifndef __stationaryorbit_core_iterator__
#define __stationaryorbit_core_iterator__
#include <stdexcept>
#include <utility>
#include <functional>
#include <optional>
#include "iteratortraits.hpp"
#include "invalidoperation.hpp"
namespace zawa_ch::StationaryOrbit
{
	#if 0
	template<class T, std::enable_if_t<IteratorTraits::is_iterator<T>, int> = 0>
	T& operator++(T& value) { (void)value.next(); return value; }

	template<class T, std::enable_if_t<IteratorTraits::is_iterator<T>, int> = 0>
	T operator++(T& value, int) { auto result = value; (void)value.next(); return result; }

	template<class T, std::enable_if_t<IteratorTraits::is_iterator<T>, int> = 0>
	const typename T::ValueType& operator*(const T& value) { return value.current(); }

	template<class T, std::enable_if_t<SequencialOrderIteratorTraits::is_sequencial_order_iterator<T>, int> = 0>
	bool operator==(const T& value, const T& other) { return value.equals(other); }

	template<class T, std::enable_if_t<SequencialOrderIteratorTraits::is_sequencial_order_iterator<T>, int> = 0>
	bool operator!=(const T& value, const T& other) { return !value.equals(other); }

	template<class T, std::enable_if_t<BidirectionalOrderIteratorTraits::is_bidirectional_order_iterator<T>, int> = 0>
	T& operator--(T& value) { (void)value.previous(); return value; }

	template<class T, std::enable_if_t<BidirectionalOrderIteratorTraits::is_bidirectional_order_iterator<T>, int> = 0>
	T operator--(T& value, int) { auto result = value; (void)value.previous(); return result; }

	template<class T, std::enable_if_t<LinearOrderIteratorTraits::is_linear_order_iterator<T>, int> = 0>
	T& operator+=(T& value, const LinearOrderIteratorTraits::IteratorDiff& diff) { (void)value.next(diff); return value; }

	template<class T, std::enable_if_t<LinearOrderIteratorTraits::is_linear_order_iterator<T>, int> = 0>
	T operator+(const T& value, const LinearOrderIteratorTraits::IteratorDiff& diff) { auto result = value; (void)result.next(diff); return result; }

	template<class T, std::enable_if_t<LinearOrderIteratorTraits::is_linear_order_iterator<T>, int> = 0>
	T& operator-=(T& value, const LinearOrderIteratorTraits::IteratorDiff& diff) { (void)value.previous(diff); return value; }

	template<class T, std::enable_if_t<LinearOrderIteratorTraits::is_linear_order_iterator<T>, int> = 0>
	T operator-(const T& value, const LinearOrderIteratorTraits::IteratorDiff& diff) { auto result = value; (void)result.previous(diff); return result; }

	template<class T, std::enable_if_t<LinearOrderIteratorTraits::is_linear_order_iterator<T>, int> = 0>
	LinearOrderIteratorTraits::IteratorDiff operator-(const T& value, const T& other) { return value.distance(other); }

	template<class T, std::enable_if_t<LinearOrderIteratorTraits::is_linear_order_iterator<T>, int> = 0>
	T operator<(const T& value, const T& other) { return value.compare(other) < 0; }

	template<class T, std::enable_if_t<LinearOrderIteratorTraits::is_linear_order_iterator<T>, int> = 0>
	T operator>(const T& value, const T& other) { return value.compare(other) > 0; }

	template<class T, std::enable_if_t<LinearOrderIteratorTraits::is_linear_order_iterator<T>, int> = 0>
	T operator<=(const T& value, const T& other) { return value.compare(other) <= 0; }

	template<class T, std::enable_if_t<LinearOrderIteratorTraits::is_linear_order_iterator<T>, int> = 0>
	T operator>=(const T& value, const T& other) { return value.compare(other) >= 0; }
	#endif
	///	イテレータを使用した処理を行います。
	class ItrProcesser
	{
	public:
		///	イテレータで列挙されるすべての要素に対して、指定された述語を適用します。
		///	@note
		///	計算時間はイテレータの要素数に比例。
		template<class It, class resultT = typename It::ValueType, class predT = std::function<void(resultT)>>
		constexpr static void ForEach(It iter, const predT& pred)
		{
			iter.reset();
			while(iter.has_value()) { pred(iter.current()); (void)iter.next(); }
		}
	};

	///	このライブラリで使用されるイテレータをC++標準のイテレータに変換します。
	///	@param	T
	///	変換するイテレータの型。 @a IteratorTraits::is_iterator を満たす必要があります。
	template<class T, class = void>
	class IteratorAdapter
	{
		static_assert(IteratorTraits::is_iterator<T>, "テンプレート型 T はIteratorTraits::IsIteratorを満たす必要があります。");
		template<class, class> friend class IteratorAdaptContainer;
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
			if (other._itr.has_value()) { return _itr->equals(*(other._itr)); }
			else { return !_itr->has_value(); }
		}
		constexpr bool operator==(const IteratorAdapter<T>& other) const { return equals(other); }
		constexpr bool operator!=(const IteratorAdapter<T>& other) const { return !equals(other); }
		constexpr typename std::iterator_traits<IteratorAdapter<T>>::reference operator*() const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->current();
		}
		constexpr IteratorAdapter<T>& operator++()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->next();
			return *this;
		}
		constexpr IteratorAdapter<T> operator++(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)_itr->next();
			return result;
		}
	};
	///	このライブラリで使用されるイテレータをC++標準のイテレータに変換します。
	///	@param	T
	///	変換するイテレータの型。 @a IteratorTraits::is_bidirectional_order_iterator を満たす場合の拡張が存在します。
	template<class T>
	class IteratorAdapter<T, std::enable_if_t<BidirectionalOrderIteratorTraits::is_bidirectional_order_iterator<T> && !LinearOrderIteratorTraits::is_linear_order_iterator<T>>>
	{
		static_assert(BidirectionalOrderIteratorTraits::is_bidirectional_order_iterator<T>, "テンプレート型 T はIteratorTraits::IsBidirectionalOrderIteratorを満たす必要があります。");
		template<class, class> friend class IteratorAdaptContainer;
		template<class> friend class IteratorReverseAdaptContainer;
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
			if (other._itr.has_value()) { return _itr->equals(*(other._itr)); }
			else { return !_itr->has_value(); }
		}
		constexpr bool operator==(const IteratorAdapter<T>& other) const { return equals(other); }
		constexpr bool operator!=(const IteratorAdapter<T>& other) const { return !equals(other); }
		constexpr typename std::iterator_traits<IteratorAdapter<T>>::reference operator*() const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->current();
		}
		constexpr IteratorAdapter<T>& operator++()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->next();
			return *this;
		}
		constexpr IteratorAdapter<T> operator++(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)_itr->next();
			return result;
		}
		constexpr IteratorAdapter<T>& operator--()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->previous();
			return *this;
		}
		constexpr IteratorAdapter<T> operator--(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)_itr->previous();
			return result;
		}
	};
	///	このライブラリで使用されるイテレータをC++標準のイテレータに変換します。
	///	@param	T
	///	変換するイテレータの型。 @a IteratorTraits::is_linear_order_iterator を満たす場合の拡張が存在します。
	template<class T>
	class IteratorAdapter<T, std::enable_if_t<LinearOrderIteratorTraits::is_linear_order_iterator<T>>>
	{
		static_assert(LinearOrderIteratorTraits::is_linear_order_iterator<T>, "テンプレート型 T はIteratorTraits::IsLinearOrderIteratorを満たす必要があります。");
		template<class, class> friend class IteratorAdaptContainer;
		template<class> friend class IteratorReverseAdaptContainer;
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
			if (other._itr.has_value()) { return _itr->equals(*(other._itr)); }
			else { return !_itr->has_value(); }
		}
		constexpr bool operator==(const IteratorAdapter<T>& other) const { return equals(other); }
		constexpr bool operator!=(const IteratorAdapter<T>& other) const { return !equals(other); }
		constexpr typename std::iterator_traits<IteratorAdapter<T>>::reference operator*() const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->current();
		}
		constexpr IteratorAdapter<T>& operator++()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->next();
			return *this;
		}
		constexpr IteratorAdapter<T> operator++(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)_itr->next();
			return result;
		}
		constexpr IteratorAdapter<T>& operator--()
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->previous();
			return *this;
		}
		constexpr IteratorAdapter<T> operator--(int)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)_itr->previous();
			return result;
		}
		constexpr IteratorAdapter<T>& operator+=(const typename std::iterator_traits<IteratorAdapter<T>>::difference_type& count)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->next(count);
			return *this;
		}
		constexpr IteratorAdapter<T> operator+(const typename std::iterator_traits<IteratorAdapter<T>>::difference_type& count) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)result._itr->next(count);
			return result;
		}
		constexpr IteratorAdapter<T>& operator-=(const typename std::iterator_traits<IteratorAdapter<T>>::difference_type& count)
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			(void)_itr->previous(count);
			return *this;
		}
		constexpr IteratorAdapter<T> operator-(const typename std::iterator_traits<IteratorAdapter<T>>::difference_type& count) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)result._itr->previous(count);
			return result;
		}
		constexpr typename std::iterator_traits<IteratorAdapter<T>>::difference_type& operator-(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			if (!other._itr.has_value()) { throw InvalidOperationException("指定されたオブジェクトはイテレータを持ちません。"); }
			return _itr->distance(other._itr.value());
		}
		constexpr typename std::iterator_traits<IteratorAdapter<T>>::reference operator[](const typename std::iterator_traits<IteratorAdapter<T>>::difference_type& count) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			auto result = *this;
			(void)result._itr->next(count);
			return result._itr->current();
		}
		constexpr bool operator<(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->compare(other._itr.value()) < 0;
		}
		constexpr bool operator>(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->compare(other._itr.value()) > 0;
		}
		constexpr bool operator<=(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->compare(other._itr.value()) <= 0;
		}
		constexpr bool operator>=(const IteratorAdapter<T>& other) const
		{
			if (!_itr.has_value()) { throw InvalidOperationException("このオブジェクトはイテレータを持ちません。"); }
			return _itr->compare(other._itr.value()) >= 0;
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

	template<class contT, class T = typename contT::value_type>
	class LegacyIterator
	{
	public:
		typedef contT ContainerType;
		typedef T ValueType;
	private:
		const ContainerType& _cont;
		typename contT::const_iterator _itr;
	public:
		LegacyIterator(const ContainerType& container) : _cont(container) {}
		virtual void reset() { _itr = _cont.cbegin(); }
		virtual bool has_value() const { return _itr != _cont.cend(); }
		virtual const T& current() const { if (has_value()) { return *_itr; } else { throw std::out_of_range("要素の範囲外にあるイテレータに対して逆参照を試みました。"); } }
		virtual bool next() { if (has_value()) { ++_itr; } return _itr != _cont.cend(); }
	};

	template<class contT, class T = typename contT::value_type>
	class LegacyReverseIterator
	{
	public:
		typedef contT ContainerType;
		typedef T ValueType;
	private:
		const ContainerType& _cont;
		typename contT::const_reverse_iterator _itr;
	public:
		LegacyReverseIterator(const ContainerType& container) : _cont(container) {}
		virtual void reset() { _itr = _cont.crbegin(); }
		virtual bool has_value() const { return _itr != _cont.crend(); }
		virtual const T& current() const { if (has_value()) { return *_itr; } else { throw std::out_of_range("要素の範囲外にあるイテレータに対して逆参照を試みました。"); } }
		virtual bool next() { if (has_value()) { ++_itr; } return _itr != _cont.crend(); }
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
#endif // __stationaryorbit_core_iterator__