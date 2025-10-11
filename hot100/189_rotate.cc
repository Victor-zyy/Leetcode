#include <vector>
#include <climits>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <numeric>
/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

using namespace std;
ostream&
operator << (ostream &os, const vector<int>& v);


#if 0
// time complexity O(n) 
// space complexity O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> ans(n);
      for(int i = 0; i < nums.size(); i++){
	ans[(i + k) % n] = nums[i];
      }
      //nums = ans;
      //use assign method to make it more efficiently
      nums.assign(ans.begin(), ans.end());
    }
};
#endif

class Solution {
public:
  //double pointer reverse
  void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
      swap(nums[start], nums[end]);
      start += 1;
      end -= 1;
    }
  }

  void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
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
