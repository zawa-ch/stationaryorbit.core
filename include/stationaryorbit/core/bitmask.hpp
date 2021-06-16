//	stationaryorbit/core/bitmask
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
#ifndef __stationaryorbit_core_bitmask__
#define __stationaryorbit_core_bitmask__
#include <limits>
#include "traits.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	@brief	ビット列をマスクする機能を提供します
	///
	///	マスクするためのビット列を保持し、マスクを用いたビット列の取得・変更を行います。
	///	このクラスは継承できません。
	///
	///	@param	Tp
	///	マスクのためのビット列の型。型要件:BitSequenceType を満たす必要があります。
	template<class Tp>
	class BitMask final
	{
		static_assert(Traits::IsBitSequenceType<Tp>, "テンプレート型 Tp はビット列型である必要があります。");
	public:
		///	このオブジェクトのマスク値。
		Tp mask;

		///	規定の @a BitMask を構築します。
		constexpr BitMask() : mask() {}
		///	マスク値を指定して @a BitMask を構築します。
		///	@param	value
		///	マスクを指定したビット列。
		explicit constexpr BitMask(const Tp& value) noexcept : mask(value) {}

		///	このマスクが開始される(最初にビットが1となる)、LSBから数えたビット数を取得します。
		constexpr std::size_t begin_index() const noexcept { return get_begin_index(mask); }
		///	このマスクが終了される(最後にビットが0となる)、LSBから数えたビット数を取得します。
		constexpr std::size_t end_index() const noexcept { return get_end_index(mask); }
		///	マスクの開始から終了までのビットの長さを取得します。
		constexpr std::size_t length() const noexcept { return end_index() - begin_index(); }
		///	入力をマスク値に従ってマスクします。
		///	@param	source
		///	値を取得するソース。
		constexpr Tp get_from(const Tp& source) const noexcept { return source & mask; }
		///	入力をマスク値に従って書き込みます。
		///	@param	destination
		///	値の設定先。
		///	@param	value
		///	書き込みを行う値。
		constexpr Tp set_to(const Tp& destination, const Tp& value) const noexcept { return (destination & ~mask) | (value & mask); }
		///	入力をマスク値に従ってマスクし、LSBに詰めます。
		///	@param	source
		///	値を取得するソース。
		constexpr Tp get_aligned_from(const Tp& source) const noexcept { return get_from(source) >> get_begin_index(mask); }
		///	LSBに詰められた入力をマスク値に従って書き込みます。
		///	@param	destination
		///	値の設定先。
		///	@param	value
		///	書き込みを行う値。
		constexpr Tp set_aligned_to(const Tp& destination, const Tp& value) const noexcept { return set_to(destination, value << get_begin_index(mask)); }

		constexpr BitMask<Tp> operator~() const noexcept { return BitMask<Tp>(~mask); }
		constexpr BitMask<Tp> operator|(const BitMask<Tp>& other) const noexcept { return BitMask<Tp>(mask | other.mask); }
		constexpr BitMask<Tp> operator&(const BitMask<Tp>& other) const noexcept { return BitMask<Tp>(mask & other.mask); }
		constexpr BitMask<Tp> operator^(const BitMask<Tp>& other) const noexcept { return BitMask<Tp>(mask ^ other.mask); }
		constexpr BitMask<Tp>& operator|=(const BitMask<Tp>& other) noexcept { return *this = BitMask<Tp>(mask | other.mask); }
		constexpr BitMask<Tp>& operator&=(const BitMask<Tp>& other) noexcept { return *this = BitMask<Tp>(mask & other.mask); }
		constexpr BitMask<Tp>& operator^=(const BitMask<Tp>& other) noexcept { return *this = BitMask<Tp>(mask ^ other.mask); }

		///	他の @a BitMask との等価比較を行います。
		///	@param	other
		///	比較対象となるオブジェクト。
		constexpr bool equals(const BitMask<Tp>& other) const noexcept { return mask == other.mask; }
		constexpr bool operator==(const BitMask<Tp>& other) const noexcept { return equals(other); }
		constexpr bool operator!=(const BitMask<Tp>& other) const noexcept { return !equals(other); }
	private:
		///	指定された値の開始ビットのインデックスを取得します。
		static constexpr std::size_t get_begin_index(const Tp& value, const Tp& start = 0) noexcept
		{
			const size_t length = bitwidth<Tp>;
			for (std::size_t i = start; i < length; i++) { if ((value & (1 << i)) != 0) { return i; } }
			return length;
		}
		///	指定された値の終端ビットのインデックスを取得します。
		static constexpr std::size_t get_end_index(const Tp& value, const Tp& start = std::numeric_limits<Tp>::max()) noexcept
		{
			const size_t length = bitwidth<Tp>;
			for (std::size_t i = ((start < length)?start:length); 0 < i; i--) { if ((value & (1 << (i - 1))) != 0) { return i; } }
			return length;
		}
	};

	extern template class BitMask<uint8_t>;
	extern template class BitMask<uint16_t>;
	extern template class BitMask<uint32_t>;
	extern template class BitMask<uint64_t>;
}
#endif // __stationaryorbit_core_bitmask__