///*
// * Name: Amy Bae
// * EID: hb22882
// * PA7
// * Santacruz, Fall 2023
// */
//
//#include <stdio.h>
//#include "UTString.h"
//#include "Customer.h"
//#include "CustomerDB.h"
//#include <iostream>
//
//void readString(UTString&);
//void readNum(int&);
//
//CustomerDB database;
//
//int num_books = 0;
//int num_dice = 0;
//int num_figures = 0;
//int num_towers = 0;
//
//UTString item_type;
//UTString customer_name;
//int quantity;
//
///* clear the inventory and reset the customer database to empty */
//void reset(void) {
//    database.clear();
//    num_books = 0;
//    num_dice = 0;
//    num_figures = 0;
//    num_towers = 0;
//}
//
///*
// * selectInventItem is a convenience function that allows you
// * to obtain a pointer to the inventory record using the item type name
// * word must be "Books", "Dice", "Figures" or "Towers"
// * for example the expression *selectInventItem("Books") returns the
// * current global variable for the number of books in the inventory
// */
//int* selectInventItem(UTString word) {
//    if (word == "Books") {
//        return &num_books;
//    } else if (word == "Dice") {
//        return &num_dice;
//    } else if (word == "Figures") {
//        return &num_figures;
//    } else if (word == "Towers"){
//        return &num_towers;
//    }
//
//    /* NOT REACHED */
//    return 0;
//}
//
///*
// * this overload of selectInventItem is similar to selectInventItem above, however
// * this overload takes a Customer as a second argument and selects the data member
// * of that Customer that matches "word". The function returns a pointer to one of the three data
// * members from the specified customer.
// */
//int* selectInventItem(UTString word, Customer& cust) {
//    if (word == "Books") {
//        return &cust.books;
//    } else if (word == "Dice") {
//        return &cust.dice;
//    } else if (word == "Figures") {
//        return &cust.figures;
//    } else if (word == "Towers"){
//        return &cust.towers;
//    }
//
//    /* NOT REACHED */
//    return 0;
//}
//
///*
// * findMax searches through the CustomerDB "database" and returns the Customer
// * who has purchased the most items of the specified type.
// * type must be one of "Books", "Dice", "Figures" or "Towers".
// *
// * Note: if two or more Customers are tied for having purchased the most of that item type
// * then findMax returns the first Customer in the CustomerDB who has purchased that maximal
// * quantity.
// *
// * Note: in the special case (invalid case) where there are zero Customers in the
// * CustomerDB, fundMax returns a null pointer (0)
// */
//Customer* findMax(UTString type) {
//    Customer* result = 0;
//    int max = 0;
//    for (int k = 0; k < database.size(); k += 1) {
//        Customer& cust = database[k];
//        int *p = selectInventItem(type, cust);
//        if (*p > max) {
//            max = *p;
//            result = &cust;
//        }
//    }
//
//    return result;
//}
//
//void processPurchase() {
//    // reading in the name of the customer
//    readString(customer_name);
//
//    // reading in the item
//    readString(item_type);
//
//    // reading in the quantity
//    readNum(quantity);
//
//    UTString Books("Books");
//    UTString Dice("Dice");
//    UTString Figures("Figures");
//    UTString Towers("Towers");
//
//    if(item_type == Books) {
//        // If Bob wanted to buy 0 books
//        if (quantity == 0)
//            return;
//
//        // checking if there's enough books for purchase
//        if (quantity > num_books) {
//            std::cout << "Sorry " << customer_name.c_str() << ", we only have " << num_books << " Books" << std::endl;
//            return;
//        } else
//            num_books -= quantity;
//    }
//
//    else if(item_type == Dice) {
//        // If Bob wanted to buy 0 dice
//        if (quantity == 0)
//            return;
//
//        // checking if there's enough dice for purchase
//        if (quantity > num_dice) {
//            std::cout << "Sorry " << customer_name.c_str() << ", we only have " << num_dice << " Dice" << std::endl;
//            return;
//        } else
//            num_dice -= quantity;
//    }
//
//    else if(item_type == Figures) {
//        // If Bob wanted to buy 0 figures
//        if (quantity == 0)
//            return;
//
//        // checking if there's enough figures for purchase
//        if (quantity > num_figures) {
//            std::cout << "Sorry " << customer_name.c_str() << ", we only have " << num_figures << " Figures" << std::endl;
//            return;
//        } else
//            num_figures -= quantity;
//    }
//
//    if(item_type == Towers) {
//        // If Bob wanted to buy 0 Towers
//        if (quantity == 0)
//            return;
//
//        // checking if there's enough towers for purchase
//        if (quantity > num_towers) {
//            std::cout << "Sorry " << customer_name.c_str() << ", we only have " << num_towers << " Towers" << std::endl;
//            return;
//        } else
//            num_towers -= quantity;
//    }
//
//    // updating customer record
//    int* cust_pt = selectInventItem(item_type, database[customer_name]); // CustomerDB[]
//    *cust_pt += quantity; // adding the purchase to record
//}
//
//void processSummarize() {
//    UTString Books("Books");
//    UTString Dice("Dice");
//    UTString Figures("Figures");
//    UTString Towers("Towers");
//
//    std::cout << "There are " << num_books << " Books " << num_dice << " Dice " << num_figures << " Figures and " << num_towers << " Towers in inventory" << std::endl;
//    std::cout << "we have had a total of " << database.size() << " different customers" << std::endl;
//
//    if(findMax(Books) != nullptr && (findMax(Books)->books) != 0)
//        std::cout << (findMax(Books)->name).c_str() << " has purchased the most Books (" << (findMax(Books)->books) << ")" << std::endl;
//    else // if there were 0 customers or no one has bought this item
//        std::cout << "no one has purchased any Books" << std::endl;
//
//    if(findMax(Dice) != nullptr && (findMax(Dice)->dice) != 0)
//        std::cout << (findMax(Dice)->name).c_str() << " has purchased the most Dice (" << (findMax(Dice)->dice) << ")" << std::endl;
//    else
//        std::cout << "no one has purchased any Dice" << std::endl;
//
//    if(findMax(Figures) != nullptr && (findMax(Figures)->figures) != 0)
//        std::cout << (findMax(Figures)->name).c_str() << " has purchased the most Figures (" << (findMax(Figures)->figures) << ")" << std::endl;
//    else
//        std::cout << "no one has purchased any Figures" << std::endl;
//
//    if(findMax(Towers) != nullptr && (findMax(Towers)->towers) != 0)
//        std::cout << (findMax(Towers)->name).c_str() << " has purchased the most Towers (" << (findMax(Towers)->towers) << ")" << std::endl;
//    else
//        std::cout << "no one has purchased any Towers" << std::endl;
//}
//
//void processInventory() {
//    // reading in the item
//    readString(item_type);
//
//    // reading in the quantity
//    readNum(quantity);
//
//    UTString Books("Books");
//    UTString Dice("Dice");
//    UTString Figures("Figures");
//    UTString Towers("Towers");
//
//    if(item_type == Books)
//        num_books += quantity;
//    else if (item_type == Dice)
//        num_dice += quantity;
//    else if(item_type == Figures)
//        num_figures += quantity;
//    else if(item_type == Towers)
//        num_towers += quantity;
//}

/*
 * Name: Amy Bae
 * EID: hb22882
 * PA7
 * Santacruz, Fall 2023
 */

#include <stdio.h>
#include "UTString.h"
#include "Customer.h"
#include "CustomerDB.h"
#include <iostream>

void readString(UTString&);
void readNum(int&);
void Find_max_index(CustomerDB &database);

CustomerDB database;

int num_books = 0;
int num_dice = 0;
int num_figures = 0;
int num_towers = 0;

int i_books = 0;
int i_dice = 0;
int i_figures = 0;
int i_towers = 0;

UTString item_type;
UTString customer_name;
int quantity;

/* clear the inventory and reset the customer database to empty */
void reset(void) {
    database.clear();
    num_books = 0;
    num_dice = 0;
    num_figures = 0;
    num_towers = 0;
}

/*
 * selectInventItem is a convenience function that allows you
 * to obtain a pointer to the inventory record using the item type name
 * word must be "Books", "Dice", "Figures" or "Towers"
 * for example the expression *selectInventItem("Books") returns the
 * current global variable for the number of books in the inventory
 */
int* selectInventItem(UTString word) {
    if (word == "Books") {
        return &num_books;
    } else if (word == "Dice") {
        return &num_dice;
    } else if (word == "Figures") {
        return &num_figures;
    } else if (word == "Towers"){
        return &num_towers;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * this overload of selectInventItem is similar to selectInventItem above, however
 * this overload takes a Customer as a second argument and selects the data member
 * of that Customer that matches "word". The function returns a pointer to one of the three data
 * members from the specified customer.
 */
int* selectInventItem(UTString word, Customer& cust) {
    if (word == "Books") {
        return &cust.books;
    } else if (word == "Dice") {
        return &cust.dice;
    } else if (word == "Figures") {
        return &cust.figures;
    } else if (word == "Towers"){
        return &cust.towers;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * findMax searches through the CustomerDB "database" and returns the Customer
 * who has purchased the most items of the specified type.
 * type must be one of "Books", "Dice", "Figures" or "Towers".
 *
 * Note: if two or more Customers are tied for having purchased the most of that item type
 * then findMax returns the first Customer in the CustomerDB who has purchased that maximal
 * quantity.
 *
 * Note: in the special case (invalid case) where there are zero Customers in the
 * CustomerDB, fundMax returns a null pointer (0)
 */
Customer* findMax(UTString type) {
    Customer* result = 0;
    int max = 0;
    for (int k = 0; k < database.size(); k += 1) {
        Customer& cust = database[k];
        int *p = selectInventItem(type, cust);
        if (*p > max) {
            max = *p;
            result = &cust;
        }
    }

    return result;
}

void processPurchase() {
    // reading in the name of the customer
    readString(customer_name);

    // reading in the item
    readString(item_type);

    // reading in the quantity
    readNum(quantity);

    UTString Books("Books");
    UTString Dice("Dice");
    UTString Figures("Figures");
    UTString Towers("Towers");

    if(item_type == Books) {
        // If Bob wanted to buy 0 books
        if (quantity == 0)
            return;

        // checking if there's enough books for purchase
        if (quantity > num_books) {
            std::cout << "Sorry " << customer_name.c_str() << ", we only have " << num_books << " Books" << std::endl;
            return;
        } else
            num_books -= quantity;
    }

    else if(item_type == Dice) {
        // If Bob wanted to buy 0 dice
        if (quantity == 0)
            return;

        // checking if there's enough dice for purchase
        if (quantity > num_dice) {
            std::cout << "Sorry " << customer_name.c_str() << ", we only have " << num_dice << " Dice" << std::endl;
            return;
        } else
            num_dice -= quantity;
    }

    else if(item_type == Figures) {
        // If Bob wanted to buy 0 figures
        if (quantity == 0)
            return;

        // checking if there's enough figures for purchase
        if (quantity > num_figures) {
            std::cout << "Sorry " << customer_name.c_str() << ", we only have " << num_figures << " Figures" << std::endl;
            return;
        } else
            num_figures -= quantity;
    }

    if(item_type == Towers) {
        // If Bob wanted to buy 0 Towers
        if (quantity == 0)
            return;

        // checking if there's enough towers for purchase
        if (quantity > num_towers) {
            std::cout << "Sorry " << customer_name.c_str() << ", we only have " << num_towers << " Towers" << std::endl;
            return;
        } else
            num_towers -= quantity;
    }

    // updating customer record
    int* cust_pt = selectInventItem(item_type, database[customer_name]); // CustomerDB[]
    *cust_pt += quantity; // adding the purchase to record
}

void processSummarize() {
    UTString Books("Books");
    UTString Dice("Dice");
    UTString Figures("Figures");
    UTString Towers("Towers");

    // function find the index of the person that bought the most books
    Find_max_index(database);

    std::cout << "There are " << num_books << " Books " << num_dice << " Dice " << num_figures << " Figures and " << num_towers << " Towers in inventory" << std::endl;
    std::cout << "we have had a total of " << database.size() << " different customers" << std::endl;

    if(database[i_books].books != 0)
        std::cout << ((database[i_books]).name).c_str() << " has purchased the most Books (" << database[i_books].books << ")" << std::endl;
    else
        std::cout << "no one has purchased any Books" << std::endl;

    if(database[i_dice].dice != 0)
        std::cout << database[i_dice].name.c_str() << " has purchased the most Dice (" << database[i_dice].dice << ")" << std::endl;
    else
        std::cout << "no one has purchased any Dice" << std::endl;

    if(database[i_figures].figures != 0)
        std::cout << database[i_figures].name.c_str() << " has purchased the most Figures (" << database[i_figures].figures << ")" << std::endl;
    else
        std::cout << "no one has purchased any Figures" << std::endl;

    if(database[i_towers].towers != 0)
        std::cout << database[i_towers].name.c_str() << " has purchased the most Towers (" << database[i_towers].towers << ")" << std::endl;
    else
        std::cout << "no one has purchased any Towers" << std::endl;
}

void processInventory() {
    // reading in the item
    readString(item_type);

    // reading in the quantity
    readNum(quantity);

    UTString Books("Books");
    UTString Dice("Dice");
    UTString Figures("Figures");
    UTString Towers("Towers");

    if(item_type == Books)
        num_books += quantity;
    else if (item_type == Dice)
        num_dice += quantity;
    else if(item_type == Figures)
        num_figures += quantity;
    else if(item_type == Towers)
        num_towers += quantity;
}

void Find_max_index(CustomerDB &database){

    int max;
    int i;

    // finding max for books
    max = database[0].books;
    for (i = 0; i < database.size(); i++){
        if (max < database[i].books){
            max = database[i].books;
            i_books = i;
        }
    }

    // finding max for dice
    max = database[0].dice;
    for (i = 0; i < database.size(); i++){
        if (max < database[i].dice){
            max = database[i].dice;
            i_dice = i;
        }
    }

    // finding max for figures
    max = database[0].figures;
    for (i = 0; i < database.size(); i++){
        if (max < database[i].figures){
            max = database[i].figures;
            i_figures = i;
        }
    }

    // finding max for towers
    max = database[0].towers;
    for (i = 0; i < database.size(); i++){
        if (max < database[i].towers){
            max = database[i].towers;
            i_towers = i;
        }
    }
}