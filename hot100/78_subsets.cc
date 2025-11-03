#include <vector>
using namespace std;

#define     METHOD1     0
#define     METHOD2     1
/**
 * Given an integer array nums of unique elements, return all possible
 * (the power set).
 * The solution set must not contain duplicate subsets. 
 * Return the solution in any order.
 */

#if     METHOD1
/**
 * METHOD1: backtrace -- recursive
 */
class Solution {
private:
    vector<int> temp;
    vector<vector<int>> ans;
public:
    void dfs( int cur, vector<int>& nums ){
        /**
         * Recursive Termination Condition
         */
        if( cur == nums.size() ){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[cur]);
        dfs( cur + 1, nums );
        temp.pop_back();
        dfs( cur + 1, nums );
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        /**
         * 1 element 2 element ---- nums.size() elements
         */
        dfs( 0, nums );
        return ans;
    }
};

#elif   METHOD2

/**
 * [ 1 2 3 ]
 * METHOD2: Iteration Method [0 0 0] -- > []        mask: 0
 *                           [0 0 1] -- > [3]       mask: 1
 *                           [0 1 0] -- > [2]       mask: 2
 *                           [0 1 1] -- > [2 3]
 *                           [1 0 0] -- > [1]
 *      
 */
class Solution {
private:
    vector<int> temp;
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for(int mask = 0; mask < (1 << n); mask ++ ){
            temp.clear();
            for(int i = 0; i < n; i++ ){
                if( mask & ( 1 << i ) ){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
#endif