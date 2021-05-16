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
#include "test-helper.hpp"
#include "stationaryorbit/core.numeral.hpp"
using namespace zawa_ch::StationaryOrbit;

std::array<std::function<int(void)>, 9> tests =
{
	[]()
	{
		std::cout << "p1 = GeometricPoint(3, 4)" << std::endl;
		std::cout << "p2 = GeometricPoint(2, 8)" << std::endl;
		auto p1 = GeometricPoint(3, 4);
		auto p2 = GeometricPoint(2, 8);
		std::cout << "1. p1 + p2 ? (" << (p1 + p2).x() << ", " << (p1 + p2).y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "p1 = GeometricPoint(3, 4)" << std::endl;
		std::cout << "p2 = GeometricPoint(2, 8)" << std::endl;
		auto p1 = GeometricPoint(3, 4);
		auto p2 = GeometricPoint(2, 8);
		std::cout << "2. p1 - p2 ? (" << (p1 - p2).x() << ", " << (p1 - p2).y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "p1 = GeometricPoint(3, 4)" << std::endl;
		auto p1 = GeometricPoint(3, 4);
		std::cout << "3. Point2D<int, Quadrants2D::DownRight>(p1) == Point2D<int, Quadrants2D::DownRight>(3, -4) ->true?";
		return check_if(Point2D<int, Quadrants2D::DownRight>(p1) == Point2D<int, Quadrants2D::DownRight>(3, -4));
	},
	[]()
	{
		std::cout << "fp1 = GeometricPointF(0.3, 1.8)" << std::endl;
		std::cout << "fp2 = GeometricPointF(-3.1, 2.0)" << std::endl;
		auto fp1 = GeometricPointF(0.3, 1.8);
		auto fp2 = GeometricPointF(-3.1, 2.0);
		std::cout << "4. fp1 + fp2 ? (" << (fp1 + fp2).x() << ", " << (fp1 + fp2).y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "fp1 = GeometricPointF(0.3, 1.8)" << std::endl;
		std::cout << "fp2 = GeometricPointF(-3.1, 2.0)" << std::endl;
		auto fp1 = GeometricPointF(0.3, 1.8);
		auto fp2 = GeometricPointF(-3.1, 2.0);
		std::cout << "5. fp1 - fp2 ? (" << (fp1 - fp2).x() << ", " << (fp1 - fp2).y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "fp1 = GeometricPointF(0.3, 1.8)" << std::endl;
		auto fp1 = GeometricPointF(0.3, 1.8);
		std::cout << "6. fp1.round() ? (" << fp1.round().x() << ", " << fp1.round().y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "fp1 = GeometricPointF(0.3, 1.8)" << std::endl;
		auto fp1 = GeometricPointF(0.3, 1.8);
		std::cout << "7. fp1.floor() ? (" << fp1.floor().x() << ", " << fp1.floor().y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "fp1 = GeometricPointF(0.3, 1.8)" << std::endl;
		auto fp1 = GeometricPointF(0.3, 1.8);
		std::cout << "8. fp1.ceil() ? (" << fp1.ceil().x() << ", " << fp1.ceil().y() << ")" << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "fp1 = GeometricPointF(0.3, 1.8)" << std::endl;
		auto fp1 = GeometricPointF(0.3, 1.8);
		std::cout << "9. fp1.extract() ? (" << fp1.extract().x() << ", " << fp1.extract().y() << ")" << std::endl;
		return 0;
	},
};


int main(int argc, char const *argv[])
{
	std::cout << "<--- Point2D --->" << std::endl;
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
