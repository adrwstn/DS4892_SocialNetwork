#ifndef SOCIAL_NETWORK_H_
#define SOCIAL_NETWORK_H_

#include "User.h"
#include <sstream>
#include <vector>
#include <ctime>
#include <random>
#include <unordered_map>

/* A (rather crude!) representation of a social network.*/
class SocialNetwork
{
public:
	//! Add a new user to the social network.
	User::ID addUser(std::string name); // key will be generated from name

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

		bool operator==(const Iterator& otherUser) const;

		bool operator!=(const Iterator& otherUser) const;

		std::vector<User*> vec_users;
		std::vector<User*>::iterator itr_;

		Iterator(std::vector<User*> users);

	};

	//! Get an iterator over all users in the network.
	Iterator begin();

	//! Find all users in the network whose names start with `name`.
	Iterator find(std::string name);

	//! Get an iterator that signifies the end of any user iteration.
	Iterator end();

	std::tuple<std::string, std::string> parseName(std::string name);

	SocialNetwork();
private:
	std::unordered_map<User::ID, std::shared_ptr<User>> users_;

	/*Random number generator to create 3-digit ID between 100-999*/
	std::mt19937 generator;

	User::ID genRandomID();
};

#endif
