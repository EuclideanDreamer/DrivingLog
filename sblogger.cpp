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
//*	* 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//Libreoffice Calc (spreadsheet) data entry with C++
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <sqlite3.h>
#include <fstream>
using namespace std;
void driving();
void gas();
void other();
int main()
{
    while (true)
    {
        char line ='-';
        char menu;
        //getting the time for stamp
        time_t t;
        time(&t);
        cout <<t<<endl;
        char *curent= ctime(&t);
        //prepping file openers
        ifstream indata;
        ofstream otdata;
        cout<<setfill('#')<<setw(75)<<"#"<<endl;
        cout <<"\nWelcome to the Logger\n"<<endl;
        cout <<"\nEnter 1 to submit gas receipts"<<endl;
        cout <<"\nEnter 2 to submit an entry to driving log"<<endl;
        cout <<"\nEnter 3 to submit other business receipts"<<endl;
        //cout <<"Enter 4 to read data from files"<<endl;
        cout <<"\nEnter F to exit program"<<endl;
        cin >>menu;
        cout << endl;
        switch (menu){
            case '1':
                //do 1 stuff
                gas();
                break;
            case '2':
                //do 2 stuff
                driving();
                break;
            case '3':
                //do 3 stuff
                other();
                break;
            //case '4':
                //do 4 stuff
                //break;
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
void driving()
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
    string reason;
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
    <<","<< milage << "," << current;
    otdata.close();
    return;
}
void gas()
{
    char c;
    string gas;
    string date;
    //getting the time for stamp
    time_t t;
    time(&t);
    char *current= ctime(&t);
    cout<<setfill('G')<<setw(75)<<"G"<<endl;
    cout <<"\nWelcome to the Gas Receipt Log";
    //prepping file openers
    ofstream otdata;
    otdata.open("log/gasrec.csv", ios::app);
    cout <<"\nEnter the total gas: ";
    cin >> gas;
    cout << "\nIs this from today/right now? enter y/n:";
    cin >> c;
    if (c=='y'){
        date=current;
    }
    else{
        cout << "\nEnter the date on the receipt in MM/DD/YYYY format: ";
        cin >> date;
    }
    otdata << "\n" << "gas,"<< gas << ","<< date;
    otdata.close();
    return;
}
void other()
{
    char c;
    string item;
    string reason;
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
    otdata << "\n" << item << ","<< total << "," << reason << ","<< date;
    otdata.close();
    return;
}
