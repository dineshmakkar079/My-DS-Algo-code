/*
Time : Tue Aug 01 2017 23:06:38 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/reverselinklistrecursion/
Reverse a linked list using recursion.

Example :
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.

PROBLEM 
APPROACH :

Complete solution code in the hints

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* rev(ListNode* A){
	if(!A)
    	return A;
    if(A->next){
    	ListNode* temp = rev(A->next);
    	temp->next = A;
    	return A;
    }else{
    	return A;
    }
}

ListNode* Solution::reverseList(ListNode* A) {
    ListNode* ret = A;
    if(!ret)
        return ret;
    while(ret->next)
    	ret = ret->next;
    rev(A);
    A->next = NULL;
    return ret;
}


int main(){

	return 0;
}
