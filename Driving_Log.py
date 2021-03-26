"""
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name	: Driving_log.py	* 
//*	* 
//* Written by	: Bailey Nichols	* 
//*	* 
//* Purpose	: This is a program that promts the user to enter a driving log*
//*---------------------------------------------------------------------* 
//* Change Log:	* 
//*	Revision	* 
//*	Date	Changed  Rel Ver Mod Purpose	* 
//* 03/25/21	Nichols 001.000.000 Initial release of program	*
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
"""
import sqlite3 as sl 
import time
import datetime
"""getting unix time, connecting to db and activating cusor"""
unix=time.time()
conn=sl.connect('driving.db')
c=conn.cursor()
"""function to create table"""
def create_table():
    c.execute('CREATE TABLE IF NOT EXISTS Hyundai_Accent_2017(Date TEXT, Time TEXT, Destination TEXT, Start TEXT, Reason TEXT)')
"""function to enter data into table"""
def data_entry():
    """getting date and time into format"""
    Time = str(datetime.datetime.fromtimestamp(unix).strftime('%H:%M'))
    Date = str(datetime.datetime.fromtimestamp(unix).strftime('%Y-%m-%d'))
    """getting user input and inserting it into table"""
    Destination=input("\nEnter the destinaton for your trip:\n",)
    Start=input("\nEnter the starting point for your trip:\n",)
    Reason=input("\nEnter the reason for your trip:\n",)
    c.execute("INSERT INTO Hyundai_Accent_2017 (Date, Time, Destination, Start, Reason) VALUES (?, ?, ?, ?, ?)",
    (Date, Time, Destination, Start, Reason))
    conn.commit()
#create_table()
"""Just above and below are contols for program, uncomment the create_table on the first run, then recomment it, and uncomment the data_entry, to run the program """
#data_entry()
"""closing connection and cursor"""
c.close()
conn.close()