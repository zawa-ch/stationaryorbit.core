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
	///	@brief	コンパイル時に内容が決定する値の配列を表します
	///
	///	@a ConstArray はテンプレート引数に列挙された型の静的メンバ定数 @a value を収集し、配列にします。
	///
	///	@param	FirstValue
	///	値の配列の最初の値。静的メンバ定数 @a value を持つ型である必要があります。
	///	@param	Values
	///	値の配列の二番目以降の値。 @a FirstValue::value と同じ型の静的メンバ定数 @a value を持つ型である必要があります。
	template<typename FirstValue, typename ... Values>
	struct ConstArray
	{
	private:
		ConstArray() = delete;
		ConstArray(const ConstArray&) = delete;
		ConstArray(ConstArray&&) = delete;
		~ConstArray() = delete;
	public:
		///	配列の値の型。
		typedef decltype(FirstValue::value) ValueType;
		///	この配列の表す型。
		typedef ValueType Type[sizeof...(Values) + 1];

		///	この @a ConstArray の内容。
		static constexpr Type values = { FirstValue::value, Values::value ... };
		///	この @a ConstArray の配列の大きさ。
		static constexpr size_t size = sizeof...(Values) + 1;

		///	@brief	この @a ConstArray の内容に値を追加します。
		///	@param	ConcatValues
		///	追加する値の列。 @a FirstValue::value と同じ型の静的メンバ定数 @a value を持つ型である必要があります。
		template<typename ... ConcatValues>
		struct Concat
		{
			typedef ConstArray<FirstValue, Values..., ConcatValues...> Type;
		};
	};
}
#endif // __stationaryorbit_core_constarray__
