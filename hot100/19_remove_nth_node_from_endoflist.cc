/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#define  METHOD1 0
#define  METHOD2 0
#define  METHOD3 0
#define  METHOD4 1

#if METHOD1
/**
 * METHOD1: reverse two + n times of linked-list
 * Follow up: do this in one pass!
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. reverse the node
        ListNode *pA = head;
        ListNode *pB = nullptr;
        ListNode *pC = nullptr;
        ListNode *pend = nullptr;
        while( pA ){
            pB = pA->next;
            pA->next = pC;
            pC = pA;
            pA = pB;
        }
        pend = pC;
        // 2. del the nth node iterate

        ListNode *prev = nullptr;
        int i = 1;
        for( i = 1; i < n ; i++ )
        {
            prev = pC;
            pC = pC->next;    
        }
        if( prev ){
            prev->next = pC->next;
        }
        if( i == 1 ){
            pend = pC->next;
        }
        pC->next = nullptr;

        // 3. reverse back the node
        pA = pend;
        pB = nullptr;
        pC = nullptr;
        while ( pA )
        {
            pB = pA->next;
            pA->next = pC;
            pC = pA;
            pA = pB;
        }
        return pC; 
    }
};
#elif METHOD2
/**
 * METHOD2: two pointers like fast slow, fast is ahead of slow to nth nodes
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode( 0, head );
        ListNode *fast = dummy ;
        ListNode *slow = dummy;
        for(int i = 0; i < n; i++ ){
            fast = fast->next;
        }

        while ( fast->next )
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
#elif METHOD3 
/**
 * METHOD3: calculate the length of the linked-list
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode *plist = head;
        ListNode *dummy = new ListNode ( 0, head );
        ListNode *phead = dummy;
        while( plist ){
            length++;
            plist = plist->next;
        }

        for( int i = 0; i < length - n ; i ++ ) 
        {
            phead = phead->next;
        }
        phead->next = phead->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
#elif METHOD4

/**
 * METHOD4: use stack
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode *>stk;
        ListNode *dummy = new ListNode(0, head);
        ListNode *plist = dummy;
        while (plist)
        {
            stk.push(plist);
            plist = plist->next;
        }
        for(int i = 0; i < n; i++ ){
            stk.pop();
        }
        ListNode *prev = stk.top(); 
        prev->next = prev->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#endif