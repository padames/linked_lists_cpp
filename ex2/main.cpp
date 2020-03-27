 // lab6Ex2.cpp
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
  the_list.insert(550);
  the_list.insert(110);
  cout << "List after some insertions: " << endl;
  the_list.print();

  OLList another_list(the_list);
  cout << "Just created a new copy" << endl;
  another_list.print();

  cout << "Removed 440 from the copied list" << endl;
  another_list.remove(440);
  another_list.print();

  cout << "original list:" << endl;
  the_list.print();

  cout << "Creating yet another list with copy operator" << endl;

  OLList a_third_list = another_list;

  a_third_list.print();

  return 0;
}
