//	stationaryorbit/core/hashfunction
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
#ifndef __stationaryorbit_core_hashfunction__
#define __stationaryorbit_core_hashfunction__
#include "traits.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	@brief	ハッシュ関数を識別します
	///
	///	任意長のビット列から固定長のビット列を生成するクラスを識別します。
	///	このクラスのインスタンスを作成することはできません。また、継承することもできません。
	class HashFunctionTraits final
	{
		HashFunctionTraits() = delete;
		~HashFunctionTraits() = delete;
	private:
		template<typename Tp, class = std::void_t<>>
		struct HasValueType_t : std::false_type {};
		template<typename Tp>
		struct HasValueType_t<Tp, std::void_t<typename Tp::ValueType>> : std::true_type {};
		template<typename Tp, class = std::void_t<>>
		struct HasValueFunction_t : std::false_type {};
		template<typename Tp>
		struct HasValueFunction_t<Tp, std::void_t< decltype(std::declval<const Tp&>().value()) >> : std::true_type {};
		template<typename Tp, typename ValueT, class = std::void_t<>>
		struct HasInsertFunction_t : std::false_type {};
		template<typename Tp, typename ValueT>
		struct HasInsertFunction_t<Tp, std::void_t< decltype(std::declval<Tp&>().insert(std::declval<ValueT&>())) >> : std::true_type {};
	public:
		///	指定された型 Tp がメンバ型 ValueType を保持するかを識別します。
		template<typename Tp>
		static constexpr bool has_valuetype = HasValueType_t<Tp>::value;
		///	指定された型 Tp がメンバ関数 value() を保持するかを識別します。
		template<typename Tp>
		static constexpr bool has_value_function = HasValueFunction_t<Tp>::value;
		///	指定された型 Tp がメンバ関数 insert(ValueT) を保持するかを識別します。
		template<typename Tp, typename ValueT>
		static constexpr bool has_insert_function = HasInsertFunction_t<Tp, ValueT>::value;
	private:
		template<typename Tp, class = std::void_t<>>
		struct IsValueFunctionSameValueType_t : std::false_type {};
		template<typename Tp>
		struct IsValueFunctionSameValueType_t<Tp, std::void_t< typename Tp::ValueType, decltype(std::declval<const Tp&>().value()) >> : std::is_same<typename Tp::ValueType, decltype(std::declval<const Tp&>().value())> {};
		template<typename Tp, typename ValueT>
		struct IsHashfunction_t : std::conjunction<std::is_default_constructible<Tp>, HasValueType_t<Tp>, HasValueFunction_t<Tp>, HasInsertFunction_t<Tp, ValueT>, IsValueFunctionSameValueType_t<Tp>> {};
	public:
		///	ハッシュ関数を扱うクラスであるかを識別します。
		template<typename Tp, typename ValueT>
		static constexpr bool is_hashfunction = IsHashfunction_t<Tp, ValueT>::value;

		///	指定されたハッシュ関数クラス Tp のメンバ型 ValueType を取得します。
		template<typename Tp>
		using ValueType = typename Tp::ValueType;
		///	指定されたハッシュ関数クラス Tp のオブジェクトのハッシュ値を取得します。
		template<typename Tp>
		static constexpr auto value(const Tp& object) { return object.value(); }
		///	指定されたハッシュ関数クラス Tp のオブジェクトにビット列を追加し、ハッシュ値を更新します。
		template<typename Tp, typename ValueT>
		static constexpr auto insert(const Tp& insert, const ValueT& value) { return object.insert(value); }
	};
}
#endif // __stationaryorbit_core_hashfunction__