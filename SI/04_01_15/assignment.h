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
///     TA: <Dingwen Tao>
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

template<typename T>
// typedef int T;

class IntVector
{
    private:
        unsigned sz, cap;
        int *data;
        
    public:
        IntVector(): sz(0), cap(0), data(NULL)
        {
            
        }
        
        IntVector( unsigned size ): sz(size), cap(size)
        {
            data = new T [size];
            for (unsigned int i = 0; i < size; ++i)
            {
                data[i] = T();
            }
            
        }
        
        IntVector( unsigned size, T value ): sz(size), cap(size)
        {
            data = new T [size];
            for (unsigned int i = 0; i < size; ++i)
            {
                data[i] = value;
            }
        }
        
        unsigned size( ) const
        {
            return sz;
        }
        
        unsigned capacity( ) const
        {
            return cap;
        }
        
        bool empty( ) const
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
        
        
        const int & at( unsigned index ) const
        {
            if (index > sz)
            {
                exit(1);
            }
            
            return data[index];
        }
        
        const int & front() const
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
        
        const int & back() const
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
        
        void expand()
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
        
        void expand(unsigned amount)
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
        
        void insert(unsigned index, T value)
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
        
        void erase(unsigned index)
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
        
        void push_back(T value)
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
        
        void pop_back()
        {
            if (empty())
            {
                exit(1);
            }
            sz--;
        }
        
        void clear()
        {
            sz = 0;
        }
        
        void resize(unsigned size)
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
        
        void resize(unsigned size, T value)
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
        void reserve(unsigned n)
        {
            if (n > cap)
            {
                (cap * 2 >= n) ? expand() : expand(n - cap);
            }
        }
        
        void assign(unsigned n, T value)
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
        
        int & at(unsigned index)
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
        
        int & front()
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
        
        
        int & back()
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
        
        ~IntVector()
        {
            if (data != 0)
            {
                delete[] data;
            }
            return;
        }
    
};


#endif