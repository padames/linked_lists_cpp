 // lab6Ex1.cpp
// 
// ENSF 607 Lab 6 Exercise 1 and 2
//

#include <iostream>
using namespace std;

#include "../common/OLList.h"

int main()
{
  OLList the_list;

  cout << "List just after creation: " << endl;
  the_list.print();
  the_list.insert(330);
  the_list.insert(440);
  the_list.insert(220);
  the_list.insert(110);
  cout << "List after some insertions: " << endl;
  the_list.print();
  the_list.remove(110);
  cout << "List after removing from head: " << endl;
  the_list.print();
  the_list.remove(550);
  the_list.remove(440);
  cout << "List after some more removals: " << endl;
  the_list.print();

  cout << endl;
  OLList second_list;

  cout << "Second list just after creation: " << endl;
  second_list.print();
  second_list.insert(330);
  second_list.insert(440);
  second_list.insert(220);
  second_list.insert(550);
  second_list.insert(110);
  cout << "Second list after some insertions: " << endl;
  second_list.print();

  OLList another_list(second_list);
  cout << "Second list just created a new copy" << endl;
  another_list.print();

  cout << "Removed 440 from the copied list" << endl;
  another_list.remove(440);
  another_list.print();

  cout << "original second list:" << endl;
  second_list.print();

  cout << "Creating yet another list with copy operator" << endl;

  OLList a_third_list = another_list;

  a_third_list.print();

  return 0;
}
