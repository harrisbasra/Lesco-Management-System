//-------------------------  LIBRARIES ---------------------------//
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<Windows.h>
#include"UnloadedDataBase.h"
#include"Startup.h"
#include"Admin.h"
#include"User.h"
//------------------------ STD LIBRARY --------------------------//
using namespace std;
///////////////////////////////////////////////////////////
//------------------------- PROTOTYPES ---------------------------//
char initialdisplay(); // To select Admin or User
bool passwordmanager(int decision); // Match Password
int dispadminmenu(); // Menu Print
int dispusermenu(); // Menu Print
bool EmployeeConfirmation(string username, string password);
void loadermainfunction();
//------------------------- INT MAIN ----------------------------//
int main() {
	cout << "HEHE";
	loadermainfunction();
	billcreator();
	char i = initialdisplay();
	if (i == 'e' || i == 'E') {
		bool flag = passwordmanager(0);
		if (flag == true) {
			int todo = dispadminmenu();
			if (todo == 1)
			{
				addcustomer();
			}
			if (todo == 2)
			{
				vieworcalculatebill();
			}
			if (todo == 3)
			{
				changefixprices();
			}
			if (todo == 4)
			{
				changetaxesandbills();
			}
			if (todo == 5)
			{
				chargebill();
			}
			if (todo == 6)
			{
				passwordchange();
			}
			if (todo == 0) {
				cout << "\n                                                      Thanks for Using this High-Level Software...!\n" << endl;
				return 0;
			}
		}
		if (flag == false) {
			i = 'q';
		}
	}
	if (i == 'U' || i == 'u') {
		bool flag = passwordmanager(1);
		if (flag) {
			int todo = dispusermenu();
			if (todo == 1) {
				getinfoaboutme();
			}
			if (todo == 2) {
				vieworcalculatebill2();
			}
			if (todo == 3) {
				checkprices();
			}
			if (todo == 4) {
				getinfoaboutme();
			}
			if (todo == 5) {
				paybill();
			}
			if (todo == 0) {
				cout << "\n                                                      Thanks for Using this High-Level Software...!\n" << endl;
				return 0;
			}
		}
		if (flag == false) {
			i = 'q';
		}
	}
	if (i == 'q' || i == 'Q') {
		cout << "Thanks for Using" << endl;
			endofprogram();
		return 0;
	}
	endofprogram();
	return 0;
}