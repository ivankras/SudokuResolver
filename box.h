#pragma once

#include <vector>

using index = unsigned short int;

enum class valBox {
	UNKNOWN,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE
};

class boxGrid {
public:
	boxGrid(index line, index column, valBox v);

	// Getters
	index getLine();
	index getColumn();
	valBox getValue();
	std::vector<valBox> getPossibleValues();

	// Setters
	void setValue(valBox v);
	void clearPossibleValues();

	// Methods
	void showPossibleValues();
	bool hasAValue();
	void addPossibleValue(valBox v);

private:
	index _line;
	index _column;
	valBox _value;
	std::vector<valBox> _possibleValue;
};