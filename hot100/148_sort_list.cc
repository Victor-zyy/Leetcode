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

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

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
#elif METHOD2

/**
 * METHOD2: merge sort or quick sort but needs O(1) space complexity
 * Top-down approach and then merge
 * Bottom-up approach and then merge
 */
class Solution {
public:
    ListNode *mergeTwoList( ListNode *list1, ListNode *list2 ){
        if( list1 == nullptr )
            return list2;
        if( list2 == nullptr )
            return list1;
        ListNode *dummy = new ListNode(0);
        // ascending order
        ListNode *head = dummy;
        while ( list1 && list2 )
        {
            if(list1->val < list2->val){
                head->next = list1;
                head = head->next;
                list1 = list1->next;
            }else{
                head->next = list2;
                head = head->next;
                list2 = list2->next;
            }
        }

        head->next = list1 == nullptr ? list2 : list1;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }

    ListNode* sortList(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        // Recursive condition ending
        if( head == nullptr || head->next == nullptr )
            return head;
        // Partition
        while( fast && fast->next && fast->next->next ){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *slow_next = slow->next;
        slow->next = nullptr;
        ListNode *left = sortList( head ); 
        ListNode *right = sortList( slow_next );
        // Then Merge the two sorted-lists
        return mergeTwoList( left, right );
    }
};
#elif METHOD3
/**
 * METHOD3: merge sort or quick sort but needs O(1) space complexity
 * Bottom-up approach and then merge
 * Odd and OVEN
 */
class Solution {
public:
    ListNode *mergeTwoList( ListNode *list1, ListNode *list2 ){
        if( list1 == nullptr )
            return list2;
        if( list2 == nullptr )
            return list1;
        ListNode *dummy = new ListNode(0);
        // ascending order
        ListNode *head = dummy;
        while ( list1 && list2 )
        {
            if(list1->val < list2->val){
                head->next = list1;
                head = head->next;
                list1 = list1->next;
            }else{
                head->next = list2;
                head = head->next;
                list2 = list2->next;
            }
        }

        head->next = list1 == nullptr ? list2 : list1;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }

    ListNode* sortList(ListNode* head) {
        if( head == nullptr || head->next == nullptr )
            return head;
        int length = 0;
        ListNode *node = head;
        // Get ListNode Length
        while ( node )
        {
            length++;
            node = node->next;
        }
        ListNode *dummy = new ListNode(0, head);
        int sublength = 0;
        for( sublength = 1; sublength < length; sublength <<= 1 ){
           ListNode *prev = dummy;
           ListNode *cur = dummy->next;
           while ( cur )
           {
                ListNode *head1 = cur;
                for( int i = 1 ; i < sublength && cur->next ; i++ ){
                    cur = cur->next; 
                }
                ListNode *temp = cur->next;
                cur->next = nullptr;
                cur = temp;
                ListNode *head2 = cur;
                for( int i = 1 ; i < sublength && cur ; i++ ){
                    cur = cur->next; 
                }
                temp = nullptr;
                if( cur != nullptr ){
                    temp = cur->next;
                    cur->next = nullptr;
                }
                ListNode *merge = mergeTwoList( head1, head2 );
                prev->next = merge;
                while ( prev->next )
                {
                    prev = prev->next;
                }
                cur = temp;
           }
           
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
    ListNode n5(0);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode *ans = mysolve.sortList( &n1 );
    while( ans ){
        cout << ans->val << endl;
        ans = ans->next;
    }

    return 0;
}