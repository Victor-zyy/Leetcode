#include <vector>
#include <string>
using namespace std;

#define METHOD1 0
#define METHOD2 1


#if METHOD1
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() < 1)
            return {};
        int num = nums[0];
        int interval = 1;
        int start = num;
        vector<string> ans;
        for (int i = 1; i < nums.size(); i++ ){
            if (nums[i] == num + 1){
                interval++;
                num = nums[i];
                continue;
            } else {
                // start -> nums[i]  (by interval)
                if (interval == 1){
                    ans.emplace_back(to_string(start));
                }else {
                    ans.emplace_back(to_string(start) + "->" + to_string(num));
                }
                start = nums[i];
                num = nums[i];
                interval = 1;
            }
        }     
        // for the last time to emplace the answer
        if (interval == 1){
            ans.emplace_back(to_string(start));
        }else {
            ans.emplace_back(to_string(start) + "->" + to_string(num));
        }
        return ans;
    }
};

#elif METHOD2

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            int low = i;
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1)
            {
                i++;
            }
            int high = i - 1; 

            string temp = to_string(nums[low]);
            if (low < high){
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            ans.push_back(move(temp));
        }
        return ans;
    }
};

#endif

int main()
{
    Solution mysolve;
    vector<int> nums = {0,2,3,4,6,8,9};
    mysolve.summaryRanges(nums);
}