#pragma once
#include "BaseShop.h"
class Monitors : public Inventory {
private:
	double screenSize;
	string resolution;
	int ports;
	double weight;
public:
	//Constructor 
	Monitors() {
		screenSize = 0;
		ports = 0;
		weight = 0;
	}
	// Setters

	void setSize(double l) {
		screenSize = l;
	}

	void setRes(string res) {
		resolution = res;
	}
	void setPorts(int p) {
		ports = p;
	}
	void setWeight(double lbs) {
		weight = lbs;
	}

	//Getters 

	double getScreenSize() {
		return screenSize;
	}
	
	string getRes() {
		return resolution;
	}
	int getPorts() {
		return ports;

	}
	double getWeight() {
		return weight;
	}

	//Display Function

	void displayScreens();
	};

void Monitors::displayScreens() {
	displayInv();
	cout << " Screen Size: " << getScreenSize() << endl;
	cout << " Resolution: " << getRes() << endl;
	cout  << " Ports: " << getPorts() << endl;
	cout  << " Weight: " << getWeight() << endl;
}