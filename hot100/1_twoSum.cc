#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
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

int main(){
  Solution solve;
  vector<int> test {-1,0,1,2,-1,-4};
  cout << test << endl;
  vector<int> ans = solve.twoSum(test, 3);
  for(auto &it : ans)
    cout << it << " ";
  cout << endl;
  return 0;
}
