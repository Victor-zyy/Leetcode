/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>
#include <unordered_map>
using namespace std;

#define METHOD1 0
#define METHOD2 1

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#if METHOD1
/**
 * METHOD1: DFS -- Depth First Search
 */
class Solution {
public:
    int rootSum(TreeNode *root, long long targetSum){
        if(!root)
            return 0;
        int ret = 0;
        if(root->val == targetSum)
            ret++;
        ret += rootSum(root->left, targetSum-root->val);
        ret += rootSum(root->right, targetSum-root->val);
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if( !root )
            return 0;
        int ret = rootSum( root, targetSum ); 
        ret += pathSum(root->left, targetSum); // more important
        ret += pathSum(root->right, targetSum);
        return ret;
    }
};
#elif METHOD2

/**
 * METHOD2: Prefix Sum
 */

class Solution {
private:
    unordered_map<long long, int> map;
    /**
     * curr: from root -> current node sum of paths
     * map documents root -> all nodes sum of paths
     * if targetSum = 8
     * 10 5 3
     * [0:1 10:1]
     * [0:1 10:1 15:1]
     * [0:1 10:1 15:1] -->8 = 18 - 8-->10 node->current node meets targetSum
     */
public:
    int dfs(TreeNode *root, long long curr, int targetSum){
        if( !root )
            return 0;
        curr += root->val;
        int ret = 0;
        //if( map[curr - targetSum] ){
        if( map.count(curr - targetSum)){ // both are right
            ret = map[curr - targetSum];
        }
        /**
         *  Why curr - targetSum ?
         */
        map[curr]++;
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        map[curr]--; // left sub tree prefix sum can't interference the right sub tree 
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        map[0] = 1; // 
        return dfs(root, 0, targetSum);
    }
};
#endif