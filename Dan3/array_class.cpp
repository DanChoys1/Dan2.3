#include <iomanip>
#include <iostream>
#include "array_class.h"

using namespace std;

Array::Array(int ArrLine, int ArrColumn) : line(ArrLine), column(ArrColumn) {
	arr = new int*[line];

	for (int i = 0; i < line; i++) {
		arr[i] = new int[column];
	}

}

Array::Array(const Array& old_array) : column(old_array.column), line(old_array.line) {
	max_value = old_array.max_value;
	arr = new int*[line];

	for (int i = 0; i < line; i++) {
		arr[i] = new int[column];
	}

	for (int i = 0; i < line; i++) {

		for (int j = 0; j < column; j++) {
			arr[i][j] = old_array.arr[i][j];
		}

	}

}

Array::Array(Array&& old_array) : column(old_array.column), line(old_array.line) {
	max_value = old_array.max_value;

	arr = old_array.arr;
	old_array.arr = nullptr;

	old_array.line = 0;
	old_array.column = 0;
}

Array::~Array() {

	for (int i = 0; i < line; i++) {
		delete[](arr[i]);
	}

	delete[] arr;
}

Array::ColumnElements::ColumnElements(int* array) : array_line(array) {}

int &  Array::ColumnElements::operator [] (int index) {
	return array_line[index];
}

Array::ColumnElements Array::operator [] (int index) {
	ColumnElements array(arr[index]);
	return array;
}

int Array::GetColumn(void) {
	return column;
}

int Array::GetLine(void) {
	return line;
}

void Array::InitializelMaxValue(void) {
	max_value = 0;

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {

			if (abs(arr[i][j]) > abs(max_value)) {
				max_value = arr[i][j];
			}

		}
	}
}

int Array::GetMaxLengthValue(void) {
	int length = 0;
	int saved_max_value = max_value;

	while (saved_max_value / 10) {
		saved_max_value /= 10;
		length++;
	}

	length += 2;

	return length;
}

void Array::Print(void) {
	int length = GetMaxLengthValue();

	for (int i = 0; i < line; i++) {
		cout << "|";

		for (int j = 0; j < column; j++) {
			cout << setw(length) << arr[i][j] << "|";
		}

		cout << endl;
	}

}

Array & Array::operator = (Array&& old_array) {

	if (this != &old_array) {

		if (arr != nullptr) {
			for (int i = 0; i < line; i++) {
				delete[](arr[i]);
			}

			delete arr;
		}

		line = old_array.line;
		column = old_array.column;
		max_value = old_array.max_value;

		arr = old_array.arr;
		old_array.arr = nullptr;

		old_array.line = 0;
		old_array.column = 0;
	}

	return *this;
}
