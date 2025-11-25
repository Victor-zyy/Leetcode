#include <vector>
using namespace std;

#define METHOD1 0
#define METHOD2 1

#if METHOD1
/**
 * METHOD1: Dynamic Programming MultiDimension
 * f(i,j) = f(i-1,j) + f(i, j-1)
 * f(i,j) indicates the paths numbers from upper-left-corner
 * initial condition f(0,0) = 1
 * f(0,j) equals 1
 * f(i,0) equals 1
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++){
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
#elif METHOD2

/**
 * METHOD2: to optimize space complexity from O(mn) -> O(min(m,n))
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};

#endif