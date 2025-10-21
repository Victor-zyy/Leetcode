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
using namespace std;

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
#define METHOD3 1

#if METHOD1
/**
 * Inorder Traverse Method: left middle right
 */
class Solution {
private:
    vector<int> ans;
public:
    void inorder( TreeNode *root ){
        if( root != nullptr ){
            inorder( root->left );
            ans.emplace_back( root->val );
            inorder( root->right );
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder( root );
        return this->ans;
    }
};

#elif METHOD2

#include <stack>
/**
 * METHOD2: Stack Traverse and Color Tagged
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        const int white = 0;
        const int gray = 1;
        stack<pair< int, TreeNode *>> stk;
        stk.push({white, root});

        while ( !stk.empty() )
        {
            auto it = stk.top();
            stk.pop();

            if( !it.second ) continue; // important

            if( it.first == white ){
                stk.push({white, (it.second)->right});
                stk.push({gray, it.second});
                stk.push({white, (it.second)->left});
            }else{
                ans.emplace_back((it.second)->val);
            }
        }

        return ans; 
    }
};

#elif METHOD3

/**
 * METHOD3: 
 */

#endif