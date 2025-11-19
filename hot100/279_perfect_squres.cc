#include <vector>
#include <iostream>

using namespace std;

/**
 * Dynamic Programming:
 * Big Question -> tailor to the same pattern small question
 * 
 * condition 
 * dp[0] = 0
 * dp[1] = 1
 * dp[2] = 2
 * dp[3] = dp[2] + dp[1] / dp[1] + dp[1] + dp[1] = 3
 * dp[4] = 1
 * dp[5] = 2
 * dp[6] = 
 * 1 4 9 16 25
 * f[i] = 1 + minf[i-j^2] 
 */

class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n+1);
        for(int i = 1; i <= n; i++ ){
            int minn = __INT_MAX__;
            for(int j = 1; j * j <= i; j++ ){
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }            
        return f[n];
    }
};


int main(){
    Solution mysolve;
    mysolve.numSquares(12);
}