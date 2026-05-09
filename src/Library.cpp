#include "../header/Library.hpp"

void Library :: AddBook()
{
    cout << "Enter the Details of Books : " <<endl;
    int id;
    string title,author,category;
    cout << "Enter Id : ";
    cin>>id;
    cout << "Enter Title of the Book : ";
    cin.ignore();   //clears the leftover input buffer done cause it should not read the newline
    getline(cin,title);
    cout << "Enter AuthorName of the Book : ";
    getline(cin,author);
    cout << "Enter Category of Book : ";
    getline(cin,category);

    Books.push_back(Book(id,title,author,category));
    cout << "Book Added Successfully!!"<<endl;
}

void Library :: UpdateBookDetails()
{
    cout << "Enter the Book details you want to update!!"<<endl;
    int id;
    cout << "Enter The Book Id you want to Update: ";
    cin>>id;
    for(auto &book : Books)
    {
        if(book.getBookId() == id)
        {
            book.UpdateBookDetails();
            cout << "Book Updated Successfully"<<endl;
            return;
        }
    }
    cout << "No Book Found for the id "<<endl;
}


void Library :: DeleteBook()
{
    int id;
    cout << "Enter the id of Book You want to delete"<<endl;
    cin>>id;
    for(int i = 0 ; i < Books.size() ; i++)
    {
        if(Books[i].getBookId() == id)
        {
            Books.erase(Books.begin() + i);
            cout << "Book Deleted Successfully"<<endl;
            return ;
        }

    }
    cout << "No Book Found for the id : "<<id;
}

void Library ::DisplayBookInfo()
{
     if (Books.empty())
    {
        cout << "No books available.\n";
        return;
    }

    for (auto &book : Books)
    {
        book.DisplayBookInfo();
        cout << "----------------------\n";
    }
}

void Library ::searchByTitle()
{
    cout <<"Enter the title of the book : ";
    string title;
    cin.ignore();
    getline(cin,title);
    for(auto &book : Books)
    {
        if(book.getTitle() == title)
        {
            cout <<"Book is Present in the Library!!"<<endl;
            book.DisplayBookInfo();
            return;
        }
    }
    cout << "No Book found for the title: "<<title<<endl;
}

void Library :: searchByCategory()
{
    cout << "Enter Category of the book : ";
    string category;
    cin.ignore();
    getline(cin,category);
    for(auto &book : Books)
    {
        if(book.getCategory() == category)
        {
            cout <<"Book is Present in the Library!!"<<endl;
            book.DisplayBookInfo();
            return;
        }
    }
    cout << "No Book found for the category: "<<category<<endl;
}

void Library ::AddUser()
{
    int id;
    cout << "Enter the id of the user : ";
    cin>>id;
    string name;
    cout << "Enter the Name of the user : ";
    cin.ignore();
    getline(cin,name);

    Users.push_back(User(id,name));
    cout << "User Added Successfully!!!"<<endl;
}

Book* Library :: findBookById(int id)
{
    for(auto &book : Books)
    {
        if(id == book.getBookId())
        {
            return &book;
        }
    }
    return nullptr;
}
User* Library :: findUserById(int id)
{
    for(auto &user : Users)
    {
        if(id == user.getUserId())
        {
            return &user;
        }
    }
    return nullptr;
}
string Library ::getCurrentDate()
{
    time_t date = time(NULL);
    string time = ctime(&date);
    time.pop_back();   //remove newline character 
    return time;
}
void Library :: IssueBook(int bookid,int userid)
{
    Book* book = findBookById(bookid);
    User* user = findUserById(userid);
    if(!book || !user)
    {
        cout << "Invalid User or Book !!"<<endl;
        return;
    }
    if(!book->getAvailability())
    {
        cout << "Sorry is Already Issued by someone !!"<<endl;
    }
    book->setAvailabilty(false);
    user->IssueBook(bookid);
    Activities.push_back(Activity(bookid,userid,getCurrentDate()));
    cout << "Book Issued Successfully!!"<<endl;

}

void Library ::returnBook(int bookid,int userid)
{
    Book* book = findBookById(bookid);
    User* user = findUserById(userid);
    if(!book || !user)
    {
        cout << "Invalid User or Book !!"<<endl;
        return;
    }
    
    if(!user->hasBook(bookid))
    {
        cout << "User Doesn't Have this Book !!"<<endl;
    }
    book->setAvailabilty(true);
    user->ReturnBook(bookid);

    for(auto &activity : Activities)
    {
        if(activity.getBookId() == bookid && !activity.getReturnStatus())
        {
            activity.markReturned(getCurrentDate());
            cout << "Book Returned SuccessFully"<<endl;
            return;
        }
    }

}


vector<Book>& Library ::getBooks()
{
    return this->Books;
}

vector<User>& Library::getUser()
{
    return this->Users;
}
vector<Activity>& Library::getActivities()
{
    return this->Activities;
}

bool Library :: checkAvailability()
{
    int id;
    cout << "Enter The Book id which You want to search : ";
    cin>>id;
    for(auto &book: Books)
    {
        if(book.getBookId() == id)
        {
            return book.getAvailability();   // if we return true then book exists if return this means book is available
        }
    }
    return false;
}