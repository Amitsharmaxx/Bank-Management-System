#include<iostream>
#include<random>
using namespace std;
string randompass()
{
    string temp;
    for(register int i=0;i<=10;i++)
    {
        temp+=(char)(rand()%94+32);
    }
    return temp;
}