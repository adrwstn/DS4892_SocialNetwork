// SocialNetwork source file
#include "SocialNetwork.h"

User::ID SocialNetwork::addUser(std::string name)
{
	User::ID genID = genRandomID();
	auto parsedName = std::tuple(parseName(name));
	// User newUser = User(genID, get<1>(parsedName), get<0>(parsedName));
	std::unique_ptr<User> newUser = std::make_unique<User>(genID, get<1>(parsedName), get<0>(parsedName));
	// users_.emplace(std::make_pair(genID, std::move(newUser)));
	return newUser->id();
}

SocialNetwork& SocialNetwork::addFriendship(User::ID user1_ID, User::ID user2_ID)   //TODO! implement
{

}

User& SocialNetwork::getUser(User::ID id)
{
	auto found = users_.find(id);
	return found->second;
}

SocialNetwork::Iterator SocialNetwork::find(std::string name)
{
	auto findName = parseName(name);
	Iterator foundUsers(users_);
	for (auto user : foundUsers.networkCopy_)
	{
		if (user.second.getLastName() == std::get<0>(findName) && user.second.getFirstName() == std::get<1>(findName))
		{
			foundUsers.sameNames.emplace_back(user.first,user.second);
		}
	}
	return foundUsers;
}

SocialNetwork::Iterator SocialNetwork::begin()
{
	Iterator users(users_);
	return users;
}

SocialNetwork::Iterator SocialNetwork::end()
{
	Iterator users(users_);
	users.iter_ = std::make_pair(users.networkCopy_.end()->first, users.networkCopy_.end()->second);
	// users.itr_ = users.networkCopy_.end();//->first, users.networkCopy_.end()->second);
	return users;
}


SocialNetwork::Iterator::Iterator(std::unordered_map<User::ID, User> network)
	: networkCopy_(network),
		iter_(std::make_pair(networkCopy_.begin()->first, networkCopy_.begin()->second))
{}

User& SocialNetwork::Iterator::operator*()
{
	return this->iter_.second;
}

SocialNetwork::Iterator SocialNetwork::Iterator::operator++(int)
{
	auto previousUser = iter_;
	bool flag;
	for (auto users : networkCopy_)
	{
		previousUser = users;
		if (flag)
			break;

		if (previousUser.first == iter_.first)
			flag = true;
	}
	iter_ = previousUser;
	return *this;
}

bool SocialNetwork::Iterator::operator==(const SocialNetwork::Iterator& otherUser) const
{
	return this->iter_.first == otherUser.iter_.first;
}

bool SocialNetwork::Iterator::operator!=(const SocialNetwork::Iterator& otherUser) const
{
	return this->iter_.first != otherUser.iter_.first;
}

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
