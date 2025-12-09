#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

#define FIRST_TIME 0
#define SECOND_TIME 0
#define REVIEW_THIRD 1
using namespace std;

#if FIRST_TIME
/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
-4 -1 -1 0 1 2 
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end());
      int first = 0;
      for(first = 0; first < nums.size() - 1; first++){
	int target = -nums[first];
	int second = first + 1;
	int third = nums.size() - 1;
	if(first > 0 && nums[first] == nums[first - 1])
	  continue;
	for(; second < nums.size() - 1 ; second++){

	  if ( second > first + 1 && nums[second] == nums[second - 1])
	    continue;

	  // // FIXME: 
	  while(second < third && nums[second] + nums[third] > target)
	    third--;
	  // two pointers termination condition
	  if(second == third)
	    break;

	  if(nums[third] + nums[second] == target)
	    ans.push_back({nums[first], nums[second], nums[third]});
	}
      }
      return ans;
    }
};

#if 0
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

      int n = nums.size();
      sort(nums.begin(), nums.end());
      // sort to decrease the repeated value
      vector<vector<int>> ans;
      for( int first = 0; first < n; first++){

	// FIXME: to avoid duplicates
	if(first > 0 && nums[first] == nums[first - 1])
	  continue;

	int third = n - 1;
	int target = -nums[first]; // twoSum

	for(int second = first + 1; second < n; second++){

	  if ( second > first + 1 && nums[second] == nums[second - 1])
	    continue;

	  while( second < third && nums[second] + nums[third] > target)
	    --third;

	  if(second == third)
	    break;

	  if(nums[second] + nums[third] == target)
	    ans.push_back({nums[first], nums[second], nums[third]});

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

#elif SECOND_TIME

class Solution {
public:
	// -nums[i] = nums[j] + nums[k]
	// to let no duplicate use set
    vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int first = 0;
		vector<vector<int>> ans;

		for (int first = 0; first < nums.size(); first++)
		{
			if ( first > 0 && nums[first] == nums[first - 1] ){
				continue;
			}
			int third = nums.size() - 1;
			int target = -nums[first];
			for (int second = first + 1 ; second < nums.size(); second++)
			{
				if ( second > first + 1 && nums[second] == nums[second - 1] ){
					continue;
				}

				while ( second < third && nums[second] + nums[third] > target )
				{
					--third;
				}

				if ( second == third ) break;

				if ( nums[third] + nums[second] == target ){
					ans.push_back({nums[first], nums[second], nums[third]});
				}
				
			}
			
		}
		return ans;
    }
};

#elif REVIEW_THIRD
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		for (int first = 0; first < n; first++)
		{
			if (first > 0 && nums[first] == nums[first - 1]) continue;

			int target = 0 - nums[first];
			int third = n - 1;
			for (int second = first + 1; second < n; second++)
			{
				if (second > first + 1 && nums[second] == nums[second - 1]) continue;
				
				while (second < third && nums[second] + nums[third] > target )
				{
					--third;
				}
				
				if (third == second) break;

				if (nums[second] + nums[third] == target)
				{
					ans.push_back({nums[first], nums[second], nums[third]});
				}
			}
		}
		return ans;
	}
};

#endif


int main()
{
	Solution mysolve;
	vector<int> nums = {-1,0,1,2,-1,-4};
	mysolve.threeSum(nums);
}