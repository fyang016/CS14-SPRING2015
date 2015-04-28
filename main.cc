#include <iostream>
#include <stack>
#include <cstdlib>
#include "lab3.h"
using namespace std;

int main()
{
    // int inputSize = 0;
    // int inputMaxTop = 0;
    
    // cout << "TwoStackFixed: " << endl;
    // cout << "Please enter the size of the array: ";
    // cin >> inputSize;
    
    // cout << "Please enter the size of the max top: ";
    // cin >> inputMaxTop;
    
    // TwoStackFixed<int> asdf(inputSize, inputMaxTop);
    
    // asdf.pushStack1(5);
    // asdf.pushStack1(4);
    // asdf.pushStack1(3);
    // asdf.pushStack1(2);
    // asdf.pushStack1(1);
    // asdf.pushStack1(1);
    // asdf.pushStack1(1);
    // asdf.pushStack1(1);
    
    // asdf.pushStack2(5);
    // asdf.pushStack2(4);
    // asdf.pushStack2(3);
    // asdf.pushStack2(2);
    // asdf.pushStack2(1);
    
    // cout << asdf.popStack1() << endl;
    // cout << asdf.popStack1() << endl;
    // cout << asdf.popStack1() << endl;
    // cout << asdf.popStack1() << endl;
    // cout << asdf.popStack1() << endl;
    
    // cout << asdf.popStack2() << endl;
    // cout << asdf.popStack2() << endl;
    // cout << asdf.popStack2() << endl;
    // cout << asdf.popStack2() << endl;
    // cout << asdf.popStack2() << endl;
    
    // cout << "TwoStackOptimal: " << endl;
    // cout << "Please enter the size of the array: ";
    // cin >> inputSize;
    
    // TwoStackOptimal<int> asdf2(5);
    
    // asdf2.pushFlexStack1(8);
    // asdf2.pushFlexStack1(7);
    // asdf2.pushFlexStack1(6);
    // asdf2.pushFlexStack1(5);
    // asdf2.pushFlexStack1(8);
    // asdf2.pushFlexStack1(8);
    // asdf2.pushFlexStack1(8);
    
    // asdf2.pushFlexStack2(7);
    // asdf2.pushFlexStack2(6);
    // asdf2.pushFlexStack2(5);
    // asdf2.pushFlexStack2(4);
    
    // cout << asdf2.popFlexStack1() << endl;
    // cout << asdf2.popFlexStack1() << endl;
    // cout << asdf2.popFlexStack1() << endl;
    // cout << asdf2.popFlexStack1() << endl;
    // cout << asdf2.popFlexStack1() << endl;
    
    // cout << asdf2.popFlexStack2() << endl;
    // cout << asdf2.popFlexStack2() << endl;
    // cout << asdf2.popFlexStack2() << endl;
    // cout << asdf2.popFlexStack2() << endl;
    // cout << asdf2.popFlexStack2() << endl;
    
    
    int n = 3;
    
    
    stack<char> A;
    stack<char> B;
    stack<char> C;
    
    // stack<char> *stkPtr1 = &A;
    // stack<char> *stkPtr2 = &B;
    // stack<char> *stkPtr3 = &C;
    
    A.push('3');
    A.push('2');
    A.push('1');
    
    showTowerStates(n, A, B, C);
    
    // displayTower(A);
    // displayTower(A);
    displayTower(A);
    
    // displayTower(B);
    // displayTower(B);
    displayTower(B);
    
    // displayTower(C);
    // displayTower(C);
    displayTower(C);
    
    
    return 0;
}