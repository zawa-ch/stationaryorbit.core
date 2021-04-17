//	stationaryorbit.core.test.iterator:/test.iterator
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
#include <iostream>
#include "stationaryorbit/core.iteration.hpp"
using namespace zawa_ch::StationaryOrbit;

int test1();
int test2();
int test3();
int test4();

int main(int argc, char const *argv[])
{
	std::cout << "<--- Iterator --->" << std::endl;
	if (argc < 2)
	{
		std::cerr << "E: At least 1 argument is required";
		return 2;
	}

	auto test_index = std::stoi(argv[1]);
	switch(test_index)
	{
		case 1: { return test1(); }
		case 2: { return test2(); }
		case 3: { return test3(); }
		default:
		{
			std::cerr << "Invalid test index";
			return 2;
		}
	}
	return 0;
}

class IncrementIterator
{
public:
	typedef int ValueType;
private:
	ValueType _i;
	const ValueType tgt;
public:
	IncrementIterator(ValueType target) :  _i(0), tgt(target) {}
	[[nodiscard]] bool Equals(const IncrementIterator& other) const { return (_i == other._i) && (tgt == other.tgt); }
	bool Next() { if (HasValue()) { ++_i; } return HasValue(); }
	[[nodiscard]] const ValueType& Current() const { return _i; }
	[[nodiscard]] bool HasValue() const { return _i < tgt; }
	void Reset() { _i = 0; }
};
static_assert(IteratorTraits::IsSequencialOrderIterator<IncrementIterator>, "テストに使用される IncrementIterator が IsSequencialOrderIterator の要件を満たしませんでした。");

int test1()
{
	std::vector<int> cont = {1, 2, 3, 4, 5};
	ItrProcesser::ForEach(LegacyIterator(cont), [](auto item) { std::cout << item << " "; });
	std::cout << std::endl;
	return 0;
}

int test2()
{
	std::vector<int> cont = {1, 2, 3, 4, 5};
	ItrProcesser::ForEach(LegacyReverseIterator(cont), [](const auto& item)->void { std::cout << item << " "; });
	std::cout << std::endl;
	return 0;
}

int test3()
{
	auto it = IncrementIterator(5);
	for(auto i: IteratorAdaptContainer(it))
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return 0;
}
