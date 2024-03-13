#include "customer.h"
#include <iostream>
using namespace std;

class Account {

private:
    Customer customer;
    double balance;

public:
    Account(Customer customer, double balance) {
        this->customer = customer;
        this->balance = balance;
    }

    Account() {} // Default constructor

    Customer get_customer() {
        return this->customer;
    }

    double get_balance() {
        return this->balance;
    }

    void deposit(double deposit_money) {
        if (deposit_money < 0) {
            throw runtime_error("Can't upload negative money");
        }

        this->balance += deposit_money;
    }

    double withdraw(double withdraw_money) {
        if (withdraw_money > this->balance) {
            throw runtime_error("Not enough money, check balance");
        }

        this->balance -= withdraw_money;
        return withdraw_money;
    }
};