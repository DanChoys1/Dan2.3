#pragma once

class Array final {
	int column = 0;
	int line = 0;
	int **arr = nullptr;
	int max_value = 0;

public:
	explicit Array(int ArrLine, int ArrColumn);

	Array(const Array& old_arr);

	Array(Array&& old_array);

	~Array();

	class ColumnElements {

		int* array_line = nullptr;

	public:
		ColumnElements(int* array);

		int & operator[](int index);

	};

	ColumnElements operator [] (int index);

	int GetColumn(void);

	int GetLine(void);

	void InitializelMaxValue(void);

	int GetMaxLengthValue(void);

	void Print(void);

	Array & operator = (Array&& old_array);

	Array & operator = (Array& old_array) = delete;

};
