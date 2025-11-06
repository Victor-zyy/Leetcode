#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


#define METHOD1 0
#define METHOD2 1

#if METHOD1
/**
 * METHOD1: Using Set and Backtrace
 */
class Solution {
public:
    vector<string> boardGenerate(vector<int>& queens, int n){
        auto board = vector<string>();
        for(int i = 0; i < n; i++ ){
            string str = string(n, '.');
            str[queens[i]] = 'Q';
            board.push_back(str);
        }
        return board;
    }
    void backtrace(vector<vector<string>>& solutions, vector<int>& queens, int n, int row, unordered_set<int>& columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2){
        if( n == row ){
            vector<string> ans = boardGenerate(queens, n);
            solutions.push_back(ans);
            return;
        }
        for( int i = 0; i < n; i++ ){
            int cols = i;
            if( columns.find(cols) != columns.end() ){
                continue;
            }
            int diagonal1 = row - i;
            if( diagonals1.find(diagonal1) != diagonals1.end() ){
                continue;
            }
            int diagonal2 = row + i;
            if( diagonals2.find(diagonal2) != diagonals2.end() ){
                continue;
            }
            queens[row] = i;
            columns.insert(cols);
            diagonals1.insert(diagonal1);
            diagonals2.insert(diagonal2);
            backtrace(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
            queens[row] = -1;
            columns.erase(cols);
            diagonals1.erase(diagonal1);
            diagonals2.erase(diagonal2);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();          
        /**
         * Calculate which column is queen
         */
        auto queens = vector<int>(n, -1); // why initialzie -1 
        auto columns = unordered_set<int>();
        auto diagonals1 =unordered_set<int>();
        auto diagonals2 =unordered_set<int>();
        backtrace(solutions, queens, n, 0, columns, diagonals1, diagonals2);
        return solutions;
    }
};

#elif METHOD2

/**
 * METHOD2: bit operations
 * x & (-x) get the loweset 1 number
 * x & (x - 1) clear the lowest 1 number
 * 
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        solve(solutions, queens, n, 0, 0, 0, 0);
        return solutions;
    }

    void solve(vector<vector<string>> &solutions, vector<int> &queens, int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            auto board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);
                availablePositions = availablePositions & (availablePositions - 1);
                int column = __builtin_ctz(position); // get 100 = 2
                                                      // 10000 = 4
                queens[row] = column;
                solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
                queens[row] = -1;
            }
        }
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};

#endif