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

#define METHOD5 1
#define METHOD4 0
#define METHOD3 0
#define METHOD2 0
//#define METHOD1 0

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
        if( list1 == nullptr ){
            return list2;
        }
        if( list2 == nullptr ){
            return list1;
        }
        
        if( list1->val < list2->val ){
            list1->next = mergeTwoLists( list1->next, list2 );
            return list1;
        }else{
            list2->next = mergeTwoLists( list1, list2->next );
            return list2;
        }
    }
};
#elif METHOD3

/**
 * METHOD3 : sentinel Node to let the return more elegant
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * sentinel = new ListNode( -1 );
        ListNode *prev = sentinel;
        while ( list1 && list2 )
        {
            if( list1->val < list2->val ){
                prev->next = list1;
                list1 = list1->next;
            }else{
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        prev->next = list1 == nullptr ? list2 : list1;
        return sentinel->next;
        
    }
};

#elif METHOD4
/**
 * METHOD4: indirect pointer -- get rid of new/malloc memory
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //ListNode * sentinel = new ListNode( -1 ); // get rid of this malloc
        ListNode * sentinel; // get rid of this malloc
        ListNode **pprev = &sentinel;
        while ( list1 && list2 )
        {
            if( list1->val < list2->val ){
                *pprev = list1;
                list1 = list1->next;
            }else{
                *pprev = list2;
                list2 = list2->next;
            }
            pprev = &(*pprev)->next;
        }
        *pprev = list1 == nullptr ? list2 : list1;
        return sentinel; 
    }
};
#elif METHOD5 
/**
 * METHOD5: change if-else branch prediction using indirect pointer
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //ListNode * sentinel = new ListNode( -1 ); // get rid of this malloc
        ListNode * sentinel; // get rid of this malloc
        ListNode **pprev = &sentinel;
        ListNode **node = nullptr;
        for( node = nullptr; list1 && list2; *node = (*node)->next ){
            node = (list1->val < list2->val) ? &list1 : &list2;
            *pprev = *node;
            pprev = &(*pprev)->next;
        }
        *pprev = (struct ListNode *)(( __UINTPTR_TYPE__)list1 | (__UINTPTR_TYPE__)list2);
        return sentinel;
    }
};
#endif