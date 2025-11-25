#include <string>
#include <vector>
using namespace std;


/**
 * METHOD1: DynamicProgramming
 * palindromic: from back and front read the same
 * P(i,j) indicates substring (i,j) is palindrome or not
 * P(i,j)=P(i+1,j−1)∧(Si​==Sj​)
 * Boader Condition
 * substring length is 1 or 2
 * when substring length equals 1 it must be palindrome
 * when substring length equals 2 it will be palindrome when Si == Si+1
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if( n < 2 ){
            return s;
        }

        // dynamic programming array
        vector<vector<int>> dp(n, vector<int>(n)); 
        // initialize substring length equals 1
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        int maxLen = 1; 
        int begin = 0;
        // enumerate substring
        for( int L = 2; L <= n; L++ ){
            for (int i = 0; i < n; i++)
            {
                // j - i + 1 = L ( L indicates length of substring )
                int j = L + i - 1;
                if( j >= n ){
                    break;
                }

                if( s[i] != s[j] ){
                    dp[i][j] = false;
                }else{
                    if( j - i < 3 ){ // substring length 1, 2, 3 assign true value directly
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                // Update
                if( dp[i][j] && j - i + 1 > maxLen ){
                    maxLen = j - i + 1;
                    begin = i; 
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};