#include <vector>
using namespace std;

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

#if METHOD1
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            ans[( i + k ) % n] = nums[i];
        }
        nums.assign(ans.begin(), ans.end());
    }
};

#elif METHOD2

/**
 * Do it on nums vector itself no extra space allocated
 */
class Solution {
public:
    void reverse(vector<int> &nums, int l, int r){
        while ( l < r )
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};

#elif METHOD3

#include <numeric>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n); // need to be considered
        for (int start = 0; start < count; start++)
        {
            int current = start;
            do
            {   //it seems like the nums[start] is a transfer station
                swap(nums[(current + k) % n], nums[start]);
                current = (current + k) % n;
            } while (start != current);
            
        }
    }
};

#endif