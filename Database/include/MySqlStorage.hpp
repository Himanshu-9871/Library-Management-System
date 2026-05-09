#ifndef MYSQLSTORAGE_HPP
#define MYSQLSTORAGE_HPP

#include "HelperDb.hpp"
#include <mysql/mysql.h>

class MySQLStorage : public HelperDb
{
private:
    MYSQL* conn;

public:
    MySQLStorage();
    ~MySQLStorage();

    void loadBooks(vector<Book>& books) override;
    void saveBooks( vector<Book>& books) override;

    void loadUsers(vector<User>& users) override;
    void saveUsers( vector<User>& users) override;

    void loadActivities(vector<Activity>& activities) override;
    void saveActivities( vector<Activity>& activities) override;
};

#endif