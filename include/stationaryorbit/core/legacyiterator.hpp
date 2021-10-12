//	stationaryorbit/core/legacyiterator
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
#ifndef __stationaryorbit_core_legacyiterator__
#define __stationaryorbit_core_legacyiterator__
#include <type_traits>
#include <stdexcept>
#include "stditeratortraits.hpp"
#include "stdcontainertraits.hpp"
namespace zawa_ch::StationaryOrbit
{
	template<typename contT, typename> class LegacyIterator;
	template<typename contT> class LegacyReverseIterator;

	///	C++標準のコンテナをライブラリのイテレータに変換します。
	template<typename contT, typename = std::void_t<>>
	class LegacyIterator final
	{
		static_assert(StdContainerTraits::is_container<contT>, "テンプレート引数型 contT は 名前付き要件:Container を満たす必要があります。");
	public:
		typedef contT ContainerType;
		typedef typename contT::value_type ValueType;
	private:
		const ContainerType& _cont;
		StdContainerTraits::ConstIterator<contT> _itr;

		constexpr LegacyIterator(const ContainerType& container, const StdContainerTraits::ConstIterator<contT>& iterator) : _cont(container), _itr(iterator) {}
	public:
		constexpr LegacyIterator(const ContainerType& container) : LegacyIterator(container, StdContainerTraits::cbegin(container)) {}
		[[nodiscard]] constexpr bool equals(const LegacyIterator<contT>& other) const { return StdLegacyForwardIteratorTraits::equals(_itr, other._itr); }
		[[nodiscard]] constexpr bool operator==(const LegacyIterator<contT>& other) const { return equals(other); }
		[[nodiscard]] constexpr bool operator!=(const LegacyIterator<contT>& other) const { return !equals(other); }
		[[nodiscard]] constexpr bool has_value() const { return StdLegacyForwardIteratorTraits::not_equals(_itr, StdContainerTraits::cend(_cont)); }
		[[nodiscard]] constexpr StdContainerTraits::ConstReference<contT> current() const { if (has_value()) { return StdLegacyForwardIteratorTraits::dereference(_itr); } else { throw std::out_of_range("要素の範囲外にあるイテレータに対して逆参照を試みました。"); } }
		constexpr bool next() { if (has_value()) { StdLegacyForwardIteratorTraits::next(_itr); } return has_value(); }
		constexpr void reset() { _itr = StdContainerTraits::cbegin(_cont); }
	};
	///	C++標準のコンテナをライブラリのイテレータに変換します。
	template<typename contT>
	class LegacyIterator<contT, std::enable_if_t<StdReversibleContainerTraits::is_reversible_container<contT>>> final
	{
		friend class LegacyReverseIterator<contT>;
	public:
		typedef contT ContainerType;
		typedef typename contT::value_type ValueType;
	private:
		const ContainerType& _cont;
		StdReversibleContainerTraits::ConstIterator<contT> _itr;

		constexpr LegacyIterator(const ContainerType& container, const StdReversibleContainerTraits::ConstIterator<contT>& iterator) : _cont(container), _itr(iterator) {}
	public:
		constexpr LegacyIterator(const ContainerType& container) : LegacyIterator(container, StdReversibleContainerTraits::cbegin(container)) {}
		constexpr explicit LegacyIterator(const LegacyReverseIterator<contT>& iterator) : LegacyIterator(iterator.reverse()) {}
		[[nodiscard]] constexpr bool equals(const LegacyIterator<contT>& other) const { return StdLegacyBidirectionalIteratorTraits::equals(_itr, other._itr); }
		[[nodiscard]] constexpr bool operator==(const LegacyIterator<contT>& other) const { return equals(other); }
		[[nodiscard]] constexpr bool operator!=(const LegacyIterator<contT>& other) const { return !equals(other); }
		[[nodiscard]] constexpr bool has_value() const { return StdLegacyBidirectionalIteratorTraits::not_equals(_itr, StdReversibleContainerTraits::cend(_cont)); }
		[[nodiscard]] constexpr bool is_before_begin() const { return false; }
		[[nodiscard]] constexpr bool is_after_end() const { return StdLegacyBidirectionalIteratorTraits::not_equals(_itr, StdReversibleContainerTraits::cend(_cont)); }
		[[nodiscard]] constexpr StdReversibleContainerTraits::ConstReference<contT> current() const { if (has_value()) { return StdLegacyBidirectionalIteratorTraits::dereference(_itr); } else { throw std::out_of_range("要素の範囲外にあるイテレータに対して逆参照を試みました。"); } }
		constexpr bool next() { if (has_value()) { StdLegacyBidirectionalIteratorTraits::next(_itr); } return has_value(); }
		constexpr bool previous() { if (has_value()) { StdLegacyBidirectionalIteratorTraits::previous(_itr); } return has_value(); }
		constexpr void reset() { reset(IteratorOrigin::Begin); }
		constexpr void reset(const IteratorOrigin& origin)
		{
			switch(origin)
			{
				case IteratorOrigin::Begin: { _itr = StdReversibleContainerTraits::cbegin(_cont); return; }
				case IteratorOrigin::End: { _itr = StdReversibleContainerTraits::cend(_cont); return; }
			}
		}
		[[nodiscard]] constexpr LegacyReverseIterator<contT> reverse() const { return LegacyReverseIterator<contT>(_cont, StdReversibleContainerTraits::ConstReverseIterator<contT>(_itr)); }
	};

	///	C++標準のコンテナをライブラリのイテレータに変換します。
	template<typename contT>
	class LegacyReverseIterator final
	{
		static_assert(StdReversibleContainerTraits::is_reversible_container<contT>, "テンプレート引数型 contT は 名前付き要件:ReversibleContainer を満たす必要があります。");
		friend class LegacyIterator<contT>;
	public:
		typedef contT ContainerType;
		typedef typename contT::value_type ValueType;
	private:
		const ContainerType& _cont;
		StdReversibleContainerTraits::ConstReverseIterator<contT> _itr;

		constexpr LegacyReverseIterator(const ContainerType& container, const StdReversibleContainerTraits::ConstReverseIterator<contT>& iterator) : _cont(container), _itr(iterator) {}
	public:
		constexpr LegacyReverseIterator(const ContainerType& container) : LegacyReverseIterator(container, StdReversibleContainerTraits::crbegin(container)) {}
		constexpr explicit LegacyReverseIterator(const LegacyIterator<contT>& iterator) : LegacyReverseIterator(iterator.reverse()) {}
		[[nodiscard]] constexpr bool equals(const LegacyReverseIterator<contT>& other) const { return StdLegacyBidirectionalIteratorTraits::equals(_itr, other._itr); }
		[[nodiscard]] constexpr bool operator==(const LegacyReverseIterator<contT>& other) const { return equals(other); }
		[[nodiscard]] constexpr bool operator!=(const LegacyReverseIterator<contT>& other) const { return !equals(other); }
		[[nodiscard]] constexpr bool has_value() const { return StdLegacyBidirectionalIteratorTraits::not_equals(_itr, StdReversibleContainerTraits::crend(_cont)); }
		[[nodiscard]] constexpr bool is_before_begin() const { return StdLegacyBidirectionalIteratorTraits::not_equals(_itr, StdReversibleContainerTraits::crend(_cont)); }
		[[nodiscard]] constexpr bool is_after_end() const { return false; }
		[[nodiscard]] constexpr StdReversibleContainerTraits::ConstReference<contT> current() const { if (has_value()) { return StdLegacyBidirectionalIteratorTraits::dereference(_itr); } else { throw std::out_of_range("要素の範囲外にあるイテレータに対して逆参照を試みました。"); } }
		constexpr bool next() { if (has_value()) { StdLegacyBidirectionalIteratorTraits::next(_itr); } return has_value(); }
		constexpr bool previous() { if (has_value()) { StdLegacyBidirectionalIteratorTraits::previous(_itr); } return has_value(); }
		constexpr void reset() { reset(IteratorOrigin::Begin); }
		constexpr void reset(const IteratorOrigin& origin)
		{
			switch(origin)
			{
				case IteratorOrigin::Begin: { _itr = StdReversibleContainerTraits::crbegin(_cont); return; }
				case IteratorOrigin::End: { _itr = StdReversibleContainerTraits::crend(_cont); return; }
			}
		}
		[[nodiscard]] constexpr LegacyIterator<contT> reverse() const { return LegacyIterator<contT>(_cont, StdReversibleContainerTraits::ConstIterator<contT>(_itr)); }
	};
}
#endif // __stationaryorbit_core_legacyiterator__
