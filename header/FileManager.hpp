#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Book.hpp"
#include "User.hpp"
#include "Activity.hpp"

using namespace std;

class FileManager
{
    public : 
    //Loading from files to vectors
    void LoadBooks(vector<Book>&Books);
    void LoadUsers(vector<User>&Users);
    void LoadActivities(vector<Activity>&Activities);
    
    //saving into files from vectors
    void saveBooks(vector<Book>& Books);
    void saveUsers(vector<User>& Users);
    void saveActivities(vector<Activity> &Activity);
    
};

#endif

