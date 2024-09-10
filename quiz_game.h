#include<bits/stdc++.h>
#include<conio.h>
#include<C:\oops\Bank Management System\loadquestion.h>
using namespace std;
int quiz()
{
    int correct=0;
    vector<string> question=loading();
    vector<vector<string>> o=options();
    vector<int> ans=anskey();
    int x=0;
    vector<int> arr(26,-1); 
    while(x<100 && correct<10)
    {
        int c = rand() % 25 + 1;
        if(arr[c]==-1)
        {
            arr[c]++;
            cout<<question[c]<<endl;
            cout<<"1 "<<o[c][0]<<endl;
            cout<<"2 "<<o[c][1]<<endl;
            cout<<"3 "<<o[c][2]<<endl;
            cout<<"4 "<<o[c][3]<<endl;
            int ch;
            cout<<"Enter your answer ";
            cin>>ch;
            if(ans[c]==ch)
            {
                cout<<"correct answer!!!"<<endl;
                cout<<"Press enter to load Next question "<<endl;
                correct++;
                char xc=getch();
                system("CLS");
                correct ++;
            }
            else
            {
                cout<<"Oh thats wrong Answer "<<endl;
                cout<<"Correct answer is.."<<o[c][ans[c]-1]<<endl;
                break;
            }
        }
        x++;
    }
    if(correct==10)
    {
        return 15;
    }
    return 2;
}