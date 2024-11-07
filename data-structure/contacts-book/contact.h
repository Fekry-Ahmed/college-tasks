#ifndef CONTACT_H_
#define CONTACT_H_

#include <string>
#include <vector>
#include "address.h"
#include "utils.h"

class Contact
{
private:
    static void update_contact_info(Contact &contact)
    {
        cout << "Enter first name: ";
        string first_name;
        cin >> first_name;
        contact.set_first_name(first_name);

        cout << "Enter last name: ";
        string last_name;
        cin >> last_name;
        contact.set_last_name(last_name);

        cout << "Enter category: ";
        string category;
        cin >> category;
        contact.set_category(category);

        cout << "Is it favourite? (1/0): ";
        int favourite;
        cin >> favourite;
        contact.set_is_favourite(favourite);

        cout << "Enter phone number: ";
        string phone_number;
        cin >> phone_number;
        contact.set_phone_number(phone_number);

        cout << "Enter email address: ";
        string mail;
        cin >> mail;
        contact.set_mail(mail);

        Address address = Address::read_info();
        contact.set_address(address);
    }

public:
    static Contact read_contact()
    {
        Contact contact;
        update_contact_info(contact);
        return contact;
    }

private:
    string first_name;
    string last_name;
    string phone_number;
    string category;
    bool is_favourite;
    string mail;
    Address address;

public:
    Contact() {}
    Contact(string input)
    {
        vector<string> v = split_tring(input, "\n");
        first_name = v[0];
        last_name = v[1];
        phone_number = v[2];
        category = v[3];
        is_favourite = v[4] == "1";
        mail = v[5];
        address = Address(v[6] + "\n" + v[7] + "\n" + v[8]);
    }
    ~Contact() {}

    string to_string() const
    {
        return first_name + "\n" +                 //
               last_name + "\n" +                  //
               phone_number + "\n" +               //
               category + "\n" +                   //
               (is_favourite ? "1" : "0") + "\n" + //
               mail + "\n" +                       //
               address.to_string();
    }

    void set_first_name(string f)
    {
        first_name = f;
    }
    void set_last_name(string l)
    {
        last_name = l;
    }
    string get_last_name() const
    {
        return last_name;
    }
    void set_category(string c)
    {
        category = c;
    }
    string get_category() const
    {
        return category;
    }
    void set_is_favourite(bool f)
    {
        is_favourite = f;
    }
    bool get_is_favourite()
    {
        return is_favourite;
    }
    void set_phone_number(string p)
    {
        phone_number = p;
    }
    void set_mail(string m)
    {
        mail = m;
    }
    void set_address(Address a)
    {
        address = a;
    }

    void update()
    {
        update_contact_info(*this);
    }

    void print() const
    {
        cout << "Name: " << first_name << " " << last_name << ", Phone: " << phone_number << endl;
        address.print();
    }
};

#endif // CONTACT_H_
