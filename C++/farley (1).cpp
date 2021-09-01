/*
   A metrix adder from aarray and barray into carray and stored there.
 Written by James Farley
 September 2018
 Language: C++
 Compiler: https://www.onlinegdb.com/online_c++_compiler*/

#include <iostream>
using namespace std;

void aarray (int &row,int &col, int &result1);
void barray (int &row,int &col, int &result2);
void carray (int &row,int &col, int &result3);

int main(void)
{
int row, col, err, row2, col2;
int aarry [3][3] = {{1, 2, 4},{ 7, 3, 8}, {11, 12, 10}};
int barry [3][3] = {{2, 4, 6},{ 10, 6, 5}, {4, 3, 2}};
int carry [3][3] = {{0, 0, 0},{ 0, 0, 0}, {0, 0, 0}};
row=0;
col=0;
err=0;
cout<<"Array a \n";for (row=0; row<3; row++){cout<<aarry[row][col]<<" ";cout<<aarry[row][col+1]<<" ";cout<<aarry[row][col+2]<<"\n";}
cout<<"Array b \n";for (row=0; row<3; row++){cout<<barry[row][col]<<" ";cout<<barry[row][col+1]<<" ";cout<<barry[row][col+2]<<"\n";}
for (row=0; row<3; row++){for (col=0; col<3; col++){carry[row][col] = aarry[row][col] + barry[row][col];}}
cout<<"Array c ";for (row=0; row<3; row++){cout<<"\n";for (col=0; col<3; col++){cout<<carry[row][col]<<" ";    }}return 0;}


