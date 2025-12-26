#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();     
        int fast = 1; int slow = 1;
        if (n == 0)
            return 0;
        while (fast < n)
        {
            if (nums[fast] != nums[fast - 1]){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow; 
    }
};