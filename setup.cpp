#ifndef setup_CPP
#define setup_CPP

void setupArrays()
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

#endif
