#include <vector>
using namespace std;


/**
 * 1. 构成最大子数组和的子数组为 nums[i:j]，包括 nums[i] 到 nums[j−1] 共 j−i 个元素，其中 0≤i<j≤n。
 * 2. 构成最大子数组和的子数组为 nums[0:i] 和 nums[j:n]，其中 0<i<j<n。
 * First Condition we can use 53 method, and the second condition use prefix and suffix sum.
 */

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

#if METHOD1

/**
 * METHOD1:
 */
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmax(n, 0);
        int res = nums[0];   
        int pre = nums[0];
        int leftsum = nums[0];
        leftmax[0] = nums[0];
        /**
         * Condition 1: internal
         */
        for (int i = 1; i < n; i++)
        {
            pre = max(pre + nums[i], nums[i]);
            res = max(pre, res);
            leftsum += nums[i];
            leftmax[i] = max(leftmax[i - 1] , leftsum);
        }
        
        int rightsum = 0;
        for (int i = n - 1; i > 0; i--)
        {
            rightsum += nums[i];
            res = max(res, rightsum + leftmax[i - 1]);
        }
        
        return res;
    }
};

#elif METHOD2

/**
 * METHOD2: for nums[0,..,i] nums[j...,n] we can ask for the minimum number inside
 * the array like condition 1
 */
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int premax = nums[0];
        int preSummax = nums[0];

        int sum = nums[0];

        int premin = nums[0];
        int preSummin = nums[0];
        for (int i = 1; i < n; i++)
        {
            premax = max(premax + nums[i], nums[i]);
            preSummax = max(preSummax, premax);

            premin = min(premin + nums[i], nums[i]);
            preSummin = min(preSummin, premin);
            sum += nums[i];
        }

        if (preSummax < 0) {
            return preSummax;
        } else {
            return max(preSummax, sum - preSummin);
        }
        
    }
};

#elif METHOD3

#include <queue>

/**
 * ------------------------
 * front   |   |     |     | back   from front to back the presum is always increasing
 * ------------------------
 * We have also to ensure that the elements in that fifo less than n
 */
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        deque<pair<int, int>> q;
        int pre = nums[0], res = nums[0];
        q.push_back({0, pre});
        for (int i = 1; i < 2 * n; i++) {
            while (!q.empty() && q.front().first < i - n) {
                q.pop_front();
            }
            pre += nums[i % n];
            res = max(res, pre - q.front().second);
            while (!q.empty() && q.back().second >= pre) {
                q.pop_back();
            }
            q.push_back({i, pre});
        }
        return res;
    }
};

#endif


int main()
{
    Solution mysolve;
    vector<int> nums = {1, -2, 3, -2};
    mysolve.maxSubarraySumCircular(nums);
}