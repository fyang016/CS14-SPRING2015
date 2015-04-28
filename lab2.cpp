/*
LAB 2
Name: Franklin Yang
SID: 861157376
Date: 04/14/15
*/

#include <iostream>
#include <forward_list>
#include "lab2.h"

using namespace std;

int primeCount(forward_list<int> lst );
bool isPrime(int i);


int main()
{
    forward_list<string> lst1;
    lst1.push_front("a");
    lst1.push_front("b");
    lst1.push_front("c");
    lst1.push_front("d");
    
    forward_list<string> lst2;
    lst2.push_front("I need to do well in CS 14");
    lst2.push_front("I am more afraid of failure than CS 14");
    lst2.push_front("I need to do my best.");
    lst2.push_front("I am Franklin");
    
    lst1 = listCopy(lst2, lst1);
    
    forward_list<int>lst3;
    lst3.push_front(3);
    lst3.push_front(2);
    lst3.push_front(1);
    lst3.push_front(0);
    
    cout << endl;
    
    printLots(lst1, lst3);
    
    cout << endl << endl;
    
    List<char> asdf;
    
    asdf.push_back('h');
    asdf.push_back('g');
    asdf.push_back('w');
    cout << asdf.listSize() << endl;
    
    cout << asdf.elementPosition(0) << endl;
    cout << asdf.elementPosition(1) << endl;
    cout << asdf.elementPosition(2) << endl;
    
    asdf.elementSwap(asdf,1);
    cout << endl << endl;
    cout << asdf.elementPosition(0) << endl;
    cout << asdf.elementPosition(1) << endl;
    cout << asdf.elementPosition(2) << endl;
    
    // printLots(lst2, lst3);
    
    return 0;
}