//
// Created by pablo on 2020-03-27.
//

#ifndef EX3_FLOWLIST_H
#define EX3_FLOWLIST_H

#include <iostream>

using namespace std;

struct ListItem {
    int year;
    double flow; // billions of cubic meters
};

bool operator==(const ListItem& one, const ListItem& other);
bool operator<=(const ListItem& one, const ListItem& other);
bool operator<(const ListItem& one, const ListItem& other);
bool operator>(const ListItem& one, const ListItem& other);

std::ostream& operator<<(std::ostream& os, const ListItem& obj);



struct Node {
    ListItem item;
    Node *next;
};


class FlowList {

public:
    FlowList(); // PROMISES: Creates empty list.
    FlowList(const FlowList& source);
    FlowList& operator =(const FlowList& rhs);
    ~FlowList();

    void insert(const ListItem& itemA);
    // PROMISES:
    //    A node with a copy of itemA is added in
    //    a way that preserves the nonde creasing
    //    order of items in nodes.

    void remove(const ListItem& itemA);
    //  PROMISES:
    //    If no node has an item matching itemA,
    //    list is unchanged.
    //    Otherwise exactly one node with
    //    its item == itemA is removed.

    void print() const;
    // PROMISES:
    //   Prints items in list on a single line, with commas separating
    //   the items and square brackets marking the ends of the list.
    // NOTE:
    //   This is different from the print function presented in lectures.

    bool empty() const;

private:
    Node *headM;
    void destroy();
    // Deallocate all nodes, set headM to zero.

    void copy(const FlowList& source);
    // List becomes copy of source.

};

#endif //EX3_FLOWLIST_H



