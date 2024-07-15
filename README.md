# Sudoku-Solver
Description
The Sudoku Solver is a C++ program that solves a given Sudoku puzzle using a backtracking algorithm. The program allows users to input the puzzle either manually or through a file.

Features
Manual Input: Users can input the Sudoku puzzle manually.
File Input: Users can input the Sudoku puzzle from a file.
Grid Display: The program displays the Sudoku grid before and after solving the puzzle.
Validation: The program checks the validity of the grid during input and solving process.
Backtracking Algorithm: Utilizes a recursive backtracking algorithm to solve the puzzle.

Installation
1. Clone the repository:
   git clone https://github.com/your-username/sudoku-solver.git
2. Navigate to the project directory:
   cd sudoku-solver
Usage
1. Compile the program:
   g++ -o SudokuSolver sudoku_solver.cpp
2. Run the program:
   ./SudokuSolver
Input
The program supports two types of inputs:

1. Manual Input:

The user will be prompted to enter the Sudoku grid values manually.
Enter 0 for empty cells.

2. File Input:

The user will be prompted to enter the filename.
The file must contain 81 integers (0-9) separated by spaces or newlines, representing the Sudoku grid values.
Example file content
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

Example
Manual Input:
======================
    Sudoku Solver
======================

Welcome to Sudoku Solver!
Input the puzzle:
1. Manual input (Enter 1)
2. File input (Enter 2)
   (File must have 81 values, 0 for empty cells)
--> 1

Enter values for the grid (0 for empty cells):
Cell[1][1] --> 5
Cell[1][2] --> 3
Cell[1][3] --> 0
...

File Input:
======================
    Sudoku Solver
======================

Welcome to Sudoku Solver!
Input the puzzle:
1. Manual input (Enter 1)
2. File input (Enter 2)
   (File must have 81 values, 0 for empty cells)
--> 2

Enter the filename:
--> puzzle.txt

Contributing
Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

License
This project is licensed under the MIT License. See the LICENSE file for details.

