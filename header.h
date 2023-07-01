#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

struct InventoryBin
{
    string partDescription; // CALC & OUT - description of a part
    int numberOfParts;      // CALC & OUT - ammount/stock of part
};

/*******************************************************************************
 * displayInventory
 * This function takes in an array for struct and the array length ref and outs
 *  its elements.
 *  - returns nothing.
 ******************************************************************************/

void displayInventory(InventoryBin bin[],   // IN - array of struct
                      int &binNumber);      // IN - ref length of array

/*******************************************************************************
 * addItem
 * This function takes in an array for struct and the array length ref and adds
 *  a new element to the array.
 *  - returns nothing.
 ******************************************************************************/

void addItem(InventoryBin bin[],    // IN - array of struct
             int &binNumber);       // IN - ref length of array

/*******************************************************************************
 * addParts
 * This function takes in an array for struct, the array length ref, an int
 *  ammount to add, and a string holding the users selection. The func
 *  compares the user input to each element of the array and adds change to the
 *  matching one.
 *  - returns nothing.
 ******************************************************************************/

void addParts(InventoryBin bin[],   // IN - array of struct
              string tempInput,     // IN - user entered selection
              int &binNumber,       // IN - ref array length
              int change);          // IN - ammount to add

/*******************************************************************************
 * removeParts
 * This function takes in an array for struct, the array length ref, an int
 *  ammount to subtract, and a string holding the users selection. The func
 *  compares the user input to each element of the array and subs change to the
 *  matching one.
 *  - returns nothing.
 ******************************************************************************/

void removeParts(InventoryBin bin[],   // IN - array of struct
                 string tempInput,     // IN - user entered selection
                 int &binNumber,       // IN - ref array length
                 int change);           // IN - ammount to add

/*******************************************************************************
 * countDigit
 * This function takes in a number and calculates the number of digits.
 *  - returns number of digits.
 ******************************************************************************/

int countDigit(int n);   // IN - a number

#endif // HEADER_H
