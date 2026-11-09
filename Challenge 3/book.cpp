
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Book
{
private:
    string title, author, id;
    int pages;
    bool borrowed;

public:
    // Constructor
    Book(string t, string a, int p, string i, bool b)
        : title(t), author(a), pages(p), id(i), borrowed(b) {}

    // Getters
    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getPages() { return pages; }
    string getID() { return id; }
    bool getBorrowed() { return borrowed; }

    // Update borrowing status
    bool changeStatus(bool status)
    {
        if (borrowed == status)
            return false;

        borrowed = status;
        return true;
    }

    // Display book details
    void display()
    {
        cout 
        << "\n" << title << " - " << author
        << "\nPages: " << pages
        << "\nID: " << id
        << "\nStatus: " << (borrowed ? "Borrowed" : "Available")
        << "\n";
    }
};

// Read books from file
void loadBooks(vector<Book>& books)
{
    ifstream file("bookData.txt");
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string title, author, pages, id, status;

        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, pages, ',');
        getline(ss, id, ',');
        getline(ss, status);

        books.emplace_back(title, author, stoi(pages),
        id, status == "true");
    }

    file.close();
}

// Save updated books
void saveBooks(vector<Book>& books)
{
    ofstream file("bookData.txt");

    for (Book& book : books)
    {
        file
             << book.getTitle() << ","
             << book.getAuthor() << ","
             << book.getPages() << ","
             << book.getID() << ","
             << (book.getBorrowed() ? "true" : "false") << "\n";
    }

    file.close();
}

// Find book by ID
int findBook(vector<Book>& books, string id)
{
    for (int i = 0; i < books.size(); i++)
        if (books[i].getID() == id)
            return i;

    return -1;
}

int main()
{
    vector<Book> books;
    loadBooks(books);

    int choice;
    string id;

    do
    {
        cout 
            << "\n BOOK MANAGER \n"
            << "1. View all books\n"
            << "2. View individual book\n"
            << "3. Borrow a book\n"
            << "4. Return a book\n"
            << "0. Exit\n"
            << "Choice: ";3
        cin >> choice;

        if (choice >= 2 && choice <= 4)
        {
            cout << "Enter book ID: ";
            cin >> id;

            int index = findBook(books, id);

            if (index == -1)
            {
                cout << "Book not found.\n";
                continue;
            }

            if (choice == 2)
                books[index].display();

            else if (books[index].changeStatus(choice == 3))
            {
                saveBooks(books);
                cout << "Book status updated.\n";
            }
            else
                cout << "Book status has not changed.\n";
        }
        else if (choice == 1)
        {
            for (Book& book : books)
                book.display();
        }
        else if (choice != 0)
            cout << "Invalid option.\n";

    } while (choice != 0);

    saveBooks(books);
    cout << "Goodbye!\n";

    return 0;
}
