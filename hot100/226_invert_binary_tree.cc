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

#define METHOD1 0
#define METHOD2 1

#if METHOD1
/**
 * METHOD1: Breadth First Search---BFS---Not Implemented
 */
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if( root == nullptr )
            return root;
        stack< TreeNode * > stk;
        stk.push(root);
        while( !stk.empty() ){
            TreeNode *next = stk.top();
            stk.pop();
            if( next->right ){
                stk.push( next->right );
            }
            if( next->left ){
                stk.push( next->left );
            }
        }
        
    }
};
#elif METHOD2

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if( root == nullptr )
            return root;
        TreeNode *left = invertTree( root->left );
        TreeNode *right = invertTree( root->right );
        root->left  =  right;
        root->right = left; 
        return root;
    }
};


#endif