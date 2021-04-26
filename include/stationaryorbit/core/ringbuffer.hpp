//	stationaryorbit/core/ringbuffer
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
#ifndef __stationaryorbit_core_ringbuffer__
#define __stationaryorbit_core_ringbuffer__
#include <stdexcept>
#include <array>
#include "invalidoperation.hpp"
namespace zawa_ch::StationaryOrbit
{
	template<class Tp, size_t N> class RingBufferIterator;
	template<class Tp, size_t N> class RingBufferConstIterator;
	template<class Tp, size_t N> class RingBufferReverseIterator;
	template<class Tp, size_t N> class RingBufferConstReverseIterator;

	template<class Tp, size_t N>
	class RingBuffer
	{
	public:
		typedef std::array<Tp, N> DataType;
		typedef Tp ValueType;
		typedef size_t SizeType;
		typedef ptrdiff_t DifferenceType;
		typedef typename DataType::reference Reference;
		typedef typename DataType::const_reference ConstReference;
		typedef typename DataType::pointer Pointer;
		typedef typename DataType::const_pointer ConstPointer;
		typedef RingBufferIterator<Tp, N> Iterator;
		typedef RingBufferConstIterator<Tp, N> ConstIterator;
		typedef RingBufferReverseIterator<Tp, N> ReverseIterator;
		typedef RingBufferConstReverseIterator<Tp, N> ConstReverseIterator;
	private:
		DataType _data;
		SizeType _orig;
		SizeType _size;
	public:
		constexpr RingBuffer() : _data(), _orig(0), _size(0) {}

		[[nodiscard]] constexpr bool empty() const noexcept { return _size == 0; }
		[[nodiscard]] constexpr SizeType size() const noexcept { return _size; }
		[[nodiscard]] constexpr SizeType capacity() const noexcept { return N; }
		[[nodiscard]] constexpr Reference at(SizeType pos)
		{
			if (_size <= pos) { throw std::out_of_range("指定されたインデックスはオブジェクトの領域を超えています。"); }
			return _data.at((_orig + pos) % N);
		}
		[[nodiscard]] constexpr ConstReference at(SizeType pos) const
		{
			if (_size <= pos) { throw std::out_of_range("指定されたインデックスはオブジェクトの領域を超えています。"); }
			return _data.at((_orig + pos) % N);
		}
		[[nodiscard]] constexpr Reference operator[](SizeType pos) { return _data[(_orig + pos) % N]; }
		[[nodiscard]] constexpr ConstReference operator[](SizeType pos) const { return _data[(_orig + pos) % N]; }
		[[nodiscard]] constexpr Reference front() { return operator[](0); }
		[[nodiscard]] constexpr ConstReference front() const { return operator[](0); }
		[[nodiscard]] constexpr Reference back() { return operator[](_size - 1); }
		[[nodiscard]] constexpr ConstReference back() const { return operator[](_size - 1); }

		constexpr void clear() noexcept
		{
			_data.fill(Tp());
			_orig = 0;
			_size = 0;
		}
		constexpr void push_back(const ValueType& value)
		{
			if (N <= _size) { throw InvalidOperationException("バッファの内容がいっぱいです。"); }
			_data.at((_orig + _size) % N) = value;
			++_size;
		}
		constexpr void push_back(ValueType&& value)
		{
			if (N <= _size) { throw InvalidOperationException("バッファの内容がいっぱいです。"); }
			_data.at((_orig + _size) % N) = std::move(value);
			++_size;
		}
		constexpr void push_front(const ValueType& value)
		{
			if (N <= _size) { throw InvalidOperationException("バッファの内容がいっぱいです。"); }
			_data.at((_orig + (N - 1)) % N) = value;
			_orig = (0 <= _orig)?(_orig - 1):(N - 1);
			++_size;
		}
		constexpr void push_front(ValueType&& value)
		{
			if (N <= _size) { throw InvalidOperationException("バッファの内容がいっぱいです。"); }
			_data.at((_orig + (N - 1)) % N) = std::move(value);
			_orig = (0 <= _orig)?(_orig - 1):(N - 1);
			++_size;
		}
		template<class It>
		constexpr void copy_back(It first, It last)
		{
			size_t copy_size = std::abs(std::distance(first, last));
			if (N < (_size + copy_size)) { throw InvalidOperationException("バッファの内容がいっぱいです。"); }
			while(first != last)
			{
				push_back(*first);
				++first;
			}
		}
		template<class It>
		constexpr void copy_front(It first, It last)
		{
			size_t copy_size = std::abs(std::distance(first, last));
			if (N < (_size + copy_size)) { throw InvalidOperationException("バッファの内容がいっぱいです。"); }
			size_t new_orig = ((copy_size <= _orig)?(_orig - copy_size):(N - (copy_size - _orig)));
			size_t i = 0;
			while(first != last)
			{
				_data.at((new_orig + i) % N) = *first;
				++first;
				++i;
			}
			_orig = new_orig;
			_size += copy_size;
		}
		constexpr void pop_back()
		{
			if (_size == 0) { throw InvalidOperationException("空のバッファから値を削除しようとしました。"); }
			--_size;
			_data.at((_orig + _size) % N) = Tp();
		}
		constexpr void pop_front()
		{
			if (_size == 0) { throw InvalidOperationException("空のバッファから値を削除しようとしました。"); }
			_orig = (_orig < (N - 1))?(_orig + 1):(0);
			--_size;
			_data.at((_orig + (N - 1)) % N) = Tp();
		}

		[[nodiscard]] constexpr Iterator begin() noexcept { return Iterator(_data.begin(), _orig); }
		[[nodiscard]] constexpr ConstIterator begin() const noexcept { return ConstIterator(_data.begin(), _orig); }
		[[nodiscard]] constexpr Iterator end() noexcept { return Iterator(_data.begin(), _orig + _size); }
		[[nodiscard]] constexpr ConstIterator end() const noexcept { return ConstIterator(_data.begin(), _orig + _size); }
		[[nodiscard]] constexpr ConstIterator cbegin() const noexcept { return ConstIterator(_data.cbegin(), _orig); }
		[[nodiscard]] constexpr ConstIterator cend() const noexcept { return ConstIterator(_data.cbegin(), _orig + _size); }
		[[nodiscard]] constexpr ReverseIterator rbegin() noexcept { return ReverseIterator(_data.begin(), _orig + _size); }
		[[nodiscard]] constexpr ConstReverseIterator rbegin() const noexcept { return ConstReverseIterator(_data.begin(), _orig + _size); }
		[[nodiscard]] constexpr ReverseIterator rend() noexcept { return ReverseIterator(_data.begin(), _orig); }
		[[nodiscard]] constexpr ConstReverseIterator rend() const noexcept { return ConstReverseIterator(_data.begin(), _orig); }
		[[nodiscard]] constexpr ConstReverseIterator crbegin() const noexcept { return ConstReverseIterator(_data.cbegin(), _orig + _size); }
		[[nodiscard]] constexpr ConstReverseIterator crend() const noexcept { return ConstReverseIterator(_data.cbegin(), _orig); }
	};
	template<class Tp, size_t N>
	class RingBufferIterator
	{
	public:
		typedef RingBuffer<Tp, N> DataType;
		typedef typename DataType::ValueType ValueType;
		typedef typename DataType::DifferenceType DifferenceType;
		typedef typename DataType::Reference Reference;
		typedef typename DataType::Pointer Pointer;
		typedef std::bidirectional_iterator_tag Category;
		typedef typename DataType::DataType::iterator BaseIterator;
	private:
		const BaseIterator b;
		size_t i;
	public:
		constexpr RingBufferIterator(BaseIterator base, size_t index) : b(base), i(index) {}

		[[nodiscard]] Reference operator*() { return *(b + (i % N)); }
		RingBufferIterator& operator++() { ++i; return *this; }
		[[nodiscard]] RingBufferIterator operator++(int) { RingBufferIterator result = *this; ++(*this); return result; }
		RingBufferIterator& operator--() { --i; return *this; }
		[[nodiscard]] RingBufferIterator operator--(int) { RingBufferIterator result = *this; --(*this); return result; }
		[[nodiscard]] bool equals(const RingBufferIterator& other) const noexcept { return (b == other.b) && (i == other.i); }
		[[nodiscard]] bool operator==(const RingBufferIterator& other) const noexcept { return equals(other); }
		[[nodiscard]] bool operator!=(const RingBufferIterator& other) const noexcept { return !equals(other); }
	};
	template<class Tp, size_t N>
	class RingBufferConstIterator
	{
	public:
		typedef RingBuffer<Tp, N> DataType;
		typedef typename DataType::ValueType ValueType;
		typedef typename DataType::DifferenceType DifferenceType;
		typedef typename DataType::ConstReference Reference;
		typedef typename DataType::ConstPointer Pointer;
		typedef std::bidirectional_iterator_tag Category;
		typedef typename DataType::DataType::const_iterator BaseIterator;
	private:
		const BaseIterator b;
		size_t i;
	public:
		constexpr RingBufferConstIterator(BaseIterator base, size_t index) : b(base), i(index) {}

		[[nodiscard]] Reference operator*() { return *(b + (i % N)); }
		RingBufferConstIterator& operator++() { ++i; return *this; }
		[[nodiscard]] RingBufferConstIterator operator++(int) { RingBufferConstIterator result = *this; ++(*this); return result; }
		RingBufferConstIterator& operator--() { --i; return *this; }
		[[nodiscard]] RingBufferConstIterator operator--(int) { RingBufferConstIterator result = *this; --(*this); return result; }
		[[nodiscard]] bool equals(const RingBufferConstIterator& other) const noexcept { return (b == other.b) && (i == other.i); }
		[[nodiscard]] bool operator==(const RingBufferConstIterator& other) const noexcept { return equals(other); }
		[[nodiscard]] bool operator!=(const RingBufferConstIterator& other) const noexcept { return !equals(other); }
	};
	template<class Tp, size_t N>
	class RingBufferReverseIterator
	{
	public:
		typedef RingBuffer<Tp, N> DataType;
		typedef typename DataType::ValueType ValueType;
		typedef typename DataType::DifferenceType DifferenceType;
		typedef typename DataType::Reference Reference;
		typedef typename DataType::Pointer Pointer;
		typedef std::bidirectional_iterator_tag Category;
		typedef typename DataType::DataType::iterator BaseIterator;
	private:
		const BaseIterator b;
		size_t i;
	public:
		constexpr RingBufferReverseIterator(BaseIterator base, size_t index) : b(base), i(index) {}

		[[nodiscard]] Reference operator*() { return *(b + ((i - 1) % N)); }
		RingBufferReverseIterator& operator++() { --i; return *this; }
		[[nodiscard]] RingBufferReverseIterator operator++(int) { RingBufferReverseIterator result = *this; ++(*this); return result; }
		RingBufferReverseIterator& operator--() { ++i; return *this; }
		[[nodiscard]] RingBufferReverseIterator operator--(int) { RingBufferReverseIterator result = *this; --(*this); return result; }
		[[nodiscard]] bool equals(const RingBufferReverseIterator& other) const noexcept { return (b == other.b) && (i == other.i); }
		[[nodiscard]] bool operator==(const RingBufferReverseIterator& other) const noexcept { return equals(other); }
		[[nodiscard]] bool operator!=(const RingBufferReverseIterator& other) const noexcept { return !equals(other); }
	};
	template<class Tp, size_t N>
	class RingBufferConstReverseIterator
	{
	public:
		typedef RingBuffer<Tp, N> DataType;
		typedef typename DataType::ValueType ValueType;
		typedef typename DataType::DifferenceType DifferenceType;
		typedef typename DataType::ConstReference Reference;
		typedef typename DataType::ConstPointer Pointer;
		typedef std::bidirectional_iterator_tag Category;
		typedef typename DataType::DataType::const_iterator BaseIterator;
	private:
		const BaseIterator b;
		size_t i;
	public:
		constexpr RingBufferConstReverseIterator(BaseIterator base, size_t index) : b(base), i(index) {}

		[[nodiscard]] Reference operator*() { return *(b + ((i - 1) % N)); }
		RingBufferConstReverseIterator& operator++() { --i; return *this; }
		[[nodiscard]] RingBufferConstReverseIterator operator++(int) { RingBufferConstReverseIterator result = *this; ++(*this); return result; }
		RingBufferConstReverseIterator& operator--() { ++i; return *this; }
		[[nodiscard]] RingBufferConstReverseIterator operator--(int) { RingBufferConstReverseIterator result = *this; --(*this); return result; }
		[[nodiscard]] bool equals(const RingBufferConstReverseIterator& other) const noexcept { return (b == other.b) && (i == other.i); }
		[[nodiscard]] bool operator==(const RingBufferConstReverseIterator& other) const noexcept { return equals(other); }
		[[nodiscard]] bool operator!=(const RingBufferConstReverseIterator& other) const noexcept { return !equals(other); }
	};
}
namespace std
{
	template<class Tp, size_t N>
	struct iterator_traits<typename zawa_ch::StationaryOrbit::RingBufferIterator<Tp, N>>
	{
		typedef typename zawa_ch::StationaryOrbit::RingBufferIterator<Tp, N>::DifferenceType difference_type;
		typedef typename zawa_ch::StationaryOrbit::RingBufferIterator<Tp, N>::ValueType value_type;
		typedef typename zawa_ch::StationaryOrbit::RingBufferIterator<Tp, N>::Pointer pointer;
		typedef typename zawa_ch::StationaryOrbit::RingBufferIterator<Tp, N>::Reference reference;
		typedef typename zawa_ch::StationaryOrbit::RingBufferIterator<Tp, N>::Category iterator_category;
	};
	template<class Tp, size_t N>
	struct iterator_traits<typename zawa_ch::StationaryOrbit::RingBufferConstIterator<Tp, N>>
	{
		typedef typename zawa_ch::StationaryOrbit::RingBufferConstIterator<Tp, N>::DifferenceType difference_type;
		typedef typename zawa_ch::StationaryOrbit::RingBufferConstIterator<Tp, N>::ValueType value_type;
		typedef typename zawa_ch::StationaryOrbit::RingBufferConstIterator<Tp, N>::Pointer pointer;
		typedef typename zawa_ch::StationaryOrbit::RingBufferConstIterator<Tp, N>::Reference reference;
		typedef typename zawa_ch::StationaryOrbit::RingBufferConstIterator<Tp, N>::Category iterator_category;
	};
	template<class Tp, size_t N>
	struct iterator_traits<typename zawa_ch::StationaryOrbit::RingBufferReverseIterator<Tp, N>>
	{
		typedef typename zawa_ch::StationaryOrbit::RingBufferReverseIterator<Tp, N>::DifferenceType difference_type;
		typedef typename zawa_ch::StationaryOrbit::RingBufferReverseIterator<Tp, N>::ValueType value_type;
		typedef typename zawa_ch::StationaryOrbit::RingBufferReverseIterator<Tp, N>::Pointer pointer;
		typedef typename zawa_ch::StationaryOrbit::RingBufferReverseIterator<Tp, N>::Reference reference;
		typedef typename zawa_ch::StationaryOrbit::RingBufferReverseIterator<Tp, N>::Category iterator_category;
	};
	template<class Tp, size_t N>
	struct iterator_traits<typename zawa_ch::StationaryOrbit::RingBufferConstReverseIterator<Tp, N>>
	{
		typedef typename zawa_ch::StationaryOrbit::RingBufferConstReverseIterator<Tp, N>::DifferenceType difference_type;
		typedef typename zawa_ch::StationaryOrbit::RingBufferConstReverseIterator<Tp, N>::ValueType value_type;
		typedef typename zawa_ch::StationaryOrbit::RingBufferConstReverseIterator<Tp, N>::Pointer pointer;
		typedef typename zawa_ch::StationaryOrbit::RingBufferConstReverseIterator<Tp, N>::Reference reference;
		typedef typename zawa_ch::StationaryOrbit::RingBufferConstReverseIterator<Tp, N>::Category iterator_category;
	};
}
#endif // __stationaryorbit_core_ringbuffer__
