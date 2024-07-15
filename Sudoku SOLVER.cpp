#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class SudokuGrid {
  int grid[9][9]; // Holds the Sudoku values
  
public:
  SudokuGrid() {
    menu();
  }
  
private:
  void menu() {
    cout << "\n======================\n";
    cout << "    Sudoku Solver\n";
    cout << "======================\n\n";
    cout << "Welcome to Sudoku Solver!\n";
    cout << "Input the puzzle:\n";
    cout << "1. Manual input (Enter 1)\n";
    cout << "2. File input (Enter 2)\n";
    cout << "   (File must have 81 values, 0 for empty cells)\n--> ";
    
    int option;
    cin >> option;
    
    if (option == 1) 
      readFromConsole();
    else if (option == 2) 
      readFromFile();
    else 
      menu(); // Re-display menu for invalid input
  }
  
  void readFromConsole() {
    cout << "\nEnter values for the grid (0 for empty cells):\n";
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        int value;
        cout << "Cell[" << row + 1 << "][" << col + 1 << "] --> ";
        cin >> value;
        
        while (value < 0 || value > 9) {
          cout << "Invalid value! Try again:\n";
          cout << "Cell[" << row + 1 << "][" << col + 1 << "] --> ";
          cin >> value;
        }
        
        grid[row][col] = value;
      }
      cout << "-------\n";
    }
  }
  
  void readFromFile() {
    char filename[30];
    cout << "\nEnter the filename:\n--> ";
    cin >> filename;
    
    ifstream input_file(filename);
    if (!input_file) {
      cerr << "Error opening file: " << filename << endl;
      exit(EXIT_FAILURE);
    }
    
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        int value;
        input_file >> value;
        
        if (value < 0 || value > 9) {
          cerr << "Invalid value in " << filename << " at position " << (row * 9 + col + 1) << endl;
          exit(EXIT_FAILURE);
        }
        
        grid[row][col] = value;
      }
    }
    
    input_file.close();
  }
  
public:
  void setCellValue(int row, int col, int key) {
    grid[row][col] = key;
  }
  
  int getCellValue(int row, int col) {
    return grid[row][col];
  }
  
  void displayGrid() {
    cout << "++=====================================++";
    for (int row = 0; row < 9; row++) {
      cout << "\n||";
      for (int col = 0; col < 9; col++) {
        cout << (grid[row][col] != 0 ? to_string(grid[row][col]) : " ") << (col % 3 == 2 ? " ||" : "  ");
      }
      if (row % 3 == 2) 
        cout << "\n++=====================================++";
      else 
        cout << "\n++-----------++-----------++-----------++";
    }
    cout << " ";
  }
};

class SudokuSolver {
  int recursiveCount = 0; // Count of recursive calls
  SudokuGrid grid; // The grid object
  
public:
  SudokuSolver() {
    displayGrid();
    cout << "\nCalculating...\n";
    solve();
    displayGrid();
  }
  
private:
  bool cellValueValid(int row, int col, int keyValue) {
    for (int i = 0; i < 9; i++) {
      if (grid.getCellValue(row, i) == keyValue || grid.getCellValue(i, col) == keyValue)
        return false;
    }
    return ThreeByThreeGridValid(row, col, keyValue);
  }
  
  bool ThreeByThreeGridValid(int row, int col, int keyValue) {
    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = startRow; i < startRow + 3; i++) {
      for (int j = startCol; j < startCol + 3; j++) {
        if (grid.getCellValue(i, j) == keyValue)
          return false;
      }
    }
    return true;
  }
  
  bool gridSolved() {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (grid.getCellValue(i, j) == 0 || !cellValueValid(i, j, grid.getCellValue(i, j)))
          return false;
      }
    }
    return true;
  }
  
  bool singleCellSolve() {
    recursiveCount++;
    if (gridSolved()) return true;
    
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        if (grid.getCellValue(row, col) == 0) {
          for (int keyValue = 1; keyValue <= 9; keyValue++) {
            if (cellValueValid(row, col, keyValue)) {
              grid.setCellValue(row, col, keyValue);
              if (singleCellSolve()) return true;
              grid.setCellValue(row, col, 0);
            }
          }
          return false; // Backtrack
        }
      }
    }
    return false;
  }
  
  void solve() {
    if (singleCellSolve()) {
      cout << "Puzzle solved!\n\n";
    } else {
      cout << "No solution exists for this puzzle.\n";
    }
    cout << "Recursive calls: " << recursiveCount << endl;
  }
  
  void displayGrid() {
    grid.displayGrid();
  }
};

int main() {
  SudokuSolver ss;
  return 0;
}
