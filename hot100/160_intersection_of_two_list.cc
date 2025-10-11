/**
 * Given the heads of two singly linked-lists headA and headB, 
 * return the node at which the two lists intersect. 
 * If the two linked lists have no intersection at all, return null.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>

using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#ifdef HASH_METHOD
/**
 * Using HashMap Method (thinking : unordered_set O(m+n) interation)
 * But O(m)/O(n) space
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visited;
        ListNode *temp = headA;
        while( temp )
        {
            visited.insert( temp );
            temp = temp->next;
        }                
        temp = headB;
        while( temp )
        {
            if( visited.count(temp) )
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};
#else
/**
 * Two pointers like
 * headA----<------a
 *          \------(c)
 *          /
 * headB----<------b
 * 
 * headA length = a + c = m
 * headB length = b + c = n
 * Method:
 * 1. pA->headA, pB->headB
 * 2. pA->next is not null then pointing next Node, after that pB does the same thing
 * 3. pA->next is NULL then pA->HeadB
 * 4. pA = pB then return or NULL
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA, *pB;
        pA = headA;
        pB = headB;

        if( pA == nullptr || pB == nullptr )
            return nullptr;
        
        #if 0
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
        #endif
        /**
         * wrong writing pA->next not pA to compare
         * pA->next doesn't compare the null then pointing another node
         */
        while ( pA != pB )
        {
            
            if( pA == nullptr )
                pA = headB;
            else
                pA = pA->next;

            if( pB == nullptr )
                pB = headA;
            else
                pB = pB->next;

        }

        return pA;
    }
};


#endif