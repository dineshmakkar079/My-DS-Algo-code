/*
Time : Wed Jun 28 2017 16:52:41 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/reverse-link-list-ii/
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given
1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the
following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews
is reversing the whole linked list which is obviously an easier version of this question.

*/

ListNode* reverseList(ListNode* A) {
	if(!A or !A->next)
		return A;
	ListNode* head = A;
	ListNode* temp = NULL;
	while(head->next){
		ListNode* temp2 = head->next;
		head->next = temp;
		temp = head;
		head = temp2;
	}
	head->next = temp;
	return head;
}

ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
	if(!A || !A->next || m == n || n == 1)
		return A;
	if(m == 1){
		ListNode* end = A;
		for(int i=0;i<n-1;i++){
			end = end->next;
		}
		ListNode* front = end->next;
		end->next = NULL;
		A = reverseList(A);
		ListNode* temp = A;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = front;
		return A;
	}else{
		ListNode* head = A;
		for(int i=0;i<m-2;i++)
			head = head->next;
		ListNode* midhead = head->next,*temp = head->next;
		for(int i=0;i<n-m;i++)
			temp = temp->next;
		ListNode* end = NULL;
		if(temp){
		    end = temp->next;
		    temp->next = NULL;
		}
		midhead = reverseList(midhead);
		head->next = midhead;
		while(midhead->next)
			midhead = midhead->next;
		midhead->next = end;
		return A;
	}
}

#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
