#include <iostream>
#include <string>
using namespace std;

#define MAX_ITEMS 50


class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }

    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }

 
    LibraryItem(string t, string a, string d) {
        title = t;
        author = a;
        dueDate = d;
    }

  
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};


class Book : public LibraryItem {
private:
    string ISBN;

public:
    Book(string t, string a, string d, string isbn)
        : LibraryItem(t, a, d) {
        if (isbn.length() != 13)
            throw invalid_argument("Invalid ISBN! Must be 13 digits.");
        ISBN = isbn;
    }

    void checkOut() override {
        cout << "Book Checked Out: " << getTitle() << endl;
    }

    void returnItem() override {
        cout << "Book Returned: " << getTitle() << endl;
    }

    void displayDetails() override {
        cout << "\n--- Book Details ---" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "ISBN: " << ISBN << endl;
    }
};


class DVD : public LibraryItem {
private:
    int duration; 

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d) {
        if (dur <= 0)
            throw invalid_argument("Duration cannot be negative or zero!");
        duration = dur;
    }

    void checkOut() override {
        cout << "DVD Checked Out: " << getTitle() << endl;
    }

    void returnItem() override {
        cout << "DVD Returned: " << getTitle() << endl;
    }

    void displayDetails() override {
        cout << "\n--- DVD Details ---" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Director: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Duration: " << duration << " minutes" << endl;
    }
};


class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d) {
        if (issue <= 0)
            throw invalid_argument("Issue Number must be positive!");
        issueNumber = issue;
    }

    void checkOut() override {
        cout << "Magazine Checked Out: " << getTitle() << endl;
    }

    void returnItem() override {
        cout << "Magazine Returned: " << getTitle() << endl;
    }

    void displayDetails() override {
        cout << "\n--- Magazine Details ---" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Publisher: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Issue: " << issueNumber << endl;
    }
};


int main() {
    LibraryItem* libraryItems[MAX_ITEMS];
    int count = 0, choice;

    do {
        cout << "\n===== Library Management System =====" << endl;
        cout << "1. Add Book\n2. Add DVD\n3. Add Magazine\n4. Display All Items\n5. Check Out Item\n6. Return Item\n7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1: {
                string title, author, dueDate, isbn;
                cout << "Enter Book Title: ";
                cin >> title;
                cout << "Enter Author: ";
                cin >> author;
                cout << "Enter Due Date: ";
                cin >> dueDate;
                cout << "Enter ISBN (13 digits): ";
                cin >> isbn;

                libraryItems[count++] = new Book(title, author, dueDate, isbn);
                cout << "Book Added Successfully!" << endl;
                break;
            }

            case 2: {
                string title, author, dueDate;
                int duration;
                cout << "Enter DVD Title: ";
                cin >> title;
                cout << "Enter Director: ";
                cin >> author;
                cout << "Enter Due Date: ";
                cin >> dueDate;
                cout << "Enter Duration (minutes): ";
                cin >> duration;

                libraryItems[count++] = new DVD(title, author, dueDate, duration);
                cout << "DVD Added Successfully!" << endl;
                break;
            }

            case 3: {
                string title, author, dueDate;
                int issue;
                cout << "Enter Magazine Title: ";
                cin >> title;
                cout << "Enter Publisher: ";
                cin >> author;
                cout << "Enter Due Date: ";
                cin >> dueDate;
                cout << "Enter Issue Number: ";
                cin >> issue;

                libraryItems[count++] = new Magazine(title, author, dueDate, issue);
                cout << "Magazine Added Successfully!" << endl;
                break;
            }

            case 4:
                for (int i = 0; i < count; i++)
                    libraryItems[i]->displayDetails();
                break;

            case 5: {
                int id;
                cout << "Enter Index To Check Out: ";
                cin >> id;
                libraryItems[id]->checkOut();
                break;
            }

            case 6: {
                int id;
                cout << "Enter Index To Return: ";
                cin >> id;
                libraryItems[id]->returnItem();
                break;
            }

            case 7:
                cout << "Exiting... Releasing Memory..." << endl;
                for (int i = 0; i < count; i++)
                    delete libraryItems[i];
                break;

            default:
                cout << "Invalid Choice!" << endl;
            }
        }
        catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (choice != 7);

    return 0;
}