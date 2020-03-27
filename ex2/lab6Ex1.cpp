 // lab6Ex1.cpp
// 
// ENSF 607 Lab 6 Exercise 1 and 2
//

#include <iostream>
using namespace std;

#include "OLList.h"

int main()
{
  OLList the_list;

  cout << "List just after creation: ";
  the_list.print();
  the_list.insert(330);
  the_list.insert(440);
  the_list.insert(220);
  the_list.insert(110);
  cout << "List after some insertions: ";
  the_list.print();
  the_list.remove(110);
  cout << "List after removing from head: ";
  the_list.print();
  the_list.remove(550);
  the_list.remove(440);
  cout << "List after some more removals: ";
  the_list.print();

  return 0;
}
