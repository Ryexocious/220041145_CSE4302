#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;

public:
    Book(string t, string a, string i) : title(t), author(a), ISBN(i) {}
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << endl;
    }
};
class library{
private:
    vector<Book>inventory;
    deque<Book>borrowedBooks;
    list<Book>archivedBooks;
public:
    void addbook(){
        string title,aurthor,isbn;
        cin.ignore();
        cout<<"Enter the title\n";
        getline(cin,title);
        cout<<"Enter the name of the aurthor\n";
        getline(cin,aurthor);
        cout<<"Enter the isbn\n";
        cin>>isbn;
        Book b(title,aurthor,isbn);
        inventory.push_back(b);
    }
    void borrowbook(string isbn){
        for (auto it=inventory.begin();it!=inventory.end();it++){
            if(it->getISBN()==isbn){
                borrowedBooks.push_back(*it);
                inventory.erase(it);
                return;
            }
        }
        cout<<"book not found\n";
    }
    void returnBook(string isbn){
        for(auto it=borrowedBooks.begin();it!=borrowedBooks.end();it++){
            if (it->getISBN() == isbn) {
                inventory.push_back(*it);
                borrowedBooks.erase(it);
                return;
            }
        }
        cout<<"book not found" <<"\n";
    }
    void archieveBook(string isbn){
        for(auto it=inventory.begin();it!=inventory.end();it++){
            if (it->getISBN() == isbn) {
                archivedBooks.push_back(*it);
                inventory.erase(it);
                return;
            }
        }
        cout<<"book not found\n";
    }
    void displayallBooks(){
        cout<<"Inventory: \n";
        for(auto it : inventory){
            it.display();
        }
        cout<<"borrowedbooks: \n";
        for(auto it : borrowedBooks){
            it.display();
        }
        cout<<"archieved: \n";
        for(auto it : archivedBooks){
            it.display();
        }
    }
    void saveDat(){
        ofstream ifile("inventory.txt"), bfile("borrowed.txt"), arfile("archived.txt");
        if (ifile.is_open() && bfile.is_open() && arfile.is_open()) {
            for (auto it : inventory) {
                ifile << it.getTitle()+","+it.getAuthor()+","+it.getISBN()<<"\n";
            }
            for (auto it : borrowedBooks) {
                bfile << it.getTitle()+","+it.getAuthor()+","+it.getISBN()<<"\n";
            }
            for (auto it : archivedBooks) {
                arfile << it.getTitle()+","+it.getAuthor()+","+it.getISBN()<<"\n";
            }
            cout << "Data saved" <<"\n";
        }
        else {
            cout << "Error opening files for saving!" <<"\n";
        }
    }
    void loadDat() {
        ifstream ifile("inventory.txt"), bfile("borrowed.txt"), arfile("archived.txt");
        string line;
        if (ifile.is_open()) {
            while (getline(ifile, line)) {
                stringstream ss(line);
                string title, author, isbn;
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, isbn, ',');
                inventory.push_back(Book(title, author, isbn));
            }
        }

        if (bfile.is_open()) {
            while (getline(bfile, line)) {
                stringstream ss(line);
                string title, author, isbn;
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, isbn, ',');
                borrowedBooks.push_back(Book(title, author, isbn));
            }
        }

        if (arfile.is_open()) {
            while (getline(arfile, line)) {
                stringstream ss(line);
                string title, author, isbn;
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, isbn, ',');
                archivedBooks.push_back(Book(title, author, isbn));
            }
        }
        cout << "Data loaded" << endl;
    }
};
int main(){
    library l;
    int n;
    cout<<"welcome to library\n";
    cout << "1. Add Book\n2. Borrow Book\n3. Return Book\n4. Archive Book\n5. Display Books\n6. Save Data\n7. Load Data\n8. Exit\n";
    cout<<"Enter your choice \n";
    while(cin>>n && n!=8){
        if(n==1){
            l.addbook();
        }
        if(n==2){
            string isbn;
            cout<<"Enter the isbn number\n";
            cin>>isbn;
            l.borrowbook(isbn);
        }
        if(n==3){
            string isbn;
            cout<<"Enter the isbn number\n";
            cin>>isbn;
            l.returnBook(isbn);
        }
        if(n==4){
            string isbn;
            cout<<"Enter the isbn number\n";
            cin>>isbn;
            l.archieveBook(isbn);
        }
        if(n==5){
            l.displayallBooks();
        }
        if(n==6){
            l.saveDat();
        }
        if(n==7){
            l.loadDat();
        }
        cout << "1. Add Book\n2. Borrow Book\n3. Return Book\n4. Archive Book\n5. Display Books\n6. Save Data\n7. Load Data\n8. Exit\n";
        cout<<"Enter your choice \n";
    }
}
