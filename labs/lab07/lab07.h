// Franklin
// SID: 861157376
// Date: 05/22/15

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <set>

using namespace std;

void randomizer(vector<string> & wordVector)
{
    
    for (int i = 0; i < 50000; ++i)
    {
        // cout << "swapping: " << wordVector.at(i) << endl;
        swap(wordVector.at(i), wordVector.at(rand() % 50000));
    }
    
}

float treeInsert(set<string> &SBT, const vector<string> &wordVector, const int n)
{
    clock_t t;
    t = clock();
    
    
    for (int i = 0; i < n; ++i)
    {
        SBT.insert(wordVector.at(i));
    }
    
    t = clock() - t;
    
    return ((float)t) / CLOCKS_PER_SEC;
    
}

float hashInsert(unordered_set<string> &hashTable, const vector<string> &wordVector, const int n)
{
    clock_t t;
    t = clock();
    
    for (int i = 0; i < n; ++i)
    {
        hashTable.insert(wordVector.at(i));
    }
    
    t = clock() - t;
    
    return ((float)t) / CLOCKS_PER_SEC;
}

float treeLookup(set<string> &SBT, const vector<string> &wordVector, const int n)
{
    clock_t t;
    t = clock();
    
    for (int i = 0; i < n; ++i)
    {
        SBT.find(wordVector.at(i));
    }
    
    t = clock() - t;
    
    return (((float)t) / CLOCKS_PER_SEC) / n;
}

float hashLookup(unordered_set<string> &hashTable, const vector<string> &wordVector, const int n)
{
    clock_t t;
    t = clock();
    
    for (int i = 0; i < n; ++i)
    {
        hashTable.find(wordVector.at(i));
    }
    
    t = clock() - t;
    
    return (((float)t) / CLOCKS_PER_SEC) / n;
}