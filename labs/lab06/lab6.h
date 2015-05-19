// Franklin Yang
// ID: 861157376
// 05/15/15

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int numMoves = 0;

// Question 1

template <typename L>

void selectionsort (L &l)
{
    numMoves = 0;
    
    
    
    // sorting code
    
    typename L::iterator it1 = l.begin();
    typename L::iterator it2 = l.begin();
    
    typename L::iterator min = l.begin();
    
    for (it1 = l.begin(); it1 != l.end(); ++it1)
    {
        // cout << "first for loop" << endl;
        min = it1;
        for (it2 = it1; it2 != l.end(); ++it2)
        {
            // cout << "second for loop" << endl;
            if (*it2 < *min)
            {
                // cout << "*it2 is less than *min" << endl;
                min = it2;
            }
        }
        
        if (*it1 != *min)
        {
            swap(*it1, *min);
            numMoves += 3;
        }
    }
    
}

// Question 2

// part a: Can you give a reason why your selection sort is or
// is not stable?

// My selection sort is stable because it compares two elements
// to see if the former is LESS than the latter.
// If both the former and the latter have the same value, it
// does not switch.
