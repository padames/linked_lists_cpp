 // lab6Ex1.cpp
// 
// ENSF 607 Lab 6 Exercise 1 and 2
//

#include <iostream>
using namespace std;

#include "../common/OLList.h"

int main()
{
    cout << "\nPart One: copy" << endl;

    OLList the_list;

    cout << "'the_list'' after creation: " << endl;
    the_list.print();

    cout << "\n(1a) copy of an empty list via 'new_list = the_list;'" << endl;

    OLList new_list = the_list;

    new_list.print();

    cout << "\n(1b) copy of an empty list via 'a_new_list(the_list);'" << endl;

    OLList a_new_list(the_list);

    a_new_list.print();

    cout << "Adding `330` to 'the_list'" << endl;

    the_list.insert(330);

    cout << "\n(2a) copy of an list with only one item via 'new_list = the_list'" << endl;

    new_list = the_list;

    new_list.print();

    cout << "\n(2b) copy of an list with only one item via 'another_new_list(the_list)'" << endl;

    OLList another_new_list(the_list);

    another_new_list.print();

    cout << "Adding more items to `the_list`" << endl;

    the_list.insert(440);
    the_list.insert(220);
    the_list.insert(110);
    cout << "`the_list` after some insertions: " << endl;
    the_list.print();

    cout << "\n(3a) copy of a list with multiple values via yet_another_list = the_list" << endl;

    auto yet_another_list = the_list;

    yet_another_list.print();

    cout << "\n(3b) copy of a list with multiple values via `yet_another_new_list(the_list);``" << endl;

    OLList yet_another_new_list(the_list);
    yet_another_new_list.print();


    cout << "\nPart Two: destroy" << endl;

    cout << "\nRemoving `110 from `the_list`" << endl;

    the_list.remove(110);

    cout << "\nList after removing `110`: " << endl;
    the_list.print();

    cout << "\n`yet_another_new_list` after `the_list was changed" << endl;

    yet_another_new_list.print();

    the_list.remove(550);
    the_list.remove(440);
    cout << "\nthe_list after some more removals: " << endl;
    the_list.print();


    return 0;
}
