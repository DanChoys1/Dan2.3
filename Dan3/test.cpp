#include <iostream>
#include <cmath>
#include "array_class.h"
#include "sort.h"

using namespace std;

const int ALL_TEST_PASSED = 5;

enum IncorrectSorting {
	ARR_BUBBLE_SORT,
	ARR_SELECTION_SORT,
	ARR_INSERTION_SORT,
	ARR_SHELL_SORT
};

bool TestingProgram(Array entered_arr, Array expected_arr_change, int value_test_passed) {
	Bubble_Sort bubble_sort;
	Array array_bubble_sort = bubble_sort.Sort(entered_arr);

	Selection_Sort selection_sort;
	Array arr_selection_sort = selection_sort.Sort(entered_arr);

	Insertion_Sort insertion_sort;
	Array arr_insertion_sort = insertion_sort.Sort(entered_arr);

	Shell_Sort shell_sort;
	Array arr_shell_sort = shell_sort.Sort(entered_arr);

	Quick_Sort quick_sort;
	Array arr_quick_sort = quick_sort.Sort(entered_arr);


	try {

		for (int i = 0; i < entered_arr.GetLine(); i++) {
			for (int j = 0; j < entered_arr.GetColumn(); j++) {

				if(abs(array_bubble_sort[i][j]) != abs(arr_selection_sort[i][j])) throw ARR_BUBBLE_SORT;
				if (abs(arr_selection_sort[i][j]) != abs(arr_insertion_sort[i][j])) throw ARR_SELECTION_SORT;
				if (abs(arr_insertion_sort[i][j]) != abs(arr_shell_sort[i][j])) throw ARR_INSERTION_SORT;
				if (abs(arr_shell_sort[i][j]) != abs(arr_quick_sort[i][j])) throw ARR_SHELL_SORT;
				if(abs(arr_quick_sort[i][j]) != abs(expected_arr_change[i][j])) throw i;

			}
		}

		return true;

	} catch (IncorrectSorting incorrect_sorting) {

		if (incorrect_sorting == ARR_BUBBLE_SORT) {
			cout << endl << "Test" << value_test_passed + 1 << " faild" << endl
				<< "Bubble Sort does not equal Selection Sort" << endl
				<< "Bubble Sort" << endl;
			array_bubble_sort.Print();
			
			cout << "Selection Sort" << endl;
			arr_selection_sort.Print();
		}

		if (incorrect_sorting == ARR_SELECTION_SORT) {
			cout << endl << "Test" << value_test_passed + 1 << " faild" << endl
				<< "Selection Sort does not equal Insertion Sort" << endl
				<< "Selection Sort" << endl;
			arr_selection_sort.Print();

			cout << "Insertion Sort" << endl;
			arr_insertion_sort.Print();
		}

		if (incorrect_sorting == ARR_INSERTION_SORT) {
			cout << endl << "Test" << value_test_passed + 1 << " faild" << endl
				<< "Shell Sort does not equal Insertion Sort" << endl
				<< "Shell Sort" << endl;
			arr_shell_sort.Print();

			cout << "Insertion Sort" << endl;
			arr_insertion_sort.Print();
		}

		if (incorrect_sorting == ARR_SHELL_SORT) {
			cout << endl << "Test" << value_test_passed + 1 << " faild" << endl
				<< "Shell Sort does not equal Quick Sort" << endl;
			cout << "Shell Sort" << endl;
			arr_shell_sort.Print();

			cout << "Quick Sort" << endl;
			arr_quick_sort.Print();
		}

	} catch (int line_value) {
		cout << endl <<  "Test" << value_test_passed + 1 << " failed. Mismatch found in " << line_value + 1 << " item" << endl;
		cout << "Input array:" << endl;
		entered_arr.Print();

		cout << endl << "Expected output array:" << endl;
		expected_arr_change.Print();

		cout << endl << "Output array:" << endl;
		arr_quick_sort.Print();

		return false;
	}
}

void Test(void) {
	int value_test_passed = 0;
	const int line_test1 = 3;
	const int column_test1 = 10;
	int entered_data_test1[line_test1][column_test1] = { {-22,  75,  61, -22, -53,  34,  23, -7,   2, -84 },
	{ 86, -32,  34,  41, -47,  47,   9, -70,  91,  58 },
	{-86,  82,  95, -95,  78, -50, -33, -41, -84, -34} };

	Array entered_arr_test1(line_test1, column_test1);

	for (int i = 0; i < line_test1; i++) {
		for (int j = 0; j < column_test1; j++) {
			entered_arr_test1[i][j] = entered_data_test1[i][j];
		}
	}

	entered_arr_test1.InitializelMaxValue();

	int expected_result_test1[line_test1][column_test1] = { {86, 82, 95, -95, 78, -50, -33, -70, 91, -84 },
	{-86, 75, 61, 41, -53, 47, 23, -41, -84, 58 },
	{-22, -32, 34, -22, -47, 34, 9, -7, 2, -34 } };

	Array expected_arr_change_test1(line_test1, column_test1);

	for (int i = 0; i < line_test1; i++) {
		for (int j = 0; j < column_test1; j++) {
			expected_arr_change_test1[i][j] = expected_result_test1[i][j];
		}
	}

	expected_arr_change_test1.InitializelMaxValue();

	if (TestingProgram(move(entered_arr_test1), move(expected_arr_change_test1), value_test_passed) == true) {
		value_test_passed++;
	}

	const int column_test2 = 10;
	const int line_test2 = 10;
	int entered_data_test2[line_test2][column_test2] = { {6, -3,  0,  9,  6,  4, -3, -1, -8,  7},
	{8,  1,  0,  4,  1,  3,  9,  8, -5,  0},
	{9,  8,  2, -7, -7, -8,  2,  9, -4,  7},
	{-8, -4, -3, -4,  2,  4,  2, -2,  2,  2},
	{-7, -9, -5, -4, -8,  0,  2, -1, -4,  4},
	{-3,  5, -8, -9,  4,  3,  7, -5,  5, -9},
	{5,  1,  3,  2, -6,  5,  6, -8, -4,  8},
	{-7, -5, -1, -9,  0, -8,  6,  9,  9, -8},
	{3,  4,  4, -9, -2, -3,  5, -3, -5,  9},
	{3, -5, -7,  4,  7, -9, -5,  7, -6, -7} };

	Array entered_arr_test2(line_test2, column_test2);

	for (int i = 0; i < line_test2; i++) {
		for (int j = 0; j < column_test2; j++) {
			entered_arr_test2[i][j] = entered_data_test2[i][j];
		}
	}

	entered_arr_test2.InitializelMaxValue();

	int expected_result_test2[line_test2][column_test2] = { {9, -9, -8, 9, -8, -9, 9, 9, 9, -9 },
	{8, 8, -7, -9, 7, -8, 7, 9, -8, 9 },
	{-8, -5, -5, -9, -7, -8, 6, -8, -6, -8 },
	{-7, -5, 4, -9, -6, 5, 6, 8, -5, 8 },
	{-7, 5, -3, -7, 6, 4, 5, 7, -5, -7 },
	{6, -4, 3, -4, 4, 4, -5, -5, 5, 7 },
	{5, 4, 2, -4, -2, 3, -3, -3, -4, 7 },
	{-3, -3, -1, 4, 2, 3, 2, -2, -4, 4 },
	{3, 1, 0, 4, 1, -3, 2, -1, -4, 2 },
	{3, 1, 0, 2, 0, 0, 2, -1, 2, 0 } };

	Array expected_arr_change_test2(line_test2, column_test2);

	for (int i = 0; i < line_test2; i++) {
		for (int j = 0; j < column_test2; j++) {
			expected_arr_change_test2[i][j] = expected_result_test2[i][j];
		}
	}

	expected_arr_change_test2.InitializelMaxValue();
	
	if (TestingProgram(move(entered_arr_test2), move(expected_arr_change_test2), value_test_passed) == true) {
		value_test_passed++;
	}

	const int column_test3 = 5;
	const int line_test3 = 5;
	int entered_data_test3[line_test3][column_test3] = { {-48,  98, -68,  65,  39 },
	{ 91,  16, -89, -78,  35 },
	{-55,  38,  33, -38,  49 },
	{-80, -43,  77,  77,  18 },
	{ 11, -70, -34,  97,  91 } };

	Array entered_arr_test3(line_test3, column_test3);

	for (int i = 0; i < line_test3; i++) {
		for (int j = 0; j < column_test3; j++) {
			entered_arr_test3[i][j] = entered_data_test3[i][j];
		}
	}

	entered_arr_test3.InitializelMaxValue();

	int expected_result_test3[line_test3][column_test3] = { {91, 98, -89, 97, 91 },
	{80, -70, 77, -78, 49 },
	{-55, -43, -68, 77, 39 },
	{-48, 38, -34, 65, 35 },
	{11, 16, 33, -38, 18 } };

	Array expected_arr_change_test3(line_test3, column_test3);

	for (int i = 0; i < line_test3; i++) {
		for (int j = 0; j < column_test3; j++) {
			expected_arr_change_test3[i][j] = expected_result_test3[i][j];
		}
	}

	expected_arr_change_test3.InitializelMaxValue();

	if (TestingProgram(move(entered_arr_test3), move(expected_arr_change_test3), value_test_passed) == true) {
		value_test_passed++;
	}

	const int column_test4 = 7;
	const int line_test4 = 7;
	int entered_data_test4[line_test4][column_test4] = { { -6, -65,   4,  32,  23, -69, -82 },
	{ 42, -32, -16,  58,  78, -83, -89 },
	{ 99, -84, -18,  95, -66, -57,  72 },
	{-74, -83, -46, -90,  72,  98,  42 },
	{ 50,  38, -43,  40,  43,  56, -50 },
	{ 22, -79,  76,  43,  76,  68,  59 },
	{-76, -6,  80, -7, -38,  69, -48 } };

	Array entered_arr_test4(line_test4, column_test4);

	for (int i = 0; i < line_test4; i++) {
		for (int j = 0; j < column_test4; j++) {
			entered_arr_test4[i][j] = entered_data_test4[i][j];
		}
	}

	entered_arr_test4.InitializelMaxValue();

	int expected_result_test4[line_test4][column_test4] = { {99, -84, 80, 95, 78, 98, -89 },
	{-76, -83, 76, -90, 76, -83, -82 },
	{-74, -79, -46, 58, 72, -69, 72 },
	{50, -65, -43, 43, -66, 69, 59 },
	{42, 38, -18, 40, 43, 68, -50 },
	{22, -32, -16, 32, -38, -57, -48 },
	{-6, -6, 4, -7, 23, 56, 42 } };

	Array expected_arr_change_test4(line_test4, column_test4);

	for (int i = 0; i < line_test4; i++) {
		for (int j = 0; j < column_test4; j++) {
			expected_arr_change_test4[i][j] = expected_result_test4[i][j];
		}
	}

	expected_arr_change_test4.InitializelMaxValue();

	if (TestingProgram(move(entered_arr_test4), move(expected_arr_change_test4), value_test_passed) == true) {
		value_test_passed++;
	}

	const int column_test5 = 10;
	const int line_test5 = 10;
	int entered_data_test5[line_test5][column_test5] = { {-21, -19,   6, -36,  80,  28,  52,  41,  32,  45 },
	{ 60, -46,   8,  66, -59, -8,  70,  35,  18, -98 },
	{-74,  48, -60,  25,  78,  72,  52,  98, -96, -42 },
	{ 69, -19,  99,  79, -43,  22,  59,  35,  61,  32 },
	{  0, -36,  25,  96,  15, -98,  22,  94,  37, -53 },
	{-67, -4,  74, -85,  97, -32,  11,  21, -80, -40 },
	{ 41, -60, -94, -60,  80, -56,  67, -52,  64,  26 },
	{-40, -12, -63,  43, -37,  18,  53, -58,  19, -63 },
	{ 99,  51, -78, -94,  16,  54, -87, -72,  79, -14 },
	{ 43,  62,  11,  83,  18,  94,  74,   4, -58, -6 } };

	Array entered_arr_test5(line_test5, column_test5);

	for (int i = 0; i < line_test5; i++) {
		for (int j = 0; j < column_test5; j++) {
			entered_arr_test5[i][j] = entered_data_test5[i][j];
		}
	}

	entered_arr_test5.InitializelMaxValue();

	int expected_result_test5[line_test5][column_test5] = { {99, 62, 99, 96, 97, -98, -87, 98, -96, -98 },
	{-74, -60, -94, -94, 80, 94, 74, 94, -80, -63 },
	{69, 51, -78, -85, 80, 72, 70, -72, 79, -53 },
	{-67, 48, 74, 83, 78, -56, 67, -58, 64, 45 },
	{60, -46, -63, 79, -59, 54, 59, -52, 61, -42 },
	{43, -36, -60, 66, -43, -32, 53, 41, -58, -40 },
	{41, -19, 25, -60, -37, 28, 52, 35, 37, 32 },
	{-40, -19, 11, 43, 18, 22, 52, 35, 32, 26 },
	{-21, -12, 8, -36, 16, 18, 22, 21, 19, -14 },
	{0, -4, 6, 25, 15, -8, 11, 4, 18, -6} };

	Array expected_arr_change_test5(line_test5, column_test5);

	for (int i = 0; i < line_test5; i++) {
		for (int j = 0; j < column_test5; j++) {
			expected_arr_change_test5[i][j] = expected_result_test5[i][j];
		}
	}
	
	expected_arr_change_test5.InitializelMaxValue();

	if (TestingProgram(move(entered_arr_test5), move(expected_arr_change_test5), value_test_passed) == true) {
		value_test_passed++;
	}

	if (value_test_passed == ALL_TEST_PASSED) {
		cout << endl << "All test passed" << endl;
	}

}