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

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Method1: two pointers, 
 * but single linked-list need to be copied into array
 */
#ifdef METHOD1
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        if( head == nullptr )
            return false;
        if( head->next == nullptr )
            return true; 
        // 1.copy data to array(vector)
        while( head )
        {
            arr.push_back( head->val );//better way is to emplace_back--avoiding copy and move
            head = head->next;
        }
        // 2.using two pointers
        int i,j;
        for( i = 0, j = arr.size() - 1; i <= j; i++, j-- )
        {
            if( arr[i] == arr[j] )
                continue;
            else
                break;
        }

        if( i < j )
            return false;
        else
            return true;
    }
};
#elif   METHOD2
/**
 * Method2: recrusive to reverse the linked-list
 * in recursive
 * out of recursive
 */
class Solution {
    ListNode *frontNode;
public:
    bool recursiveCheck( ListNode * currentNode )
    {
        if( currentNode != nullptr )
        {
            if( !recursiveCheck( currentNode->next ) )
            {
                return false;
            }
            if( currentNode->val != frontNode->val )
                return false;

            frontNode = frontNode->next;
        } 
        return true;
    }
    bool isPalindrome(ListNode* head) {
        frontNode = head;
        return recursiveCheck(head);
    }
};

#else
/**
 * Method3: 1. get the middle of the linked-list using fast-slow pointer
 *          2. reverse the latter linked-list
 *          3. traverse the linked-list
 *          4. recover the linked-list
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 1. get the middle of the linked-list
        ListNode *fast = head, *slow = head;
        while( fast && fast->next && fast->next->next ){
            fast = fast->next->next;
            slow = slow->next;
        }
        // 2. slow is the middle of the linked-list
        // for odd/even
        ListNode *pA = slow->next;
        ListNode *pB = nullptr;
        ListNode *pC = nullptr;

        while( pA )
        {
            pB = pA->next;
            pA->next = pC;
            pC = pA;
            pA = pB;
        }
        // pC
        ListNode *pD = head;
        ListNode *pE = pC;
        bool isPalind = true;
        while( pE && pD )
        {
            if( pE->val != pD->val )
            {
                isPalind = false;
                break;
            }else{
                pE = pE->next;
                pD = pD->next;
                continue;
            }
        }

        // 3. recover the linked-list
        pA = pC; 
        pB = nullptr;
        pC = nullptr;
        while( pA )
        {
            pB = pA->next;
            pA->next = pC;
            pC = pA;
            pA = pB;
        }
        slow->next = pC;
        return isPalind;
    }
};

#endif