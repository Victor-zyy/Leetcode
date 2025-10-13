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

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#if METHOD1
/**
 * METHOD1: fast and slow and recursive swap nodes not value
 */
class Solution {
public:
    void swap( int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode ( 0, head);
        ListNode *dummy2 = new ListNode ( 0, dummy);
        ListNode *fast = dummy;
        ListNode *slow = dummy2;
        
        while (slow && fast && slow->next && fast->next && slow->next->next && fast->next->next )
        {
            fast = fast->next->next;
            slow = slow->next->next;
            swap( &slow->val, &fast->val ); 
        }
        ListNode *ans = dummy->next;
        delete dummy2;
        delete dummy;
        return ans;

    }
};
#elif METHOD2
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode( 0, head );
        ListNode *plist = dummy;
        while( plist && plist->next && plist->next->next ){
            ListNode *prev = plist->next;
            ListNode *tail = prev->next;
            plist->next = tail;
            prev->next = tail->next;
            tail->next = prev;
            plist = plist->next->next;
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#elif METHOD3
/**
 * METHOD3: recursive
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if( head == nullptr || head->next == nullptr ){
            return head;
        }

        ListNode *newHead = head->next;
        head->next = swapPairs( newHead->next );
        newHead->next = head;
        return newHead;
    }
};


#endif