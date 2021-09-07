//	stationaryorbit/core/comparabletypetraits
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
#ifndef __stationaryorbit_core_comparabletypetraits__
#define __stationaryorbit_core_comparabletypetraits__
#include "typetraitsbase.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	型要件:Comparable を満たす型の比較結果
	enum class ComparisonResult
	{
		///	値が等しい。
		equals = 0,
		///	他方の値より大きい。
		larger = 1,
		///	他方の値より小さい。
		smaller = -1,
		///	順序が特定されない。
		unordered = -128
	};

	///	型要件:Comparable を満たす型を識別します
	class ComparableTypeTraits
	{
		ComparableTypeTraits() = delete;
		ComparableTypeTraits(const ComparableTypeTraits&) = delete;
		ComparableTypeTraits(ComparableTypeTraits&&) = delete;
		ComparableTypeTraits& operator=(const ComparableTypeTraits&) = delete;
		ComparableTypeTraits& operator=(ComparableTypeTraits&&) = delete;
		~ComparableTypeTraits() = delete;
	private:
		template<typename T, typename U>
		struct IsComparable_impl :
			std::conjunction
			<
				std::bool_constant<TypeTraitsBase::compare_larger_result_is_convertible<T, U, bool>>,
				std::bool_constant<TypeTraitsBase::compare_smaller_result_is_convertible<T, U, bool>>,
				std::bool_constant<TypeTraitsBase::compare_least_result_is_convertible<T, U, bool>>,
				std::bool_constant<TypeTraitsBase::compare_most_result_is_convertible<T, U, bool>>
			>
		{};
	public:
		///	指定された型が 型要件:Comparable を満たすかを識別します。
		template<typename T, typename U = T> constexpr static bool is_comparable = IsComparable_impl<T, U>::value;

		///	指定したオブジェクトが他方のオブジェクトより大きいかを取得します。
		template<typename T, typename U = T> static constexpr bool compare_larger(const T& object, const U& other) { static_assert(is_comparable<T, U>, "型 T, U の組み合わせは 型要件:Comparable を満たしません。"); return TypeTraitsBase::compare_larger(object, other); }
		///	指定したオブジェクトが他方のオブジェクトより小さいかを取得します。
		template<typename T, typename U = T> static constexpr bool compare_smaller(const T& object, const U& other) { static_assert(is_comparable<T, U>, "型 T, U の組み合わせは 型要件:Comparable を満たしません。"); return TypeTraitsBase::compare_smaller(object, other); }
		///	指定したオブジェクトが他方のオブジェクト以上かを取得します。
		template<typename T, typename U = T> static constexpr bool compare_larger_or_equal(const T& object, const U& other) { static_assert(is_comparable<T, U>, "型 T, U の組み合わせは 型要件:Comparable を満たしません。"); return TypeTraitsBase::compare_least(object, other); }
		///	指定したオブジェクトが他方のオブジェクト以下かを取得します。
		template<typename T, typename U = T> static constexpr bool compare_smaller_or_equal(const T& object, const U& other) { static_assert(is_comparable<T, U>, "型 T, U の組み合わせは 型要件:Comparable を満たしません。"); return TypeTraitsBase::compare_most(object, other); }

		///	指定したオブジェクトの大小比較を行います。
		template<typename T, typename U = T>
		static constexpr ComparisonResult compare(const T& object, const U& other)
		{
			static_assert(is_comparable<T, U>, "型 T, U の組み合わせは 型要件:Comparable を満たしません。");
			if (compare_larger(object, other))
			{
				if (!compare_smaller_or_equal(object, other)) { return ComparisonResult::larger; }
				else { return ComparisonResult::unordered; }
			}
			else if (compare_smaller(object, other))
			{
				if (!compare_larger_or_equal(object, other)) { return ComparisonResult::smaller; }
				else { return ComparisonResult::unordered; }
			}
			else if (compare_larger_or_equal(object, other) && compare_smaller_or_equal(object, other))
			{
				return ComparisonResult::equals;
			}
			else
			{
				return ComparisonResult::unordered;
			}
		}
	};
}
#endif // __stationaryorbit_core_comparabletypetraits__
