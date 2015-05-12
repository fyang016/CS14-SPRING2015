// Franklin Yang
// SID: 861157376
// 05/10/15

#ifndef LAB5_H
#define LAB5_H
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
using namespace std;
// #define Value     int
#define nil 0

template < typename Value >
class BST {
    
    class Node { // binary tree node
        public:
            Node* left;
            Node* right;
            
            bool selected = false;
            
            
            Value value;
            Node( const Value v = Value() )
                : value(v), left(nil), right(nil) {}
            Value& content() { return value; }
            bool isInternal() { return left != nil && right != nil; }
            bool isExternal() { return left != nil || right != nil; }
            bool isLeaf() { return left == nil && right == nil; }
            int height() 
            {
                // returns the height of the subtree rooted at this node
                
                return height(this);
            }
            
            int height(Node *p) const
            {
                if (p == nil)
                {
                    return -1;
                }
                
                int maxHeight = 0;
                
                int leftHeight = height(p->left);
                int rightHeight = height(p->right);
                
                
                if (leftHeight <= rightHeight)
                {
                    maxHeight = rightHeight;
                }
                else
                {
                    maxHeight = leftHeight;
                }
                return  maxHeight + 1;
            }
            
            
            int size() 
            {
                // returns the size of the subtree rooted at this node,
                
                int nodeCount = 0;
                
                Node *current;
                Node *pre;
                
                if (this == nil)
                {
                    // cout << "root == nil" << endl;
                    return nodeCount;
                }
                
                current = this;
                while (current != nil)
                {
                    // cout << "current != nil" << endl;
                    if (current->left == nil)
                    {
                        // cout << "current->left == nil" << endl;
                        
                        ++nodeCount;
                        current = current->right;
                    }
                    else
                    {
                        // cout << "current->left != nil" << endl;
                        pre = current->left;
                        while(pre->right != nil && pre->right != current)
                        {
                            // cout << "pre->right != nil && pre->right != current" << endl;
                            
                            pre = pre->right;
                        }
                        
                        if (pre->right == nil)
                        {
                            // cout << "pre->right == nil" << endl;
                            pre->right = current;
                            current = current->left;
                        }
                        else
                        {
                            // cout << "pre->right != nil" << endl;
                            pre->right = nil;
                            ++nodeCount;
                            current = current->right;
                        }
                    }
                }
                return nodeCount;
            }
    }; // Node


    // const Node* nil; // later nil will point to a sentinel node.
    Node* root;
    int count;
    int minimumCover;
    int selectedNum;
    
    public:
        int size() 
        {
            // size of the overall tree.
            count = 0;
            
            Node *current;
            Node *pre;
            
            if (root == nil)
            {
                // cout << "root == nil" << endl;
                return count;
            }
            
            current = root;
            while (current != nil)
            {
                // cout << "current != nil" << endl;
                if (current->left == nil)
                {
                    // cout << "current->left == nil" << endl;
                    
                    ++count;
                    current = current->right;
                }
                else
                {
                    // cout << "current->left != nil" << endl;
                    pre = current->left;
                    while(pre->right != nil && pre->right != current)
                    {
                        // cout << "pre->right != nil && pre->right != current" << endl;
                        
                        pre = pre->right;
                    }
                    
                    if (pre->right == nil)
                    {
                        // cout << "pre->right == nil" << endl;
                        pre->right = current;
                        current = current->left;
                    }
                    else
                    {
                        // cout << "pre->right != nil" << endl;
                        pre->right = nil;
                        ++count;
                        current = current->right;
                    }
                }
            }
            
            return count;
        }
        bool empty() { return size() == 0; }
        void print_node( const Node* n ) 
        {
            // Print the node’s value.
            cout << "Node's value: " << n->value << endl;
        }
        
        bool search ( Value x ) 
        {
            // search for a Value in the BST and return true if it was found.
            
            Node *current = root;
            while (current != nil)
            {
                if (x > current->value)
                {
                    // cout << "x is greater than the current value." << endl;
                    current = current->right;
                    
                }
                else if (x < current->value)
                {
                    // cout << "x is less than the current value. " << endl;
                    current = current->left;
                }
                else if (x == current->value)
                {
                    // cout << "x is equal to the current value. " << endl;
                    cout << "The value was found. " << endl;
                    return true;
                }
                else
                {
                    // cout << "There is something wrong with the code." << endl;
                    return false;
                }
            }
            
            cout << "The value was not found." << endl;
            
            return false;
        }
        void preorder()const 
        {
            // Traverse and print the tree one Value per line in preorder.
            preorder(root);
            
        }
        
        void preorder(Node *p) const
        {
            if (p != nil)
            {
                cout << p->value << endl;
                preorder(p->left);
                preorder(p->right);
            }
        }
        
        // Lab 5 part 1
        void displayMinCover()
        {
            cout << "Part 1" << endl;
            
            selectedNum = 0;
            
            displayMinCover(root);
            
            cout << endl << selectedNum << endl;
        }
        
        
        // Lab 5 part 1
        void displayMinCover(Node *p)
        {
            if (p != nil)
            {
                if (p->selected == true)
                {
                    cout << p->value << " ";
                    ++selectedNum;
                }
                displayMinCover(p->left);
                displayMinCover(p->right);
            }
        }
        
        // Lab 5 part 1
        void minCover() const
        {
            minCover(root);
            
        }
        
        // Lab 5 part 1
        void minCover(Node *p)const
        {
            
            
            if (p != nil)
            {
                
                minCover(p->left);
                minCover(p->right);
                
            }
            
            
            
            
            if (p == nil)
            {
                return;
            }
            if (p->left == nil && p->right == nil)
            {
                // cout << "Phase 0 " << endl;
                p->selected = false;
                return;
            }
            
            p->selected = false;
            // cout << "p->left, p->right" << endl;
            // cout << p->left << " " << p->right << endl;
            
            // cout << "Entering Phase 1.0" << endl;
            
            
            if (p->left != nil)
            {
                
                if (p->left->isLeaf())
                {
                    p->selected = true;
                }
            }
            else
            {
                p->selected = false;
            }
            if (p->right != nil)
            {
                if (p->right->isLeaf() || p->selected == true)
                {
                    p->selected = true;
                }
            }
            else
            {
                p->selected = false;
            }
            
            
            
            // cout << "Entering Phase 2" << endl;
            // if (p->left->selected == true || p->right->selected == true)
            // {
            //     cout << "Phase 2" << endl;
            //     return;
            // }
            
            
            if (p->left != nil)
            {
                // cout << "p->left" << endl;
                if (p->left->selected == true)
                {
                    
                    // cout << "p->left->selected" << endl;
                    // cout << "Phase 2" << endl;
                    return;
                }
            }
            if (p->right != nil)
            {
                if (p->right->selected == true)
                {
                    // cout << "Phase 2" << endl;
                    return;
                }
            }
            
            
        }
        
        
        
        // DFS(node x) 
        // {
        //     mark x as visited;
        //     while(y = x.getChildren() != NULL) {
        //             if(y is not marked visited) {
        //             /* if child is not selected as a vertex for minimum selected cover then
        //             select the parent */
        //                 if(y is not selected) {
        //                     mark x selected
        //             }
        //         }
        //     }
        // }
        
        void postorder()const 
        {
            // Traverse and print the tree one Value per line in postorder.
            
            postorder(root);
        }
        
        void postorder(Node *p) const
        {
            if (p != nil)
            {
                postorder(p->left);
                postorder(p->right);
                cout << p->value << endl;
            }
        }
        
        void inorder()const 
        {
            // Traverse and print the tree one Value per line in inorder.
            
            inorder(root);
            
        }
        
        void inorder(Node *p) const
        {
            
            if (p != nil)
            {
                inorder(p->left);
                cout << p->value << endl;
                inorder(p->right);
            }
        }
        
        Value& operator[] (int n) 
        {
            // returns reference to the value field of the n-th Node.
            // FILL IN
            
            cout << "You called the operator. How do you do?" << endl;
            
            // e.g. index 0 returns 1 for this test tree and 
            // index 1 returns 2 for this test tree
            
            int nodeCount = 0;
                
            Node *current;
            Node *pre;
            
            if (root == nil)
            {
                // cout << "root == nil" << endl;
                return root->value;
            }
            
            current = root;
            while (current != nil && nodeCount - 1 != n)
            {
                // cout << "current != nil" << endl;
                if (current->left == nil && nodeCount - 1 != n)
                {
                    // cout << "current->left == nil" << endl;
                    
                    ++nodeCount;
                    if (nodeCount - 1 != n)
                    {
                        current = current->right;
                    }
                    
                }
                else if (current->left != nil && nodeCount - 1 != n)
                {
                    // cout << "current->left != nil" << endl;
                    pre = current->left;
                    while(pre->right != nil && pre->right != current && nodeCount - 1 != n)
                    {
                        // cout << "pre->right != nil && pre->right != current" << endl;
                        
                        pre = pre->right;
                    }
                    
                    if (pre->right == nil && nodeCount - 1 != n)
                    {
                        // cout << "pre->right == nil" << endl;
                        pre->right = current;
                        current = current->left;
                    }
                    else if (pre->right != nil && nodeCount - 1 != n)
                    {
                        // cout << "pre->right != nil" << endl;
                        pre->right = nil;
                        ++nodeCount;
                        
                        if (nodeCount - 1 != n)
                        {
                            current = current->right;
                        }
                        
                    }
                }
            }
            return current->value;
        }
        BST() : count(0), root(nil) {}
        
        void insert( Value X ) { root = insert( X, root ); }
        
        Node* insert( Value X, Node* T ) 
        {
            // The normal binary-tree insertion procedure ...
            if ( T == nil ) {
                T = new Node( X ); // the only place that T gets updated.
            } else if ( X < T->value ) {
                T->left = insert( X, T->left );
            } else if ( X > T->value ) {
                T->right = insert( X, T->right );
            } else {
                T->value = X;
            }
            // later, rebalancing code will be installed here

            return T;
        }
        void remove( Value X ) { root = remove( X, root ); }
        
        Node* remove( Value X, Node*& T ) 
        {
            // The normal binary-tree removal procedure ...
            // Weiss’s code is faster but way more intricate.
            if ( T != nil ) 
            {
                if ( X > T->value ) 
                {
                    T->right = remove( X, T->right );
                } 
                else if ( X < T->value ) 
                {
                    T->left = remove( X, T->left );
                } 
                else 
                { // X == T->value
                    if ( T->right != nil ) 
                    {
                        Node* x = T->right;
                        while ( x->left != nil ) x = x->left;
                        T->value = x->value; // successor’s value
                        T->right = remove( T->value, T->right );
                    } 
                    else if ( T->left != nil ) 
                    {
                        Node* x = T->left;
                        while ( x->right != nil ) x = x->right;
                        T->value = x->value; // predecessor’s value
                        T->left = remove( T->value, T->left );
                    } 
                    else 
                    { // *T is external
                        delete T;
                        T = nil; // the only updating of T
                    }
                }
            }
    
            // later, rebalancing code will be installed here
            
            return T;
        }
    
        void okay( ) { okay( root ); }
        
        void okay( Node* T ) 
        {
            // diagnostic code can be installed here
            return;
        }
        
        Node* getRoot()
        {
            return root;
        }
        
        // Lab 5 PART 2
        void findSumPath(Node *n, int sum, int buffer[])
        {
            cout << "Part 2 " << endl;
            
            bool good = false;
            
            int counter = 0;
            
            findSumPath(n, counter, sum, buffer, good);
            
            cout << endl;
        }
        
        void findSumPath(Node *n, int counter, int sum, int buffer[], bool good)
        {
            
            int check = 0;
            
            if (n != nil)
            {
                *(buffer + counter) = n->value;
                // cout << "counter: " << counter << endl;
                // cout << "buffer + counter " << *(buffer + counter) << endl;
                
                findSumPath(n->left, counter + 1, sum, buffer, good);
                
                
                
                if (n->isLeaf())
                {
                    for (int h = counter; h >= 0; --h)
                    {
                        check += *(buffer + h);
                    }
                    
                    if (check == sum)
                    {
                        
                        good = true;
                    }
                    
                    // cout << "n is a leaf, and counter is " << counter << " and variable is " << *(buffer + counter) << endl;
                    
                    if (check == sum)
                    {
                        for (int h = counter; h >= 0; --h)
                        {
                            cout << *(buffer + h) << " ";
                        }
                    }
                }
                
                findSumPath(n->right, counter + 1, sum, buffer, good);
            }
        }
        
        
        
        // Lab 5 PART 3
        void vertSum(Node* node, int hd, std::map<int, int> &m) const
        {
            cout << "Part 3" << endl;
            
            int min = 0;
            int max = 0;
            
            vertSum(node, hd, m, min, max);
            
            
            for (int i = min; i <= max; ++i)
            {
                cout << m[i] << " ";
            }
            
            cout << endl;
        }
        
        void vertSum(Node* node, int hd, std::map<int, int> &m, int &min, int& max) const
        {
            if (node != nil)
            {
                vertSum(node->left, hd - 1, m, min, max);
                m[hd] += node->value;
                if (hd < min && m[hd] > 0)
                {
                    min = hd;
                }
                if (hd > max && m[hd] > 0)
                {
                    max = hd;
                }
                // cout << m[hd] << endl;
                vertSum(node->right, hd + 1, m, min, max);
            }
        }
        
}; // BST




#endif