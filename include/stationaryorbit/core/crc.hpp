//	stationaryorbit/core/crc
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
#ifndef __stationaryorbit_core_crc__
#define __stationaryorbit_core_crc__
#include "hashfunction.hpp"
#include "bitsequencetypetraits.hpp"
#include "numericaltypetraits.hpp"
#include "constprogression.hpp"
#include "range.hpp"
#include "bitwidth.hpp"
namespace zawa_ch::StationaryOrbit
{
	template<typename Tresult, Tresult polynomial>
	class CRCTableBuilder
	{
		static_assert(IntegralTypeTraits::is_integraltype<Tresult>, "テンプレート型引数 Tresult は、 型要件:IntegralType を満たす必要があります。");
		static_assert(BitSequenceTypeTraits::is_bitsequence_type<Tresult>, "テンプレート型引数 Tresult は、 型要件:BitSequenceType を満たす必要があります。");
	public:
		typedef Tresult ValueType;
	private:
		Tresult _iter;
	public:
		constexpr CRCTableBuilder() : _iter(0) {}

		[[nodiscard]] constexpr bool has_value() const noexcept { return true; }
		[[nodiscard]] constexpr ValueType current() const noexcept
		{
			ValueType c = _iter;
			for(auto n: Range<size_t>(0, 8).get_std_iterator())
			{
				c = (BitSequenceTypeTraits::bitwise_and<ValueType>(c, Tresult(1)))?(BitSequenceTypeTraits::bitwise_xor<ValueType>(polynomial, BitSequenceTypeTraits::rshift<ValueType>(c, 1))):(BitSequenceTypeTraits::rshift<ValueType>(c, 1));
			}
			return c;
		}
		constexpr bool next() noexcept { IntegralTypeTraits::pre_increment(_iter); return true; }
	};

	typedef CRCTableBuilder<uint32_t, 0xEDB88320> CRC32TableBuilder;

	template<typename Ttable, typename Tresult = typename Ttable::ValueType>
	class CRC
	{
		static_assert(IntegralTypeTraits::is_integraltype<Tresult>, "テンプレート型引数 Tresult は、 型要件:IntegralType を満たす必要があります。");
		static_assert(BitSequenceTypeTraits::is_bitsequence_type<Tresult>, "テンプレート型引数 Tresult は、 型要件:BitSequenceType を満たす必要があります。");
	public:
		typedef Tresult DigestType;
		typedef ConstProgressionArray<Ttable, 256> CRCTable;
	private:
		DigestType _digest;
	public:
		constexpr CRC() : _digest(BitSequenceTypeTraits::bitwise_not(DigestType(0))) {}
		constexpr void insert(uint8_t data)
		{
			_digest = BitSequenceTypeTraits::bitwise_xor<DigestType>(CRCTable::values[BitSequenceTypeTraits::bitwise_and<DigestType>(BitSequenceTypeTraits::bitwise_xor<DigestType>(_digest, data), 0xFF)], BitSequenceTypeTraits::rshift<DigestType>(_digest, 8));
		}
		constexpr DigestType digest() const { return BitSequenceTypeTraits::bitwise_not(_digest); }
	};

	typedef CRC<CRC32TableBuilder> CRC32;
}
#endif // __stationaryorbit_core_crc__
