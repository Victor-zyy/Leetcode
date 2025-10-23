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

#include <vector>
#include <iostream>
using namespace std;

#define METHOD1 0
#define METHOD2 0
#define METHOD3 0
#define METHOD4 0
#define METHOD5 1


#if METHOD1
/**
 * METHOD1: Mid-Order Traverse
 */
class Solution {
private:
    vector<int> ans;
public:
    TreeNode *midTraverse( TreeNode *root ){
        if( root == nullptr ) return nullptr;
        TreeNode *left = midTraverse( root->left );
        ans.emplace_back( root->val );
        TreeNode *right = midTraverse( root->right );
        return root;
    }
    int kthSmallest(TreeNode* root, int k) {
        midTraverse( root );
        return ans[k - 1];
    }
};
#elif METHOD2

#include <stack>
/**
 * METHOD2: Color-Tagged Traverse
 */
class Solution {
private:
    vector<int> ans;
    const int white = 0;
    const int gray = 1;
public:
    TreeNode *midTraverse( TreeNode *root ){
        if( root == nullptr ) return nullptr;
        stack<pair<int, TreeNode*>> stk;
        stk.push({white, root});
        while (!stk.empty())
        {
            auto pos = stk.top(); stk.pop();
            if( !pos.second ) continue;
            if( pos.first == white ){
                stk.push({white, pos.second->right});
                stk.push({gray, pos.second});
                stk.push({white, pos.second->left});
            }else{
                ans.emplace_back(pos.second->val);
            }
        }
        
        return root;
    }
    int kthSmallest(TreeNode* root, int k) {
        midTraverse( root );
        return ans[k - 1];
    }
};

#elif METHOD3

#include <stack>
/**
 * METHOD3: Use Stack mid-order traverse but not travers all nodes
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if( root == nullptr ) return 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty())
        {
            while ( root )
            {
                stk.push(root);
                root = root->left;
            }

            root = stk.top(); stk.pop(); 
            --k;
            if( k == 0 ) return root->val;

            root = root->right;
        }
        
        return 0;
    }
};
#elif METHOD4

/**
 * METHOD4: doc the node number of each node
 */
#include <unordered_map>

class bst{
private:
    TreeNode *root;
    unordered_map<TreeNode *, int> nodeNum;
    int coutNodeNum(TreeNode *node ){
        if( node == nullptr )
            return 0;
        nodeNum[node] = 1 + coutNodeNum(node->left) + coutNodeNum(node->right);
        return nodeNum[node];
    }
    int getNodeNum( TreeNode *node ){
        if( node != nullptr && nodeNum.count(node) )
            return nodeNum[node];
        else
            return 0;
    }
public:
    int kthSmallest( int k ){
        TreeNode *node = this->root;
        while ( node )
        {
            int num = getNodeNum( node->left ); 
            if( num == k - 1 ){
                return node->val;
            }else if( num < k - 1 ){
                // right
                node = node->right;
                k -= num + 1; // k = k - num - 1
            }else{
                // left
                node = node->left;
            }
        }
        return node->val;
    }
public:
    bst( TreeNode *root ){
        this->root = root;
        coutNodeNum(root);
    }

};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        bst Bst(root);
        return Bst.kthSmallest(k);
    }
};

#elif METHOD5
/**
 * METHOD5: Build AVL 
 */

struct Node
{
    int val;
    Node *parent;
    Node *left;
    Node *right;
    int size;
    int height;

    Node(int val){
        this->val = val;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        this->size = 1;
        this->height = 0;
    }

    Node(int val, Node *parent){
        this->val = val;
        this->parent = parent;
        this->left = nullptr;
        this->right = nullptr;
        this->size = 1;
        this->height = 0;
    }

    Node(int val, Node *parent, Node *left, Node *right){
        this->val = val;
        this->parent = parent;
        this->left = left;
        this->right = right;
        this->size = 1;
        this->height = 0;
    }
};

class AVL{

private:
    Node *root;
    static int getHeight( Node *node ){
        return node != nullptr ? node->height : 0;
    }
    static int getSize(Node *node ){
        return node != nullptr ? node->size : 0;
    }
    static Node *subtreeFirst( Node *node ){
        while (node->left)
        {
            node = node->left;
        }
        return node; 
    }
    static Node *subtreeLast( Node *node ){
        while (node->right)
        {
            node = node->right;
        }
        return node; 
    }
    void recompute( Node *node ){
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        node->size = 1 + getSize(node->left) + getSize(node->right);
    }
    Node *subtreeSearch( Node *node, int v ){
        if( node->val < v && node->right != nullptr )
        {
            return subtreeSearch( node->right, v );
        }else if( node->val > v && node->left ){
            return subtreeSearch( node->left, v );
        }else{
            return node;
        }
    }
    static void relink(Node *parent, Node *child, bool isLeft){
        if( isLeft ){
            parent->left = child;
        }else{
            parent->right = child;
        }
        if( child != nullptr ){
            child->parent = parent;
        }
    }
    Node *tailChild(Node *node ){
        if( getHeight(node->left) > getHeight(node->right) ){
            return node->left;
        }else{
            return node->right;
        }
    }
    Node *tailGrandchild(Node *node ){
        Node *child = tailChild(node);
        return tailChild(child);
    }
    void rotate(Node *node){
        Node *parent = node->parent;
        Node *grandparent = parent->parent;
        if( grandparent == nullptr ){
            this->root = node;
            node->parent = nullptr;
        }else{
            relink(grandparent, node, parent == grandparent->left );
        }

        if( node == parent->left ){
            relink( parent, node->left, true );
            relink( node, parent, false );
        }else{
            relink( parent, node->left, false );
            relink( node, parent, true );
        }
    }
    /**
     * trinode
     */
    Node *restructure(Node *node){
        Node *parent = node->parent;
        Node *grandparent = parent->parent;
        if( (node == parent->right) == (parent == grandparent->right)){
            rotate(parent);
            return parent;
        }else{
            rotate(node);
            rotate(node);
            return node;
        }
    }
    bool isBalanced(Node *node){
        return abs(getHeight(node->left) - getHeight(node->right)) <= 1;
    }
    void rebalance( Node *node ){
        while (node)
        {
            int oldheight = node->height, oldsize = node->size;
            if( !isBalanced(node) ){
                node = restructure(tailGrandchild(node));
                recompute(node->left);
                recompute(node->right);
            }
            recompute(node);
            if(node->height == oldheight && node->size == oldsize )
                node = nullptr;
            else
                node = node->parent;
        }
    }
    void Delete( Node *node ){
        if( node->left && node->right )
            return;
        Node *child = node->left ? node->left : node->right;
        if( child ){
            child->parent = node->parent;
        }
        if( node == root ){
            root = child;
        }else{
            Node *parent = node->parent;
            if(node == parent->left ){
                parent->left = child;
            }else{
                parent->right = child;
            }
        }
        node->parent = node;
    }
public:
    AVL(vector<int>& vals){
        if( !vals.empty() ){
            root = build(vals, 0, vals.size() - 1, nullptr);
        }
    }

    Node * build(vector<int> &vals, int l, int r, Node *parent){
        int m = (l + r) >> 1;
        Node * node = new Node(vals[m], parent);
        if( l <= m - 1 ){
            node->left = build( vals, l, m - 1, node );
        }
        if( m + 1 <= r ){
            node->right = build( vals, m + 1, r, node );
        }

        recompute( node );

        return node;
    }

    int kthSmallest(int k ){
        Node *node = this->root;
        while( node ){
            int size = getSize(node->left);
            if( size == k - 1){
                break;
            }else if( size < k - 1){
                k -= size + 1;
                node = node->right;
            }else{
                node = node->left;
            }
        }
        return node->val;
    }

    /**
     * AVL--Insert
     */
    void insert(int v){
        if( this->root == nullptr ){
            this->root = new Node(v);
        }
        else{
            /**
             * Calculate the position of the node which is gonna be inserted
             */
            Node *node = subtreeSearch(this->root, v);
            bool isAddLeft = v <= node->val;
            if( node->val == v ){ // already exists
                if( node->left ){
                    node = subtreeLast(node->left);
                    isAddLeft = false;
                }else{
                    isAddLeft = true;
                }
            }

            Node *leaf = new Node(v, node);
            if( isAddLeft ){
                node->left = leaf;
            }else{
                node->right = leaf;
            }

            rebalance( leaf );
        }
        
    }
    bool Delete(int v){
        if( this->root = nullptr ){
            return false;
        }
        Node *node = subtreeSearch(this->root, v);
        if(node->val != v)
            return false;
        if( node->left && node->right ){
            Node *replacement = nullptr;
            if( node->left->height <= node->right->height ){
                replacement = subtreeFirst(node->right);
            }else{
                replacement = subtreeLast(node->left);
            }
            node->val = replacement->val;
            node = replacement;
        }
        Node *parent = node->parent;
        Delete(node);
        rebalance(parent);
        return true;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        /**
         * Vector-mid-order traverse
         */
        vector<int> inorderList;
        inorder(root, inorderList);
        /**
         * AVL build an AVL Tree
         */ 
        AVL avl(inorderList);

        return avl.kthSmallest(k);
    }
private:
    void inorder( TreeNode *node, vector<int>& inorderList ){
        if( node->left != nullptr ){
            inorder( node->left, inorderList );
        }
        inorderList.emplace_back( node->val );
        if( node->right != nullptr ){
            inorder( node->right, inorderList );
        }
    }
};
#endif


int main(){

    TreeNode n1(3);
    TreeNode n2(1);
    TreeNode n3(4);
    TreeNode n4(2);

    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    Solution mysolve;
    cout << mysolve.kthSmallest( &n1, 1 ) << endl;
}