//
// Created by pablo on 2020-03-27.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <math.h>
#include "hydro.h"

Hydro::Hydro() {
    flowList = new FlowList();
}

/**
 * populate the flow list with data from file
 * @param x a <code>FlowList</code> object
 * @return number of records found in file and read to list
 */
int Hydro::readData() {
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
            flowList->insert(*temp);
            countRecords++;
        }
    }
    return countRecords;
}

void Hydro::callPressEnter() {
    int c = '\0';
    while ( c != '\n' ) {
        cout << "<<< Press Enter to Continue >>>" << endl;
        c = cin.get();
    }
}

/**
 * present program information to user
 */
void Hydro::displayHeader() {
    cout << "H-E-F Hydropower Studies – Winter 2020\n"
            "Program: Flow Studies\n"
            "Version: 1.0\n"
            "Lab section: B01\n"
            "Produced by: Pablo Adames\n\n";
    callPressEnter();
}

/**
 * Capture the user choice
 * @return the user's choice
 */
int Hydro::menu(){
    ostringstream ss;
    cout << "\nPlease select from the following operations" << endl;
    ss.setf(ios_base::right, ios_base::adjustfield);
    ss << "   1. Display flow list, average, and median" << endl;
    ss << "   2. Add data" << endl;
    ss << "   3. Save data into the file" << endl;
    ss << "   4. Remove data" << endl;
    ss << "   5. Quit" << endl;
    ss << "Enter your choice (1, 2, 3, 4, or 5)" << endl;
    cout << ss.str();
    int selection(0);
    cin >> selection;
    return selection;
}

double* Hydro::calcStats() {
    flowList->reset();
    const Node* c = flowList->cursor();
    int number_entries = flowList->count();
    double sum = 0.0;
    double median(0.0), average(0.0);
    bool oddEntries = (number_entries % 2) > 0;
    int midPoint = number_entries / 2;
    int n(0);
    while (nullptr != c) {
        n++;
        sum += c->item.flow;
        if (n == midPoint) {
            median = flowList->getItem().flow;
        }
        if (n == (midPoint +1) && !oddEntries) {
            median += flowList->getItem().flow;
            median /= 2;
        }
        flowList->forward();
        c = flowList->cursor();
    }
    average = sum / number_entries;
    double* stats = new double[2];
    stats[0] = average;
    stats[1] = median;
    return stats;

}

void Hydro::displayListAverageMedian() {
    if (flowList != nullptr) {
        double* stats = calcStats();
        double average = stats[0];
        double median = stats[1];
        flowList->print();

        cout << "\nThe annual average of the flow is: " <<  (round(average * 10.0 ) / 10.0) << " millions cubic meters.";
        cout << "\nThe median flow is: " <<  (round(median * 10.0 ) / 10.0) << " millions cubic meters." << endl;
    }
}

void Hydro::addData() {
    cout << "Please enter a year: ";
    int year;
    cin >> year;
    cout << "Please enter the flow: ";
    double flow;
    cin >> flow;

    ListItem newData;
    newData.year = year;
    newData.flow = flow;
    int numDataBefore = flowList->count();
    flowList->reset();
    bool duplicateYear = false;
    const Node* c = flowList->cursor();
    while(nullptr!=c) {
        if (year == c->item.year) {
            duplicateYear = true;
            break;
        }
        flowList->forward();
        c = flowList->cursor();
    }
    if (!duplicateYear) {
        flowList->insert(newData);
        cout << "\nNew record inserted successfully." << endl;
    } else {
        cout << "\nError: duplicate data\n";
    }
}

void Hydro::saveData() {
    string fileName = "../../data/flow.txt";
    ofstream outFile(fileName);
    if (!outFile) {
        cerr << "Could not open file '" << fileName << "' for writing.";
    } else {
        ostringstream ss;
        flowList->reset();
        const Node *c = flowList->cursor();
        while(nullptr != c) {
            ss << c->item.year << "      " << c->item.flow << endl;
            outFile << ss.str();
            ss.clear(); ss.str("");
            flowList->forward();
            c = flowList->cursor();
        }
    }
    cout << "\nData saved to file." << endl;
}

void Hydro::removeData() {
    cout << "Please enter the year that you want removed: ";
    int year;
    cin >> year;
    flowList->remove(year);
}