/*
Time : Wed Jun 28 2017 17:52:27 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4,
you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may
not modify the values in the list, only nodes itself can be changed.

*/

ListNode* Solution::swapPairs(ListNode* A) {
	if(!A || !A->next){
		return A;
	}
	ListNode* head = A;
	ListNode *odd = head,*even = head->next, *prev = head;
	ListNode* nextodd = even->next;
	even->next = odd;
	odd->next = swapPairs(nextodd);
	return even;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
