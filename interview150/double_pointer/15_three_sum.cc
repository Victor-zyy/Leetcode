#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	// -nums[i] = nums[j] + nums[k]
	// to let no duplicate use set
    vector<vector<int>> threeSum(vector<int>& nums) {
        int first = 0; 
        sort(nums.begin(), nums.end());  // accending-order
        vector<vector<int>> ans;
        for (first = 0; first < nums.size(); first++)
        {
            // to ensure no duplicates 
            if (first > 0 && nums[first] == nums[first - 1]) continue;

            int target = 0 - nums[first];
            int second = first + 1;

            int third = nums.size() - 1; // why we need to init the third var here? not in while loop--- it will exceed the time limit

            for (second ; second < nums.size() ; second++)
            {
                // to ensure no duplicates 
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;

                while (second < third && nums[second] + nums[third] > target)
                {
                    --third;
                }
               
                // why we need break
                if (second == third) break;

                if (nums[second] + nums[third] == target)
                    ans.push_back({nums[first], nums[second], nums[third]});
            }
            
        }
        return ans; 
    }
};


int main()
{
    Solution mysolve;
    vector<int> nums = {-1,0,1,2,-1,-4};
    mysolve.threeSum(nums);
}