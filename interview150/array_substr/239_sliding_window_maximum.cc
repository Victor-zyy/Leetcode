#include <vector>
using namespace std;

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

#if METHOD1
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n, 0); 
        vector<int> suffix(n, 0); 
        for (int i = 0; i < n; i++)
        {
            if (i % k == 0) {
                prefix[i] = nums[i];
            } else {
                prefix[i] = max(prefix[i - 1], nums[i]);
            }
        }
        
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1 || (i + 1) % k == 0) // suffix conditions
            {
                suffix[i] = nums[i];
            }else {
                suffix[i] = max(suffix[i + 1], nums[i]);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i <= n - k; i++)
        {
            ans.emplace_back(max(prefix[i + k - 1], suffix[i])); //why prefix index is i + k - 1
            // that is because prefix sum
        }
        
        return ans;
    }
};
#elif METHOD2

#include <queue>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> q;

        for (int i = 0; i < k; i++)
        {
            q.push({nums[i], i});
        }
        
        ans.emplace_back(q.top().first);
        int n = nums.size();

        for (int i = k; i < n; i++)
        {
            q.push({nums[i], i}); 
            while (q.top().second <= i - k) // if we use size to pop right?
            //while (q.size() != k) // if we use size to pop right?
            {
                q.pop();
            }
            ans.emplace_back(q.top().first);
        }
       
        return ans;
    }
};

#elif METHOD3

#include <queue>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;

        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && nums[i] > nums[q.back()])
            {
                q.pop_back(); // ascending order
            }
            
            q.push_back(i);
        }
        
        ans.emplace_back(nums[q.front()]);
        int n = nums.size();

        for (int i = k; i < n; i++)
        {
            //while (q.top().second <= i - k) // if we use size to pop right?
            while (!q.empty() && nums[i] > nums[q.back()])// if we use size to pop right?
            {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k)
            {
                q.pop_front();
            }
            
            ans.emplace_back(nums[q.front()]);
        }
       
        return ans;
    }
};

#endif

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    Solution myslove;
    myslove.maxSlidingWindow(nums, 3);
}
