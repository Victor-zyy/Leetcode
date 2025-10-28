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
#include <stack>
#include <unordered_map>
#define METHOD1     0
#define METHOD2     1
using namespace std;

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
 * METHOD1: preorder--root node
 *          inorder--size of left tree/right tree
 *          Recursive Construct Binary Tree
 */
class Solution {
private:
    unordered_map<int, int> map;
public:
    TreeNode* recurBuildTree(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright){
        if(preleft > preright)
            return nullptr;
        int root_node = preleft;
        int inorder_index = map[preorder[root_node]];
        TreeNode *root = new TreeNode(preorder[root_node]);
        int size_left_tree = inorder_index - inleft;
        root->left = recurBuildTree(preorder, inorder, preleft + 1, preleft + size_left_tree, inleft, inorder_index - 1 );
        root->right = recurBuildTree(preorder, inorder, preleft + size_left_tree + 1, preright, inorder_index + 1, inright);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int sz = preorder.size();
        for(int i = 0; i < sz; i++){
            map[inorder[i]] = i;
        }
        return recurBuildTree(preorder, inorder, 0, sz-1, 0, sz-1);
    }
};
#elif METHOD2
/**
 * METHOD2: Iterate Method
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()){
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        for(int i = 1; i < preorder.size(); i++){
            int preorderVal = preorder[i];
            TreeNode *node = stk.top();
            if(node->val != inorder[inorderIndex]){
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }else{
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex])
                {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};

#endif