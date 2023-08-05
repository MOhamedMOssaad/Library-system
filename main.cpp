#include<cstring>
#include<iostream>
#include <User.h>
#include<Book.h>
#include <UserList.h>
#include <BookList.h>
#include <string>
#include <limits>
using namespace std;


int Book::Count =1;

int main()
{
    /*cout << "Let's add a user" << endl;
   cout << "Enter the user information in this order" << endl <<
   "Name Age Email Password (Space separated)" << endl;
   User obj1;
   cin >> obj1;
   cout << obj1;

   cout << "Let's add another user" << endl;
   cout << "Enter the user information in this order" <<endl <<
   "Name Age Email Password (Space separated)" << endl;
   User obj2;
   cin >> obj2;
   obj2.setId(2);
   cout << obj2;

    cout << "Let's add a book" << endl;
    cout << "Enter the book information in this order" << endl;
    cout << "Title ISBN Category(space separated)" << endl;
    Book obj3;
    cin >> obj3;
    cout << obj3;
    cout << "Let's add another book" << endl;
    cout << "Enter the book information in this order" << endl;
    cout << "Title ISBN Category(space separategooutLISTd)" << endl;
    Book obj4;
    cin >> obj4;
    cout << obj4;



    cout << "Let's assign an author for the first book, " <<
                  "set the first user as an author" << endl;


    obj3.setAuthor(obj1);
    cout << "Let's rate the first book with 3 and 4 ratings and print the book info" << endl;
    obj3.rateBook(3);
    obj3.rateBook(4);
    cout << obj3;
    cout << obj1;

    cout << "Let's add a new rating for b1 with 5 and print the book info" << endl;
    obj3.rateBook(5);
    cout << obj3;
    cout << obj1;*/

    // initial objects for use in the menu
    UserList userslist(3000);
    BookList bookslist(3000);

    bool capUserEx = false;
    bool capBookEx = false;

    while(true) {
        cout << "Select One of the following choices: " << endl;
        cout << "1- Books Menu" << endl;
        cout << "2- Users menu " << endl ;
        cout << "3- Exit" << endl ;
        int menuKey;
        cin>>menuKey;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to avoid bad input (chars in this case) infinity loop problem of cin

        bool goOut = false;
        switch(menuKey) {
            // ========   Books Menu    ===========
            case 1:
            {
                if (!capBookEx) {
                    cout << "How many books will be added?" << endl;
                    int cap;
                    cin >> cap;
                    bookslist.setCapacity(cap);
                    capBookEx = true;
                }
                bool goOutBook = false;
                while(!goOutBook) {
                    cout << "Books MENU" << endl;
                    cout << "1- Create a book and add it to the list  " << endl ;

                    cout << "2- Search for a book " << endl ;
                    cout << "3- Display all books (with book rating)  " << endl ;
                    cout << "4- Get the highest rating book" << endl ;
                    cout << "5- Get all the books of a user" << endl ;
                    cout << "6- Copy the current Book List to a new Book List and switch to it" << endl ;
                    cout << "7- Back to the main menu" << endl ;
                    int bookKey;
                    cin >> bookKey;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    switch(bookKey)
                    {
                        // option 1: add book
                        case 1:
                        {
                            bool finishAdding = false;
                            if (bookslist.getBooksCount() == bookslist.getCapacity())
                            {
                                cout << "Can't add another book, the book list is full" << endl;
                                finishAdding = true;
                            } else {
                                Book OBJ;
                                cin >> OBJ;
                                bookslist.addBook(OBJ);
                            }
                            int addAuthor;
                            while (!finishAdding)
                            {
                                cout << "1- Assign author" << endl;
                                cout << "2- Continue" << endl;
                                cin >> addAuthor;
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                if (addAuthor == 1)
                                {
                                    cout << "Enter author (user) id: " << endl;
                                    int idOfAuthor;
                                    cin >> idOfAuthor;
                                    if (userslist.isUserExiest(idOfAuthor)) {
                                        (bookslist.getBooks())[bookslist.getBooksCount()-1].setAuthor(userslist.searchUser(idOfAuthor));
                                        finishAdding = true;
                                    } else {
                                        cout << "No Author Found with id = " << idOfAuthor << endl;
                                    }
                                } else if (addAuthor == 2) {
                                    finishAdding = true;
                                }
                            }
                            break;
                        }
                        // option 2 :   search for a book
                        case 2:
                        {
                            string searchBookName;
                            int searchBookId;
                            bool goOutSearchBook = false;
                            bool goToMenu = false;
                            while (!goOutSearchBook)
                            {
                                cout << "SEARCH FOR A BOOK" << endl;
                                cout << "1- Search by name" << endl;
                                cout << "2- Search by id" << endl;
                                cout << "3- Return to Books Menu" << endl;
                                int bookSearchKey;
                                cin >> bookSearchKey;
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                if (bookSearchKey == 1)
                                {
                                    cout << "Enter name" << endl;
                                    cin >> searchBookName;
                                    if (!bookslist.isBookExiest(searchBookName))
                                    {
                                        cout << "No Book found with name: " << searchBookName << endl;
                                    } else
                                    {
                                        cout << bookslist.searchBook(searchBookName) << endl ;
                                        searchBookId = bookslist.searchBook(searchBookName).getId();
                                        goOutSearchBook = true;
                                    }
                                } else if (bookSearchKey == 2)
                                {
                                    cout << "Enter book id" << endl;
                                    cin >> searchBookId;
                                    if (!bookslist.isBookExiest(searchBookId))
                                    {
                                        cout << "No Book found with id: " << searchBookId << endl;
                                    } else
                                    {
                                        cout << bookslist.searchBook(searchBookId) << endl ;
                                        goOutSearchBook = true;
                                    }
                                } else if (bookSearchKey == 3)
                                {
                                    goOutSearchBook = true;
                                    goToMenu = true;
                                }
                            }

                            bool goOutEditBook = false;
                            while (!goToMenu && !goOutEditBook)
                            {
                                cout << "1- Update author" << endl;
                                cout << "2- Update name" << endl;
                                cout << "3- Update Category" << endl;
                                cout << "4- Delete Book" << endl;
                                cout << "5- Rate book" << endl;
                                cout << "6- Get back to books menu" << endl;
                                int editKey;
                                cin >> editKey;
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                switch (editKey)
                                {
                                    // option 1:  update author
                                    case 1:
                                    {
                                        cout << "Enter author (user) id: " << endl;
                                        int idOfAuthor;
                                        cin >> idOfAuthor;
                                        if (userslist.isUserExiest(idOfAuthor)) {
                                            bookslist.searchBook(searchBookId).setAuthor(userslist.searchUser(idOfAuthor));
                                        } else {
                                            cout << "No Author Found with id = " << idOfAuthor << endl;
                                        }
                                        break;
                                    }
                                    // option 2:  update name
                                    case 2:
                                    {
                                        cout << "Enter new Name: " << endl;
                                        string newTitle;
                                        cin >> newTitle;
                                        bookslist.searchBook(searchBookId).setTitle(newTitle);

                                        break;
                                    }
                                    // option 3 : update category
                                    case 3:
                                    {
                                        cout << "Enter new Category: " << endl;
                                        string newCategory;
                                        cin >> newCategory;
                                        bookslist.searchBook(searchBookId).setCategory(newCategory);

                                        break;
                                    }
                                    // option 4:   delete book
                                    case 4:
                                    {
                                        bookslist.deleteBook(searchBookId);
                                        goOutEditBook = true;
                                        goToMenu = true;

                                        break;
                                    }
                                    // option 5:   rate book
                                    case 5:
                                    {
                                        cout << "Enter Rating Value: " << endl;
                                        int newRate;
                                        cin >> newRate;
                                        bookslist.searchBook(searchBookId).rateBook(newRate);

                                        break;
                                    }
                                    // option 6:   go to menu
                                    case 6:
                                    {
                                        goOutEditBook = true;
                                        goToMenu = true;

                                        break;
                                    }
                                }
                            }

                            break;
                        }
                        // option 3 : display all the books
                        case 3:
                        {
                            cout << bookslist;
                            break;
                        }
                        // option 4 : get the highest rating book
                        case 4:
                        {
                            cout << bookslist.getTheHighestRatedBook() << endl ;

                            break;
                        }
                        // option 5 : get all the book of a given author
                        case 5:
                        {


                            break;
                        }
                        // option 6 : copy the current book list to a new one
                        case 6:
                        {

                            break;
                        }
                        // option 7 : back to the main menu
                        case 7:
                        {
                            goOutBook = true;

                            break;
                        }
                    }
                }
                break;
            }
            //   ============   User Menu     =======
            case 2:
            {
                if (!capUserEx) {
                     cout << "How many users will be added?" << endl;
                    int cap;
                    cin >> cap;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    userslist.setCapacity(cap);
                    capUserEx = true;
                }
                while(true) {
                    cout << "USERS MENU" << endl;
                    cout << "1- Create a USER and add it to the list  " << endl ;
                    cout << "2- Search for a user " << endl ;
                    cout << "3- Display all users  " << endl ;
                    cout << "4- Back to the main menu  " << endl ;
                    int userKey ;
                    cin >> userKey ;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    bool gooutLIST = false;
                    switch(userKey)
                     {
                          //  option 1 :   add user
                        case 1 :
                        {
                            if (userslist.getUsersCount() == userslist.getCapacity()) {
                                cout << "Can't add another user, the user list is full" << endl;
                            } else {
                                cout << "Enter the user information in this order" << endl <<
                                "Name Age Email Password (Space separated)" << endl;
                                User OBJ ;
                                cin >> OBJ ;
                                userslist.addUser(OBJ) ;
                            }
                            break ;
                        }
                        // option 2 :   search for a user
                        case 2 :
                        {
                            bool gooutListSearch = false;
                            while(true) {
                                cout << " SEARCH FOR A USER " << endl ;
                                cout << " 1- Search by name " << endl ;
                                cout << " 2- Search by Id " << endl ;
                                cout << " 3- Return to User menu " << endl ;
                                int listSearchKey;
                                cin >> listSearchKey;
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                switch(listSearchKey)
                                {
                                    case 1:
                                    {
                                        string nameSU;
                                        cout << "Enter Name" << endl;
                                        cin >> nameSU;
                                        cout << userslist.searchUser(nameSU) << endl ;
                                        cout << "1- Delete user" << endl;
                                        cout << "2- Return to Users Menu" << endl;
                                        int delUser;
                                        cin >> delUser;
                                        if (delUser == 1) {
                                            int delUserID = userslist.searchUser(nameSU).getId();
                                            userslist.deleteUser(delUserID);
                                        }
                                        else if (delUser == 2) {
                                            gooutListSearch = true;
                                        }

                                        break;
                                    }
                                    case 2:
                                        int idSU;
                                        cout << "Enter User id:" << endl;
                                        cin >> idSU;
                                        cout << userslist.searchUser(idSU) << endl ;
                                        cout << "1- Delete user" << endl;
                                        cout << "2- Return to Users Menu" << endl;
                                        int delUser;
                                        cin >> delUser;
                                        if (delUser == 1) {
                                            userslist.deleteUser(idSU);
                                        }
                                        else if (delUser == 2) {
                                            gooutListSearch = true;
                                        }

                                        break;
                                    case 3:
                                        gooutListSearch = true;
                                        break;
                                }
                                if (gooutListSearch) {
                                    break;
                                }
                            }
                            break;
                        }
                        case 3:
                            {
                            cout << userslist;

                            break;
                            }
                        case 4:
                            {
                            gooutLIST = true;
                            break;
                            }
                    }
                    if (gooutLIST){
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                goOut = true;
                break;
            }
        }
        if (goOut) {
            break;
        }

    }


    return 0;
}
