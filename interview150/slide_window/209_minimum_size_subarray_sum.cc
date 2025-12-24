#include <vector>
using namespace std;

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

#if METHOD1
/**
 * METHOD1: brute force method
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = -1;
        int sum = 0;
        int minlen = __INT_MAX__;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum >= target){
                    minlen = j - i + 1 < minlen ? j - i + 1: minlen;
                }
                sum = 0;
                break;
            }
        }
        return minlen == __INT_MAX__ ? 0 : minlen;
    }
};
#elif METHOD2

/**
 * METHOD2: binary search + prefix sum to optimize
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen = __INT_MAX__;
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        
        for (int i = 1; i <= n; i++)
        {
            sums[i] = nums[i - 1] + sums[i - 1];
        }
        
        for (int i = 1; i <= n; i++)
        {
            int s_target = target + sums[i - 1];
            auto temp = lower_bound(sums.begin(), sums.end(), s_target); // find temp which is greater than s_target
            if (temp != sums.end()){
                minlen = min(minlen, static_cast<int>((temp - sums.begin()) - (i - 1)));
            }
        }
        return minlen == __INT_MAX__ ? 0 : minlen; 
    }
};
#elif METHOD3

/**
 * METHOD3: slide window
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen = __INT_MAX__;
        int end = 0; int start = 0;
        int n = nums.size();
        int sum = 0;
        while (end < n)
        {
            sum += nums[end];
            while (sum >= target)
            {
                minlen = min(minlen, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        
        return minlen == __INT_MAX__ ? 0 : minlen; 
    }
};

#endif

int main()
{
    Solution mysolve;
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    mysolve.minSubArrayLen(target, nums);
}