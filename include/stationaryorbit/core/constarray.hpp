//	stationaryorbit/core/constarray
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
#ifndef __stationaryorbit_core_constarray__
#define __stationaryorbit_core_constarray__
namespace zawa_ch::StationaryOrbit
{
	///	コンパイル時に内容が決定する値の配列を表します。
	///	@param	T
	///	値の型。
	///	@param	Values
	///	配列の内容。
	template<class FirstValue, class ... Values>
	struct ConstArray
	{
	private:
		ConstArray() = delete;
		ConstArray(const ConstArray&) = delete;
		ConstArray(ConstArray&&) = delete;
		~ConstArray() = delete;
	public:
		typedef decltype(FirstValue::value) ValueType;
		///	この配列の表す型。
		typedef ValueType Type[sizeof...(Values) + 1];

		///	この @a ConstArray の内容。
		static constexpr Type values = { FirstValue::value, Values::value ... };
		///	この @a ConstArray の配列の大きさ。
		static constexpr size_t size = sizeof...(Values) + 1;

		///	この @a ConstArray の内容に値を追加します。
		template<class ... ConcatValues>
		struct Concat
		{
			typedef ConstArray<FirstValue, Values..., ConcatValues...> Type;
		};
	};
}
#endif // __stationaryorbit_core_constarray__
