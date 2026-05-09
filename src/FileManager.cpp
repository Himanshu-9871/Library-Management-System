#include "../header/FileManager.hpp"
//TODO Loading data from file and into files

//load to file

void FileManager::LoadBooks(vector<Book>&Books)
{
    ifstream file("Files/books.txt");

    if(!file.is_open())
    {
        cout << "Error in Book Opening File "<<endl;
    }
    string line;   //take input in this
    while(getline(file,line))
    {
        stringstream ss(line);
        string temp;
        int id;
        string title;
        string author;
        string category;
        int availability;
        //id
        getline(ss,temp,',');
        id = stoi(temp);
        //title
        getline(ss,title,',');

        //author 
        getline(ss,author,',');

        //category
        getline(ss,category,',');

        //availability
        getline(ss,temp);
        availability = stoi(temp);
        
        Book book(id,title,author,category);
        book.setAvailabilty(availability);
        Books.push_back(book);
    }
    file.close();    
}

void FileManager::LoadUsers(vector<User>&Users)
{
    ifstream file("Files/user.txt");
    if (!file.is_open())
    {
        cout << "Error opening users file.\n";
        return;
    }
    string line;
    while(getline(file,line))
    {
        stringstream ss(line);  // ss is an object of stringstream 
        int userid;
        string userName;
        string bookid_s;
        
        string temp;
        getline(ss,temp,',');
        userid = stoi(temp);
        
        getline(ss,userName,',');

        getline(ss,bookid_s);

        //[101 | 102 | 103] like that books we have 
        User user(userid,userName);
        stringstream bb(bookid_s);
        string bookid;
        while(getline(bb,bookid,'|'))
        {
            if(!bookid.empty())
            {
                user.IssueBook(stoi(bookid));
            }
        }
        Users.push_back(user);
    }
    file.close();
}


void FileManager::LoadActivities(vector<Activity>&Activities)
{
    ifstream file("Files/activity.txt");
    if (!file.is_open())
    {
        cout << "Error opening Activities file.\n";
        return;
    }
    string line;
    while(getline(file,line))
    {
        stringstream ss(line);
        int BookId;
        int UserId;
        string returnDate,issueDate;
        int isReturned;

        //book id
        string temp;
        getline(ss,temp,',');  
        if(!temp.empty())      
        BookId = stoi(temp);
        
        temp.clear();
        //user id
        getline(ss,temp,',');
        if(!temp.empty())
        UserId = stoi(temp);

        //issueDate
        getline(ss,issueDate,',');

        //returnDate
        
        getline(ss,returnDate,',');
        //if return date already existed
        //isReturned
        temp.clear();
        getline(ss,temp);
        if(!temp.empty())
        {
            isReturned = stoi(temp);
        }
        //cout << "ehlo";
        Activity activity(BookId,UserId,issueDate);

        if(!returnDate.empty() && isReturned == 1)
        {
            activity.markReturned(returnDate);
        }
        Activities.push_back(activity);
    }
    file.close();
}

//Save to file 

void FileManager :: saveActivities(vector<Activity>&Activities)
{
    ofstream file("Files/activity.txt");
    if(!file.is_open())
    {
        cout << "Error in Opening the file \n"<<endl;
    }
    for(auto &activity : Activities)
    {
        file << activity.getBookId() << ","
             << activity.getUserId() << ","
             << activity.getIssueDate() << ",";
             if(activity.getReturnStatus())
             {
                file << activity.getReturnDate()<<",";
             }
             else{
                file << "NULL,";
             }
             file << activity.getReturnStatus()<<"\n";
    }
    file.close();
}
void FileManager :: saveBooks(vector<Book>&Books)
{
    ofstream file("Files/books.txt");
    if(!file.is_open())
    {
        cout << "Error in Opening the file \n"<<endl;
    }
    for(auto &book : Books)
    {
        file << book.getBookId() << ","
             << book.getTitle() << ","
             << book.getAuthor() << ","
             << book.getCategory() << ","
             << book.getAvailability()<<endl;
    }
    file.close();
}
void FileManager :: saveUsers(vector<User>&Users)
{
    ofstream file("Files/user.txt");
    if(!file.is_open())
    {
        cout << "Error in Opening the file \n"<<endl;
    }
    for(auto &user : Users)
    {
        file << user.getUserId() << ","
            << user.getUserName() <<",";
            vector<int>temp = user.getIssuedBooks();
            for(int i = 0 ; i < temp.size() ; i++)
            {
                file << temp[i];
                if(i != temp.size() - 1)
                {
                    file << "|";
                }
            }
            file << "\n";
    }
    file.close();
}



