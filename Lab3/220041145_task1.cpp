#include<bits/stdc++.h>
using namespace std;
class counter{
private:
    int count;
    int incrementstep;
public:
    counter(){
        count=0;
    }
    void setincrementstep(int nstep){
        incrementstep=nstep;
    }
    int Ccounter() const{
        return count;
    }
    void increment(){
        count+=incrementstep;
    }
    void reset(){
        count=0;
    }

};
int main(){
    counter c1;
    c1.setincrementstep(5);
    c1.increment();
    cout<<c1.Ccounter()<<"\n";
    c1.setincrementstep(2);
    c1.increment();
    cout<<c1.Ccounter()<<"\n";
    c1.reset();
    cout<<c1.Ccounter()<<"\n";

}
