#include <iostream>
#include <string>
using namespace std;

// typedef int T;

template<typename T>
T get_in(T & input, string question)
{
    cout << question;
    
    cin >> input;
    
    return input;
}

int main()
{
    int x = 5;
    get_in(x, "enter a number: ");

    
    string s;
    get_in(s, "What is your name? ");
    cout << s << " " << x << endl;
    return 0;
}