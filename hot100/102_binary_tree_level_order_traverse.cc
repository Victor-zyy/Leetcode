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

#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if( root == nullptr )
            return {};
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        q.push( root );
        while ( !q.empty() )
        {
            vector<int> v_int;
            int size = q.size();
            while ( size > 0 )
            {
                TreeNode *next = q.front(); q.pop();
                size--;
                v_int.emplace_back( next->val );
                if( next->left )
                    q.push( next->left );
                if( next->right )
                    q.push( next->right );
            }
            ans.emplace_back(v_int);
        }
        return ans; 
    }
};