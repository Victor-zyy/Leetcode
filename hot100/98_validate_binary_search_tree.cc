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
 * METHOD: left is Binary-Search Tree, right is Binary-Search Tree
 */
class Solution {
private:
    const long inherit_r = __LONG_MAX__;
    const long inherit_l = __LONG_MAX__;
public:
    bool isvalidBSTHelper(TreeNode *root, long inherit_ll, long inherit_rr ){
        if( root == nullptr )
            return true;

        if( root->left && root->left->val >= root->val ){
            return false;
        }
        if( root->left && root->left->val <= inherit_ll )
            return false;

        if( root->right && root->right->val <= root->val ){
            return false;
        }
        if( root->right && root->right->val >= inherit_rr )
            return false;

        bool left_f = isvalidBSTHelper( root->left, inherit_ll, root->val );
        bool left_r = isvalidBSTHelper( root->right, root->val, inherit_rr);
        return left_f && left_r;
    }
    bool isValidBST(TreeNode* root) {
        return isvalidBSTHelper( root, -inherit_l, inherit_r );
    }
};

#include <iostream>
using namespace std;
int main(){

    cout << -__INT_MAX__ << endl;
    Solution mysolve;
    TreeNode n1(3);
    TreeNode n2(1);
    TreeNode n3(5);
    TreeNode n4(0);
    TreeNode n5(2);
    TreeNode n6(4);
    TreeNode n7(6);

    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;
    n2.right = &n5;

    n3.left = &n6;
    n3.right = &n7;

    mysolve.isValidBST(&n1);

}