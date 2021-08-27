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
		struct HasDigestType_t : std::false_type {};
		template<typename Tp>
		struct HasDigestType_t<Tp, std::void_t<typename Tp::DigestType>> : std::true_type {};
		template<typename Tp, class = std::void_t<>>
		struct HasDigestFunction_t : std::false_type {};
		template<typename Tp>
		struct HasDigestFunction_t<Tp, std::void_t< decltype(std::declval<const Tp&>().digest()) >> : std::true_type {};
		template<typename Tp, typename ValueT, class = std::void_t<>>
		struct HasInsertFunction_t : std::false_type {};
		template<typename Tp, typename ValueT>
		struct HasInsertFunction_t<Tp, ValueT, std::void_t< decltype(std::declval<Tp&>().insert(std::declval<ValueT&>())) >> : std::true_type {};
	public:
		///	指定された型 Tp がメンバ型 DigestType を保持するかを識別します。
		template<typename Tp>
		static constexpr bool has_valuetype = HasDigestType_t<Tp>::value;
		///	指定された型 Tp がメンバ関数 digest() を保持するかを識別します。
		template<typename Tp>
		static constexpr bool has_digest_function = HasDigestFunction_t<Tp>::value;
		///	指定された型 Tp がメンバ関数 insert(ValueT) を保持するかを識別します。
		template<typename Tp, typename ValueT>
		static constexpr bool has_insert_function = HasInsertFunction_t<Tp, ValueT>::value;
	private:
		template<typename Tp, class = std::void_t<>>
		struct IsDigestFunctionSameDigestType_t : std::false_type {};
		template<typename Tp>
		struct IsDigestFunctionSameDigestType_t<Tp, std::void_t< typename Tp::DigestType, decltype(std::declval<const Tp&>().digest()) >> : std::is_same<typename Tp::DigestType, decltype(std::declval<const Tp&>().digest())> {};
		template<typename Tp, typename ValueT>
		struct IsHashfunction_t : std::conjunction<std::is_default_constructible<Tp>, HasDigestType_t<Tp>, HasDigestFunction_t<Tp>, HasInsertFunction_t<Tp, ValueT>, IsDigestFunctionSameDigestType_t<Tp>> {};
	public:
		///	ハッシュ関数を扱うクラスであるかを識別します。
		template<typename Tp, typename ValueT>
		static constexpr bool is_hashfunction = IsHashfunction_t<Tp, ValueT>::value;

		///	指定されたハッシュ関数クラス Tp のメンバ型 DigestType を取得します。
		template<typename Tp>
		using DigestType = typename Tp::DigestType;
		///	指定されたハッシュ関数クラス Tp のオブジェクトのハッシュ値を取得します。
		template<typename Tp>
		static constexpr DigestType<Tp> digest(const Tp& object) { return object.digest(); }
		///	指定されたハッシュ関数クラス Tp のオブジェクトにビット列を追加し、ハッシュ値を更新します。
		template<typename Tp, typename ValueT>
		static constexpr void insert(const Tp& object, const Tp& insert, const ValueT& value) { object.insert(value); }
	};
}
#endif // __stationaryorbit_core_hashfunction__