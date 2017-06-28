/*
Time : Wed Jun 28 2017 16:39:46 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/rotate-list/
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given
1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/

int length(ListNode* h){
	int length = 0;
	while(h){
		h = h->next; length++;
	}
	return length;
}

ListNode* Solution::rotateRight(ListNode* A, int B) {
	int l = length(A);
	if(l == 0 || l == 1)
		return A;
	B = B % l;
	if(B == 0)
		return A;
	ListNode* head = A;
	while(head->next){
		head = head->next;
	}
	head->next = A;
	head = A;
	int diff = l - B;
	for(int i=0;i< diff;i++){
		head = head->next;
	}
	ListNode* toret = head->next;
	head->next = NULL;
	return toret;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
