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
		constexpr LegacyReverseIterator(const ContainerType& container) : _cont(container) {}
		[[nodiscard]] constexpr bool equals(const LegacyReverseIterator<contT>& other) { return _itr == other._itr; }
		[[nodiscard]] constexpr bool has_value() const { return _itr != _cont.crend(); }
		[[nodiscard]] constexpr const T& current() const { if (has_value()) { return *_itr; } else { throw std::out_of_range("要素の範囲外にあるイテレータに対して逆参照を試みました。"); } }
		constexpr bool next() { if (has_value()) { ++_itr; } return _itr != _cont.crend(); }
		constexpr void reset() { _itr = _cont.crbegin(); }
	};
}
#endif // __stationaryorbit_core_legacyiterator__
