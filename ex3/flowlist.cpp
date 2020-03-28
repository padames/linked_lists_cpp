//
// Created by pablo on 2020-03-27.
//

#include <iostream>
#include <stdlib.h>
#include <iomanip>

#include "flowlist.h"

using namespace std;

bool operator==(const ListItem& one, const ListItem& other) { (one.year == other.year && one.flow == other.flow)? true: false;}
bool operator<=(const ListItem& one, const ListItem& other) { (one.year <= other.year)? true: false;}
bool operator<(const ListItem& one, const ListItem& other) { (one.year < other.year)? true: false;}
bool operator>(const ListItem& one, const ListItem& other) { (one.year > other.year)? true: false;}

std::ostream& operator<<(std::ostream& os, const ListItem& obj) {
    os << "year: " << obj.year << ", flow: " << obj.flow << endl;
    return os;
}


FlowList::FlowList()
        : headM(nullptr)
{
}

FlowList::FlowList(const FlowList& source)
{
    copy(source);
}

FlowList& FlowList::operator =(const FlowList& rhs)
{
    if (this != &rhs) {
        if (!empty()) destroy();
        copy(rhs);
    }
    return *this;
}

FlowList::~FlowList()
{
    destroy();
}

//int year; double flow;
//while(inFile >> year >> flow) {

//countRecords++;
//}
//cout << setw(24) << "====================================";

void FlowList::print() const
{
    ostringstream ss;
    cout << setw(24) << "===============================" << endl;
    ss.setf(ios_base::left, ios_base::adjustfield);
    ss << setw(10) << "Year" << setw(15) << "Flow (billion m3)" << endl;
    cout << ss.str();
    ss.clear(); ss.str("");
    cout << setw(24) << "===============================" << endl;
    if (headM != nullptr) {
        for (const Node *p = headM->next; p != nullptr; p = p->next) {
            ss << setw(10) << p->item.year << setw(6) << p->item.flow;
            cout << ss.str() << endl;
            ss.clear();
            ss.str("");
        }
    }
    cout << setw(24) << "===============================" << endl;
}

void FlowList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;

    if (headM == nullptr || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != nullptr && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void FlowList::remove(int targetYear)
{
    // if list is empty, do nothing
//    if (headM == nullptr || itemA < headM->item)
//        return;
//
//    Node *doomed_node = nullptr;
//
//    if (itemA == headM->item) {
//        doomed_node = headM;
//        headM = headM->next;
//    }
//    else {
//        Node *before = headM;
//        Node *maybe_doomed = headM->next;
//        while ( nullptr != maybe_doomed && itemA > maybe_doomed->item) {
//            before = maybe_doomed;
//            maybe_doomed = maybe_doomed->next;
//        }
//        if (nullptr != maybe_doomed) {
//            if (itemA == maybe_doomed->item) {
//                doomed_node = maybe_doomed;
//                before->next = maybe_doomed->next;
//            }
//        }
//        // point three
//        if (nullptr != doomed_node) {
//            delete doomed_node;
//        }
//    }
}

bool FlowList::empty() const {
    if (nullptr == headM ) {
        return true;
    }
    return false;
}

void FlowList::destroy()
{
//    cout << "FlowList::destroy was called" << endl;
    if (!empty()) {
        Node* p_this = headM;
        while (nullptr != p_this) {
            Node* p_temp = p_this;
            if (nullptr != p_this->next) {
                p_this = p_this->next;
                delete p_temp;
            } else {
                break;
            }
        }
    }
}

void FlowList::copy(const FlowList& source)
{
    if (!source.empty()) {

        Node* p_other = source.headM;

        headM = new Node;
        Node* p_this = headM;
        p_this->item = p_other->item;

        while (p_other->next != nullptr) {
            p_this->next = new Node;
            p_this = p_this->next;
            p_other = p_other->next;
            p_this->item = p_other->item;
        }
    }
}


