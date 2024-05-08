#include <stdio.h>

#define ROWS 20
#define COLS 20

// Function to find the maximum of three numbers
int max(int a, int b, int c) {
    int max = (a > b) ? a : b;
    return (max > c) ? max : c;
}

// Function to find the largest product of four adjacent numbers in the grid
long long findLargestProduct(int grid[ROWS][COLS]) {
    long long maxProduct = 0;

    // Check horizontally
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            long long product = (long long)grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
            maxProduct = (product > maxProduct) ? product : maxProduct;
        }
    }

    // Check vertically
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            long long product = (long long)grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
            maxProduct = (product > maxProduct) ? product : maxProduct;
        }
    }

    // Check diagonally (from top-left to bottom-right)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            long long product = (long long)grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
            maxProduct = (product > maxProduct) ? product : maxProduct;
        }
    }

    // Check diagonally (from top-right to bottom-left)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 3; j < COLS; j++) {
            long long product = (long long)grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3];
            maxProduct = (product > maxProduct) ? product : maxProduct;
        }
    }

    return maxProduct;
}

int main() {
    int grid[20][20] = {
  {8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78},
  {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43},
  {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88},
  {52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32},
  {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40},
  {24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36},
  {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54},
  {67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8},
  {24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83},
  {21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61},
  {78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62},
  {16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17},
  {86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60},
  {19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52},
  {04, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26},
  {88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55},
  {04, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46},
  {20, 69, 36, 41, 72


    int largestProduct = findLargestProduct(grid);
    printf("Largest product of four adjacent numbers: %lld\n", findLargestProduct);

    return 0;
}
