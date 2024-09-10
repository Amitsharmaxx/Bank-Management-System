#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void welcome()
{
    string s1="Divyanshu Katyan";
    string s2="Divyanshu Pal";
    string s3="Presented by-";
    for(int i=0;i<30;i++)
    {
        if(i==0 || i==29)
        {
            for(int j=0;j<82;j++)
            {
                cout<<"*"<<" ";
            }
        }
        else if(i==13)
        {
            for(int j=0;j<82-s1.length();j++)
            {
                if(j==0 || j==81-s1.length())
                {
                    cout<<"*"<<" ";
                }
                else if(j==28)
                {
                    cout<<s3<<"                     ";
                }
                else
                {
                    cout<<"  ";
                }

            } 
        }
        else if(i==14)
        {
            for(int j=0;j<82-s1.length();j++)
            {
                if(j==0 || j==81-s1.length())
                {
                    cout<<"*"<<" ";
                }
                else if(j==30)
                {
                    cout<<s1<<"                  ";
                }
                else
                {
                    cout<<"  ";
                }

            }
        }
        else if(i==15)
        {
            for(int j=0;j<82-s1.length();j++)
            {
                if(j==0 || j==81-s1.length())
                {
                    cout<<"*"<<" ";
                }
                else if(j==30)
                {
                    cout<<s2<<"                     ";
                }
                else
                {
                    cout<<"  ";
                }

            }
        }
        else
        {
            for(int j=0;j<82;j++)
            {
                if(j==0 || j==81)
                    cout<<"*"<<" ";
                else
                {
                    cout<<"  ";
                }
            }
        }
        cout<<"\n";
    }
    cout<<endl;
    for(int i=0;i<64;i++)
    {
        cout<<"  ";
    }
    cout<<"Press Enter to continue........";
    char ch;
    fflush(stdin);
    ch = getch();
}