//	stationaryorbit/core/bitwidth
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
#ifndef __stationaryorbit_core_bitwidth__
#define __stationaryorbit_core_bitwidth__
#include "traits.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	@brief	特定の型のビット幅を計測します
	///
	///	BitCounter は型のビット幅を計測するための機能を提供するクラスです。
	///	このクラスのインスタンスを作成することはできません。また、継承することもできません。
	class BitCounter final
	{
		BitCounter() = delete;
		BitCounter(const BitCounter&) = delete;
		BitCounter(BitCounter&&) = delete;
		~BitCounter() = delete;
	public:
		///	@brief	指定された型のビット幅を計測します。
		///
		///	@param	T
		///	ビット幅を計測する型。型要件:BitSequenceType を満たす必要があります。
		template<class T, std::enable_if_t<Traits::IsBitSequenceType<T>, int> = 0>
		static constexpr size_t count() noexcept
		{
			static_assert(std::is_convertible_v<T, uint8_t> || Traits::IsAggregatable<T, uint8_t> || std::is_constructible_v<T, uint8_t>, "テンプレート型 T は (uint8_t) を引数に持つコンストラクタ,集成体初期化またはuint8_tからの暗黙の変換をサポートする必要があります。");
			T v = T();
			T z = T();
			if constexpr (std::is_convertible_v<T, uint8_t>)
			{
				v = 1;
				z = 0;
			}
			if constexpr ((!std::is_convertible_v<T, uint8_t>) && Traits::IsAggregatable<T, uint8_t>)
			{
				v = T{ 1 };
				z = T{ 0 };
			}
			if constexpr ((!std::is_convertible_v<T, uint8_t>) && !(Traits::IsAggregatable<T, uint8_t>) && std::is_constructible_v<T, uint8_t>)
			{
				v = T(1);
				z = T(0);
			}
			size_t result = 0;
			while(v != z)
			{
				++result;
				if (v == T(v << 1)) { break; }
				v = v << 1;
			}
			return result;
		}
	};
	///	@brief	指定された型のビット幅を識別します
	///
	///	BitWidth_t は型のビット幅を識別するメタクラスです。
	///	このクラスに対する特殊化の試みは未定義動作です。
	///
	///	@param	T
	///	ビット幅を識別する型。型要件:BitSequenceType を満たす必要があります。
	template<class T> struct BitWidth_t : std::integral_constant<size_t, BitCounter::count<T>()>
	{
		static_assert(Traits::IsBitSequenceType<T>, "ビット幅の計数は整数型、boolなどの固定幅のビットシーケンスでのみ有効です。");
	};
	template<std::size_t N> struct BitWidth_t<std::bitset<N>> : std::integral_constant<size_t, N> {};
	///	@brief	指定された型のビット幅を識別します
	///
	///	@param	T
	///	ビット幅を識別する型。型要件:BitSequenceType を満たす必要があります。
	template<class T> inline constexpr size_t bitwidth = BitWidth_t<T>::value;
}
#endif // __stationaryorbit_core_bitwidth__
