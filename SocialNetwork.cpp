// SocialNetwork source file
#include "SocialNetwork.h"

#include <utility>

User::ID SocialNetwork::addUser(std::string name)
{
	User::ID genID = genRandomID();
	auto parsedName = std::tuple(parseName(name));

	std::shared_ptr<User> newUser = std::make_shared<User>(genID, std::get<1>(parsedName), std::get<0>(parsedName));
	users_[genID] = newUser;
	return newUser->id();
}

SocialNetwork& SocialNetwork::addFriendship(User::ID user1_ID, User::ID user2_ID)
{
	getUser(user1_ID).addFriend(getUser(user2_ID));
	getUser(user2_ID).addFriend(getUser(user1_ID));
	return  *this;
}

User& SocialNetwork::getUser(User::ID id)
{
	return *users_[id];
}

SocialNetwork::Iterator SocialNetwork::find(std::string name)
{
	std::vector<User *> sameName;
	for (auto u: users_)
	{
		if (u.second->getName().rfind(name) == 0)
			sameName.push_back(u.second.get());
	}
	Iterator same(sameName);
	return same;
}

SocialNetwork::Iterator SocialNetwork::begin()
{
	std::vector<User *> handoff;
	for (auto u : users_)
	{
		handoff.push_back(u.second.get());
	}

	Iterator users(handoff);
	return users;
}

SocialNetwork::Iterator SocialNetwork::end()
{
	std::vector<User *> handoff;
	for (auto u : users_)
	{
		handoff.push_back(u.second.get());
	}

	Iterator users(handoff);
	users.itr_ = users.vec_users.end();
	return users;
}


User& SocialNetwork::Iterator::operator*()
{
	return **itr_;
}

SocialNetwork::Iterator SocialNetwork::Iterator::operator++(int)
{
	itr_++;
	return *this;
}

bool SocialNetwork::Iterator::operator==(const SocialNetwork::Iterator& otherUser) const
{
	return (*itr_)->id() == (*(otherUser.itr_))->id();
}

bool SocialNetwork::Iterator::operator!=(const SocialNetwork::Iterator& otherUser) const
{
	return (*itr_)->id() != (*(otherUser.itr_))->id();
}

SocialNetwork::Iterator::Iterator(std::vector<User *> users)
	: vec_users(std::move(users)), itr_(vec_users.begin())
{}


std::tuple<std::string, std::string> SocialNetwork::parseName(std::string name)
{
	std::vector<std::string> nameTokens;
	std::stringstream str(name);
	std::string immediate;
	while (getline(str, immediate, ' '))
	{
		nameTokens.push_back(immediate);
	}
	return std::tuple<std::string, std::string>(nameTokens[0], nameTokens[1]);
}

User::ID SocialNetwork::genRandomID()
{
	std::uniform_int_distribution<User::ID> ID(100, 999);
	User::ID id = ID(generator);
	return id;
}

SocialNetwork::SocialNetwork()
{}

