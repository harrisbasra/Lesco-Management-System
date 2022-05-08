//-------------------------------------------------------------HEADER-FILES------------------------------------------------------------//
#include<iostream>
#include<fstream>
#include<string>
//---------------------------------------------------------------NAMESPACE-------------------------------------------------------------//
using namespace std;
//---------------------------------------------------------------SIGNATURES------------------------------------------------------------//
void vieworcalculatebill(); //Bill Viewer && Calculator
void changefixprices();	// Update Fixed Surcharges
void changetaxesandbills(); // Update Unit Per Price
void addcustomer(); // Add a new customer
void chargebill(); // Monthly Bill Charging
void passwordchange(); // Change Admin Passwords
//--------------------------------------------------------------DEFINITIONS------------------------------------------------------------//
void vieworcalculatebill() {
	cout << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "                                         -----------------WELCOME TO LESCO COMPUTING SOFTWARE------------------\n\n\n\n";
	cout << "\n\n";
	cout << "                                                             _____________________________        \n";
	cout << "                                                            |     ....................     |      \n";
	cout << "                                                                   VIEW BILL (PRESS 1)            \n";
	cout << "                                                            |     ....................     |      \n";
	cout << "                                                                           OR                     \n";
	cout << "                                                            |   .........................  |      \n";
	cout << "                                                                 CALCULATE BILL (PRESS 2)         \n";
	cout << "                                                            |   .........................  |      \n";
	cout << "                                                             _______________________________      \n\n";
	cout << "                                                                       INPUT = ";
	int input;
	while (99) {
		cin >> input;
		cout << endl;
		if (input == 1 || input == 2) {
			break;
		}
		cout << "                                                          Enter Valid Input Pleasee\n";
		cout << "                                                                    INPUT = ";
	}
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	//.......................................................................................................................................
	if (input == 1) {
		int index=-33;
		system("cls");
		cout << endl;
		int id = 0;
		long long idcardno = 0;
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "                                             ------------------------------USER BILL VIEWER MANUAL------------------------\n\n\n\n";
		cout << "\n\n\n\n\n";
		while (99) {
			cout << "                                                            _________________________________________\n";
			cout << "                                                               4-DIGIT ID :: ";
			cin >> id;
			cout << "                                                            _________________________________________\n";
			cout << "                                                            _________________________________________\n";
			cout << "                                                               CNIC NUMBER :: ";
			cin >> idcardno;
			cout << "                                                            _________________________________________\n";
			cout << "\n\n\n";
			cout << "                                           Searching for Required User................!!! (This may take some time)\n";
			for (int o = 0; o < 4; o++) {
				if (customerinfo_customerid[o] == id) {
					if (customerinfo_cnicnumber[o] == idcardno) {
						index = o;
					}
				}
			}
			Sleep(3000);
			if (index != -33) {
				cout << "                                                                      FOUND SUCCESSFULLY        \n";
				cout << "                                            " << customerinfo_firstname[index] << " " << customerinfo_secondname[index] << "'s" << "(HIS / HER) total bill is : Rs." << billinginfo_totaldue[index] << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";					
				break;
			}
			else {
				cout << "                                                                 SORRY..! YOUR REQUIRED USER NOT FOUND\n\n";
				cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			}
		}
	}
	if (input == 2) {
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		int currentregunits = 0; int currentpeakunits = 0; char metretype; char usertype;
		float basic = 0;
		float secondary = 0;
		float final = 0;
		cout << "                                                            _________________________________________\n";
		cout << "                                                               USER TYPE (D or C) :: ";
		while (99) {
			cin >> usertype;
			if (usertype == 'D' || usertype == 'd' || usertype == 'C' || usertype == 'c') {
				break;
			}
			cout << "                                                                     GIVE VALID INPUT\n";
		}
		cout << "                                                            _________________________________________\n";
		cout << "                                                            _________________________________________\n";
		cout << "                                                               METRE TYPE (S or T) :: ";
		while (99) {
			cin >> metretype;
			if (metretype == 'S' || metretype == 's' || metretype == 'T' || metretype == 't') {
				break;
			}
			cout << "                                                                     GIVE VALID INPUT\n";
		}
		cout << "                                                            _________________________________________\n";
		cout << "                                                            _________________________________________\n";
		cout << "                                                               REGULAR UNITS CONSUMED :: ";
		cin >> currentregunits;
		cout << "                                                            _________________________________________\n";
		if (metretype == 'T' || metretype == 't') {
			cout << "                                                            _________________________________________\n";
			cout << "                                                               PEAK UNITS CONSUMED :: ";
			cin >> currentpeakunits;
			cout << "                                                            _________________________________________\n";
		}
		if (usertype == 'D' && metretype == 'S') {

			basic = (currentregunits * tarriftaxinfo_regunitprice[0]) + (currentpeakunits * 0);
		}
		if (usertype == 'C' && metretype == 'S') {

			basic = (currentregunits * tarriftaxinfo_regunitprice[1]) + (currentpeakunits * tarriftaxinfo_peakunitprice[2]);
		}
		if (usertype == 'D' && metretype == 'T') {

			basic = (currentregunits * tarriftaxinfo_regunitprice[2]) + (currentpeakunits * 0);
		}
		if (usertype == 'C' && metretype == 'T') {

			basic = (currentregunits * tarriftaxinfo_regunitprice[3]) + (currentpeakunits * tarriftaxinfo_peakunitprice[3]);
		}
		//........................................
		if (usertype == 'D' && metretype == 'S') {
			secondary = (basic * tarriftaxinfo_taxes[0]) / 100;
		}
		if (usertype == 'C' && metretype == 'S') {
			secondary = (basic * tarriftaxinfo_taxes[1]) / 100;
		}
		if (usertype == 'D' && metretype == 'T') {
			secondary = (basic * tarriftaxinfo_taxes[2]) / 100;
		}
		if (usertype == 'C' && metretype == 'T') {
			secondary = (basic * tarriftaxinfo_taxes[3]) / 100;
		}
		//........................................
		if (usertype == 'D' && metretype == 'S') {
			final = basic + secondary + tarriftaxinfo_fixedcharges[0];
		}
		if (usertype == 'C' && metretype == 'S') {
			final = basic + secondary + tarriftaxinfo_fixedcharges[1];
		}
		if (usertype == 'D' && metretype == 'T') {
			final = basic + secondary + tarriftaxinfo_fixedcharges[2];
		}
		if (usertype == 'C' && metretype == 'T') {
			final = basic + secondary + tarriftaxinfo_fixedcharges[3];
		}
		cout << "                                                             YOUR TOTAL BILL IS:  Rs." << final << "/-                                 \n";
	}
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";

}
void changefixprices() {
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "\n             Which one to change.....??\n";
	cout << "                                                             .______________________________________________.\n";
	cout << "                                                             |         ................................     |\n";
	cout << "                                                             |         SINGLE PHASE, DOMESTIC (PRESS 1)     |\n";
	cout << "                                                             |         ................................     |\n";
	cout << "                                                             |                        OR                    |\n";
	cout << "                                                             |        ..................................    |\n";
	cout << "                                                             |        SINGLE PHASE, COMMERCIAL (PRESS 2)    |\n";
	cout << "                                                             |        ..................................    |\n";
	cout << "                                                             |                        OR                    |\n";
	cout << "                                                             |         ................................     |\n";
	cout << "                                                             |         TRIPLE PHASE, DOMESTIC (PRESS 3)     |\n";
	cout << "                                                             |         ................................     |\n";
	cout << "                                                             |                        OR                    |\n";
	cout << "                                                             |        ..................................    |\n";
	cout << "                                                             |        TRIPLE PHASE, COMMERCIAL (PRESS 4)    |\n";
	cout << "                                                             |        ..................................    |\n";
	cout << "                                                             |______________________________________________|\n";
	cout << "                                                                                  INPUT = ";
	float input;
	float nedprice;
	while (99) {
		cin >> input;
		cout << endl;
		if (input == 1 || input == 2 || input == 3 || input == 4) {
			break;
		}
		cout << "                                                          Enter Valid Input Pleaseee\n";
		cout << "                                                                    INPUT = ";
	}
	cout << "                                                                              ENTER NEW PRICE =";
	cin >> nedprice;
	if (input == 1) {
		tarriftaxinfo_fixedcharges[0] = nedprice;
	}
	if (input == 2) {
		tarriftaxinfo_fixedcharges[1] = nedprice;
	}
	if (input == 3) {
		tarriftaxinfo_fixedcharges[2] = nedprice;
	}
	if (input == 4) {
		tarriftaxinfo_fixedcharges[3] = nedprice;
	}
	cout << "--------------------------------------------------------------------------------------------------------------------------------------";

}
void changetaxesandbills()
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "\n             Which one to change.....??\n";
	cout << "                                                             .______________________________________________.\n";
	cout << "                                                             |         ................................     |\n";
	cout << "                                                             |         SINGLE PHASE, DOMESTIC (PRESS 1)     |\n";
	cout << "                                                             |         ................................     |\n";
	cout << "                                                             |                        OR                    |\n";
	cout << "                                                             |        ..................................    |\n";
	cout << "                                                             |        SINGLE PHASE, COMMERCIAL (PRESS 2)    |\n";
	cout << "                                                             |        ..................................    |\n";
	cout << "                                                             |                        OR                    |\n";
	cout << "                                                             |         ................................     |\n";
	cout << "                                                             |         TRIPLE PHASE, DOMESTIC (PRESS 3)     |\n";
	cout << "                                                             |         ................................     |\n";
	cout << "                                                             |                        OR                    |\n";
	cout << "                                                             |        ..................................    |\n";
	cout << "                                                             |        TRIPLE PHASE, COMMERCIAL (PRESS 4)    |\n";
	cout << "                                                             |        ..................................    |\n";
	cout << "                                                             |______________________________________________|\n";
	cout << "                                                                                  INPUT = ";
	int input;
	float gst;
	float nedprice1;
	float nedprice2;
	while (99) {
		cin >> input;
		cout << endl;
		if (input == 1 || input == 2 || input == 3 || input == 4) {
			break;
		}
		cout << "                                                                        Enter Valid Input Pleaseee\n";
		cout << "                                                                                   INPUT = ";
	}
	cout << "                                                             ENTER NEW TAX % (ANY NEGATIVE NUMBER FOR NO CHANGE)= ";
	cin >> gst;
	if (input == 1 && gst>=0) {
		tarriftaxinfo_taxes[0] = gst;
	}
	if (input == 2 && gst >= 0) {
		tarriftaxinfo_taxes[1] = gst;
	}
	if (input == 3 && gst >= 0) {
		tarriftaxinfo_taxes[2] = gst;
	}
	if (input == 4 && gst >= 0) {
		tarriftaxinfo_taxes[3] = gst;
	}
	cout << "                                                             ENTER NEW UNIT PRICE (ANY NEGATIVE NUMBER FOR NO CHANGE)= ";
	if (input == 1) {
		cin >> nedprice1;
		if (nedprice1 >= 0) {
			tarriftaxinfo_regunitprice[0] = nedprice1;
		}
	}
	if (input == 2) {
		cin >> nedprice1;
		if (nedprice1 >= 0) {
			tarriftaxinfo_regunitprice[1] = nedprice1;
		}
	}
	if (input == 3) {
		cin >> nedprice1;
		if (nedprice1 >= 0) {
			tarriftaxinfo_regunitprice[2] = nedprice1;
		}
		cout << "                                                             ENTER PEAK UNIT PRICE (ANY NEGATIVE NUMBER FOR NO CHANGE)= ";
		cin >> nedprice2;
		if (nedprice2 >= 0) {
			tarriftaxinfo_peakunitprice[2] = nedprice2;
		}
	}
	if (input == 4) {
		cin >> nedprice1;
		if (nedprice1 >= 0) {
			tarriftaxinfo_regunitprice[3] = nedprice1;
		}
		cout << "                                                             ENTER PEAK UNIT PRICE (ANY NEGATIVE NUMBER FOR NO CHANGE)= ";
		cin >> nedprice2;
		if (nedprice2 >= 0) {
			tarriftaxinfo_peakunitprice[3] = nedprice2;
		}
	}
	cout << "--------------------------------------------------------------------------------------------------------------------------------------";

}
void addcustomer() {

}
void chargebill() {
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "----------------------------------------------------------------BILL CHARGING MANUAL----------------------------------------------------E-\n";
	cout << "\n\n\n";
	cout << "                                                         ENTER CUSTOMER ID (TO CHARGE BILL) : \n";
	int ideeyyy;
	int indexxx=-33;
	while (99)
	{
		cout << "                                                                    INPUT = ";
		cin >> ideeyyy;
		if (ideeyyy < 1000 || ideeyyy>9999) {
			cout << "                                                                ENTER VALID ID\n";
		}
		for (int i = 0; i < 4; i++) {
			if (customerinfo_customerid[i] == ideeyyy) {
				indexxx = i;
			}
		}
		if (indexxx == -33 || (indexxx >= 0 && indexxx <= 3)) {
			break;
		}
		cout << "                                                                 USER NOT FOUND\n";
	}
	customerinfo_unitsconsumed[indexxx] = billinginfo_currentunitsreg[indexxx];
	cout << "\n\n\n\n                                                                 ENTER NEW UNITS = ";
	float newww;
	cin >> newww;
	billinginfo_currentunitsreg[indexxx] = newww;
	cout << "\n                                                                    UPDATED SUCCESSFULLY\n";
	if (customerinfo_metretype[indexxx] == 'T') {
		customerinfo_peakhourunits[indexxx] = billinginfo_currentunitspeak[indexxx];
		cout << "                                                                     ENTER PEAK UNITS = ";
		float newww2;
		cin >> newww2;
		billinginfo_currentunitspeak[indexxx] = newww2;
	}
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------\n";
}
void passwordchange() {
	system("cls");
	cout << endl;
	string passwordf = ".";
	string newpassword;
	string newpasswordb;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "                                             --------------------------PASSWORD CHANGING MANUAL------------------------\n\n\n\n";
	cout << "\n\n\n\n\n";
	while (99) {
		cout << "                                                            _________________________________________\n";
		cout << "                                                               OLD PASSWORD :: ";
		cin >> passwordf;
		cout << "                                                            _________________________________________\n";
		cout << "                                                            _________________________________________\n";
		cout << "                                                               NEW PASSWORD :: ";
		cin >> newpassword;
		cout << "                                                            _________________________________________\n";
		cout << "                                                            _________________________________________\n";
		cout << "                                                               CONFIRM NEW PASSWORD :: ";
		cin >> newpasswordb;
		cout << "                                                            _________________________________________\n";
		if (passwordf == supremesecret) {
			if (newpassword == newpasswordb) {
				supremeloggedin.append(",");
				supremeloggedin.append(newpassword);
				empdata_unp[supremeindex] = supremeloggedin;
				break;
			}
			else
			{
				cout << "                                                                    PASSWORDS DO NOT MATCH\n";
			}
			cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n";
		}
		else {
			cout << "                                                                       PASSWORD INVALID\n";
		}
	}
}