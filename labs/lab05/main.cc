// Franklin Yang
// SID: 861157376
// 05/10/15

#include <iostream>
#include <map>
#include "lab5.h"

using namespace std;

int main()
{
    map <int, int> mymap;
    
    BST<int> tree;
    tree.insert(50);
    tree.insert(20);
    tree.insert(10);
    tree.insert(40);
    tree.insert(35);
    tree.insert(45);
    tree.insert(60);
    tree.insert(70);
    
    int arr[tree.size()];
    
    for (int i = 0; i < tree.size(); ++i)
    {
        arr[i] = 0;
    }
    
    // tree.inorder();
    
    tree.minCover();
    
    tree.displayMinCover();
    
    tree.findSumPath(tree.getRoot() , 80, arr);
    
    tree.vertSum(tree.getRoot(), 0, mymap);
    
    return 0;
}