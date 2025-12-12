#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
#define METHOD1 0
#define METHOD2 1

#if METHOD1
/**
 * METHOD1: Dynamic Programming
 * pre = max(pre + x , x)
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0; int maxSum = nums[0];
        for (const auto &x : nums)
        {
            pre = max(pre + x, x);
            maxSum = max(maxSum, pre);
        }
        return maxSum;
    }
};
#elif METHOD2

/**
 * METHOD2: maxSubArray
 * 
 * divde and conquer
 * 
 */
class Solution {
public:
    struct Status
    {
        int lSum, rSum, mSum, iSum;
        /**
         * lSum indicates from l pos 
         * rSum indicates end  r pos 
         * mSum indicates max interval
         * iSum indicates sum of interval
         */
    };
    Status pushUp(Status lsub, Status rsub){
        int iSum = lsub.iSum + rsub.iSum;
        int lSum = max(lsub.lSum, lsub.iSum + rsub.lSum);
        int rSum = max(rsub.rSum, lsub.rSum + rsub.iSum);
        int mSum = max(max(lsub.mSum, rsub.mSum), lsub.rSum + rsub.lSum);
        return (Status){lSum, rSum, mSum, iSum};
    }
    Status get(vector<int>& a, int l, int r)
    {
        if (l == r){
            return (Status){ a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lsub = get(a, l, m);
        Status rsub = get(a, m + 1, r);
        return pushUp(lsub, rsub);
    } 

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

#endif