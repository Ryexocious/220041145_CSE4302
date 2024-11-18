#include<iostream>
using namespace std;
enum class CoverType { Hardcover, Paperback };
// task1
class LibraryResource{
private:
    string title;
    string author;
    int price;
    int isbn=1;
public:
    LibraryResource(string t,string s,int z) : title(t),author(s),price(z){}
    ~LibraryResource(){}
    void set_no_of_copies(int s){
        isbn=s;
    }
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
    int getnumcopy(){
        return isbn;
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
             cout<<"No of copies: "<<LibraryResource::getnumcopy()<<'\n';
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
             cout<<"No of copies: "<<LibraryResource::getnumcopy()<<'\n';
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
             cout<<"No of copies: "<<LibraryResource::getnumcopy()<<'\n';
    }    
};
int main() {
    LibraryResource *resource_list[100];
    /** TASK 1:
    So that the following lines execute without errors
    */
    resource_list[0] = new Book("The Alchemist", "Paulo Coelho", 500, CoverType::Hardcover);
    resource_list[1] = new EBook("1984", "George Orwell", 300, 2.5);
    resource_list[2] = new Audiobook("Becoming", "Michelle Obama", 700, 120);
    /** TASK 2: Display details */
    for (int i = 0; i < 3; i++)
    {
        resource_list[i]->resourceDetails();
    }
    /** TASK 3: Setting ISBN for Book */
    resource_list[0]->set_no_of_copies(50);
    resource_list[1]->set_no_of_copies(5);
    resource_list[2]->set_no_of_copies(1);
    for (int i = 0; i < 3; i++)
    {
        resource_list[i]->resourceDetails();
    }
}