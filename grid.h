#pragma once

#include "box.h"
#include <vector>

// Class Grid
//	A Grid represents a Sudoku game holder
class Grid {
public:
	// Grid: default constructor
	//	Initialises the Sudoku grid (9x9) with default (UNKNOWN) values
	Grid();

	// getSquare
	//	\param c: box part of the square to be returned
	//	\return : from the eight remaining values of the square of which 'c' is part, those that are not unknown
	std::vector<ValBox> getSquare(BoxGrid& c);

	// getLine
	//  \param c: box part of the line to be returned
	//	\return : from the eight remaining values of the line of which 'c' is part, those that are not unknown
	std::vector<ValBox> getLine(BoxGrid& c);

	// getColumn
	//  \param c: box part of the column to be returned
	//	\return : from the eight remaining values of the column of which 'c' is part, those that are not unknown
	std::vector<ValBox> getColumn(BoxGrid& c);

	// getPossibleValuesForSquare
	//	\param c: box part of the square to be analysed
	//	\return : all possible values for the square of which 'c' is part
	std::vector<ValBox> getPossibleValuesForSquare(BoxGrid& c);

	// getPossibleValuesForLine
	//	\param c: box part of the line to be analysed
	//	\return : all possible values for the line of which 'c' is part
	std::vector<ValBox> getPossibleValuesForLine(BoxGrid& c);

	// getPossibleValuesForColumn
	//	\param c: box part of the column to be analysed
	//	\return : all possible values for the column of which 'c' is part
	std::vector<ValBox> getPossibleValuesForColumn(BoxGrid& c);

	// isCorrect: checks every line, column and square for repeated values
	//	\return : true if there are not repeated values in any line, column nor square
	bool isCorrect();

	// setPossibleValues: computes all possible values for a box 'c'
	//	\param c: box to be analysed
	//	If this box already has a set of possible values, those are the only ones to be tested
	//	Otherwise, every value has to be tested
	void setPossibleValues(BoxGrid& c);

	// getCharOfValBox: given a value (ValBox), returns the equivalent character
	//	\param v: value (ValBox) to be converted
	//	\return : converted character
	// e.g.: ValBox::ONE => '1' || ValBox::UNKNOWN => 'x'
	char getCharOfValBox(ValBox v);

	// getValBoxOfChar: given a character, returns the equivalent value (ValBox)
	//	\param c: character to be converted
	//	\return : converted value (ValBox)
	// e.g.: '2' => ValBox::TWO || 'x' => ValBox::UNKNOWN
	ValBox getValBoxOfChar(char c);

	// setValBox: sets a value (ValBox) for the box in a given line and column
	//	\param line: number of line of the box to be assigned
	//	\param column: number of column of the box to be assigned
	//	\param v: value to assign
	void setValBox(index line, index column, ValBox v);

	// resolveCompletely: iterates until the grid is solved or not a value is set
	void resolveCompletely();

	// showGrid: human-readably prints the grid
	void showGrid();

private:
	std::vector<std::vector<BoxGrid>> _grid;
	

	// iterate: represents one attempt of solving the grid
	//	\return : true if at least one ValBox has been set on the iteration
	bool iterate();

	// resolve: from the possible values of each box, tries to determine each one permanently
	//	\return : true if at least one ValBox has been set while resolving
	bool resolve();

};
