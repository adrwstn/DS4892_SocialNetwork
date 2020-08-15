#ifndef SOCIAL_NETWORK_H_
#define SOCIAL_NETWORK_H_

#include "User.h"
// #include <sstream>
#include <vector>
#include <ctime>
#include <random>
#include <unordered_map>
#include <map>

/* A (rather crude!) representation of a social network.*/
class SocialNetwork
{
public:
	//! Add a new user to the social network.
	User::ID addUser(std::string name);

	/* Add a (bidirectional/undirected) friendship link between two users.
	 * @pre the named users actually exist in the social network
	 */
	SocialNetwork& addFriendship(User::ID user1_ID, User::ID user2_ID);

	//! Retrieve a reference to a specific user.
	User& getUser(User::ID);

	//! An iterator over users in the social network
	struct Iterator
	{
		User& operator*();

		Iterator operator++(int);
		Iterator operator++();

		bool operator==(const Iterator& otherUser) const;

		bool operator!=(const Iterator& otherUser) const;

		std::vector<User> vec_users;
		std::vector<User>::iterator itr_;

		Iterator(std::vector<User> users);
	};

	//! Get an iterator over all users in the network.
	Iterator begin();

	//! Get an iterator that signifies the end of any user iteration.
	Iterator end();

	//! Find all users in the network whose names start with `name`.
	Iterator find(std::string name);


	SocialNetwork();
private:
	std::unordered_map<User::ID, User> users_;
	// std::map<User::ID, User> users_;

	/*Random number generator to create 3-digit ID between 100-999*/
	std::mt19937 generator;

	User::ID genRandomID();
};

#endif
