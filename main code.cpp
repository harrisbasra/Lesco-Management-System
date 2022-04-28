//-------------------------  LIBRARIES ---------------------------//
#include<iostream>;
#include<fstream>;
#include<cstring>;
#include<string>;
#include<Windows.h>;
//----------------------- GLOBAL MEMORY -------------------------//

//------------------------ STD LIBRARY --------------------------//
using namespace std;
//------------------------ PROTOTYPES ---------------------------//
char initialdisplay(); // To select Admin or User
bool passwordmanager(int decision); // Match Password
int dispadminmenu(); // Menu Print
void thankspage();
bool EmployeeConfirmation(string username, string password);
//------------------------- INT MAIN ----------------------------//
int main() {
	char i = initialdisplay();
	if (i == 'e' || i=='E') {
		bool flag = passwordmanager(0);
		if (flag == true) {
			dispadminmenu();
		}
		if (flag == false) {
			i = 'q';
		}
	}
	if (i == 'U' || i == 'u') {
		bool flag = passwordmanager(1);
	}
	if (i == 'q' || i == 'Q') {
		cout << "Thanks for Using" << endl;
		return 0;
	}

	return 0;
}
//------------------------ FUNCTION DEFFS. --------------------------//
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
		string username=".";
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
			if (EmployeeConfirmation(username,password)) {
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
	if (decision == 1) {


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
			return true;
		}
	}
	return false;
}
int dispadminmenu() {
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
		if (input == 0 || input == 1 || input == 2 || input == 3 || input == 4 || input == 5|| input == 6) {
			break;
		}
		cout << "                                                          Enter Valid Input Pleasee\n";
		cout << "                                                                    INPUT = ";
	}
	cout << "--------------------------------------------------------------------------------------------------------------------------------------";

	return 0;
}
