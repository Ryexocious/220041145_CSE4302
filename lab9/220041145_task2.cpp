#include<iostream>
using namespace std;
enum class CoverType { Hardcover, Paperback };
// task1
class LibraryResource{
private:
    string title;
    string author;
    int price;
public:
    LibraryResource(string t,string s,int z) : title(t),author(s),price(z){}
    ~LibraryResource(){}
    virtual void resourceDetails() = 0;
    string gettil(){
        return title;
    }
    string getaurt(){
        return author;
    }
    int getprice(){
        return price;
    }

};
class Book : public LibraryResource{
private:
    CoverType covertype;
public:
    Book(string t, string s, int z, CoverType c): LibraryResource(t, s, z), covertype(c) {}
    //task2
    void resourceDetails() override {
        cout << "Book Title: " << LibraryResource::gettil() << "\n Author: " << LibraryResource::getaurt()
             << "\n Price: " << LibraryResource::getprice() 
             << "\n Cover Type: " << (covertype == CoverType::Hardcover ? "Hardcover" : "Paperback") << "\n";
    }

};
class EBook : public LibraryResource{
private:
    double mb;
public:
    EBook(string t, string s, int z, double c): LibraryResource(t, s, z), mb(c) {}

    void resourceDetails() override {
        cout << "Book Title: " << LibraryResource::gettil() << "\n Author: " << LibraryResource::getaurt()
             << "\n Price: " << LibraryResource::getprice() 
             << "\n Filesize " << mb << "\n";
    }
};
class Audiobook : public LibraryResource{
private:
    int min;
public:
    Audiobook(string t, string s, int z, int c): LibraryResource(t, s, z), min(c) {}

    void resourceDetails() override {
        cout << "Book Title: " << LibraryResource::gettil() << "\n Author: " << LibraryResource::getaurt()
             << "\n Price: " << LibraryResource::getprice() 
             << "\n Duration " << min << "\n";
    }    
};
int main() {
 LibraryResource* resource_list[100];
 /** TASK 1:
 So that the following lines execute without errors
 */
 resource_list[0] = new Book("The Alchemist", "Paulo Coelho",
 500,
 CoverType::Hardcover);
 resource_list[1] = new EBook("1984", "George Orwell", 300,
 2.5);
 resource_list[2] = new Audiobook("Becoming", "Michelle Obama",
 700, 120);
 /** TASK 2: Display details */
 for (int i = 0; i < 3; i++) {
    resource_list[i]->resourceDetails();
 }
}