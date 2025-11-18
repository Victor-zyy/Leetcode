#include <vector>
#include <iostream>
using namespace std;

#define METHOD1 0
#define METHOD2 1
#define METHOD3 0

#if METHOD1
/**
 * METHOD1: State Transition Equation
 * Dp[i] = Dp[i-1] + Dp[i-2]
 */
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++ ){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
#elif METHOD2

/**
 * METHOD2: matrix quick power 
 * [1 1]  [f(n)]    = [f(n+1)]
 * [1 0]  [f(n-1)]    [f(n)]
 * 
 * Using quick-power to accelerate the matrix multiplication
 */
class Solution {
public:
    vector<vector<long long>>  multiply(vector<vector<long long>> &a, vector<vector<long long>> &b){
        vector<vector<long long>> c(2, vector<long long>(2));
        for(int i = 0; i < 2; i++ ){
            for(int j = 0; j < 2; j++ ){
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
    vector<vector<long long>> matrixPow(vector<vector<long long>> a, int n){
        vector<vector<long long>> ret = { {1, 0}, {0, 1} };
        while ( n > 0)
        {
            if( n & 1){
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret; 
    }
    int climbStairs(int n) {
        vector<vector<long long>> matrx = { {1, 1}, {1, 0} };
        auto ret = matrixPow(matrx, n);
        return ret[0][0];
    }
};
#endif


int main(){
    Solution myslove;
    myslove.climbStairs(2);
}