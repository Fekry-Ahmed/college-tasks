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
    Address(string input)
    {

        int index = 0;
        string temp = "";
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '\n')
            {
                if (index == 0)
                {
                    street_name = temp;
                }
                else if (index == 1)
                {
                    city = temp;
                }
                else if (index == 2)
                {
                    state = temp;
                }
                index++;
                temp = "";
            }
            else
            {
                temp += input[i];
            }
        }
    }

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

        return address;
    }

    string to_string() const
    {
        return street_name + "\n" //
               + city + "\n"      //
               + state;
    }

    string get_street_name()
    {
        return street_name;
    }
    void set_street_name(string name)
    {
        street_name = name;
    }
    void set_city(string c)
    {
        city = c;
    }
    string get_city()
    {
        return city;
    }
    void set_state(string s)
    {
        state = s;
    }
    string get_state()
    {
        return state;
    }

    void print() const
    {
        cout << "Street: " << street_name << ", City: " << city << endl;
    }
};

#endif /* ADDRESS_H_ */