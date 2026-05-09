#include <iostream>
#include "header/Activity.hpp"
#include "header/Book.hpp"
#include "header/FileManager.hpp"
#include "header/Library.hpp"
#include "header/User.hpp"

#include "Database/include/FileStorage.hpp"
#include "Database/include/MySqlStorage.hpp"

using namespace std;


int main()
{
     int storageChoice;
    cout << "Choose Storage:\n";
    cout << "1. File Storage\n";
    cout << "2. MySQL Storage\n";
    cout << "Enter choice: ";
    cin >> storageChoice;
    HelperDb* storage;

    if (storageChoice == 1)
        storage = new FileStorage();
    else
        storage = new MySQLStorage();

    Library lib(storage);
    storage->loadBooks(lib.getBooks());
    storage->loadUsers(lib.getUser());
    storage->loadActivities(lib.getActivities());
    //step 1 is to load the files 

    // files.LoadBooks(lib.getBooks());
    // files.LoadUsers(lib.getUser());
    // files.LoadActivities(lib.getActivities());

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
                lib.AddBook();
                storage->saveBooks(lib.getBooks());
                break;

            case 2:
                lib.AddUser();
                storage->saveUsers(lib.getUser());
                break;

            case 3:
                lib.UpdateBookDetails();
                storage->saveBooks(lib.getBooks());
                break;

            case 4:
                lib.DeleteBook();
                storage->saveBooks(lib.getBooks());
                break;

            case 5:
            {
                bool status = lib.checkAvailability();
                cout << (status ? "Book is available\n" : "Book not found\n");
                break;
            }

            case 6:
                lib.searchByTitle();
                break;

            case 7:
                lib.searchByCategory();
                break;

            case 8:
            {
                int bookid, userid;

                cout << "Enter Book ID: ";
                cin >> bookid;

                cout << "Enter User ID: ";
                cin >> userid;

                lib.IssueBook(bookid, userid);

                storage->saveBooks(lib.getBooks());
                storage->saveUsers(lib.getUser());
                storage->saveActivities(lib.getActivities());
                break;
            }

            case 9:
            {
                int bookid, userid;

                cout << "Enter Book ID: ";
                cin >> bookid;

                cout << "Enter User ID: ";
                cin >> userid;

                lib.returnBook(bookid, userid);

                storage->saveBooks(lib.getBooks());
                storage->saveUsers(lib.getUser());
                storage->saveActivities(lib.getActivities());
                break;
            }

            case 10:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    }

    delete storage;  // 🔥 cleanup
    return 0;

}

