#include<bits/stdc++.h>
using namespace std;
class Time{
private:
    int hour;
    int minute;
    int second;
    void mod(){
        if(second>=60){
            minute+=second/60;
            second%=60;
        }
        if(minute>=60){
            hour+=minute/60;
            minute%=60;
        }
        hour=hour%24;
    }
public:
    Time(){
        hour=0;
        minute=0;
        second=0;
    }
    int hours(){
        return hour;
    }
    int minutes(){
        return minute;
    }
    int seconds(){
        return second;
    }
    void reset(int h,int m,int s){
        hour=h;
        minute=m;
        second=s;
        mod();
    }
    void advance(int h,int m,int s){
        hour+=h;
        minute+=m;
        second+=s;
        mod();
    }
    void print(){
        cout << setw(2) << setfill('0') << hour << ":"<< setw(2) << setfill('0') << minute << ":"<< setw(2) << setfill('0') << second << "\n";
    }
};
int main(){
    Time t;
    t.reset(20,30,30);
    cout<<t.hours()<<" "<<t.minutes()<<" "<<t.seconds()<<" "<<"\n";
    t.advance(2,3,3);
    t.print();

}
