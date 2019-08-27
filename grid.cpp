#include "grid.h"
#include "box.h"
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

Grid::Grid() : _grid() {
	
	for (index line(0); line <= 8; line++) {
		std::vector<BoxGrid> v;
		for (index col(0); col <= 8; col++) {
			BoxGrid c(line, col, ValBox::UNKNOWN);
			v.push_back(c);
		}
		_grid.push_back(v);
	}

}

std::vector<ValBox> Grid::getSquare(BoxGrid& c) {

	std::vector<ValBox > v;
	index line = c.getLine();
	index column = c.getColumn();

	//
	//	Coordinates of the square are the quotients line/3 and column/3
	//	The upper-left box of the square has coordinate 0, 3 or 6
	//	if quotient < 1 square.upperLeftBoxLine/Column = 0
	//				> 1								   = 6
	//				else							   = 3
	//
	index upperLeftBoxLine = (line / 3) * 3;
	index upperLeftBoxColumn = (column / 3) * 3;

	for (index i = upperLeftBoxLine; i < upperLeftBoxLine + 3; i++) {
		for (index j = upperLeftBoxColumn; j < upperLeftBoxColumn + 3; j++) {
			if (_grid.at(i).at(j).hasAValue()) {
				v.push_back(_grid.at(i).at(j).getValue());
			}
		}
	}

	return v;
}

std::vector<ValBox> Grid::getLine(BoxGrid& c) {
	std::vector<ValBox> v;
	index line = c.getLine();

	for (index i(0); i <= 8; ++i) {
		if (_grid.at(line).at(i).hasAValue()) {
			v.push_back(_grid.at(line).at(i).getValue());
		}
	}
	return v;
}

std::vector<ValBox> Grid::getColumn(BoxGrid& c) {
	std::vector<ValBox> v;
	index column = c.getColumn();

	for (index i(0); i <= 8; ++i) {
		if (_grid.at(i).at(column).hasAValue()) {
			v.push_back(_grid.at(i).at(column).getValue());
		}
	}
	return v;
}

std::vector<ValBox> Grid::getPossibleValuesForSquare(BoxGrid& c) {
	std::vector<ValBox> v;
	index line = c.getLine();
	index column = c.getColumn();

	index upperLeftBoxLine = (line / 3) * 3;
	index upperLeftBoxColumn = (column / 3) * 3;

	for (index i = upperLeftBoxLine; i < upperLeftBoxLine + 3; i++) {
		for (index j = upperLeftBoxColumn; j < upperLeftBoxColumn + 3; j++) {
			if (!_grid.at(i).at(j).hasAValue() && (i != c.getLine() || j != c.getColumn())) {
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

std::vector<ValBox> Grid::getPossibleValuesForLine(BoxGrid& c) {
	std::vector<ValBox> v;
	index line = c.getLine();

	for (index i(0); i <= 8; ++i) {
		if (!_grid.at(line).at(i).hasAValue() && i != c.getColumn()) {
			for (auto& k : _grid.at(line).at(i).getPossibleValues()) {
				// If these values are not already present they are included
				if (std::find(v.begin(), v.end(), k) == v.end()) {
					v.push_back(k);
				}
			}
		}
	}

	return v;
}

std::vector<ValBox> Grid::getPossibleValuesForColumn(BoxGrid& c) {
	std::vector<ValBox> v;
	index column = c.getColumn();

	for (index i(0); i <= 8; ++i) {
		if (!_grid.at(i).at(column).hasAValue() && i != c.getLine()) {
			for (auto& k : _grid.at(i).at(column).getPossibleValues()) {
				// If these values are not already present they are included
				if (std::find(v.begin(), v.end(), k) == v.end()) {
					v.push_back(k);
				}
			}
		}
	}

	return v;
}

bool Grid::isCorrect() {
	
	std::vector<std::set<ValBox>> columnValuesSet(9);
	std::vector<std::set<ValBox>> squareValuesSet(9);
	for (short i(0); i < 9; i++) {
		columnValuesSet.at(i).clear();
		squareValuesSet.at(i).clear();
	}

	for (short lineNb(0); lineNb < 9; lineNb++) {
		std::vector<BoxGrid> line = _grid.at(lineNb);
		std::set<ValBox> lineValuesSet{};
		lineValuesSet.clear();
		for (short colNb(0); colNb < 9; colNb++) {
			ValBox v = _grid.at(lineNb).at(colNb).getValue();
			if (v != ValBox::UNKNOWN) {
				// Line check
				if (lineValuesSet.count(v) != 0) {
					return false;
				}

				// Column check
				if (columnValuesSet.at(colNb).count(v) != 0) {
					return false;
				}

				// Square check
				short squareNb{(lineNb/3)*3 + colNb/3};
				if (squareValuesSet.at(squareNb).count(v) != 0) {
					return false;
				}

				// Value not repeated
				lineValuesSet.insert(v);
				columnValuesSet.at(colNb).insert(v);
				squareValuesSet.at(squareNb).insert(v);
			}
		}
	}
	return true;
}

void Grid::setPossibleValues(BoxGrid& c) {
	std::vector<ValBox> vectSquare = getSquare(c);
	std::vector<ValBox> vectLine = getLine(c);
	std::vector<ValBox> vectColumn = getColumn(c);
	
	if (c.getPossibleValues().empty()) {
		for (int i(0); i < 9; i++) {
			ValBox valBox_i = getValBoxOfChar(std::to_string(i + 1).at(0));
			if (std::find(vectSquare.begin(), vectSquare.end(), valBox_i) == vectSquare.end() &&
				std::find(vectLine.begin(), vectLine.end(), valBox_i) == vectLine.end() &&
				std::find(vectColumn.begin(), vectColumn.end(), valBox_i) == vectColumn.end()) {
				c.addPossibleValue(valBox_i);
			}
		}
	} else {
		std::vector<ValBox> vectPossibleValues = c.getPossibleValues();
		c.clearPossibleValues();
		for (auto i : vectPossibleValues) {
			if (std::find(vectSquare.begin(), vectSquare.end(), i) == vectSquare.end() &&
				std::find(vectLine.begin(), vectLine.end(), i) == vectLine.end() &&
				std::find(vectColumn.begin(), vectColumn.end(), i) == vectColumn.end()) {
				c.addPossibleValue(i);
			}
		}
	}
}

char Grid::getCharOfValBox(ValBox v) {
	switch (v) {
	case ValBox::ONE:
		return '1';
	case ValBox::TWO:
		return '2';
	case ValBox::THREE:
		return '3';
	case ValBox::FOUR:
		return '4';
	case ValBox::FIVE:
		return '5';
	case ValBox::SIX:
		return '6';
	case ValBox::SEVEN:
		return '7';
	case ValBox::EIGHT:
		return '8';
	case ValBox::NINE:
		return '9';
	case ValBox::UNKNOWN:
		return 'x';
	default:
		std::cout << "Grid::fillGrid switch wrong value entered!";
		return '0';
	}
}

ValBox Grid::getValBoxOfChar(char c) {
	switch (c) {
	case '1':
		return ValBox::ONE;
	case '2':
		return ValBox::TWO;
	case '3':
		return ValBox::THREE;
	case '4':
		return ValBox::FOUR;
	case '5':
		return ValBox::FIVE;
	case '6':
		return ValBox::SIX;
	case '7':
		return ValBox::SEVEN;
	case '8':
		return ValBox::EIGHT;
	case '9':
		return ValBox::NINE;
	case 'x':
		return ValBox::UNKNOWN;
	default:
		std::cout << "Grid::fillGrid switch wrong value entered : " << c << std::endl;
		return ValBox::UNKNOWN;
	}
}

void Grid::setValBox(index line, index column, ValBox v) {
	_grid.at(line).at(column).setValue(v);
}

void Grid::resolveCompletely() {
	int nbIteration = 0;
	bool modification = true;

	while (nbIteration < 200 && modification) {
		std::cout << "Iteration number " << nbIteration + 1 << ") : " << std::endl;
		modification = iterate();
		nbIteration++;
	}
}

void Grid::showGrid() {
	std::string separator = " ";
	for (index i(0); i <= 8; ++i) {
		for (index j(0); j <= 8; ++j) {
			if (j == 2 || j == 5) {
				separator = " | ";
			}
			else {
				separator = " ";
			}
			ValBox v = _grid.at(i).at(j).getValue();
			if (v == ValBox::UNKNOWN)
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
			// If it is the only possible value, it is modified
			if (!j.hasAValue() && j.getPossibleValues().size() == 1) {
				std::cout << "Method 1 : box modification (" << j.getLine() << ", " << j.getColumn() << "), with " << getCharOfValBox(j.getPossibleValues()[0]) << std::endl;
				j.setValue(j.getPossibleValues()[0]);
				j.clearPossibleValues();
				res = true;
			} else {
				// Otherwise, check if the value is only possible for that place in the line, column or square
				std::vector<ValBox> cgSquare = getPossibleValuesForSquare(j);
				std::vector<ValBox> cgColumn = getPossibleValuesForColumn(j);
				std::vector<ValBox> cgLine = getPossibleValuesForLine(j);

				setPossibleValues(j);

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