#include <vector>
using namespace std;

#define METHOD1 0
#define METHOD2 1

/**
 * The best method is presedo hash 
 */
#if METHOD1 // using sort method() can't satisfy the requirements
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();  
        for (auto &num : nums)
        {
            if (num <= 0)
                num = n + 1;
        }
        
        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]); // [3, 4, -1, 1] ---> 4 [3, 4, 5, -1] not -1 to -4 then use abs to set 3 is -3
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return i + 1;
        }
        
        return n + 1;
    }
};

#elif METHOD2

/**
 * METHOD2: Use replacement
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();  
        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] -1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        
        return n + 1;
    }
};
#endif


int main()
{
    vector<int> nums = {3, 4, -1, 1};
    Solution mysolve;
    mysolve.firstMissingPositive(nums);
}