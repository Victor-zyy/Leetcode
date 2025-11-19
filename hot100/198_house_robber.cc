#include <vector>
#include <iostream>
using namespace std;

#define METHOD1 0
#define METHOD2 1

#if METHOD1
/**
 * dp[i]=max(dp[i−2]+nums[i],dp[i−1])
 * Condition:
 * dp[0] = nums[0]
 * dp[1] = max(nums[0],nums[1])
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        if( nums.size() <= 1){
            return dp[0];
        }
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++ ){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[nums.size() - 1];
    }
};
#elif METHOD2

/**
 * dp[i]=max(dp[i−2]+nums[i],dp[i−1])
 * Condition:
 * dp[0] = nums[0]
 * dp[1] = max(nums[0],nums[1])
 * do not use dp array
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[0];
        if( nums.size() <= 1){
            return temp;
        }
        int first = max(nums[0], nums[1]);
        int second = max(first, temp);
        for(int i = 2; i < nums.size(); i++ ){
            second = max(first, temp + nums[i]);
            temp = first; 
            first = second;
        }
        return second;
    }
};

#endif


int main(){
    Solution mysolve;
    vector<int> num = {2, 1, 1, 2};
    cout << mysolve.rob(num) << endl;
}