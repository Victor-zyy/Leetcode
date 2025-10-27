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
using namespace std;

#define METHOD1 0
#define METHOD2 0
#define METHOD3 0
#define METHOD4 0
#define METHOD5 1
    
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
 * METHOD1: preorder traversal--O(n) space complexity
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        if( root == nullptr ){
            return;
        }    
        vector<TreeNode *> save_node;
        preorder_traversal(root, save_node);
        if( save_node.size() ){

            for(int i = 0; i < save_node.size() - 1; i++ ){
                save_node[i]->right = save_node[i + 1];
                save_node[i]->left = nullptr; 
            }
            save_node[save_node.size() - 1]->right = nullptr;
            save_node[save_node.size() - 1]->left = nullptr;

        }
    }
    void preorder_traversal(TreeNode *root, vector<TreeNode*>& save){
        if( root == nullptr )
            return;
        save.emplace_back( root );
        preorder_traversal(root->left, save);
        preorder_traversal(root->right, save);
    }
};

#elif METHOD2 

/**
 * METHOD2: use stack to stimulate the Preorder Traverse
 */
class Solution {
private:
    const int white = 0;
    const int gray = 1;
public:
    void flatten(TreeNode* root) {
        if( root == nullptr ){
            return;
        }    
        stack<pair<int, TreeNode*>> stk;
        stk.push({white, root});
        vector<TreeNode*> save;
        while (!stk.empty())
        {
            auto it = stk.top(); stk.pop();
            if(!it.second) continue;
            if( it.first == white ){
                stk.push({white, it.second->right});
                stk.push({white, it.second->left});
                stk.push({gray, it.second});
            }else{
                save.emplace_back(it.second);
            }
        }

        if( save.size() ){
            for(int i = 0; i < save.size() - 1; i++ ){
                save[i]->right = save[i + 1];
                save[i]->left = nullptr; 
            }
            save[save.size() - 1]->right = nullptr;
            save[save.size() - 1]->left = nullptr;
        }

    }
};


#elif METHOD3

/**
 * METHOD3: Preorder traversal and Linked list altogether
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if( root == nullptr ){
            return;
        }    

        stack<TreeNode *>stk;
        TreeNode *prev = nullptr;
        stk.push( root );

        while (!stk.empty())
        {
            TreeNode *next = stk.top(); stk.pop();

            if( prev ){
                prev->left = nullptr;
                prev->right = next;
            } 

            TreeNode *left = next->left; 
            TreeNode *right = next->right; 

            if(right){
                stk.push(right);
            }

            if( left ){
                stk.push(left);
            }

            prev = next;
        }
        
    }
};

#elif METHOD4
class Solution {
public:
    void flatten(TreeNode* root) {
        auto v = vector<TreeNode*>();
        auto stk = stack<TreeNode*>();
        TreeNode *node = root;
        while (node != nullptr || !stk.empty()) {
            while (node != nullptr) {
                v.push_back(node);
                stk.push(node);
                node = node->left;
            }
            node = stk.top(); stk.pop();
            node = node->right;
        }
        int size = v.size();
        for (int i = 1; i < size; i++) {
            auto prev = v.at(i - 1), curr = v.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }
};

#elif METHOD5
// predecessor--midorder the previous node

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        TreeNode *curr = root;
        TreeNode *predecesor = nullptr;
        while (curr)
        {
            if(curr->left){
                predecesor = curr->left;
                TreeNode *next = curr->left; // need to be considered
                while (predecesor->right)
                {
                    predecesor = predecesor->right;
                }
                predecesor->right = curr->right;
                curr->left = nullptr;
                curr->right = next; 
            }
            curr = curr->right;
        }
    }
};
#endif