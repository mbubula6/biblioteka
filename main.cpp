#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book(string t = "", string a = "", int y = 0) : title(t), author(a), year(y) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }

    void display() const {
        cout << "Tytuł: " << title << ", Autor: " << author << ", Rok: " << year << endl;
    }

};

class Library {
private:
    Book books[MAX_BOOKS];    
    int bookCount = 0;

public:
    void addBook(const Book& book) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount] = book;
            bookCount++;
            cout << "Książka została dodana." << endl;
        } else {
            cout << "Biblioteka jest pełna, nie można dodać więcej książek." << endl;
        }
    }

    void showBooks() const {
        if (bookCount == 0) {
            cout << "Biblioteka jest pusta!" << endl;
            return;
        }
        cout << "Lista książek w bibliotece:" << endl;
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
        }
    }

    void removeBook(const string& title) {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                for (int j = i; j < bookCount - 1; j++) {
                    books[j] = books[j + 1];
                }
                bookCount--;
                cout << "Książka \"" << title << "\" została usunięta z biblioteki." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Nie znaleziono książki o tytule \"" << title << "\"." << endl;
        }
    }

    void searchBookByTitle(const string& title) const {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                books[i].display();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Nie znaleziono książki o tytule \"" << title << "\"." << endl;
        }
    }
};

int main() {
    Library library;
    int choice;
    string title, author;
    int year;

    while (true) {
        cout << "\nWybierz opcję:\n";
        cout << "1. Dodaj książkę\n";
        cout << "2. Wyświetl książki\n";
        cout << "3. Usuń książkę\n";
        cout << "4. Szukaj książki po tytule\n";
        cout << "5. Zakończ\n";
        cout << "Twoja opcja: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Podaj tytuł książki: ";
                getline(cin, title);
                cout << "Podaj autora książki: ";
                getline(cin, author);
                cout << "Podaj rok wydania: ";
                cin >> year;
                cin.ignore();

                library.addBook(Book(title, author, year));
                break;

            case 2:
                library.showBooks();
                break;

            case 3:
                cout << "Podaj tytuł książki do usunięcia: ";
                getline(cin, title);
                library.removeBook(title);
                break;

            case 4:
                cout << "Podaj tytuł książki do wyszukania: ";
                getline(cin, title);
                library.searchBookByTitle(title);
                break;

            case 5:
                cout << "Zakończenie programu.\n";
                return 0;

            default:
                cout << "Nieprawidłowy wybór. Spróbuj ponownie.\n";
        }
    }

    return 0;
}