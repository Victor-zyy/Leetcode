#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      vector<int> prefix(nums.size());
      int res = 0;
      prefix[0] = nums[0];
      for(int i = 1; i < nums.size(); i++){
	prefix[i] = prefix[ i - 1 ] + nums[i];
      }
      // nums[0] nums[1] 2 3 4 
      // prefix[i] - prefix[j] = nums[j + 1] + ... + nums[i]
      // prefix[i] - prefix[j - 1] = nums[j] + ... + nums[i] = k
      // -> twoSums
      // Input: nums = [1,1,1], k = 2
      // prefix [1 2 3]
      unordered_map<int, int> map_;
      // sum, num of accurrence
      map_[0] = 1;
      for(int i = 0; i < prefix.size(); i++){
	auto it = map_.find(prefix[i] - k); // // FIXME:  two sums construct the format of the two sums
	if(it != map_.end())
	  res += it->second;// FIXME: add sequence of number
	map_[prefix[i]]++;
      }
      return res;
    }
};
#if 0
/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

*/
// Given an array of integers nums and an integer k, return the total number of subarrays
// whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.
// Method  prefix_sum + Hashmap
// prefix_sum attribute
// pre[0] = nums[0]
// pre[1] = nums[0] + nums[1]
// pre[i] = nums[0] + ... + nums[i]
// pre[i] - pre[j] = pre[i] + .... + pre[j + 1]
// pre[i] - pre[j - 1] = pre[i] + .... + pre[j] = k (twoSum)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int pre = 0;
      int count = 0;
      unordered_map<int, int> map_;
      map_[pre]++;// FIXME: 0,1 is the key point
      for(int i = 0 ; i < nums.size(); i++){
	pre += nums[i];
	auto it = map_.find(pre - k);
	if(it != map_.end()){
	  //count++;// FIXME: 
	  count += map_[pre-k];
	}
	map_[pre]++;// FIXME: 
      }
      return count;
    }
};

// iterate all nums' elements
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
      int count = 0;
      for(int end = 0; end < nums.size(); end++){
	int sum = 0;
	for(int start = end; start >= 0; --start){
	  sum += nums[start];
	  if(sum == k)
	    count++;
	}
      }
      return count;
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
  vector<int> nums {1, 2, 3};
  cout << nums << " k " << 3 << " count  " << solve.subarraySum(nums, 3) << endl;
  return 0;
}
