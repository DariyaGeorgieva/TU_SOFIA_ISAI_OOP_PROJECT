#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Item {
    private:
        int num; 
        double price; 
    public:
    //Constructor 
        Item (int num, double price){
            this -> num = num;
            this -> price = price; 
        }

    //Getters 
        int getNum(){
            return num; 
        }
        double getPrice(){
            return price; 
        }

    //Setters 
        void setNum (int num){
            this -> num = num;
        }
        void setPrice (double price){
            this -> price = price; 
        }

    //Print
        void printObject(){
            printf ("Item: num = %d, price = %f\n", num, price); 
        }

    //Destructor
         ~ Item() {
        cout << "Destroying Item object with num: " << num << ", price:" << price <<endl;
        }
}; 

class Book : public Item {
private:
    string title;
    string autor;
    int year;
public:
    // Constructor
    Book(int num, double price, string title, string autor, int year)
        : Item(num, price) 
    {
        this->title = title;
        this->autor = autor;
        this->year = year;
    }

    // Getters 
    string getTitle() {
        return title;
    }
    string getAutor() {
        return autor;
    }
    int getYear() {
        return year;
    }

    // Setters 
    void setTitle(string title) {
        this->title = title;
    }
    void setAutor(string autor) {
        this->autor = autor;
    }
    void setYear(int year) {  
        this->year = year;
    }

    // Print
    void printBook() {
        printf("Book: num = %d, price = %.2f, title = %s, autor = %s, year = %d\n", getNum(), getPrice(), title.c_str(), autor.c_str(), year);
    }

    // Destructor
    ~Book() {
        cout << "Destroying Book with title: " << title << ", autor: " << autor << ", year: " << year << endl;
    }
}; 

int main(){
    int n;
    double vatRate = 0.20; // 20% VAT

    cout << "Enter the number of books (<= 50): ";
    cin >> n;

    if (n > 50 || n <= 0) {
        cout << "Invalid number of books. Exiting..." << endl;
        return 1;
    }

    vector<Book> books;

    // Input data for each book
    for (int i = 0; i < n; i++) {
        int num, year;
        double price;
        string title, autor;

        cout << "\nEnter details for book " << (i + 1) << ":" << endl;
        cout << "ID: ";
        cin >> num;
        cout << "Price: ";
        cin >> price;
        cin.ignore(); // Ignore leftover newline
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, autor);
        cout << "Year: ";
        cin >> year;

        books.emplace_back(num, price, title, autor, year);
    }

    // Print information for all books
    cout << "\nAll Book Information:\n";
    for (int i = 0; i < n; i++) {
        books[i].printBook();
    }

    // Calculate and print the order total including VAT
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += books[i].getPrice();
    }
    double totalWithVAT = total * (1 + vatRate);
    printf("\nOrder Total (Including VAT): %.2f\n", totalWithVAT);

    // Print information for all books by a given author published after 2020
    string searchAutor;
    cout << "\nEnter author name to search for books published after 2020: ";
    cin.ignore(); // Ignore leftover newline
    getline(cin, searchAutor);

    cout << "\nBooks by " << searchAutor << " published after 2020:\n";
    for (int i = 0; i < n; i++) {
        if (books[i].getAutor() == searchAutor && books[i].getYear() > 2020) {
            books[i].printBook();
        }
    }
    return 0; 
}
