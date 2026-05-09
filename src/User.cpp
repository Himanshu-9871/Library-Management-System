#include "../header/User.hpp"

User :: User()
{
    this->UserId = -1;
    this->UserName = "";
}
User :: User(int id,string Name)
{
    this->UserId = id;
    this->UserName = Name;
}

void User :: IssueBook(int bookId)
{
    this->IssuedBooks.push_back(bookId);
}
void User ::ReturnBook(int bookId)
{
    for(int i = 0 ; i < IssuedBooks.size() ; i++)
    {
        if(bookId == IssuedBooks[i])
        {
            IssuedBooks.erase(IssuedBooks.begin()+i);
        }
    }
}

//if use erase then all elements shifts to the left to fill the gap 


bool User ::hasBook(int bookId)
{
    for(int i = 0 ; i < IssuedBooks.size() ; i++)
    {
        if(IssuedBooks[i] == bookId)
        {
            return true;
        }
    }
    return false;
}


void User :: UserINFO()
{
    cout << "User Id is : " <<this->UserId << endl;
    cout << "User Name is : " <<this->UserName <<endl;
    cout << "User Have Issued These Books : "<<endl;
    for(int i : IssuedBooks)
    {
        cout << "BookId : "<<this->UserId;
    }

}


//Getters

int User :: getUserId()
{
    return this->UserId;
}

string User :: getUserName()
{
    return this->UserName;
}
vector<int> User ::getIssuedBooks()
{
    return this->IssuedBooks;
}
