/*
Time : Tue Oct 10 2017 23:33:03 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1
Given a Binary Tree (BT), convert it to a Circular Doubly Linked List(DLL) In-Place. The left and 
right pointers in nodes are to be used as previous and next pointers respectively in converted CDLL. 
The order of nodes in CDLL must be same as Inorder of the given Binary Tree. The first node of Inorder 
traversal (left most node in BT) must be head node of the CDLL.

Input:
The task is to complete 
the method which takes a arguments, root of Binary Tree.
The struct Node has a data part which stores 
the data, pointer to left child and pointer to right child.
There are multiple test cases. For each 
test case, this method will be called individually.

Output:
The function should return the head 
of CDLL.

Constraints:
1 <=T<= 100
1 <=Number of nodes<= 100
1 <=Data of a node<= 100

Example:
Input:
2
2
1 
2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
Output:
3 1 2 
2 1 3
40 20 60 10 30 
30 10 60 20 40

** 
For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows:
struct Node
{
    struct Node *left, *right;
    int data;
};*/

Node* util(Node* root){
    if(!root)return root;
    if(!root->left && !root->right)return root;
    Node* l = util(root->left);
    Node* r = util(root->right);
    Node* temp = l;
    root->right = r;
    if(r) r->left = root;
    if(!l) return root;
    while(l->right){
        l = l->right;
    }
    l->right = root;
    root->left = l;
    return temp; 
}

void BToDLL(Node *root, Node **head_ref)
{
    if(!root){
        *head_ref = NULL;
        return;
    }
    *head_ref = util(root);
}

Node *bTreeToCList(Node *root)
{
    Node* h = NULL;
    Node** head = &h;
    BToDLL(root,head);
    Node* temp = *head;
    while(temp->right){
        temp = temp->right;
    }
    temp->right = *head;
    (*head)->left = temp;
    return *head;
}

int main(){

	return 0;
}
