#include "box.h"
#include <iostream>
#include <string>

// Box Class

// Constructor
boxGrid::boxGrid(index line, index column, valBox v)
	:_line(line), _column(column), _value(v), _possibleValue() {};

// Getters
index boxGrid::getLine() {
	return _line;
}

index boxGrid::getColumn() {
	return _column;
}

valBox boxGrid::getValue() {
	return _value;
}

std::vector<valBox> boxGrid::getPossibleValues() {
	return _possibleValue;
}

void boxGrid::showPossibleValues() {
	std::cout << "box(" << _line << ", " << _column << "), possible values : ";
	for (auto& i : _possibleValue) {
		switch (i) {
		case valBox::ONE:
			std::cout << "1, ";
			break;
		case valBox::TWO:
			std::cout << "2, ";
			break;
		case valBox::THREE:
			std::cout << "3, ";
			break;
		case valBox::FOUR:
			std::cout << "4, ";
			break;
		case valBox::FIVE:
			std::cout << "5, ";
			break;
		case valBox::SIX:
			std::cout << "6, ";
			break;
		case valBox::SEVEN:
			std::cout << "7, ";
			break;
		case valBox::EIGHT:
			std::cout << "8, ";
			break;
		case valBox::NINE:
			std::cout << "9, ";
			break;
		case valBox::UNKNOWN:
			std::cout << "x, ";
			break;
		}
	}
	std::cout << std::endl;
}


// Setters
void boxGrid::setValue(valBox v) {
	_value = v;
}

void boxGrid::clearPossibleValues() {
	_possibleValue.clear();
}

// Methods
bool boxGrid::hasAValue() {
	return _value != valBox::UNKNOWN;
}

void boxGrid::addPossibleValue(valBox v) {
	_possibleValue.push_back(v);
}
