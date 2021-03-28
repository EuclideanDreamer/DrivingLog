//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name	: sblogger	*
//*	* 
//* Written by	: Bailey Nichols	*
//*	* 
//* Purpose	: This program was developed to keep records on my vehicle 	* 
//*	  expesnes to file taxes easier.	* 
//*	* 
//* Inputs          : 1,2,3 to choose menu, then enter trip or receipt data. 	* 
//*	* 
//*	* 
//* Calls           : sends data to log/csvfile.csv	* 
//*	*
//*---------------------------------------------------------------------* 
//*	Date	Changed   Rel Ver Mod Purpose	*
//* 03/27/21 Nichols  001.000.000 Initial release of program	*
//*	03/28/21 Nichols  001.100.000* 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//Libreoffice Calc (spreadsheet) data entry with C++
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <sqlite3.h>
#include <fstream>
using namespace std;
void driving(string, string);
void gas(string, string);
void other(string, string);
void meal(string, string);
int main()
{
    cout <<"\nWelcome to the Logger\n"<<endl;
        cout<<"Please enter the first and last name of the person entering data: ";
        string namef;
        string namel;
        cin>> namef;
        cin>> namel;
        char line ='-';
        char menu;
    while (true)
    {
        cout<<setfill('#')<<setw(75)<<"#"<<endl;
        cout <<"\nEnter 1 to submit gas receipts"<<endl;
        cout <<"\nEnter 2 to submit an entry to driving log"<<endl;
        cout <<"\nEnter 3 to submit other business receipts"<<endl;
        cout <<"\nEnter 4 to submit a meal recipt"<<endl;
        cout <<"\nEnter F to exit program"<<endl;
        cin >>menu;
        cout << endl;
        switch (menu){
            case '1':
                //do 1 stuff
                gas(namef, namel);
                break;
            case '2':
                //do 2 stuff
                driving(namef, namel);
                break;
            case '3':
                //do 3 stuff
                other(namef, namel);
                break;
            case '4':
                //do 4 stuff
                meal(namef, namel);
                break;
            case 'F':
                //Quit Program 
                return 0;
                break;
            default:
                menu=' ';
                break;
            
        }
    }
    return 0;
}
void driving(string namef, string namel)
{
    //getting the time for stamp
    time_t t;
    time(&t);
    char *current= ctime(&t);
    cout<<setfill('D')<<setw(75)<<"D"<<endl;
    cout <<"\nWelcome to the Driving Log";
    //prepping file openers
    ofstream otdata;
    otdata.open("log/drivinglog.csv", ios::app);
    cout <<"\nEnter the reason for your trip: ";
    char reason[50];
    cin >>reason;
    cout <<"\nEnter the destination for your trip: ";
    string destination;
    cin >>destination;
    cout <<"\nEnter the starting location for your trip: ";
    string start;
    cin >>start;
    cout <<"\nEnter the milage estimated for your trip: ";
    string milage;
    cin >>milage;
    otdata <<"\n"<<reason <<","<< start <<","<< destination 
    <<","<< milage << "," << ","<< namef << ","<< namel << ","<< current;
    otdata.close();
    return;
}
void gas(string namef, string namel)
{
    char y1, y2;
    string gas;
    string date;
    //getting the time for stamp
    time_t t;
    time(&t);
    char *current= ctime(&t);
    cout<<setfill('G')<<setw(75)<<"G"<<endl;
    cout <<"\nWelcome to the Gas Receipt Log";
    //prepping file openers
    restartgas:
    ofstream otdata;
    otdata.open("log/gasrec.csv", ios::app);
    cout <<"\nEnter the total gas: ";
    cin >> gas;
    cout << "\nIs this from today/right now? enter y/n:";
    cin >> y1;
    if (y1=='y'){
        date=current;
    }
    else{
        cout << "\nEnter the date on the receipt in MM/DD/YYYY format: ";
        cin >> date;
    }
    otdata << "\n" << "gas,"<< gas << ","<< ","<< namef << ","<< namel << ","<< date;
    cout << "\nWould you like to enter more gas recipts? enter y/n: ";
    cin >> y2;
    while (y2=='y'){
        goto restartgas;
    }
    otdata.close();
    return;
}
void other(string namef, string namel)
{
    char c;
    string item;
    char reason[50];
    string total;
    string date;
    //getting the time for stamp
    time_t t;
    time(&t);
    char *current= ctime(&t);
    cout<<setfill('$')<<setw(75)<<"$"<<endl;
    cout <<"\nWelcome to the Receipt Log";
    //prepping file openers
    ofstream otdata;
    otdata.open("log/otherrec.csv", ios::app);
    cout <<"\nEnter the total price: ";
    cin >> total;
    //knowing actual date
    cout << "\nIs this from today/right now? enter y/n:";
    cin >> c;
    if (c=='y'){
        date=current;
    }
    else{
        cout << "\nEnter the date on the receipt in MM/DD/YYYY format: ";
        cin >> date;
    }
    cout << "\nEnter the name of item purchased:";
    cin >>item;
    cout << "\nEnter the reason for purchase:";
    cin >>reason;
    otdata << "\n" << item << ","<< total << "," << reason << ","<< ","<< namef << ","<< namel << ","<< date;
    otdata.close();
    return;
}
void meal(string namef, string namel)
{
    char c;
    string item;
    char reason[50];
    string total;
    string date;
    //getting the time for stamp
    time_t t;
    time(&t);
    char *current= ctime(&t);
    cout<<setfill('$')<<setw(75)<<"$"<<endl;
    cout <<"\nWelcome to the Business meal Log";
    //prepping file openers
    ofstream otdata;
    otdata.open("log/otherrec.csv", ios::app);
    cout <<"\nEnter the total price: ";
    cin >> total;
    //knowing actual date
    cout << "\nIs this from today/right now? enter y/n:";
    cin >> c;
    if (c=='y'){
        date=current;
    }
    else{
        cout << "\nEnter the date on the receipt in MM/DD/YYYY format: ";
        cin >> date;
    }
    cout << "\nEnter the name food vednor/restaurant:";
    cin >>item;
    otdata << "\n" << item << ","<< total << ","<< namef << ","<< namel << ","<<date;
    otdata.close();
    return;
}