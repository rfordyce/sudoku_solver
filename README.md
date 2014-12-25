sudoku_solver
=============

A sudoku solving program.

More about the techniques used can be found [here][1]

To Build:

```bash
git clone https://github.com/rfordyce/sudoku_solver.git
cd ./sudoku_solver
make
./sudoku_solver
```

---

Initial Steps

1. Generate board with potential entries.
2. Get board from user.
3. Remove known board entries from potential pool.

Recurring Steps

1. Go through all the potential values each entry contains and determine if it is the only valid place for it.
	* Rows
	* Columns
	* Subsquares
2. Create chains that link the potential values such that if one is solved they are all solved.
3. Fewer than N boards remain?
	* Generate all remaining boards.
	* Bruteforce-match them.

[1]: https://www.kristanix.com/sudokuepic/sudoku-solving-techniques.php
