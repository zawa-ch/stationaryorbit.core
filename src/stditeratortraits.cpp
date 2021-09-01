//	stationaryorbit.core:/stditeratortraits
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
#include <array>
#include <vector>
#include <deque>
#include <list>
#include "stationaryorbit/core/stditeratortraits.hpp"
using namespace zawa_ch::StationaryOrbit;

static_assert(StdIteratorTraits::IsStdLegacyIterator<std::array<int, 16>::iterator>, "std::array のイテレータは LegacyIterator を満たしますが、識別結果は false  を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyInputIterator<std::array<int, 16>::iterator>, "std::array のイテレータは LegacyInputIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyForwardIterator<std::array<int, 16>::iterator>, "std::array のイテレータは LegacyForwardIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyBidirectionalIterator<std::array<int, 16>::iterator>, "std::array のイテレータは LegacyBidirectionalIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyRandomAccessIterator<std::array<int, 16>::iterator>, "std::array のイテレータは LegacyRandomAccessIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyOutputIterator<std::array<int, 16>::iterator, int>, "std::array のイテレータは LegacyOutputIterator を満たしますが、識別結果は false を返しました。");

static_assert(StdIteratorTraits::IsStdLegacyIterator<std::vector<int>::iterator>, "std::vector のイテレータは LegacyIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyInputIterator<std::vector<int>::iterator>, "std::vector のイテレータは LegacyInputIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyForwardIterator<std::vector<int>::iterator>, "std::vector のイテレータは LegacyForwardIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyBidirectionalIterator<std::vector<int>::iterator>, "std::vector のイテレータは LegacyBidirectionalIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyRandomAccessIterator<std::vector<int>::iterator>, "std::vector のイテレータは LegacyRandomAccessIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyOutputIterator<std::vector<int>::iterator, int>, "std::vector のイテレータは LegacyOutputIterator を満たしますが、識別結果は false を返しました。");

static_assert(StdIteratorTraits::IsStdLegacyIterator<std::deque<int>::iterator>, "std::deque のイテレータは LegacyIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyInputIterator<std::deque<int>::iterator>, "std::deque のイテレータは LegacyInputIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyForwardIterator<std::deque<int>::iterator>, "std::deque のイテレータは LegacyForwardIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyBidirectionalIterator<std::deque<int>::iterator>, "std::deque のイテレータは LegacyBidirectionalIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyRandomAccessIterator<std::deque<int>::iterator>, "std::deque のイテレータは LegacyRandomAccessIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyOutputIterator<std::deque<int>::iterator, int>, "std::deque のイテレータは LegacyOutputIterator を満たしますが、識別結果は false を返しました。");

static_assert(StdIteratorTraits::IsStdLegacyIterator<std::list<int>::iterator>, "std::list のイテレータは LegacyIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyInputIterator<std::list<int>::iterator>, "std::list のイテレータは LegacyInputIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyForwardIterator<std::list<int>::iterator>, "std::list のイテレータは LegacyForwardIterator を満たしますが、識別結果は false を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyBidirectionalIterator<std::list<int>::iterator>, "std::list のイテレータは LegacyBidirectionalIterator を満たしますが、識別結果は false を返しました。");
static_assert(!StdIteratorTraits::IsStdLegacyRandomAccessIterator<std::list<int>::iterator>, "std::list のイテレータは LegacyRandomAccessIterator を満たしませんが、識別結果は true を返しました。");
static_assert(StdIteratorTraits::IsStdLegacyOutputIterator<std::list<int>::iterator, int>, "std::list のイテレータは LegacyOutputIterator を満たしますが、識別結果は false を返しました。");