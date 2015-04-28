#include <iostream>
#include "assignment.h"

using namespace std;

int main()
{
    IntVector<int> testHarness;
    
    cout << testHarness.size() << endl << endl;
    
    for (int i = 0; i < testHarness.size(); ++i)
    {
        cout << testHarness.at(i) << endl;
    }
    
    
    
    cout << endl << "Size: " << testHarness.size() << endl;
    cout << "Capacity: " << testHarness.capacity() << endl;
    
    cout << endl << "Front: "<< testHarness.front() << endl;
    cout << endl << "Back: " << testHarness.back() << endl;
    
    cout << endl;
    
    testHarness.insert(0, 1);
    testHarness.insert(0, 3);
    testHarness.insert(1, 6);
    testHarness.erase(2);
    
    // testHarness.push_back(89);
    
    // testHarness.pop_back();
    // testHarness.assign(10, 77);
    
    
    cout << "New Capacity: " << testHarness.capacity() << endl;
    cout << "New Size: " << testHarness.size() << endl << endl;
    
    
    
    for (int i = 0; i < testHarness.size(); ++i)
    {
        cout << testHarness.at(i) << endl;
    }
    
    
    return 0;
}