/*******************************************************************************
 * AUTHOR        : Dillon Welsh, Joe Lung
 * LAB #3        : INVENTORY BINS
 * CLASS         : CS3A
 * SECTION       : 71206
 * DUE DATE      : 09/03/2020
 ******************************************************************************/

#include "header.h"

/*******************************************************************************
 * INVENTORY BINS
 *______________________________________________________________________________
 * Write a program that simulates inventory bins in a warehouse. Each bin holds
 * a number of the same type of parts.
 *______________________________________________________________________________
 * INPUT:
 *  string inputFileName: User enters file name
 *  string tempInput    : String that holds extracted information from file
 *  string menuSelection: String that allows user to select from menu
 *  string addOrSub     : String that allows user to select from menu
 *  int change          : User entered ammount to add or sub by
 *
 * OUTPUT:
 *  InventoryBin bin[]  : Array of structs
 ******************************************************************************/

int main()
{
    InventoryBin bin[30]={};    // CALC & OUT - array of bins
    string inputFileName;       // INPUT - user input inventory file
    string tempInput;           // INPUT - extracted txt from file
    string menuSelection;       // INPUT - user selects from menu
    string addOrSub;            // INPUT - user selects from menu
    int binNumber;              // CALC - index for bin struct array
    int change;                 // INPUT - user ammount to + or - by

    binNumber = 0;

    // INPUT - user enters text file name
    cout << "Enter name of inventory file: \n";
    getline(cin,inputFileName);

    // PROCESSING - initialize ifsream variable to open file
    ifstream inFile;
    inFile.open(inputFileName.c_str());

    // PROCESSING - if file doesn't open
    if(inFile.fail())
    {
        cout << "Error.\n";
    }
    // PROCESSING - if file opens
    else
    {
        // PROCESSING - execute up to end of file
        while(!inFile.eof())
        {
            // PROCESSING - extract line by line save to struct
            getline(inFile,tempInput);
            bin[binNumber].partDescription = tempInput;
            getline(inFile,tempInput);
            stringstream convert(tempInput);
            convert >> bin[binNumber].numberOfParts;
            binNumber++;
        }
        // PROCESSING - close file
        inFile.close();

        // PROCESSING - execute unless user enters q
        do
        {
            // PROCESSING - clear user menu selection
            menuSelection.clear();
            // displayInventory - prints out elements of bin[]
            displayInventory(bin,binNumber);

            // PROCESSING - execute if user doesn't enter correct selection


            do
            {
                // INPUT & OUPUT - menu selection
                cout << endl;
                cout << "Menu:\n" << "Add a new item (a)\n" << "Select a bin (s)\n"
                     << "Quit (q)\n\n" << "Selection: \n";
                getline(cin,menuSelection);
            }while((menuSelection != "a") && (menuSelection != "s") &&
                   (menuSelection != "q"));


            // PROCESSING - q for quit
            if(menuSelection == "q")
            {
                break;
                cout << "Good Bye!!!\n";
            }
            // PROCESSING - a for add
            else if(menuSelection == "a")
            {
                // addItem - adds element to struct array
                addItem(bin, binNumber);
            }
            // PROCESSING - s for select
            else if(menuSelection == "s")
            {
                // INPUT & OUTPUT - menu selection
                cout << "Bin Selection: \n\n";
                getline(cin,tempInput);

                // PROCESSING - execute if user doesn't enter correct selection
                do
                {
                    // INPUT & OUTPUT - menu selection
                    cout << "Menu:\n" << "Add parts (a)\n"
                         << "Remove parts (r)\n\n" << "Selection: \n";
                    getline(cin,addOrSub);

                    if((addOrSub != "r") && (addOrSub!="a")) cout << endl;
                }while((addOrSub != "r") && (addOrSub!="a"));

                // PROCESSING - a for add
                if(addOrSub == "a")
                {
                    // INPUT & OUTPUT - number to add by
                    cout << "Number of parts to add: \n";
                    cin >> change;
                    // addParts - adds user input number to specified item
                    addParts(bin, tempInput, binNumber, change);
                }
                // PROCESSING - r for remove
                else if(addOrSub == "r")
                {
                    // INPUT & OUTPUT - number to sub by
                    cout << "Number of parts to remove: \n";
                    cin >> change;
                    // removeParts - subs user input number to specified item
                    removeParts(bin, tempInput, binNumber, change);
                }
                if(menuSelection!="q") menuSelection.clear();
            }
        }while(menuSelection != "q");
    }

    return 0;
}
