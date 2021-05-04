//	stationaryorbit/core/bitreference
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
#ifndef __stationaryorbit_core_bitreference__
#define __stationaryorbit_core_bitreference__
#include <cstddef>
#include <stdexcept>
namespace zawa_ch::StationaryOrbit
{
	///	特定のビットへの参照を保持し、ビット単位でのアクセスを行います。
	class BitReference final
	{
	private:
		std::byte& _ref;	///< 参照先の1バイトビット列。
		size_t _pos;	///< 参照先のビット位置。
	public:
		///	特定のビットへの参照を作成します。
		constexpr BitReference(std::byte& reference, size_t bit) : _ref(reference), _pos(bit) { if (8 <= bit) throw std::out_of_range("bit は0から7の範囲内である必要があります。"); }

		///	ビット参照の逆参照を行い、boolに変換します。
		constexpr bool get_value() const { return (_ref & std::byte(0x01 << _pos)) != std::byte(0); }
		constexpr operator bool() const { return get_value(); }
		///	参照先に値を代入します。
		constexpr void set_value(bool value) { _ref = (_ref & std::byte(~(0x01 << _pos))) | std::byte(value & (0x01 << _pos)); }
		constexpr BitReference& operator=(bool value) { set_value(value); return *this; }
	};

}
#endif // __stationaryorbit_core_bitreference__