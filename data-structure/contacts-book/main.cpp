#include <iostream>
#include "ContactsBook.h"

int main() {
    ContactsBook book;

    Address address1("Zagazig", "Some street");
    Person person1("Fekry", "123456789", address1);

    Address address2("Cairo", "street");
    Person person2("fekry again", "Some number", address2);

    book.addContact(person1);
    book.addContact(person2);

    // Person contact = book.searchContact("Fekry");
    // contact.printInfo();

    book.printContacts();

    return 0;
}
