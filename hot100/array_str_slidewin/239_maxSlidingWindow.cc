#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;
#define FIRST_TIME 0
#define SECOND_TIME 1

#if FIRST_TIME
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> ans;
      // priority_queue
      priority_queue<pair<int,int>> q;
      for(int i = 0; i < k; i++)
	q.push(pair(nums[i], i));
      ans.emplace_back(q.top().first);

      // 0 1 2 3 4 5 k = 2
      for(int i = k; i < nums.size(); i++){
	q.push(pair(nums[i], i));
	while(!q.empty() && (q.top().second <= i - k
			     || q.top().second > i)){
	  q.pop();
	}
	ans.emplace_back(q.top().first);
      }
      return ans;
    }
};
#if 0
/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/
//You are given an array of integers nums,
//there is a sliding window of size k which is moving from the very leftof the array to the very right.
//You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//Return the max sliding window.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> q;
        if (k == 1)
            return nums;

        for (int i = 0; i < k; i++) {
            q.emplace(nums[i], i);
        }
        ans.push_back(q.top().first);
        for (int i = k; i < nums.size(); i++) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k)
                q.pop();
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

// Max-Heap
// priority_queue 
// 1,3,-1,-3,5,3,6,7
// 1,3,3,3,5,5,6,7
// prefixMax and SuffixMax
// you have to consider whether index of i is multiplies of k or not,
// if it is then max is the group
// if not, max is the max of former of prefix and latter of suffix
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

      vector<int> ans;

      vector<int> prefix(nums.size());
      vector<int> suffix(nums.size());

      if(k == 1)
	return nums;
      // prefix_max
      // build the prefix_max vector
      for(int i = 0; i < nums.size(); i++){
	if(i % k == 0){
	  prefix[i] = nums[i];
	}else{
	  prefix[i] = max(prefix[i-1], nums[i]);
	}
      }

      // suffix_max
      // build the suffix_max vector
      for(int i = nums.size() - 1; i >= 0; i--){
	if(i % k == 0){
	  suffix[i] = nums[i];
	}else{
	  suffix[i] = max(suffix[i+1], nums[i]);
	}
      }
      //
      for(int i = 0; i < nums.size() - k ; i++){
	if( i % k == 0){
	  ans.push_back(prefix[i]);
	}else{
	  ans.push_back(max(prefix[i], suffix[i + k - 1]));
	}
      }
      return ans;
    }
};

class Solution3 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
#endif
ostream&
operator << (ostream &os, const vector<int>& v)
{
  os << "{ ";
  for(auto it : v)
    os << it << ' ';
  return os << "} ";
}

int main(){
  Solution solve;
  vector<int> v{1,3,-1,-3,5,3,6,7};
  vector<int> v1{9, 11};
  vector<int> v2{1, -1};

  cout << v << " max slide : " << solve.maxSlidingWindow(v, 3) << endl;
  cout << v1 << " max slide : " << solve.maxSlidingWindow(v1, 2) << endl;
  cout << v2 << " max slide : " << solve.maxSlidingWindow(v2, 1) << endl;
  return 0;
}

#elif SECOND_TIME

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

#if METHOD1
/**
 * METHOD1: max heapify --- priority queue
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> max_q;
        for (int i = 0; i < k; i++)
        {
            max_q.emplace(nums[i], i);
        }
        
        vector<int> ans {max_q.top().first};

        for (int i = k; i < nums.size(); i++)
        {
            max_q.emplace(nums[i], i);
            while (max_q.top().second <= i - k) // the maximum value may be not present in the priority queue
            {
                max_q.pop();
            }
            ans.emplace_back(max_q.top().first); 
        }
        return ans; 
    }
};
#elif METHOD2

/**
 * METHOD2: monotonic queue
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && nums[i] >= nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i); 
        }
        
        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < nums.size(); i++)
        {
            while (!q.empty() && nums[i] >= nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i); 
            while (!q.empty() && q.front() <= i - k)
            {
                q.pop_front();
            }
            ans.emplace_back(nums[q.front()]);
        }
        return ans;
    }
};
#elif METHOD3

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        vector<int> prefix(n); // when you refer to the vector value you need to allocate space first
        vector<int> suffix(n);

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (i % k == 0)
            {
                prefix[i] = nums[i];
            } else {
                prefix[i] = max(prefix[i - 1], nums[i]);
            }
            
        }
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0 ; i--)
        {
            if ((i + 1) % k == 0) // need to be handed i + 1
            {
                suffix[i] = nums[i];
            } else {
                suffix[i] = max(prefix[i + 1], nums[i]);
            }
        }

        for (int i = 0; i < nums.size() - k + 1; i++)
        {
            ans.emplace_back(max(suffix[i], prefix[i + k - 1]));
        }
        
        return ans;
    }
};
#endif

int main()
{
    Solution mysolve;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    mysolve.maxSlidingWindow(nums, k);
}

#endif