/*

A program thats finds if a word is a palindrome or not.

Written by James Farley

November 2018

Language: C++

Compiler: https://www.onlinegdb.com/online_c++_compiler

*/

 

#include <iostream>

#include <stack>

using namespace std;

 

int main()

{

    stack<char> a;

    string s;

    string r;

    cout << "Enter a word to see if it is a palindrome: ";

   cin >> s;

  

 for(int i = 0; i < s.length(); i++)

 {

  a.push(s.at(i));

 }

 

 while(!a.empty())

 {

  r.push_back(a.top());

  a.pop();

 }

 

 cout<<"The word was "<< s<<" and it's reverse is "<<r<<".\n";

  

   if (s == r)

 {

    cout << s << " is a palindrome.";

 }

    else

 {

    cout << s << " is not a palindrome.";

 }

 return 0;

}
