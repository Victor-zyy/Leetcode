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
 * METHOD1: Recursive Method
 */
class Solution {
public:
    bool symCheck( TreeNode *left, TreeNode *right ){
        if( !left && !right ) return true;
        if( !left || !right ) return false;
        return left->val == right->val && symCheck( left->left, right->right ) && symCheck( left->right, right->left );
    }
    bool isSymmetric(TreeNode* root) {
        return symCheck( root->left, root->right ); 
    }
};


#elif METHOD2

/**
 * METHOD2: Interation : using Queue
 */
#include <queue>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if( root == nullptr )
            return true;
        queue<TreeNode *> q;
        q.push( root );
        q.push( root );
        TreeNode *u;
        TreeNode *v;
        while ( !q.empty() )
        {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if( !u && !v ) continue;
            if( ( !u || !v ) || ( u->val != v->val ) ) return false;

            q.push(v->right);
            q.push(u->left);
            
            q.push(u->right);
            q.push(v->left);
        }
        return true; 
    }
};


#endif