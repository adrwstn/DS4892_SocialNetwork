// User source file
#include "User.h"

using ID = size_t;

//! What is this user's ID?
ID User::id() const
{
	return id_;
}

//! How many friends does this user have?
size_t User::degree() const
{
	return myFriends.size();
}

/**
 * What is the shortest path to the given User from this one?
 * @returns   the number of friend links between this User and that
 *            one, or SIZE_MAX if there is no connection between them
 */
size_t User::distance(const User&) const    //TODO! implement
{
	// return 0;
}


User::FriendIterator User::begin() const    //TODO! implement
{
	// return User::FriendIterator();
}

//! Make this User friends with another User.
void User::addFriend(const User& myfriend)  //TODO! implement
{
	// myFriends.emplace_back(id);
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
User::FriendIterator User::friendsOfFriends() const //TODO! implement
{
	// return User::FriendIterator();
}

//! Get an iterator that signifies the end of any friend iteration.
User::FriendIterator User::end() const  //TODO! implement
{
	// return User::FriendIterator();
}

std::string& User::getLastName()
{
	return lastName_;
}

std::string& User::getFirstName()
{
	return firstName_;
}


User::User(ID id, std::string& lastName, std::string& firstName)
	: id_(id), lastName_(lastName), firstName_(firstName)
{}


// Struct FriendIterator methods

User& User::FriendIterator::operator*()
{

	// return this->friendItr_;
}

User::FriendIterator User::FriendIterator::operator++(int)
{
	this->friendItr_ = this->friendItr_++;
	return *this;
}

bool User::FriendIterator::operator==(const User::FriendIterator& otherUser) const
{
	return this->friendItr_ == otherUser.friendItr_;
}

bool User::FriendIterator::operator!=(const User::FriendIterator& otherUser) const
{
	return this->friendItr_ != otherUser.friendItr_;
}

User::FriendIterator::FriendIterator(std::set<User> friends)
	: friends_(friends), friendItr_(friends_.begin())
{}















