#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "open_file.h"
#include "array_class.h"

using namespace std;

void SaveInputArray(Array arr) {
	cout << endl << "Do you want to save the initial data in a file?" << endl
		<< "y - Yes" << endl
		<< "n - No" << endl
		<< "Choice: ";

	string choice_repeat = "";

	do {
		cin >> choice_repeat;

		if (choice_repeat.compare("n") && choice_repeat.compare("y")) {
			cout << "There is no such action." << endl
				<< "Choice: ";
		}

	} while (choice_repeat.compare("n") && choice_repeat.compare("y"));

	if (choice_repeat.compare("n")) {
		ofstream file = OpenFileOutput();

		file << arr.GetLine() << endl << arr.GetColumn() << endl;

		int length = arr.GetMaxLengthValue();

		for (int i = 0; i < arr.GetLine(); i++) {

			for (int j = 0; j < arr.GetColumn(); j++) {

				file << setw(length) << arr[i][j] << " ";
			
			}

			file << endl;

		}

		file.close();
	}

};

void SaveChangeArray(Array arr) {
	cout << endl << "Do you want to save the result of the program?" << endl
		<< "y - Yes" << endl
		<< "n - No" << endl
		<< "Choice: ";

	string choice_repeat = "";

	do {
		cin >> choice_repeat;

		if (choice_repeat.compare("n") && choice_repeat.compare("y")) {
			cout << "There is no such action." << endl
				<< "Choice: ";
		}

	} while (choice_repeat.compare("n") && choice_repeat.compare("y"));

	if (choice_repeat.compare("n")) {
		ofstream file;
		file = OpenFileOutput();

		for (int i = 0; i < arr.GetLine(); i++) {

			for (int j = 0; j < arr.GetColumn(); j++) {

				file << arr[i][j] << " ";

			}

			file << endl;

		}

		file.close();
	}

}