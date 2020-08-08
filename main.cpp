#include <iostream>
#include "SocialNetwork.h"

std::tuple<std::string, std::string> parseName(std::string name);

int main()
{
	SocialNetwork SN;
	// SN.isGroupEmpty() ? std::cout<<"Table is empty!"<<std::endl : std::cout<<"Table is NOT empty"<<std::endl;
	// SN.addUser("Andrew Stone");
	// SN.isGroupEmpty() ? std::cout<<"Table is empty!"<<std::endl : std::cout<<"Table is NOT empty"<<std::endl;
	SN.addUser("andrew stone");
	// auto u = SN.find("andrew Stone");
	// std::cout << &u << std::endl;
	auto a = SN.begin();

	std::cout << "--END--"<< std::endl;
	return 0;
}




/*std::string myName = "Andrew Stone";
// std::tuple<std::string,std::string>(parseName(myName)) parsedName;
auto parsedName = std::tuple(parseName(myName));
std::cout << get<0>(parsedName) << " " << get<1>(parsedName) << std::endl;

std::cout << "--END--" << std::endl;*/

/*
std::tuple<std::string, std::string> parseName(std::string name)
{
	std::vector<std::string> nameTokens;
	std::stringstream str(name);
	std::string immediate;
	while (getline(str, immediate, ' '))
	{
		nameTokens.push_back(immediate);
	}
	return std::tuple<std::string, std::string>(nameTokens[0], nameTokens[1]);
}*/
