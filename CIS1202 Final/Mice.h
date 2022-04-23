#pragma once
#include "BaseShop.h"

class Mice : public Inventory {
private:
	MouseType Mtype;
public:
// Setter

	
	void setMouse(int m) {
		Mtype = static_cast<MouseType>(m);
	}

	//Diaplay function
void	displayMice();
};

void Mice::displayMice() {
	displayInv();
	switch (Mtype) {
	case 0:
		cout << " Mouse Type: Mechanical" << endl;
		break;
	case 1:
		cout << " Mouse Type: Optical" << endl;
	}
}

