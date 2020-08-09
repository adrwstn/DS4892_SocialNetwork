#include <iostream>
#include "SocialNetwork.h"

int main()
{
	SocialNetwork SN;

	SN.addUser("andrew");

	for (auto u = SN.begin(); u != SN.end(); u++)
	{
		std::cout << &u << std::endl;
	}

	std::cout << "--END--" << std::endl;
	return 0;
}