#include <iostream>
#include "../include/MySqlStorage.hpp"

MySQLStorage::MySQLStorage()
{
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, "localhost", "root", "iron", "library_db", 0, NULL, 0))
    {
        cout << "MySQL connection failed\n";
    }
    else
    {
        cout << "Connected to MySQL\n";
    }
}


MySQLStorage::~MySQLStorage()
{
    mysql_close(conn);
}
void MySQLStorage::loadBooks(vector<Book>& books) {
     mysql_query(conn, "SELECT * FROM books");

    MYSQL_RES* res = mysql_store_result(conn);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res)))
    {
        int id = stoi(row[0]);
        string title = row[1];
        string author = row[2];
        string category = row[3];
        bool avail = stoi(row[4]);

        Book b(id, title, author, category);
        b.setAvailabilty(avail);

        books.push_back(b);
    }

    mysql_free_result(res);
}

void MySQLStorage::saveBooks( vector<Book>& books) {
    for (auto &b : books)
    {
        string query = "INSERT INTO books VALUES (" +
                       to_string(b.getBookId()) + ", '" +
                       b.getTitle() + "', '" +
                       b.getAuthor() + "', '" +
                       b.getCategory() + "', " +
                       to_string(b.getAvailability()) + ")";

        if (mysql_query(conn, query.c_str()))
        {
            cout << "Insert failed: " << mysql_error(conn) << endl;
        }
        else
        {
            cout << "Inserted book ID: " << b.getBookId() << endl;
        }
    }
}

void MySQLStorage::loadUsers(vector<User>& users) {
    mysql_query(conn, "SELECT * FROM users");

    MYSQL_RES* res = mysql_store_result(conn);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res)))
    {
        int id = stoi(row[0]);
        string name = row[1];

        users.push_back(User(id, name));
    }

    mysql_free_result(res);
}

void MySQLStorage::saveUsers( vector<User>& users) {
     for (auto &u : users)
    {
        string query = "INSERT INTO users VALUES (" +
                       to_string(u.getUserId()) + ", '" +
                       u.getUserName() + "') "
                       "ON DUPLICATE KEY UPDATE "
                       "name=VALUES(name)";

        if (mysql_query(conn, query.c_str()))
        {
            cout << "User insert/update failed: " << mysql_error(conn) << endl;
        }
    }
}

void MySQLStorage::loadActivities(vector<Activity>& activities) {
     mysql_query(conn, "SELECT * FROM activities");

    MYSQL_RES* res = mysql_store_result(conn);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res)))
    {
        int bookId = stoi(row[0]);
        int userId = stoi(row[1]);
        string issueDate = row[2];
        string returnDate = row[3];
        bool returned = stoi(row[4]);

        Activity a(bookId, userId, issueDate);

        if (returned)
            a.markReturned(returnDate);

        activities.push_back(a);
    }

    mysql_free_result(res);
}

void MySQLStorage::saveActivities( vector<Activity>& activities) {
    for (auto &a : activities)
    {
        string query = "INSERT INTO activities VALUES (" +
                       to_string(a.getBookId()) + ", " +
                       to_string(a.getUserId()) + ", '" +
                       a.getIssueDate() + "', '" +
                       a.getReturnDate() + "', " +
                       to_string(a.getReturnStatus()) + ")";

        if (mysql_query(conn, query.c_str()))
        {
            cout << "Activity insert failed: " << mysql_error(conn) << endl;
        }
    }
}