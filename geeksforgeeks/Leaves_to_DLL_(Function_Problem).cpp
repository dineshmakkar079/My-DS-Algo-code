/*
Time : Tue Oct 10 2017 23:27:48 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/leaves-to-dll/1
Given a Binary Tree, extract all leaves of it in a Doubly Linked List (DLL). Note that the DLL need 
to be created in-place. Assume that the node structure of DLL and Binary Tree is same, only the 
meaning of left and right pointers are different. In DLL, left means previous pointer and right 
means next pointer. Head of DLL should point to the left most leaf and than in inorder traversal 
and so on.

Note:The Input/Ouput format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. As it is a function problem, hence a user 
should not read any input from stdin/console. The task is to complete the function specified, and 
not to write the full code.

Input:
The task is to complete the method which takes two arguments, 
root of Binary Tree and reference to head of DLL.
The struct Node has a data part which stores the 
data, pointer to left child and pointer to right child.
There are multiple test cases. For each 
test case, this method will be called individually.

Output:
In the function make changes in Head.

Constraints:
1<=T<=100
1<=N<=10000

Example:
Input:
2
2
1 
2 L 1 3 R
3
1 2 L 1 3 R 2 4 L
Output:
2 3
3 2 
4 3
3 4 

** For More Input/Output Examples Use 'Expected 
Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/
void inorder(Node* root,Node*& left,Node*& right){
    if(root){
        inorder(root->left,left,right);
        if(!root->left && !root->right){
            if(!left) left = root;
            right = root;
        }
        inorder(root->right,left,right);
    }
}

void link(Node* root,Node*& prevleaf){
    if(root){
        link(root->left,prevleaf);
        if(!prevleaf && !root->left && !root->right){
            prevleaf = root;
        }
        else if(prevleaf && !root->left && !root->right){
            prevleaf->right = root;
            root->left = prevleaf;
            prevleaf = root;
        }
        link(root->right,prevleaf);
    }
}

Node *convertToDLL(Node *root,Node **head_ref)
{
    Node* ll = NULL, *rr=NULL;
    Node*& left =ll ; Node*& right = rr;
    inorder(root,left,right);
    *head_ref = left;
    left = NULL;
    link(root,left);
    return *head_ref;
}

int main(){

	return 0;
}
