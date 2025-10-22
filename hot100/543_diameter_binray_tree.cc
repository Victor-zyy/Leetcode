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

/**
 * METHOD1: Depth First Search
 */
#include <math.h>
using namespace std;

class Solution {
private:
    int ans;
    int diameter( TreeNode *root ){
        if( root == nullptr )
            return 0;
        int l = diameter(root->left);
        int r = diameter(root->right);
        ans = max( l + r + 1, ans );
        return max( l, r ) + 1;  //depth
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        diameter( root );
        return ans - 1;
    }
};