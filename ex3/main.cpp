#include <iostream>
#include <fstream>

#include "FlowList.h"


using namespace std;

void displayHeader() {
    cout << "" << endl;
}

int readData(FlowList x) {

    return 0;
}

int menu(){
    return 5;
}


int main() {
   FlowList x;
   int numRecords;
   displayHeader();
   numRecords = readData(x);
   int quit =0;
   while(true){
       switch(menu()){
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

    return 0;
}
