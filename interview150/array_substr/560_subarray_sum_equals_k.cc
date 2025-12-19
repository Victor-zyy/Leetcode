#include <vector>
#include <unordered_map>
using namespace std;

/**
 * METHOD1: Dynamic Programming
 * f(j) - f(i) = k
 * prefix sum + hashmap ( two sums )
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        #if 0
        vector<int> prefix(n, 0); // we can optimize the prefix vector
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        #endif
        unordered_map<int, int> _map;
        int ans = 0;
        _map[0] = 1;
        int prefix = 0;
        for (int i = 0; i < n; i++)
        {
            prefix += nums[i];
            int target = prefix - k;
            if (_map.count(target)){
                ans+= _map[target];
            }
            _map[prefix]++;
        }
        
        return ans;
    }

};


int main()
{

    vector<int> nums = {1, 2, 3};
    Solution myslove;
    myslove.subarraySum(nums, 3);
}