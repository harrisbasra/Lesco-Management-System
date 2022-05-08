#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<Windows.h>
using namespace std;
//------------------------ PROTOTYPES ---------------------------//
char initialdisplay(); // To select Admin or User
bool passwordmanager(int decision); // Match Password
bool passwordmanager2(); // Match Password
int  dispadminmenu(); // Menu Print
int  dispusermenu(); // Menu Print
bool EmployeeConfirmation(string username, string password); // Local Password Checker
bool UserConfirmation(int idcard, long long cnic); // Local Password Checker
void loadermainfunction(); // Fill Information
void billcreator(); // Fill Money
void endofprogram(); // Writer Back
//------------------------ FUNCTION DEFFS. --------------------------//
void loadermainfunction() {
	readhead.open("CustomerInfo.txt");
	for (int kk = 0; kk < 4; kk++) {
		readhead >> customerinfo_customerid[kk];
		readhead >> commastorer;
		readhead >> customerinfo_cnicnumber[kk];
		readhead >> commastorer;
		readhead >> customerinfo_firstname[kk];
		readhead >> customerinfo_secondname[kk];
		readhead >> commastorer;
		readhead >> customerinfo_address1[kk];
		readhead >> customerinfo_address2[kk];
		readhead >> commastorer;
		readhead >> customerinfo_phonenumber[kk];
		readhead >> commastorer;
		readhead >> customerinfo_customertype[kk];
		readhead >> commastorer;
		readhead >> customerinfo_metretype[kk];
		readhead >> commastorer;
		readhead >> customerinfo_date[kk];
		readhead >> commastorer;
		readhead >> customerinfo_unitsconsumed[kk];
		readhead >> commastorer;
		readhead >> customerinfo_peakhourunits[kk];
	}
	readhead.close();
	readhead2.open("TarriffTaxInfo.txt");
	for (int kk = 0; kk < 4; kk++) {
		readhead2 >> tarriftaxinfo_metrename[kk];
		readhead2 >> commastorer;
		readhead2 >> tarriftaxinfo_regunitprice[kk];
		readhead2 >> commastorer;
		if (kk == 2 || kk == 3)
			readhead2 >> tarriftaxinfo_peakunitprice[kk];
		readhead2 >> commastorer;
		readhead2 >> tarriftaxinfo_taxes[kk];
		readhead2 >> commastorer;
		readhead2 >> tarriftaxinfo_fixedcharges[kk];
	}
	readhead2.close();
	readhead3.open("NadraDB.txt");
	for (int kk = 0; kk < 4; kk++) {
		readhead3 >> nadradb_issuedate[kk];
		readhead3 >> commastorer;
		readhead3 >> waste;
		readhead3 >> commastorer;
		readhead3 >> nadradb_expirydate[kk];
	}
	readhead3.close();
	readhead4.open("EmpData.txt");
	for (int m = 0; m < 4; m++) {
		readhead4 >> empdata_unp[m];
	}
	readhead4.close();
	readhead5.open("BillingInfo.txt");
	for (int cc = 0; cc < 4; cc++)
	{
		readhead5 >> waste5;
		readhead5 >> commastorer;
		readhead5 >> billinginfo_monthname[cc];
		readhead5 >> commastorer;
		readhead5 >> billinginfo_currentunitsreg[cc];
		readhead5 >> commastorer;
		readhead5 >> billinginfo_currentunitspeak[cc];
		readhead5 >> commastorer;
		readhead5 >> billinginfo_readingdate[cc];
		readhead5 >> commastorer;
		readhead5 >> billinginfo_costofelec[cc];
		readhead5 >> commastorer;
		readhead5 >> billinginfo_salestax[cc];
		readhead5 >> commastorer;
		readhead5 >> billinginfo_fixamount[cc];
		readhead5 >> commastorer;
		readhead5 >> billinginfo_totaldue[cc];
		readhead5 >> commastorer;
		readhead5 >> billinginfo_duedate[cc];
		readhead5 >> commastorer;
		readhead5 >> billinginfo_status[cc];
		readhead5 >> commastorer;
		readhead5 >> billinginfo_payingdate[cc];
	}	
	readhead5.close();
}
char initialdisplay() {
	cout << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "                                         -----------------WELCOME TO LESCO COMPUTING SOFTWARE------------------\n\n\n\n";
	cout << "                                                                  PRESENTED BY ::                         \n\n ";
	cout << "                                        ----------------------------------------------------------------\n";
	cout << "                                        |   1) ZAYAM AMJAD       2) HARRIS KHALID      3)FAISAL SHAHZAD  |  \n";
	cout << "                                        |            4) MASHAL PERVAIZ         5) AYESHA ABID            |  \n";
	cout << "                                         ----------------------------------------------------------------\n";
	cout << "\n\n";
	cout << "                                                   ______________________________________________\n";
	cout << "                                                             ............................         \n";
	cout << "                                                             LOG IN AS EMPLOYEE (PRESS E)         \n";
	cout << "                                                             ............................         \n";
	cout << "                                                                         OR                       \n";
	cout << "                                                              ..........................          \n";
	cout << "                                                              CONTINUE AS USER (PRESS U)          \n";
	cout << "                                                              ..........................          \n";
	cout << "                                                                         OR                       \n";
	cout << "                                                                   ...............                \n";
	cout << "                                                                    QUIT (PRESS Q)                \n";
	cout << "                                                                   ...............                \n";
	cout << "                                                   ______________________________________________ \n\n";
	cout << "                                                                       INPUT = ";
	char input;
	while (99) {
		cin >> input;
		cout << endl;
		if (input == 'Q' || input == 'q' || input == 'E' || input == 'e' || input == 'U' || input == 'u') {
			break;
		}
		cout << "                                                          Enter Valid Input Pleasee\n";
		cout << "                                                                    INPUT = ";
	}
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	return input;
}
bool passwordmanager(int decision) {
	system("cls");
	int warning = 0;
	if (decision == 0) {
		cout << endl;
		string username = ".";
		string password = ".";
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "                                             ------------------------PASSWORD CHECK MANAGER------------------------\n\n\n\n";
		cout << "\n\n\n\n\n";
		while (99) {
			cout << "                                                            _________________________________________\n";
			cout << "                                                               USERNAME :: ";
			cin >> username;
			cout << "                                                            _________________________________________\n";
			cout << "                                                            _________________________________________\n";
			cout << "                                                               PASSWORD :: ";
			cin >> password;
			cout << "                                                            _________________________________________\n";
			if (EmployeeConfirmation(username, password)) {
				cout << "\n\n\n";
				cout << "                                           Verifying your credentials................!!! (This may take some time)\n";
				Sleep(3000);
				cout << "                                                                     @LOGGED IN SUCCESSFULLY\n\n";
				cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				supremeloggedin = username;
				supremesecret = password;
				return true;
			}
			else {
				cout << "\n\n\n";
				cout << "                                           Verifying your credenrials................!!! (This may take some time)\n";
				Sleep(3000);
				cout << "                                                                 SORRY..! YOUR CREDENTIALS ARE WRONG\n\n";
				cout << "                                                                     " << 3 - warning << " Attemps left\n";
				cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				warning++;
			}
			if (warning == 4) {
				cout << "                                                                  YOU CANNOT LOGIN NOW...! RESTART PROGRAM\n";
				break;
			}
		}
	}
	if (decision == 1) {
		cout << endl;
		int username;
		long long password ;
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "                                             ------------------------PASSWORD CHECK MANAGER------------------------\n\n\n\n";
		cout << "\n\n\n\n\n";
		while (99) {
			cout << "                                                            _________________________________________\n";
			cout << "                                                               UNIQUE USER ID :: ";
			cin >> username;
			cout << "                                                            _________________________________________\n";
			cout << "                                                            _________________________________________\n";
			cout << "                                                               CNIC NUMBER :: ";
			cin >> password;
			cout << "                                                            _________________________________________\n";
			if (UserConfirmation(username,password)) {
				cout << "\n\n\n";
				cout << "                                           Verifying your credentials................!!! (This may take some time)\n";
				Sleep(3000);
				cout << "                                                                     @LOGGED IN SUCCESSFULLY\n\n";
				cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				return true;
			}
			else {
				cout << "\n\n\n";
				cout << "                                           Verifying your credenrials................!!! (This may take some time)\n";
				Sleep(3000);
				cout << "                                                                 SORRY..! YOUR CREDENTIALS ARE WRONG\n\n";
				cout << "                                                                     " << 3 - warning << " Attemps left\n";
				cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				warning++;
			}
			if (warning == 4) {
				cout << "                                                                  YOU CANNOT LOGIN NOW...! RESTART PROGRAM\n";
				break;
			}
		}
	}
	return false;
}
bool EmployeeConfirmation(string username, string password) {

	string users[5] = {};
	ifstream fout;
	int i = 0;
	string h;
	fout.open("EmpData.txt");
	while (!(fout.eof())) {
		fout >> h;
		users[i] = h;
		i++;
	}
	string appender = ",";
	username.append(appender);
	username.append(password);
	for (int ii = 0; ii < 5; ii++) {
		if (username == users[ii]) {
			supremeindex = ii;
			return true;
		}
	}
	return false;
}
bool UserConfirmation(int idcard, long long cnic) {
	for (int i = 0; i < 4; i++) {
		if (customerinfo_customerid[i] == idcard) {
			loggedinindex = i;
			loggedinuser = idcard;
			return true;
		}
	}
	return false;
}
int  dispadminmenu() {
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "\n-----------------------------------------------------------WELCOME TO ADMIN USE PORTAL----------------------------------------------\n";
	cout << "\n             What's On Your Mind ....??\n";
	cout << "                                                  .______________________________________________.\n";
	cout << "                                                  |           ........................           |\n";
	cout << "                                                  |            ADD CUSTOMER (PRESS 1)            |\n";
	cout << "                                                  |           ........................           |\n";
	cout << "                                                  |                      OR                      |\n";
	cout << "                                                  |      ................................        |\n";
	cout << "                                                  |      VIEW OR CALCULATE BILL (PRESS 2)        |\n";
	cout << "                                                  |      ................................        |\n";
	cout << "                                                  |                      OR                      |\n";
	cout << "                                                  |         ...........................          |\n";
	cout << "                                                  |         CHANGE UNIT RATES (PRESS 3)          |\n";
	cout << "                                                  |         ...........................          |\n";
	cout << "                                                  |                      OR                      |\n";
	cout << "                                                  |        .............................         |\n";
	cout << "                                                  |         CHANGE FIX PRICES (PRESS 4)          |\n";
	cout << "                                                  |        .............................         |\n";
	cout << "                                                  |                      OR                      |\n";
	cout << "                                                  |            .......................           |\n";
	cout << "                                                  |             CHARGE BILL (PRESS 5)            |\n";
	cout << "                                                  |            .......................           |\n";
	cout << "                                                  |                      OR                      |\n";
	cout << "                                                  |          ...........................         |\n";
	cout << "                                                  |           PASSWORD CHANGE (PRESS 6)          |\n";
	cout << "                                                  |          ...........................         |\n";
	cout << "                                                  |                      OR                      |\n";
	cout << "                                                  |                ...............               |\n";
	cout << "                                                  |                 EXIT (PRESS 0)               |\n";
	cout << "                                                  |                ...............               |\n";
	cout << "                                                  |______________________________________________|\n";
	cout << "                                                                       INPUT = ";
	int input;
	while (99) {
		cin >> input;
		cout << endl;
		if (input == 0 || input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input == 6) {
			break;
		}
		cout << "                                                          Enter Valid Input Pleasee\n";
		cout << "                                                                    INPUT = ";
	}
	cout << "--------------------------------------------------------------------------------------------------------------------------------------";

	return input;
}
int  dispusermenu(){
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "\n-----------------------------------------------------------WELCOME TO USER PORTAL----------------------------------------------\n";
	cout << "\n             What can we provide ....??\n";
	cout << "                                                  .______________________________________________.\n";
	cout << "                                                  |           ........................           |\n";
	cout << "                                                  |           SHOW MY PROFILE (PRESS 1)          |\n";
	cout << "                                                  |           ........................           |\n";
	cout << "                                                  |                      OR                      |\n";
	cout << "                                                  |      ................................        |\n";
	cout << "                                                  |      VIEW OR CALCULATE BILL (PRESS 2)        |\n";
	cout << "                                                  |      ................................        |\n";
	cout << "                                                  |                      OR                      |\n";
	cout << "                                                  |             ....................             |\n";
	cout << "                                                  |              GET INFO (PRESS 3)              |\n";
	cout << "                                                  |             ....................             |\n";
	cout << "                                                  |                      OR                      |\n";
	cout << "                                                  |           .........................          |\n";
	cout << "                                                  |            CHECK DUE BILL (PRESS 4)          |\n";
	cout << "                                                  |           .........................          |\n";
	cout << "                                                  |                      OR                      |\n";
	cout << "                                                  |               ..................             |\n";
	cout << "                                                  |               PAY BILL (PRESS 5)             |\n";
	cout << "                                                  |               ..................             |\n";
	cout << "                                                  |                      OR                      |\n";
	cout << "                                                  |                ...............               |\n";
	cout << "                                                  |                 EXIT (PRESS 0)               |\n";
	cout << "                                                  |                ...............               |\n";
	cout << "                                                  |______________________________________________|\n";
	cout << "                                                                       INPUT = ";
	int input;
	while (99) {
		cin >> input;
		cout << endl;
		if (input == 0 || input == 1 || input == 2 || input == 3 || input == 4 || input == 5) {
			break;
		}
		cout << "                                                          Enter Valid Input Pleasee\n";
		cout << "                                                                    INPUT = ";
	}
	cout << "--------------------------------------------------------------------------------------------------------------------------------------";

	return input;
}
void billcreator() {
	for (int i = 0; i < 4; i++) {
		
			if (customerinfo_customertype[i] == 'D' && customerinfo_metretype[i] == 'S') {
				
				billinginfo_costofelec[i] = ((billinginfo_currentunitsreg[i] - customerinfo_unitsconsumed[i]) * tarriftaxinfo_regunitprice[0]) + ((billinginfo_currentunitspeak[i] - customerinfo_peakhourunits[i]) * 0);
			}
			if (customerinfo_customertype[i] == 'C' && customerinfo_metretype[i] == 'S') {
				
				billinginfo_costofelec[i] = ((billinginfo_currentunitsreg[i] - customerinfo_unitsconsumed[i]) * tarriftaxinfo_regunitprice[1]) + ((billinginfo_currentunitspeak[i] - customerinfo_peakhourunits[i]) * tarriftaxinfo_peakunitprice[2]);
			}
			if (customerinfo_customertype[i] == 'D' && customerinfo_metretype[i] == 'T') {
				
				billinginfo_costofelec[i] = ((billinginfo_currentunitsreg[i] - customerinfo_unitsconsumed[i]) * tarriftaxinfo_regunitprice[2]) + ((customerinfo_peakhourunits[i] - billinginfo_currentunitspeak[i]) * 0);
			}
			if (customerinfo_customertype[i] == 'C' && customerinfo_metretype[i] == 'T') {
				
				billinginfo_costofelec[i] = ((billinginfo_currentunitsreg[i] - customerinfo_unitsconsumed[i]) * tarriftaxinfo_regunitprice[3]) + ((customerinfo_peakhourunits[i] - billinginfo_currentunitspeak[i]) * tarriftaxinfo_peakunitprice[3]);
			}
			//................................................................................................
			if (customerinfo_customertype[i] == 'D' && customerinfo_metretype[i] == 'S') {
				billinginfo_salestax[i] = (billinginfo_costofelec[i] * tarriftaxinfo_taxes[0]) / 100;
			}
			if (customerinfo_customertype[i] == 'C' && customerinfo_metretype[i] == 'S') {
				billinginfo_salestax[i] = (billinginfo_costofelec[i] * tarriftaxinfo_taxes[1]) / 100;
			}
			if (customerinfo_customertype[i] == 'D' && customerinfo_metretype[i] == 'T') {
				billinginfo_salestax[i] = (billinginfo_costofelec[i] * tarriftaxinfo_taxes[2]) / 100;
			}
			if (customerinfo_customertype[i] == 'C' && customerinfo_metretype[i] == 'T') {
				billinginfo_salestax[i] = (billinginfo_costofelec[i] * tarriftaxinfo_taxes[3]) / 100;
			}
			//................................................................................................
		
			if (customerinfo_customertype[i] == 'D' && customerinfo_metretype[i] == 'S') {
				billinginfo_fixamount[i] = tarriftaxinfo_fixedcharges[0];
			}
			if (customerinfo_customertype[i] == 'C' && customerinfo_metretype[i] == 'S') {
				billinginfo_fixamount[i] = tarriftaxinfo_fixedcharges[1];
			}
			if (customerinfo_customertype[i] == 'D' && customerinfo_metretype[i] == 'T') {
				billinginfo_fixamount[i] = tarriftaxinfo_fixedcharges[2];
			}
			if (customerinfo_customertype[i] == 'C' && customerinfo_metretype[i] == 'T') {
				billinginfo_fixamount[i] = tarriftaxinfo_fixedcharges[3];
			}
			//................................................................................................
		billinginfo_totaldue[i] = billinginfo_costofelec[i] + billinginfo_salestax[i] + billinginfo_fixamount[i];
	}
}
void endofprogram() {

	writehead.open("CustomerInfo.txt");
	for (int kk = 0; kk < 4; kk++) {
		writehead << customerinfo_customerid[kk];
		writehead << " ";
		writehead << commastorer;
		writehead << " ";
		writehead << customerinfo_cnicnumber[kk];
		writehead << " ";
		writehead << commastorer;
		writehead << " ";
		writehead << customerinfo_firstname[kk];
		writehead << " ";
		writehead << customerinfo_secondname[kk];
		writehead << " ";
		writehead << commastorer;
		writehead << " ";
		writehead << customerinfo_address1[kk];
		writehead << " ";
		writehead << customerinfo_address2[kk];
		writehead << " ";
		writehead << commastorer;
		writehead << " ";
		writehead << customerinfo_phonenumber[kk];
		writehead << " ";
		writehead << commastorer;
		writehead << " ";
		writehead << customerinfo_customertype[kk];
		writehead << " ";
		writehead << commastorer;
		writehead << " ";
		writehead << customerinfo_metretype[kk];
		writehead << " ";
		writehead << commastorer;
		writehead << " ";
		writehead << customerinfo_date[kk];
		writehead << " ";
		writehead << commastorer;
		writehead << " ";
		writehead << customerinfo_unitsconsumed[kk];
		writehead << " ";
		writehead << commastorer;
		writehead << " ";
		writehead << customerinfo_peakhourunits[kk];
		writehead << endl;
	}
	writehead.close();
	writehead2.open("TarriffTaxInfo.txt");
	for (int kk = 0; kk < 4; kk++) {
		writehead2 << tarriftaxinfo_metrename[kk];
		writehead2 << " ";
		writehead2 << commastorer;
		writehead2 << " ";
		writehead2 << tarriftaxinfo_regunitprice[kk];
		writehead2 << " ";
		writehead2 << commastorer;
		writehead2 << " ";
		if (kk == 2 || kk == 3)
			writehead2 << tarriftaxinfo_peakunitprice[kk];
		writehead2 << " ";
		writehead2 << commastorer;
		writehead2 << " ";
		writehead2 << tarriftaxinfo_taxes[kk];
		writehead2 << " ";
		writehead2 << commastorer;
		writehead2 << " ";
		writehead2 << tarriftaxinfo_fixedcharges[kk];
		writehead2 << endl;
	}
	writehead2.close();
	writehead3.open("NadraDB.txt");
	for (int kk = 0; kk < 4; kk++) {
		writehead3 << nadradb_issuedate[kk];
		writehead3 << " ";
		writehead3 << commastorer;
		writehead3 << " ";
		writehead3 << customerinfo_cnicnumber[kk];
		writehead3 << " ";
		writehead3 << commastorer;
		writehead3 << " ";
		writehead3 << nadradb_expirydate[kk];
		writehead3 << endl;
	}
	writehead3.close();
	writehead4.open("EmpData.txt");
	for (int m = 0; m < 4; m++) {
		writehead4 << empdata_unp[m];
		writehead4 << endl;
	}
	writehead4.close();
	writehead5.open("BillingInfo.txt");
	for (int cc = 0; cc < 4; cc++)
	{
		writehead5 << customerinfo_customerid[cc];
		writehead5 << " ";
		writehead5 << commastorer;
		writehead5 << " ";
		writehead5 << billinginfo_monthname[cc];
		writehead5 << " ";
		writehead5 << commastorer;
		writehead5 << " ";
		writehead5 << billinginfo_currentunitsreg[cc];
		writehead5 << " ";
		writehead5 << commastorer;
		writehead5 << " ";
		writehead5 << billinginfo_currentunitspeak[cc];
		writehead5 << " ";
		writehead5 << commastorer;
		writehead5 << " ";
		writehead5 << billinginfo_readingdate[cc];
		writehead5 << " ";
		writehead5 << commastorer;
		writehead5 << " ";
		writehead5 << billinginfo_costofelec[cc];
		writehead5 << " ";
		writehead5 << commastorer;
		writehead5 << " ";
		writehead5 << billinginfo_salestax[cc];
		writehead5 << " ";
		writehead5 << commastorer;
		writehead5 << " ";
		writehead5 << billinginfo_fixamount[cc];
		writehead5 << " ";
		writehead5 << commastorer;
		writehead5 << " ";
		writehead5 << billinginfo_totaldue[cc];
		writehead5 << " ";
		writehead5 << commastorer;
		writehead5 << " ";
		writehead5 << billinginfo_duedate[cc];
		writehead5 << " ";
		writehead5 << commastorer;
		writehead5 << " ";
		writehead5 << billinginfo_status[cc];
		writehead5 << " ";
		writehead5 << commastorer;
		writehead5 << " ";
		writehead5 << billinginfo_payingdate[cc];
		writehead5 << endl;
	}
	writehead5.close();
}