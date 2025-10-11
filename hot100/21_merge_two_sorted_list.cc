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
// Both list1 and list2 are sorted in non-decreasing order.
/**
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 */

#define METHOD2 1
#ifdef METHOD1
/**
 *  Method1: iterate method not very elegant
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       if( list1 == nullptr ){
            return list2;
       }
       if( list2 == nullptr ){
            return list1;
       }
       ListNode *pA = list1;
       ListNode *pB = list2;
       ListNode *res = nullptr;
       ListNode *head = nullptr;
       while ( list1 && list2 )
       {
            if( pA->val < pB->val ){
                list1 = list1->next;
                if( res == nullptr ){
                    head = pA;
                    res = pA;
                }else{
                    res->next = pA;
                    res = res->next;
                }
                pA = list1;
            }else{
                list2 = list2->next;
                if( res == nullptr ){
                    head = pB;
                    res = pB;
                }else{
                    res->next = pB;
                    res = res->next;
                }
                pB = list2;
            }
       }

       if( list1 == nullptr ){
            res->next = list2;
       }

       if( list2 == nullptr ){
            res->next = list1;
       }

       return head;

    }
};
#elif METHOD2
/**
 * Method2: recursive method 
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    }
};
#endif