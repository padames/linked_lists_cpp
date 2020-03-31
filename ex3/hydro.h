//
// Created by pablo on 2020-03-27.
//

#ifndef EX3_HYDRO_H
#define EX3_HYDRO_H

#include "list.h"

class Hydro {
public:
    Hydro();
    int readData();
    void displayHeader();
    int menu();
    void displayListAverageMedian();
    void callPressEnter();
    void addData();

private:

    double* calcStats();

    FlowList* flowList;

};
#endif //EX3_HYDRO_H
