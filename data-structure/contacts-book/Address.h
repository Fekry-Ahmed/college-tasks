#include <string>
using namespace std;

class Address {
private:
    string street;
    string city;

public:
    Address() {}
    Address(string street, string city) : street(street), city(city) {}

    string getStreet() const {
        return street;
    }

    string getCity() const {
        return city;
    }
};
