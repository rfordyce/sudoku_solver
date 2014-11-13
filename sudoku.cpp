#include <iostream>
#include <iomanip>
#include <vector>
#include <getopt.h> //for getopt()
#include <cstdlib> //for exit()
#include <string>

bool DISPLAY_PROGRESS = false;

class entry {
public:
	int value;
	int index;
	int row;
	int column;
	int subsquare;
	int numbers[10]; // wasted,1,2,3,4,5,6,7,8,9
	// possible numbers
	// impossible numbers
entry() { //initializer
	value = 0;
	//square;
	//row;
	//column;
	numbers[0] = 0; //wasted for convenience
	for (int v = 1; v <= 9; v++) { //set the number entries
		numbers[v] = v;
	}
}
};/**/

int iterations = 0;

std::vector <entry> board(81);
entry* rows[9][9];
entry* columns[9][9];
entry* subsquares[9][9];

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
			for (int v = 1; v <= 3; v++) {
				if ((*rows[r][c]).numbers[v] > 0) {
					std::cout << (*rows[r][c]).numbers[v];
				} else { std::cout << "_";}
			}
			if ((c + 1) % 3 == 0 and c < 8) std::cout << "   ";
		}
		std::cout << std::endl;
		for (int c = 0; c < 9; c++) {
			for (int v = 4; v <= 6; v++) {
				if ((*rows[r][c]).numbers[v] > 0) {
					std::cout << (*rows[r][c]).numbers[v];
				} else { std::cout << "_";}
			}
			if ((c + 1) % 3 == 0 and c < 8) std::cout << "   ";
		}
		std::cout << std::endl;
		for (int c = 0; c < 9; c++) {
			for (int v = 7; v <= 9; v++) {
				if ((*rows[r][c]).numbers[v] > 0) {
					std::cout << (*rows[r][c]).numbers[v];
				} else { std::cout << "_";}
			}
			if ((c + 1) % 3 == 0 and c < 8) std::cout << "   ";
		}
		std::cout << std::endl;
		if ((r + 1) % 3 == 0 and r < 8) std::cout << "                              \n                              " << std::endl;
	}
}

void inputBoard()
{
	char cont = 'x';
	std::string lines[9];
	//get input
	//test length of first line, and assign length based upon that
	//put into board
	//check board
	while (true) {
		std::cout << "input: " << std::endl;
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
			case 17:
			case 18:
				for (int i = 0; i < 9; i++)
					for (int j = 0; j < 18; j++)
						if (j % 2 == 0) {
							if (lines[i][j] - '0'>= 1 and lines[i][j] - '0'<= 9) {
								if (DISPLAY_PROGRESS) std::cout << "i = " << i << " j = " << j << " lines[i][j] = " << lines[i][j] << "boardindex: " << i * 9 + j / 2 << std::endl;
								board.at(i * 9 + j / 2).value = lines[i][j] - '0';
							}
						}
				for (int i = 0; i < 81; i++) //clean the numbers from input!
					if (board.at(i).value > 0)
						for (int v = 1; v <= 9; v++)
							board.at(i).numbers[v] = 0;
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

void setupArrays() //this should be in a separate file
{
	for (int i = 0; i < 81; i++) {
		board.at(i).index = i; // saves math later at the expense of negligible amount of memory
		board.at(i).row = i / 9; // abuses integar truncation
		board.at(i).column = i % 9; // remainder is the column
		board.at(i).subsquare = (board.at(i).row / 3) + (board.at(i).column / 3) + i / 27 * 2; // refer to spreadsheet
	}
	// row pointers
	rows[0][0] = &board.at(0);
	rows[0][1] = &board.at(1);
	rows[0][2] = &board.at(2);
	rows[0][3] = &board.at(3);
	rows[0][4] = &board.at(4);
	rows[0][5] = &board.at(5);
	rows[0][6] = &board.at(6);
	rows[0][7] = &board.at(7);
	rows[0][8] = &board.at(8);
	rows[1][0] = &board.at(9);
	rows[1][1] = &board.at(10);
	rows[1][2] = &board.at(11);
	rows[1][3] = &board.at(12);
	rows[1][4] = &board.at(13);
	rows[1][5] = &board.at(14);
	rows[1][6] = &board.at(15);
	rows[1][7] = &board.at(16);
	rows[1][8] = &board.at(17);
	rows[2][0] = &board.at(18);
	rows[2][1] = &board.at(19);
	rows[2][2] = &board.at(20);
	rows[2][3] = &board.at(21);
	rows[2][4] = &board.at(22);
	rows[2][5] = &board.at(23);
	rows[2][6] = &board.at(24);
	rows[2][7] = &board.at(25);
	rows[2][8] = &board.at(26);
	rows[3][0] = &board.at(27);
	rows[3][1] = &board.at(28);
	rows[3][2] = &board.at(29);
	rows[3][3] = &board.at(30);
	rows[3][4] = &board.at(31);
	rows[3][5] = &board.at(32);
	rows[3][6] = &board.at(33);
	rows[3][7] = &board.at(34);
	rows[3][8] = &board.at(35);
	rows[4][0] = &board.at(36);
	rows[4][1] = &board.at(37);
	rows[4][2] = &board.at(38);
	rows[4][3] = &board.at(39);
	rows[4][4] = &board.at(40);
	rows[4][5] = &board.at(41);
	rows[4][6] = &board.at(42);
	rows[4][7] = &board.at(43);
	rows[4][8] = &board.at(44);
	rows[5][0] = &board.at(45);
	rows[5][1] = &board.at(46);
	rows[5][2] = &board.at(47);
	rows[5][3] = &board.at(48);
	rows[5][4] = &board.at(49);
	rows[5][5] = &board.at(50);
	rows[5][6] = &board.at(51);
	rows[5][7] = &board.at(52);
	rows[5][8] = &board.at(53);
	rows[6][0] = &board.at(54);
	rows[6][1] = &board.at(55);
	rows[6][2] = &board.at(56);
	rows[6][3] = &board.at(57);
	rows[6][4] = &board.at(58);
	rows[6][5] = &board.at(59);
	rows[6][6] = &board.at(60);
	rows[6][7] = &board.at(61);
	rows[6][8] = &board.at(62);
	rows[7][0] = &board.at(63);
	rows[7][1] = &board.at(64);
	rows[7][2] = &board.at(65);
	rows[7][3] = &board.at(66);
	rows[7][4] = &board.at(67);
	rows[7][5] = &board.at(68);
	rows[7][6] = &board.at(69);
	rows[7][7] = &board.at(70);
	rows[7][8] = &board.at(71);
	rows[8][0] = &board.at(72);
	rows[8][1] = &board.at(73);
	rows[8][2] = &board.at(74);
	rows[8][3] = &board.at(75);
	rows[8][4] = &board.at(76);
	rows[8][5] = &board.at(77);
	rows[8][6] = &board.at(78);
	rows[8][7] = &board.at(79);
	rows[8][8] = &board.at(80);
	// column pointers
	columns[0][0] = &board.at(0);
	columns[1][0] = &board.at(1);
	columns[2][0] = &board.at(2);
	columns[3][0] = &board.at(3);
	columns[4][0] = &board.at(4);
	columns[5][0] = &board.at(5);
	columns[6][0] = &board.at(6);
	columns[7][0] = &board.at(7);
	columns[8][0] = &board.at(8);
	columns[0][1] = &board.at(9);
	columns[1][1] = &board.at(10);
	columns[2][1] = &board.at(11);
	columns[3][1] = &board.at(12);
	columns[4][1] = &board.at(13);
	columns[5][1] = &board.at(14);
	columns[6][1] = &board.at(15);
	columns[7][1] = &board.at(16);
	columns[8][1] = &board.at(17);
	columns[0][2] = &board.at(18);
	columns[1][2] = &board.at(19);
	columns[2][2] = &board.at(20);
	columns[3][2] = &board.at(21);
	columns[4][2] = &board.at(22);
	columns[5][2] = &board.at(23);
	columns[6][2] = &board.at(24);
	columns[7][2] = &board.at(25);
	columns[8][2] = &board.at(26);
	columns[0][3] = &board.at(27);
	columns[1][3] = &board.at(28);
	columns[2][3] = &board.at(29);
	columns[3][3] = &board.at(30);
	columns[4][3] = &board.at(31);
	columns[5][3] = &board.at(32);
	columns[6][3] = &board.at(33);
	columns[7][3] = &board.at(34);
	columns[8][3] = &board.at(35);
	columns[0][4] = &board.at(36);
	columns[1][4] = &board.at(37);
	columns[2][4] = &board.at(38);
	columns[3][4] = &board.at(39);
	columns[4][4] = &board.at(40);
	columns[5][4] = &board.at(41);
	columns[6][4] = &board.at(42);
	columns[7][4] = &board.at(43);
	columns[8][4] = &board.at(44);
	columns[0][5] = &board.at(45);
	columns[1][5] = &board.at(46);
	columns[2][5] = &board.at(47);
	columns[3][5] = &board.at(48);
	columns[4][5] = &board.at(49);
	columns[5][5] = &board.at(50);
	columns[6][5] = &board.at(51);
	columns[7][5] = &board.at(52);
	columns[8][5] = &board.at(53);
	columns[0][6] = &board.at(54);
	columns[1][6] = &board.at(55);
	columns[2][6] = &board.at(56);
	columns[3][6] = &board.at(57);
	columns[4][6] = &board.at(58);
	columns[5][6] = &board.at(59);
	columns[6][6] = &board.at(60);
	columns[7][6] = &board.at(61);
	columns[8][6] = &board.at(62);
	columns[0][7] = &board.at(63);
	columns[1][7] = &board.at(64);
	columns[2][7] = &board.at(65);
	columns[3][7] = &board.at(66);
	columns[4][7] = &board.at(67);
	columns[5][7] = &board.at(68);
	columns[6][7] = &board.at(69);
	columns[7][7] = &board.at(70);
	columns[8][7] = &board.at(71);
	columns[0][8] = &board.at(72);
	columns[1][8] = &board.at(73);
	columns[2][8] = &board.at(74);
	columns[3][8] = &board.at(75);
	columns[4][8] = &board.at(76);
	columns[5][8] = &board.at(77);
	columns[6][8] = &board.at(78);
	columns[7][8] = &board.at(79);
	columns[8][8] = &board.at(80);
	// subsquare pointers
	subsquares[0][0] = &board.at(0);
	subsquares[0][1] = &board.at(1);
	subsquares[0][2] = &board.at(2);
	subsquares[1][0] = &board.at(3);
	subsquares[1][1] = &board.at(4);
	subsquares[1][2] = &board.at(5);
	subsquares[2][0] = &board.at(6);
	subsquares[2][1] = &board.at(7);
	subsquares[2][2] = &board.at(8);
	subsquares[0][3] = &board.at(9);
	subsquares[0][4] = &board.at(10);
	subsquares[0][5] = &board.at(11);
	subsquares[1][3] = &board.at(12);
	subsquares[1][4] = &board.at(13);
	subsquares[1][5] = &board.at(14);
	subsquares[2][3] = &board.at(15);
	subsquares[2][4] = &board.at(16);
	subsquares[2][5] = &board.at(17);
	subsquares[0][6] = &board.at(18);
	subsquares[0][7] = &board.at(19);
	subsquares[0][8] = &board.at(20);
	subsquares[1][6] = &board.at(21);
	subsquares[1][7] = &board.at(22);
	subsquares[1][8] = &board.at(23);
	subsquares[2][6] = &board.at(24);
	subsquares[2][7] = &board.at(25);
	subsquares[2][8] = &board.at(26);
	subsquares[3][0] = &board.at(27);
	subsquares[3][1] = &board.at(28);
	subsquares[3][2] = &board.at(29);
	subsquares[4][0] = &board.at(30);
	subsquares[4][1] = &board.at(31);
	subsquares[4][2] = &board.at(32);
	subsquares[5][0] = &board.at(33);
	subsquares[5][1] = &board.at(34);
	subsquares[5][2] = &board.at(35);
	subsquares[3][3] = &board.at(36);
	subsquares[3][4] = &board.at(37);
	subsquares[3][5] = &board.at(38);
	subsquares[4][3] = &board.at(39);
	subsquares[4][4] = &board.at(40);
	subsquares[4][5] = &board.at(41);
	subsquares[5][3] = &board.at(42);
	subsquares[5][4] = &board.at(43);
	subsquares[5][5] = &board.at(44);
	subsquares[3][6] = &board.at(45);
	subsquares[3][7] = &board.at(46);
	subsquares[3][8] = &board.at(47);
	subsquares[4][6] = &board.at(48);
	subsquares[4][7] = &board.at(49);
	subsquares[4][8] = &board.at(50);
	subsquares[5][6] = &board.at(51);
	subsquares[5][7] = &board.at(52);
	subsquares[5][8] = &board.at(53);
	subsquares[6][0] = &board.at(54);
	subsquares[6][1] = &board.at(55);
	subsquares[6][2] = &board.at(56);
	subsquares[7][0] = &board.at(57);
	subsquares[7][1] = &board.at(58);
	subsquares[7][2] = &board.at(59);
	subsquares[8][0] = &board.at(60);
	subsquares[8][1] = &board.at(61);
	subsquares[8][2] = &board.at(62);
	subsquares[6][3] = &board.at(63);
	subsquares[6][4] = &board.at(64);
	subsquares[6][5] = &board.at(65);
	subsquares[7][3] = &board.at(66);
	subsquares[7][4] = &board.at(67);
	subsquares[7][5] = &board.at(68);
	subsquares[8][3] = &board.at(69);
	subsquares[8][4] = &board.at(70);
	subsquares[8][5] = &board.at(71);
	subsquares[6][6] = &board.at(72);
	subsquares[6][7] = &board.at(73);
	subsquares[6][8] = &board.at(74);
	subsquares[7][6] = &board.at(75);
	subsquares[7][7] = &board.at(76);
	subsquares[7][8] = &board.at(77);
	subsquares[8][6] = &board.at(78);
	subsquares[8][7] = &board.at(79);
	subsquares[8][8] = &board.at(80);
}/**/

void setValue(entry* e, int v)
{
	(*e).value = v;
	for (int i = 0; i < 9; i++) { //clean value from surrounding
		(*rows[(*e).row][i]).numbers[v] = 0;
		(*columns[(*e).column][i]).numbers[v] = 0;
		(*subsquares[(*e).subsquare][i]).numbers[v] = 0;
	}
	for (int v = 1; v <= 9; v++)
		(*e).numbers[v] = 0;
	if (DISPLAY_PROGRESS) printBoard();
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
		if (i != (*e).column) {// not itself
			if ((*rows[(*e).row][i]).value == v) return; //value is in another box already! (shouldn't happen)
			if ((*rows[(*e).row][i]).numbers[v] > 0) return; //this is not the only valid spot!
		}
	setValue(e,v);
}

void testOnlyValidPositionColumns(entry* e, int v)
{
	for (int i = 0; i < 9; i++)
		if (i != (*e).column) {// not itself
			if ((*columns[(*e).column][i]).value == v) return; //value is in another box already! (shouldn't happen)
			if ((*columns[(*e).column][i]).numbers[v] > 0) return; //this is not the only valid spot!
		}
	setValue(e,v);
}

void testOnlyValidPositionSubsquares(entry* e, int v)
{
	for (int i = 0; i < 9; i++)
		if (i != (*e).column) {// not itself
			if ((*subsquares[(*e).subsquare][i]).value == v) return; //value is in another box already! (shouldn't happen)
			if ((*subsquares[(*e).subsquare][i]).numbers[v] > 0) return; //this is not the only valid spot!
		}
	setValue(e,v);
}

/*bool testUniqueCandidateRows(entry* e, int v)
{
	for (int i = 0; i < 9; i++) {
		if (not (i = (*e).row)) {// not itself
			switch((*e).row % 3) {
				case 0: //+1+2
					if ((*rows[(*e).row + 1][i]).value == v) return false;
					if ((*rows[(*e).row + 2][i]).value == v) return false;
					break;
				case 1: //-1+1
					if ((*rows[(*e).row - 1][i]).value == v) return false;
					if ((*rows[(*e).row + 1][i]).value == v) return false;
					break;
				case 2: //-1-2
					if ((*rows[(*e).row - 1][i]).value == v) return false;
					if ((*rows[(*e).row - 2][i]).value == v) return false;
					break;
				default:; //exit(-1); //invalid entry
			}
		}
	}
	return true;
}/**/

/*bool testUniqueCandidateColumns(entry* e, int v)
{
	for (int i = 0; i < 9; i++) {
		if (not (i = (*e).column)) {// not itself
			switch((*e).column % 3) {
				case 0: //+1+2
					if ((*columns[(*e).column + 1][i]).value == v) return false;
					if ((*columns[(*e).column + 2][i]).value == v) return false;
					break;
				case 1: //-1+1
					if ((*columns[(*e).column - 1][i]).value == v) return false;
					if ((*columns[(*e).column + 1][i]).value == v) return false;
					break;
				case 2: //-1-2
					if ((*columns[(*e).column - 1][i]).value == v) return false;
					if ((*columns[(*e).column - 2][i]).value == v) return false;
					break;
				default:; //exit(-1); //invalid entry
			}
		}
	}
	return true;
}/**/

void testEntry(entry* e)
{
	// update numbers to exclude duplicates of known values
	for (int v = 1; v <= 9; v++) { //for each value in numbers[]
		if ((*e).numbers[v] > 0) { //if there is a value in numbers[v]
			for (int i = 0; i < 9; i++) { // this does check itself, but is probably faster than testing if it is itself
				if ((*rows[(*e).row][i]).value == (*e).numbers[v])             (*e).numbers[v] = 0;
				if ((*columns[(*e).column][i]).value == (*e).numbers[v])       (*e).numbers[v] = 0;
				if ((*subsquares[(*e).subsquare][i]).value == (*e).numbers[v]) (*e).numbers[v] = 0;
			}
		}
	}
	
	// test if only valid position for numbers (no other numbers[] include it!)
	for (int v = 1; v <= 9; v++) { //for each value in numbers[]
		if ((*e).numbers[v] > 0) { //if there is a number in numbers[v]
			testOnlyValidPositionRows(e,v);
			testOnlyValidPositionColumns(e,v);
			testOnlyValidPositionSubsquares(e,v);
		}
	}

	//test for unique candidate https://www.kristanix.com/sudokuepic/sudoku-solving-techniques.php
	/*for (int v = 1; v <= 9; v++) //probably redundant
		if ((*e).numbers[v] > 0)
			if (testUniqueCandidateRows(e,v) and testUniqueCandidateColumns(e,v))
				setValue(e,v);*/
}/**/

void validateEntry(entry* e)
{
	int value = 0;
	for (int v = 1; v <= 9; v++) { //numbers index
		if ((*e).numbers[v] > 0 ) {
			if (value > 0) return; //other entries have values!
			value = (*e).numbers[v];
		}
	}
	if (value == 0) { //safeguard; can be removed later
		std::cout << "value == 0\n";
		exit(-1);
	}
	setValue(e,value);
	if (DISPLAY_PROGRESS) printBoard();
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

void filltestvalues()
{
	// fill with an easy sudoku for testing
	board.at(0).value = 4;
	board.at(1).value = 1;
	board.at(7).value = 3;
	board.at(8).value = 7;
	board.at(9).value = 6;
	board.at(10).value = 2;
	board.at(16).value = 9;
	board.at(17).value = 8;
	board.at(20).value = 5;
	board.at(21).value = 9;
	board.at(23).value = 2;
	board.at(24).value = 1;
	board.at(29).value = 2;
	board.at(30).value = 7;
	board.at(32).value = 3;
	board.at(33).value = 4;
	board.at(40).value = 5;
	board.at(47).value = 1;
	board.at(48).value = 4;
	board.at(50).value = 6;
	board.at(51).value = 9;
	board.at(56).value = 4;
	board.at(57).value = 3;
	board.at(59).value = 8;
	board.at(60).value = 6;
	board.at(63).value = 2;
	board.at(64).value = 5;
	board.at(70).value = 4;
	board.at(71).value = 3;
	board.at(72).value = 9;
	board.at(73).value = 6;
	board.at(79).value = 1;
	board.at(80).value = 2;
}/**/

/*void filltestvalues()
{
	//board.at(0).value = 1;
	board.at(1).value = 2;
	board.at(2).value = 3;
	board.at(3).value = 4;
	board.at(4).value = 5;
	board.at(5).value = 6;
	board.at(6).value = 7;
	board.at(7).value = 8;
	board.at(8).value = 9;
	board.at(54).value = 2;
	board.at(55).value = 3;
	board.at(56).value = 4;
	board.at(57).value = 5;
	board.at(58).value = 6;
	board.at(59).value = 7;
	board.at(60).value = 8;
	board.at(61).value = 9;
}/**/
	
int main(int argc, char* argv[])
{
	int c;
	while ((c = getopt(argc, argv, "idh")) != -1) {
		switch (c) {
			case 'i':
				inputBoard();
				break;
			case 'd':
				DISPLAY_PROGRESS = true;
				break;
			case 'f':
				inputFile();
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
	std::cout << "Building arrays.." << std::endl;
	setupArrays();
	//get layout
	std::cout << "Program beginning.." << std::endl;
	//filltestvalues(); //temporary test
	//test layout is valid
	printBoard();
	
	int last = 0;
	int latest = 0;
	do {
		///printBoardEverything();
		sweepEntries();
		iterations++;
		if (iterations % 5000 == 0) std::cout << "iterations: " << iterations << std::endl;
		latest = 0;
		/*for (int i = 0 ; i < 81 ; i++)
			for (int v = 1; v <=9 ; v++)
				if (board.at(i).numbers[v] > 0) latest++;
		if (latest == last) {
			std::cout << "stagnated with " << iterations << " iterations!" << std::endl;
			exit(0);
		}
		last = latest; //relies on an incorrect assumption; must have at least nine iterations before canning it */
		std::cout << "\n";
		printBoard();
		printBoardEverything();
		std::cout << "\n\n\n\n";
		if (iterations > 5) exit(0);
	} while (not testBoardComplete());
	printBoard(); // final output!
	return 0;
}/**/
