//	stationaryorbit.core:/stdcontainertraits
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
#include <set>
#include <map>
#include "stationaryorbit/core/stdcontainertraits.hpp"
using namespace zawa_ch::StationaryOrbit;

static_assert(StdContainerTraits::is_container<std::array<int, 16>>, "std::array は 名前付き要件:Container を満たしますが、Traits判定は false でした。");
static_assert(StdContainerTraits::is_container<std::vector<int>>, "std::vector は 名前付き要件:Container を満たしますが、Traits判定は false でした。");
static_assert(StdContainerTraits::is_container<std::deque<int>>, "std::deque は 名前付き要件:Container を満たしますが、Traits判定は false でした。");
static_assert(StdContainerTraits::is_container<std::list<int>>, "std::list は 名前付き要件:Container を満たしますが、Traits判定は false でした。");
static_assert(StdContainerTraits::is_container<std::set<int>>, "std::set は 名前付き要件:Container を満たしますが、Traits判定は false でした。");
static_assert(StdContainerTraits::is_container<std::map<int, int>>, "std::map は 名前付き要件:Container を満たしますが、Traits判定は false でした。");

static_assert(StdReversibleContainerTraits::is_reversible_container<std::array<int, 16>>, "std::array は 名前付き要件:Container を満たしますが、Traits判定は false でした。");
static_assert(StdReversibleContainerTraits::is_reversible_container<std::vector<int>>, "std::vector は 名前付き要件:Container を満たしますが、Traits判定は false でした。");
static_assert(StdReversibleContainerTraits::is_reversible_container<std::deque<int>>, "std::deque は 名前付き要件:Container を満たしますが、Traits判定は false でした。");
static_assert(StdReversibleContainerTraits::is_reversible_container<std::list<int>>, "std::list は 名前付き要件:Container を満たしますが、Traits判定は false でした。");
static_assert(StdReversibleContainerTraits::is_reversible_container<std::set<int>>, "std::set は 名前付き要件:Container を満たしますが、Traits判定は false でした。");
static_assert(StdReversibleContainerTraits::is_reversible_container<std::map<int, int>>, "std::map は 名前付き要件:Container を満たしますが、Traits判定は false でした。");
