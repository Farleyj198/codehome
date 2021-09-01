/*

A program that uses a hash class to organize words and to sort them.

Written by James Farley

December 2018

Language: C++

Compiler: https://www.onlinegdb.com/online_c++_compiler

*/

#include <iostream>

#include <vector>

#include <string>

using namespace std;

 

class Hash

{   

   public:

   Hash()

   {

   cout<<"Enter 15 different words\n";     

   cout<<"Word (1):";

   cin>>c;

   for(int i = 0; i < 23; i++)

       {

           b.push_back(1);

       }

   for(int i = 0; i < c.size(); i++)

       {

          b.at(i)=c.at(i);

       }

 

   x=(b.front() + b.back())%23;

       for (i=0;i<=23;i++)

           words.push_back("0");

       x=(b.front()+b.back())%23;

      words.at(x)=c;    

   }

   

   void copy(string c)

   {   

   for(int i=0; i<c.size(); i++)

       {

           b[i]=c.at(i);

       }

       x=(b.front()+b.back())%23;

    if (words.at(x)=="0")

      words.at(x)=c;

  else if (words.at(x)!="0")

  {

      do{   

      i=0;

      if (x>22)

          x=0;

      else

          x++;

      if (words.at(x)=="0")

      {

          words.at(x)=c;

          i++;

      }

          }while (i!=1) ;

  }}

   

   void display()

   {

       for (i=1;i<24;i++)

           cout<<" "<<words[i];

           cout<<"\n";

 

   };

 

   void queue()

   

   {

   string c;

   int v;

   v = 0;

   int e=1;

   while(e!=v)

   {

   cout<<"Enter a word you would like to find:";

   cin>>c;

   int w;

   w=0;

   for (int i = 1; i<words.size(); i++)

       if (c == words[i])

           {w++;}

       if(w!=0)

    {

        cout <<c<< " word was found\n";

    }

       else

    {

        cout <<c<< " word was not found\n";

    }

   w=0;

       cout<<"Do you want to end? (1) for yes,(0) for no:";

   cin>>v;

   }};

   private:

       int i,x;

       vector<string>words;

       vector<int>b;

       string c;

};

 

int main(void)

{

   int z;

   string c;

   Hash a;

   for(z=0;z<14;z++){

   cout<<"Word ("<<z+2<<"):";

   cin>>c;

   a.copy(c);}

   a.display();

   a.queue();

   return 0;

}

