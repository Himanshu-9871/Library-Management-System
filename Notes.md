# FileManager
As we Need persistent storage so for that we use a file manager 
which will do the following tasks: 

1. SaveData To files
2. LoadData from files

**Save means** -> loading data from vectors to file, and 

**Load means** -> loading data from files to vectors.

books.txt → vector**Book**

users.txt → vector**User**

activities.txt → vector**Activity**

Only does read write Operations 

whyy pass by reference is done in filemanager

So FileManager directly fills your Library vectors


# FileHandling

So Now We have to Manage the file's

while we load files we need to read from the file
to read from the file we use **ifstream Library**

ifstream file("../Files/books.txt");  ==> Creates file as Object

getline(**cin or any another source where you wnt to read**,**into what you want to read**)


