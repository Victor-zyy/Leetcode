#include <vector>
#include <iostream>
using namespace std;

ostream& operator << (ostream &os, const vector<int>& v);
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if(headA->next == NULL || headB->next == NULL)
	return NULL;

      ListNode* temp1 = NULL;
      ListNode* temp2 = NULL;
      while(headA){
	temp1 = headA;
	temp2 = temp1->next;
	headA = temp2->next;
	temp->next = temp;
      }

      while(headB->next){
	temp = headB;
	headB = headB->next;
	temp->next = temp;
      }

      if(headA->next != headB->next)
	return NULL;
      while(headA->next && headB->next && headA->next == headB->next){
	headA = headA->next;
	headB = headB->next;
      }

      return headA;
    }
};
ostream&
operator << (ostream &os, const vector<int>& v)
{
  os << "{ ";
  for(auto it : v)
    os << it << ' ';
  return os << "} ";
}

ostream&
operator<<( ostream& os, const vector<vector<int>>& matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  os << "{" << endl;
  for( int i = 0; i < m ; i++) {
    os << "[ ";
    for( int j = 0; j < n ; j++) {
      os << matrix[i][j] << " ";
    }
    os << "]" << endl;
  }
  os << "}" << endl;
  return os;
}

int main(){
  return 0;
}
