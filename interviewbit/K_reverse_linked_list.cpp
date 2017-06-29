/*
Time : Wed Jun 28 2017 21:12:06 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/k-reverse-linked-list/
Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns
modified linked list.

 NOTE : The length of the list is divisible by K
Example :

Given linked
list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve
the problem using constant extra space.

*/
#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* last(ListNode* head){
	if(!head)
		return head;
	while(head->next){
		head = head->next;
	}
	return head;
}

ListNode* reverseListC(ListNode* A) {
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

void print(ListNode* h){
	while(h){
		cout << h->val << " "; h = h->next;
	}
	cout << endl;
}

ListNode* reverseList(ListNode* A, int B) {
	if(!A || !A->next || B == 1)
		return A;
	ListNode *head = A, *temp = A;
	for(int i=0;i<B-1;i++){
		temp = temp->next;
	}
	if(!temp){
		//cout << "herer\n";
		//print(reverseListC(A));
		return reverseListC(A);
	}
	ListNode* nextHead = temp->next;
	temp->next = NULL;
	head = reverseListC(head);
	ListNode* end = last(head);
	end->next = reverseList(nextHead,B);
	return head;
}

int main(){
	ListNode *head = new ListNode(0), *temp = head;
	for(int i=1;i<10;i++){
		temp->next = new ListNode(i);
		temp = temp->next;
	}
	print(reverseList(head,2));
	return 0;
}
