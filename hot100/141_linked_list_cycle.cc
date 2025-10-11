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

#define METHOD2 1
#include <unordered_set>
using namespace std;

/**
 * Method1: fast and slow pointers O(1) space complexity
 */
#ifdef METHOD1
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while( fast && fast->next && fast->next->next )
        {
            fast = fast->next->next;
            slow = slow->next;
            if( fast == slow )
                return true;
        }
        return false;
    }
};
#elif METHOD2
/**
 * Method2: hash to store the ListNode*, O(N) space complexity
 */
class solution
{
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while( head )
        {
            if( visited.count( head ) )
            {
                return true;
            }
            visited.emplace( head );
            head = head->next;
        }
        return false;
    }
};

#endif