//	stationaryorbit.core.test.rectangle2d:/test.rectangle2d.cpp
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
		auto r1 = GeometricRectangle(0, 0, 3, 4);
		std::cout << "r1 = GeometricRectangle(0, 0, 3, 4)" << std::endl;
		std::cout << "1. r1.left ? " << r1.Left() << std::endl;
		return 0;
	},
	[]()
	{
		auto r1 = GeometricRectangle(0, 0, 3, 4);
		std::cout << "r1 = GeometricRectangle(0, 0, 3, 4)" << std::endl;
		std::cout << "2. r1.right ? " << r1.Right() << std::endl;
		return 0;
	},
	[]()
	{
		auto r1 = GeometricRectangle(0, 0, 3, 4);
		std::cout << "r1 = GeometricRectangle(0, 0, 3, 4)" << std::endl;
		std::cout << "3. r1.top ? " << r1.Top() << std::endl;
		return 0;
	},
	[]()
	{
		auto r1 = GeometricRectangle(0, 0, 3, 4);
		std::cout << "r1 = GeometricRectangle(0, 0, 3, 4)" << std::endl;
		std::cout << "4. r1.bottom ? " << r1.Bottom() << std::endl;
		return 0;
	},
	[]()
	{
		auto r1 = GeometricRectangle(0, 0, 3, 4);
		std::cout << "r1 = GeometricRectangle(0, 0, 3, 4)" << std::endl;
		std::cout << "5. r1.Contains(GeometricRectangle::PointType(1, 1)) -> true?" << std::endl;
		return check_if(r1.Contains(GeometricRectangle::PointType(1, 1)));
	},
	[]()
	{
		auto r1 = GeometricRectangle(0, 0, 3, 4);
		auto r2 = r1.Offset(GeometricRectangle::PointType(-3, 6));
		std::cout << "r1 = GeometricRectangle(0, 0, 3, 4)" << std::endl;
		std::cout << "r2 = r1.Offset(GeometricRectangle::PointType(-3, 6))" << std::endl;
		std::cout << "6. r2.left ? " << r2.Left() << std::endl;
		return 0;
	},
	[]()
	{
		auto r1 = GeometricRectangle(0, 0, 3, 4);
		auto r2 = r1.Offset(GeometricRectangle::PointType(-3, 6));
		std::cout << "r1 = GeometricRectangle(0, 0, 3, 4)" << std::endl;
		std::cout << "r2 = r1.Offset(GeometricRectangle::PointType(-3, 6))" << std::endl;
		std::cout << "7. r2.right ? " << r2.Right() << std::endl;
		return 0;
	},
	[]()
	{
		auto r1 = GeometricRectangle(0, 0, 3, 4);
		auto r2 = r1.Offset(GeometricRectangle::PointType(-3, 6));
		std::cout << "r1 = GeometricRectangle(0, 0, 3, 4)" << std::endl;
		std::cout << "r2 = r1.Offset(GeometricRectangle::PointType(-3, 6))" << std::endl;
		std::cout << "8. r2.top ? " << r2.Top() << std::endl;
		return 0;
	},
	[]()
	{
		auto r1 = GeometricRectangle(0, 0, 3, 4);
		auto r2 = r1.Offset(GeometricRectangle::PointType(-3, 6));
		std::cout << "r1 = GeometricRectangle(0, 0, 3, 4)" << std::endl;
		std::cout << "r2 = r1.Offset(GeometricRectangle::PointType(-3, 6))" << std::endl;
		std::cout << "9. r2.bottom ? " << r2.Bottom() << std::endl;
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- Rectangle2D --->" << std::endl;
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
