#ifndef brute_H
#define brute_H

std::vector <int[81]> remainingboards;

//generate all remaining boards


/*
			double layouts = 1;
			int remaining = 0;
			for (int i = 0; i < 81; i++) {
				if (board.at(i).value > 0) {
					layouts = layouts; //no change to layout
					std::cout << i << " " << 1 << std::endl;
				} else {
					for (int v = 1; v <= 9; v++)
						if (board.at(i).numbers[v] > 0) remaining++;
					layouts = layouts * remaining;
					std::cout << i << " " << remaining << std::endl;
					remaining = 0;
				}
			}
*/
bool testBoardValid(int boardarray[81])
{
	// 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 == 362880
	// test rows
	if (boardarray[0]  * boardarray[1]  * boardarray[2]  * boardarray[3]  * boardarray[4]  * boardarray[5]  * boardarray[6]  * boardarray[7]  * boardarray[8]  != 362880) return false;
	if (boardarray[9]  * boardarray[10] * boardarray[11] * boardarray[12] * boardarray[13] * boardarray[14] * boardarray[15] * boardarray[16] * boardarray[17] != 362880) return false;
	if (boardarray[18] * boardarray[19] * boardarray[20] * boardarray[21] * boardarray[22] * boardarray[23] * boardarray[24] * boardarray[25] * boardarray[26] != 362880) return false;
	if (boardarray[27] * boardarray[28] * boardarray[29] * boardarray[30] * boardarray[31] * boardarray[32] * boardarray[33] * boardarray[34] * boardarray[35] != 362880) return false;
	if (boardarray[36] * boardarray[37] * boardarray[38] * boardarray[39] * boardarray[40] * boardarray[41] * boardarray[42] * boardarray[43] * boardarray[44] != 362880) return false;
	if (boardarray[45] * boardarray[46] * boardarray[47] * boardarray[48] * boardarray[49] * boardarray[50] * boardarray[51] * boardarray[52] * boardarray[53] != 362880) return false;
	if (boardarray[54] * boardarray[55] * boardarray[56] * boardarray[57] * boardarray[58] * boardarray[59] * boardarray[60] * boardarray[61] * boardarray[62] != 362880) return false;
	if (boardarray[63] * boardarray[64] * boardarray[65] * boardarray[66] * boardarray[67] * boardarray[68] * boardarray[69] * boardarray[70] * boardarray[71] != 362880) return false;
	if (boardarray[72] * boardarray[73] * boardarray[74] * boardarray[75] * boardarray[76] * boardarray[77] * boardarray[78] * boardarray[79] * boardarray[80] != 362880) return false;
	// test columns
	if (boardarray[0]  * boardarray[9]  * boardarray[18] * boardarray[27] * boardarray[36] * boardarray[45] * boardarray[54] * boardarray[63] * boardarray[72] != 362880) return false;
	if (boardarray[1]  * boardarray[10] * boardarray[19] * boardarray[28] * boardarray[37] * boardarray[46] * boardarray[55] * boardarray[64] * boardarray[73] != 362880) return false;
	if (boardarray[2]  * boardarray[11] * boardarray[20] * boardarray[29] * boardarray[38] * boardarray[47] * boardarray[56] * boardarray[65] * boardarray[74] != 362880) return false;
	if (boardarray[3]  * boardarray[12] * boardarray[21] * boardarray[30] * boardarray[39] * boardarray[48] * boardarray[57] * boardarray[66] * boardarray[75] != 362880) return false;
	if (boardarray[4]  * boardarray[13] * boardarray[22] * boardarray[31] * boardarray[40] * boardarray[49] * boardarray[58] * boardarray[67] * boardarray[76] != 362880) return false;
	if (boardarray[5]  * boardarray[14] * boardarray[23] * boardarray[32] * boardarray[41] * boardarray[50] * boardarray[59] * boardarray[68] * boardarray[77] != 362880) return false;
	if (boardarray[6]  * boardarray[15] * boardarray[24] * boardarray[33] * boardarray[42] * boardarray[51] * boardarray[60] * boardarray[69] * boardarray[78] != 362880) return false;
	if (boardarray[7]  * boardarray[16] * boardarray[25] * boardarray[34] * boardarray[43] * boardarray[52] * boardarray[61] * boardarray[70] * boardarray[79] != 362880) return false;
	if (boardarray[8]  * boardarray[17] * boardarray[26] * boardarray[35] * boardarray[44] * boardarray[53] * boardarray[62] * boardarray[71] * boardarray[80] != 362880) return false;
	// test subsquares
	if (boardarray[0]  * boardarray[1]  * boardarray[2]  * boardarray[9]  * boardarray[10] * boardarray[11] * boardarray[18] * boardarray[19] * boardarray[20] != 362880) return false;
	if (boardarray[3]  * boardarray[4]  * boardarray[5]  * boardarray[12] * boardarray[13] * boardarray[14] * boardarray[21] * boardarray[22] * boardarray[23] != 362880) return false;
	if (boardarray[6]  * boardarray[7]  * boardarray[8]  * boardarray[15] * boardarray[16] * boardarray[17] * boardarray[24] * boardarray[25] * boardarray[26] != 362880) return false;
	if (boardarray[27] * boardarray[28] * boardarray[29] * boardarray[36] * boardarray[37] * boardarray[38] * boardarray[45] * boardarray[46] * boardarray[47] != 362880) return false;
	if (boardarray[30] * boardarray[31] * boardarray[32] * boardarray[39] * boardarray[40] * boardarray[41] * boardarray[48] * boardarray[49] * boardarray[50] != 362880) return false;
	if (boardarray[33] * boardarray[34] * boardarray[35] * boardarray[42] * boardarray[43] * boardarray[44] * boardarray[51] * boardarray[52] * boardarray[53] != 362880) return false;
	if (boardarray[54] * boardarray[55] * boardarray[56] * boardarray[63] * boardarray[64] * boardarray[65] * boardarray[72] * boardarray[73] * boardarray[74] != 362880) return false;
	if (boardarray[57] * boardarray[58] * boardarray[59] * boardarray[66] * boardarray[67] * boardarray[68] * boardarray[75] * boardarray[76] * boardarray[77] != 362880) return false;
	if (boardarray[60] * boardarray[61] * boardarray[62] * boardarray[69] * boardarray[70] * boardarray[71] * boardarray[78] * boardarray[79] * boardarray[80] != 362880) return false;

	return true; //hooray, it's a valid board!
}

#endif
