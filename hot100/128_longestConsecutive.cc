#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;
/*
Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:

Input: nums = [1,0,1,2]
Output: 3
*/
#if 0
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> set_;
        for(auto &num : nums){
            set_.insert(num);
        }
        int cnt = 0;
        for(auto& num: set_){
            if(!set_.count(num - 1)){
                int current_num = num;
                int long_stk = 1;
                while(set_.count(current_num + 1)){
                    long_stk ++;
                    current_num++;
                }
                cnt = max(cnt, long_stk);
            }
        }
        return cnt;
    }
};
#endif
// exceed time limit
// find usage
// use count
// set is a tool to remove duplicates
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      // using set is kind of hash
      unordered_set<int> set_;
      //
      if(nums.size() == 0)
	return 0; 
      int max_len = 1;
      sort(nums.begin(), nums.end());
      for(auto& num_ : nums){
	set_.emplace(num_);
      }

      // 4 
      for(auto &val : set_){
	if(!set_.count(val - 1)){
	  int index = 1;
	  while(set_.count(val + index))
	    index++;
	  if(index > max_len){
	    max_len = index;
	  }
	}
      }
      return max_len;
    }
};

ostream&
operator << (ostream &os, const vector<int>& v)
{
  os << "{ ";
  for(auto it : v)
    os << it << ' ';
  return os << "} ";
}

ostream&
operator << (ostream &os, const vector<string>& v)
{
  os << "{ ";
  for(auto it : v)
    os << it << ' ';
  return os << "} ";
}
int main(){
  Solution solve;
  vector<int> test {0,3,7,2,5,8,4,6,0,1};
  cout << test << endl;
  int ans = solve.longestConsecutive(test);
  cout << ans << endl;
  // test case
  unordered_set<int> set_;
  set_.emplace(4);
  set_.emplace(8);
  set_.emplace(9);
  set_.emplace(1);
  set_.emplace(1);
  set_.emplace(1);
  set_.emplace(1);
  set_.emplace(1);
  set_.emplace(5);
  for(auto &val : set_)
    cout << "set_ : " << val << endl;
  cout << set_.count(1) << endl;
  cout << set_.count(5) << endl;
  return 0;
}
