#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
//----------------------- GLOBAL MEMORY -------------------------//
//------------------ GLOBAL MEMORY 1 (C.INFO)--------------------//
int customerinfo_customerid[4] = {};
long long customerinfo_cnicnumber[4] = {};
string customerinfo_firstname[4] = {};
string customerinfo_secondname[4] = {};
string customerinfo_address1[4] = {};
string customerinfo_address2[4] = {};
unsigned long customerinfo_phonenumber[4] = {};
char customerinfo_customertype[4] = {};
char customerinfo_metretype[4] = {};
long customerinfo_date[4] = {};
float customerinfo_unitsconsumed[4] = {};         //0000000000000000000000000000000000000000000000000000000000
float customerinfo_peakhourunits[4] = {};         //0000000000000000000000000000000000000000000000000000000000
//-------------------------- LOADERS 1--------------------------//
char commastorer = ',';
ifstream readhead;
ofstream writehead;
//////////////////////////////////////////////////////////////////
//-------------- GLOBAL MEMORY 2 (TarrifTaxInfo)----------------//
string tarriftaxinfo_metrename[4] = {};
float tarriftaxinfo_regunitprice[4] = {};         //0000000000000000000000000000000000000000000000000000000000
float tarriftaxinfo_peakunitprice[4] = {};        //0000000000000000000000000000000000000000000000000000000000
float tarriftaxinfo_taxes[4] = {};                //0000000000000000000000000000000000000000000000000000000000
float tarriftaxinfo_fixedcharges[4] = {};         //0000000000000000000000000000000000000000000000000000000000
//-------------------------- LOADERS 2--------------------------//
ifstream readhead2;
ofstream writehead2;
//////////////////////////////////////////////////////////////////
//-------------- GLOBAL MEMORY 3 (TarrifTaxInfo)----------------//
long nadradb_issuedate[4] = {};
long nadradb_expirydate[4] = {};
//-------------------------- LOADERS 3--------------------------//
ifstream readhead3;
ofstream writehead3;
long long waste;
//////////////////////////////////////////////////////////////////
//-------------- GLOBAL MEMORY 4 (EmpData File)-----------------//
string empdata_unp[4] = {};
//-------------------------- LOADERS 4--------------------------//
ifstream readhead4; 
ofstream writehead4;
//-------------- GLOBAL MEMORY 5 (BillingInfo File)-----------------//
string billinginfo_monthname[4] = {};  
float billinginfo_currentunitsreg[4] = {};          //0000000000000000000000000000000000000000000000000000000000
float billinginfo_currentunitspeak[4] = {};         //0000000000000000000000000000000000000000000000000000000000
long billinginfo_readingdate[4] = {};
float billinginfo_costofelec[4] = {};
float billinginfo_salestax[4] = {};                 //0000000000000000000000000000000000000000000000000000000000
float billinginfo_fixamount[4] = {};                //0000000000000000000000000000000000000000000000000000000000
float billinginfo_totaldue[4] = {};                 //0000000000000000000000000000000000000000000000000000000000
long billinginfo_duedate[4] = {};
int billinginfo_status[4] = {};
long billinginfo_payingdate[4] = {};             
//-------------------------- LOADERS 5--------------------------//
ifstream readhead5;
ofstream writehead5;
int waste5;
//------------------- GLOBAL MEMORY (UNANIMOUS) ----------------//
int loggedinuser=1011;
int loggedinindex = 0;
string supremeloggedin;
int supremeindex=0;
string supremesecret;