#include <vector>
using namespace std;

#define METHOD1 0
#define METHOD2 1

/**
 * Greedy Method --- Classical
 * METHOD1: reverse search the longest length of last jump
 */
#if METHOD1
class Solution {
public:
    int jump(vector<int>& nums) {
        int position = nums.size() - 1;
        int steps = 0;
        while (position > 0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (i + nums[i] >= position) {
                    position = i;
                    steps++;
                    break;
                }
            }
        }
        return steps;
    }
};

#elif METHOD2

// end 就是你在上一次更新end的时候那个点能跳到的最远距离，要想走更远，得在跳一次了（step ++）
class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int maxPos = 0;
        int end = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    steps ++;
                    end = maxPos;
                }
            }
        }
        return steps; 
    }
};
#endif


int main()
{
    vector<int> nums = {2,3,1,1,4};
    Solution mysolve;
    mysolve.jump(nums);
}