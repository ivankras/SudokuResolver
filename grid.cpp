#include "grid.h"
#include "case.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


// Grid class

Grid::Grid() : _grid() {

	// Initialize with empty (UNKNOWN boxes) grid
	for (index line(0); line <= 8; line++) {
		std::vector<boxGrid> v;
		for (index col(0); col <= 8; col++) {
			boxGrid c(line, col, valBox::UNKNOWN);
			v.push_back(c);
		}
		_grid.push_back(v);
	}
}


// Getters
std::vector<valBox> Grid::getSquare(boxGrid& c) {

	std::vector<valBox > v;
	index line = c.getLine();
	index column = c.getColumn();

	//
	//	this method returns a set of boxes of the parameter square except itself
	//	coords of the square are the quotient of line/3 and column/3
	//	the upper-left box of the square has coord 0, 3 or 6
	//	line : if quotient < 1 square.upperLeftPoint.line = 0
	//					   > 1                            = 6
	//					   else                           = 3
	//	column : if quotient < 1 carre.pointHaucheGauche.column = 0
	//						 > 1                                = 6
	//						 else                               = 3
	//

	int quotientLine = line/3;
	int quotientColumn = column/3;
	index upperLeftBoxLine = 0;
	index upperLeftBoxColumn = 0;


	if (quotientLine < 1) {
		upperLeftBoxLine = 0;
	}
	else {
		if (quotientLine > 1) {
			upperLeftBoxLine = 6;
		}
		else {
			upperLeftBoxLine = 3;
		}
	}

	if (quotientColumn < 1) {
		upperLeftBoxColumn = 0;
	}
	else {
		if (quotientColumn > 1) {
			upperLeftBoxColumn = 6;
		}
		else {
			upperLeftBoxColumn = 3;
		}
	}


	for (index i = upperLeftBoxLine; i < upperLeftBoxLine + 3; i++) {
		for (index j = upperLeftBoxColumn; j < upperLeftBoxColumn + 3; j++) {
			if (_grid.at(i).at(j).hasAValue()) {
				v.push_back(_grid.at(i).at(j).getValue());
				//DEBUG std::cout << getCharOfValBox(_grid.at(i).at(j).getValue()) << ", ";
			}
		}
	}
	//DEBUG std::cout << std::endl;

	return v;
}

std::vector<valBox> Grid::getLine(boxGrid& c) {
	std::vector<valBox> v;
	index line = c.getLine();

	//DEBUG std::cout << "TEST : getLine : ";

	for (index i(0); i <= 8; ++i) {
		if (_grid.at(line).at(i).hasAValue()) {
			v.push_back(_grid.at(line).at(i).getValue());
			//DEBUG std::cout << getCharOfValBox(_grid.at(line).at(i).getValue()) << ", ";
		}
	}
	//DEBUG std::cout << std::endl;
	return v;
}

std::vector<valBox> Grid::getColumn(boxGrid& c) {
	std::vector<valBox> v;
	index column = c.getColumn();

	//DEBUG std::cout << "TEST : getColumn : ";

	for (index i(0); i <= 8; ++i) {
		if (_grid.at(i).at(column).hasAValue()) {
			v.push_back(_grid.at(i).at(column).getValue());
			//DEBUG std::cout << getCharOfValBox(_grid.at(i).at(column).getValue()) << ", ";
		}
	}
	//DEBUG std::cout << std::endl;
	return v;
}

std::vector<valBox> Grid::getPossibleValuesForSquare(boxGrid& c) {
	std::vector<valBox> v;
	index line = c.getLine();
	index column = c.getColumn();

	// See getSquare for explanation
	int quotientLine = line/3;
	int quotientColumn = column/3;
	index upperLeftBoxLine = 0;
	index upperLeftBoxColumn = 0;


	if (quotientLine < 1) {
		upperLeftBoxLine = 0;
	}
	else {
		if (quotientLine > 1) {
			upperLeftBoxLine = 6;
		}
		else {
			upperLeftBoxLine = 3;
		}
	}

	if (quotientColumn < 1) {
		upperLeftBoxColumn = 0;
	}
	else {
		if (quotientColumn > 1) {
			upperLeftBoxColumn = 6;
		}
		else {
			upperLeftBoxColumn = 3;
		}
	}

	//DEBUG std::cout << "carre : " << std::endl;
	for (index i = upperLeftBoxLine; i < upperLeftBoxLine + 3; i++) {
		for (index j = upperLeftBoxColumn; j < upperLeftBoxColumn + 3; j++) {
			if (!_grid.at(i).at(j).hasAValue() && (i != c.getLine() || j != c.getColumn())) {
				//DEBUG _grid.at(i).at(j).afficherValeursPossibles();
				for (auto& k : _grid.at(i).at(j).getPossibleValues()) {
					// If these values are not already present they are included
					if (std::find(v.begin(), v.end(), k) == v.end()) {
						v.push_back(k);
					}
				}
			}
		}
	}

	return v;
}
std::vector<valBox> Grid::getPossibleValuesForColumn(boxGrid& c) {
	std::vector<valBox> v;
	index column = c.getColumn();

	//TODO: Check! This is exactly like other code (f.i., getSquare())
	//DEBUG std::cout << "column : " << std::endl;
	for (index i(0); i <= 8; ++i) {
		if (!_grid.at(i).at(column).hasAValue() && i != c.getLine()) {
			//DEBUG _grid.at(i).at(column).showPossibleValues();
			for (auto& k : _grid.at(i).at(column).getPossibleValues()) {
				if (std::find(v.begin(), v.end(), k) == v.end()) {
					v.push_back(k);
				}
			}
		}
	}

	return v;
}

std::vector<valBox> Grid::getPossibleValuesForLine(boxGrid& c) {
	std::vector<valBox> v;
	index line = c.getLine();

	//TODO: Check! This is exactly like other code (f.i., getSquare())
	//DEBUG std::cout << "line : " << std::endl;
	for (index i(0); i <= 8; ++i) {
		if (!_grid.at(line).at(i).hasAValue() && i != c.getColumn()) {
			//DEBUG _grid.at(line).at(i).showPossibleValues();
			for (auto& k : _grid.at(line).at(i).getPossibleValues()) {
				if (std::find(v.begin(), v.end(), k) == v.end()) {
					v.push_back(k);
				}
			}
		}
	}

	return v;
}


// Methods

// Every possible number for the box has to be passed
// If this box already has a set of possible values, those are the only ones to be tested.
// Otherwise, every value has to be tested.
void Grid::setPossibleValues(boxGrid& c) {
	//DEBUG std::cout << "Set possible values for the box (" << c.getLine() << ", " << c.getColumn() << ")" << std::endl;

	std::vector<valBox> vectSquare = getSquare(c);
	std::vector<valBox> vectLine = getLine(c);
	std::vector<valBox> vectColumn = getColumn(c);
	if (c.getPossibleValues().empty()) {
		for (int i(0); i < 9; i++) {
			valBox valBox_i = getValBoxOfChar(std::to_string(i + 1).at(0));
			if (std::find(vectSquare.begin(), vectSquare.end(), valBox_i) == vectSquare.end() &&
				std::find(vectLine.begin(), vectLine.end(), valBox_i) == vectLine.end() &&
				std::find(vectColumn.begin(), vectColumn.end(), valBox_i) == vectColumn.end()) {
				c.addPossibleValue(valBox_i);
				//DEBUG std::cout << "possible value: " << getCharOfValBox(valBox_i) << std::endl;
			}
		}
	}
	else {
		std::vector<valBox > vectPossibleValues = c.getPossibleValues();
		c.clearPossibleValues();
		for (auto i : vectPossibleValues) {
			if (std::find(vectSquare.begin(), vectSquare.end(), i) == vectSquare.end() &&
				std::find(vectLine.begin(), vectLine.end(), i) == vectLine.end() &&
				std::find(vectColumn.begin(), vectColumn.end(), i) == vectColumn.end()) {
				c.addPossibleValue(i);
				//DEBUG std::cout << "possible value: " << getCharOfValBox(i) << std::endl;
			}
		}
	}
}

void Grid::setValBox(index line, index column, valBox v) {
	_grid.at(line).at(column).setValue(v);
}

bool Grid::iterate() {
	for (auto& i : _grid) {
		for (auto& j : i) {
			if (!j.hasAValue())
				setPossibleValues(j);
		}
	}
	return resolve();
}

bool Grid::resolve() {
	bool res = false;

	for (auto& i : _grid) {
		for (auto& j : i) {
			// If it is the only possible value it is modified
			if (!j.hasAValue() && j.getPossibleValues().size() == 1) {
				std::cout << "Method 1 : box modification (" << j.getLine() << ", " << j.getColumn() << "), with " << getCharOfValBox(j.getPossibleValues()[0]) << std::endl;
				j.setValue(j.getPossibleValues()[0]);
				j.clearPossibleValues();
				res = true;
			}
			else {
				// Otherwise, check if the value is only possible for that place in the line, column or square
				std::vector<valBox> cgSquare = getPossibleValuesForSquare(j);
				std::vector<valBox> cgColumn = getPossibleValuesForColumn(j);
				std::vector<valBox> cgLine = getPossibleValuesForLine(j);

				setPossibleValues(j);
				/*	DEBUG
								std::cout << "cgSquare : " << std::endl;
								for(auto m : cgSquare)
									std::cout << getCharOfValBox(m) << ", ";
								std::cout << std::endl;

								std::cout << "cgColumn : " << std::endl;
								for(auto m : cgColumn)
									std::cout << getCharOfValBox(m) << ", ";
								std::cout << std::endl;

								std::cout << "cgLine : " << std::endl;
								for(auto m : cgLine)
									std::cout << getCharOfValBox(m) << ", ";
								std::cout << std::endl;
				*/

				//	DEBUG exit(2);

				for (auto& k : j.getPossibleValues()) {
					if (std::find(cgSquare.begin(), cgSquare.end(), k) == cgSquare.end() || // only possible place of the square
						std::find(cgColumn.begin(), cgColumn.end(), k) == cgColumn.end() || // or only possible place of the column
						std::find(cgLine.begin(), cgLine.end(), k) == cgLine.end()) { // or only possible place of the line
						std::cout << "Method 2 : box modification (" << j.getLine() << ", " << j.getColumn() << "), with " << getCharOfValBox(k) << std::endl;
						j.setValue(k);
						j.clearPossibleValues();
						res = true;
					}
				}
			}
		}
	}
	return res;
}

void Grid::resolveCompletely() {
	int nbIteration = 0;
	bool modification = true;

	while (nbIteration < 20 && modification) {
		std::cout << "Iteration number " << nbIteration + 1 << ") : " << std::endl;
		modification = iterate();
		//DEBUG showGrid();
		nbIteration++;
	}
}

void Grid::showGrid() {
	std::string separator = " ";
	for (index i(0); i <= 8; ++i) {
		for (index j(0); j <= 8; ++j) {
			if (j == 2 || j == 5) {
				separator = "   ";
			}
			else {
				separator = " ";
			}
			valBox v = _grid.at(i).at(j).getValue();
			if (v == valBox::UNKNOWN)
				std::cout << " " << separator;
			else
				std::cout << getCharOfValBox(v) << separator;
		}
		if (i == 2 || i == 5) {
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

char Grid::getCharOfValBox(valBox v) {
	switch (v) {
	case valBox::ONE:
		return '1';
	case valBox::TWO:
		return '2';
	case valBox::THREE:
		return '3';
	case valBox::FOUR:
		return '4';
	case valBox::FIVE:
		return '5';
	case valBox::SIX:
		return '6';
	case valBox::SEVEN:
		return '7';
	case valBox::EIGHT:
		return '8';
	case valBox::NINE:
		return '9';
	case valBox::UNKNOWN:
		return 'x';

	default:
		std::cout << "Grid::fillGrid [ switch wrong value entered ] !";
		return '0';
	}
}

valBox Grid::getValBoxOfChar(char c) {
	switch (c) {
	case '1':
		return valBox::ONE;
	case '2':
		return valBox::TWO;
	case '3':
		return valBox::THREE;
	case '4':
		return valBox::FOUR;
	case '5':
		return valBox::FIVE;
	case '6':
		return valBox::SIX;
	case '7':
		return valBox::SEVEN;
	case '8':
		return valBox::EIGHT;
	case '9':
		return valBox::NINE;
	case 'x':
		return valBox::UNKNOWN;

	default:
		std::cout << "Grid::fillGrid switch wrong value entered : " << c << std::endl;
		return valBox::UNKNOWN;
	}
}