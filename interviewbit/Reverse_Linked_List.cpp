/*
Time : Tue Jun 27 2017 22:07:49 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/reverse-linked-list/
Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,

return
5->4->3->2->1->NULL.

PROBLEM APPROACH :

Complete solution code in the hints

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
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
