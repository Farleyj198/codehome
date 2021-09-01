/*
 A program that counts consonants in a text file.
 Written by James Farley
 October 2018
 Language: C++
Code Blocks
*/
#include <iostream>
#include <fstream>
using namespace std;
int main(void){    char name [50];    char output[100];    int count;    char checka = 'a';    char checke = 'e';    char checki = 'i';    char checko = 'o';    char checku = 'u';    char checkA = 'A';    char checkE = 'E';    char checkI = 'I';    char checkO = 'O';    char checkU = 'U';    char check0 = ' ';
    ifstream nam;    cout<<"Enter a name of a file you want to open.\n";    cin.getline(name, 50);    count = 0;
    nam.open(name);    if(!nam.is_open())    {        cout<<"No file with that name was found.\n";        return 0;    }    else    {        nam >> output;    }
    for(int i = 0; i < output[i]; ++i)   {        if(checka != output[i])           {        if(checke != output[i])           {        if(checki != output[i])           {        if(checko != output[i])           {        if(checku != output[i])           {        if(checkA != output[i])           {        if(checkE != output[i])           {        if(checkI != output[i])           {        if(checkO != output[i])           {        if(checkU != output[i])           {        if(check0 != output[i])           {++count;}}}}}}}}}}}}cout << "Number of consonants in " << name << " is " << count << "\n";
    return 0;}

