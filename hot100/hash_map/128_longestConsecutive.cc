#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;


#define FIRST_TIME 0
#define SECOND_TIME 1

#if FIRST_TIME

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

#elif SECOND_TIME

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int longest = 1;    
      int n = nums.size();
      if( n == 0 )  return 0;

      unordered_set<int> _set;
      for(const auto &num : nums){
        _set.emplace(num);
      }
      unordered_map<int, int> _map;
      sort(nums.begin(), nums.end());
      for(int i = 0; i < n; i++ ){
        if( _set.count(nums[i] - 1) ){
          _map[nums[i]] = _map[nums[i] - 1] + 1;
          if( _map[nums[i]] > longest ){
            longest = _map[nums[i]];
          }
        }else{
          _map[nums[i]] = 1;
        }
      }
      return longest;
    }
};

// improvement

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
};

#endif

int main(){
  return 0;
}
