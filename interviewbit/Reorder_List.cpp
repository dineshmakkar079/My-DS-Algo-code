/*
Time : Thu Jun 29 2017 20:04:30 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/reorder-list/
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given
{1,2,3,4}, reorder it to {1,4,2,3}.

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

ListNode* Solution::reorderList(ListNode* A) {
	if(!A || !A->next)
		return A;
	ListNode* slow = A, *fast = A;
	while(fast->next && fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* secondHead =  slow->next;
	slow->next = NULL;
	secondHead = reverseList(secondHead);
	int i=1;
	ListNode* common = new ListNode(0);
	ListNode* tempA = A, *tempB = secondHead, temp = common;
	while(tempA && tempB){
		if(i%2){
			temp->next = tempA;
			tempA = tempA->next;
		}else{
			temp->next = tempB;
			tempB = tempB->next;
		}
		i++;
		temp = temp->next;
	}
	if(tempA && !tempB){
		temp->next = tempA;
	}else if(!tempA && tempB){
		temp->next = tempB;
	}
	return common->next;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
