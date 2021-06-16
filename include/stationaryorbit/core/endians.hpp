//	stationaryorbit/core/endians
//	Copyright 2020-2021 zawa-ch.
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
#ifndef __stationaryorbit_core_endians__
#define __stationaryorbit_core_endians__
#include <cstdint>
#include <array>
#include "invalidoperation.hpp"
#include "traits.hpp"
#include "disperse.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	すべてのスカラー型のエンディアン
	enum class Endians
	{
		#ifdef _WIN32
			///	リトルエンディアン。
			little = 0,
			///	ビッグエンディアン。
			big    = 1,
			///	現在の処理系におけるスカラー型のエンディアン。
			native = little
		#else
			///	リトルエンディアン。
			little = __ORDER_LITTLE_ENDIAN__,
			///	ビッグエンディアン。
			big    = __ORDER_BIG_ENDIAN__,
			///	現在の処理系におけるスカラー型のエンディアン。
			native = __BYTE_ORDER__
		#endif
	};

	///	@brief	エンディアンの変換を行います
	///
	///	値型に対して、リトルエンディアン、ビッグエンディアンの間の変換を行います。
	///	このクラスは継承できません。
	///
	///	@param	from
	///	変換元のエンディアン。
	///	@param	dest
	///	変換先のエンディアン。
	template<Endians from, Endians dest>
	class EndianConverter final
	{
	public:
		///	指定された値のエンディアンを @a from から @a dest に変換します。
		///	@param	T
		///	エンディアン変換を行う値の型。型要件:ValueType を満たす必要があります。
		///	@param	value
		///	エンディアン変換を行う値。
		///	@exception	InvalidOperationException	指定されたエンディアンの組み合わせに対する適切な変換が定義されていない場合にスローされます。
		template<class T>
		[[nodiscard]] static constexpr std::array<std::byte, sizeof(T)> encode(const T& value)
		{
			static_assert(Traits::IsValueType<T>, "テンプレート引数 T は値型である必要があります。");
			return convert(Disperse::to_binary(value));
		}
		///	指定された値のエンディアンを @a dest から @a from に変換します。
		///	@param	T
		///	エンディアン変換を行う値の型。型要件:ValueTypeを満たす必要があります。
		///	@param	data
		///	エンディアン変換を行うビット列。
		///	@exception	InvalidOperationException	指定されたエンディアンの組み合わせに対する適切な変換が定義されていない場合にスローされます。
		template<class T>
		[[nodiscard]] static constexpr T decode(const std::array<std::byte, sizeof(T)>& data)
		{
			static_assert(Traits::IsValueType<T>, "テンプレート引数 T は値型である必要があります。");
			return Disperse::perse<T>(convert(data));
		}
		///	指定された @a std::array のバイト順序を @a from から @a dest に変換します。
		///	@param	N
		///	@a std::array の大きさ。バイト単位で指定します。
		///	@param	data
		///	バイト順序変換を行うビット列。
		///	@exception	InvalidOperationException	指定されたエンディアンの組み合わせに対する適切な変換が定義されていない場合にスローされます。
		template<size_t N>
		[[nodiscard]] static constexpr std::array<std::byte, N> convert(const std::array<std::byte, N>& data)
		{
			if constexpr (from == dest) { return data; }
			if constexpr ((from != dest)&&((from == Endians::little)||(from == Endians::big))&&((dest == Endians::little)||(dest == Endians::big)))
			{
				auto result = std::array<std::byte, N>();
				auto si = data.crbegin();
				auto se = data.crend();
				auto di = result.begin();
				auto de = result.end();
				while((si != se) && (di != de)) { *di = *si; ++di; ++si; }
				return result;
			}
			if constexpr ((from != dest)&&(from != Endians::little)&&(from != Endians::big)&&(dest != Endians::little)&&(dest != Endians::big))
			{ throw InvalidOperationException("指定されたエンディアンの適切な変換が存在しません。"); }
		}
	};
	///	現在のバイトオーダーからリトルエンディアンへの変換を表す EndianConverter 。
	typedef EndianConverter<Endians::native, Endians::little> LittleEndian;
	///	現在のバイトオーダーからビッグエンディアンへの変換を表す EndianConverter 。
	typedef EndianConverter<Endians::native, Endians::big> BigEndian;

	///	@brief	スカラー型を特定のバイトオーダーで格納します
	///
	///	スカラー型を指定されたバイトオーダーでメモリ上に格納します。
	///	このクラスは継承できません。
	///
	///	@param	Tp
	///	格納する値の型。型要件:ValueTypeを満たす必要があります。
	///	@param	order
	///	メモリに配置する際のバイトオーダー。
	template<class Tp, Endians order = Endians::native>
	struct EndianValueType final
	{
		static_assert(Traits::IsValueType<Tp>, "テンプレート引数 Tp は値型である必要があります。");
	public:
		///	格納されている値の型。
		typedef Tp ValueType;
		///	内部でデータを格納するための型。
		typedef std::array<std::byte, sizeof(Tp)> DataType;
		///	メモリに配置する際のバイトオーダー。
		static constexpr Endians endian = order;
	private:
		alignas(alignof(Tp)) DataType _data;
	public:
		///	規定値で @a EndianValueType を構築します。
		EndianValueType() = default;
		///	@a EndianValueType を指定された値で構築します。
		///	@param	value
		///	構築時に代入する値。
		constexpr EndianValueType(const ValueType& value) : _data(EndianConverter<Endians::native, order>::encode(value)) {}
		///	異なるエンディアンの @a EndianValueType からエンディアンを変換します。
		///	@param	value
		///	変換元となる @a EndianValueType 。
		template<Endians from>
		constexpr EndianValueType(const EndianValueType<Tp, from>& value) : _data(EndianConverter<from, order>::convert(value._data)) {}

		///	このオブジェクトの値を取得します。
		[[nodiscard]] constexpr ValueType value() const { return EndianConverter<Endians::native, order>::template decode<Tp>(_data); }

		///	このオブジェクトが格納されているデータに直接アクセスします。
		[[nodiscard]] constexpr const DataType& data() const { return _data; }

		[[nodiscard]] constexpr operator ValueType() const { return EndianConverter<Endians::native, order>::template decode<Tp>(_data); }
	};

	extern template struct EndianValueType<uint8_t, Endians::big>;
	extern template struct EndianValueType<uint16_t, Endians::big>;
	extern template struct EndianValueType<uint32_t, Endians::big>;
	extern template struct EndianValueType<uint64_t, Endians::big>;
	extern template struct EndianValueType<float, Endians::big>;
	extern template struct EndianValueType<double, Endians::big>;
	extern template struct EndianValueType<uint8_t, Endians::little>;
	extern template struct EndianValueType<uint16_t, Endians::little>;
	extern template struct EndianValueType<uint32_t, Endians::little>;
	extern template struct EndianValueType<uint64_t, Endians::little>;
	extern template struct EndianValueType<float, Endians::little>;
	extern template struct EndianValueType<double, Endians::little>;

	///	リトルエンディアンとして格納される @a uint8_t 。
	typedef EndianValueType<uint8_t, Endians::big> uint8be_t;
	///	リトルエンディアンとして格納される @a uint16_t 。
	typedef EndianValueType<uint16_t, Endians::big> uint16be_t;
	///	リトルエンディアンとして格納される @a uint32_t 。
	typedef EndianValueType<uint32_t, Endians::big> uint32be_t;
	///	リトルエンディアンとして格納される @a uint64_t 。
	typedef EndianValueType<uint64_t, Endians::big> uint64be_t;
	///	リトルエンディアンとして格納される @a float 。
	typedef EndianValueType<float, Endians::big> float32be_t;
	///	リトルエンディアンとして格納される @a double 。
	typedef EndianValueType<double, Endians::big> float64be_t;
	///	ビッグエンディアンとして格納される @a uint8_t 。
	typedef EndianValueType<uint8_t, Endians::little> uint8le_t;
	///	ビッグエンディアンとして格納される @a uint16_t 。
	typedef EndianValueType<uint16_t, Endians::little> uint16le_t;
	///	ビッグエンディアンとして格納される @a uint32_t 。
	typedef EndianValueType<uint32_t, Endians::little> uint32le_t;
	///	ビッグエンディアンとして格納される @a uint64_t 。
	typedef EndianValueType<uint64_t, Endians::little> uint64le_t;
	///	ビッグエンディアンとして格納される @a float 。
	typedef EndianValueType<float, Endians::little> float32le_t;
	///	ビッグエンディアンとして格納される @a double 。
	typedef EndianValueType<double, Endians::little> float64le_t;
}
#endif // __stationaryorbit_core_endians__