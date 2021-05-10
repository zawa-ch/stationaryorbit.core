//	stationaryorbit.core.test.delegete:/test.delegete.cpp
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
#include "stationaryorbit/core.utilities.hpp"
using namespace zawa_ch::StationaryOrbit;
class Default_EventArgs : EventArgs {};

class Has_Event
{
public:
	typedef Delegate<const Has_Event&, Default_EventArgs&> Default_EventHandler;
	Default_EventHandler Default_Event;
	void InvokeEvent() const
	{
		auto args = Default_EventArgs();
		Default_Event.Invoke(*this, args);
	}
};

std::array<std::function<int(void)>, 1> tests =
{
	[]()
	{
		std::cout << "1. Event Invoke ->?" << std::endl;
		// Delegate型を使用したイベントを持つ型を用意する
		auto inst = Has_Event();
		bool handled = false;
		// イベントハンドラでhandledをtrueにする
		inst.Default_Event += [&](const auto& sender, Default_EventArgs& args)
		{
			std::cout << "Event handled." << std::endl;
			handled = true;
		};
		inst.InvokeEvent();
		// Default_Eventに登録されたイベントは
		// DelegateをInvokeしたスレッド(ここではメインスレッド)で実行されるため
		// ハンドラを正しく呼び出せている場合はこの段階で必ずhandled==trueになる
		if (handled)
		{
			std::cout << "...OK" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "...NG" << std::endl;
			return 1;
		}
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- Delegate/Event --->" << std::endl;
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
