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
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#define METHOD2 1

#ifdef METHOD1
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int tens = 0;
        ListNode *sentinel;
        ListNode **head = &sentinel;
        while ( l1 && l2 )
        {
            *head = new ListNode( 0 );
            sum = l1->val + l2->val + tens; 
            if( sum >= 10 ){
                sum -= 10;
                (*head)->val = sum;
                tens = 1;
            }else{
                (*head)->val = sum;
                tens = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
            head = &(*head)->next;
        }

        ListNode *reserve = l1 == nullptr ? l2 : l1;
        while ( reserve )
        {
            *head = new ListNode( 0 );
            sum = reserve->val + tens;
            if( sum >= 10 ){
                sum -= 10;
                (*head)->val = sum;
                tens = 1;
            }else{
                (*head)->val = sum;
                tens = 0;
            }
            reserve = reserve->next;
            head = &(*head)->next;
        }

        if( tens ){
            *head = new ListNode( 1 );
        } 

        return sentinel;
    }
};

#elif METHOD2

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sentinel = nullptr;
        ListNode **head = &sentinel;
        int tens = 0;
        while ( l1 || l2 )
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            int sum = n1 + n2 + tens;

            if( sum >= 10 ){
                sum -= 10;
                tens = 1;
            }else{
                tens = 0;
            }
            *head = new ListNode ( 0 );
            (*head)->val = sum;
            head = &(*head)->next;
        }

        if( tens ){
            *head = new ListNode ( 1 );
        }
        return sentinel;
    }
};


#endif

int main()
{
    Solution mysolve; 
    ListNode n10(3);
    ListNode n11(7);
    n10.next = &n11;
    
    ListNode n20(9);
    ListNode n21(2);
    n20.next = &n21;
    ListNode *res = nullptr;
    res = mysolve.addTwoNumbers( &n10, &n20 );
    while ( res )
    {
        cout << res->val << " ";
        res = res->next;
    }
    
    return 0;
}