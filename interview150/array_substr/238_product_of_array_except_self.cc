#include <vector>
using namespace std;


#define METHOD1 0
#define METHOD2 1


#if METHOD1
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        // prefix 
        // suffix
        prefix[0] = 1;
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        suffix[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            ans[i] = prefix[i] * suffix[i];
        }
    
        return ans;
    }
};

#elif METHOD2

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        // prefix 
        // suffix
        ans[0] = 1;
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int right = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = ans[i] * right; 
            right *= nums[i];
        }
    
        return ans;
    }
};

#endif