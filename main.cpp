#include <iostream>
#include "SocialNetwork.h"

int main()
{
	SocialNetwork SN;
	SN.addUser("andrew");
	SN.addUser("jon");

	for (auto u = SN.begin(); u != SN.end(); u++)
	{
		std::cout << (*u).getName() << std::endl;
	}

	for (auto i : SN)
	{
		std::cout << i.id() << std::endl;
	}

	std::cout << "--END--" << std::endl;
	return 0;
}