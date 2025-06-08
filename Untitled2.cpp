#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


void saveBooksToFile();
void saveAuthorsToFile();
void saveCustomersToFile();
void saveSalesToFile();


class Person {
protected:
    string id;
    string name;
    string phone;
    int age;
public:
    Person() {
        id = "";
        name = "";
        phone = "";
        age = 0;
    }
    Person(string id, string name, string phone, int age) {
        this->id = id;
        this->name = name;
        this->phone = phone;
        this->age = age;
    }
    string getId() {
        return id;
    }
    string getName() {
        return name;
    }
    string getPhone() {
        return phone;
    }
    int getAge() {
        return age;
    }
};

class Author : public Person {
private:
    string degree;
    string position;
    string workplace;
public:
    Author() : Person() {
        degree = "";
        position = "";
        workplace = "";
    }
    Author(string id, string name, string phone, int age, string degree, string position, string workplace)
        : Person(id, name, phone, age) {
        this->degree = degree;
        this->position = position;
        this->workplace = workplace;
    }
    string getDegree() {
        return degree;
    }
    string getPosition() {
        return position;
    }
    string getWorkplace() {
        return workplace;
    }
};

class Customer : public Person {
private:
    string email;
    string address;
public:
    Customer() : Person() {
        email = "";
        address = "";
    }
    Customer(string id, string name, string phone, int age, string email, string address)
        : Person(id, name, phone, age) {
        this->email = email;
        this->address = address;
    }
    string getEmail() {
        return email;
    }
    string getAddress() {
        return address;
    }
};

class Book {
private:
    int code;
    string title;
    string authorId;
    double price;
public:
    Book() {
        code = 0;
        title = "";
        authorId = "";
        price = 0;
    }
    Book(int code, string title, string authorId, double price) {
        this->code = code;
        this->title = title;
        this->authorId = authorId;
        this->price = price;
    }
    int getCode() {
        return code;
    }
    string getTitle() {
        return title;
    }
    string getAuthorId() {
        return authorId;
    }
    double getPrice() {
        return price;
    }
};

class Sale {
private:
    int bookCode;
    string date;
    int quantity;
    double totalPrice;
public:
    Sale() {
        bookCode = 0;
        date = "";
        quantity = 0;
        totalPrice = 0;
    }
    Sale(int bookCode, string date, int quantity, double totalPrice) {
        this->bookCode = bookCode;
        this->date = date;
        this->quantity = quantity;
        this->totalPrice = totalPrice;
    }
    int getBookCode() {
        return bookCode;
    }
    string getDate() {
        return date;
    }
    int getQuantity() {
        return quantity;
    }
    double getTotalPrice() {
        return totalPrice;
    }
};

vector<Book> books;
vector<Author> authors;
vector<Customer> customers;
vector<Sale> sales;

void addBook() {
    int code;
    string title;
    string authorId;
    double price;

    cout << "\nEnter book code: ";
    cin >> code;
    cout << "Enter book title: ";
    cin >> title;
    cout << "Enter author ID: ";
    cin >> authorId;
    cout << "Enter book price: ";
    cin >> price;

    Book newBook(code, title, authorId, price);
    books.push_back(newBook);
    saveBooksToFile();

    cout << "Book added successfully.\n";
}

void listBooks() {
    cout << "\n--- Book List ---\n";
    for (int i = 0; i < books.size(); i++) {
        cout << "Code: " << books[i].getCode() << endl;
        cout << "Title: " << books[i].getTitle() << endl;
        cout << "Author ID: " << books[i].getAuthorId() << endl;
        cout << "Price: " << books[i].getPrice() << endl;
        cout << "-------------------------\n";
    }
}

void addAuthor() {
    string id, name, phone, degree, position, workplace;
    int age;

    
    cout << "\nEnter author ID: ";
    cin >> id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter phone: ";
    cin >> phone;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter degree: ";
    cin >> degree;
    cout << "Enter position: ";
    cin>>position;
    cout << "Enter workplace: ";
    getline(cin, workplace);
    cin >> workplace;

    Author newAuthor(id, name, phone, age, degree, position, workplace);
    authors.push_back(newAuthor);
    saveAuthorsToFile();

    cout << "Author added successfully.\n";
}

void listAuthors() {
    cout << "\n--- Author List ---\n";
    for (int i = 0; i < authors.size(); i++) {
        cout << "ID: " << authors[i].getId() << endl;
        cout << "Name: " << authors[i].getName() << endl;
        cout << "Phone: " << authors[i].getPhone() << endl;
        cout << "Age: " << authors[i].getAge() << endl;
        cout << "Degree: " << authors[i].getDegree() << endl;
        cout << "Position: " << authors[i].getPosition() << endl;
        cout << "Workplace: " << authors[i].getWorkplace() << endl;
        cout << "-------------------------\n";
    }
}

void addCustomer() {
    string id, name, phone, email, address;
    int age;

    cout << "\nEnter customer ID: ";
    cin >> id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter phone: ";
    cin >> phone;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter email: ";
    getline(cin, email);
    cin >> email;
    cout << "Enter address: ";
    
    cin >> address;

    Customer newCustomer(id, name, phone, age, email, address);
    customers.push_back(newCustomer);
    saveCustomersToFile();

    cout << "Customer added successfully.\n";
}

void listCustomers() {
    cout << "\n--- Customer List ---\n";
    for (int i = 0; i < customers.size(); i++) {
        cout << "ID: " << customers[i].getId() << endl;
        cout << "Name: " << customers[i].getName() << endl;
        cout << "Phone: " << customers[i].getPhone() << endl;
        cout << "Age: " << customers[i].getAge() << endl;
        cout << "Email: " << customers[i].getEmail() << endl;
        cout << "Address: " << customers[i].getAddress() << endl;
        cout << "-------------------------\n";
    }
}

void addSale() {
    int bookCode;
    string date;
    int quantity;

    cout << "\nEnter book code: ";
    cin >> bookCode;
    
    cout << "Enter sale date (YYYY-MM-DD): ";
    cin >> ;
    cout << "Enter quantity sold: ";
    cin >> quantity;

    double price = 0;
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getCode() == bookCode) {
            price = books[i].getPrice();
            break;
        }
    }
    if (price == 0) {
        cout << "Book code not found.\n";
        return;
    }

    double totalPrice = price * quantity;
    Sale newSale(bookCode, date, quantity, totalPrice);
    sales.push_back(newSale);
     saveSalesToFile();

    cout << "Sale recorded successfully.\n";
}

void reportSales() {
    cout << "\n--- Sales Report ---\n";

    if (sales.empty()) {
        cout << "No sales recorded yet.\n";
        return;
    }

    for (int i = 0; i < sales.size(); i++) {
        int bookCode = sales[i].getBookCode();
        string bookTitle = "Unknown";

        
        for (int j = 0; j < books.size(); j++) {
            if (books[j].getCode() == bookCode) {
                bookTitle = books[j].getTitle();
                break;
            }
        }

        cout << "Book Code: " << bookCode 
             << ", Title: " << bookTitle 
             << ", Date: " << sales[i].getDate() 
             << ", Quantity: " << sales[i].getQuantity() 
             << ", Total Price: " << sales[i].getTotalPrice() <<" Rial"<< endl;
    }
    
    int totalOfSales = 0;
    for(int i = 0; i < sales.size(); i++){
    	totalOfSales += sales[i].getTotalPrice();
	}
	
	cout<<"------ total of all sale: "<< totalOfSales<<endl;
}


void authorMenu() {
    int choice;
    do {
        cout << "\n--- Author Management ---\n";
        cout << "1. Add Author\n";
        cout << "2. Show Author List\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addAuthor();
                break;
            case 2:
                listAuthors();
                break;
        }
    } while (choice != 0);
}

void bookMenu() {
    int choice;
    do {
        cout << "\n--- Book Management ---\n";
        cout << "1. Add Book\n";
        cout << "2. Show Book List\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
        }
    } while (choice != 0);
}

void salesMenu() {
    int choice;
    do {
        cout << "\n--- Sales Management ---\n";
        cout << "1. Add Sale\n";
        cout << "2. Show Sales Report\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addSale();
                break;
            case 2:
                reportSales();
                break;
        }
    } while (choice != 0);
}

void saveBooksToFile() {
    ofstream out("books.txt");
    for (int i = 0; i < books.size(); i++) {
        out << books[i].getCode() << "\n";
        out << books[i].getTitle() << "\n";
        out << books[i].getAuthorId() << "\n";
        out << books[i].getPrice() << "\n";
    }
    out.close();
    cout << "Books saved.\n";
}

void loadBooksFromFile() {
    books.clear();
    ifstream in("books.txt");
    int code;
    string title;
    string authorId;
    double price;

    while (in >> code) {
        in.ignore();
        getline(in, title);
        getline(in, authorId);
        in >> price;
        in.ignore();

        Book b(code, title, authorId, price);
        books.push_back(b);
    }

    in.close();
    cout << "Books loaded.\n";
}

void saveAuthorsToFile() {
    ofstream out("authors.txt");
    for (int i = 0; i < authors.size(); i++) {
        out << authors[i].getId() << "\n";
        out << authors[i].getName() << "\n";
        out << authors[i].getPhone() << "\n";
        out << authors[i].getAge() << "\n";
        out << authors[i].getDegree() << "\n";
        out << authors[i].getPosition() << "\n";
        out << authors[i].getWorkplace() << "\n";
    }
    out.close();
    cout << "Authors saved.\n";
}

void loadAuthorsFromFile() {
    authors.clear();
    ifstream in("authors.txt");
    string id, name, phone, degree, position, workplace;
    int age;

    while (getline(in, id)) {
        getline(in, name);
        getline(in, phone);
        in >> age;
        in.ignore();
        getline(in, degree);
        getline(in, position);
        getline(in, workplace);

        Author a(id, name, phone, age, degree, position, workplace);
        authors.push_back(a);
    }
    in.close();
    cout << "Authors loaded.\n";
}

void saveCustomersToFile() {
    ofstream out("customers.txt");
    for (int i = 0; i < customers.size(); i++) {
        out << customers[i].getId() << "\n";
        out << customers[i].getName() << "\n";
        out << customers[i].getPhone() << "\n";
        out << customers[i].getAge() << "\n";
        out << customers[i].getEmail() << "\n";
        out << customers[i].getAddress() << "\n";
    }
    out.close();
    cout << "Customers saved.\n";
}

void loadCustomersFromFile() {
    customers.clear();
    ifstream in("customers.txt");
    string id, name, phone, email, address;
    int age;

    while (getline(in, id)) {
        getline(in, name);
        getline(in, phone);
        in >> age;
        in.ignore();
        getline(in, email);
        getline(in, address);

        Customer c(id, name, phone, age, email, address);
        customers.push_back(c);
    }
    in.close();
    cout << "Customers loaded.\n";
}

void saveSalesToFile() {
    ofstream out("sales.txt");
    for (int i = 0; i < sales.size(); i++) {
        out << sales[i].getBookCode() << "\n";
        out << sales[i].getDate() << "\n";
        out << sales[i].getQuantity() << "\n";
        out << sales[i].getTotalPrice() << "\n";
    }
    out.close();
    cout << "Sales saved.\n";
}


void loadSalesFromFile() {
    sales.clear();
    ifstream in("sales.txt");
    int bookCode, quantity;
    string date;
    double totalPrice;

    while (in >> bookCode) {
        in.ignore();
        getline(in, date);
        in >> quantity;
        in >> totalPrice;
        in.ignore();

        Sale s(bookCode, date, quantity, totalPrice);
        sales.push_back(s);
    }
    in.close();
    cout << "Sales loaded.\n";
}




int main() {
    int choice;
    loadBooksFromFile();
    loadAuthorsFromFile();
    loadCustomersFromFile();
    loadSalesFromFile();
    do {
        cout << "\n			--------- Store Management --------- Abolfazl Kiumarsi --------- \n";
        cout << "1. Book Management\n";
        cout << "2. Author Management\n";
        cout << "3. Sales Management\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                bookMenu();
                break;
            case 2:
                authorMenu();
                break;
            case 3:
                salesMenu();
                break;
            
        }
    } while (choice != 0);
    saveBooksToFile();
    saveAuthorsToFile();
    saveCustomersToFile();
    saveSalesToFile();
    cout << "Goodbye!\n";
    return 0;
}
