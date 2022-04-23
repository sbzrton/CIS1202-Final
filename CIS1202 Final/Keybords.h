#pragma once

#include "BaseShop.h"


class Keyboards :public Inventory {
private:
	 SwitchKeys switchType;
public:
	// Setter
	
	void setSwitch(int s) {
		switchType = static_cast<SwitchKeys>(s);
	}

	//Display Function

	void displayKeys();
};

void Keyboards::displayKeys() {

	displayInv();

	switch (switchType) {
	case 0:
		cout << " Switch Type: Linear" << endl;
		break;
	case 1:
		cout << " Switch Type: Tactile" << endl;
		break;
	case 2:
		cout <<  " Switch Type: Optical" << endl;
		break;
	}
}
