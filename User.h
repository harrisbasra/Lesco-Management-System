//-------------------------------------------------------------HEADER-FILES------------------------------------------------------------//
#include<iostream>
#include<fstream>
#include<string>
//-------------------------------------------------------------- NAMESPACE ------------------------------------------------------------//
using namespace std;
//---------------------------------------------------------------SIGNATURES------------------------------------------------------------//
void vieworcalculatebill2(); // Bill Viewer && Calculator
void getinfoaboutme(); // Learn Basic Info
void checkprices(); // View Rates
void paybill(); // Pay Bill via Credit Card
//--------------------------------------------------------------DEFINITIONS------------------------------------------------------------//
void vieworcalculatebill2() {
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
		int index = -33;
		system("cls");
		cout << endl;
		int id = 0;
		long long idcardno = 0;
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "                                             ------------------------------USER BILL VIEWER MANUAL-------------------------------\n\n\n\n";
		cout << "\n\n\n\n\n";
		cout << "                                                            _________________________________________\n";
		cout << "                                                               4-DIGIT ID :: "<<loggedinuser<<endl;
		cout << "                                                            _________________________________________\n";
		cout << "                                                            _________________________________________\n";
		cout << "                                                               CNIC NUMBER :: "<<customerinfo_cnicnumber[loggedinindex]<<endl;
		cout << "                                                            _________________________________________\n";
		cout << "\n\n\n";
		cout << "                                                       " << customerinfo_firstname[loggedinindex] << " " << customerinfo_secondname[loggedinindex] << "'s" << "(HIS / HER) total bill is : Rs." << billinginfo_totaldue[loggedinindex] << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";	
		
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
void getinfoaboutme() {
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "----------------------------------------------------------------------------WELCOME TO INFORMATION PORTAL-----------------------------------------------";
	cout << endl;
	cout << "                                                                     \n";
	cout << "                                                 MY NAME IS : "<<customerinfo_firstname[loggedinindex]<<" "<<customerinfo_secondname[loggedinindex]<<endl;
	cout << "                                                                    \n";
	cout << "                                                 MY CNIC IS : "<<customerinfo_cnicnumber[loggedinindex]<<endl;
	cout << "                                                                     \n";
	cout << "                                                 MY PH. No. IS : "<<customerinfo_phonenumber[loggedinindex]<<endl;
	cout << "                                                                     \n";
	cout << "                                                 MY ADRRESS IS : "<<customerinfo_address1[loggedinindex]<<" "<<customerinfo_address2[loggedinindex]<<endl;
	cout << "                                                                     \n";
	cout << "                                                 MY ID IS : "<<loggedinuser<<endl;
	cout << "                                                                     \n";
	cout << "                                                 MY CONSUMED UNITS ARE : "<<customerinfo_unitsconsumed[loggedinindex]<<endl;
	cout << "                                                                     \n";
	cout << "                                                 MY CONNECTION DATE IS : "<<customerinfo_date[loggedinindex]<<endl;
	cout << "                                                                     \n";
	cout << "                                                 MY DUE BILL IS :"<<billinginfo_totaldue[loggedinindex]<<endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
}
void checkprices() {
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------------------------|\n";
	cout << "    (SINGLE PHASE)--(DOMESTIC)                                    |                                         (SINGLE PHASE)--(COMMERCIAL)  |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "      STANDARD COST OF ELECTRICITY :  Rs. 5/unit-                 |            STANDARD COST OF ELECTRICITY :  Rs. 15/unit-               |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "      FIXED CHARGES                :  Rs. 150/month-              |            FIXED CHARGES                :  Rs. 250/month-             |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "      TAXES                        :  17% of Domestic Money       |            TAXES                        :  20% of Domestic Money      |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "------------------------------------------------------------------|-----------------------------------------------------------------------|\n";
	cout << "     (TRIPLE PHASE)--(DOMESTIC)                                   |                                          (TRIPLE PHASE)--(COMMERCIAL) |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "     REGULAR COST OF ELECTRICITY :  Rs. 8/unit-                   |             REGULAR COST OF ELECTRICITY :  Rs. 18/unit-               |\n";
	cout << "     PEAK COST OF ELECTRICITY    :  Rs. 12/unit-                  |             PEAK COST OF ELECTRICITY    :  Rs. 25/unit-               |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "     FIXED CHARGES                :  Rs. 150/month-               |             FIXED CHARGES                :  Rs. 250/month-            |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "     TAXES                        :  17% of Domestic Money        |             TAXES                        :  20% of Domestic Money     |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "                                                                  |                                                                       |\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------------|\n";
}
void paybill() {
	if (billinginfo_status[loggedinindex] == 1) {
		cout << "                                                    YOUR BILL IS ALREADY PAID.......!!!\n\n";
	}
	if (billinginfo_status[loggedinindex] == 0) {
		cout << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "                                         -----------------WELCOME TO LESCO BILL PAYMENT BAY------------------\n\n\n\n";
		cout << "\n\n";
		cout << "                                                          __________________________________\n";
		cout << "                                                             ............................         \n";
		cout << "                                                             ENTER A VALID CREDIT CARD NO         \n";
		cout << "                                                             ............................         \n";
		cout << "                                                          ___________________________________\n\n";
		cout << "                                                                INPUT = ";
		long long input;
		while (99) {
			cin >> input;
			cout << endl;
			if (input >= 1000000000000000 && input <= 9999999999999999) {
				break;
			}
			cout << "                                                          Enter Valid CREDIT CARD Pleasee\n";
			cout << "                                                                      INPUT = ";
		}
		cout << "                                                                 YOUR BILL IS: Rs." << billinginfo_totaldue[loggedinindex] << endl;
		cout << "                                                           ARE YOU SURE YOU WANT TO PAY ??(Y/N)\n";
		cout << "                                                                      INPUT = ";
		char confirm;
		while (99) {
			cin >> confirm;
			cout << endl;
			if (confirm == 'Y' || confirm == 'y' || confirm == 'N' || confirm == 'n') {
				break;
			}
			cout << "                                                             Enter Valid CHOICE Pleasee\n";
			cout << "                                                                      INPUT = ";
		}
		if (confirm == 'Y' || confirm == 'y') {
			cout << "                                                               YOUR BILL IS PAID, THANKS\n";
			billinginfo_status[loggedinindex] = 1;
		}
			cout << "------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	}
}