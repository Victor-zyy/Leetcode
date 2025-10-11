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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pA = head;
        ListNode *pB = nullptr;
        ListNode *pC = nullptr;
        
        if( pA == nullptr || pA->next == nullptr )
            return head;
        
        while( pA )
        {
            pB = pA->next;
            pA->next = pC;
            pC = pA;
            pA = pB; 
        }
        return pC;
    }
};