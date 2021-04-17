#pragma once

#include "array_class.h"

class ISort {
protected:
	int comparison = 0;
	int permutation = 0;
public:

	virtual Array Sort(Array arr) = 0;

	int GetComparison(void);

	int GetPermutation(void);

	virtual ~ISort() = default;

};

class Bubble_Sort final : public ISort {
public:

	Array Sort(Array arr);

};

class Selection_Sort final : public ISort {
public:

	Array Sort(Array arr) ;

};

class Insertion_Sort final : public ISort {
public:

	Array Sort(Array arr);

};

class Shell_Sort final : public ISort {
public:

	Array Sort(Array arr);

};

class Quick_Sort final : public ISort {

	Array Recursion_Sort(Array arr, int low, int high, int j);

public:

	Array Sort(Array arr);

};