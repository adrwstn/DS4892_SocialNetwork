// User source file
#include "User.h"

using ID = size_t;

//! What is this user's ID?
ID User::id() const
{
	return this->id_;
}

//! How many friends does this user have?
size_t User::degree() const
{
	return myFriends_.size();
}

/* What is the shortest path to the given User from this one?
 * @returns   the number of friend links between this User and that
 *            one, or SIZE_MAX if there is no connection between them
 */
size_t User::distance(const User& findU) const
{
#define ever (;;)
	size_t distance = 0;
	std::set<User> users_allDegrees;
	std::set<User> users_currentDeg;
	users_currentDeg.insert(*this);

	for ever
	{
		size_t sizebefore = users_allDegrees.size();
		for (auto u : users_currentDeg)
		{
			if (u.id() == findU.id())
				return distance;
			else users_allDegrees.insert(u);
		}
		std::set<User> tmp = users_currentDeg;
		for (auto u : tmp)
		{
			for (auto f : u.myFriends_)
			{
				users_currentDeg.insert(f);
			}
			users_currentDeg.erase(u);
		}
		size_t sizeafter = users_allDegrees.size();
		if (sizebefore == sizeafter)
			return SIZE_MAX;
		distance++;
	}
}


User::FriendIterator User::begin() const
{
	std::vector<User *> handoff;
	for (auto u : myFriends_)
	{
		handoff.push_back(&u);
	}

	FriendIterator friends(handoff);
	return friends;
}

//! Make this User friends with another User.
void User::addFriend(const User& myfriend)
{
	myFriends_.emplace(myfriend);
}

/**
* Get an iterator that will iterate over this User's friends
* as well as **their** friends.
*
* The resulting iterator should iterate over all of this user's friends
* and friends of friends in no particular order. This user (i.e., the
* centre of the egonet) should not show up in the iteration, and no
* single user should be iterated over more than once.
*/
User::FriendIterator User::friendsOfFriends() const
{
	std::set<User> friendsoffriends;
	std::vector<User *> vec_friendsoffriends;

	for (auto f : myFriends_)
	{
		friendsoffriends.insert(f);

		for (auto fof : f.myFriends_)
		{
			if (fof.id() != id_)
				friendsoffriends.insert(fof);
		}
	}
	vec_friendsoffriends.reserve(friendsoffriends.size());
	for (auto fof : friendsoffriends)
	{
		vec_friendsoffriends.push_back(&fof);
	}
	FriendIterator fof(vec_friendsoffriends);
	return fof;
}

//! Get an iterator that signifies the end of any friend iteration.
User::FriendIterator User::end() const
{
	std::vector<User *> handoff;
	for (auto u : myFriends_)
	{
		handoff.push_back(&u);
	}

	FriendIterator friends(handoff);
	friends.friendItr_ = friends.friends_.end();
	return friends;
}

User::User(ID id, std::string& name)
	: id_(id), name_(name)
{}

std::string& User::getName()
{
	return name_;
}


// Struct FriendIterator methods

User& User::FriendIterator::operator*()
{
	return **friendItr_;
}

User::FriendIterator User::FriendIterator::operator++(int)
{
	friendItr_++;
	return *this;
}

bool User::FriendIterator::operator==(const User::FriendIterator& otherUser) const
{
	return friendItr_ == otherUser.friendItr_;
}

bool User::FriendIterator::operator!=(const User::FriendIterator& otherUser) const
{
	return friendItr_ != otherUser.friendItr_;
}

User::FriendIterator::FriendIterator(std::vector<User *> friends)
	: friends_(friends), friendItr_(friends_.begin())
{}
















