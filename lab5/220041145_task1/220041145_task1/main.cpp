#include "savingsaccount.h"
#include <algorithm>
#include <cstdlib>
#include <ctime> 
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
string generateRandomWord(int len) {
    string word = "";
    for (int i = 0; i < len; i++) {
        word += 'a' + rand() % 26;
    }
    return word;
}
void EditInformationByKeyboard(SavingsAccount& acc) {
    string name, address;
    double interestRate, balance;
    cout << "Enter account name: ";
    getline(cin, name);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter annual interest rate: ";
    cin >> interestRate;
    cout << "Enter current balance: ";
    cin >> balance;
    acc.setAccName(name);
    acc.setAddress(address);
    acc.setAnnualInterestRate(interestRate);
    acc.setCurrentBalance(balance);
    cin.ignore();
}

void generateInformationRandom(SavingsAccount& acc) {
    string name = generateRandomWord(4 + rand() % 7) + " " + generateRandomWord(4 + rand() % 7);
    string address = generateRandomWord(4 + rand() % 7) + " " + generateRandomWord(4 + rand() % 7) +
        " " + generateRandomWord(4 + rand() % 7) + " " + generateRandomWord(4 + rand() % 7);
    double interestRate = 2.0 + (rand() % 21) * 0.10;
    double balance = 1000 + rand() % 49001;
    acc.setAccName(name);
    acc.setAddress(address);
    acc.setAnnualInterestRate(interestRate);
    acc.setCurrentBalance(balance);
}

void ShowInterestAll(SavingsAccount accounts[], int size) {
    cout << "Interest amount for all accounts:" << endl;
    for (int i = 0; i < size; i++) {
        cout << accounts[i].getAccName() << ": "
            << fixed << setprecision(2)
            << accounts[i].calculateInterest(12) << " TK" << endl;
    }

    char confirm;
    cout << "Disburse interest to all accounts? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        for (int i = 0; i < size; i++) {
            accounts[i].disburseInterest(12);
        }
        cout << "Interest disbursed to all accounts." << endl;
    }
    else {
        cout << "Disbursement cancelled." << endl;
    }
}

void ShowAllAlphabetically(SavingsAccount accounts[], int size) {
    vector<SavingsAccount> sortedAccounts(accounts, accounts + size);
    sort(sortedAccounts.begin(), sortedAccounts.end(), [](SavingsAccount& a, SavingsAccount& b) {
        return a.getAccName() < b.getAccName();
        });
    cout << "Accounts sorted alphabetically:" << endl;
    for (const auto& acc : sortedAccounts) {
        cout << acc.getAccName() << ": " << fixed << setprecision(2)
            << acc.getCurrentBalance() << " TK" << endl;
    }
}

int main() {
    srand(time(0));
    SavingsAccount accounts[100];
    for (int i = 0; i < 5; i++) {
        EditInformationByKeyboard(accounts[i]);
    }
    for (int i = 5; i < 100; i++) {
        generateInformationRandom(accounts[i]);
    }
    ShowInterestAll(accounts, 100);
    ShowAllAlphabetically(accounts, 100);

    return 0;
}

