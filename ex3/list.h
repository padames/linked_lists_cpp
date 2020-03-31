//
// Created by pablo on 2020-03-27.
//

#ifndef EX3_LIST_H
#define EX3_LIST_H

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

    const ListItem& getItem() const;
    // REQUIRES: cursorM != NULL.
    // PROMISES: returns the item to which cursorM is attached to.


    void reset();
    // PROMISES: cursorM is equal to headM.

    bool isOn() const;
    // PROMISES: returns true if cursorM != NULL, otherwise
    //returns false

    const Node* cursor() const;
    // PROMISES: returns cursorM.

    void forward();
    // PROMISES: if cursorM != NULL, moves cursorM to the next.


    void insert(const ListItem& itemA);
    // PROMISES: A node with a copy of itemA is added in a way
    // that preserves the non-decreasing order of flows
    // in nodes. Then, sets cursorM to NULL.


    void remove(int target_year);
    // PROMISES: If a node has an item matching the
    // target_year, list is unchanged and gives a clear message
    // that the target_year (e.g. 2000) Not Found. Otherwise
    // exactly one node with its item.year == itemA.year is
    // removed. Then, sets cursorM to NULL.

    int count () const;
    // PROMISES: returns the number of nodes in the list.


    void print() const;
    // PROMISES:
    //   Prints items in list on a single line, with commas separating
    //   the items and square brackets marking the ends of the list.
    // NOTE:
    //   This is different from the print function presented in lectures.

    bool empty() const;

private:
    /**
     * always points to the first node in the list.
     */
    Node *headM;

    /**
     * Initially is set to NULL, but it may point to any node.
     */
    Node *cursorM;

    int counter;

    void increaseCounter() {counter++;}
    void decreaseCounter() {counter--;}

    /**
     * Deallocate all nodes, set headM to nullptr.
     */
    void destroy();

    /**
     * this list becomes a copy of source.
     * @param source
     */
    void copy(const FlowList& source);

};

#endif //EX3_LIST_H



