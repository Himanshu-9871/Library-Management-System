#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP
#include<iostream>
#include<vector>
#include<ctime>
#include "Book.hpp"

using namespace std;

class Activity
{
    private:
    int BookId;
    int UserId;
    bool isReturned;
    string issueDate;
    string returnDate;
    //vector<Book*>IssuedBooks;
    
    public:
    Activity();
    //issue is happening at the time of creation of the activity 
    Activity(int bookId,int UserId, string issueDate);
    
    void markReturned(string date);
    // getters
    int getBookId(); 
    int getUserId();
    string getIssueDate();
    string getReturnDate();
    bool getReturnStatus();

    void displayActivity();

};

#endif