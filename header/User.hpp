#ifndef USER_HPP
#define USER_HPP
#include<iostream>
#include<vector>

using namespace std;

class User
{
    private:
    int UserId;
    string UserName;
    vector<int>IssuedBooks;  //we can get book using id
    
    public:
    User();
    User(int id,string Name);
    void IssueBook(int BookId);
    void ReturnBook(int BookId);
    bool hasBook(int bookId);
    void UserINFO();
    //getters
    int getUserId();
    string getUserName();
    vector<int> getIssuedBooks();

};

#endif