#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

#define FIRST_TIME 0
#define SECOND_TIME 1

#if FIRST_TIME
// method 1. hash table [key,value] [key = nums[i], value = index of vector]
// method 2. two pointers nope, the question of return the index of two, but when sorted the vector, index disappear

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> map_;
      // [key,val] ->
      for(int i = 0; i < nums.size(); i++){
	auto it = map_.find(target - nums[i]);
	if(it != map_.end()){
	  return {i, it->second};
	}else{
	  map_[nums[i]] = i;
	}
      }
      return {};
    }
};
#if 0
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int left = 0;
      int right = nums.size() - 1;
      sort(nums.begin(), nums.end()); // FIXME: index disappear
      vector<int> temp = nums; // FIXME: copy value for index
      int flag = 0;
      while(left < right){
	if(nums[left] + nums[right] > target){
	  right--;
	}

	if(nums[left] + nums[right] < target){
	  left++; 
	}

	if(nums[left] + nums[right] == target){
	  flag = 1;
	  break;
	}
      }

      if(flag){
      // find index of value
	int index_left  = 0;
	int index_right  = 0;
	for(int i = 0; i < temp.size(); i++){
	  if(temp[i] == nums[left]){
	    index_left = i;
	    break;
	  }
	}

	for(int i = 0; i < temp.size(); i++){
	  if(temp[i] == nums[right]){
	    index_right = i;
	    break;
	  }
	}

	return { index_left, index_right};
      }
      return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            auto it = map.find(target - nums[i]);
            if(it != map.end()){
                // return {i, it->second};
                return {i, map[target-nums[i]]};
            }else{
                map[nums[i]] = i;
            }
        }
        return {};
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

#elif SECOND_TIME

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> _map;     
      for(int i = 0; i < nums.size(); i++ ){
        _map[nums[i]] = i;
      }
      vector<int> ans;
      for(int i = 0; i < nums.size(); i++ ){
        auto it = _map.find(target - nums[i] );
        if( it != _map.end() && it->second != i ){
          ans.emplace_back(i);
          ans.emplace_back(_map[target - nums[i]]);
          break;
        }
      }
      return ans;
    }
};

// improvement --- we don't construct the hashtable at once, we build it when iterate

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> _map;     
      for(int i = 0; i < nums.size(); i++ ){
        auto it = _map.find(target - nums[i] );
        if( it != _map.end() ){
          return {it->second, i};
        }
        _map[nums[i]] = i;
      }
      return {};
    }
};

#endif

int main(){
}
