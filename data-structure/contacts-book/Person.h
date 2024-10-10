#include <string>
#include "Address.h"

class Person {
private:
    string name;
    string phoneNumber;
    Address address;

public:
    Person() {}
    Person(string name, string phone, Address address) : name(name), phoneNumber(phone), address(address) {}

    string getName() const {
        return name;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }

    void setPhoneNumber(string p) {
        phoneNumber = p;
    }

    Address getAddress() const {
        return address;
    }

    void setAddress(Address a) {
        address = a;
    }

    void printInfo() const {
        cout << "Name: " << getName() << ", Phone: " << getPhoneNumber() << endl;
        cout << "Address: " << address.getStreet() << ", " << address.getCity() << endl;
    }
};
