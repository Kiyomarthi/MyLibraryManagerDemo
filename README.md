# Project README

This README outlines the steps to build a basic console-based library management application in C++ (or any object-oriented language), including class design, data handling, user interaction, file persistence, and version control setup.

## Features

1. **Core Class Design**

   * Create a base class `Person` with the following fields:

     * `id` (identifier)
     * `name`
     * `phone`
     * `age`
   * Derive two subclasses from `Person`:

     * `Author` (with additional fields such as `degree`, `position`, `workplace`)
     * `Customer` (with additional fields such as `email`, `address`)

2. **In-Memory Data Storage**

   * Maintain lists (e.g., `std::vector`) for:

     * Books
     * Authors
     * Customers
     * Sales records

3. **Book Management**

   * Implement a function to add a new book by prompting the user for:

     * Book code
     * Title
     * Author ID
     * Price
   * Store the book in the books list.
   * Implement a function to display all books line by line.

4. **Author Management**

   * Implement a function to add a new author by prompting the user for:

     * ID
     * Name
     * Phone
     * Age
     * Degree
     * Position
     * Workplace
   * Store the author in the authors list.
   * Implement a function to list all authors.

5. **Customer Management**

   * Implement a function to add a new customer by prompting the user for:

     * ID
     * Name
     * Phone
     * Age
     * Email
     * Address
   * Store the customer in the customers list.
   * Implement a function to display all customers.

6. **Sales Recording & Reporting**

   * Implement a function to record a sale by prompting for:

     * Book code
     * Date
     * Quantity
   * Calculate the total price and store the sale record.
   * Implement a function to display all sales records line by line.

7. **Interactive Console Menu**

   * Create submenus for:

     * Books
     * Authors
     * Customers
     * Sales
   * Implement the main menu function to display options and call the appropriate submenu functions.

8. **File Persistence**

   * Add `load` (read) and `save` (write) functions for each list using `std::ifstream` and `std::ofstream`.
   * On program start, load all data from files.
   * After every significant change (e.g., adding a record), immediately save the updated list.
   * On exit, save all data one more time.

9. **Duplicate Record Prevention**

   * Before adding a book, author, or customer, check that the ID is not already in use.

10. **GitHub Release Preparation**

    * Initialize Git in the project folder.
    * Create a `.gitignore` file.
    * Commit your changes and push to a GitHub repository.
