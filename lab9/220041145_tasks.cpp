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

};
class Book : public LibraryResource{
private:
    CoverType covertype;
public:
    Book(string t, string s, int z, CoverType c): LibraryResource(t, s, z), covertype(c) {}

};
class EBook : public LibraryResource{
private:
    double mb;
public:
    EBook(string t, string s, int z, double c): LibraryResource(t, s, z), mb(c) {}

};
class Audiobook : public LibraryResource{
private:
    int min;
public:
    Audiobook(string t, string s, int z, int c): LibraryResource(t, s, z), min(c) {}   
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
 
 }