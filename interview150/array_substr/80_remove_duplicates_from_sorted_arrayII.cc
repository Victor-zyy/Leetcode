#include <vector>
using namespace std;

/**
 * Learn it like 26_remove_duplicates_from_sorted_array
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;
        int fast = 2; int slow = 2;     
        while (fast < n)
        {
            if (nums[fast] != nums[slow - 2]){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};


int main()
{
    Solution mysolve;
    vector<int> nums = {1,1,1,2,2,3};
    mysolve.removeDuplicates(nums);
}