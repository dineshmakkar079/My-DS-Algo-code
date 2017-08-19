/*
Time : Thu Aug 17 2017 00:15:27 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/copy-list/
A linked list is given such that each node contains an additional random pointer which could point 
to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 
2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy 
of the list. The returned answer should not contain the same node as the original list, but a copy 
of them. The pointers in the returned list should not link to any node in the original input list.

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    map<RandomListNode*, RandomListNode*> m;
    map<RandomListNode*, RandomListNode*>::iterator it;
    RandomListNode* temp = A;
    while(temp){
        RandomListNode* newNode = new RandomListNode(temp->label);
        m[temp] = newNode;
        temp = temp->next;
    }
    RandomListNode* newHead = m[A];
    RandomListNode* newTemp = newHead;
    temp = A;
    while(temp){
        RandomListNode* t = m[temp];
        if(t){
            newTemp->next = temp->next ? m[temp->next] : NULL;
            newTemp->random = temp->random ? m[temp->random] : NULL;
        }
        temp = temp->next;
        newTemp = newTemp->next;
    }
    return newHead;
}

int main(){

	return 0;
}
