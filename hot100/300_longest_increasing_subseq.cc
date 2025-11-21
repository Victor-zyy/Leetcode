#include <vector>
using namespace std;

#define METHOD1 0
#define METHOD2 1

#if METHOD1
/**
 * METHOD1: dp[i] = max([j=0...i-1])dp[j]  + 1 && (nums[i] > nums[j])
 * Time Complexity O(n^2)
 */
class Solution {
private:
    int max_seq = 1;
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if( nums[i] > nums[j] ){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_seq = max(max_seq, dp[i]);
        }
        return max_seq;
    }
};
#elif METHOD2

/**
 * METHOD2: Greedy + Binary-Search
 * Aim at Time Complexity O(nlog(n))
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1;
        int n = nums.size();
        if( n == 0 ){
            return 0;
        }
        vector<int> d(n + 1);
        d[len] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if( nums[i] > d[len] ){
                d[++len] = nums[i];
            }else {
                // binary search d array to find which one is smaller than nums[i]
                int left = 1; int right = len;  // left why equals 1
                int pos = 0;
                while (left <= right)
                {
                    int mid = (left + right) >> 1;
                    if( d[mid] < nums[i] ){
                        pos = mid;
                        left = mid + 1;
                    }else{
                        right = mid - 1;
                    }
                }
                d[pos + 1] = nums[i]; 
            }
        }
        return len;
    }
};

#endif

int main()
{
    vector<int> num = {1,3,6,7,9,4,10,5,6};
    Solution mysolve;
    mysolve.lengthOfLIS(num);
}