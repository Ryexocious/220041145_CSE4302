#include<bits/stdc++.h>
using namespace std;
class Calculator{
private: 
    int current;
    void getset(int x){
        current=x;
    }
    int get(){
        return current;
    }
    void add(int a){
        current+=a;
    }
    void sub(int a){
        current-=a;
    }
    void mul(int a){
        current*=a;
    }
    void div(int a){
        if(a==0){
            cout<<"Invalid arithmetic operation.\n";
            return;
        }
        current/=a;
    }
public:
    Calculator(){
        current=0;
    }
    Calculator(int x){
        getset(x);
    }
    void Add(int x){
        add(x);
    }
    void Sub(int x){
        sub(x);
    }
    void MUl(int x){
        mul(x);
    }
    void Div(int x){
        div(x);
    }
    void display(){
        cout<<get()<<"\n";
    }
    void clear(){
        current=0;
    }
    ~Calculator(){
        cout<<current<<"Destructor of the Calculator object is called."<<"\n";
    }
};
int main(){
    Calculator c;
    c.Add(10); c.display();
    c.Add(7); c.display();
    c.MUl(7); c.display();
    c.Sub(31); c.display();
    c.Div(7);c.display();
    c.Div(0);c.display();
    c.Add(3);c.display();
    c.clear(); c.display();

}
