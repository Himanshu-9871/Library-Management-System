#ifndef FILESTORAGE_HPP
#define FILESTORAGE_HPP

#include "HelperDb.hpp"
#include <fstream>
#include <sstream>

class FileStorage : public HelperDb
{
public:
    void loadBooks(vector<Book>& books) override;
    void saveBooks( vector<Book>& books) override;

    void loadUsers(vector<User>& users) override;
    void saveUsers(vector<User>& users) override;

    void loadActivities(vector<Activity>& activities) override;
    void saveActivities(vector<Activity>& activities) override;
};

#endif