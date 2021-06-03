//	stationaryorbit.core.test:/numeral
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
#include <stdexcept>
#include "stationaryorbit/core.traits.hpp"
#include "stationaryorbit/core.numeral.hpp"
using namespace zawa_ch::StationaryOrbit;

int Test_Vector2d();

void Test_Numeral()
{
	Test_Vector2d();
}

int Test_Vector2d()
{
	std::cout << "<--- Vector2d --->" << std::endl;
	Vector2d vec1 = Vector2d(3, 4);
	Vector2d vec2 = Vector2d(10, Rotation(-30, RotationUnit::Degree));

	std::cout << "vec1 = (" << vec1.getMagnitude() << "∠" << vec1.getRotation().getDegree() << "deg)" << std::endl;
	std::cout << "vec2 = (" << vec2.getX() << ", " << vec2.getY() << ")" << std::endl;
	std::cout << "vec1 + vec2 = (" << (vec1 + vec2).getX() << ", " << (vec1 + vec2).getY() << ")" << std::endl;
	std::cout << "vec1 - vec2 = (" << (vec1 - vec2).getX() << ", " << (vec1 - vec2).getY() << ")" << std::endl;
	std::cout << "vec1 ・ vec2 = " << vec1.DotProduct(vec2) << std::endl;

	if (vec1 < vec2)
	{
		std::cout << "vec1 < vec2" << std::endl;
	}
	else
	{
		return -1;
	}

	return 0;
}
