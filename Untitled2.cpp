#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string id;
    string name;
public:
    Person();
    Person(string id, string name);
    string getId();
    string getName();
    virtual ~Person();
};

class Author : public Person {
public:
    Author();
    Author(string id, string name);
};

class Customer : public Person {
public:
    Customer();
    Customer(string id, string name);
};

class Book {
private:
    int code;
    string title;
    string authorId;
    double price;
public:
    Book();
    Book(int code, string title, string authorId, double price);
    int getCode();
    string getTitle();
    string getAuthorId();
    double getPrice();
};

int main() {
    return 0;
}
