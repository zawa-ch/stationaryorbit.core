//	stationaryorbit/core/md5
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
#ifndef __stationaryorbit_core_md5__
#define __stationaryorbit_core_md5__
#include <cstdint>
#include <array>
#include "hashfunction.hpp"
#include "basicmath.hpp"
namespace zawa_ch::StationaryOrbit
{
	class MD5TableBuilder
	{
	public:
		typedef uint32_t ValueType;
	private:
		uint32_t _iter;
	public:
		constexpr MD5TableBuilder() : _iter(0) {}

		[[nodiscard]] constexpr bool has_value() const noexcept { return true; }
		[[nodiscard]] constexpr ValueType current() const noexcept { return uint32_t(BasicMathematics::abstract<double>(BasicMathematics::sin(double(_iter))) * 4294967296.0); }
		constexpr bool next() noexcept { ++_iter; return true; }
	};
	class MD5Hash
	{
	public:
		typedef std::array<uint8_t, 16> DigestType;
	private:
		typedef std::array<uint32_t, 4> BufferType;
		typedef std::array<uint32_t, 16> ChunkType;

		BufferType _buffer;
		uint64_t _message_length;
		uint32_t _byte_cache;
		ChunkType _word_cache;

		static constexpr BufferType _buffer_init = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
	public:
		constexpr MD5Hash() : _buffer(_buffer_init), _message_length(0), _byte_cache(), _word_cache() {}

		constexpr void insert(uint8_t data)
		{
			_byte_cache |= (uint32_t(data) << (_message_length % 32));
			_message_length += 8;
			if (((_message_length / 8) % 4) == 0)
			{
				_word_cache[(((_message_length / 32) - 1) % 16)] = _byte_cache;
				_byte_cache = uint32_t(0);
				if (((_message_length / 32) % 16) == 0)
				{
					round_f(_buffer, _word_cache);
					_word_cache = ChunkType();
				}
			}
		}
		constexpr DigestType digest() const
		{
			auto w = _buffer;
			auto chunk = _word_cache;
			chunk[((_message_length / 32) % 16)] = _byte_cache;
			if ((_message_length % 512) != 0)
			{
				chunk[(_message_length / 32) % 16] |= 0x80 << (((_message_length / 8) % 4) * 8);
			}
			if ((_message_length % 512) >= 448)
			{
				round_f(w, chunk);
				chunk = ChunkType();
			}
			if ((_message_length % 512) == 0) {
				chunk[(_message_length / 32) % 16] |= 0x80 << (((_message_length / 8) % 4) * 8);
			}
			chunk[14] = _message_length & 0xFFFFFFFF;
			chunk[15] = (_message_length >> 32) & 0xFFFFFFFF;
			round_f(w, chunk);
			DigestType result = DigestType();
			for(auto i: Range<size_t>(0, 16).GetStdIterator())
			{
				result[i] = (w[i / 4] >> ((i % 4) * 8)) & (0xFF);
			}
			return result;
		}
	private:
		static constexpr void round_f(BufferType& buffer, const ChunkType& chunk)
		{
			auto w = buffer;
			for(auto i: Range<size_t>(0, 64).GetStdIterator())
			{
				uint32_t f = 0;
				size_t data_index= 0;
				int shift_amount = 0;
				if (i < 16)
				{
					std::array<int, 4> shift_table = { 7, 12, 17, 22 };
					f = aux_f(w[1], w[2], w[3]);
					data_index = i;
					shift_amount = shift_table[i % 4];
				}
				else if (i < 32)
				{
					std::array<int, 4> shift_table = { 5, 9, 14, 20 };
					f = aux_g(w[1], w[2], w[3]);
					data_index = (i * 5 + 1) % 16;
					shift_amount = shift_table[i % 4];
				}
				else if (i < 48)
				{
					std::array<int, 4> shift_table = { 4, 11, 16, 23 };
					f = aux_h(w[1], w[2], w[3]);
					data_index = (i * 3 + 5) % 16;
					shift_amount = shift_table[i % 4];
				}
				else
				{
					std::array<int, 4> shift_table = { 6, 10, 15, 21 };
					f = aux_i(w[1], w[2], w[3]);
					data_index = (i * 7) % 16;
					shift_amount = shift_table[i % 4];
				}
				uint32_t res_f = w[0] + f + ConstProgressionArray<MD5TableBuilder, 64, 1>::values[i] + chunk[data_index];
				w[0] = w[3];
				w[3] = w[2];
				w[2] = w[1];
				w[1] += rot_l(res_f, shift_amount);
			}
			for(auto i: Range<size_t>(0, 4).GetStdIterator())
			{
				buffer[i] += w[i];
			}
		}
		static constexpr uint32_t aux_f(uint32_t x, uint32_t y, uint32_t z) { return ((x & y) | (~x & z)); }
		static constexpr uint32_t aux_g(uint32_t x, uint32_t y, uint32_t z) { return ((x & z) | (y & ~z)); }
		static constexpr uint32_t aux_h(uint32_t x, uint32_t y, uint32_t z) { return (x ^ y ^ z); }
		static constexpr uint32_t aux_i(uint32_t x, uint32_t y, uint32_t z) { return (y ^ (x | ~z)); }
		static constexpr uint32_t rot_l(uint32_t x, int n) { return (x << n) | (x >> (bitwidth<uint32_t> - n)); }
	};
}
#endif // __stationaryorbit_core_md5__