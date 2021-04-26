//	stationaryorbit.core.test.ringbuffer:/test.ringbuffer.cpp
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
#include <iostream>
#include <array>
#include <functional>
#include "stationaryorbit/core.datastructure.hpp"
#include "stationaryorbit/core.iteration.hpp"
using namespace zawa_ch::StationaryOrbit;

constexpr int check_if(bool condition)
{
	if (condition)
	{
		std::cout << "...OK" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "...NG" << std::endl;
		return 1;
	}
}

std::array<std::function<int(void)>, 6> tests =
{
	[]()
	{
		std::array<int, 4> d1 = { 1, 2, 4, 7 };
		std::cout << "d1 = std::array<int, 4>{ 1, 2, 4, 7 }" << std::endl;
		RingBuffer<int, 10> b;
		std::cout << "RingBuffer::copy_back(d1)" << std::endl;
		b.copy_back(d1.cbegin(), d1.cend());
		std::cout << "1. for(b) ? ";
		for(auto i: b)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
		return 0;
	},
	[]()
	{
		std::array<int, 4> d1 = { 1, 2, 4, 7 };
		std::cout << "d1 = std::array<int, 4>{ 1, 2, 4, 7 }" << std::endl;
		RingBuffer<int, 10> b;
		std::cout << "RingBuffer::copy_back(d1)" << std::endl;
		b.copy_back(d1.cbegin(), d1.cend());
		std::cout << "2. for(const b) ? ";
		for(auto i: static_cast<const RingBuffer<int, 10>&>(b))
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
		return 0;
	},
	[]()
	{
		std::array<int, 4> d1 = { 1, 2, 4, 7 };
		std::cout << "d1 = std::array<int, 4>{ 1, 2, 4, 7 }" << std::endl;
		RingBuffer<int, 10> b;
		std::cout << "RingBuffer::copy_front(d1)" << std::endl;
		b.copy_front(d1.cbegin(), d1.cend());
		std::cout << "3. rfor(b) ? ";
		auto it = b.rbegin();
		auto ie = b.rend();
		while(it != ie)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		return 0;
	},
	[]()
	{
		std::array<int, 4> d1 = { 1, 2, 4, 7 };
		std::cout << "d1 = std::array<int, 4>{ 1, 2, 4, 7 }" << std::endl;
		RingBuffer<int, 10> b;
		std::cout << "RingBuffer::copy_front(d1)" << std::endl;
		b.copy_front(d1.cbegin(), d1.cend());
		std::cout << "4. rfor(const b) ? ";
		auto it = b.crbegin();
		auto ie = b.crend();
		while(it != ie)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		return 0;
	},
	[]()
	{
		std::array<int, 10> d1;
		std::cout << "d1 = std::array<int, 10>{}" << std::endl;
		RingBuffer<int, 10> b;
		std::cout << "RingBuffer::copy_back(d1)" << std::endl;
		b.copy_back(d1.cbegin(), d1.cend());
		std::cout << "5. push_back(0) to full buffer?";
		try
		{
			b.push_back(0);
		}
		catch (InvalidOperationException e)
		{
			std::cout << "...NG (throw exception)" << std::endl << e.what() << std::endl;
			return 1;
		}
		std::cout << "...OK" << std::endl;
		return 0;
	},
	[]()
	{
		std::array<int, 10> d1;
		std::cout << "d1 = std::array<int, 10>{}" << std::endl;
		RingBuffer<int, 10> b;
		std::cout << "RingBuffer::copy_back(d1)" << std::endl;
		b.copy_back(d1.cbegin(), d1.cend());
		std::cout << "6. push_front(0) to full buffer?";
		try
		{
			b.push_front(0);
		}
		catch (InvalidOperationException e)
		{
			std::cout << "...NG (throw exception)" << std::endl << e.what() << std::endl;
			return 1;
		}
		std::cout << "...OK" << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- RingBuffer --->" << std::endl;
	int test_index;
	if (2 <= argc)
	{
		test_index = std::stoi(argv[1]);
	}
	else
	{
		std::cerr << "W: No test# specified" << std::endl;
		std::cout << "Test#? ";
		std::cin >> test_index;
	}
	if (0 < test_index && test_index <= tests.size() )
	{
		return tests[test_index - 1]();
	}
	else
	{
		std::cerr << "E: Invalid test index" << std::endl;
		return 2;
	}
}
