/*
Time : Wed Jun 28 2017 15:33:51 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/remove-nth-node-from-list-end/
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given
linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list
becomes 1->2->3->5.

 Note:
* If n is greater than the size of the list, remove the first node of
the list.
Try doing it using constant additional space.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
     if(!A || !A->next)
         return NULL;
 	ListNode* back = A;
 	ListNode* front = A;
 	for(int i=0;front->next && i<B;i++){
 		front = front->next;
 	}
 	while(front->next){
 		front = front->next;
 		back = back->next;
 	}
 	if(back == A && B != 1){
 		ListNode* toDel = A;
 		A = A->next;
 		delete toDel;
 		return A;
 	}else{
 		ListNode* toDel = back->next;
 		back->next = toDel->next;
 		delete toDel;
 		return A;
 	}
 }


#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
