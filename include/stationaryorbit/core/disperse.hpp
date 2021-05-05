//	stationaryorbit/core/disperse
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
#ifndef __stationaryorbit_core_disperse__
#define __stationaryorbit_core_disperse__
#include <array>
namespace zawa_ch::StationaryOrbit
{
	///	データ型をバイナリ列として読み取ったり、その逆を行う変換を提供します
	class Disperse final
	{
		Disperse() = delete;
		~Disperse() = delete;
	public:
		template<class Tp>
		[[nodiscard]] static constexpr const std::array<std::byte, sizeof(Tp)>& to_binary(const Tp& object) { return reinterpret_cast<const std::array<std::byte, sizeof(Tp)>&>(object); }
		template<class Tp>
		[[nodiscard]] static constexpr std::array<std::byte, sizeof(Tp)>& to_binary(Tp& object) { return reinterpret_cast<std::array<std::byte, sizeof(Tp)>&>(object); }
		template<class Tp>
		[[nodiscard]] static constexpr std::array<std::byte, sizeof(Tp)> to_binary(Tp&& object) { return reinterpret_cast<std::array<std::byte, sizeof(Tp)>&&>(object); }
		template<class Tp>
		[[nodiscard]] static constexpr const Tp& perse(const std::array<std::byte, sizeof(Tp)>& data){ return reinterpret_cast<const Tp&>(data); }
		template<class Tp>
		[[nodiscard]] static constexpr Tp& perse(std::array<std::byte, sizeof(Tp)>& data){ return reinterpret_cast<Tp&>(data); }
		template<class Tp>
		[[nodiscard]] static constexpr Tp perse(std::array<std::byte, sizeof(Tp)>&& data){ return reinterpret_cast<Tp&&>(data); }
	};
}
#endif // __stationaryorbit_core_disperse__
