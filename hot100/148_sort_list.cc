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

#define METHOD1 1
#if METHOD1
/**
 * METHOD1: sort list--O(nlogn) time complexity O(1) space complexity
 * METHOD2: insert-sort list O(n^2) O(1)
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if( head == nullptr || head->next == nullptr )
            return head;
        ListNode *dummy = new ListNode (0, head);
        ListNode *lastsorted = head;
        ListNode *cur = head->next;
        while( cur ){
            if( lastsorted->val <= cur->val )
                lastsorted = lastsorted->next;
            else{
                // Find the ListNode that is greater than the current node form dummy point
                ListNode *phead = dummy;
                while( phead->next->val <= cur->val ){
                    phead = phead->next;
                }
                //lastsorted->next = cur->next;
                //cur->next = lastsorted;
                //phead->next = cur;
                lastsorted->next = cur->next;
                cur->next = phead->next;
                phead->next = cur;
            }
            cur = lastsorted->next;
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#endif

#include <iostream>

using namespace std;

int main(){
    Solution mysolve;

    ListNode n1(4);
    ListNode n2(2);
    ListNode n3(1);
    ListNode n4(3);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    ListNode *ans = mysolve.sortList( &n1 );
    while( ans ){
        cout << ans->val << endl;
    }

    return 0;
}