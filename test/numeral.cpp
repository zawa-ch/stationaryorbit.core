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

void Test_Range();
void Test_Rectangle();
void Test_Rotation();
int Test_Vector2d();

void Test_Numeral()
{
	Test_Range();
	Test_Rectangle();
	Test_Rotation();
	Test_Vector2d();
}

void Test_Range()
{
	std::cout << "<--- Range --->" << std::endl;
	static_assert(IteratorTraits::IsIterator<Range<size_t>::IteratorType>, "Range<size_t>::IteratorTypeがIteratorTraits::IsIteratorの要件を満たしません。");
	static_assert(IteratorTraits::IsSequencialOrderIterator<Range<size_t>::IteratorType>, "Range<size_t>::IteratorTypeがIteratorTraits::IsIteratorの要件を満たしません。");
	static_assert(IteratorTraits::IsBidirectionalOrderIterator<Range<size_t>::IteratorType>, "Range<size_t>::IteratorTypeがIteratorTraits::IsBidirectionalOrderIteratorの要件を満たしません。");
	static_assert(Traits::IsSequencialOrderType<Range<size_t>::IteratorType>, "Range<size_t>::IteratorTypeがTraits::IsSequencialOrderの要件を満たしません。");
	static_assert(Traits::IsBidirectionalOrderType<Range<size_t>::IteratorType>, "Range<size_t>::IteratorTypeがTraits::IsBidirectionalOrderの要件を満たしません。");
	// 範囲forを用いて0..9の数値を列挙する
	for(auto i : Range(0, 10).GetStdIterator())
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	// 逆イテレータを使用して5..11の数値を逆に列挙する
	for(auto i : Range(5, 12).GetStdReverseIterator())
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	// 0.5fが0.0f以上1.0f未満であることを検査する
	static_assert(Range(0.0f, 1.0f).isIncluded(0.5f), "0.5fが0.0f以上1.0f未満ではありません。");
}

void Test_Rectangle()
{
	std::cout << "<--- Rectangle --->" << std::endl;
	auto r1 = GeometricRectangle(0, 0, 3, 4);
	std::cout << "r1.left = " << r1.Left() << std::endl;
	std::cout << "r1.right = " << r1.Right() << std::endl;
	std::cout << "r1.top = " << r1.Top() << std::endl;
	std::cout << "r1.bottom = " << r1.Bottom() << std::endl;
	if (!r1.Contains(GeometricRectangle::PointType(1, 1))) { throw std::exception(); }
	auto r2 = r1.Offset(GeometricRectangle::PointType(-3, 6));
	std::cout << "r2.left = " << r2.Left() << std::endl;
	std::cout << "r2.right = " << r2.Right() << std::endl;
	std::cout << "r2.top = " << r2.Top() << std::endl;
	std::cout << "r2.bottom = " << r2.Bottom() << std::endl;
}

void Test_Rotation()
{
	std::cout << "<--- Rotation --->" << std::endl;
	Rotation rot1 = Rotation(30, RotationUnit::Degree);
	Rotation rot2 = Rotation(0.5 * M_PI, RotationUnit::Radian);
	Rotation rot3 = Rotation(60, RotationUnit::Degree);

	std::cout << "rot1 = " << rot1.getRadian() << "rad" << std::endl;
	std::cout << "rot2 = " << rot2.getDegree() << "deg" << std::endl;
	std::cout << "rot1 + rot2 = " << (rot1 + rot2).getDegree() << "deg" << std::endl;
	std::cout << "rot1 - rot2 = " << (rot1 - rot2).getDegree() << "deg" << std::endl;
	std::cout << "rot2 * 2.0 = " << (rot2 * 2.0).getDegree() << "deg" << std::endl;
	std::cout << "rot1 / 2.0 = " << (rot1 * 2.0).getDegree() << "deg" << std::endl;
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
