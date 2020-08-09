#include <iostream>
#include "SocialNetwork.h"

std::tuple<std::string, std::string> parseName(std::string name);

int main()
{
	SocialNetwork SN;
	// SN.isGroupEmpty() ? std::cout<<"Table is empty!"<<std::endl : std::cout<<"Table is NOT empty"<<std::endl;
	// SN.addUser("Andrew Stone");
	SN.addUser("andrew");
	// SN.addUser("john");
	// SN.addUser("tim");

	// auto u = SN.find("andrew Stone");
	//
	// auto a = SN.begin();
	// auto b = SN.end();
	// auto c = SN.find("andrew stone");
	for (auto u=SN.begin();u != SN.end(); u++)
	{
		std::cout<<&u<<std::endl;
	}



	std::cout << "--END--" << std::endl;
	return 0;
}