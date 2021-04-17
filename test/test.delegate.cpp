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
#include "stationaryorbit/core.delegate.hpp"
#include "stationaryorbit/core.event.hpp"
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

int test1();

int main(int argc, char const *argv[])
{
	std::cout << "<--- Delegate/Event --->" << std::endl;
	if (argc < 2)
	{
		std::cerr << "E: At least 1 argument is required";
		return 2;
	}

	auto test_index = std::stoi(argv[1]);
	switch(test_index)
	{
		case 1: { return test1(); }
		default:
		{
			std::cerr << "Invalid test index";
			return 2;
		}
	}
}

int test1()
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
}
