#include <vector>
using namespace std;


/**
 * Greedy method
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1)
                    return true;
            }
        }
        return false;
    }
};