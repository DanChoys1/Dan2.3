#include <iostream>
#include <iomanip>
#include "input.h"
#include "save_data.h"
#include "sort.h"

using namespace std;

Input *InputType(bool *user_selected_file_input);

void ArrayInterface(void) {
	bool user_selected_file_input = false;

	Input* inp = InputType(&user_selected_file_input);

	Array arr = inp->Read();

	delete inp;

	cout << "Input array:" << endl;
	arr.Print();

	Bubble_Sort bubble_sort;
	Array array_bubble_sort = bubble_sort.Sort(arr);

	Selection_Sort selection_sort;
	Array arr_selection_sort = selection_sort.Sort(arr);

	Insertion_Sort insertion_sort;
	Array arr_insertion_sort = insertion_sort.Sort(arr);

	Shell_Sort shell_sort;
	Array arr_shell_sort = shell_sort.Sort(arr);

	Quick_Sort quick_sort;
	Array arr_quick_sort = quick_sort.Sort(arr);

	cout << "Sorting array:" << endl;
	arr_quick_sort.Print();

	cout << endl << "                comparison   permutation" << endl;
			cout << "Bubble Sort:" << setw(14) << bubble_sort.GetComparison() << setw(14) << bubble_sort.GetPermutation() << endl;
			cout << "Selection Sort:" << setw(11) << selection_sort.GetComparison() << setw(14) << selection_sort.GetPermutation() << endl;
			cout << "Insertion Sort:" << setw(11) << insertion_sort.GetComparison() << setw(14) << insertion_sort.GetPermutation() << endl;
			cout << "Shell Sort:" << setw(15) << shell_sort.GetComparison() << setw(14) << shell_sort.GetPermutation() << endl;
			cout << "Quick Sort:" << setw(15) << quick_sort.GetComparison() << setw(14) << quick_sort.GetPermutation() << endl;
	
	if (user_selected_file_input != true) {
		SaveInputArray(move(arr));
	}

	SaveChangeArray(move(arr_shell_sort));
}
