#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/

// monotonic stack
class Solution{
public:
    int trap(vector<int>& height) {
      int ans = 0;
      stack<int> stk;
      int n = height.size();
      for(int i = 0 ; i < n; i++){
	while(!stk.empty() && height[i] > height[stk.top()]){
	  int top = stk.top();
	  stk.pop();
	  if(stk.empty())// FIXME: 
	    break;
	  int left = stk.top();
	  int wid = i - left - 1;
	  int high = min(height[left], height[i]) - height[top];
	  ans += wid * high;
	}
	stk.push(i);
      }

      return ans;
    }

};

class Solution {
public:
  // using double pointers
    int trap(vector<int>& height) {
      int left = 0;
      int right = height.size() - 1;
      int left_max = 0;
      int right_max = 0;
      int ans = 0;
      while(left < right){
	if(height[left] < height[right]){
	  // left side
	  if(height[left] > left_max){
	    left_max = height[left];
	  }else{
	    ans += left_max - height[left];
	  }
	  left ++;
	}else{
	  if(height[right] > right_max){
	    right_max = height[right];
	  }else{
	    ans += right_max - height[right];
	  }
	  right --;

	}
      }
      return ans;
    }
};























#if 0
class Solution {
public:
  // using double pointers
    int trap(vector<int>& height) {
      int left = 0;
      int right = height.size() - 1;
      int ans = 0;
      int left_max = 0;
      int right_max = 0;
      while(left < right){
	// only focus left side
	if(height[left] < height[right]){
	  if(height[left] > left_max)
	    left_max = height[left];
	  else
	    ans += left_max - height[left];

	  left++;
	}else{
	// only focus right side
	  if(height[right] > right_max)
	    right_max = height[right];
	  else
	    ans += right_max - height[right];

	  right--;
	}
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
  vector<int> test {-1,0,1,2,-1,-4};
  cout << test << endl;
  vector<vector<int>> ans = solve.threeSum(test);
  for(auto &it : ans)
    cout << it << endl;
  return 0;
}
