#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;


// #1. 


template <class T> class TwoStackFixed
{
    private:
        T *tsfPointer;
        int maxtop;
        int totalSize;
        
        int countOne;
        // int sizeOne;
        
        int countTwo;
        // int sizeTwo;
    public:
        TwoStackFixed();
        TwoStackFixed(int size, int maxtop);
        ~TwoStackFixed();
        void pushStack1(T value);
        void pushStack2(T value);
        T popStack1();
        T popStack2();
        bool isFullStack1();
        bool isFullStack2();
        bool isEmptyStack1();
        bool isEmptyStack2();
};

template <class T> TwoStackFixed<T>::TwoStackFixed()
{
    cout << "You can't do that. Exiting..." << endl;
    exit(1);
}

template <class T> TwoStackFixed<T>::TwoStackFixed(int size, int maxtop)
{
    if (size < 0)
    {
        size = 0;
    }
    
    if (maxtop > size)
    {
        maxtop = size;
    }
    
    this->maxtop = maxtop;
    tsfPointer = new T [size + 1];
    
    countOne = 0;
    // sizeOne = 0;
    
    countTwo = size + 1;
    // sizeTwo = 0;
    
    totalSize = size;
    
}

template <class T> TwoStackFixed<T>::~TwoStackFixed()
{
    delete tsfPointer;
}

template <class T> void TwoStackFixed<T>::pushStack1(T value)
{
    // if (sizeOne < 0)
    // if (countOne < 1)
    // {
    //     // sizeOne = 0;
    //     // --countOne;
    //     countOne = 1;
    // }
    
    ++countOne;
    
    // cout << "entered pushStack1 with value " << value << endl;
    // cout << "countOne == " << countOne << endl << endl;
    // if (countOne < 0)
    // {
    //     cout << "You can't push anymore. Returning..." << endl;
    //     return;
    // }
    
    if (isFullStack1())
    {
        return;
    }
    
    tsfPointer[countOne] = value;
    
    // ++sizeOne;
}

template <class T> void TwoStackFixed<T>::pushStack2(T value)
{
    // if (sizeTwo < 0)
    // if (countTwo > size)
    // {
    //     // sizeTwo = 0;
    //     // ++countTwo;
    //     countTwo = size;
    // }
    
    --countTwo;
    
    // cout << "entered pushStack2 with value " << value << endl;
    // cout << "countTwo == " << countTwo << endl << endl;
    // if (countTwo > size - 1)
    // {
    //     cout << "You can't push stack2 any more. Returning..." << endl;
    //     return;
    // }
    
    if (isFullStack2())
    {
        return;
    }
    
    tsfPointer[countTwo] = value;
    
    // ++sizeTwo;
}

template <class T> T TwoStackFixed<T>::popStack1()
{
    // if (countOne == -1)
    // if (countOne > maxtop)
    // {
    //     // countOne = 0;
    //     // --sizeOne;
    //     countOne = maxtop;
    // }
    
    --countOne;
    
    // cout << "pop stack1 " << endl;
    // cout << "countOne == " << countOne << endl;
    if (isEmptyStack1())
    {
        cout << "You can't pop stack1 anymore. Exiting..." << endl;
        exit(1);
    }
    
    // ++countOne;
    // --sizeOne;
    return tsfPointer[countOne];
}

template <class T> T TwoStackFixed<T>::popStack2()
{
    // if (countTwo == totalSize)
    // if (countTwo < maxtop)
    // {
    //     // --countTwo;
    //     // --sizeTwo;
    //     countTwo = maxtop + 1;
    // }
    
    ++countTwo;
    
    // cout << "pop stack2" << endl;
    // cout << "countTwo == " << countTwo << endl;
    if (isEmptyStack2())
    {
        cout << "You can't pop stack2 anymore. Exiting..." << endl;
        exit(1);
    }
    // --countTwo;
    // --sizeTwo;
    return tsfPointer[countTwo];
}

template <class T> bool TwoStackFixed<T>::isFullStack1()
{
    if (countOne > maxtop)
    {
        cout << "You can't push stack1 anymore. Returning..." << endl;
        // countOne = 0;
        return true;
    }
    return false;
}

template <class T> bool TwoStackFixed<T>::isFullStack2()
{
    if (countTwo < maxtop + 1)
    {
        cout << "You can't push stack2 any more. Returning..." << endl;
        // countTwo = totalSize - 1;
        countTwo = maxtop;
        return true;
    }
    
    return false;
}

template <class T> bool TwoStackFixed<T>::isEmptyStack1()
{
    if (countOne < 1)
    {
        countOne = 0;
        return true;
    }
    return false;
}

template <class T> bool TwoStackFixed<T>::isEmptyStack2()
{
    if (countTwo > totalSize)
    {
        countTwo = totalSize + 1;
        return true;
    }
    
    return false;
}



// #2.

template <class T2> class TwoStackOptimal
{
    private:
        T2 *tsoPointer;
        int capacity;
        int currentSize;
        int s1;
        int s2;
    public:
        TwoStackOptimal();
        TwoStackOptimal(int size);
        ~TwoStackOptimal();
        void pushFlexStack1(T2 value);
        void pushFlexStack2(T2 value);
        T2 popFlexStack1();
        T2 popFlexStack2();
        bool isFullStack1();
        bool isFullStack2();
        bool isEmptyStack1();
        bool isEmptyStack2();
};

template <class T2> TwoStackOptimal<T2>::TwoStackOptimal()
{
    cout << "You can't do that. Exiting..." << endl;
    exit(1);
}

template <class T2> TwoStackOptimal<T2>::TwoStackOptimal(int size)
{
    tsoPointer = new T2 [size];
    currentSize = 0;
    capacity = size;
    s1 = 0;
    s2 = capacity;
}

template <class T2> TwoStackOptimal<T2>::~TwoStackOptimal()
{
    delete tsoPointer;
}

template <class T2> void TwoStackOptimal<T2>::pushFlexStack1(T2 value)
{
    ++s1;
    ++currentSize;
    
    // cout << "s1: " << s1 << ", currentSize: " << currentSize << endl;
    
    if (isFullStack1())
    {
        cout << "You can't push stack1 anymore. Returning..." << endl;
        return;
    }
    
    // cout << "Afterwards, s1: " << s1 << ", currentSize: " << currentSize << endl;
    
    tsoPointer[s1 - 1] = value;
}

template <class T2> void TwoStackOptimal<T2>::pushFlexStack2(T2 value)
{
    --s2;
    ++currentSize;
    
    // cout << "s2: " << s2 << ", currentSize: " << currentSize << endl;
    
    if (isFullStack2())
    {
        cout << "You can't push stack2 anymore. Returning..." << endl;
        return;
    }
    
    // cout << "Afterwards, s2: " << s2 << ", currentSize: " << currentSize << endl;
    
    tsoPointer[capacity - s2] = value;
}

template <class T2> T2 TwoStackOptimal<T2>::popFlexStack1()
{
    --s1;
    --currentSize;
    
    if (isEmptyStack1())
    {
        cout << "You can't exit stack1 anymore. Exiting..." << endl;
        exit(1);
    }
    
    return tsoPointer[s1];
    
}

template <class T2> T2 TwoStackOptimal<T2>::popFlexStack2()
{
    ++s2;
    --currentSize;
    
    // cout << "popStack2: s2: " << s2 << ", currentSize: " << currentSize << endl;
    
    if (isEmptyStack2())
    {
        cout << "You can't pop stack2 anymore. Exiting..." << endl;
        exit(1);
    }
    
    // cout << "afterwards: s2: " << s2 << ", currentSize: " << currentSize << endl;
    
    return tsoPointer[capacity - s2 + 1];
    
}

template <class T2> bool TwoStackOptimal<T2>::isFullStack1()
{
    if (currentSize > capacity)
    {
        
        currentSize = capacity;
        s1 = currentSize - s2;
        return true;
    }
    
    return false;
}

template <class T2> bool TwoStackOptimal<T2>::isFullStack2()
{
    if (currentSize > capacity)
    {
        
        currentSize = capacity;
        s2 = currentSize - s1;
        return true;
    }
    
    return false;
}

template <class T2> bool TwoStackOptimal<T2>::isEmptyStack1()
{
    if (s1 < 0)
    {
        s1 = -1;
        currentSize = 0;
        return true;
    }
    
    
    return false;
}

template <class T2> bool TwoStackOptimal<T2>::isEmptyStack2()
{
    if (s2 > capacity)
    {
        s2 = s2 - 1;
        currentSize = 0;
        return true;
    }
    
    return false;
}



// #3.

// in order to track the variables A, B, and C, keep track of the base
// addresses
// On first call, get the addresses of all three stacks and associate the name
// with each using some variables. On consequent calls, check for address
// if address matches any of three, display that name.

template <typename T3>
void showTowerStates(int n, stack<T3>& A, stack<T3>& B, stack<T3>& C)
{
    
    static stack<T3> *stkPtrA = &A;
    static stack<T3> *stkPtrB = &B;
    static stack<T3> *stkPtrC = &C;
    
    char p1;
    char p3;
    
    // if (n == 1)
    // {
    //     cout << "Moved " << A.top() << " from peg A to B" << endl;
    //     B.push(A.top());
    //     A.pop();
        
    // }
    // else
    // {
    //     showTowerStates(n - 1, A, C, B);
        
    //     cout << "Moved " << A.top() << " from peg A to B" << endl;
    //     showTowerStates(n - 1, C, B, A);
    // }
    
    char temp;
    
    if (n > 0)
    {
        showTowerStates(n - 1, A, C, B);
        
        temp = A.top();
        A.pop();
        C.push(temp);
        
        // if (&A == stkPtr1)
        // {
        //     cout << "this works. " << endl;
        // }
        // else
        // {
        //     cout << "This does not work. " << endl;
        // }
        
        if (&A == stkPtrA)
        {
            p1 = 'A';
        }
        else if (&A == stkPtrB)
        {
            p1 = 'B';
        }
        else if (&A == stkPtrC)
        {
            p1 = 'C';
        }
        else
        {
            cout << "p1 has not been changed." << endl;
        }
        
        
        
        if (&C == stkPtrA)
        {
            p3 = 'A';
        }
        else if (&C == stkPtrB)
        {
            p3 = 'B';
        }
        else if (&C == stkPtrC)
        {
            p3 = 'C';
        }
        else
        {
            cout << "p2 has not been changed." << endl;
        }
        
        cout << "Moved " << temp << " from peg " << p1 << " to " << p3 << endl;
        showTowerStates(n - 1, B, A, C);
    }
}

template <typename T4>
void displayTower(stack<T4> A)
{
    int count = 0;
    while (!A.empty())
    {
        A.pop();
        ++count;
    }
    
    cout << "count is " << count << endl;
    
}