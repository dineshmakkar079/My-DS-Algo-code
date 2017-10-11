/*
Time : Fri Oct 06 2017 11:42:31 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/vertical-sum/1
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums 
through different vertical lines.

Input:
First line of every test case consists of T test case. 
First line of every test case consists of N, denoting number of nodes. Second line of every test 
case consists of 3*N elements denoting , 2 integers and 1 character ,i.e., parent node , child node 
and character denotes which child.

Output:
Single line output, print the vertical sum from left 
to right.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
3
5 2 L 5 3 R 2 1 L
5
5 3 R 5 2 L 
2 1 L 2 7 R 3 6 L
Output:
1 2 5 3 
1 2 18 3 

** For More Input/Output Examples Use 'Expected Output' 
option **

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
void build(Node* root,int index,map<int,int>& m){
    if(!root)return;
    map<int,int>::iterator it = m.find(index);
    if(it==m.end()){
        m[index] = root->data;
    }else{
        it->second += root->data;
    }
    build(root->left,index-1,m);
    build(root->right,index+1,m);
}

void printVertical(Node *root)
{
    map<int,int> ma;
    map<int,int>& m = ma;
    build(root,0,m);
    map<int,int>::iterator it=  m.begin();
    while(it!=m.end()){
        cout << it->second << " ";
        it++;
    }
}

int main(){

	return 0;
}
