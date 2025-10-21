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

#define METHOD1  0
#define METHOD2  0
#define METHOD3  1

#include <queue>
using namespace std;

#if METHOD1
/**
 * METHOD: breadth-first--only total number of Nodes not depth
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue< TreeNode *> q;
        if( root == nullptr )
            return 0;
        q.push( root );
        while ( !q.empty() )
        {
            depth++;
            TreeNode *pos = q.front();
            q.pop();
            if( pos->left ){
                q.push( pos->left );
            }

            if( pos->right ){
                q.push( pos->right );
            }
        }
        return depth;
    }
};
#elif METHOD2

/**
 * METHOD2: DFS--Depth First Search
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if( root == nullptr ) return 0;
        return max( maxDepth(root->left), maxDepth(root->right)) + 1 ;
    }
};

#elif METHOD3

/**
 * METHOD3: BFS--Breadth First Search
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue< TreeNode * > q;
        if( root == nullptr ) return 0;
        int depth = 0;
        int size = 0;
        q.push( root );
        while( !q.empty() ){
            size = q.size();
            while ( size > 0 )
            {
                TreeNode *pos = q.front();
                q.pop();
                if( pos->left ){
                    q.push( pos->left );
                }

                if( pos->right ){
                    q.push( pos->right );
                }

                --size;
            }
            ++depth;
        }
        return depth;
    }
};
#endif