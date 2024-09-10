#include<iostream>
#include<C:\oops\Bank Management System\numberguess.h>
#include<C:\oops\Bank Management System\tictactoe.h>
#include<C:\oops\Bank Management System\quiz_game.h>
using namespace std;
int gamingport()
{
    int rtr=0;
    cout<<"1-Tic Tac toe"<<endl;
    cout<<"2- Guessing number "<<endl;
    cout<<"3- Quiz Game "<<endl;
    cout<<"4- Exit"<<endl;
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:
            rtr=playtictactoe();
            break;
        case 2:
            numberguessing();
            break;
        case 3:
            rtr=quiz();
        case 4:
            break;
        default:
            cout<<"Enter Valid Option "<<endl;
            break;
    }
    return rtr;
}