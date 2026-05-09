#include "../header/Book.hpp"

Book :: Book()
{
    this->BookId = -1;
    this->BookAuthor = "";
    this->BookCategory = "";
    this->BookTitle = "";
    this->isAvailable = false;
}

//Book Added to the Library
Book :: Book(int id,string title,string author,string category)
{
    this->BookId = id;
    this->BookTitle = title;
    this->BookAuthor = author;
    this->BookCategory = category;
    this->isAvailable = true;
}


void Book ::DisplayBookInfo()
{
    cout << "ID: " << BookId << endl;
    cout << "Title: " << BookTitle << endl;
    cout << "Author: " << BookAuthor << endl;
    cout << "Category: " << BookCategory << endl;
    cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;
}

//Getters

int Book :: getBookId()
{
    return this->BookId;
}
bool Book ::getAvailability()
{
    return this->isAvailable;
}
string Book::getTitle()
{
    return this->BookTitle;
}

string Book::getAuthor()
{
    return this->BookAuthor;
}

string Book::getCategory()
{
    return this->BookCategory;
}


//setters

void Book::setBookId(int id)
{
    BookId = id;
}

void Book::setAvailabilty(bool status)
{
    isAvailable = status;
}

void Book::setBookTitle(string title)
{
    BookTitle = title;
}

void Book::setBookAuthor(string author)
{
    BookAuthor = author;
}

void Book::setBookCategory(string category)
{
    BookCategory = category;
}



void Book ::UpdateBookDetails()
{
    cout << "Which Specific Detail You wanted to Update: "<<endl;
    cout << "\n=========Enter Choice========\n";
    cout << "1. Update Title of the Book \n";
    cout << "2. Update Author of the Book \n";
    cout << "3. Update Category of the Book \n";
    cout << "4. Exit \n";
    int choice;
    cin>>choice;
    while(true)
    {
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter New Title: ";
                cin>>this->BookTitle;
                cout <<endl;
            }
            case 2:
            {
                cout<<"Enter New Author: ";
                cin>>this->BookAuthor;
                cout << endl;
            }
            case 3:
            {
                cout << "Enter New Category: ";
                cout << this->BookCategory;
                cout<<endl;
            }
            case 4:
            {
                break;
            }
            default:cout <<"Invalid Choice Please Choose from among choices....."<<endl;
        }
    }
    
}