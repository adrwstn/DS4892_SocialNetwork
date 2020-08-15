// SocialNetwork source file
#include "SocialNetwork.h"

// #include <utility>


User::ID SocialNetwork::addUser(std::string name)
{
	User::ID genID = genRandomID();
	User newUser(genID, name);
	users_.insert({genID, newUser});
	return newUser.id();
}

SocialNetwork& SocialNetwork::addFriendship(User::ID user1_ID, User::ID user2_ID)
{
	getUser(user1_ID).addFriend(getUser(user2_ID));
	getUser(user2_ID).addFriend(getUser(user1_ID));
	return *this;
}

User& SocialNetwork::getUser(User::ID id)
{
	// return users_[id];
	return users_.at(id);
}

SocialNetwork::Iterator SocialNetwork::find(std::string name)
{
	std::vector<User> sameName;
	for (auto u: users_)
	{
		if (u.second.getName().rfind(name) == 0 || name.empty())
			sameName.push_back(u.second);
	}
	Iterator same(sameName);
	return same;
}

SocialNetwork::Iterator SocialNetwork::begin()
{
	std::vector<User> handoff;
	for (auto u : users_)
	{
		handoff.push_back(u.second);
		// handoff.emplace_back(u.second);
	}

	Iterator users(handoff);
	users.itr_ = users.vec_users.begin();
	return users;
}

SocialNetwork::Iterator SocialNetwork::end()
{
	std::vector<User> handoff;
	for (auto u : users_)
	{
		handoff.push_back(u.second);
		// handoff.emplace_back(u.second);
	}

	Iterator users(handoff);
	users.itr_ = users.vec_users.end();
	return users;
}


User& SocialNetwork::Iterator::operator*()
{
	return *itr_;
}

SocialNetwork::Iterator SocialNetwork::Iterator::operator++(int)
{
	// this->itr_ =std::next(itr_);
	// std::next(itr_);

	// itr_++;
	// return *this;

	if (itr_ == vec_users.end())
		return *this;
	itr_++;
	return *this;
}

SocialNetwork::Iterator SocialNetwork::Iterator::operator++()
{
	if (itr_ == vec_users.end())
		return *this;
	++itr_;
	return *this;

}

bool SocialNetwork::Iterator::operator==(const SocialNetwork::Iterator& otherUser) const
{
	//(*itr_)->id() == (*(otherUser.itr_))->id();
	// return !(*this != otherUser);
	return itr_->id() == otherUser.itr_->id();
}

bool SocialNetwork::Iterator::operator!=(const SocialNetwork::Iterator& otherUser) const
{
	// return (*itr_)->id() != ((*(otherUser.itr_))->id());
	// return &itr_ != &otherUser.itr_;

	if (itr_ == vec_users.end() && otherUser.itr_ == otherUser.vec_users.end())
	{
		return false;
	}
	if (itr_ == vec_users.end() || otherUser.itr_ == otherUser.vec_users.end())
	{
		return true;
	}
	return itr_->id() != otherUser.itr_->id();
}

SocialNetwork::Iterator::Iterator(std::vector<User> users)
	: vec_users(users), itr_(vec_users.begin())
{}


User::ID SocialNetwork::genRandomID()
{
	std::uniform_int_distribution<User::ID> ID(100, 999);
	User::ID id = ID(generator);
	return id;
}

SocialNetwork::SocialNetwork()
{}
// : users_(std::unordered_map<User::ID, User>().empty())

