// Franklin Yang
// ID: 861157376
// 05/15/15
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <utility>
#include "lab6.h"

using namespace std;



int main()
{
    
    // test case 1
    
    vector<int> test;
    
    
    
    test.push_back(2);
    test.push_back(4);
    test.push_back(5);
    test.push_back(1);
    test.push_back(8);
    test.push_back(9);
    
    // test case 2
    
    // vector<int> test;
    
    
    cout << "pre: ";
    
    for (vector<int>::iterator it = test.begin(); it != test.end(); ++it)
    {
        cout << *it << " ";
    }
    
    cout << endl;
    
    selectionsort(test);
    
    
    cout << "post: ";
    for (vector<int>::iterator it = test.begin(); it != test.end(); ++it)
    {
        cout << *it << " ";
    }
    
    cout << endl;
    
    
    // test case 3
    
    // pair<int, int> pair1(1, 2);
    // pair<int, int> pair2(3,-1);
    // pair<int, int> pair3(-1, 3);
    // pair<int, int> pair4(0, 0);
    // pair<int, int> pair5(2, 3);
    // pair<int, int> pair6(1, 2);
    // pair<int, int> pair7(1, -2);
    // pair<int, int> pair8(8, 10);
    
    
    
    // vector<pair <int, int> > test;
    
    
    // test.push_back(pair1);
    // test.push_back(pair2);
    // test.push_back(pair3);
    // test.push_back(pair4);
    // test.push_back(pair5);
    // test.push_back(pair6);
    // test.push_back(pair7);
    // test.push_back(pair8);
    
    //test case 4
    
    // pair<int, int> pair1(10,2);
    // pair<int, int> pair2(-3,-1);
    // pair<int, int> pair3(-8,0);
    // pair<int, int> pair4(1,1);
    // pair<int, int> pair5(1,1);
    // pair<int, int> pair6(0,0);
    // pair<int, int> pair7(10,2);
    // pair<int, int> pair8(5,5);
    // pair<int, int> pair9(5,-5);
    // pair<int, int> pair10(0,0);
    // pair<int, int> pair11(10,2);
    
    // vector<pair <int, int> > test;
    
    // test.push_back(pair1);
    // test.push_back(pair2);
    // test.push_back(pair3);
    // test.push_back(pair4);
    // test.push_back(pair5);
    // test.push_back(pair6);
    // test.push_back(pair7);
    // test.push_back(pair8);
    // test.push_back(pair9);
    // test.push_back(pair10);
    // test.push_back(pair11);
    
    
    
    
    // test case 5
    
    // pair<int, int> pair1(-1,3);
    // pair<int, int> pair2(0,0); 
    // pair<int, int> pair3(1,-2); 
    // pair<int, int> pair4(1,2);
    // pair<int, int> pair5(1,2);
    // pair<int, int> pair6(2,3); 
    // pair<int, int> pair7(3,-1); 
    // pair<int, int> pair8(8,10);
    
    // vector<pair <int, int> > test;
    
    // test.push_back(pair1);
    // test.push_back(pair2);
    // test.push_back(pair3);
    // test.push_back(pair4);
    // test.push_back(pair5);
    // test.push_back(pair6);
    // test.push_back(pair7);
    // test.push_back(pair8);
    
    // part b test case
    
    // pair<int, int> pair1(3,-1);
    // pair<int, int> pair2(3,-1); 
    // pair<int, int> pair3(3,-1); 
    // pair<int, int> pair4(3,-1);
    // pair<int, int> pair5(3,-1);
    // pair<int, int> pair6(3,-1); 
    // pair<int, int> pair7(3,-1); 
    // pair<int, int> pair8(3,-1);
    
    // vector<pair <int, int> > test;
    
    // test.push_back(pair1);
    // test.push_back(pair2);
    // test.push_back(pair3);
    // test.push_back(pair4);
    // test.push_back(pair5);
    // test.push_back(pair6);
    // test.push_back(pair7);
    // test.push_back(pair8);
    
    // cout << "pre: ";
    
    // for (vector<pair <int, int> >::iterator it = test.begin(); it != test.end(); ++it)
    // {
    //     cout << "(" << (*it).first << "," << (*it).second << ") ";
    // }
    
    // cout << endl;
    
    // cout << "post: ";
    
    // selectionsort(test);
    
    // for (vector<pair <int, int> >::iterator it = test.begin(); it != test.end(); ++it)
    // {
    //     cout << "(" << (*it).first << "," << (*it).second << ") ";
    // }
    
    
    
    
    // cout << endl;
    
    // cout << "0 copies and " << numMoves << " moves" << endl;
    
    return 0;
}