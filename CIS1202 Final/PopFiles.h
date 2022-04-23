#pragma once
#include "BaseShop.h"
#include "Keybords.h"
#include "Mice.h"
#include "Monitors.h"
#include "PrePC.h"
#include "color.h"

//Prototype
void pop();

//constants
const int NAME_SIZE = 50;
const int NUM_ITEMS = 5;
const int TOTAL_INV = 17;

//Structure used for reading and writing names to and from binary files
struct GetName {
	char keyboardName[NAME_SIZE];
	char miceName[NAME_SIZE];
	char monitorName[NAME_SIZE];
	char prePcName[NAME_SIZE];
};


//instance of structure 
GetName n; 

//instances of classes
Keyboards keys[NUM_ITEMS];
Mice mouse[NUM_ITEMS];
Monitors screens[NUM_ITEMS];
PreBuiltPC Prepcs[NUM_ITEMS];


//binary file vars (for classes)
fstream keyboards;
fstream mice;
fstream monitors;
fstream pcs;

//binary file vars (for struct)
fstream keyboardName;
fstream miceName;
fstream screenName;
fstream pcName;


//Used for getting and returnning information regarding the cart/checkout process of the shop

int items = 0; //used to iterate through items arrays

int itemNums[TOTAL_INV]; //used to display item #'s in cart;

double priceItems[TOTAL_INV];
string nameItems[TOTAL_INV];
string finalNames[TOTAL_INV];
Inventory check; //used to call checkout functions in BaseShop.h

double ogOwed = 0; //used to make the user play their balance
double fixedRemainder = 0;



// Function used for populating all files
void pop() {
	string itemName; 


	//Populating binary files via struct (strings)


	//Keyboard Names
	 keyboardName.open("keyName.dat", ios::out, ios::binary);
	if (!keyboardName.is_open()) {
		cout << "Could not open file";
	}

	strcpy_s(n.keyboardName, "Keycron K2");
	keyboardName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.keyboardName, "CORSAIR Gaming K6");
	keyboardName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.keyboardName, "Logitech Multi-Device K780");
	keyboardName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.keyboardName, "HyperX Alloy Orgins");
	keyboardName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.keyboardName, "ASUS ROG Falchion");
	keyboardName.write(reinterpret_cast<char*>(&n), sizeof(n));


	keyboardName.close();
	

	//Mouse Name's



	miceName.open("miceName.dat", ios::out, ios::binary);
	if (!miceName.is_open()) {
		cout << "Could not open file";
	}

	strcpy_s(n.miceName, "Razer DeathAdder V2");
	miceName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.miceName, "Logitech G PRO Wireless");
	miceName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.miceName, "Corsair Scimitar PRO RGB");
	miceName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.miceName, "Logitech G G502 HERO");
	miceName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.miceName, "Dell MS116");
	miceName.write(reinterpret_cast<char*>(&n), sizeof(n));


	miceName.close();

	//Monitor Name's

	screenName.open("monitorName.dat", ios::out, ios::binary);
	if (!screenName.is_open()) {
		cout << "Could not open file";
	}

	strcpy_s(n.monitorName, "ViewSonic G-SYNC Monitor");
	screenName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.monitorName, "Samsumg Odessy Gaming CRG5 Series Monitor");
	screenName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.monitorName, "Birning Rapids CZ25 Series Monitor");
	screenName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.monitorName, "BenQ EW328OU 4k Monitor");
	screenName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.monitorName, "LG UltraFine IPS UHD Monitor");
	screenName.write(reinterpret_cast<char*>(&n), sizeof(n));


	screenName.close();




	//Pre Built Pc Names
	pcName.open("PrePcName.dat", ios::out, ios::binary);
	if (!pcName.is_open()) {
		cout << "Could not open file";
	}

	strcpy_s(n.prePcName, "Gaming RDY SLHRG215");
	pcName.write(reinterpret_cast<char*>(&n), sizeof(n));


	strcpy_s(n.prePcName, "GCool Series MDUJS23");
	pcName.write(reinterpret_cast<char*>(&n), sizeof(n));

	strcpy_s(n.prePcName, "AMD Creator");
	pcName.write(reinterpret_cast<char*>(&n), sizeof(n));

	pcName.close();








	//Populating binary files via class objects (no strings)
	keyboards.open("keys.dat", ios::out, ios::binary);
	if (!keyboards.is_open()) {
		cout << "Could not open file";
	}
	
	keys[0].setPrice(69.00);
	keys[0].setCond(1);
	keys[0].setSwitch(2);
	

	
	keys[1].setPrice(109.99);
	keys[1].setCond(0);
	keys[1].setSwitch(0);
	


	keys[2].setPrice(64.99);
	keys[2].setCond(1);
	keys[2].setSwitch(1);
	


	keys[3].setPrice(90.00);
	keys[3].setCond(0);
	keys[3].setSwitch(2);
	


	keys[4].setPrice(127.55);
	keys[4].setCond(0);
	keys[4].setSwitch(0);
	
	for (int i = 0; i < NUM_ITEMS; ++i) {
		keyboards.write(reinterpret_cast<char*>(&keys[i]), sizeof(keys));

	}


	
 	
	//Populating Mice file
	mice.open("mice.dat", ios::out, ios::binary);

	
	mouse[0].setPrice(69.99);
	mouse[0].setCond(1);
	mouse[0].setMouse(0);
	

	
	mouse[1].setPrice(129.99);
	mouse[1].setCond(0);
	mouse[1].setMouse(0);



	mouse[2].setPrice(79.99);
	mouse[2].setCond(1);
	mouse[2].setMouse(1);
	

	mouse[3].setPrice(85.22);
	mouse[3].setCond(0);
	mouse[3].setMouse(0);


	mouse[4].setPrice(19.99);
	mouse[4].setCond(1);
	mouse[4].setMouse(1);
	;

	for (int i = 0; i < NUM_ITEMS; ++i) {
		mice.write(reinterpret_cast<char*>(&mouse[i]), sizeof(Mice));
	}
	



	//Populating monitors file

	monitors.open("monitors.dat", ios::out, ios::binary);

	screens[0].setPrice(399.99);
	screens[0].setCond(0);
	screens[0].setSize(27);
	screens[0].setRes("1920 x 1080");
	screens[0].setPorts(7);
	screens[0].setWeight(17.4);


	screens[1].setPrice(279.99);
	screens[1].setCond(0);
	screens[1].setSize(27);
	screens[1].setRes("1920 x 1080");
	screens[1].setPorts(5);
	screens[1].setWeight(10.1);


	screens[2].setPrice(169.99);
	screens[2].setCond(1);
	screens[2].setSize(24);
	screens[2].setRes("1920 x 1080");
	screens[2].setPorts(6);
	screens[2].setWeight(7.3);
	

	screens[3].setPrice(703.99);
	screens[3].setCond(0);
	screens[3].setSize(32);
	screens[3].setRes("3840 x 2160");
	screens[3].setPorts(3);
	screens[3].setWeight(24.03);


	screens[4].setPrice(468.98);
	screens[4].setCond(1);
	screens[4].setSize(32);
	screens[4].setRes("3840 x 2160");
	screens[4].setPorts(2);
	screens[4].setWeight(18.1);

	for (int i = 0; i < NUM_ITEMS; i++) {
		monitors.write(reinterpret_cast<char*>(&screens[i]), sizeof(Monitors));

	}


	//Populating Pre-Build PCs file

	pcs.open("pcs.dat", ios::out, ios::binary);

	Prepcs[0].setPrice(1949.98);
	Prepcs[0].setCond(0);
	Prepcs[0].setMother("B550");
	Prepcs[0].setCpu("AMD Ryzen 7 5800X Processor");
	Prepcs[0].setPsu("750 Watt - 80 PLUS Gold Certified");
	Prepcs[0].setDrive("1TB M.2 NVMe SSD");
	

	Prepcs[1].setPrice(1623.50);
	Prepcs[1].setCond(0);
	Prepcs[1].setMother("ASUS PRIME Z690-P D4 ");
	Prepcs[1].setCpu("Intel Core i5-12600KF Processor");
	Prepcs[1].setPsu("600 Watt - 80 PLUS Gold Certified");
	Prepcs[1].setDrive("1TB M.2 NVMe SSD");
	

	Prepcs[2].setPrice(2468.12);
	Prepcs[2].setCond(0);
	Prepcs[2].setMother("ASUS PRIME Z690-P D4 ");
	Prepcs[2].setCpu("Intel Core i7-12700KF Processor");
	Prepcs[2].setPsu("650 Watt - 80 PLUS Gold Certified");
	Prepcs[2].setDrive("1TB M.2 NVMe SSD");

	for (int i = 0; i < 3; i++) {
		pcs.write(reinterpret_cast<char*>(&Prepcs[i]), sizeof(PreBuiltPC));
	}

	keyboards.close();
	mice.close();
	monitors.close();
	pcs.close();

	




}



