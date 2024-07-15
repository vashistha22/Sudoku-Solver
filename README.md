# Sudoku-Solver
Description
The Sudoku Solver is an advanced C++ program designed to solve any given Sudoku puzzle using a recursive backtracking algorithm. The program offers a user-friendly interface for inputting puzzles either manually or through a file, ensuring flexibility and ease of use.

Features
Manual Input: Allows users to input the Sudoku puzzle manually with a simple and intuitive prompt.
File Input: Users can input the Sudoku puzzle from a file, facilitating ease of use and batch processing.
Grid Display: Clearly displays the Sudoku grid before and after solving the puzzle.
Validation: Ensures all inputs and steps during the solving process are valid, preventing errors and ensuring a correct solution.
Backtracking Algorithm: Utilizes an efficient recursive backtracking algorithm to find the solution, showcasing advanced problem-solving techniques.

Installation
1. Clone the repository:
   git clone https://github.com/vashistha22/sudoku-solver.git
2. Navigate to the project directory:
   cd sudoku-solver
Usage
1. Compile the program:
   g++ -o SudokuSolver sudoku_solver.cpp
2. Run the program:
   ./SudokuSolver
   
Technical Details

SudokuGrid Class
The SudokuGrid class encapsulates the entire Sudoku grid and related operations. This class is pivotal as it provides the structure and methods required to handle the Sudoku puzzle.

Attributes:

int grid[9][9]; - A 2D array to store the values of the Sudoku grid.

Methods:

Constructor: Initializes the grid and prompts the user to input the puzzle. This sets up the initial state of the puzzle.
menu(): Displays the main menu for input options, guiding the user through the input process.
readFromConsole(): Reads the Sudoku puzzle values from the console, ensuring valid input through continuous validation checks.
readFromFile(): Reads the Sudoku puzzle values from a file, with robust error handling to ensure file integrity and proper format.
setCellValue(int row, int col, int value): Sets a value in the grid, a crucial function for updating the grid during solving.
getCellValue(int row, int col) const: Gets a value from the grid, essential for checking current grid state.
displayGrid() const: Displays the Sudoku grid in a formatted manner, allowing users to visually verify the grid before and after solving.

SudokuSolver Class
The SudokuSolver class handles the core functionality of solving the Sudoku puzzle. This class employs advanced algorithms to ensure the puzzle is solved efficiently.

Attributes:

int recursiveCount = 0; - A counter to track the number of recursive calls, providing insight into the algorithm's performance.
SudokuGrid grid; - An instance of the SudokuGrid class, representing the puzzle to be solved.
Methods:

Constructor: Initializes the solver, displays the grid, and attempts to solve the puzzle, setting the stage for the solving process.
cellValueValid(int row, int col, int keyValue) const: Checks if a value is valid at a specific position by ensuring no conflicts in the row, column, or 3x3 subgrid. This is vital for maintaining Sudoku rules.
threeByThreeGridValid(int row, int col, int keyValue) const: Ensures the 3x3 subgrid validity, a critical part of the Sudoku constraints.
gridSolved() const: Checks if the grid is completely and correctly solved, acting as a termination condition for the solving algorithm.
singleCellSolve(): Implements the backtracking algorithm, attempting to place values in empty cells and backtracking when conflicts arise. This is the heart of the solving process.
solve(): Main solving function that starts the recursive solving process and displays the results, giving the user the final solved puzzle or indicating if no solution exists.
displayGrid(): Calls the displayGrid method from SudokuGrid to show the grid, providing visual feedback to the user.

Backtracking Algorithm
The backtracking algorithm implemented in the SudokuSolver class is the core mechanism used to solve the puzzle. This method involves placing a number in an empty cell, checking if it leads to a valid solution, and recursively attempting to solve the rest of the puzzle. If a conflict arises, the algorithm backtracks by removing the number and trying the next possible number. This ensures all possible configurations are explored, guaranteeing a solution if one exists.
Enter values for the grid (0 for empty cells):
Cell[1][1] --> 5
Cell[1][2] --> 3
Cell[1][3] --> 0
...

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

