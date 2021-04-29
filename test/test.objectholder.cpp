//	stationaryorbit.core.test.objectholder:/test.objectholder.cpp
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
#include "stationaryorbit/core.utilities.hpp"
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

struct NoCopyData
{
	int a;
	NoCopyData(const NoCopyData&) = delete;
	NoCopyData(NoCopyData&&) = default;
	NoCopyData& operator=(const NoCopyData&) = delete;
	NoCopyData& operator=(NoCopyData&&) = default;
};
template class zawa_ch::StationaryOrbit::ObjectHolder<int>;
template class zawa_ch::StationaryOrbit::ObjectHolder<NoCopyData>;

std::array<std::function<int(void)>, 46> tests =
{
	[]()
	{
		std::cout << "v1 = int(15)" << std::endl;
		int v1 = 15;
		std::cout << "r1 = v1" << std::endl;
		auto r1 = ObjectHolder(v1);
		std::cout << "1. r1.has_value ->true ?";
		return check_if(r1.has_value());
	},
	[]()
	{
		std::cout << "v1 = int(15)" << std::endl;
		int v1 = 15;
		std::cout << "r1 = v1" << std::endl;
		auto r1 = ObjectHolder(v1);
		std::cout << "2. r1.is_owner ->false ?";
		return check_if(!r1.is_owner());
	},
	[]()
	{
		std::cout << "v1 = int(15)" << std::endl;
		int v1 = 15;
		std::cout << "r1 = v1" << std::endl;
		auto r1 = ObjectHolder(v1);
		std::cout << "3. r1.value ? ";
		std::cout << r1.value() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "v1 = int(15)" << std::endl;
		int v1 = 15;
		std::cout << "r1 = v1" << std::endl;
		auto r1 = ObjectHolder(v1);
		std::cout << "*r1 = 28" << std::endl;
		*r1 = 28;
		std::cout << "4. v1 ? ";
		std::cout << v1 << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "v1 = int(15)" << std::endl;
		int v1 = 15;
		std::cout << "r1 = std::as_const(v1)" << std::endl;
		auto r1 = ObjectHolder<int>(std::as_const(v1));
		std::cout << "5. r1.has_value ->true ?";
		return check_if(r1.has_value());
	},
	[]()
	{
		std::cout << "v1 = int(15)" << std::endl;
		int v1 = 15;
		std::cout << "r1 = std::as_const(v1)" << std::endl;
		auto r1 = ObjectHolder<int>(std::as_const(v1));
		std::cout << "6. r1.is_owner ->true ?";
		return check_if(r1.is_owner());
	},
	[]()
	{
		std::cout << "v1 = int(15)" << std::endl;
		int v1 = 15;
		std::cout << "r1 = std::as_const(v1)" << std::endl;
		auto r1 = ObjectHolder<int>(std::as_const(v1));
		std::cout << "7. r1.value ? ";
		std::cout << r1.value() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "v1 = int(15)" << std::endl;
		int v1 = 15;
		std::cout << "r1 = std::as_const(v1)" << std::endl;
		auto r1 = ObjectHolder<int>(std::as_const(v1));
		std::cout << "*r1 = 28" << std::endl;
		*r1 = 28;
		std::cout << "8. v1 ? ";
		std::cout << v1 << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(15)" << std::endl;
		auto r1 = ObjectHolder(15);
		std::cout << "9. r1.has_value ->true ?";
		return check_if(r1.has_value());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(15)" << std::endl;
		auto r1 = ObjectHolder(15);
		std::cout << "10. r1.is_owner ->true ?";
		return check_if(r1.is_owner());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(15)" << std::endl;
		auto r1 = ObjectHolder(15);
		std::cout << "11. r1.value ? ";
		std::cout << r1.value() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(15)" << std::endl;
		auto r1 = ObjectHolder(15);
		std::cout << "r2 = ObjectHolder(r1)" << std::endl;
		auto r2 = ObjectHolder(r1);
		std::cout << "12. r2.has_value ->true ?";
		return check_if(r2.has_value());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(15)" << std::endl;
		auto r1 = ObjectHolder(15);
		std::cout << "r2 = ObjectHolder(r1)" << std::endl;
		auto r2 = ObjectHolder(r1);
		std::cout << "13. r2.is_owner ->true ?";
		return check_if(r2.is_owner());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(15)" << std::endl;
		auto r1 = ObjectHolder(15);
		std::cout << "r2 = ObjectHolder(r1)" << std::endl;
		auto r2 = ObjectHolder(r1);
		std::cout << "14. r2.value ? ";
		std::cout << r2.value() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(15)" << std::endl;
		auto r1 = ObjectHolder(15);
		std::cout << "r2 = ObjectHolder(r1)" << std::endl;
		auto r2 = ObjectHolder(r1);
		std::cout << "*r2 = 28" << std::endl;
		*r2 = 28;
		std::cout << "15. *r1 ? ";
		std::cout << *r1 << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder<int>()" << std::endl;
		auto r1 = ObjectHolder<int>();
		std::cout << "16. r1.has_value ->false ?";
		return check_if(!r1.has_value());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder<int>()" << std::endl;
		auto r1 = ObjectHolder<int>();
		std::cout << "17. r1.is_owner ->false ?";
		return check_if(!r1.is_owner());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder<int>()" << std::endl;
		auto r1 = ObjectHolder<int>();
		std::cout << "18. r1.value ? ";
		try
		{
			std::cout << r1.value() << std::endl;
		}
		catch(NullReferenceException e)
		{
			std::cout << "...NG (exception handled)" << std::endl;
			return 1;
		}
		return 0;
	},
	[]()
	{
		std::cout << "v1 = NoCopyData{15}" << std::endl;
		NoCopyData v1 = { 15 };
		std::cout << "r1 = v1" << std::endl;
		auto r1 = ObjectHolder(v1);
		std::cout << "19. r1.has_value ->true ?";
		return check_if(r1.has_value());
	},
	[]()
	{
		std::cout << "v1 = NoCopyData{15}" << std::endl;
		NoCopyData v1 = { 15 };
		std::cout << "r1 = v1" << std::endl;
		auto r1 = ObjectHolder(v1);
		std::cout << "20. r1.is_owner ->false ?";
		return check_if(!r1.is_owner());
	},
	[]()
	{
		std::cout << "v1 = NoCopyData{15}" << std::endl;
		NoCopyData v1 = { 15 };
		std::cout << "r1 = v1" << std::endl;
		auto r1 = ObjectHolder(v1);
		std::cout << "21. r1->a ? ";
		std::cout << r1->a << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "v1 = NoCopyData{15}" << std::endl;
		NoCopyData v1 = { 15 };
		std::cout << "r1 = v1" << std::endl;
		auto r1 = ObjectHolder(v1);
		std::cout << "r1->a = 28" << std::endl;
		r1->a = 28;
		std::cout << "22. v1.a ? ";
		std::cout << v1.a << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(NoCopyData{15})" << std::endl;
		auto r1 = ObjectHolder(NoCopyData{15});
		std::cout << "23. r1.has_value ->true ?";
		return check_if(r1.has_value());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(NoCopyData{15})" << std::endl;
		auto r1 = ObjectHolder(NoCopyData{15});
		std::cout << "24. r1.is_owner ->true ?";
		return check_if(r1.is_owner());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(NoCopyData{15})" << std::endl;
		auto r1 = ObjectHolder(NoCopyData{15});
		std::cout << "25. r1->a ? ";
		std::cout << r1->a << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder<NoCopyData>()" << std::endl;
		auto r1 = ObjectHolder<NoCopyData>();
		std::cout << "26. r1.has_value ->false ?";
		return check_if(!r1.has_value());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder<NoCopyData>()" << std::endl;
		auto r1 = ObjectHolder<NoCopyData>();
		std::cout << "27. r1.is_owner ->false ?";
		return check_if(!r1.is_owner());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder<NoCopyData>()" << std::endl;
		auto r1 = ObjectHolder<NoCopyData>();
		std::cout << "28. r1.value ? ";
		try
		{
			std::cout << r1->a << std::endl;
		}
		catch(NullReferenceException e)
		{
			std::cout << "...NG (exception handled)" << std::endl;
			return 1;
		}
		return 0;
	},
	[]()
	{
		std::cout << "v1 = int(15)" << std::endl;
		int v1 = 15;
		std::cout << "r1 = v1" << std::endl;
		auto r1 = ObjectHolder(v1);
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "29. r1.has_value ->false ?";
		return check_if(!r1.has_value());
	},
	[]()
	{
		std::cout << "v1 = int(15)" << std::endl;
		int v1 = 15;
		std::cout << "r1 = v1" << std::endl;
		auto r1 = ObjectHolder(v1);
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "30. r1.value ? ";
		try
		{
			std::cout << r1.value() << std::endl;
		}
		catch(NullReferenceException e)
		{
			std::cout << "...NG (exception handled)" << std::endl;
			return 1;
		}
		return 0;
	},
	[]()
	{
		std::cout << "v1 = int(15)" << std::endl;
		int v1 = 15;
		std::cout << "r1 = std::as_const(v1)" << std::endl;
		auto r1 = ObjectHolder<int>(std::as_const(v1));
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "31. r1.has_value ->false ?";
		return check_if(!r1.has_value());
	},
	[]()
	{
		std::cout << "v1 = int(15)" << std::endl;
		int v1 = 15;
		std::cout << "r1 = std::as_const(v1)" << std::endl;
		auto r1 = ObjectHolder<int>(std::as_const(v1));
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "32. r1.value ? ";
		try
		{
			std::cout << r1.value() << std::endl;
		}
		catch(NullReferenceException e)
		{
			std::cout << "...NG (exception handled)" << std::endl;
			return 1;
		}
		return 0;
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(15)" << std::endl;
		auto r1 = ObjectHolder(15);
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "33. r1.has_value ->false ?";
		return check_if(!r1.has_value());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(15)" << std::endl;
		auto r1 = ObjectHolder(15);
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "34. r1.value ? ";
		try
		{
			std::cout << r1.value() << std::endl;
		}
		catch(NullReferenceException e)
		{
			std::cout << "...NG (exception handled)" << std::endl;
			return 1;
		}
		return 0;
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(15)" << std::endl;
		auto r1 = ObjectHolder(15);
		std::cout << "r2 = ObjectHolder(r1)" << std::endl;
		auto r2 = ObjectHolder(r1);
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "35. r2.has_value ->true ?";
		return check_if(r2.has_value());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(15)" << std::endl;
		auto r1 = ObjectHolder(15);
		std::cout << "r2 = ObjectHolder(r1)" << std::endl;
		auto r2 = ObjectHolder(r1);
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "36. r2.value ? ";
		std::cout << r2.value() << std::endl;
		return 0;
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder<int>()" << std::endl;
		auto r1 = ObjectHolder<int>();
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "37. r1.has_value ->false ?";
		return check_if(!r1.has_value());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder<int>()" << std::endl;
		auto r1 = ObjectHolder<int>();
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "38. r1.value ? ";
		try
		{
			std::cout << r1.value() << std::endl;
		}
		catch(NullReferenceException e)
		{
			std::cout << "...NG (exception handled)" << std::endl;
			return 1;
		}
		return 0;
	},
	[]()
	{
		std::cout << "v1 = NoCopyData{15}" << std::endl;
		NoCopyData v1 = { 15 };
		std::cout << "r1 = v1" << std::endl;
		auto r1 = ObjectHolder(v1);
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "39. r1.has_value ->false ?";
		return check_if(!r1.has_value());
	},
	[]()
	{
		std::cout << "v1 = NoCopyData{15}" << std::endl;
		NoCopyData v1 = { 15 };
		std::cout << "r1 = v1" << std::endl;
		auto r1 = ObjectHolder(v1);
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "40. r1->a ? ";
		try
		{
			std::cout << r1->a << std::endl;
		}
		catch(NullReferenceException e)
		{
			std::cout << "...NG (exception handled)" << std::endl;
			return 1;
		}
		return 0;
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(NoCopyData{15})" << std::endl;
		auto r1 = ObjectHolder(NoCopyData{15});
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "41. r1.has_value ->false ?";
		return check_if(!r1.has_value());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder(NoCopyData{15})" << std::endl;
		auto r1 = ObjectHolder(NoCopyData{15});
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "42. r1->a ? ";
		try
		{
			std::cout << r1->a << std::endl;
		}
		catch(NullReferenceException e)
		{
			std::cout << "...NG (exception handled)" << std::endl;
			return 1;
		}
		return 0;
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder<NoCopyData>()" << std::endl;
		auto r1 = ObjectHolder<NoCopyData>();
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "43. r1.has_value ->false ?";
		return check_if(!r1.has_value());
	},
	[]()
	{
		std::cout << "r1 = ObjectHolder<NoCopyData>()" << std::endl;
		auto r1 = ObjectHolder<NoCopyData>();
		std::cout << "r1.clear()" << std::endl;
		r1.clear();
		std::cout << "44. r1->a ? ";
		try
		{
			std::cout << r1->a << std::endl;
		}
		catch(NullReferenceException e)
		{
			std::cout << "...NG (exception handled)" << std::endl;
			return 1;
		}
		return 0;
	},
};

int main(int argc, char const *argv[])
{
	std::cout << "<--- ObjectHolder --->" << std::endl;
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
