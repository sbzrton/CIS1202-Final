#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//enums
enum NewUsed {NEW, USED};
enum SwitchKeys{LINEAR, TACTILE, OPTICAL};
enum MouseType{MECHANICAL, OPTICL};


//Class 
class Inventory {
private:
	
	double checkoutPrice;
	int stock;
	double price;
	NewUsed condition;
public:
	//Constructor 
	
	//Setters
	
	void setCheckout(double check) { checkoutPrice += check; }
	void setCheckout(double , double ); //overloading the checkout function

	void clearCart() { checkoutPrice = 0; }
	void setPrice(double p) { price = p; }
	void setCond(int c) { condition = static_cast<NewUsed>(c); }

	//Getters 

	
	double getPrice() { return price; }
	double getCheckout() { return checkoutPrice; }

	//Display Function
	void displayInv();

	
};

void Inventory::displayInv() {
	
	
	
	cout   << fixed << setprecision(2) << " Price: $" << getPrice() << endl;

	switch (condition) {
	case 0: 
		cout   << " Condition: NEW" << endl;
		break;
	case 1:
		cout << " Condition: USED" << endl;
		break;
	}
}



void Inventory::setCheckout( double check, double nevermind) {
	checkoutPrice = 0;
	checkoutPrice = check - nevermind;
}