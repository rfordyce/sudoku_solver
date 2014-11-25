#include <iostream>
#include <iomanip>
#include <vector>
#include <getopt.h> //for getopt()
#include <cstdlib> //for exit()
#include <string>

#include "entry.hpp"

#include "setup.cpp"
#include "brute.cpp"

void printBoard(char type='x')
{
	std::cout << "i" << iterations << " ";
	switch(type) {
		case 'r':
			std::cout << "rows:";
			break;
		case 'c':
			std::cout << "columns:";
			break;
		case 's':
			std::cout << "subsquares:";
			break;
		default:
			std::cout << "values:";
			break;
	}
	for (int i = 0; i < 81; i++) {
		if (i % 9 == 0) std::cout << std::endl;
		switch(type) {
			case 'r':
				std::cout << board.at(i).row;
				break;
			case 'c':
				std::cout << board.at(i).column;
				break;
			case 's':
				std::cout << board.at(i).subsquare;
				break;
			default:
				if (board.at(i).value > 0) {
					std::cout << board.at(i).value;
				} else {
					std::cout << "_";
				}
				break;
		}
		std::cout << " ";
	}
	std::cout << std::endl << std::endl;;
}/**/

void printBoardEverything()
{
	for (int r = 0; r < 9; r++) {//rows
		for (int c = 0; c < 9; c++) {
			if ((*rows[r][c]).value > 0) {
				std::cout << "\u250C\u2500\u2510";
			} else {
				for (int v = 1; v <= 3; v++) {
					if ((*rows[r][c]).numbers[v] > 0) {
						std::cout << (*rows[r][c]).numbers[v];
					} else { std::cout << "_";}
				}
			}
			if ((c + 1) % 3 == 0 and c < 8) std::cout << "    ";
		}
		std::cout << std::endl;
		for (int c = 0; c < 9; c++) {
			if ((*rows[r][c]).value > 0) {
				std::cout << "\u2502" << (*rows[r][c]).value << "\u2502";
			} else {
				for (int v = 4; v <= 6; v++) {
					if ((*rows[r][c]).numbers[v] > 0) {
						std::cout << (*rows[r][c]).numbers[v];
					} else { std::cout << "_";}
				}
			}
			if ((c + 1) % 3 == 0 and c < 8) std::cout << "    ";
		}
		std::cout << std::endl;
		for (int c = 0; c < 9; c++) {
			if ((*rows[r][c]).value > 0) {
				std::cout << "\u2514\u2500\u2518";
			} else {
				for (int v = 7; v <= 9; v++) {
					if ((*rows[r][c]).numbers[v] > 0) {
						std::cout << (*rows[r][c]).numbers[v];
					} else { std::cout << "_";}
				}
			}
			if ((c + 1) % 3 == 0 and c < 8) std::cout << "    ";
		}
		std::cout << std::endl;
		if ((r + 1) % 3 == 0 and r < 8) std::cout << "                                   \n                                   " << std::endl;
	}
}

void setValue(entry* e, int v)
{
	(*e).value = v;
	for (int i = 0; i < 9; i++) { //clean value from surrounding
		(*rows[(*e).row][i]).numbers[v] = 0;
		(*columns[(*e).column][i]).numbers[v] = 0;
		(*subsquares[(*e).subsquare][i]).numbers[v] = 0;
	}
	for (int x = 1; x <= 9; x++)
		(*e).numbers[x] = 0;
	std::cout << "set " << (*e).index << " to " << v << std::endl;
}

void inputText()
{
	char cont = 'x';
	std::string lines[9];
	//get input
	//test length of first line, and assign length based upon that
	//put into board
	//check board
	while (true) {
		std::cout << "input: (q or ctrl+c to quit)" << std::endl;
		getline(std::cin,lines[0]);
		if (lines[0][0] == 'q') exit(0); //user input is trash
		getline(std::cin,lines[1]);
		getline(std::cin,lines[2]);
		getline(std::cin,lines[3]);
		getline(std::cin,lines[4]);
		getline(std::cin,lines[5]);
		getline(std::cin,lines[6]);
		getline(std::cin,lines[7]);
		getline(std::cin,lines[8]);
		std::cout << "lines[0].size() : " << lines[0].size() << std::endl;
		switch(lines[0].size()) {
			case 9: //fixme
				for (int i = 0; i < 9; i++)
					for (int j = 0; j < 9; j++)
						board.at(i * 9 + j).value = lines[i][j];
				break;
			case 17: // intentional fallover
			case 18:
				for (int i = 0; i < 9; i++)
					for (int j = 0; j < 18; j++)
						if (j % 2 == 0)
							if (lines[i][j] - '0' >= 1 and lines[i][j] - '0' <= 9)
								//board.at(i * 9 + j / 2).value = lines[i][j] - '0';
								setValue(&board.at(i * 9 + j / 2), lines[i][j] - '0');
/*				for (int i = 0; i < 81; i++) // clean the numbers from input!
					if (board.at(i).value > 0) {
						for (int r = 0; r < 9; r++)
							(*rows[board.at(i).row][r]).numbers[board.at(i).value + 1] = 0;
						for (int c = 0; c < 9; c++)
							(*columns[board.at(i).column][c]).numbers[board.at(i).value + 1] = 0;
						for (int s = 0; s < 9; s++)
							(*subsquares[board.at(i).subsquare][s]).numbers[board.at(i).value + 1] = 0;
						for (int v = 1; v <= 9; v++)
							board.at(i).numbers[v] = 0;
					}*/
				break;
			default:
				std::cout << "make the rows divisible by 9 or 18!" << std::endl;
				exit(0);
		}
		printBoard();
		std::cout << "is this ok? (y/n/q): ";
		std::cin >> cont;
		if (cont == 'y') return;
		if (cont == 'q') exit(0);
		// reset stuff
		for (int i = 0; i < 9 ; i++)
			lines[i] = "";
		for (int i = 0; i < 81; i++)
			board.at(i).value = 0;
	}
}

void inputFile()
{
	return;
}

//sweep rows for invalid numbers
//sweep columns for invalid numbers
//sweep subsquares for invalid numbers
//check if no other in row have value n
//check if no other in column have value n
//check if no other in subsquare have value n
//test if board complete

void testOnlyValidPositionRows(entry* e, int v)
{
	for (int i = 0; i < 9; i++)
		if (i != (*e).row) {// not itself
			if ((*rows[(*e).row][i]).value == v) return; //value is in another box already! (shouldn't happen)
			if ((*columns[(*e).column][i]).value == v) return;
			if ((*subsquares[(*e).subsquare][i]).value == v) return;
			if ((*rows[(*e).row][i]).numbers[v] > 0) return; //this is not the only valid spot!
		}
	setValue(e,v);
}

void testOnlyValidPositionColumns(entry* e, int v)
{
	for (int i = 0; i < 9; i++)
		if (i != (*e).column) {// not itself
			if ((*rows[(*e).row][i]).value == v) return; //value is in another box already! (shouldn't happen)
			if ((*columns[(*e).column][i]).value == v) return;
			if ((*subsquares[(*e).subsquare][i]).value == v) return;
			if ((*columns[(*e).column][i]).numbers[v] > 0) return; //this is not the only valid spot!
		}
	setValue(e,v);
}

void testOnlyValidPositionSubsquares(entry* e, int v)
{
	for (int i = 0; i < 9; i++)
		if (i != (*e).subsquare) {// not itself
			if ((*rows[(*e).row][i]).value == v) return; //value is in another box already! (shouldn't happen)
			if ((*columns[(*e).column][i]).value == v) return;
			if ((*subsquares[(*e).subsquare][i]).value == v) return;
			if ((*subsquares[(*e).subsquare][i]).numbers[v] > 0) return; //this is not the only valid spot!
		}
	//setValue(e,v);
}

bool testUniqueCandidateRows(entry* e, int v)
{
	for (int i = 0; i < 9; i++)
		if (not (i == (*e).row)) {// not itself
			switch((*e).row % 3) {
				case 0: //+1+2
					if ((*rows[(*e).row + 1][i]).value == v) return false;
					if ((*rows[(*e).row + 2][i]).value == v) return false;
					if ((*rows[(*e).row + 1][i]).numbers[v] == v) return false;
					if ((*rows[(*e).row + 2][i]).numbers[v] == v) return false;
					break;
				case 1: //-1+1
					if ((*rows[(*e).row - 1][i]).value == v) return false;
					if ((*rows[(*e).row + 1][i]).value == v) return false;
					if ((*rows[(*e).row - 1][i]).numbers[v] == v) return false;
					if ((*rows[(*e).row + 1][i]).numbers[v] == v) return false;
					break;
				case 2: //-1-2
					if ((*rows[(*e).row - 1][i]).value == v) return false;
					if ((*rows[(*e).row - 2][i]).value == v) return false;
					if ((*rows[(*e).row - 1][i]).numbers[v] == v) return false;
					if ((*rows[(*e).row - 2][i]).numbers[v] == v) return false;
					break;
				default:; //exit(-1); //invalid entry
					std::cout << "invalid entry row " << (*e).row << " in testUniqueCandidateRows. v = " << v << std::endl;
					exit(-1);
			}
		}
	return true;
}/**/

bool testUniqueCandidateColumns(entry* e, int v)
{
	for (int i = 0; i < 9; i++)
		if (not (i == (*e).column)) {// not itself
			switch((*e).column % 3) {
				case 0: //+1+2
					if ((*columns[(*e).column + 1][i]).value == v) return false;
					if ((*columns[(*e).column + 2][i]).value == v) return false;
					if ((*columns[(*e).column + 1][i]).numbers[v] == v) return false;
					if ((*columns[(*e).column + 2][i]).numbers[v] == v) return false;
					break;
				case 1: //-1+1
					if ((*columns[(*e).column - 1][i]).value == v) return false;
					if ((*columns[(*e).column + 1][i]).value == v) return false;
					if ((*columns[(*e).column - 1][i]).numbers[v] == v) return false;
					if ((*columns[(*e).column + 1][i]).numbers[v] == v) return false;
					break;
				case 2: //-1-2
					if ((*columns[(*e).column - 1][i]).value == v) return false;
					if ((*columns[(*e).column - 2][i]).value == v) return false;
					if ((*columns[(*e).column - 1][i]).numbers[v] == v) return false;
					if ((*columns[(*e).column - 2][i]).numbers[v] == v) return false;
					break;
				default:; //exit(-1); //invalid entry
					std::cout << "invalid entry column " << (*e).column << " in testUniqueCandidateColumns. v = " << v << std::endl;
					exit(-1);
			}
		}
	return true;
}/**/

void testEntry(entry* e)
{
	// update numbers to exclude duplicates of known values
	for (int v = 1; v <= 9; v++) { //for each value in numbers[]
		for (int i = 0; i < 9; i++) { // this does check itself, but is probably faster than testing if it is itself
			if ((*e).numbers[v] > 0)
				if ((*rows[(*e).row][i]).value == (*e).numbers[v])             (*e).numbers[v] = 0;
			if ((*e).numbers[v] > 0)
				if ((*columns[(*e).column][i]).value == (*e).numbers[v])       (*e).numbers[v] = 0;
			if ((*e).numbers[v] > 0)
				if ((*subsquares[(*e).subsquare][i]).value == (*e).numbers[v]) (*e).numbers[v] = 0;
		}
	}
	
	// test if only valid position for numbers (no other numbers[] include it!)
	for (int v = 1; v <= 9; v++) { //for each value in numbers[]
		if ((*e).numbers[v] > 0)
			testOnlyValidPositionRows(e,v);
		if ((*e).numbers[v] > 0)
			testOnlyValidPositionColumns(e,v);
		if ((*e).numbers[v] > 0)
			testOnlyValidPositionSubsquares(e,v);
	}

	//test for unique candidate https://www.kristanix.com/sudokuepic/sudoku-solving-techniques.php
	for (int v = 1; v <= 9; v++) // possibly redundant in this program
		if ((*e).numbers[v] > 0)
			if (testUniqueCandidateRows(e,v))
				if(testUniqueCandidateColumns(e,v)) {
					std::cout << "found a unique candidate!\n";
					setValue(e,v);
				}
}/**/

void validateEntry(entry* e)
{
	int value = 0;
	for (int v = 1; v <= 9; v++) { //numbers index
		if ((*e).numbers[v] > 0 ) { // potential value
			if (value > 0) return; //other entries have values!
			value = (*e).numbers[v];
		}
	}
	if (value == 0) { //safeguard; can be removed later
		std::cout << (*e).index << ": value == 0\n";
		printBoardEverything();
		exit(-1);
	}
	setValue(e,value);
}/**/

void sweepEntries()
{
	for (int i = 0; i < 81 ; i++) {
		if (board.at(i).value < 1) testEntry(&board.at(i)); //no value yet!
	}
	for (int i = 0; i < 81 ; i++) {
		if (board.at(i).value < 1) validateEntry(&board.at(i)); //no value yet!
	}
}/**/

bool testBoardComplete()
{
	for (int i = 0; i < 81; i++)
		if (board.at(i).value < 1) return false; //there is an unset value!
	return true;
}/**/

int main(int argc, char* argv[])
{
	setupArrays();
	int c;
	while ((c = getopt(argc, argv, "idh")) != -1) {
		switch (c) {
			case 'i':
				inputText();
				break;
			case 'd':
				DISPLAY_PROGRESS = true;
				break;
			case 'f':
				inputFile();
				break;
			case 'm':
				MAX_ITERATIONS = atoi(optarg);
				break;
			case 'h':
			default: // fallover as bad flag displays help too!
				std::cout << "sudoku help" << std::endl
					<< "h\ttThis help menu" << std::endl
					<< "i\tRegular Input" << std::endl
					<< "d\tOutput the full layout whenever a new value is found" << std::endl
					<< "f\tSpecify a file to read from" << std::endl
				;
				exit(0); break;
		}
	}
	//get layout
	std::cout << "Program beginning.." << std::endl;
	//filltestvalues(); //temporary test
	//test layout is valid
	printBoard();
	do {
		///printBoardEverything();
		sweepEntries();
		iterations++;
		//if (iterations % 5000 == 0) std::cout << "iterations: " << iterations << std::endl;
		if (iterations > 900) {
			std::cout << "layouts: " << layoutsRemaining() << std::endl;
			printBoardEverything();
			exit(0);
		}
	} while (not testBoardComplete());
	printBoard(); // final output!
	printBoardEverything();
	return 0;
}/**/
