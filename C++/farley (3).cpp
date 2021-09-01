/*
A program thats finds the prime factor of a number using stacks.
Written by James Farley
November 2018
Language: C++
Compiler: Code:blocks
*/
#include <iostream>
using namespace std;
#include "Stack.h"
#include "Stack.cpp"

int main(void)
{
    int num;
    int con;
    Stack a;

	cout<<"Enter a positive number to get its prime factor:";
            cin >> num;
	if(num<=0)
	{
	cout<<"You entered a negative number and the program will now be terminated.";
	return 0;
	}
	else
	{
	cout<<"\nThe prime factor for "<<num<<" are:";

    for (int i = 2; num != 1; i++)
        while(num%i == 0)
		{
	        a.push(i);
    		num = num/i;
    		con++;
		}
con++;
    while(!a.empty())
    {
     cout << " " << a.top();

     a.pop();
    }
}
cout<<"\n";
return 0;
}
