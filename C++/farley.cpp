/*
	Search the numbers from a 3 x 3 matrix mat in rowise order for an entry of a number
	Written by James Farley
	September 2018
	Language: C++
	Compiler: https://www.onlinegdb.com/online_c++_compiler
	Requires: input, array
*/

#include <iostream>

using namespace std;

void input (int &impnum);
void array (int &numr);

int main(void)
{ int row, col, num;
row=3;
col=4;
num=0;

	input (num);
	array (num);
return 0;
}

void input (int &impnum)
{ int numb;
numb=0;

    cout<<"Choose a number from 1 to 12. \n";
cin >> impnum;


    return ;
}

void array (int &numr)
{ int row, col, found;
int arry [3][3] = {{1, 2, 4},{ 7, 3, 8}, {11, 12, 10}};
row=0;
col=0;
found=0;

     for (int row=0; row<3; row++)

		for (int col=0; col<3; col++)
 
		  if (arry[row][col]==numr)

			  found=1, row=3, col=3;
              
		  else

			  found=0;


	  if (found==1)

        cout<<"The number was found.\n";

  else

        cout<<"The number was not found.\n";

        return;
}
