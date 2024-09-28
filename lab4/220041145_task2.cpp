#include<bits/stdc++.h>
using namespace std;
class flightdet{
private:
    int flightnumber;
    string destination;
    float distance;
    float MaxFuelCapacity;
    double Calfuel(){
        if(distance<=1000){
            return 500;
        }
        else if(distance>1000 && distance<=2000){
            return 1100;
        }
        else{
            return 2200;
        }
    }
public:
    void feedinfo(){
        int x;string s;float dis;float max;
        cin>>x>>s>>dis>>max;
        flightnumber=x;
        destination=s;
        distance=dis;
        MaxFuelCapacity=max;
    }
    void showinfo(){
        cout<<"flightnum "<<flightnumber<<"\n";
        cout<<"destination : "<<destination<<"\n";
        cout<<"distance :"<<distance<<'\n';
        cout<<"maxfuel :"<<MaxFuelCapacity<<'\n';
        if(Calfuel()>MaxFuelCapacity){
            cout<<"Not sufficient fuel capacity for this flight\n";
        }
        else{
            cout<<"Fuel capacity is fit for this flight distance\n";
        }
    }
};
int main(){
    flightdet f;
    f.feedinfo();
    f.showinfo();
}
