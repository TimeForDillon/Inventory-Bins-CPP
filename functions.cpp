#include "header.h"

/*******************************************************************************
 * FUNCTION displayInventory
 * _____________________________________________________________________________
 * This function takes in an array for struct and the array length ref and outs
 *  its elements.
 *  - returns nothing.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      bin[]     : Array holding structs.
 *      &binNumber: ref length of array.
 *
 * POST-CONDITIONS
 *      prints out array holding structs.
 ******************************************************************************/

void displayInventory(InventoryBin bin[],   // IN - array of struct
                      int &binNumber)       // IN - ref length of array
{
    // PROCESSING - parse through array
    for (int i = 0; i<binNumber; i++)
    {
        // OUTPUT - description of part
        cout << bin[i].partDescription;
        // PROCESSING - formatting
        for(int j = 0; j < (20 - int(bin[i].partDescription.length())); j++)
        {
            cout << " ";
        }
        // PROCESSING - formatting
        for(int k = 0; k < (3 - countDigit(bin[i].numberOfParts)); k++)
        {
            cout << " ";
        }
        // OUTPUT - number of parts
        cout << bin[i].numberOfParts << endl;
    }
}

/*******************************************************************************
 * FUNCTION addItem
 * _____________________________________________________________________________
 * This function takes in an array for struct and the array length ref and adds
 *  a new element to the array.
 *  - returns nothing.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      bin[]     : Array holding structs.
 *      &binNumber: ref length of array.
 *
 * POST-CONDITIONS
 *      adds new element to bin[].
 ******************************************************************************/

void addItem(InventoryBin bin[],    // IN - array of struct
             int &binNumber)        // IN - ref length of array
{
    InventoryBin tempBin;   // INPUT - user enters description and number

    // INPUT & OUTPUT - user enters information
    cout << "\nEnter Part Description: \n";
    cin >> tempBin.partDescription;
    cout << "Number of Parts in the Bin: \n\n";
    cin >> tempBin.numberOfParts;

    // PROCESSING - store user input in next index of array.
    bin[binNumber++] = tempBin;
}

/*******************************************************************************
 * FUNCTION addParts
 * _____________________________________________________________________________
 * This function takes in an array for struct, the array length ref, an int
 *  ammount to add, and a string holding the users selection. The func
 *  compares the user input to each element of the array and adds change to the
 *  matching one.
 *  - returns nothing.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      bin[]     : Array holding structs.
 *      tempInput : User input for selection.
 *      change    : Ammount to add.
 *      &binNumber: ref length of array.
 *
 * POST-CONDITIONS
 *      adds change to numberofparts in specific index.
 ******************************************************************************/

void addParts(InventoryBin bin[],   // IN - array of struct
              string tempInput,     // IN - user entered selection
              int &binNumber,       // IN - ref array length
              int change)           // IN - ammount to add
{
    // PROCESSING - parse through array
    for(int i = 0; i < binNumber; i++)
    {
        // PROCESSING - if user input matches part description
        if(bin[i].partDescription == tempInput)
        {
            // PROCESSING - add change to number of parts
            bin[i].numberOfParts += change;
        }
    }
}

/*******************************************************************************
 * FUNCTION removeParts
 * _____________________________________________________________________________
 * This function takes in an array for struct, the array length ref, an int
 *  ammount to subtract, and a string holding the users selection. The func
 *  compares the user input to each element of the array and subs change to the
 *  matching one.
 *  - returns nothing.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      bin[]     : Array holding structs.
 *      tempInput : User input for selection.
 *      change    : Ammount to add.
 *      &binNumber: ref length of array.
 *
 * POST-CONDITIONS
 *      subtracts change to numberofparts in specific index.
 ******************************************************************************/

void removeParts(InventoryBin bin[],   // IN - array of struct
                 string tempInput,     // IN - user entered selection
                 int &binNumber,       // IN - ref array length
                 int change)           // IN - ammount to add
{
    // PROCESSING - parse through array
    for(int i = 0; i < binNumber; i++)
    {
        // PROCESSING - if user input matches part description
        if(bin[i].partDescription == tempInput)
        {
            // PROCESSING - sub change to number of parts
            bin[i].numberOfParts -= change;
        }
    }
}

/*******************************************************************************
 * FUNCTION countDigit
 * _____________________________________________________________________________
 * This function takes in a number and calculates the number of digits.
 *  - returns number of digits.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      n: a number
 *
 * POST-CONDITIONS
 *      returns the number of digits.
 ******************************************************************************/

int countDigit(int n)   // IN - a number
{
    int count;  // CALC - incrimentor

    count = 0;
    // PROCESSING - return 1 digit for number 0
    if(n==0) return 1;

    // PROCESSING - execute if n isn't 0
    while (n != 0)
    {
        // PROCESSING - divide and incriment
        n /= 10;
        ++count;
    }

    return count;
}
