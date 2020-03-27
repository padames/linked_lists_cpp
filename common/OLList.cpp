// OLList.cpp
// ENSF 607  Lab 6 Exercise 1 and 2

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
: headM(nullptr)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != nullptr) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != nullptr; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
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

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == nullptr || itemA < headM->item)
        return;
    
    Node *doomed_node = nullptr;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while ( nullptr != maybe_doomed && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        if (nullptr != maybe_doomed) {
            if (itemA == maybe_doomed->item) {
                doomed_node = maybe_doomed;
                before->next = maybe_doomed->next;
            }
        }
        // point three
        if (nullptr != doomed_node) {
            delete doomed_node;
        }
    }
}

bool OLList::empty() const {
    if (nullptr == headM ) {
        return true;
    }
    return false;
}

void OLList::destroy()
{
//    cout << "OLList::destroy was called" << endl;
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

void OLList::copy(const OLList& source)
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


