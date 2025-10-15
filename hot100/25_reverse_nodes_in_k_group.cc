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
#define METHOD2 1
#if METHOD1
class Solution {
public:
    ListNode *reverseOneGroup(ListNode *head, ListNode *tail ){
        ListNode *pA = head;
        ListNode *pB = nullptr;
        ListNode *pC = nullptr;
        ListNode *pend = tail ? tail->next : nullptr;
        //while ( pA != tail ? tail->next : nullptr )
        while ( pA != pend )
        {
            pB = pA->next;
            pA->next = pC;
            pC = pA;
            pA = pB;
        }
        return pC; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode( 0, head ); 
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        for( int i = 0; fast && i < k; i++ ){
            fast = fast->next;
        }
        if( fast == nullptr ){
            ListNode *ans = dummy->next;
            delete dummy;
            return ans;
        }
        while ( fast && slow )
        {
            int i = 0;
            ListNode *tail = slow->next;
            ListNode *prev = fast->next;
            slow->next = reverseOneGroup( slow->next, fast );
            tail->next = prev;
            fast = tail;
            for( i = 0; fast && slow && i < k; i++ ){
                slow = slow->next;
                fast = fast->next;
            }
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
#elif METHOD2
class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};
#endif
#include <iostream>
using namespace std;

int main(){
    Solution mysolve;
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode *ans = mysolve.reverseKGroup( &n1, 2 );
    while ( ans )
    {
        cout << ans->val << " " ;
        ans = ans->next;
    }
    cout << endl;
    
}