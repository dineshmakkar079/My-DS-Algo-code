/*
Time : Tue Jun 27 2017 22:18:04 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/palindrome-list/
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome
or not, respectively.

Notes:
- Expected solution is linear in time and constant in space.

For
example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int len(ListNode* head){
 	 int length = 0;
 	 while(head){
 		 length++; head = head->next;
 	 }
 	 return length;
}

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

int Solution::lPalin(ListNode* A) {
	if(!A || !A->next)
		return 1;
	ListNode* fhead = A;
	int length = len(fhead);
	int half = length / 2 ;
	for(int i=0;i< half - 1; i++){
		fhead = fhead->next;
	}
	ListNode* rhead = reverseList(fhead->next);
	ListNode* temp = rhead;
	while(temp->next){
	    temp = temp->next;
	}
	temp->next = fhead;
	fhead = A;
	int i = 0;
	while(fhead && rhead && i<half){
		if(fhead->val != rhead->val)
			return 0;
		fhead = fhead->next;
		rhead = rhead->next;
		i++;
	}
	return 1;
}
