#include <iostream>
#include <string>
#include <chrono>
#include "grid.h"

bool lineIsCorrect(std::string& str) {
	std::string	processedStr{};

	for (char c : str) {
		if (c == ' ') {
			continue;
		} else {
			processedStr.push_back(c);
		}
	}
	//DEBUG std::cout << "Processed String: " << processedStr << std::endl;

	if (processedStr.length() != 9) {
		std::cout << "Length not 9 error" << std::endl;
		return false;
	}

	for (char c : processedStr) {
		if (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9' && c != 'x') {
			std::cout << "Wrong char error" << std::endl;
			return false;
		}
	}

	str = processedStr;
	return true;
}

void fillGrid(Grid& g) {
	std::cout << "Enter the value of the boxes, or 'x' where it is unknown: " << std::endl;
	index nbEnteredLines = 0;
	std::string input;

	while (nbEnteredLines < 9) {
		std::cout << "Line " << nbEnteredLines + 1 << ": " << std::endl;
		std::getline(std::cin, input);
		if (lineIsCorrect(input)) {
			//DEBUG	std::cout << "Line " << nbEnteredLines + 1 << ": " << input << " (length " << input.length() << ")" << std::endl;
			for (index i(0); i < 9; ++i) {
				g.setValBox(nbEnteredLines, i, g.getValBoxOfChar(input.at(i)));
			}

			nbEnteredLines++;
		}
		else {
			std::cout << "ERROR! Please type the line again." << std::endl;
		}
	}
}

void testGrid(Grid& g) {
	// First three lines
	g.setValBox(0, 3, g.getValBoxOfChar('6'));
	g.setValBox(0, 6, g.getValBoxOfChar('1'));
	g.setValBox(0, 8, g.getValBoxOfChar('7'));

	g.setValBox(1, 0, g.getValBoxOfChar('6'));
	g.setValBox(1, 1, g.getValBoxOfChar('8'));
	g.setValBox(1, 3, g.getValBoxOfChar('9'));
	g.setValBox(1, 4, g.getValBoxOfChar('5'));
	g.setValBox(1, 5, g.getValBoxOfChar('1'));
	g.setValBox(1, 6, g.getValBoxOfChar('3'));

	g.setValBox(2, 2, g.getValBoxOfChar('3'));
	g.setValBox(2, 5, g.getValBoxOfChar('2'));
	g.setValBox(2, 6, g.getValBoxOfChar('5'));
	g.setValBox(2, 7, g.getValBoxOfChar('6'));
	g.setValBox(2, 8, g.getValBoxOfChar('8'));

	// Three Middle Lines
	g.setValBox(3, 1, g.getValBoxOfChar('4'));
	g.setValBox(3, 3, g.getValBoxOfChar('8'));
	g.setValBox(3, 4, g.getValBoxOfChar('1'));
	g.setValBox(3, 7, g.getValBoxOfChar('2'));

	g.setValBox(4, 6, g.getValBoxOfChar('8'));
	g.setValBox(4, 7, g.getValBoxOfChar('5'));

	g.setValBox(5, 1, g.getValBoxOfChar('9'));
	g.setValBox(5, 4, g.getValBoxOfChar('6'));
	g.setValBox(5, 5, g.getValBoxOfChar('5'));
	g.setValBox(5, 7, g.getValBoxOfChar('7'));
	g.setValBox(5, 8, g.getValBoxOfChar('3'));

	// Last Three Lines
	g.setValBox(6, 0, g.getValBoxOfChar('4'));
	g.setValBox(6, 2, g.getValBoxOfChar('9'));
	g.setValBox(6, 5, g.getValBoxOfChar('3'));
	g.setValBox(6, 7, g.getValBoxOfChar('8'));
	g.setValBox(6, 8, g.getValBoxOfChar('5'));

	g.setValBox(7, 0, g.getValBoxOfChar('1'));
	g.setValBox(7, 1, g.getValBoxOfChar('6'));
	g.setValBox(7, 2, g.getValBoxOfChar('2'));
	g.setValBox(7, 5, g.getValBoxOfChar('9'));
	g.setValBox(7, 7, g.getValBoxOfChar('3'));

	g.setValBox(8, 0, g.getValBoxOfChar('5'));
	g.setValBox(8, 3, g.getValBoxOfChar('7'));
	g.setValBox(8, 5, g.getValBoxOfChar('6'));
}

void testGrid2(Grid& g) {
	// Three First Lines
	g.setValBox(1, 0, g.getValBoxOfChar('2'));
	g.setValBox(2, 0, g.getValBoxOfChar('3'));

	// Three Middle Lines
	g.setValBox(3, 1, g.getValBoxOfChar('1'));

	// Last Three Lines
	g.setValBox(6, 2, g.getValBoxOfChar('1'));
}

void testGrid3(Grid& g) {
	// Three First Lines
	g.setValBox(0, 2, g.getValBoxOfChar('7'));
	g.setValBox(0, 6, g.getValBoxOfChar('8'));

	g.setValBox(1, 0, g.getValBoxOfChar('3'));
	g.setValBox(1, 2, g.getValBoxOfChar('6'));
	g.setValBox(1, 3, g.getValBoxOfChar('1'));
	g.setValBox(1, 4, g.getValBoxOfChar('8'));
	g.setValBox(1, 5, g.getValBoxOfChar('2'));
	g.setValBox(1, 6, g.getValBoxOfChar('7'));
	g.setValBox(1, 7, g.getValBoxOfChar('4'));
	g.setValBox(1, 8, g.getValBoxOfChar('5'));

	g.setValBox(2, 1, g.getValBoxOfChar('8'));
	g.setValBox(2, 3, g.getValBoxOfChar('5'));
	g.setValBox(2, 4, g.getValBoxOfChar('3'));
	g.setValBox(2, 5, g.getValBoxOfChar('7'));

	// Three Middle Lines
	g.setValBox(3, 0, g.getValBoxOfChar('6'));
	g.setValBox(3, 1, g.getValBoxOfChar('7'));
	g.setValBox(3, 2, g.getValBoxOfChar('2'));
	g.setValBox(3, 5, g.getValBoxOfChar('5'));
	g.setValBox(3, 6, g.getValBoxOfChar('9'));

	g.setValBox(4, 1, g.getValBoxOfChar('4'));
	g.setValBox(4, 2, g.getValBoxOfChar('9'));
	g.setValBox(4, 3, g.getValBoxOfChar('2'));
	g.setValBox(4, 5, g.getValBoxOfChar('8'));
	g.setValBox(4, 7, g.getValBoxOfChar('1'));

	g.setValBox(5, 1, g.getValBoxOfChar('3'));
	g.setValBox(5, 3, g.getValBoxOfChar('4'));
	g.setValBox(5, 5, g.getValBoxOfChar('6'));
	g.setValBox(5, 8, g.getValBoxOfChar('7'));

	// Last Three Lines
	g.setValBox(6, 0, g.getValBoxOfChar('7'));
	g.setValBox(6, 1, g.getValBoxOfChar('6'));
	g.setValBox(6, 3, g.getValBoxOfChar('8'));
	g.setValBox(6, 6, g.getValBoxOfChar('4'));
	g.setValBox(6, 8, g.getValBoxOfChar('9'));

	g.setValBox(7, 0, g.getValBoxOfChar('9'));
	g.setValBox(7, 2, g.getValBoxOfChar('8'));
	g.setValBox(7, 5, g.getValBoxOfChar('3'));

	g.setValBox(8, 3, g.getValBoxOfChar('6'));
	g.setValBox(8, 6, g.getValBoxOfChar('3'));
}

int main() {

	Grid g;
	std::string correctGrid = "n";

	// testGrid(g); // Base Test
	// testGrid2(g); // Test for Method 2 Resolution
	// testGrid3(g);

	while (correctGrid.at(0) != 'y' && correctGrid.at(0) != 'Y') {
		fillGrid(g);
		g.showGrid();

		std::cout << "Is this grid OK? (y/n) : ";
		std::cin >> correctGrid;
	}

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	g.resolveCompletely();
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "FINAL GRID... " << std::endl << std::endl;
	g.showGrid();
	std::cout << "Took " << diff/1000000.0 << " ms" << std::endl;
	std::cout << "Took " << diff << " ns" << std::endl << std::endl;



	return 0;
}