#include <vector>
#include <iostream>
using namespace std;

/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]
*/

// time comuspution is big
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      if(nums.size() <= 1)
	return;

      int left=0, right;
      while(left < nums.size() - 1){
	if(nums[left] == 0){
	  right = left + 1;
	  while(nums[right] == 0){
	    right++;
	    if(right == nums.size()){
	      right--;
	      break;
	    }
	  }
	  // swap
	  swap(nums[left], nums[right]);
	}
	left++;
      }
    }
};

















#if 0
// left points to the zero number
// right points to the non-zero number
// two pointers starts from the same address
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
	  // we don't find the values that equals to zero
	  // we do find the value that is bigger than zero
	  // O(n)
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        if(nums.size() == 1)
            return; // corner case
        while(left < right){
	  if(!nums[left]){// find one

            int index = left + 1;

	    // in case of final one
	    if(index == right)
	      return;

	    // maybe all left behind is zero
	    while(nums[index] == 0){
	      index++;
	      if(index == right)
		return;
	    }
	    // switch value
	    int temp = nums[left];
	    nums[left] = nums[index];
	    nums[index] = temp; 
	  }
	  left++;
        }
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
  //vector<int> test{ 2, 3, 0, 8, 9};
  vector<int> test{ 0, 1, 0, 3, 12};
  cout << test << endl;
  solve.moveZeroes(test);
  cout << test << endl;
  return 0;
}
