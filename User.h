#ifndef USER_H_
#define USER_H_

#include <cstddef>      // for definition of size_t
#include <memory>       // std::unique_ptr
#include <string>
#include <set>
// #include <iterator>

/**
 * Representation of a social network user.
 */
class User
{
public:
	using ID = size_t;

	//! What is this user's ID?
	ID id() const;

	//! How many friends does this user have?
	size_t degree() const;

	/**
	 * What is the shortest path to the given User from this one?
	 *
	 * @returns   the number of friend links between this User and that
	 *            one, or SIZE_MAX if there is no connection between them
	 */
	size_t distance(const User&) const;

	//! Make this User friends with another User.
	void addFriend(const User& myfriend);

	//! An iterator that can iterate over all of a User's friends
	struct FriendIterator
	{
		User& operator*();

		FriendIterator operator++(int);

		bool operator==(const FriendIterator& otherUser) const;

		bool operator!=(const FriendIterator& otherUser) const;

		FriendIterator(std::set<User> friends);

		std::set<User> friends_;
		std::set<User>::iterator friendItr_;

	};

	//! Get an iterator that will iterate over this User's friends
	FriendIterator begin() const;

	/**
	 * Get an iterator that will iterate over this User's friends
	 * as well as **their** friends.
	 *
	 * The resulting iterator should iterate over all of this user's friends
	 * and friends of friends in no particular order. This user (i.e., the
	 * centre of the egonet) should not show up in the iteration, and no
	 * single user should be iterated over more than once.
	 */
	FriendIterator friendsOfFriends() const;

	//! Get an iterator that signifies the end of any friend iteration.
	FriendIterator end() const;


	std::string& getLastName();

	std::string& getFirstName();

	User(ID id, std::string& lastName, std::string& firstName);

	bool operator<(const User& rhs) const
	{
		return this->id() < rhs.id();
	}

private:
	ID id_;
	std::string lastName_;
	std::string firstName_;
	std::set<User> myFriends;

};

#endif
