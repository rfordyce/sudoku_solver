/*
includes

object for each entry
	square
	row
	column
	am I complete
	array[9] available numbers


test if subsquare is valid
test line for valid entries

test if game is complete

main
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <getopt.h> //for getopt()
#include <cstdlib> //for exit()

class entry {
public:
	int value;
	bool complete;
	int square;
	int row;
	int column;
	bool numbers[9];
entry() { //initializer
	value = 0;
	complete=false;
	//square;
	//row;
	//column;
	for (int i = 0; i < 9; i++) {
		numbers[i] = false;
	}
}
};

std::vector <entry> board(81);
//hardcoded arrays of pointers to the 9 each row, column, subsquares

void testLayout(){}

//sweep rows for invalid numbers
//sweep columns for invalid numbers
//sweep subsquares for invalid numbers
//check if no other in row have value n
//check if no other in column have value n
//check if no other in subsquare have value n
//test if board complete

void sweepRows()
{
	for (int i = 0; i < 81 ; i++) {
		
	}
}
	
void sweepColumns(){}
void sweepSubsquares(){}

void printBoard(){;}

void printReport()
{
	std::cout << "report goes here!" << std::endl;
	printBoard();
	return;
}/**/

int main(int argc, char* argv[])
{
	int c;
	while ((c = getopt(argc, argv, "sgh")) != -1) {
		switch (c) {
			case 's':
				std::cout << "Running in Solver Mode" << std::endl;
				break;
			case 'g':
				std::cout << "Running in Generate Mode" << std::endl;
				break;
			case 'h':
				std::cout << "sudoku help" << std::endl
				          << "-s\tSolver Mode" << std::endl
				          << "-g\tGenerate Mode" << std::endl
				;
				exit(0); break;
			default:;
		}
	}
	
	//get layout
	//test layout
	//fill vectors of pointers
	
	std::cout << "Program beginning.." << std::endl;
	//program stuff
	printReport();
	return 0;
}/**/
