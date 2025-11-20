#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


/**
 * METHOD1:  Dynamic Programming
 * F(i)=minj=0…n−1​F(i−cj​)+1
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for( int j = 0; j < coins.size(); j++ ){
                if( coins[j] <= i ){
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount]; 
    }
};


int main()
{
    Solution mysolve;
    vector<int> coins = {1, 2, 5};
    mysolve.coinChange(coins, 11);
}