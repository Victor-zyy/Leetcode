#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define METHOD1 0
#define METHOD2 2
#if METHOD1
/**
 * METHOD1: Dynamic Programming 
 * dp[i] = max(dp[i-1] * nums[i], nums[i])
 * dpmax[i] = max(dpmax[i-1] * nums[i], nums[i], dpmin[i-1]*nums[i])
 * dpmin[i] = min(dpmin[i-1] * nums[i], nums[i], dpmax[i-1]*nums[i])
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<long> dpmax(nums.begin(), nums.end());
        vector<long> dpmin(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++ ){
            dpmax[i] = max(dpmax[i-1] * nums[i], max(dpmin[i-1]*nums[i], (long)nums[i]));
            dpmin[i] = min(dpmax[i-1] * nums[i], min(dpmin[i-1]*nums[i], (long)nums[i]));
        }
        return *max_element(dpmax.begin(), dpmax.end());
    }
};
#elif METHOD2

/**
 * METHOD1: Dynamic Programming 
 * dp[i] = max(dp[i-1] * nums[i], nums[i])
 * dpmax[i] = max(dpmax[i-1] * nums[i], nums[i], dpmin[i-1]*nums[i])
 * dpmin[i] = min(dpmin[i-1] * nums[i], nums[i], dpmax[i-1]*nums[i])
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long dpmax = nums[0]; long dpmin = nums[0]; long ans = nums[0];
        for(int i = 1; i < nums.size(); i++ ){
            long mx = dpmax;
            long mi = dpmin;
            dpmax = max(mx * nums[i], max(mi*nums[i], (long)nums[i]));
            dpmin = min(mx * nums[i], min(mi*nums[i], (long)nums[i]));
            ans = max(dpmax, ans);
        }
        return ans;
    }
};

#endif


int main()
{
    vector<int> nums = {-2,3,-4};
    Solution mysolve;
    mysolve.maxProduct(nums);
    cout << __INT_MAX__ << endl;
}