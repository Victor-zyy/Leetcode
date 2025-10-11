/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include <unordered_set>
using namespace std;

/**
 * Method1: fast and slow pointer.---turtle and flow
 * t meet point
 * a-for conjunction point
 * b-for cycle length
 * c-for meet point length with conjunction point
 *  a + n1b + c = t
 * / 
 * \
 *  a + n2b + c = t
 * 
 * c = b(n2 - 2*n1) - a 
 * b - c = a + b ( 2*n1 + 1 - n2) = a + b * N ( N equals integer )
 * which means meet point to conjunction point equals a plus number of cycle length
 */
#ifdef METHOD1
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;       
        bool cycle = false;
        while( fast && fast->next && fast->next->next )
        {
            fast = fast->next->next;
            slow = slow->next;
            if( fast == slow ){
                cycle = true;
                break;
            }
        }
        if( cycle ) 
        {
            fast = head;
            while( fast != slow ){
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
        else{
            return nullptr;
        }
    }
};
#else

/**
 * Method2: HashMap using unordered_set to store the conjunction node
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while( head ){
            if( visited.count(head) )
                return head;
            visited.emplace( head );
            head = head->next;  
        }
        return nullptr;
    }
};

#endif