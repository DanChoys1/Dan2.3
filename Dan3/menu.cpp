#include <iostream>

using namespace std;

void ValueInputMenu(void) {
	cout << endl << "What you whant?" << endl
		<< "1)Enter data from the keyboard" << endl
		<< "2)Enter data from file" << endl
		<< "3)Enter data from random" << endl
		<< "Choice: ";
}

void EndProgramMenu(void) {
	cout << endl << "Do you want to repeat the program?" << endl
		<< "y - Yes" << endl
		<< "n - No" << endl
		<< "Choice: ";
}

void ArrayOrTestingMenu(void) {
	cout << endl << "What you whant?" << endl
		<< "1)Working with an array" << endl
		<< "2)Start test" << endl
		<< "Choice: ";
}