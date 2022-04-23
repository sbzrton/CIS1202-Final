//Sha'Maria Barton
//CIS1202 K01
//April 18th, 2022

//Including base and derived classes 
#include "BaseShop.h"
#include "Keybords.h"
#include "Mice.h"
#include "Monitors.h"
#include "PrePC.h"
#include "color.h"
#include "PopFiles.h"
#include "totalCheckTemp.h"

//Function Prototypes 

int menuChoice(int&);
void buyItems();   
void displayItems(int);

void sellMenu();
void sellItems(string); //(inspired by gamestop


void viewCart();
void checkOut(Inventory); //Used to check the user out



 int main() {

	 pop();

	//int used for user menu choice
	int usr = 0;
	
	system("CLS");
	
	cout << dye::blue("\n Welcome to our store!! Refer to the menu below to get started.") << "\n\n";

	do{

	menuChoice(usr);

	check.clearCart(); //clearing cart when user is directed back to the home screen
	
	
		switch (usr) {
		case 1:
			buyItems();
			break;
		case 2:
			sellMenu();
			break;
		case 3:
			exit(0);
			break;
		}
	} while (usr != 3);

	
	cin.ignore(INT_MAX);
}

//fucntion used for displaying a menu, and returning user input for the switch in main

int menuChoice(int& choice) {

	cout << "\n 1. Buy\n 2. Sell\n 3. Exit" << endl;
	cout << " Enter in your choice: ";
	
	while (!(cin >> choice) || choice < 1 || choice > 3 || cin.fail()) {
		cout << "\nPlease enter a valid menu item: ";
		cin.clear();
		cin.ignore(100, '\n');

	};

	return choice;
}




//function used to allow the user to purchase items

void buyItems() {

	
	system("CLS"); //Clearing screen to make output look "cleaner"

	int placeHold = 1;//int soley used to send the user back to the main menu. Nothing else.
	int usrBuy = 0; //used for obtaining users user choice
	int cat = 0; //used for displaying different categories depending on user menu choice

	cout << dye::blue(" \n Please choose a category to  purchase from.") << endl;
	do {
	
		cout <<dye::grey( "\n 1. Shop Keyboards\n 2. Shop Mice\n 3. Shop Monitors\n 4. Shop Pre-Built PCs\n 5. Back to Home \n 6. View Cart/Checkout") << endl;
		cout << dye::light_red(" Enter in your choice: ");
		while (!(cin >> usrBuy) || usrBuy < 1 || usrBuy >6 || cin.fail()) {
			cout << "\nPlease enter a valid menu item: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		

		switch (usrBuy) {

		case 1:
			cat = 1;
			displayItems(cat);
			break;
		case 2:
			cat = 2;
			displayItems(cat);
			break;
		case 3:
			cat = 3;
			displayItems(cat);
			break;
		case 4:
			cat = 4;
			displayItems(cat );
			break;
		case 5:
			
			main(); //Sending user back to main
				break;
		case 6:
			
			viewCart();
			break;

		}

	} while (usrBuy != 6);
}

/*Function used for displaying item categories depending on what the user chooses
in the second switch statement(located in the buyItems function) */

void displayItems(int category ) {
	//Reading in keybaords
	system("CLS");


	int userItemNum = 0;
	if (category == 1) {

		int itemNum = 1;
		
	 keyboards.open("keys.dat", ios::in, ios::binary);
		keyboardName.open("keyName.dat", ios::in, ios::binary);
		
		if (!keyboards.is_open()) {

			cout << "\n\nERROR! File could not be opened" << endl;
		}
		else {
			cout << "\n\n";
			cout << setw(60) << dye::purple("KEYBOARDS") << "\n";


			keyboards.clear();
			keyboards.seekg(0L, ios::beg);


			keyboards.read(reinterpret_cast<char*>(&keys[0]), sizeof(Keyboards));
			keyboardName.read(reinterpret_cast<char*>(&n), sizeof(n));

			cout << "\n";
			
			while (keyboards) {

				itemNums[items] = itemNum;
				nameItems[items] = n.keyboardName;
				priceItems[items] = keys[0].getPrice();
				items++;
				
				cout << dye::light_green(" \n\n Item #") << dye::light_green(itemNum); itemNum++;
				cout << "\n Name: " << n.keyboardName << endl;
				keys[0].displayKeys(); //The keys[0] will not only print the first value in the keys array. Everything displays
									   //The 0 is just a placeholder in this instance.


				keyboards.read((char*)&keys[0], sizeof(keys));
				keyboardName.read(reinterpret_cast<char*>(&n), sizeof(n));
			}
			keyboards.close();
			keyboardName.close();
		}
	
		
				cout << dye::blue("\n\n\n Enter in the number of the item you would like to purchase: ");
				while (!(cin >> userItemNum) || userItemNum < 1 || userItemNum > 5 || cin.fail()) {
					cout << "\nInvalid item number. Please refer to the green text and try again: ";
					cin.clear();
					cin.ignore(100, '\n');
				}

				userItemNum = userItemNum - 1;
				
				finalNames[userItemNum] = nameItems[userItemNum];
				
			check.setCheckout(priceItems[userItemNum]);
			
	}

	//Reading in mice
	else if (category == 2) {

		int itemNum = 6;
		items = 5;
		miceName.open("miceName.dat", ios::in, ios::binary);
		mice.open("mice.dat", ios::in, ios::binary);

		cout << "\n\n";
		cout << setw(60) << dye::green("MICE") << endl;
		mice.clear();
		mice.seekg(0L, ios::beg);

		if (!mice.is_open()) {

			cout << "\n\nERROR! File could not be opened" << endl;
		}
		
		else {
			mice.read((char*)&mouse[0], sizeof(Mice));
			miceName.read(reinterpret_cast<char*>(&n), sizeof(n));

			while (mice) {


				itemNums[items] = itemNum;
				nameItems[items] = n.miceName;
				priceItems[items] = mouse[0].getPrice();
				items++;
				cout << dye::blue(" \n\n Item #") << dye::blue(itemNum); itemNum++;
				cout << "\n Name: " << n.miceName << endl;
				mouse[0].displayMice();


				mice.read((char*)&mouse[0], sizeof(Mice));
				miceName.read(reinterpret_cast<char*>(&n), sizeof(n));

			}
			mice.close();
			miceName.close();
		}

		cout << dye::blue("\n\n\n Enter in the number of the item you would like to purchase: ");
		while (!(cin >> userItemNum) || userItemNum < 6 || userItemNum > 10 || cin.fail()) {
			cout << "\nInvalid item number. Please refer to the blue text and try again: ";
			cin.clear();
			cin.ignore(100, '\n');
		}

		userItemNum = userItemNum - 1;



		finalNames[userItemNum] = nameItems[userItemNum];
		check.setCheckout(priceItems[userItemNum]);
			
		
	}


	//Reading in monitors 
	else if (category ==3){
	
	int itemNum = 11;
	items = 10;
		screenName.open("monitorName.dat", ios::in, ios::binary);
		monitors.open("monitors.dat", ios::in, ios::binary);

		cout << "\n\n";
		cout << setw(60) << dye::aqua("MONITORS") << endl;
		monitors.clear();
		monitors.seekg(0L, ios::beg);

		if (!monitors.is_open()) {

			cout << "\n\nERROR! File could not be opened" << endl;
		}

		else {
			monitors.read((char*)&screens[0], sizeof(Monitors));
			screenName.read(reinterpret_cast<char*>(&n), sizeof(n));

			while (monitors) {



				itemNums[items] = itemNum;
				nameItems[items] = n.monitorName;
				priceItems[items] = screens[0].getPrice();
				items++;
				cout << dye::red(" \n\n Item #") << dye::red(itemNum); itemNum++;
				cout << "\n Name: " << n.monitorName << endl;
				screens[0].displayScreens();



				monitors.read((char*)&screens[0], sizeof(Monitors));
				screenName.read(reinterpret_cast<char*>(&n), sizeof(n));

			}
			monitors.close();
			screenName.close();
		}

		cout << dye::blue("\n\n\n Enter in the number of the item you would like to purchase: ");
		while (!(cin >> userItemNum) || userItemNum < 11 || userItemNum > 15 || cin.fail()) {
			cout << "\nInvalid item number. Please refer to the red text and try again: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		userItemNum = userItemNum - 1;


		finalNames[userItemNum] = nameItems[userItemNum];
		check.setCheckout(priceItems[userItemNum]);

	}

	//Reading in pre-built pcs
	else if (category == 4) {
	int itemNum = 15;
	items = 14;
	pcName.open("PrePcName.dat", ios::in, ios::binary);
	pcs.open("pcs.dat", ios::in, ios::binary);

	cout << "\n\n";
	cout << setw(60) << dye::light_blue("PRE-BUILT PCs") << endl;
	pcs.clear();
	pcs.seekg(0L, ios::beg);

	if (!pcs.is_open() || !pcName.is_open()) {

		cout << "\n\nERROR! File(s) could not be opened" << endl;
	}

	else {
		pcs.read((char*)&Prepcs[0], sizeof(PreBuiltPC));
		pcName.read(reinterpret_cast<char*>(&n), sizeof(n));

		while (pcs) {

			itemNums[items] = itemNum;
			nameItems[items] = n.prePcName;
			priceItems[items] = Prepcs[0].getPrice();
			items++;

			cout << dye::purple(" \n\n Item #") << dye::purple(itemNum); itemNum++;
			cout << "\n Name: " << n.prePcName << endl;
			Prepcs[0].displayPCs();


			pcs.read((char*)&Prepcs[0], sizeof(PreBuiltPC));
			pcName.read(reinterpret_cast<char*>(&n), sizeof(n));

		}
		pcs.close();
		pcName.close();
	}

	cout << dye::blue("\n\n\n Enter in the number of the item you would like to purchase: ");
	while (!(cin >> userItemNum) || userItemNum < 15 || userItemNum > 17 || cin.fail()) {
		cout << "\nInvalid item number. Please refer to the purple text and try again: ";
		cin.clear();
		cin.ignore(100, '\n');
	}
	userItemNum = userItemNum - 1;


	finalNames[userItemNum] = nameItems[userItemNum];
	check.setCheckout(priceItems[userItemNum]);

	}
}

//Funciton used to let the user sell items to the store (and lowball them ridiculously)

void sellMenu() {
	system("CLS");

	int usrSell = 0; //user menu input
	string category; //String containing category of item to sell (keyboard, mouse, monitor, etc.)

	cout << dye::red("\n\n Hello. You are currently attempting to sell the item of your choice, lets get started.");
	cout << dye::black_on_light_yellow("\n\n *Reminder* All sales are FINAL.");
	cout << "\n\n";
	cout << dye::grey("\n 1. Sell Keyboards\n 2. Sell Mice\n 3. Sell Monitors\n 4. Sell Pre-Built PCs\n 5. Back to Home") << endl;
	cout << dye::light_red(" Enter in your choice: ");

	while (!(cin >> usrSell) || usrSell < 0 || usrSell > 5 || cin.fail()) {
		cout << " Please enter in a valid menu option (1-5).";
		cin.clear();
		cin.ignore(100, '\n');
	}


	switch (usrSell) {
	case 1:
		category = "Keyboard";
		sellItems(category);

		break;
	case 2:
		category = "Mouse";
		sellItems(category);

		break;
	case 3:
		category = "Monitor";
		sellItems(category);

		break;
	case 4:

		category = "Pre-Built PC";
		sellItems(category);
		break;

	case 5:
		main();
		break;
	}
}

//Function used for allowing user to sell an item and printing out a random price the company is willing to pay
void sellItems(string itemCat) {

	string userInput; 
	string notFair; //Placeholder variable used to get the strings after asking for the item name (not needed since the price for each item is going to be randomized)

	system("CLS");
	cout << dye::red("\n\n You are deciding to sell an item in the ") << dye::light_aqua(itemCat) << dye::red(" category");
	cout << dye::red(" Please enter in the following information: ");

	if (itemCat == "Keyboard") {

		getline(cin, userInput);
		cout << "\n\n Enter in the name of your keyboard: ";
		getline(cin, userInput);
		cout << "\n Enter in the color switch your keyboard has: ";
		getline(cin, notFair);

		system("CLS");
		cout << dye::yellow("\n\n For your keyboard: ") << dye::blue(userInput) << dye::yellow(" you are given: ");
		srand(time(NULL));
		double a = rand() % 50 + 10.99;
		cout << fixed << setprecision(2) << dye::red(" $") << dye::red(a);

		cout << dye::blue("\n\n\n\n We appreciate your donation :) Press 1 to exit or 2 to go back to home!");
		int userFinal = 0; //used to send user back to main or exit the program
		cout << "\n Enter your choice: ";
		while(!(cin >> userFinal) || userFinal < 1 || userFinal > 2 || cin.fail()) {
			cout << " Please enter in a valid menu item (1-2): ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		switch (userFinal) {
		case 1:
			exit(0);
			break;
		case 2:
			main();
			break;
		}
	}

	else if (itemCat == "Mouse") {

		getline(cin, userInput);
		cout << "\n\n Enter in the name of your mouse: ";
		getline(cin, userInput);
		cout << "\n Enter in whether or not your mouse is mechanical or optical: ";
		getline(cin, notFair);

		system("CLS");
		cout << dye::yellow("\n\n For your mouse: ") << dye::blue(userInput) << dye::yellow(" you are given: ");
	

		srand(time(NULL));
		double a = rand() % 25 + 5.99;
		cout << fixed << setprecision(2) << dye::red(" $") << dye::red(a);

		cout << dye::blue("\n\n\n\n We appreciate your donation :) Press 1 to exit or 2 to go back to home!");
		int userFinal = 0; //used to send user back to main or exit the program
		cout << "\n Enter your choice: ";
		while (!(cin >> userFinal) || userFinal < 1 || userFinal > 2 || cin.fail()) {
			cout << " Please enter in a valid menu item (1-2): ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		switch (userFinal) {
		case 1:
			exit(0);
			break;
		case 2:
			main();
			break;
		}
	}

	else if (itemCat == "Monitor") {
		
		getline(cin, userInput);
		cout << "\n\n Enter in the name of your monitor: ";
		getline(cin, userInput);

		cout << "\n Enter in the screen size of your monitor: ";
		getline(cin, notFair);

		cout << "\n Enter in the resoution that your monitor has: ";
		getline(cin, notFair);

		cout << "\n Enter in the amount of ports your monitor has: ";
		getline(cin, notFair);

		cout << "\n Enter in how much your monitor weighs (lbs): ";
		getline(cin, notFair);


		system("CLS");
		cout << dye::yellow("\n\n For your monitor: ") << dye::blue(userInput) << dye::yellow(" you are given: ");


		srand(time(NULL));
		double a = rand() % 200 + 70.58;
		cout << fixed << setprecision(2) << dye::red(" $") << dye::red(a);

		cout << dye::blue("\n\n\n\n We appreciate your donation :) Press 1 to exit or 2 to go back to home!");
		int userFinal = 0; //used to send user back to main or exit the program
		cout << "\n Enter your choice: ";
		while (!(cin >> userFinal) || userFinal < 1 || userFinal > 2 || cin.fail()) {
			cout << " Please enter in a valid menu item (1-2): ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		switch (userFinal) {
		case 1:
			exit(0);
			break;
		case 2:
			main();
			break;
		}
	}


	else if (itemCat == "Pre-Built PC") {

		getline(cin, userInput);
		cout << "\n\n Enter in the name of your PC: ";
		getline(cin, userInput);

		cout << "\n Enter in the name of your PCs motherboard: ";
		getline(cin, notFair);

		cout << "\n Enter in the name of your PCs CPU: ";
		getline(cin, notFair);

		cout << "\n Enter in the name of your PCs PSU: ";
		getline(cin, notFair);

		cout << "\n Enter in the name of your PCs storage (HDD or SSD): ";
		getline(cin, notFair);

		system("CLS");
		cout << dye::yellow("\n\n For your PC: ") << dye::blue(userInput) << dye::yellow(" we are willing to give you: ");



		srand(time(NULL));
		double a = rand() % 500 + 100.57;
		cout << fixed << setprecision(2) << dye::red(" $") << dye::red(a);

		cout << dye::blue("\n\n\n\n We appreciate your donation :) Press 1 to exit or 2 to go back to home!");
		int userFinal = 0; //used to send user back to main or exit the program
		cout << "\n Enter your choice: ";
		while (!(cin >> userFinal) || userFinal < 1 || userFinal > 2 || cin.fail()) {
			cout << " Please enter in a valid menu item (1-2): ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		switch (userFinal) {
		case 1:
			exit(0);
			break;
		case 2:
			main();
			break;
		}
	}
}


//Function used for allowing the user to view their cart and make adjustments to 
// -what they want to purchase (this function works with an overloaded function

void viewCart() {
	system("CLS");
	cout << setw(60) << dye::blue("CART") << "\n";

	cout << dye::red("\n\n Your items: ") << "\n\n";


	//Printing items from inventory IF the user has added them to their cart
	int size = sizeof(finalNames) / sizeof(finalNames[0]);
	for (int i = 0; i < size; i++) {
		if (finalNames[i] != "" && priceItems[i] != 0) {
			cout << dye::yellow("Item #" )<< dye::yellow(itemNums[i]) << " " << finalNames[i] << ": " << priceItems[i] << endl;
		}
	}

	//Adjusting net price dependig on if the user wants to remove items from cart
	double netPrice = 0; 
	double removedPrice = 0;
	int rmItems = 0;

	char yesOrNo = 'Y';


	cout << dye::blue("\n\n Remove items? (y or n): "); cin >> yesOrNo;
		yesOrNo = tolower(yesOrNo);
	if (yesOrNo == 'y') {
		cout << dye::green(" Which item would you like to remove (refer to item #): ");
		while (!(cin >> rmItems) || rmItems < 1 || rmItems > 17 || cin.fail()) {
			cout << " Incorrect item #. Make sure the number ranges from 1-17.";
			cin.clear();
			cin.ignore(100, '\n');
	}
		rmItems = rmItems - 1;
		for (int i = 0; i < TOTAL_INV; i++) {
			if (finalNames[i] != "" && priceItems[i] != 0) {
				netPrice += priceItems[i];
			}
			

		}

		removedPrice = priceItems[rmItems];
		priceItems[rmItems] = 0;
		finalNames[rmItems] = "";
		check.setCheckout(netPrice, removedPrice);
		

		//Sending user either to the menu or letting them view their cart again
		if (check.getCheckout() == 0) {
			system("CLS");
			cout << dye::red("\n\n Cart is empty. Returning back to menu.... \n\n");

			Sleep(700);
			system("CLS");
			buyItems();
			
		}
		else {
			viewCart();
		}
		
	}


	else if (tolower(yesOrNo) == 'n') {
		cout << dye::blue("\n\n Go to checkout? (y or n): "); cin >> yesOrNo;
		yesOrNo = tolower(yesOrNo);


		//Validating that the user enters in the right letters
		if (yesOrNo != 'y' && yesOrNo != 'n') {
			while (yesOrNo != 'y' && yesOrNo != 'n') {
				cout << dye::red(" Please enter in either y or n: ");
				cin >> yesOrNo;
				yesOrNo = tolower(yesOrNo);

				cin.clear();
				cin.ignore(100, '\n');
			}
		}

		
		
			if (tolower(yesOrNo) == 'y') {

				checkOut(check);
			}
			else if (tolower(yesOrNo) == 'n') {
				buyItems();
			}
		
	}
	
	
}


//Function used for checking out the user and charging their account
//Tax on items is a default .60

void checkOut(Inventory c) {
	system("CLS");
	
	cout << setw(60) << dye::purple("CHECK-OUT") << "\n";
	cout << fixed << setprecision(2) << dye::blue("\n\n Subtotal: ") << dye::light_aqua("$") << dye::light_aqua(c.getCheckout());
	cout << fixed << setprecision(2) << dye::purple("\n Tax (6%): ") << dye::light_purple("$") << dye::light_purple(getTax(c.getCheckout())) << endl;
	cout << fixed << setprecision(2) << dye::red("\n A total of: ") << dye::light_red("$") << dye::light_red(finalPrice(c.getCheckout()))
		<< dye::red(" Has been charged to your account! ");


	cout << "\n\n THANK YOU FOR SHOPPING WITH US!!!!!!";
	
	Sleep(3000);
	system("CLS");
	main();
	
	
	
}

