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
#include "lab07.h"

using namespace std;

int main()
{
    srand(1);
    
    
    ifstream inFS;
    string word;
    
    vector<string> wordVector;
    
    cout << "Opening file words.txt." << endl;
    inFS.open("words.txt");
    
    if (!inFS.is_open()) 
    {
        cout << "Could not open file words.txt." << endl;
      
        return 1;
    }
    
    
    
    // Read all of the words into a vector of strings
    while (inFS >> word)
    {
        wordVector.push_back(word);
        // cout << word << endl;
    }
    
    inFS.close();
    
    
    set<string> SBT;
    unordered_set<string> hashTable;
    
    float TItotal = 0.f;
    float HItotal = 0.f;
    float TLtotal = 0.f;
    float HLtotal = 0.f;
    
    int n = 5000;
    
    ofstream outFS;
    
    outFS.open("data.txt");
    
    if (!outFS.is_open()) 
    {
        cout << "Could not open file data.txt." << endl;
        return 1;
    }
    
    for (n = 5000; n <= 50000; n = n + 5000)
    {
        randomizer(wordVector);
        for (int i = 0; i < 10; ++i)
        {
            TItotal += treeInsert(SBT, wordVector, n);
            HItotal += hashInsert(hashTable, wordVector, n);
            TLtotal += treeLookup(SBT, wordVector, n);
            HLtotal += hashLookup(hashTable, wordVector, n);
            
            
            SBT.clear();
            hashTable.clear();
        }
        
        cout << n << " " << TItotal * 100 << ' ' << HItotal * 100 << ' ';
        cout << TLtotal * 100 << ' ' << HLtotal * 100 << endl;
        
        outFS << n << " " << TItotal * 100 << ' ' << HItotal * 100 << ' ';
        outFS << TLtotal * 100 << ' ' << HLtotal * 100 << endl;
        
        TItotal = 0.f;
        HItotal = 0.f;
        TLtotal = 0.f;
        HLtotal = 0.f;
    }
    
    
    
    return 0;
}
