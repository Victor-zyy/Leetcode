#include <vector>
#include <climits>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

#define FIRST_TIME 0
#define SECOND_TIME 1

#if FRIST_TIME
/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

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
#elif SECOND_TIME


#define METHOD1 0
#define METHOD2 0
#define METHOD3 1
#define METHOD4 0

#if METHOD1
/**
 * METHOD1: Exceed time limit
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //i + k % nums.size();
        int assign_val = 0;
        for (int i = 0; i < k; i++)
        {
            assign_val = nums[0];
            for (int j = 0; j < nums.size(); j++)
            {
                int temp = nums[(j + 1) % nums.size()];
                nums[(j + 1) % nums.size()] = assign_val;
                assign_val = temp;
            }
        }
    }
};
#elif METHOD2

/**
 * METHOD2: use extra array
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newArray(n);
        for (int i = 0; i < nums.size(); i++)
        {
            newArray[(i + k) % nums.size()] = nums[i];
        }
        nums.assign(newArray.begin(), newArray.end());
    }
};
#elif METHOD3

/**
 * METHOD3: Ring Placement
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        for (int start = 0; start < count; start++)
        {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while ( start != current);
        }
    }
};

#elif METHOD4

/**
 * METHOD4: reverse the array
 */

class Solution {
public:
    void reverse(vector<int>& nums, int left, int right){
        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};

#endif

#endif