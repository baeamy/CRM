///*
// * Name: Amy Bae
// * EID: hb22882
// * PA7
// * Santacruz, Fall 2023
// */
//#include <iostream>
//#include <cassert>
//#include "UTString.h"
//#include "CustomerDB.h"
//
////using namespace std;
//
//const int default_capacity = 1;
//
//Customer::Customer(UTString name) { // done, please do not edit
//    this->books = 0;
//    this->dice = 0;
//    this->figures = 0;
//    this->towers = 0;
//    this->name = name;
//}
//
//CustomerDB::CustomerDB(void) { // done, please do not edit
//    this->capacity = default_capacity;
//    this->data = new Customer[this->capacity];
//    this->length = 0;
//}
//
//int CustomerDB::size(void) { // done, please do not edit
//    return this->length;
//}
//
//CustomerDB::~CustomerDB(void) { // done, please do not edit
//    delete[] this->data;
//}
//
//void CustomerDB::clear(void) { // done, please do not edit
//    delete[] this->data;
//    this->capacity = default_capacity;
//    this->data = new Customer[this->capacity];
//    this->length = 0;
//}
//
//Customer& CustomerDB::operator[](int k) { // done, please do not edit
//    assert(k >= 0 && k < this->length);
//    return this->data[k];
//}
//
//Customer& CustomerDB::operator[](UTString name) {
//
//    // Case 1: customer exists. iterating through data to find customer and then return customer.
//    for(int i = 0; i < length; i++){
//        if (data[i].name == name)
//            return data[i];
//    }
//
//    // Case 2: new customer, so add them to existing space.
//    if(length < capacity) {
//        Customer new_customer(name);
//        data[length] = new_customer;
//        return data[length++]; // incrementing length after return
//    }
//
//    // Case 3: there isn't enough space for the new customer: resize data array
//    capacity *= 2;
//    Customer* new_arr = new Customer[capacity]; // making a new array
//
//    // copy the old array into new_copy
//    for(int i = 0; i < length; i++) {
//        new_arr[i] = data[i];
////        this is the same as new_copy[i] = data[i] ==
////        new_copy[i].name = data[i].name;
////        new_copy[i].books = data[i].books;
////        new_copy[i].dice = data[i].dice;
////        new_copy[i].figures = data[i].figures;
////        new_copy[i].towers = data[i].towers;
//    }
//
//    // deleting old array
//    delete []data; // it's an array
//
//    // assigning new array to the actual data array
//    data = new_arr;
//
//    // allocate the customer into the new array
//    Customer new_customer(name);
//    data[length] = new_customer;
//    return data[length++]; // incrementing length after return
//}
//
//bool CustomerDB::isMember(UTString name) {
//    for(int i = 0; i < length; i++){
//        if (data[i].name == name)
//            return true;
//    }
//    return false;
//}

/*
 * Name:
 * EID:
 * PA7
 * Santacruz, Fall 2023
 */
#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->books = 0;
    this->dice = 0;
    this->figures = 0;
    this->towers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) {

    // Case 1: customer exists. iterating through data to find customer and then return customer.
    for(int i = 0; i < length; i++){
        if (data[i].name == name)
            return data[i];
    }

    // Case 2: new customer, so add them to existing space.
    if(length < capacity) {
        Customer new_customer(name);
        data[length] = new_customer;
        return data[length++]; // incrementing length after return
    }

    // Case 3: there isn't enough space for the new customer: resize data array
    capacity *= 2;
    Customer* new_arr = new Customer[capacity]; // making a new array

    // copy the old array into new_copy
    for(int i = 0; i < length; i++) {
        new_arr[i] = data[i];
//        this is the same as new_copy[i] = data[i] ==
//        new_copy[i].name = data[i].name;
//        new_copy[i].books = data[i].books;
//        new_copy[i].dice = data[i].dice;
//        new_copy[i].figures = data[i].figures;
//        new_copy[i].towers = data[i].towers;
    }

    // deleting old array
    delete []data; // it's an array

    // assigning new array to the actual data array
    data = new_arr;

    // allocate the customer into the new array
    Customer new_customer(name);
    data[length] = new_customer;
    return data[length++]; // incrementing length after return
}

bool CustomerDB::isMember(UTString name) {
    for(int i = 0; i < length; i++){
        if (data[i].name == name)
            return true;
    }
    return false;
}
