#pragma once

#include <vector>

std::stringstream * s1;
void input(int & i)
{
	*s1 << i << "_";
}

struct Sum
{
	Sum() : sum{ 0 } { }
	void operator()(int n) { sum += n; }
	int sum;
};

void testFoncteur(std::stringstream & s)
{
	std::vector<int> entiers;
	entiers.push_back(1);
	entiers.push_back(2);
	entiers.push_back(3);
	entiers.push_back(4);
	entiers.push_back(5);
	entiers.push_back(6);
	entiers.push_back(7);
	entiers.push_back(8);

	s << "impression avec boucle normale" << std::endl;
	for (std::vector<int>::iterator it = entiers.begin(); it != entiers.end(); ++it)
	{
		s << *it << "_";
	}
	s << std::endl << "impression avec for_each" << std::endl;
	s1 = &s;
	std::for_each(entiers.begin(), entiers.end(), input);
	s1 = NULL;

	std::vector<int> nums{ 3, 4, 2, 8, 15, 267 };

	s << "before:";
	for (auto const &n : nums)
	{
		s << ' ' << n;
	}
	s << '\n';

	std::for_each(nums.begin(), nums.end(), [](int &n) { n++; });

	// calls Sum::operator() for each number
	Sum s2 = std::for_each(nums.begin(), nums.end(), Sum());

	s << "after: ";
	for (auto const &n : nums)
	{
		s<< ' ' << n;
	}
	s<< '\n';
	s<< "sum: " << s2.sum << '\n';

}