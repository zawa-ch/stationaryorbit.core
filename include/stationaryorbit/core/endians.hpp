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
	///	すべてのスカラー型のエンディアンを表します。
	enum class Endians
	{
		#ifdef _WIN32
			little = 0,
			big    = 1,
			native = little
		#else
			little = __ORDER_LITTLE_ENDIAN__,
			big    = __ORDER_BIG_ENDIAN__,
			native = __BYTE_ORDER__
		#endif
	};
	template<Endians from, Endians dest>
	class EndianConverter final
	{
	public:
		template<class T>
		[[nodiscard]] static constexpr std::array<std::byte, sizeof(T)> encode(const T& value)
		{
			static_assert(Traits::IsValueType<T>, "テンプレート引数 T は値型である必要があります。");
			return convert(Disperse::to_binary(value));
		}
		template<class T>
		[[nodiscard]] static constexpr T decode(const std::array<std::byte, sizeof(T)>& data)
		{
			static_assert(Traits::IsValueType<T>, "テンプレート引数 T は値型である必要があります。");
			return Disperse::perse<T>(convert(data));
		}
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
	typedef EndianConverter<Endians::native, Endians::little> LittleEndian;
	typedef EndianConverter<Endians::native, Endians::big> BigEndian;

	///	スカラー型を特定のバイトオーダーで格納します。
	template<class Tp, Endians order = Endians::native>
	struct EndianValueType final
	{
		static_assert(Traits::IsValueType<Tp>, "テンプレート引数 Tp は値型である必要があります。");
	public:
		typedef Tp ValueType;
		typedef std::array<std::byte, sizeof(Tp)> DataType;
		static constexpr Endians endian = order;
	private:
		alignas(alignof(Tp)) DataType _data;
	public:
		EndianValueType() = default;
		constexpr EndianValueType(const ValueType& value) : _data(EndianConverter<Endians::native, order>::encode(value)) {}
		template<Endians from>
		constexpr EndianValueType(const EndianValueType<Tp, from>& value) : _data(EndianConverter<from, order>::convert(value._data)) {}

		[[nodiscard]] constexpr ValueType value() const { return EndianConverter<Endians::native, order>::template decode<Tp>(_data); }
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

	typedef EndianValueType<uint8_t, Endians::big> uint8be_t;
	typedef EndianValueType<uint16_t, Endians::big> uint16be_t;
	typedef EndianValueType<uint32_t, Endians::big> uint32be_t;
	typedef EndianValueType<uint64_t, Endians::big> uint64be_t;
	typedef EndianValueType<float, Endians::big> float32be_t;
	typedef EndianValueType<double, Endians::big> float64be_t;
	typedef EndianValueType<uint8_t, Endians::little> uint8le_t;
	typedef EndianValueType<uint16_t, Endians::little> uint16le_t;
	typedef EndianValueType<uint32_t, Endians::little> uint32le_t;
	typedef EndianValueType<uint64_t, Endians::little> uint64le_t;
	typedef EndianValueType<float, Endians::little> float32le_t;
	typedef EndianValueType<double, Endians::little> float64le_t;
}
#endif // __stationaryorbit_core_endians__