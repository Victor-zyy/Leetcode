/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * LCA means lowest common ancestor of a binary tree
 * Height: edges
 * Depth: nodes
 * Ancestor: all nodes from root to the current node
 */
#define METHOD1 0
#define METHOD2 1
#include <unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#if METHOD1
/**
 * METHOD1: DFS -- Depth First Search
 */
class Solution {
private:
    TreeNode *ans;
public:
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q){
        if( root == nullptr )
            return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q); 
        if((lson && rson ) || ((root->val == p->val) || (root->val == q->val) && (lson || rson))){
            ans = root;
        }
        return  lson || rson || root->val == p->val || root->val == q->val; // condition by return
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
#elif METHOD2

/**
 * METHOD2: Using HashMap
 */

class Solution {
private:
    unordered_map<int, TreeNode*>fs;
    unordered_map<int, bool>vis;
public:
    void dfs(TreeNode *root){
        if( root == nullptr )
            return;
        if(root->left)
        {
            fs[root->left->val] = root;
            dfs(root->left);
        }

        if (root->right)
        {
            fs[root->right->val] = root;
            dfs(root->right);
        }
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root == nullptr )
            return nullptr;
        fs[root->val] = nullptr;
        dfs(root);
        while (p)
        {
            vis[p->val] = true;
            p = fs[p->val];
        }

        while (q)
        {
            if(vis[q->val]) return q;
            q = fs[q->val];
        }
        return nullptr; 
    }
};


#endif