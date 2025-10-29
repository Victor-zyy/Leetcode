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

#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int maxSum;
public:
    int maxGain(TreeNode *root){
        if( root == nullptr )
            return 0;
        int left = max(maxGain(root->left), 0); 
        int right = max(maxGain(root->right), 0); 

        maxSum = maxSum < left + right + root->val ? left + right + root->val : maxSum;

        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        // maxGain and price_Newpath
        maxSum = -__INT_MAX__;
        maxGain(root);
        return maxSum;
    }
};