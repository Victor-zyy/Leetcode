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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;

/**
 * METHOD: recursive build the binary tree, mid-order traverse
 */
class Solution {
private:
    TreeNode *bst( vector<int>&nums, int left, int right ){
        if( nums.size() == 0 )
            return nullptr;
        if( left > right ) return nullptr;
        int mid = ( left + right ) /  2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = bst( nums, left, mid - 1); // do not cover mid
        root->right = bst( nums, mid + 1 , right );
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums, 0, nums.size() - 1); // size - 1
    }
};