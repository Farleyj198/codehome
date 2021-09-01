/*

 

A program that shows the production levels of Rinky Dooflingy Company using STL container.

 

Written by James Farley

 

December 2018

 

Language: C++

 

Compiler: https://www.onlinegdb.com/online_c++_compiler

 

*/

 

#include <iostream>

#include <vector>

#include <algorithm>

 

using namespace std;

 

int main(void)

{

   std::vector<int> b {0,5,3,8,7,2,9,3,5,4,5,6,8,7,3,4,6,5,10,4};

   int c,n,i;

   double average;

   

   n=0;

   i=0;

   c=b[0];

 

   std::cout << "This is the records of products produced over 4 work weeks for the Rinky Dooflingy Company.\n";

   std::cout<<"Day "<<i+1<<" production is "<<b[i]<<"\n";

   std::cout<<"Production level of day "<<i+1<<" has";

   if(c>=0)

   {

       std::cout<<" raised by: ";

   }

   else

   {

       std::cout<<" decreased by: ";

   }

   std::cout<<abs(c)<<".\n";

 

   average=b[i]+average;

   n=n+1;



for(i=1;i<20;i++)

{

   c=b[i]-b[i-1];

   std::cout<<"Day "<<i+1<<" production is "<<b[i]<<"\n";

   std::cout<<"Production level of day "<<i+1<<" has";

   if(c>=0)

   {

       std::cout<<" raised by: ";

   }

   else

   {

       std::cout<<" decreased by: ";

   }

   std::cout<<abs(c)<<".\n";

 

average=b[i]+average;

n=n+1;

}

average=average/n;

std::cout << "\nThe lowest daily production level is:"<<*min_element(b.begin(),b.end())<<"\n";  

std::cout << "The highest daily production level is:"<<*max_element(b.begin(),b.end())<<"\n";

std::cout << "The average daily production level is:"<<average;

 

return 0;}
/*
A program that shows the production levels of Rinky Dooflingy Company using STL container.
Written by James Farley
December 
