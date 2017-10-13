/*
Time : Fri Oct 13 2017 03:06:59 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/sum-of-right-leaf-nodes/1/?ref=self
Given a Binary Tree of size N, your task is to complete the function rightLeafSum(), that should 
return the sum of all the leaf nodes that are right child of their parent of the given binary tree.
Example:

Input 
: 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
     \        /  \
  
    2       6   7
Output :
sum = 2   5   7 = 14
Input:
The function takes a single arguments as 
input, the reference pointer to the root of the binary tree.
There are T test cases and for each 
test case the function will be called separately.

Output:
The function should return the sum of 
all the right leaf nodes of the binary tree.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
2
1 
2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L
Output:
3
60

Note:The Input/Ouput format and Example given 
are used for system's internal purpose, and should be used by a user for Expected Output only. As 
it is function problem, hence a user should not read any input from stdin/console. The task is to 
complete the function specified, and not to write the full code.

** For More Input/Output Examples 
Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all 
// right leaf nodes

void sumit(Node* root,int& ans,Node* parent){
    if(root){
        sumit(root->left,ans,root);
        if(!root->left && !root->right && root==parent->right)ans+=root->data;
        sumit(root->right,ans,root);
    }
}

int rightLeafSum(Node* root)
{
    int a = 0;
    int& ans = a;
    sumit(root,ans,NULL);
    return ans;
}

int main(){

	return 0;
}
