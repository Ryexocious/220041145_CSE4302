#include<bits/stdc++.h>
using namespace std;
class BankAccount{
private:    
    int accnum;
    string accholdername;
    bool acctype; //true for current false for savings
    double currentbalance;
    const double minbalance=200;
    static int totalnumofbankacc;
    static int totalnumberofbankobj;
    static double totalamountoftax;
    bool minchk(int x){
        if(x<minbalance){
            return false;
        }
        return true;
    }
    bool depchk(int x){
        if(x<0){
            return false;
        }
        return true;
    }
public:
    BankAccount(){
        totalnumofbankacc++;
        totalnumberofbankobj++;
    }
    BankAccount(int x,string s,bool l,double cur){
        if(!minchk(cur)){
            cout<<"Invalid Ammount make 200"<<"\n";
            return;
        }
        accnum=x;
        accholdername=s;
        acctype=l;
        currentbalance=cur;
        totalnumofbankacc++;
        totalnumberofbankobj++;
    }
    void assign(int x,string s,bool l,double cur){
        if(!minchk(cur)){
            cout<<"Invalid Ammount make 200"<<"\n";
            return;
        }
        accnum=x;
        accholdername=s;
        acctype=l;
        currentbalance=cur;
    }
    void show(){
        cout<<"Account Number : "<<accnum<<"\n";
        cout<<"Account Holder Name : "<<accholdername<<"\n";
        cout<<"Account type :";
        if(acctype){
            cout<<"Current\n";
        }
        else{
            cout<<"Savings\n";
        }
        cout<<"Current Balance : "<<currentbalance<<'\n';
    }
    void showbalance(){
        cout<<"Account num : "<<accnum<<" has balance :"<<currentbalance<<"\n";
    }
    void deposit(double x){
        if(!depchk(x)){
            cout<<"invalid operation\n";
            return;
        }
        currentbalance+=x;
    }
    void withdraw(double x){
        if(!minchk(currentbalance-x)){
            cout<<"invalid Action"<<"\n";
            return;
        }
        currentbalance-=x;
    }
    void giveinterest(){
        double interest,tax; 
        interest=currentbalance*0.03;
        deposit(interest);
        tax=interest*.10;
        totalamountoftax+=tax;
        withdraw(tax);
    }
    ~BankAccount(){
        totalnumofbankacc--;
        cout<<"Account of Mr. "<<accholdername<<" with account no "<<accnum<<" is destroyed with a balance BDT "<<currentbalance<<"\n";
    }
    static int getTotalAccounts() {
        return totalnumberofbankobj;
    }
    static int getActiveAccounts() {
        return totalnumofbankacc;
    }
    static double getTotalSourceTax() {
        return totalamountoftax;
    }
    friend BankAccount Larger(const BankAccount& A, const BankAccount& B);
};
void display_stat(){
    cout<<"Total Bank Accounts created: "<<BankAccount::getTotalAccounts()<<"\n";
    cout<<"Currently active Bank Accounts: "<<BankAccount::getActiveAccounts()<<"\n";
    cout<<"Total source tax collected: BDT "<<BankAccount::getTotalSourceTax()<<"\n";
}
BankAccount Larger(const BankAccount& A, const BankAccount& B) {
    if (A.currentbalance > B.currentbalance)
        return A;
    else
        return B;
}
int main(){
    BankAccount acc1(12, "QUE", 0, 10000);
    BankAccount acc2(78, "baka", 1, 20000);
    acc1.show();
    acc2.showbalance();
    Larger(acc1,acc2);
    
}
