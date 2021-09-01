//	stationaryorbit.core.test.range:/test.range.cpp
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
#include "test-helper.hpp"
#include "stationaryorbit/core.numeral.hpp"
using namespace zawa_ch::StationaryOrbit;

std::array<std::function<int(void)>, 8> tests =
{
	[]()
	{
		std::cout << "1. Type Range<size_t>::IteratorType meets the traits Iterator?";
		return check_if(IteratorTraits::IsIterator<Range<size_t>::IteratorType>);
	},
	[]()
	{
		std::cout << "2. Type Range<size_t>::IteratorType meets the traits SequencialOrderIterator?";
		return check_if(IteratorTraits::IsSequencialOrderIterator<Range<size_t>::IteratorType>);
	},
	[]()
	{
		std::cout << "3. Type Range<size_t>::IteratorType meets the traits BidirectionalOrderIterator?";
		return check_if(IteratorTraits::IsBidirectionalOrderIterator<Range<size_t>::IteratorType>);
	},
	[]()
	{
		std::cout << "4. Type Range<size_t>::IteratorType meets the traits SequencialOrderType?";
		return check_if(OrderTypeTraits::IsSequencialOrderType<Range<size_t>::IteratorType>);
	},
	[]()
	{
		std::cout << "5. Type Range<size_t>::IteratorType meets the traits BidirectionalOrderType?";
		return check_if(OrderTypeTraits::IsBidirectionalOrderType<Range<size_t>::IteratorType>);
	},
	[]()
	{
		std::cout << "6. Iterate Range(0, 10)? ";
		// 範囲forを用いて0..9の数値を列挙する
		for(auto i : Range(0, 10).GetStdIterator())
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "7. Reverce iterate Range(5, 12)? ";
		// 逆イテレータを使用して5..11の数値を逆に列挙する
		for(auto i : Range(5, 12).GetStdReverseIterator())
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
		return 0;
	},
	[]()
	{
		// 0.5fが0.0f以上1.0f未満であることを検査する
		std::cout << "8. Range(0.0f, 1.0f).isIncluded(0.5f) -> true?";
		return check_if(Range(0.0f, 1.0f).isIncluded(0.5f));
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- Range --->" << std::endl;
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
