#include "../header/Activity.hpp"

/*
int BookId;
    int UserId;
    bool isReturned;
    string issueDate;
    string returnDate;
*/

Activity :: Activity()
{
    this->BookId = -1;
    this->UserId = -1;
    this->isReturned = false;
    this->issueDate = "";
    this->returnDate = "";
}
Activity :: Activity(int bookId,int UserId, string issueDate)
{
    this->BookId = bookId;
    this->UserId = UserId;
    this->issueDate = issueDate;
    this->returnDate = "";
    this->isReturned = false;
}

int Activity ::getBookId()
{
    return this->BookId;
}
string Activity ::getIssueDate()
{
    return issueDate;
}

string Activity ::getReturnDate()
{
    return returnDate;
}
int Activity ::getUserId()
{
    return this->UserId;
}

bool Activity ::getReturnStatus()
{
    return isReturned;
}

void Activity :: displayActivity()
{
    cout << "User Id : "<<UserId<<endl;
    cout << "Book Id : "<<BookId<<endl;
    cout << "IssueDate : "<<this->issueDate<<endl;
    if(this->isReturned == true)
    {
        cout << "Return Date : "<<this->returnDate<<endl;
    }
    else{
        cout << "Return Date : Book Is Not Return By The User Yet!!"<<endl;
    }
    // cout << "Status: " << (isReturned ? "Returned" : "Issued") << endl;
    // cout << "--------------------------\n";
}


void Activity :: markReturned(string date)
{
    isReturned = true;
    this->returnDate = date;
}