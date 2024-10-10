#include "Array.h"
#include "Person.h"

class ContactsBook {
private:
    Array<Person> contacts;

public:
    ContactsBook() {}

    void addContact(const Person& person) {
        contacts.push(person);
    }

    Person getContact(int index) const {
        return contacts.get(index);
    }

    Person searchContact(const string& name) const {
        for (int i = 0; i < contacts.getSize(); i++) {
            Person person = getContact(i);
            if (person.getName() == name) return person;
        }

        throw std::runtime_error("Contact: `" + name + "` not found: "); // Should really throw an error?
    }

    void printContacts() const {
        for (int i = 0; i < contacts.getSize(); i++) {
            Person person = getContact(i);
            person.printInfo();
            cout << "-----------------------------" << endl;
        }
    }
};
