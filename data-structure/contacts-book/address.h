#ifndef ADDRESS_H_
#define ADDRESS_H_

using namespace std;

#include <string>
#include <iostream>

class Address
{

private:
    int street_number;
    string street_name;
    string city;
    string state;

public:
    Address() {}

    static Address read_info()
    {
        Address address;

        cout << "Enter street: ";
        string street;
        cin >> street;
        address.set_street_name(street);

        cout << "Enter city: ";
        string city;
        cin >> city;
        address.set_city(city);

        cout << "Enter state: ";
        string state;
        cin >> state;
        address.set_state(state);
    }

    void set_street_name(string name)
    {
        street_name = name;
    }
    void set_city(string c)
    {
        city = c;
    }
    void set_city(string c)
    {
        city = c;
    }
    void set_state(string s)
    {
        state = s;
    }

    void print() const
    {
        cout << "Street: " << street_name << ", City: " << city << endl;
    }
};

#endif /* ADDRESS_H_ */