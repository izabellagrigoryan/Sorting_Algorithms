// Counting_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.h"
#include <map>

int main()
{
	Array<int> m_array(25);
	m_array.print_array();
	std::cout << std::endl;

	std::map<int, int> m_map;
	int num = 0;

	auto it = m_map.begin();
	for (int i = 0; i < m_array.getsize(); i++)
	{
		num = m_array[i];
		it = m_map.find(num);

		if (it != m_map.end())
		{
			int count = m_map[{num}];
			m_map[{num}] = ++count;
		}
		else
		{
			m_map.insert(std::make_pair(num, int(1)));
		}
	}
	
	for (auto it : m_map)
	{
		for (int j = 0; j < it.second; j++)
		{
			std::cout << it.first << ",  ";
		}
	}

	std::cout << std::endl;

	return 0;
}