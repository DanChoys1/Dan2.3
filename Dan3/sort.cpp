#include <cmath>
#include <iostream>
#include "sort.h"
#include "array_class.h"

using namespace std;

int ISort::GetComparison(void) {
	return comparison;
}

int ISort::GetPermutation(void) {
	return permutation;
}

Array Bubble_Sort::Sort(Array arr) {
	for (int j = 0; j < arr.GetColumn(); j++) {

		for (int k = arr.GetLine() - 1; k > 0; k--) {
			int cycle_permutations = 0;

			for (int i = 0; i < k; i++) {

				if (abs(arr[i][j]) < abs(arr[i + 1][j])) {
					swap(arr[i][j], arr[i + 1][j]);
					permutation++;
					cycle_permutations++;
				}

				comparison++;
			}

			if (cycle_permutations == 0) {
				break;
			}

		}

	}

	return arr;
}

Array Selection_Sort::Sort(Array arr) {
	int max_value_index = 0;

	for (int j = 0; j < arr.GetColumn(); j++) {

		for (int k = 0; k < (arr.GetLine() - 1); k++) {
			max_value_index = k;

			for (int i = k + 1; i < arr.GetLine(); i++) {

				if (abs(arr[i][j]) > abs(arr[max_value_index][j])) {
					max_value_index = i;
				}

				comparison++;
			}

			if (max_value_index != k) {
				swap(arr[max_value_index][j], arr[k][j]);
				permutation++;
			}

		}

	}

	return arr;
}

Array Insertion_Sort::Sort(Array arr) {

	for (int j = 0; j < arr.GetColumn(); j++) {
		for (int i = 1; i < arr.GetLine(); i++) {
			int line_value = i;

			while ( ((line_value - 1) >= 0) && (abs(arr[line_value][j]) > abs(arr[line_value - 1][j])) ) {
				swap(arr[line_value][j], arr[line_value - 1][j]);
				permutation++;
				comparison++;
				line_value--;
			}
			
			if ((line_value - 1) != -1) {
				comparison++;
			}

		}

	}

	return arr;
}

Array Shell_Sort::Sort(Array arr) {

	for (int j = 0; j < arr.GetColumn(); j++) {
		int d = arr.GetLine() / 2;

		while (d != 0) {

			for (int k = d; k < arr.GetLine(); k++) {

				for (int i = k; (i - d) >= 0; i -= d) {

					if (abs(arr[i][j]) > abs(arr[i - d][j])) {
						swap(arr[i][j], arr[i - d][j]);
						permutation++;
					}
					else {
						comparison++;
						break;
					}

					comparison++;
				}

			}

			d /= 2; 

		}

	}

	return arr;
}

Array Quick_Sort::Recursion_Sort(Array arr, int low, int high, int j) {
	int center = (high + low) / 2;
	int safe_value = 0;

	for (int i = low; i < center; i++) {

		if (abs(arr[i][j]) < abs(arr[center][j])) {
			safe_value = arr[i][j];

			for (int k = i; k < center; k++) {
				arr[k][j] = arr[k + 1][j];

			}

			arr[center][j] = safe_value;
			center--;
			i--;
			permutation++;
		}

		comparison++;

	}

	for (int i = high; i > center; i--) {

		if (abs(arr[i][j]) > abs(arr[center][j])) {
			safe_value = arr[i][j];

			for (int k = i; k > center; k--) {
				arr[k][j] = arr[k - 1][j];
			}

			arr[center][j] = safe_value;
			center++;
			i++;
			permutation++;
		}

		comparison++;
	}

	if ((center - low) > 1) {
		arr = Recursion_Sort(move(arr), low, center, j);
	}

	if ((high - center) > 1) {
		arr = Recursion_Sort(move(arr), center + 1, high, j);
	}

	return arr;
}

Array Quick_Sort::Sort(Array arr) {

	for (int j = 0; j < arr.GetColumn(); j++) {
		arr = Recursion_Sort(move(arr), 0, arr.GetLine() - 1, j);
	}

	return arr;
}