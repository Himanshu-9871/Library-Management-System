#ifndef BOOK_HPP
#define BOOK_HPP
#include<iostream>
#include<vector>

using namespace std;

class Book
{
    private:
    int BookId;
    bool isAvailable;
    string BookTitle;
    string BookAuthor;
    string BookCategory;
    public:
    Book();
    Book(int id,string title,string author,string category);
    void DisplayBookInfo();
    void UpdateBookDetails();
    
    //getters
    int getBookId();
    bool getAvailability();
    string getTitle();
    string getAuthor();
    string getCategory();

    //setters
    void setBookId(int id);
    void setAvailabilty(bool available);
    void setBookTitle(string title);
    void setBookAuthor(string author);
    void setBookCategory(string category);


};

#endif