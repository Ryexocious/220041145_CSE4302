#include<iostream>
#include<algorithm>
using namespace std;
enum class CoverType { Hardcover, Paperback };
// task1
class LibraryResource{
private:
    string title;
    string author;
    int price;
    int isbn=1;
    double discount;
public:
    LibraryResource(string t,string s,int z,int x) : title(t),author(s),price(z),discount(x){}
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
    Book(string t, string s, int z,int x=0, CoverType c): LibraryResource(t, s, z,x), covertype(c) {}
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
void sort_resources_price(LibraryResource* resource_list[], int n) {
    sort(resource_list, resource_list + n, [](LibraryResource* a, LibraryResource* b) {
        return a->getprice() < b->getprice();
    });
}
int main() {
 LibraryResource* resource_list[100];
 /** TASK 1:
 So that the following lines execute without errors
 */
 resource_list[0] = new Book("The Alchemist", "Paulo Coelho",500,CoverType::Hardcover);
 resource_list[1] = new EBook("1984", "George Orwell", 300,2.5);
 resource_list[2] = new Audiobook("Becoming", "Michelle Obama",700, 120);
 /** TASK 2: Display details */
 for (int i = 0; i < 3; i++) {
 resource_list[i]->resourceDetails();
 }
 /** TASK 3: Setting ISBN for Book */
 resource_list[0]->set_no_of_copies(50);
 resource_list[1]->set_no_of_copies(5);
 resource_list[2]->set_no_of_copies(1);
 for (int i = 0; i < 3; i++) {
 resource_list[i]->resourceDetails();
 }
 /** TASK 4: Sorting resources by price
 Created 7 more objects.*/
 resource_list[3] = new Book("Sapiens", "Yuval Noah Harari",
 1000, CoverType::Paperback);
 resource_list[4] = new EBook("Digital Minimalism", "Cal Newport", 400, 3.2);
 resource_list[5] = new Audiobook("Atomic Habits", "James Clear", 1200, 180);
 resource_list[6] = new Book("Dune", "Frank Herbert", 800,CoverType::Hardcover);
 resource_list[7] = new EBook("The Subtle Art of Not Giving a F*ck", "Mark Manson", 350, 1.8);
 resource_list[8] = new Audiobook("Educated", "Tara Westover",600, 150);
 resource_list[9] = new Book("Harry Potter and the Philosopher's Page 2 of 3 Stone", "J.K. Rowling", 450, CoverType::Paperback);
 sort_resources_price(resource_list, 10);
 /** Display sorted resources */
 for (int i = 0; i < 10; i++) {
 resource_list[i]->resourceDetails();
 }
 return 0;
 }