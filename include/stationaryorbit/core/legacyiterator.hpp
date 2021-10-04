//	stationaryorbit/core/legacyiterator
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
#ifndef __stationaryorbit_core_legacyiterator__
#define __stationaryorbit_core_legacyiterator__
#include <stdexcept>
namespace zawa_ch::StationaryOrbit
{
	template<class contT, class T = typename contT::value_type>
	class LegacyIterator
	{
	public:
		typedef contT ContainerType;
		typedef T ValueType;
	private:
		const ContainerType& _cont;
		typename contT::const_iterator _itr;
	public:
		LegacyIterator(const ContainerType& container) : _cont(container) {}
		virtual void reset() { _itr = _cont.cbegin(); }
		virtual bool has_value() const { return _itr != _cont.cend(); }
		virtual const T& current() const { if (has_value()) { return *_itr; } else { throw std::out_of_range("要素の範囲外にあるイテレータに対して逆参照を試みました。"); } }
		virtual bool next() { if (has_value()) { ++_itr; } return _itr != _cont.cend(); }
	};

	template<class contT, class T = typename contT::value_type>
	class LegacyReverseIterator
	{
	public:
		typedef contT ContainerType;
		typedef T ValueType;
	private:
		const ContainerType& _cont;
		typename contT::const_reverse_iterator _itr;
	public:
		LegacyReverseIterator(const ContainerType& container) : _cont(container) {}
		virtual void reset() { _itr = _cont.crbegin(); }
		virtual bool has_value() const { return _itr != _cont.crend(); }
		virtual const T& current() const { if (has_value()) { return *_itr; } else { throw std::out_of_range("要素の範囲外にあるイテレータに対して逆参照を試みました。"); } }
		virtual bool next() { if (has_value()) { ++_itr; } return _itr != _cont.crend(); }
	};
}
#endif // __stationaryorbit_core_legacyiterator__
