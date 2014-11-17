#ifndef entry_HPP
#define entry_HPP

bool DISPLAY_PROGRESS = false;
double MAX_ITERATIONS = 100000000;

// brute force the last few boards
bool BRUTEFORCE_USE = false;
double BRUTEFORCE_MAX_BOARDS = 10000;

int iterations = 0;

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
entry() {
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

std::vector <entry> board(81);
entry* rows[9][9];
entry* columns[9][9];
entry* subsquares[9][9];

#endif
