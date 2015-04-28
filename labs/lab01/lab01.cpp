#include <iostream>
#include <list>
#include <string>

using namespace std;

template<typename T>

/*
PART A
*/

void mergeList(list<T> &list1, list<T> &list2)
{
    typename list<T>::iterator list1Pointer = list1.begin();
    typename list<T>::iterator list2Pointer = list2.begin();
    
    list<T> listCombined;
    
    
    for (typename list<T>::iterator list1Pointer = list1.begin(); list1Pointer != list1.end(); ++list1Pointer)
    {
        listCombined.push_back(*list1Pointer);
        
        if (list2Pointer != list2.end())
        {
            listCombined.push_back(*list2Pointer);
            list2Pointer++;
        }
    }
    
    for (typename list<T>::iterator list2Pointer = list2.begin(); list1Pointer == list1.end() && list2Pointer != list2.end(); ++list2Pointer)
    {
        listCombined.push_back(*list2Pointer);
    }
    
    typename list<T>::iterator listCombinedPtr = listCombined.begin();
    
    for (typename list<T>::iterator listCombinedPtr = listCombined.begin(); listCombinedPtr != listCombined.end(); ++listCombinedPtr)
    {
        cout << *listCombinedPtr << " ";
    }
    
    cout << endl << endl;
}

/*
PART B
*/

template <typename T>

void mergeSortList(list<T> &list1, list<T> &list2)
{
    typename list<T>::iterator list1Pointer = list1.begin();
    typename list<T>::iterator list2Pointer = list2.begin();
    
    list<T> listCombined;
    
    while (list1Pointer != list1.end() && list2Pointer != list2.end())
    {
        if (*list1Pointer < *list2Pointer)
        {
            listCombined.push_back(*list1Pointer);
            list1Pointer++;
        }
        else if (*list1Pointer == *list2Pointer)
        {
            listCombined.push_back(*list1Pointer);
            listCombined.push_back(*list2Pointer);
            list1Pointer++;
            list2Pointer++;
        }
        else
        {
            listCombined.push_back(*list2Pointer);
            list2Pointer++;
        }
    }
    
    while (list1Pointer != list1.end())
    {
        listCombined.push_back(*list1Pointer);
        list1Pointer++;
    }
    
    while (list2Pointer != list2.end())
    {
        listCombined.push_back(*list2Pointer);
        list2Pointer++;
    }
    
    for (typename list<T>::iterator listCombinedPtr = listCombined.begin(); listCombinedPtr != listCombined.end(); ++listCombinedPtr)
    {
        cout << *listCombinedPtr << " ";
    }
    
    cout << endl << endl;
}

template <typename T>

void rotateCounterClockwise(list<T> &myList, int nodes)
{
    typename list<T>::iterator temp = myList.begin();
    
    int j = 0;
    
    for (j = 0; temp != myList.end(); ++j, ++temp)
    {
        
    }
    
    if (nodes > j)
    {
        cout << "ERROR: Cannot rotate that many." << endl;
        return;
    }
    
    for (int i = 1; i <= nodes; ++i)
    {
        temp = myList.begin();
        
        myList.pop_front();
        myList.push_back(*temp);
    }
    
    for (temp = myList.begin(); temp != myList.end(); ++temp)
    {
        cout << *temp << " ";
    }
    cout << endl << endl;
}

int main()
{
    int value = 0;
    list<int> list1;
    
    // list1.push_back(3);
    // list1.push_back(5);
    // list1.push_back(15);
    // list1.push_back(20);
    // list1.push_back(40);
    // list1.push_back(60);
    
    list<int> list2;
    
    // list2.push_back(2);
    // list2.push_back(45);
    // list2.push_back(66);
    // list2.push_back(106);
    // list2.push_back(116);
    
    cout << "Enter your value for list 1. Enter -1 to stop. ";
    while (value != -1)
    {
        cin >> value;
        if (value != -1)
        {
            list1.push_back(value);
        }
    }
    
    cout << endl << "Enter your value for list 2. Enter -1 to stop. ";
    value = 0;
    while (value != -1)
    {
        cin >> value;
        if (value != -1)
        {
            list2.push_back(value);
        }
    }
    
    cout << "Part A: " << endl << endl;
    mergeList(list1, list2);
    
    cout << "Part B: " << endl << endl;
    
    mergeSortList(list1, list2);
    
    cout << "Part C: " << endl;
    cout << "How many nodes to rotate counter-clockwise? ";
    cin >> value;
    
    rotateCounterClockwise(list1, value);
    
    return 0;
}

