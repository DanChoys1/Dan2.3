#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "open_file.h"
#include "array_class.h"
#include "input.h"

using namespace std;

enum Opening {
	FAILED,
	COMPLITE
};

enum ChoiceTypeInput {
	CHOICE_KEYBOARD = 1,
	CHOICE_FILE,
	CHOICE_RANDOM,
};

int GetInt(void);
void ValueInputMenu(void);

Array KeyboardInput::Read() {
	int line = 0;

	do {
		cout << endl << "Enter the number of lines of the array: ";
		line = GetInt();

		if (line <= 0) {
			cout << endl << "lines must be > 0. Try again." << endl;
		}

	} while (line <= 0);

	int column = 0;

	do {
		cout << endl << "Enter the number of columns of the array: ";
		column = GetInt();

		if (column <= 0) {
			cout << endl << "columns must be > 0. Try again." << endl;
		}

	} while (column <= 0);

	Array arr(line, column);

	for (int i = 0; i < line; i++) {

		for (int j = 0; j < column; j++) {

			cout << i + 1 << '.' << j + 1 << ")";
			arr[i][j] = GetInt();

		}

	}

	arr.InitializelMaxValue();

	return arr;
}

Array FileInput::Read() {
	int line = 0;
	int column = 0;

	while (true) {
		cout << endl << "Input data" << endl;
		ifstream file = OpenFileInput();

		try {
			string value_in_file;

			getline(file, value_in_file);
			line = stoi(value_in_file);

			if (line <= 0) {
				cout << endl << "line in file must be > 0. Try again." << endl;
				continue;
			}			

			getline(file, value_in_file);
			column = stoi(value_in_file);

			if (column <= 0) {
				cout << endl << "column in file must be > 0. Try again." << endl;
				continue;
			}

			Array arr(line, column);

			string value;
			string line_values;

			for (int i = 0; i < line; i++) {
				getline(file, line_values);
				int line_column = 0;

				for (int j = 0; j < line_values.length(); j++) {

					if ((line_values[j] == ' ') && (value != "")) {

						arr[i][line_column] = stoi(value);

						line_column++;
						value = "";
					} else {

						if (line_values[j] != ' ') {
							value += line_values[j];
						}

					}

				}

			}

			cout << "Input line = " << line << endl;
			cout << "Input column = " << column << endl;

			file.close();

			arr.InitializelMaxValue();

			return arr;
		} catch (invalid_argument inv_arg) {
			cout << endl << "The value in the file are not correct. Try again." << endl;
		}

	}

}

Array RondomInput::Read() {
	int line = 0;
	int column = 0;

	do {
		cout << endl << "Enter the number of lines of the array: ";
		line = GetInt();

		if (line <= 0) {
			cout << endl << "lines must be > 0. Try again." << endl;
		}

	} while (line <= 0);

	do {
		cout << endl << "Enter the number of columns of the array: ";
		column = GetInt();

		if (column <= 0) {
			cout << endl << "columns must be > 0. Try again." << endl;
		}

	} while (column <= 0);

	Array arr(line, column);

	srand((unsigned int)time(NULL));
	int random_limits = 0;

	do {
		cout << endl << "Random numbers in a range (-a, a)" << endl
			<< "Enter a: ";
		random_limits = GetInt();

		if (random_limits <= 0) {
			cout << endl << "a must be > 0. Try again." << endl;
		}

	} while (random_limits <= 0);

	for (int i = 0; i < line; i++) {

		for (int j = 0; j < column; j++) {

			if (rand() % 2) {

				arr[i][j] = rand() % random_limits;

			} else {

				arr[i][j] = -1 * (rand() % random_limits);

			}

		}

	}

	arr.InitializelMaxValue();

	return arr;
}

unique_ptr<Input> InputType(bool *user_selected_file_input) {
int choice = 0;

do {
	ValueInputMenu();
	choice = GetInt();

	if (choice == CHOICE_KEYBOARD) {

		return unique_ptr<KeyboardInput>(new KeyboardInput);

	} else if (choice == CHOICE_FILE) {

		*user_selected_file_input = true;
		return unique_ptr<FileInput>(new FileInput);

	} else if (choice == CHOICE_RANDOM) {

		return unique_ptr<RondomInput>(new RondomInput);

	} else {

		cout << "There is no such action" << endl;

	}

} while ((choice != CHOICE_KEYBOARD) && (choice != CHOICE_FILE)
	&& (choice != CHOICE_RANDOM));

	exit(0);
}
