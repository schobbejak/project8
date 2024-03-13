#include <iostream>
#include "account.h"
#include <limits>
#include <ios>
using namespace std;

enum MenuOption {
    CREATE_ACCOUNT = 1,
    DEPOSIT_MONEY = 2,
    WITHDRAW_MONEY = 3,
    CHECK_BALANCE = 4,
};

void createAccount(Account& currentAccount) {
    cout << "Making your bank account" << endl;
    cout << "What is your name: ";
    string name;
    cin >> name;
    cout << "What is your age: ";
    int age;
    cin >> age;
    
    Customer customer(name, age);
    currentAccount = Account(customer, 0);
}

void depositMoney(Account& currentAccount) {
    cout << "How much do you want to deposit: ";
    double deposit;
    cin >> deposit;

    currentAccount.deposit(deposit);
}

void withdrawMoney(Account& currentAccount) {
    cout << "How much do you want to withdraw: ";
    double withdrawal;
    cin >> withdrawal;

    currentAccount.withdraw(withdrawal);
}

int main() {
    // Loop for user input
    Account currentAccount;
    bool isRunning = true; 
    while (isRunning) {
        cout << endl;
        cout << "Welcome " << currentAccount.get_customer().get_name() << ", what do you want to do today?" << endl;
        cout << "1 - Make a bank account, 2 - Deposit Money, 3 - Withdraw money, 4 - Balance, 5 - Cancel" << endl;
        int response;
        cin >> response;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } 
        switch (response) {
            case CREATE_ACCOUNT:
                createAccount(currentAccount);
                break;
            case DEPOSIT_MONEY:
                depositMoney(currentAccount);
                break;
            case WITHDRAW_MONEY:
                withdrawMoney(currentAccount);
                break;
            case CHECK_BALANCE:
                cout << "Current balance: " << currentAccount.get_balance() << endl;
                break;
            default:
                isRunning = false; 
                break;
        }
    }
    
    return 0;
}