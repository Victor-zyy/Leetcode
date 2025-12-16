#include <vector>
using namespace std;


/**
 * METHOD1: Kadane's Algo -- Maximum Subarray Problem
 * Dynamic Programming -- f(i)=max{f(i−1)+nums[i],nums[i]}
 */
class Solution {
public:
    struct Status
    {
        int lSum;
        int rSum;
        int mSum;
        int iSum;
    };

    Status PushUp(Status l, Status r)
    {
        Status ret;
        ret.lSum = max(l.lSum, l.iSum + r.lSum);
        ret.rSum = max(r.rSum, r.iSum + l.rSum);
        ret.iSum = l.iSum + r.iSum; // Interval
        ret.mSum = max( l.rSum + r.lSum, max(l.mSum, r.mSum));
        return ret;
    }

    Status get(vector<int> &nums, int l, int r){
        if ( l == r )
            return (Status) { nums[l], nums[l], nums[l], nums[l] };
        int m = ( l + r ) >> 1;
        Status ls = get(nums, l, m);
        Status rs = get(nums, m + 1, r);
        return PushUp(ls, rs);
    }
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int premax = 0;
        int maxSum = nums[0];
        for (const auto& num : nums)
        {
            premax = max( premax + num, num);
            maxSum = max(maxSum, premax);
        }
        return maxSum; 
    }
};