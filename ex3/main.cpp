#include <iostream>
#include "hydro.h"

using namespace std;


int main() {
    Hydro hydro = Hydro();
    hydro.displayHeader();
    int numRecords = hydro.readData();
    if (numRecords > 0) {
        int quit = 0;
        while (true) {
            switch (hydro.menu()) {
                case 1:
                    hydro.displayListAverageMedian();
                    hydro.callPressEnter();
                    break;
                case 2:
                    hydro.addData();
                    hydro.callPressEnter();
                    break;
                case 3:
                   hydro.saveData();
                   hydro.callPressEnter();
                   break;
                case 4:
                   hydro.removeData();
                   hydro.callPressEnter();
                   break;
                case 5:
                    cout << "\nProgram terminated!\n\n";
                    quit = 1;
                    break;
                default:
                    cout << "\nNot a valid input.\n";
                   hydro.callPressEnter();
           }
           if (quit == 1) break;
        }
        // Creating a copy of FlowList x called copy1

    } else {
       cout << "\nNo records found, quitting now." << endl;
    }
    return 0;
}
