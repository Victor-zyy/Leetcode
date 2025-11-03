#include <vector>
#include <unordered_map>

#define METHOD1 0
#define METHOD2 1
/**
 * The Main Idea is BackTrace
 * 一种通过探索所有可能的候选解来找出所有的解的算法。
 * 如果候选解被确认不是一个解（或者至少不是最后一个解），
 * 回溯算法会通过在上一步进行一些变化抛弃该解，即回溯并且再次尝试。
 */
using namespace std;

#if     METHOD1
/**
 * METHOD1: swap method recursive is the most common way to realize backtrace
 */
class Solution {
public:
    void backtrace( vector<vector<int>>& ans, vector<int>& nums, int first, int len ){
        if( first == len ){
            ans.push_back(nums);
        }
        for(int i = first; i < len; i++ ){
            swap(nums[first], nums[i]);
            backtrace(ans, nums, first + 1, len );
            // swap back
            swap(nums[first],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if( nums.size() == 0 ){
            return {};
        }    
        vector<vector<int>> ans;
        backtrace( ans, nums, 0, nums.size() );
        return ans;
    }
};
#elif   METHOD2

/**
 * METHOD2: use visited array
 */
class Solution {
public:
    void backtrace( vector<vector<int>>& ans, vector<int>& nums, vector<int>& visited, vector<int>& path){
        if( path.size() == nums.size() ){
            ans.push_back(path);
        } 
        for(int i = 0; i < nums.size(); i++ ){
            if( visited[i] ) continue;
            path.push_back(nums[i]);
            visited[i] = 1;
            backtrace(ans, nums, visited, path);
            visited[i] = 0;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if( nums.size() == 0 ){
            return {};
        }    
        vector<int> visited(nums.size());
        vector<vector<int>> ans;
        vector<int> path;
        backtrace(ans, nums, visited, path);
        return ans;
    }
};

#endif