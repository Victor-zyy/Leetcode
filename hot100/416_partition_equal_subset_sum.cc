#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define METHOD1 0
#define METHOD2 1

#if METHOD1
/**
 * METHOD1: Dynamic Programming (0-1 backpack question)
 * 其中 dp[i][j] 表示从数组的 [0,i] 
 * 下标范围内选取若干个正整数（可以是 0 个），
 * 是否存在一种选取方案使得被选取的正整数的和等于 j
 * dp[i][j] = { dp[i-1][j] | dp[i-1][j-num] for j >= nums[i] }
 *            { dp[i-1][j]                  for j < nums[i] }
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        if( n < 2 )
            return false;

        int sum = accumulate(nums.begin(), nums.end(),0);
        int maxNum = *max_element(nums.begin(), nums.end());

        if( sum & 1 )
            return false;

        int target = sum / 2;

        if(maxNum > target)
            return false;
        
        
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // boader condition 
        for(int i = 0; i < n; i++){
        // we don't choose to accumulate zero
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        // we don't choose to accumulate zero

        for(int i = 1; i < n; i++ ){
            for(int j = 1; j <= target; j++ ){
                int num = nums[i];
                if( j >= num ){
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-num];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n-1][target];
    }
};

#elif METHOD2

/**
 * METHOD2: dp[j]表示：考虑当前已经遍历过的所有数字，能否凑出总和 
 * dp[j] = dp[j] || dp[j-num]对应二维DP中的两种选择
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if( n < 2 )
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if( sum & 1 )
            return false;
        int maxNum = *max_element(nums.begin(), nums.end());
        int target = sum / 2;
        if( target < maxNum )
            return false;

        vector<int> dp(target + 1, 0);
        dp[0] = true;
        for(int i = 0; i < n; i++ ){
            int num = nums[i];
            for(int j = target; j >= num; --j ){
                dp[j] |= dp[j - num];
            }
        }

        return dp[target];
    }
};


#endif