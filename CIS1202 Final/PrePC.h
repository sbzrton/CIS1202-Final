#pragma once
#include "BaseShop.h"

class PreBuiltPC : public Inventory {
private:
	string motherboard;
	string cpu;
	string psu;
	string sdHd;
public:
	//setters
	
	void setMother(string m) { motherboard = m; }
	void setCpu(string c) { cpu = c; }
	void setPsu(string g) {psu = g; }
	void setDrive(string d) {	sdHd = d;}

	//Getters 

	string getMother() { return motherboard; }
	string getCpu() {return cpu;}
	string getPsu() { return psu; }
	string getDrive() { return sdHd; }

	//Displau Function 

	void displayPCs();

};

void PreBuiltPC::displayPCs() {
	displayInv();
	cout <<  " Motherboard: " << getMother() << endl;
	cout << " CPU: " << getCpu() << endl;
	cout  << " PSU: " << getPsu() <<  endl;
	cout << " Storage: " << getDrive() << endl;
}