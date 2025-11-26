#include <string>
#include <vector>

using namespace std;

/**
 * LCS Question
 * METHOD: Dynamic Programming
 * dp[i][j] indicates length i and length j of each text, 
 * dp[i][j] = dp[i-1]dp[j-1] + 1 when text1[i-1] == text2[j-1]
 * dp[i][j] = max(dp[i-1][j], dp[i][j-1]) when text1[i-1] != text2[j-1]
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(); int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i = 1; i <= m; i++ ){
            char c1 = text1.at(i - 1);
            for(int j = 1; j <= n; j++ ){
                char c2 = text2.at(j - 1);
                if( c1 == c2 ){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};