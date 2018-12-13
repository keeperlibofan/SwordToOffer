//
// Created by seadream on 2018/12/13.
//

#include <cstring>

class Solution {
public:
    static int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 0 || rows <= 0 || cols <= 0) {
            return 0;
        }
        auto visited = new bool[rows * cols];
        memset(visited, 0, sizeof(bool) * rows * cols);

        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

        delete[] visited;
        return count;

    }

private:
    static int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited) {
        auto result = 0;
        if (check(threshold, rows, cols, row, col, visited)) { // 通过check
            result++;
            result += movingCountCore(threshold, rows, cols, row+1, col, visited) +
                      movingCountCore(threshold, rows, cols, row-1, col, visited) +
                      movingCountCore(threshold, rows, cols, row, col+1, visited) +
                      movingCountCore(threshold, rows, cols, row, col-1, visited);
            visited[row * cols + col] = true;
        }
        return result;
    }

    static bool check(int threshold, int rows, int cols, int row, int col, bool *visited) {
        int sum = getDigitSum(row) + getDigitSum(row);
        return !(row < 0 || col < 0 || sum > threshold || row >= rows || col >= cols || visited[row * cols + col]);
    }

    static int getDigitSum(int number) {
        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number = number / 10;
        }
        return sum;
    }
};
