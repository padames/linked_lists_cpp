#include <iostream>
#include <fstream>
#include <gmpxx.h>
#include <sstream>
#include <iomanip>
#include "flowlist.h"

using namespace std;

/**
 * present program information to user
 */
void displayHeader() {
    cout << "H-E-F Hydropower Studies – Winter 2020\n"
            "Program: Flow Studies\n"
            "Version: 1.0\n"
            "Lab section: B01\n"
            "Produced by: Pablo Adames\n\n";

    int c = '\0';
    while ( c != '\n' ) {
        cout << "<<< Press Enter to Continue >>>";
        c = fgetc(stdin);
    }
}

/**
 * populate the flow list with data from file
 * @param x a <code>FlowList</code> object
 * @return number of records found in file and read to list
 */
int readData(FlowList* values) {
    string fileName = "../../data/flow.txt";
    ifstream inFile(fileName);
    int countRecords=0;
    if (!inFile) {
        cerr << "Could not open file '" << fileName << "'.";
    } else {
        int year; double flow;
        while(inFile >> year >> flow) {
            auto temp = new ListItem;
            temp->year = year;
            temp->flow = flow;
            values->insert(*temp);
            countRecords++;
        }
    }
    return countRecords;
}

/**
 * Capture the user choice
 * @return the user's choice
 */
int menu(){


    return 5;
}


int main() {
   FlowList* flowList = new FlowList();
   displayHeader();
   int numRecords = readData(flowList);
   flowList->print();
   if (numRecords > 0) {
       cout << "\n" << numRecords << " records read in memory." << endl;
       int quit = 0;
       while (true) {
           switch (menu()) {
               case 1:
                   //              call display function;
                   //              call pressEnter;
                   break;
               case 2:
                   //              call addData function
                   //              call pressEnter;
                   break;
               case 3:
                   //              call saveData function;
                   //              call pressEnter;
                   break;
               case 4:
                   //                call removeData
                   //                call presenter;
                   break;
               case 5:
                   cout << "\nProgram terminated!\n\n";
                   quit = 1;
                   break;
               default:
                   cout << "\nNot a valid input.\n";
                   //              pressEnter();
           }
           if (quit == 1) break;
       }
       // Creating a copy of FlowList x called copy1
   } else {
       cout << "\nNo records found, quitting now." << endl;
   }
   return 0;
}
