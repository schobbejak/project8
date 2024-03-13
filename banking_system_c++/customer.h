#include <string>
#ifndef CUSTOMER_H
#define CUSTOMER_H
using namespace std;

class Customer {

private:
    string name; 
    int age;

public:
    Customer(string name, int age) {
        this->name = name;
        this->age = age;
    }

    Customer() {
        this->name = "Customer";
    } // Default constructor

    string get_name() {
        return this->name;
    }

    int get_age() {
        return this->age;
    }

    void set_age(int new_age) {
        this->age = new_age;
    }

};

#endif