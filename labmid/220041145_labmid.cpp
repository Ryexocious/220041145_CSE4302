#include<iostream>
#include<cstring>
using namespace std;
class mystring {
private:
    char* str;
public:

    mystring() {
        str = new char[5]; 
        strcpy(str, "vaka");
    }

    mystring(const char ar[]) {
        int len = strlen(ar);
        str = new char[len + 1]; 
        strcpy(str, ar);
    }
    mystring(const mystring &other) {
        int len = strlen(other.str);
        str = new char[len + 1];
    }

    mystring& operator=(const mystring &other) {
        if (this == &other) {
            return *this; 
        }
        delete[] str;
        int len = strlen(other.str);
        str = new char[len + 1]; 
        strcpy(str, other.str); 
        return *this;
    }
    void assignstring(const char ar[]) {
        delete[] str;  
        int len = strlen(ar);
        str = new char[len + 1];  
        strcpy(str, ar);      
    }

    int length() const {
        return strlen(str);
    }

    void print() const {
        cout << str << "\n";
    }

    ~mystring() {
        delete[] str; 
    }
};

void sortbylength(mystring ar[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (ar[i].length() > ar[j].length()) {
                mystring temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
}

int main() {
    mystring s[3]; 
    char ar2[4] = "aka";

    for (int i = 0; i < 3; i++) {
        s[i].assignstring(ar2);
    }

    for (int i = 0; i < 3; i++) {
        s[i].print();
    }
}
