/*
Time : Tue Jun 27 2017 19:30:19 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/intersection-of-linked-lists/
Write a program to find the node at which the intersection of two singly linked lists begins.

For
example, the following two linked lists:


A:          a1 → a2
                   ↘

         			   c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.


Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain
their original structure after the function returns.
You may assume there are no cycles anywhere
in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Problem
approach completely explained :

Complete code in the hints section.

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

 ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
 	if(!A || !B)
 		return NULL;
 	int la = len(A);
 	int lb = len(B);
 	ListNode* big = la> lb? A : B;
 	ListNode* small = big == A? B :A;
 	int diff = abs(la - lb);
 	while(diff--){
 		big = big->next;
 	}
 	while(small && big && small != big){
 		small = small->next;
 		big = big->next;
 	}
 	return small;
 }
