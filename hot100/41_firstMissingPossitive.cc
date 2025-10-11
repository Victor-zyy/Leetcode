#include <vector>
#include <climits>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
ostream&
operator << (ostream &os, const vector<int>& v);

/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      int num = 1;
      for(int i = 0; i < n; i++){
	if(nums[i] <= 0)
	  continue;
	if(nums[i] == num){
	  num++;
	  continue;
	}else if (nums[i] > num){
	  break;
	}
      }
      return num;
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
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

int main(){
  Solution solve;
  vector<int> v1 = {-2,1,-3,4,-1,2,1,-5,4};
  int k = 3;
  cout << v1 << " rotate k =  : " << k << " ";
  solve.rotate(v1, k);
  cout << v1 << endl;
  return 0;
}
