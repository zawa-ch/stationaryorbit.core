//	stationaryorbit.core.test.iterator:/test.iterator
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
#include "stationaryorbit/core.iteration.hpp"
using namespace zawa_ch::StationaryOrbit;

class IncrementIterator
{
public:
	typedef int ValueType;
private:
	ValueType _i;
	const ValueType tgt;
public:
	IncrementIterator(ValueType target) :  _i(0), tgt(target) {}
	[[nodiscard]] bool equals(const IncrementIterator& other) const { return (_i == other._i) && (tgt == other.tgt); }
	bool next() { if (has_value()) { ++_i; } return has_value(); }
	[[nodiscard]] const ValueType& current() const { return _i; }
	[[nodiscard]] bool has_value() const { return _i < tgt; }
	void reset() { _i = 0; }
};
static_assert(SequencialOrderIteratorTraits::is_sequencial_order_iterator<IncrementIterator>, "テストに使用される IncrementIterator が is_sequencial_order_iterator の要件を満たしませんでした。");

std::array<std::function<int(void)>, 9> tests =
{
	[]()
	{
		std::cout << "1. Type LegacyIterator<std::vector<int>> meets the traits Iterator?";
		return check_if(IteratorTraits::is_iterator<LegacyIterator<std::vector<int>>>);
	},
	[]()
	{
		std::cout << "2. Type LegacyIterator<std::vector<int>> meets the traits SequencialOrderIterator?";
		return check_if(SequencialOrderIteratorTraits::is_sequencial_order_iterator<LegacyIterator<std::vector<int>>>);
	},
	[]()
	{
		std::cout << "3. Type LegacyIterator<std::vector<int>> meets the traits BidirectionalOrderIterator?";
		return check_if(BidirectionalOrderIteratorTraits::is_bidirectional_order_iterator<LegacyIterator<std::vector<int>>>);
	},
	[]()
	{
		std::cout << "4. Type LegacyReverseIterator<std::vector<int>> meets the traits Iterator?";
		return check_if(IteratorTraits::is_iterator<LegacyReverseIterator<std::vector<int>>>);
	},
	[]()
	{
		std::cout << "5. Type LegacyReverseIterator<std::vector<int>> meets the traits SequencialOrderIterator?";
		return check_if(SequencialOrderIteratorTraits::is_sequencial_order_iterator<LegacyReverseIterator<std::vector<int>>>);
	},
	[]()
	{
		std::cout << "6. Type LegacyReverseIterator<std::vector<int>> meets the traits BidirectionalOrderIterator?";
		return check_if(BidirectionalOrderIteratorTraits::is_bidirectional_order_iterator<LegacyReverseIterator<std::vector<int>>>);
	},
	[]()
	{
		std::vector<int> cont = {1, 2, 3, 4, 5};
		IteratorProcesser::ForEach(LegacyIterator(cont), [](auto item) { std::cout << item << " "; });
		std::cout << std::endl;
		return 0;
	},
	[]()
	{
		std::vector<int> cont = {1, 2, 3, 4, 5};
		IteratorProcesser::ForEach(LegacyReverseIterator(cont), [](const auto& item)->void { std::cout << item << " "; });
		std::cout << std::endl;
		return 0;
	},
	[]()
	{
		auto it = IncrementIterator(5);
		for(auto i: IteratorAdaptContainer(it))
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- Iterator --->" << std::endl;
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
