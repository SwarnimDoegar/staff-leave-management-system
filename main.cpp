#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
using namespace std;

class staff
{
    char name[30], eid[20];
    int exp;
    float salary;
    int special, sick , study, parental, retire;
public:
    staff()
    {
        special=10;
        sick=10;
        study=180;
        parental=90;
        retire=30;
        strcpy(name,"");
        strcpy(eid,"");
        exp=0;
        salary=0;
    }
    char* retEID()
    {
        return eid;
    }
    void show()
    {
        cout<<"\t\t\t************************************************";
        cout<<"\n\t\t\tName: "<<name;
        cout<<"\n\t\t\tEmployee ID: "<<eid;
        cout<<"\n\t\t\tExperience: "<<exp;
        cout<<"\n\t\t\tSalary: "<<salary;
        cout<<"\n\n\t\t\tBALANCE LEAVES...\n";
        cout<<"\t\t\t\tSick leave(s): "<<sick;
        cout<<"\n\t\t\t\tSpecial leave(s): "<<special;
        cout<<"\n\t\t\t\tStudy leave(s): "<<study;
        cout<<"\n\t\t\t\tParental leave(s): "<<parental;
        cout<<"\n\t\t\t\tRetirement leave(s): "<<retire;
        cout<<"\n\t\t\t************************************************\n";
        _getch();
    }
    void setup()
    {
        cout<<"\t\t\t************************************************";
        cout<<"\n\n\t\t\tENTER DETAILS ...\n\n";
        fflush(stdin);
        cout<<"\t\t\tName: ";
        cin.getline(name,30);
        fflush(stdin);
        cout<<"\t\t\tEmployee ID: ";
        cin.getline(eid,20);
        fflush(stdin);
        cout<<"\t\t\tExperience: ";
        cin>>exp;
        cout<<"\t\t\tSalary (per month): ";
        cin>>salary;
        cout<<"\t\t\t************************************************\n";
        _getch();
    }
    void apply()
    {
        int ch, days;

        cout<<"\t\t\t1. Sick Leave\n\t\t\t2. Special Leave\n\t\t\t3. Study leave\n\t\t\t4. Parental leave\n\t\t\t5. Retirement leave\n\n";
        cout<<"\t\t\tYour choice: ";
        cin>>ch;
        cout<<"\t\t\tEnter the number of days: ";
        cin>>days;
        switch(ch)
        {
            case 1: sick-=days;
            break;
            case 2: special-=days;
            break;
            case 3: study-=days;
            break;
            case 4: parental-=days;
            break;
            case 5: retire-=days;
            break;
        }
        _getch();
    }
};


int main()
{
    system("color 0a");
    staff s[100];
    int ch=0;
    int i=0;
    char empid[20];
    cout<<fixed<<setprecision(2);
    cout<<"~~~~~~~~~~~~~ This program manages leaves of up to 100 users ~~~~~~~~~~~~~\n\nPress ENTER to continue...";
    _getch();
    while(ch<4)
    {
        system("cls");
        cout<<"\n\t\t\t---------------------------------------------\n";
        cout<<"\t\t\t\t\t  MAIN MENU\n";
        cout<<"\n\t\t\t---------------------------------------------\n";
        cout<<"\n\n\t\t\t1. ADD USER\n\t\t\t2. APPLY LEAVE\n\t\t\t3. SEE DETAILS\n\t\t\t4. EXIT\n\n";
        cout<<"\t\t\tYour choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            if(i>=100)
            {
                cout<<"Limit Reached!";
                _getch();
                break;
            }
            s[i].setup();
            i+=1;
            break;

            case 2: fflush(stdin);
            cout<<"\n\t\t\tEnter Employee ID: ";
            cin.getline(empid, 20);
            if(i==0)
            {
                cout<<"No entries found";
                _getch();
                break;
            }
            for(int i1=0; i1<i; i1++)
            {
                if(strcmp(s[i1].retEID(),empid)==0)
                {
                    s[i1].apply();
                    break;
                }
            }
            break;
            case 3:
            fflush(stdin);
            cout<<"\n\t\t\tEnter Employee ID: ";
            cin.getline(empid, 20);
            if(i==0)
            {
                cout<<"No entries found";
                _getch();
                break;
            }
            for(int i1=0; i1<i; i1++)
            {
                if(strcmp(s[i1].retEID(),empid)==0)
                {
                    s[i1].show();
                    break;
                }
            }

        }
    }
    return 0;
}
