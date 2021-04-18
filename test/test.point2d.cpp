//	stationaryorbit.core.test.point2d:/test.point2d.cpp
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
#include "stationaryorbit/core.numeral.hpp"
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

std::array<std::function<int(void)>, 9> tests =
{
	[]()
	{
		std::cout << "p1 = GeometricPoint(3, 4)" << std::endl;
		std::cout << "p2 = GeometricPoint(2, 8)" << std::endl;
		auto p1 = GeometricPoint(3, 4);
		auto p2 = GeometricPoint(2, 8);
		std::cout << "1. p1 + p2 ? (" << (p1 + p2).X() << ", " << (p1 + p2).Y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "p1 = GeometricPoint(3, 4)" << std::endl;
		std::cout << "p2 = GeometricPoint(2, 8)" << std::endl;
		auto p1 = GeometricPoint(3, 4);
		auto p2 = GeometricPoint(2, 8);
		std::cout << "2. p1 - p2 ? (" << (p1 - p2).X() << ", " << (p1 - p2).Y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "p1 = GeometricPoint(3, 4)" << std::endl;
		auto p1 = GeometricPoint(3, 4);
		std::cout << "3. Point2D<int, Quadrants::DownRight>(p1) == Point2D<int, Quadrants::DownRight>(3, -4) ->true?";
		return check_if(Point2D<int, Quadrants::DownRight>(p1) == Point2D<int, Quadrants::DownRight>(3, -4));
	},
	[]()
	{
		std::cout << "fp1 = GeometricPointF(0.3, 1.8)" << std::endl;
		std::cout << "fp2 = GeometricPointF(-3.1, 2.0)" << std::endl;
		auto fp1 = GeometricPointF(0.3, 1.8);
		auto fp2 = GeometricPointF(-3.1, 2.0);
		std::cout << "4. fp1 + fp2 ? (" << (fp1 + fp2).X() << ", " << (fp1 + fp2).Y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "fp1 = GeometricPointF(0.3, 1.8)" << std::endl;
		std::cout << "fp2 = GeometricPointF(-3.1, 2.0)" << std::endl;
		auto fp1 = GeometricPointF(0.3, 1.8);
		auto fp2 = GeometricPointF(-3.1, 2.0);
		std::cout << "5. fp1 - fp2 ? (" << (fp1 - fp2).X() << ", " << (fp1 - fp2).Y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "fp1 = GeometricPointF(0.3, 1.8)" << std::endl;
		auto fp1 = GeometricPointF(0.3, 1.8);
		std::cout << "6. fp1.Round() ? (" << fp1.Round().X() << ", " << fp1.Round().Y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "fp1 = GeometricPointF(0.3, 1.8)" << std::endl;
		auto fp1 = GeometricPointF(0.3, 1.8);
		std::cout << "7. fp1.Floor() ? (" << fp1.Floor().X() << ", " << fp1.Floor().Y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "fp1 = GeometricPointF(0.3, 1.8)" << std::endl;
		auto fp1 = GeometricPointF(0.3, 1.8);
		std::cout << "8. fp1.Ceiling() ? (" << fp1.Ceiling().X() << ", " << fp1.Ceiling().Y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "fp1 = GeometricPointF(0.3, 1.8)" << std::endl;
		auto fp1 = GeometricPointF(0.3, 1.8);
		std::cout << "9. fp1.Extract() ? (" << fp1.Extract().X() << ", " << fp1.Extract().Y() << ")" << std::endl;
		return 0;
	},
};


int main(int argc, char const *argv[])
{
	std::cout << "<--- Point2D --->" << std::endl;
	if (argc < 2)
	{
		std::cerr << "E: At least 1 argument is required";
		return 2;
	}

	auto test_index = std::stoi(argv[1]);
	if (0 < test_index && test_index <= tests.size() )
	{
		return tests[test_index - 1]();
	}
	else
	{
		std::cerr << "Invalid test index";
		return 2;
	}
}
