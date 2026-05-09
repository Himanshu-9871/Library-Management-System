#ifndef HELPERDB_HPP
#define HELPERDB_HPP

#include <vector>
#include "../../header/Book.hpp"
#include "../../header/User.hpp"
#include "../../header/Activity.hpp"

using namespace std;

class HelperDb
{
public:
    virtual void loadBooks(vector<Book>& books) = 0;
    virtual void saveBooks(vector<Book>& books) = 0;

    virtual void loadUsers(vector<User>& users) = 0;
    virtual void saveUsers( vector<User>& users) = 0;

    virtual void loadActivities(vector<Activity>& activities) = 0;
    virtual void saveActivities(vector<Activity>& activities) = 0;

    virtual ~HelperDb() {}
};

#endif