#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/**
 * METHOD1: backtrace --- 
 */
class Solution {
private:
    int m;
    int n;
public:
    bool check( vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& str, int k){
        if( board[i][j] != str[k] ){
            return false;
        }else if( k == str.length() - 1 ){
            return true;
        }

        int dx[4] = { 0, 1, 0, -1};
        int dy[4] = { 1, 0, -1, 0};
        visited[i][j] = true;
        bool res = false;
        for( int i_ = 0; i_ < 4; i_++ ){
            int dir_x = dx[i_] + i;
            int dir_y = dy[i_] + j;
            if( dir_x >= 0 && dir_x < m && dir_y >= 0 && dir_y < n ){
                if(visited[dir_x][dir_y]) continue;
                res = check(board, visited, dir_x, dir_y, str, k + 1);
                if( res ) break;
            }
        }
        visited[i][j] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if( m == 0 ){
            return false;
        }
        n = board[0].size(); 
        vector<vector<bool>> visited( m, (vector<bool>)n );
        bool ans = false;
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                ans = check(board, visited, i, j, word, 0 );
                if( ans ) return ans;
            }
        } 
        return ans;
    }
};


int main(){
    vector<vector<char>> vec = {
        { 'A', 'B', 'C', 'E' },
        { 'S', 'F', 'C', 'S' },
        { 'A', 'D', 'E', 'F' }
    };

    Solution mysolve;
    mysolve.exist( vec, "ABCCED" );
}