#pragma once

#include "box.h"
#include <vector>

class Grid {
public:
	Grid();

	// Getters
	std::vector<valBox> getSquare(boxGrid& c);
	std::vector<valBox> getLine(boxGrid& c);
	std::vector<valBox> getColumn(boxGrid& c);

	std::vector<valBox> getPossibleValuesForSquare(boxGrid& c);
	std::vector<valBox> getPossibleValuesForColumn(boxGrid& c);
	std::vector<valBox> getPossibleValuesForLine(boxGrid& c);

	// ## methodes
	bool isCorrect();

	void setPossibleValues(boxGrid& c);
	char getCharOfValBox(valBox v);
	valBox getValBoxOfChar(char c);
	void setValBox(index line, index column, valBox v);

	bool iterate();
	bool resolve();
	void resolveCompletely();

	void showGrid();

private:
	std::vector<std::vector<boxGrid>> _grid;

};
