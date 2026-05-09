#include <iostream>
#include "header/Activity.hpp"
#include "header/Book.hpp"
#include "header/FileManager.hpp"
#include "header/Library.hpp"
#include "header/User.hpp"

using namespace std;


int main()
{
    FileManager files;
    Library lib;
    //step 1 is to load the files 

    files.LoadBooks(lib.getBooks());
    files.LoadUsers(lib.getUser());
    files.LoadActivities(lib.getActivities());

    int choice = 0;
    while(choice != 10)
    {
        cout <<"\n=====Library Management System=====\n";
        cout << "1. Add a Book\n";
        cout << "2. Add User\n";
        cout << "3. Update Book Details \n";
        cout << "4. Delete a Book From Library\n";
        cout << "5. Check Availability \n";
        cout << "6. Search Book by Title\n";
        cout << "7. Search Book by Category\n";
        cout << "8. Issue Book\n";
        cout << "9. Return Book\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                lib.AddBook();
                files.saveBooks(lib.getBooks());
                break;
            } 
            case 2:
            {
                lib.AddUser();
                files.saveUsers(lib.getUser());
                break;
            }
            case 3:
            {
                lib.UpdateBookDetails();
                files.saveBooks(lib.getBooks());
                break;
            }
            case 4:
            {
                lib.DeleteBook();
                files.saveBooks(lib.getBooks());
                break;
            }
            case 5:
            {
                bool status = lib.checkAvailability();
                if(status)
                {
                    cout << "Book Is present in the library :-) !!";
                    cout << endl;
                }
                else{
                    cout << "Sorry User Book is Not present :-("<<endl;
                }
                break;
            }
            case 6:
            {
                lib.searchByTitle();
                break;
            }
            case 7:
            {
                lib.searchByCategory();
                break;
            }
            case 8:
            {
                int bookid;
                int userid;
                cout << "Enter id of Book You want to issue: ";
                cin>>bookid;

                cout << "Enter the id of User : ";
                cin>> userid;
                lib.IssueBook(bookid,userid);
                files.saveBooks(lib.getBooks());
                files.saveUsers(lib.getUser());
                files.saveActivities(lib.getActivities());
                break;
            }
            case 9:
            {
                int bookid;
                int userid;
                cout << "Enter id of Book You want to Return : ";
                cin>>bookid;

                cout << "Enter the id of User : ";
                cin>> userid;
                lib.returnBook(bookid,userid);
                files.saveBooks(lib.getBooks());
                files.saveUsers(lib.getUser());
                files.saveActivities(lib.getActivities());
                break;

            }
            case 10:
            {
                cout << "Exiting from the library...!!"<<endl;
                break;
            }
            default : cout << "Enter a Valid Choice..!!"<<endl;
        }
    }
    return 0;
}

