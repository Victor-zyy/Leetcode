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
#include <vector>
using namespace std;

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
 * METHOD1: merge-sort / partition and conquer
 * Ascending Order--TopDown
 */
class Solution {
public:
    ListNode *sortTwoList( ListNode *list1, ListNode *list2 ){
        ListNode *dummy = new ListNode( 0 );
        ListNode *head = dummy;
        while ( list1 && list2 )
        {
            if( list1->val < list2->val )
            {
                head->next = list1;
                list1 = list1->next;
            }else{
                head->next = list2; 
                list2 = list2->next;
            }
            head = head->next;
        }

        head->next = list1 == nullptr ? list2 : list1;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    } 
    ListNode *merge( vector<ListNode *>& lists, int l, int r ){
        /**
         * End Contions 
         */
        if( l == r )
            return lists[l];
        if( l > r )
            return nullptr;
        int mid = ( l + r ) >> 1; 
        ListNode *left = merge( lists, l, mid );
        ListNode *right = merge( lists, mid + 1 , r );
        return sortTwoList( left, right );
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /**
         * 1. Divide - how to divide
         */
        return merge( lists, 0, lists.size() - 1 );
    }
};
#elif METHOD2
/**
 * METHOD2: 1-1 = 2 1-2 = 3 1-3 = 4 1-4 = 5
 * Ascending Order--TopDown
 */
class Solution {
public:
    ListNode *sortTwoList( ListNode *list1, ListNode *list2 ){
        ListNode *dummy = new ListNode( 0 );
        ListNode *head = dummy;
        // wudao: * ->next ** -> assign
        while ( list1 && list2 )
        {
            if( list1->val < list2->val )
            {
                head->next = list1;
                list1 = list1->next;
            }else{
                head->next = list2; 
                list2 = list2->next;
            }
            head = head->next;
        }
        head->next = ( list1 == nullptr ) ? list2 : list1;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    } 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode *ans = nullptr;
        for( int i = 0; i < n; i++ ){
            ans = sortTwoList(ans, lists[i] );
        }
        return ans;
    }
};

#elif METHOD3
#include <queue>

/**
 * METHOD3: Priority_queue
 */
class Solution {
public:
    struct status
    {
        int val;
        ListNode *ptr;
        bool operator<(const status &rhs) const{
            return val > rhs.val;
        }
    };
    
    priority_queue<status> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for( auto node: lists ){
            if( node ){
                q.push( {node->val, node} );
            }
        }

        ListNode *dummy = new ListNode ( 0 );
        ListNode *head = dummy;
        while( !q.empty() ){
            auto tail = q.top();  q.pop();
            head->next = tail.ptr;
            head = head->next; 
            if(tail.ptr->next){
                q.push({tail.ptr->next->val, tail.ptr->next});
            }
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
#else

#endif


int main()
{
    Solution mysolve;
    ListNode n11(1);
    ListNode n12(4);
    ListNode n13(5);
    n11.next = &n12;
    n12.next = &n13;

    ListNode n21(1);
    ListNode n22(3);
    ListNode n23(4);
    n21.next = &n22;
    n22.next = &n23;

    ListNode n31(2);
    ListNode n32(6);
    n31.next = &n32;

    vector<ListNode *> sortlist;
    sortlist.emplace_back(&n11);
    sortlist.emplace_back(&n21);
    sortlist.emplace_back(&n31);

    ListNode *ans = mysolve.mergeKLists(sortlist);

    while ( ans )
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
    

}