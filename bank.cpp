#include<bits/stdc++.h>
#include <C:\oops\Bank Management System\welcomescreen.h>
#include <C:\oops\Bank Management System\Humanverification.h>
#include <C:\oops\Bank Management System\printhorizontal.h>
#include <C:\oops\Bank Management System\randompassword.h>
#include <C:\oops\Bank Management System\gaming.h>
using namespace std;
class bank;
class customer
{
private:
    string name;
    string lname;
    string acc;
    string d;
    string aadhar;
    string balance="0";
    string username;
    string password;
    string enable="yes";
public:
    customer()
    {
        //donothing
    }
    customer(string n, string n1,int ac, string date, string ad)
    {
        name = n;
        acc = to_string(ac);
        lname=n1;
        d = date;
        aadhar = ad;
    }
    friend bank;
};
class bank
{
    static int i;
    vector<customer> arr;
public:
    void addnew();
    void changepassword();
    void addcash();
    void addcashinside(customer &c);
    void viewaccount();
    void display();
    bool checkpassword(int a, string temp);
    void withdrawl();
    void detail();
    void writingfromfile();
    void writetofile();
    bool checkusername(int a, string temp);
    void deleteacc();
};
bool bank::checkpassword(int a, string temp)
{
    if (arr[a - 1].password == temp)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool bank::checkusername(int a, string temp)
{
    if (arr[a - 1].username == temp)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void bank::deleteacc()
{
    int acno;
    cout << "Enter your account number " << endl;
    cin >> acno;
    if (acno < i)
    {
        cout << "Welcome " << arr[acno - 1].name <<" "<<arr[acno-1].lname<< endl;
        int x = 5;
        while (x)
        {
            string u;
            cout<<"Enter username: ";
            cin>>u;
            if(!checkusername(acno,u))
            {
                cout<<"Wrong username "<<endl;
                x--;
                continue;
            }
            cout << "Enter password: ";
            string temp;
            cin >> temp;
            if (checkpassword(acno, temp) && checkusername(acno,u))
            {
                cout << "Correct password !!!" << endl;
                break;
            }
            else
            {
                cout << "Wrong Password!!!!!" << endl;
            }
            x--;
        }
        if (x == 0)
        {
            cout << "Sorry username/password trial limit Exceed Due to security reasons your account has been blocked for 24 hours" << endl;
            cout << endl;
            return;
        }
        arr[acno-1].enable="no";
        cout<<"Successfully deleted..."<<endl;
    }
    else
    {
        cout << "No such account Exist ";
    }
}
void bank::detail()
{
    int acno;
    cout << "Enter your account number " << endl;
    cin >> acno;
    if (acno < i)
    {
        if((arr[acno-1].enable).compare("yes")!=0)
        {
            cout<<"Your account has been deleted contact bank"<<endl;
            return;
        }
        cout << "Welcome " << arr[acno - 1].name <<" "<<arr[acno-1].lname<< endl;
        int x = 5;
        string u;
        while (x)
        {
            cout<<"Enter username: ";
            cin>>u;
            if(!checkusername(acno,u))
            {
                cout<<"Wrong username "<<endl;
                x--;
                continue;
            }
            else
            {
                break;
            }
        }
        while(x)
        {
            cout << "Enter password: ";
            string temp;
            cin >> temp;
            if (checkpassword(acno, temp) && checkusername(acno,u))
            {
                cout << "Correct password !!!" << endl;
                break;
            }
            else
            {
                cout << "Wrong Password!!!!!" << endl;
            }
            x--;
        }
        if (x == 0)
        {
            cout << "Sorry username/password trial limit Exceed Due to security reasons your account has been blocked for 24 hours" << endl;
            cout << endl;
            return;
        }
        int index = acno - 1;
        printline();
        cout << "name " << arr[index].name << endl;
        cout << endl;
        cout << "Balance " << arr[index].balance << endl;
        cout << endl;
        printline();
    }
    else
    {
        cout << "No such account Exist ";
    }
}
void bank::addnew()
{
    cout << "Enter first name of customer ";
    string n;
    cin >> n;
    cout << "Enter last name of customer ";
    string n2;
    cin>>n2;
    cout << "Enter dob of custmer[DDMMYYYY] " << endl;
    string date;
    cin>>date;
    bool ads=true;
    string a;
    while(ads)
    {
        cout << "Enter aadhar card ";
        cin >> a;
        if(a.length()==12)
        {
            ads=false;
        }
        else
        {
            cout<<"Invalid AAdhaar reenter it"<<endl;
        }
    }
    string u;
    cout<<"Enter your username ";
    cin>>u;
    printline();
    cout << endl;
    cout << "Congrats!!! your Account has been opened......." << endl;
    cout << endl;
    cout << "Your Generated account number is " << i << endl;
    cout << endl;
    cout<<"Your username is "<<u<<endl;
    cout<<endl;
    cout << "Your default password is your dob " << endl;
    cout << endl;
    printline();
    customer c(n,n2, i++, date, a);
    arr.push_back(c);
    arr[i - 2].password = date;
    arr[i-2].username=u;
    cout << "Your account has 0 rupees wannna add some money to it? " << endl;
    cout << endl;
    cout << "press 1 for yes " << endl
         << "press 2 for no" << endl;
    char ch;
    fflush(stdin);
    ch = getch();
    if (ch == '1')
    {
        addcashinside(arr[i - 2]);
    }
    else
    {
        cout << "Ok ,May be next Time......Thankyou for choosing our bank Have a nice Day!!" << endl;
    }
}
void bank::addcashinside(customer &c)
{
    cout << "How much money You want to add?";
    long long money;
    cin >> money;
    int mon=stoi(c.balance);
    mon+= money;
    c.balance=to_string(mon);
    cout << "Balnace as of now: " << c.balance << endl;
}
void bank::withdrawl()
{
    int acno;
    cout << "Enter your account number " << endl;
    cin >> acno;
    if (acno < i)
    {
        if((arr[acno-1].enable).compare("yes")!=0)
        {
            cout<<"Your account has been deleted contact bank"<<endl;
            return;
        }
        cout << "Welcome " << arr[acno - 1].name <<" "<<arr[acno-1].lname<<endl;
        int x = 5;
        string u;
        while (x)
        {
            cout<<"Enter username: ";
            cin>>u;
            if(!checkusername(acno,u))
            {
                cout<<"Wrong username "<<endl;
                x--;
                continue;
            }
            else
            {
                break;
            }
        }
        while(x)
        {
            cout << "Enter password: ";
            string temp;
            cin >> temp;
            if (checkpassword(acno, temp) && checkusername(acno,u))
            {
                cout << "Correct password !!!" << endl;
                break;
            }
            else
            {
                cout << "Wrong Password!!!!!" << endl;
            }
            x--;
        }
        if (x == 0)
        {
            cout << "Sorry username/password trial limit Exceed Due to security reasons your account has been blocked for 24 hours" << endl;
            cout << endl;
            return;
        }
        cout << "Your account balance is " << arr[acno - 1].balance << endl;
        printline();
        cout << "Enter the amount you want to withdrawl " << endl;
        long long money;
        cin >> money;
        if ((stoi(arr[acno - 1].balance)) < money)
        {
            cout << "Insufficient Funds!!!" << endl;
            return;
        }
        long long y=(long long)(stoi(arr[acno-1].balance));
        y=y-money;
        arr[acno - 1].balance = to_string(y);
        cout << "Withdrawl Successful " << endl;
        cout << "Balnace as of now: " << arr[acno - 1].balance << endl;
    }
    else
    {
        cout << "No such account Exist ";
    }
}
void bank::addcash()
{
    int acno;
    cout << "Enter your account number " << endl;
    cin >> acno;
    if (acno < i)
    {
        if((arr[acno-1].enable).compare("yes")!=0)
        {
            cout<<"Your account has been deleted contact bank"<<endl;
            return;
        }
        cout << "Welcome " << arr[acno - 1].name <<" "<<arr[acno-1].lname<< endl;
        int x = 5;
        string u;
       while (x)
        {
            cout<<"Enter username: ";
            cin>>u;
            if(!checkusername(acno,u))
            {
                cout<<"Wrong username "<<endl;
                x--;
                continue;
            }
            else
            {
                break;
            }
        }
        while(x)
        {
            cout << "Enter password: ";
            string temp;
            cin >> temp;
            if (checkpassword(acno, temp) && checkusername(acno,u))
            {
                cout << "Correct password !!!" << endl;
                break;
            }
            else
            {
                cout << "Wrong Password!!!!!" << endl;
            }
            x--;
        }
        if (x == 0)
        {
            cout << "Sorry username/password trial limit Exceed Due to security reasons your account has been blocked for 24 hours" << endl;
            cout << endl;
            return;
        }
        cout << "How much money You want to add? ";
        long long money;
        cin>>money;
        long long y=(long long)(stoi(arr[acno-1].balance));
        y=y+money;
        arr[acno - 1].balance = to_string(y);
        cout << "Deposit Successful " << endl;
        cout << "Balnace as of now: " << arr[acno - 1].balance << endl;
    }
    else
    {
        cout << "No such account Exist ";
    }
}
void bank::writingfromfile()
{
    FILE * fp=fopen("C:\\oops\\Bank Management System\\records.txt","r");
    char ch;
    int count=0;
    string str;
    string na;
    string ln;
    string ac;
    string da;
    string adh;
    string ba;
    string pa;
    string us;
    string en;
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')
        {
            customer c(na,ln,i++, da, adh);
            arr.push_back(c);
            arr[i-2].balance=ba;
            arr[i - 2].password = pa;
            arr[i-2].username=us;
            arr[i-2].enable=en;
            count=0;
            na.clear();
            str.clear();
            continue;
        }
        if(ch!=' ')
        {
            str+=ch-1;
        }
        else if(count==0 && ch==' ')
        {
            na=str;
            str.clear();
            count++;
        }
        else if(count==1 && ch==' ')
        {
            ln=str;
            str.clear();
            count++; 
        }
        else if(count==2 && ch==' ')
        {
            ac=str;
            str.clear();
            count++; 
        }
        else if(count==3 && ch==' ')
        {
            da=str;
            str.clear();
            count++;
        }
        else if(count==4 && ch==' ')
        {
            adh=str;
            str.clear();
            count++;
        }
        else if(count==5 && ch==' ')
        {
            ba=str;
            str.clear();
            count++;
        }
        else if(count==6 && ch==' ')
        {
            us=str;
            str.clear();
            count++;
        }
        else if(count==7 && ch==' ')
        {
            pa=str;
            str.clear();
            count++;
        }
        else if(count==8 && ch==' ')
        {
            en=str;
            str.clear();
            count++;
        }
    }
    if(na.length()!=0)
    {
        customer c(na,ln, i++, da, adh);
        arr.push_back(c);
        arr[i-2].balance=ba;
        arr[i - 2].password = pa;
        arr[i-2].username=us;
    }
}
void bank::display()
{
    for (int index = 0; index < i - 1; index++)
    {
        cout << "name " << arr[index].name << endl;
        cout << endl;
        cout << "account " << arr[index].acc << endl;
        cout << endl;
        cout<<"Username "<<arr[index].username<<endl;
        cout << "password " << arr[index].password << endl;
        cout << endl;
    }
}
void bank::changepassword()
{
    int acno;
    cout << "Enter your account number " << endl;
    cin >> acno;
    if (acno < i)
    {
        if((arr[acno-1].enable).compare("yes")!=0)
        {
            cout<<"Your account has been deleted contact bank"<<endl;
            return;
        }
        cout << "Welcome " << arr[acno - 1].name <<" "<<arr[acno-1].lname<< endl;
        int x = 5;
        string u;
        while (x)
        {
            cout<<"Enter username: ";
            cin>>u;
            if(!checkusername(acno,u))
            {
                cout<<"Wrong username "<<endl;
                x--;
                continue;
            }
            else
            {
                break;
            }
        }
        while(x)
        {
            cout << "Enter password: ";
            string temp;
            cin >> temp;
            if (checkpassword(acno, temp) && checkusername(acno,u))
            {
                cout << "Correct password !!!" << endl;
                break;
            }
            else
            {
                cout << "Wrong Password!!!!!" << endl;
            }
            x--;
        }
        if (x == 0)
        {
            cout << "Sorry username/password trial limit Exceed Due to security reasons your account has been blocked for 24 hours" << endl;
            cout << endl;
            return;
        }
        cout << "press 1-to generate random password " << endl
             << "press 2-to set custom password " << endl;
        fflush(stdin);
        int ch;
        ch = getch();
        if (ch == '1')
        {
            string t = randompass();
            cout << "YOUR NEW PASSWORD IS " << t << endl;
            arr[acno - 1].password = t;
        }
        else
        {
            string custom;
            cout << "enter custom password :";
            cin >> custom;
            arr[acno - 1].password = custom;
        }
    }
    else
    {
        cout << "No such account Exist ";
    }
}
void bank::writetofile()
{
    FILE * fp=fopen("C:\\oops\\Bank Management System\\records.txt","w");
    for(int index=0;index<i-1;index++)
    {
        for(int j=0;j<arr[index].name.length();j++)
        {
            fputc(arr[index].name[j] + 1,fp);
        }
        fputc(' ',fp);
        for(int j=0;j<arr[index].lname.length();j++)
        {
            fputc(arr[index].lname[j] + 1,fp);
        }
        fputc(' ',fp);
        for(int j=0;j<arr[index].acc.length();j++)
        {
            fputc(arr[index].acc[j]+1,fp);
        }
        fputc(' ',fp);
        for(int j=0;j<arr[index].d.length();j++)
        {
            fputc(arr[index].d[j]+1,fp);
        }
        fputc(' ',fp);
        for(int j=0;j<arr[index].aadhar.length();j++)
        {
            fputc(arr[index].aadhar[j] +1,fp);
        }
        fputc(' ',fp);
        for(int j=0;j<arr[index].balance.length();j++)
        {
            fputc(arr[index].balance[j]+1,fp);
        }
        fputc(' ',fp);
        for(int j=0;j<arr[index].username.length();j++)
        {
            fputc(arr[index].username[j]+1,fp);
        }
        fputc(' ',fp);
        for(int j=0;j<arr[index].password.length();j++)
        {
            fputc(arr[index].password[j]+1,fp);
        }
        fputc(' ',fp);
        for(int j=0;j<arr[index].enable.length();j++)
        {
            fputc(arr[index].enable[j]+1,fp);
        }
        fputc(' ',fp);
        char just[5]="just";
        fputs(just,fp);
        fputc('\n',fp);
    }
}
int bank::i = 1;
int main()
{
    int xyz;
    system("CLS");
    welcome();
    system("CLS");
    int c=0;
    while(c<3)
    {
        bool b=captcha();
        if(b)
        {
            cout<<" WELCOME !!!    "<<endl;
            break;
        }
        else
        {
            cout<<"  Invalid captcha!!!  "<<endl;
            c++;
        }
    }
  
    if(c==3)
    {
        cout<<"You have entered captcha wrong 3 times please try again after some time "<<endl;
        char ch;
        cout<<"Press enter to continue.....";
        ch=getch();
        return 0;
    }
    system("CLS");
    printline();
    printline();
    bank b;
    b.writingfromfile();
    bool loop = true;
    while (loop)
    {
        cout << "1- To add new account " << endl
             << endl;
        printline();
        cout << "2- To withdrawl " << endl
             << endl;
        printline();
        cout << "3- To deposit " << endl
             << endl;
        printline();
        cout << "4- Change Password " << endl
             << endl;
        printline();
        cout << "5- CheckBalance " << endl
             << endl;
        printline();
        cout << "6- Waiting Room" << endl
             << endl;
             printline();
        cout << "7 -To exit" << endl<<endl;
        printline();
        printline();
        int ch;
        cout << "Enter your Choice " ;
        cin >> ch;
        system("CLS");
        switch (ch)
        {
        case 1:
            b.addnew();
            break;
        case 2:
            b.withdrawl();
            break;
        case 3:
            b.addcash();
            break;
        case 4:
            b.changepassword();
            break;
        case 5:
            b.detail();
            break;
        case 6:
            xyz=gamingport();
            switch(xyz)
            {
                case 1:
                    cout<<"Woah!! you got it right on the first go you recieve cash reward of 50 "<<endl;
                    cout<<"Pls enter your details and cash details "<<endl;
                    b.addcash();
                    break;
                case 15:
                    cout<<"Woah you answered every question correctly you recieve a cash reward of 1000"<<endl;
                    cout<<"Pls enter your details and cash details "<<endl;
                    b.addcash();
                    break;
                default:
                    break;
            }
            break;
        case 7:
            loop = false;
            cout << "Thank You For coming. Do visit Again !" << endl;
            break;
        default:
            cout << "Please Enter a Valid Option!!! " << endl
                 << endl;
            break;
        }
        fflush(stdin);
        cout<<"Enter to continue ";
        char en=getch();
        system("CLS");
    }
    b.writetofile();
}