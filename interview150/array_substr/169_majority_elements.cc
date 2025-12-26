#include <vector>
using namespace std;

/**
 * 
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (const auto &num : nums)
        {
            if (num == candidate)
            {
                ++count;
            } else if (--count < 0)
            {
                count = 1;
                candidate = num;
            }
        }
        return candidate;
    }
};