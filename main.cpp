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
		std::cout << &u << std::endl;
	}

	std::cout << "--END--" << std::endl;
	return 0;
}





// auto id_a = SN.addUser("andrew");
// auto id_j = SN.addUser("jon");
// SN.addFriendship(id_a,id_j);
/*
- instantiate an empty SocialNetwork
- add Alice, Bob and Charlie
- add friendships between Alice and Bob, Alice and Charlie
- alice.begin() should yield Bob and Charlie
- bob.begin() should yield Alice
*/