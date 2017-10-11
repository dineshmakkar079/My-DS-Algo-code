/*
Time : Fri Oct 06 2017 21:54:45 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1
Given two linked lists, your task is to complete the function findIntersection, that returns the 
intersection of two linked lists.

Input:
The function takes 2 arguments, reference pointer to the 
head of the first linked list (head1) and reference pointer to the head of the second linked list 
(head2). 
There are multiple test cases and for each test case this function will be called separately.

Output:
The 
function should return reference pointer to the head of the new list that is formed by the intersection 
of the two the lists. 
Note: The new list formed should be in non-decreasing order.

Constraints:
1<=T<=100
1<=N<=103

Example:
Input:
1
6
9 
6 4 2 3 8
5
1 2 8 6 2
Output:
2 6 8

Note:The Input/Ouput format and Example given are used for 
system's internal purpose, and should be used by a user for Expected Output only. As it is a function 
problem, hence a user should not read any input from stdin/console. The task is to complete the 
function specified, and not to write the full code.

** For More Input/Output Examples Use 'Expected 
Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/
struct node* findIntersection(struct node* head1, struct node* head2)
{
    map<int, int> m1,m2;
    map<int, int>::iterator it;
    struct node* head = new struct node;
    int c = 1;
    while(head1){
        it = m1.find(head1->data);
        if(it==m1.end()){
            m1[head1->data] = 1;
        }else{
            m1[head1->data]++;
        }
        head1=head1->next;
    }
    while(head2){
        it = m1.find(head2->data);
        if(it!=m1.end()){
            it = m2.find(head2->data);
            if(it==m2.end()) m2[head2->data]=1;
            else m2[head2->data]++;
            if(--m1[head2->data]==0)m1.erase(m1.find(head2->data));
        }
        head2 = head2->next;
    }
    it = m2.begin();
    struct node* temp = head;
    while(it!=m2.end()){
        while(it->second--){
            struct node* newNode = new struct node;
            newNode->data = it->first;
            newNode->next = NULL;
            temp->next = newNode;
            temp = newNode;
        }
        it++;
    }
    return head->next;
}


int main(){

	return 0;
}
