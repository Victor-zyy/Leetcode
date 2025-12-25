#include <vector>
using namespace std;

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

#if METHOD1
/**
 * Using Double Pointer
 */
#elif METHOD2

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        
        return left; 
    }
};
#elif METHOD3

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }
        return left; 
    }
};
#endif

int main()
{
    vector<int> nums = {3,2,2,3};
    int val = 2;
    Solution mysolve;
    mysolve.removeElement(nums, val);            
}