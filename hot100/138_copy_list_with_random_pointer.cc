/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

#define METHOD1 0
#define METHOD2 1
#if METHOD1
/**
 * METHOD1: Hash Map and recursive
 * Hashmap: mainly means orignal node and the new node mapping
 */
class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;
    Node* copyRandomList(Node* head) {
        if( head == nullptr )
            return nullptr;
        if( !cachedNode.count(head) ){

            Node *newhead = new Node( head->val ); 
            cachedNode[head] = newhead;
            newhead->next = copyRandomList( head->next );
            newhead->random = copyRandomList( head->random );
        }

        return cachedNode[head];
    }
};
#elif METHOD2

/**
 * METHOD2: iterate and spill apart nodes
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        for( Node *n = head; n != nullptr; n = n->next->next ){
            Node *tail = n->next;
            Node *newhead = new Node(n->val);
            n->next = newhead;
            newhead->next = tail;
        } 

        for( Node *n = head; n != nullptr; n = n->next->next ){
            Node *newhead = n->next;
            newhead->random = n->random != nullptr ? n->random->next : nullptr;
        }

        // break apart
        Node *dummy = new Node (0);
        Node *phead = dummy;
        for( Node *n = head; n ; n = n->next ){
            Node *newhead = n->next; 
            if( newhead->next != nullptr ){
                n->next = newhead->next;
            }else{
                n->next = nullptr;
            }
            phead->next = newhead;
            phead = phead->next;
        }
        Node *ans = dummy->next; 
        delete dummy;
        return ans;
    }
};

#endif

#include <iostream>

int main(){
    Solution mysolve;
    Node node1(7);
    Node node2(10);
    Node node3(3);

    node1.next = &node2;
    node2.next = &node3;

    node1.random = &node3;
    node2.random = &node1;

    Node *ans = mysolve.copyRandomList( &node1 );
    while( ans ){
        cout << ans->val << endl;
        ans = ans->next;
    }

}