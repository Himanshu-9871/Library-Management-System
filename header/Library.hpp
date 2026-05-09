#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include<iostream>
#include<vector>
#include <ctime>
#include <bits/stdc++.h>
#include "Book.hpp"
#include "User.hpp"
#include "Activity.hpp"
#include "../Database/include/HelperDb.hpp"
#include <string>
using namespace std;
//Hello user name

class Library
{
    private:
    vector<Book>Books;
    vector<User>Users;
    vector<Activity>Activities;
    HelperDb *storage;
    public:
    Library(HelperDb* store);
    Library();

    void AddBook();
    void UpdateBookDetails();
    void DeleteBook();
    bool checkAvailability();
    
    void DisplayBookInfo();
    
    void searchByTitle();
    void searchByCategory();

    void AddUser();
    //Helper Functions
    Book* findBookById(int id);
    User* findUserById(int id);
    string getCurrentDate();

    void IssueBook(int bookid,int userid);
    void returnBook(int bookid,int userId);

    //getter 
    vector<Book>& getBooks();
    vector<User>& getUser();
    vector<Activity>& getActivities();
    
};

#endif