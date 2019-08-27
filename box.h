#pragma once

#include <vector>

using index = unsigned short int;

// Class ValBox
//	A ValBox represents a value possibly held in a BoxGrid
enum class ValBox {
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

// Class BoxGrid
//	A BoxGrid represents a Box of the Grid (the Sudoku)
class BoxGrid {
public:
	// BoxGrid: constructor with parameters (no default)
	//	\param line: number of line on the Grid for the Box
	//	\param column: number of column on the Grid for the Box
	//	\param v: value to store in the Box
	BoxGrid(index line, index column, ValBox v);

	// getLine
	//	\return : number of line on the Grid of the Box
	index getLine();

	// getColumn
	//	\return : number of column on the Grid of the Box
	index getColumn();

	// getValue
	//	\return : value (ValBox) stored in the Box
	ValBox getValue();

	// getPossibleValues
	//	\return : all possible values (ValBox) for the Box
	std::vector<ValBox> getPossibleValues();

	// showPossibleValues
	//	Prints the existing set of possible values for the Box
	void showPossibleValues();

	// setValue
	//	\param v: value (ValBox) to be set
	void setValue(ValBox v);

	// clearPossibleValues
	//	Empties the existing set of possible values for the Box
	void clearPossibleValues();

	// hasAValue
	//	\return : true if the held value (ValBox) in the box is known (not ValBox::UNKNOWN)
	bool hasAValue();

	// addPossibleValue: add a certain value to the set of possible values for the Box
	//	\param v: value (valBox) to add to the set of possible values for the Box
	void addPossibleValue(ValBox v);

private:
	index _line;
	index _column;
	ValBox _value;
	std::vector<ValBox> _possibleValue;
};