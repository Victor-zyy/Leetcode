#include <string>
#include <vector>

using namespace std;

/**
 * METHOD1: Dynamic Programming
 * dp[i][j] inicates i and j length word distance
 * example:
 * horse
 * ros
 * 'h' ≠ 'r'：选择最小成本操作（替换：成本1）
   'o' = 'o'：字符匹配，无成本
   'r' ≠ 's'：选择最小成本操作（删除：成本1）
   's' = 's'：字符匹配，无成本
   'e' 需要删除：成本1
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if( m * n == 0 ) return m + n;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        /**
         * Boarder Condition
         */
        for(int i = 0; i <= m; i++ ){
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; j++ ){
            dp[0][j] = j;
        }
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                /* code */
                int left = dp[i - 1][j] + 1; // delete
                int down = dp[i][j - 1] + 1; // insert
                int left_down = dp[i - 1][j - 1]; // replace when equal don't move
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                dp[i][j] = min(left, min(down, left_down));
            }
        }
        return dp[m][n]; 
    }
};