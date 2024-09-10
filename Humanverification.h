#include<iostream>
#include<string>
using namespace std;
bool captcha()
{
    string temp;
    for(register int i=0;i<=6;i++)
    {
        temp+=(char)(rand()%94+32);
    }
    for(int i=0;i<temp.length()-1;i++)
    {
        cout<<"--";
    }
    cout<<endl;
    cout<<"|  "<<temp<<"  |";
    cout<<endl;
    for(int i=0;i<temp.length()-1;i++)
    {
        cout<<"--";
    }
    string cap;
    cout<<endl;
    cout<<"Enter captcha to verify you are human ";
    cin>>cap;
    if(temp.compare(cap)==0)
    {
        return true;
    }
    return false;
}