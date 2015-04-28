#ifndef __LAB2_H__
#define __LAB2_H__

#include <iostream>
#include <forward_list>

using namespace std;

// Number 1 part 2
// done?
bool isPrime(int i)
{
    int placeholder = i;
    bool prime = true;
    
    for (int j = 2; j < placeholder; ++j)
    {
        if (i % j == 0 || i <= 1)
        {
            prime = false;
            return prime;
        }
    }
    
    if (i <= 1)
    {
        prime = false;
        return prime;
    }
    
    return prime;
}

// Number 1 part 1
// Write a recursive function to count the number of prime numbers in a numerical
// singly linked list

// done?
int primeCount(forward_list<int> lst )
{
    int count = 0;
    forward_list<int>::iterator traversal = lst.begin();
    
    for (traversal = lst.begin(); traversal != lst.end(); ++traversal)
    {
        if (isPrime(*traversal))
        {
            ++count;
        }
    }
    return count;
}


// Number 3
template <typename Type>

forward_list <Type> listCopy( forward_list <Type> L, forward_list <Type> P)
{
    typename forward_list<Type>::iterator iteratorL = L.begin();
    
    P.clear();
    
    typename forward_list<Type>::iterator iteratorP = P.begin();
    
    
    
    for (iteratorL = L.begin(); iteratorL != L.end(); ++iteratorL)
    {
        // cout << "push_front ing to P with " << *iteratorL << endl;
        P.push_front(*iteratorL);
    }
    
    for (iteratorP = P.begin(); iteratorP != P.end(); ++iteratorP)
    {
        cout << *iteratorP << endl;
    }
    
    return P;
    
}


// Number 4
template <typename Type>

void printLots(forward_list <Type> L, forward_list <int> P)
{
    forward_list<int>::iterator myIteratorPosition;
    typename forward_list<Type>::iterator iteratorL = L.begin();
    
    int count = 0;
    
    for (myIteratorPosition = P.begin(); myIteratorPosition != P.end(); ++myIteratorPosition)
    {
        for (; count <= *myIteratorPosition && iteratorL != L.end(); ++iteratorL, ++count)
        {
            if (count == *myIteratorPosition)
            {
                cout << *iteratorL << endl;
            }
        }
    }
    
}

// Number 2
template <typename Type>

struct Node
{
    Type data;
    Node *next;
    Node( Type data ) : data(data), next(0) {}
};

template <typename Type>

class List
{
    private:
        Node<Type> *head;
        Node<Type> *tail;
    public:
        List<Type>();
        List<Type> elementSwap( List<Type> lst, int pos );
        Type elementPosition(int pos);
        int listSize();
        void push_back(Type value);
};

template <typename Type>
List<Type>::List()
{
    head = 0;
    tail = 0;
}

template <typename Type>

List<Type> List<Type>::elementSwap(List<Type> lst, int pos)
{
    int listSizeVariable = lst.listSize();
    if (listSizeVariable == 0 || listSizeVariable == 1)
    {
        cout << "Nothing to swap." << endl;
        
        // Node<Type> *temp = head;
        // int i = 0;
        // for (i = 0; i < pos && temp != 0; ++i, temp = temp->next)
        // {
        //     cout << "i is " << i << " and temp is " << temp->data << endl;
        // }
        
        // Node<Type> *temp2 = temp->next;
        
        // temp->next = temp2->next;
        // temp2->next = temp;
        return lst;
    }
    else if (listSizeVariable == 2 && pos == 0)
    {
        Node<Type> *temp = lst.head;
        Node<Type> *temp2 = lst.tail;
        temp2->next = temp;
        temp->next = 0;
        
        return lst;
    }
    else if (pos + 1 > listSize() - 1)
    {
        cout << "Cannot swap. The requested position is the last." << endl;
        
        return lst;
    }
    
    if (pos > 0)
    {
        
        Node<Type> *temp = head;
        int i = 0;
        for (i = 0; i < pos - 1 && temp != 0; ++i, temp = temp->next)
        {
            cout << "i is " << i << " and temp is " << temp->data << endl;
        }
        
        
        Node<Type> *temp2 = temp->next;
        Node<Type> *temp3 = temp2->next;
        
        temp->next = temp3;
        temp2->next = temp3->next;
        temp3->next = temp2;
    }
    else if (pos == 0)
    {
        Node<Type> *temp = head;
        Node<Type> *temp2 = temp->next;
        Node<Type> *temp3 = temp2->next;
        
        temp->next = temp3;
        temp2->next = temp;
        head = temp2;
    }
    else
    {
        cout << "Position is negative. Swapping will not take place." << endl;
    }
    
    
    
    return lst;
}

template <typename Type>

Type List<Type>::elementPosition(int pos)
{
    Node<Type> *temp = head;
    
    if (pos < 0)
    {
        cout << "Position is negative. Setting position to 0..." << endl;
    }
    
    int i = 0;
    
    for (i = 0; i < pos && temp->next != 0; ++i, temp = temp->next)
    {
        // cout << "i is " << i << " and temp is " << temp->data << endl;
    }
    
    if (i < pos)
    {
        cout << "Position is greater than max. Returning max position." << endl;
    }
    
    return temp->data;
}

template <typename Type>
int List<Type>::listSize()
{
    Node<Type> *temp = head;
    int i = 0;
    
    for (i = 0; temp != 0; temp = temp->next, ++i)
    {
        cout << "i for the listSize() is " << i << endl;
    }
    return i;
}

template <typename Type>

void List<Type>::push_back(Type value)
{
    Node<Type> *temp = new Node<Type>(value);
    
    // if the list is EMPTY
    if (head == 0)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        
        tail = tail->next;
    }
    
}

#endif