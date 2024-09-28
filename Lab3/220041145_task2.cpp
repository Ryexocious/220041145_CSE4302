#include<bits/stdc++.h>
using namespace std;
class Temperature{
private:
    double temp;
    string temptype;
    bool chkunit(string temptype){
        if(temptype=="Celsius"|| temptype=="Fahrenheit" || temptype=="Kelvin"){
            return true;
        }
        return false;
    }
    bool isAboveAbsoluteZero(double temp, const string& temptype) {
        if (temptype== "Celsius") {
            return temp >= -273.15;
        } 
        else if (temptype== "Fahrenheit") {
            return temp >= -459.67;
        } 
        else if (temptype== "Kelvin") {
            return temp >= 0;
        }
        return false;
    }
    double ctof(double c){
        return c*(9/5)+32;
    }
    double ftoc(double f){
        return (f-32)/(9/5);
    }
    double Ktoc(double k){
        return k-273.15;
    }
    double ctok(double c){
        return c+273.15;
    }
    double ftok(double f){
        return (f-32)*(5/9)+273.15;
    }
    double ktof(double k){
        return (k-273.15)*(9/5)+32;
    }
public:
    Temperature(){
        temp=0;
        temptype="Kelvin";
    }
    void assign(double t,string s){
        if(!chkunit(s)){
            cout<<"Wrong Unit"<<"\n";
            return;
        }
        if(!isAboveAbsoluteZero(t,s)){
            cout<<"Not in range of 0 Kelvin"<<'\n';
            return;
        }
        temp=t;
        temptype=s;
    }
    double convert(const string& newtype){
        if(!chkunit(newtype)){
            cout<<"Invalid unit"<<'\n';
            return -1;
        }
        if(temptype=="Celsius"){
            if(newtype=="Fahrenheit"){
                temptype=newtype;
                temp=ctof(temp);
                return temp;
            }
            else if(newtype=="Kelvin"){
                temptype=newtype;
                temp=ctok(temp);
                return temp;
            }
            else{
                return temp;
            }
        }
        if(temptype=="Fahrenheit"){
            if(newtype=="Celsius"){
                temptype=newtype;
                temp=ftoc(temp);
                return temp;
            }
            else if(newtype=="Kelvin"){
                temptype=newtype;
                temp=ftok(temp);
                return temp;
            }
            else{
                return temp;
            }
        }
        if(temptype=="Kelvin"){
            if(newtype=="Fahrenheit"){
                temptype=newtype;
                temp=ktof(temp);
                return temp;
            }
            else if(newtype=="Celsius"){
                temptype=newtype;
                temp=Ktoc(temp);
                return temp;
            }
            else{
                return temp;
            }
        }
        return -1;
    }
    void print(){
        cout<<"The temperature is "<<fixed<<setprecision(2)<<temp<<" "<<temptype<<"\n";
    }
};
int main(){
    Temperature t;
    t.assign(30,"Celsius");
    t.print();
    string s="Kelvin";
    cout<<"The converted Temp is "<<t.convert(s)<<" "<<s<<"\n";
}
