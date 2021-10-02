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

	///	このライブラリで用いられるイテレータの型特性を識別します。
	class IteratorTraits
	{
	private:
		IteratorTraits() = delete;
		IteratorTraits(const IteratorTraits&) = delete;
		IteratorTraits& operator=(const IteratorTraits&) = delete;
		IteratorTraits&& operator=(IteratorTraits&&) = delete;
		IteratorTraits(IteratorTraits&&) = delete;
		~IteratorTraits() = delete;

	public:
		///	イテレータの間隔を表すために用いる型。
		typedef std::make_signed_t<size_t> IteratorDiff_t;

	private:

		///	イテレータを識別します。
		template<class, class = std::void_t<>>
		struct IsIterator_t : std::false_type {};
		template<class T>
		struct IsIterator_t
		<
			T,
			std::void_t
			<
				typename T::ValueType,
				decltype( std::declval<T&>().Equals(std::declval<const T&>()) ),
				decltype( std::declval<T&>().Next() ),
				decltype( std::declval<T&>().Current() ),
				decltype( std::declval<T&>().HasValue() )
			>
		>
			: std::conjunction
			<
				std::is_convertible<decltype( std::declval<T&>().Equals(std::declval<const T&>()) ), bool>,
				std::is_convertible<decltype( std::declval<T&>().Next() ), bool>,
				std::is_convertible<decltype( std::declval<T&>().HasValue() ), bool>,
				std::is_convertible<decltype( std::declval<T&>().Current() ), typename T::ValueType>,
				std::is_copy_constructible<T>
			>
		{};

		///	始点および単方向の順序を持つイテレータを識別します。
		template<class, class = std::void_t<>>
		struct IsSequencialOrderIterator_t : std::false_type {};
		template<class T>
		struct IsSequencialOrderIterator_t
		<
			T,
			std::void_t
			<
				decltype( std::declval<T&>().Reset() )
			>
		>
			: std::conjunction
			<
				IsIterator_t<T>
			>
		{};

		///	始点・終点および双方向の順序を持つイテレータを識別します。
		template<class, class = std::void_t<>>
		struct IsBidirectionalOrderIterator_t : std::false_type {};
		template<class T>
		struct IsBidirectionalOrderIterator_t
		<
			T,
			std::void_t
			<
				decltype( std::declval<T&>().Previous() ),
				decltype( std::declval<T&>().Reset(std::declval<const IteratorOrigin&>()) ),
				decltype( std::declval<T&>().IsBeforeBegin() ),
				decltype( std::declval<T&>().IsAfterEnd() )
			>
		>
			: std::conjunction
			<
				IsSequencialOrderIterator_t<T>,
				std::is_convertible<decltype( std::declval<T&>().IsBeforeBegin() ), bool>,
				std::is_convertible<decltype( std::declval<T&>().IsAfterEnd() ), bool>,
				std::is_convertible<decltype( std::declval<T&>().Previous() ), bool>
			>
		{};

		///	要素が線形に配置されているイテレータを識別します。
		template<class, class = std::void_t<>>
		struct IsLinearOrderIterator_t : std::false_type {};
		template<class T>
		struct IsLinearOrderIterator_t
		<
			T,
			std::void_t
			<
				decltype( std::declval<T&>().Compare(std::declval<const T&>()) ),
				decltype( std::declval<T&>().Next(std::declval<const IteratorDiff_t&>()) ),
				decltype( std::declval<T&>().Previous(std::declval<const IteratorDiff_t&>()) ),
				decltype( std::declval<T&>().Distance(std::declval<const T&>()) )
			>
		>
			: std::conjunction
			<
				IsBidirectionalOrderIterator_t<T>,
				std::is_convertible<decltype( std::declval<T&>().Compare(std::declval<const T&>()) ), int>,
				std::is_convertible<decltype( std::declval<T&>().Next(std::declval<const IteratorDiff_t&>()) ), bool>,
				std::is_convertible<decltype( std::declval<T&>().Previous(std::declval<const IteratorDiff_t&>()) ), bool>,
				std::is_convertible<decltype( std::declval<T&>().Distance(std::declval<const T&>()) ), IteratorDiff_t>
			>
		{};
	public:
		///	イテレータを識別します。
		template<class T> inline constexpr static bool IsIterator = IsIterator_t<T>::value;
		///	始点および単方向の順序を持つイテレータを識別します。
		template<class T> inline constexpr static bool IsSequencialOrderIterator = IsSequencialOrderIterator_t<T>::value;
		///	始点・終点および双方向の順序を持つイテレータを識別します。
		template<class T> inline constexpr static bool IsBidirectionalOrderIterator = IsBidirectionalOrderIterator_t<T>::value;
		///	要素が線形に配置されているイテレータを識別します。
		template<class T> inline constexpr static bool IsLinearOrderIterator = IsLinearOrderIterator_t<T>::value;
	};
}
#endif // __stationaryorbit_core_iteratortraits__
