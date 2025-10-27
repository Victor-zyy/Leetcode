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
#include <queue>

#define METHOD1 0
#define METHOD2 1
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
 * METHOD1: BFS--Breadth First Search -- queue
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if( root == nullptr ){
            return {};
        }        
        vector<int> ans;
        queue<TreeNode *>q;
        q.push( root );
        while (!q.empty())
        {
            size_t sz = q.size();
            TreeNode *next = nullptr;
            while ( sz )
            {
                next = q.front(); q.pop();
                if (next->left)
                {
                    q.push(next->left); 
                }

                if (next->right)
                {
                    q.push(next->right); 
                }
                sz --;
            }
            if( next ){
                ans.emplace_back( next->val );
            }
            
        }
        return ans;
    }
};
#elif METHOD2

/**
 * MTHOD2: DFS--depth first search --- stack
 */
class Solution {
public:
    void dfs(TreeNode *node, int depth, vector<int>& ans ){
        if( node == nullptr )
            return;
        if( depth == ans.size() ){
            ans.emplace_back( node->val );
        }

        dfs( node->right, depth + 1, ans );
        dfs( node->left, depth + 1, ans );
    }
    vector<int> rightSideView(TreeNode* root) {
        if( root == nullptr ){
            return {};
        }
        vector<int> ans;
        dfs(root, 0, ans );
        return ans;
    }
};


#endif