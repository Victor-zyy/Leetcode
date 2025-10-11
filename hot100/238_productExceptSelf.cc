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
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

*/
// dynamic programming
// time complexity O(n)
// space complexity O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      // left and right multiple set list
      if(nums.size() < 1)
	return {};

      vector<int> ans;
      int n = nums.size();
      vector<int> L(n), R(n);

      //L[0] = nums[0];
      L[0] = 1;
      for(int i = 1; i < n; i++)
	L[i] = nums[i - 1] * L[i - 1];

      //R[n - 1] = nums[n - 1];
      R[n - 1] = 1;
      for(int i = n - 2; i >= 0; i--)
	R[i] = nums[i + 1] * R[i + 1];

      for(int i = 0; i < n; i++)
	ans.push_back(R[i] * L[i]);

      return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      // left and right multiple set list
      if(nums.size() < 1)
	return {};

      vector<int> ans;
      int n = nums.size();

      //L[0] = nums[0];
      ans[0] = 1;
      for(int i = 1; i < n; i++)
	ans[i] = nums[i - 1] * ans[i - 1];

      int R = 1;
      for(int i = n - 1; i >= 0; i--){
	ans[i] = ans[i] * R;
	R *= nums[i];
      }

      return ans;
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
