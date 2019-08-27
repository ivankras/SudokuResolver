#include "box.h"
#include <iostream>
#include <string>

BoxGrid::BoxGrid(index line, index column, ValBox v)
	:_line(line), _column(column), _value(v), _possibleValue() {};

index BoxGrid::getLine() {
	return _line;
}

index BoxGrid::getColumn() {
	return _column;
}

ValBox BoxGrid::getValue() {
	return _value;
}

std::vector<ValBox> BoxGrid::getPossibleValues() {
	return _possibleValue;
}

void BoxGrid::showPossibleValues() {
	std::cout << "box(" << _line << ", " << _column << "), possible values : ";
	for (auto& i : _possibleValue) {
		switch (i) {
		case ValBox::ONE:
			std::cout << "1, ";
			break;
		case ValBox::TWO:
			std::cout << "2, ";
			break;
		case ValBox::THREE:
			std::cout << "3, ";
			break;
		case ValBox::FOUR:
			std::cout << "4, ";
			break;
		case ValBox::FIVE:
			std::cout << "5, ";
			break;
		case ValBox::SIX:
			std::cout << "6, ";
			break;
		case ValBox::SEVEN:
			std::cout << "7, ";
			break;
		case ValBox::EIGHT:
			std::cout << "8, ";
			break;
		case ValBox::NINE:
			std::cout << "9, ";
			break;
		case ValBox::UNKNOWN:
			std::cout << "x, ";
			break;
		}
	}
	std::cout << std::endl;
}

void BoxGrid::setValue(ValBox v) {
	_value = v;
}

void BoxGrid::clearPossibleValues() {
	_possibleValue.clear();
}

bool BoxGrid::hasAValue() {
	return _value != ValBox::UNKNOWN;
}

void BoxGrid::addPossibleValue(ValBox v) {
	_possibleValue.push_back(v);
}
