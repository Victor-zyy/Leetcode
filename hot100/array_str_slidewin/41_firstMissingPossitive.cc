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

#if FIRST_TIME
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
#elif SECOND_TIME

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

#if METHOD1

/**
 * METHOD1: sort array does not accomodate the O(n) time complexity
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= 0)
                continue;
            if (nums[i] == num){
                num++;
                continue;
            } else if ( i > 0 && nums[i - 1] == num) {
                continue;
            }
        }
        return num; 
    }
};
#elif METHOD2

/**
 * METHOD2: use tagged method
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (auto &num : nums)
        {
            if ( num <= 0 ) // need to be considered
                num = n + 1;
        } 
        
        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                return i + 1;
        }

        return n + 1;
    }
};

#elif METHOD3

/**
 * METHOD3: Use swap method kind of like sort
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // [4 3 1 -1] --> [1 -1 3 4]
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        
        return n + 1;
    }
};

#endif

#endif
