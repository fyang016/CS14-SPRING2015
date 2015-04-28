//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn05/IntVector.h 
/// @brief Assignment 5 for CS 12 Winter 2015
///
/// @author Franklin Yang [fyang016@ucr.edu]
/// @date 02/14/2015
///
/// @par Enrollment Notes 
///     Lecture Section: 002
/// @par
///     Lab Section: 024
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============

#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef __ASSIGNMENT_H__
#define __ASSIGNMENT_H__

//template<typename T>;
typedef int T;

class IntVector
{
    private:
        unsigned sz, cap;
        int *data;
        
    public:
        IntVector();
        IntVector( unsigned size );
        IntVector( unsigned size, int value );
        unsigned size( ) const;
        unsigned capacity( ) const;
        bool empty( ) const;
        const int & at( unsigned index ) const;
        const int & front() const;
        const int & back() const;
        void expand();
        void expand(unsigned);
        void insert(unsigned index, int value);
        void erase(unsigned index);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned size);
        void resize(unsigned size, int value);
        void reserve(unsigned n);
        void assign(unsigned n, int value);
        int & at(unsigned index);
        int & front();
        int & back();
        
        ~IntVector();
    
};



IntVector::IntVector(): sz(0), cap(0), data(NULL)
{
    
}

IntVector::IntVector( unsigned size ): sz(size), cap(size)
{
    data = new int [size];
    for (unsigned int i = 0; i < size; ++i)
    {
        data[i] = 0;
    }
    
}

IntVector::IntVector( unsigned size, int value ): sz(size), cap(size)
{
    data = new int [size];
    for (unsigned int i = 0; i < size; ++i)
    {
        data[i] = value;
    }
}

unsigned IntVector::size( ) const
{
    return sz;
}

unsigned IntVector::capacity( ) const
{
    return cap;
}

bool IntVector::empty( ) const
{
    bool testEmpty;
    if (sz == 0)
    {
        testEmpty = true;
    }
    else
    {
        testEmpty = false;
    }
    return testEmpty;
}


const int & IntVector::at( unsigned index ) const
{
    if (index > sz)
    {
        exit(1);
    }
    
    return data[index];
}

const int & IntVector::front() const
{
    if (data != NULL)
    {
        cout << "Returning data[0]..." << endl;
        return data[0];
    }
    else
    {
        return 0;
    }
}

const int & IntVector::back() const
{
    if (data != NULL)
    {
        return data[sz - 1];
    }
    else
    {
        return 0;
    }
    
}

void IntVector::expand()
{
    
    cap = cap * 2;
    
    int *data1;
    data1 = new int [cap];
    
    for (unsigned int i = 0; i < sz; ++i)
    {
        data1[i] = data[i];
    }
    
    delete[] data;
    data = data1;
    
}

void IntVector::expand(unsigned amount)
{
    cap = cap + amount;
    
    int *data1;
    data1 = new int [cap];
    
    for (unsigned int i = 0; i < sz; ++i)
    {
        data1[i] = data[i];
    }
    
    delete[] data;
    
    data = data1;
    
}

void IntVector::insert(unsigned index, int value)
{
    
    
    if (index > sz)
    {
        exit(1);
    }
    
    ++sz;
    
    if (sz > cap)
    {
        if (cap != 0)
        {
            expand();
        }
        else
        {
            expand(5);
        }
    }
    
    
    
    // start at last element and end at the element right after index
    for (int i = sz - 1; i >= index + 1; --i)
    {
        data[i] = data[i - 1];
    }
    data[index] = value;
    
}

void IntVector::erase(unsigned index)
{
    if (index >= sz)
    {
        exit(1);
    }
    
    unsigned temp;
    
    // start at index
    for (int i = index; i + 1 < sz; ++i)
    {
        temp = data[index];
        data[index] = data[index + 1];
        data[index + 1] = temp;
    }
    
    --sz;
}

void IntVector::push_back(int value)
{
    if (sz == 0)
    {
        expand(1);
    }
    else if (sz >= cap)
    {
        expand();
    }
    sz++;
    data[sz - 1] = value;
}

void IntVector::pop_back()
{
    if (empty())
    {
        exit(1);
    }
    sz--;
}

void IntVector::clear()
{
    sz = 0;
}

void IntVector::resize(unsigned size)
{
    if (size < sz)
    {
        sz = size;
    }
    else if (size > sz)
    {
        if (size > cap)
        {
            (cap * 2 >= size) ? expand() : expand(size - cap);
        }
        for (int i = sz; i < size; ++i)
        {
            data[i] = 0;
        }
        sz = size;
    }
}

void IntVector::resize(unsigned size, int value)
{
    if (size < sz)
    {
        sz = size;
    }
    else if (size > sz)
    {
        if (size > cap)
        {
            (cap * 2 >= size) ? expand() : expand(size - cap);
        }
        for (int i = sz; i < size; ++i)
        {
            data[i] = value;
        }
        sz = size;
    }
}

void IntVector::reserve(unsigned n)
{
    if (n > cap)
    {
        (cap * 2 >= n) ? expand() : expand(n - cap);
    }
}

void IntVector::assign(unsigned n, int value)
{
    if (n > cap)
    {
        (cap * 2 >= n) ? expand() : expand(n - cap);
    }
    
    sz = n;
    for (int i = 0; i < sz; ++i)
    {
        data[i] = value;
    }
}

int & IntVector::at(unsigned index)
{
    if (index >= sz)
    {
        exit(1);
    }
    else 
    {
        return data[index];
    }
}

int & IntVector::front()
{
    if (data != NULL)
    {
        return data[0];
    }
    else
    {
        exit(1);
    }
}

int & IntVector::back()
{
    if (data != NULL)
    {
        if (sz > 0)
        {
            return data[sz - 1];
        }
        else 
        {
            return data[sz];
        }
    }
    else
    {
        exit(1);
    }
    
}

IntVector::~IntVector()
{
    if (data != 0)
    {
        delete[] data;
    }
    return;
}

#endif