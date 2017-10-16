/*
Time : Sun Oct 15 2017 00:20:16 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
Given a binary tree, a target node in the binary tree, and an integer value k, print all the nodes 
that are at distance k from the given target node. No parent pointers are available.

Input:
The 
first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case contains an integer n denoting the number of edges. Then the following line contains 
the edges as given in the example. The next line contains the target node. The last line of input 
contains the the value of distance k.

Output:
Print all the space separated nodes that are at distance 
k from the given target node.

Constraints:
1<=T<=1000
1<=no of edges<=100
1<=data of node<=100
1<=target<=100

Example:
Input:
2
6
20 
8 L 20 22 R 8 4 L 8 12 R 12 10 L 12 14 R
8
2
5
20 7 L 20 24 R 7 4 L 7 3 R 3 1 L
7
2

Output:
10 
14 22 
1 24 

** For More Input/Output Examples Use 'Expected Output' option **

*/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary Tree node
struct node
{
    int data;
    struct node *left, *right;
}; */
/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */

bool fnd = false;

void printkdistanceNodeDown(node *root, int k)
{
    if(!root || k<0)return;
    if(k==0){
        cout << root->data << " ";
        fnd = true;
        return;
    }
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}
/* Prints all nodes at distance k from a given target node.
 The k distant nodes may be upward or downward.  This function
 Returns distance of root from target node, it returns -1 if target
 node is not present in tree rooted with root. */

void build(map<node*, node*>& parentm,node* root ,node* parent){
    if(!root)return;
    build(parentm,root->left,root);
    parentm[root] = parent;
    build(parentm,root->right,root);
}
 
int printkdistanceNode(node* root, node* target , int k)
{
    fnd = false;
    if(root==target){
        printkdistanceNodeDown(root,k);
        if(!fnd)return -1;
        return 0;
    }
    printkdistanceNodeDown(target,k);
    map<node*, node*> parent;
    map<node*, node*>& p = parent;
    parent[root]=NULL;
    build(p,root->left,root);
    build(p,root->right,root);
    node* t = target;
    int lev = 1;
    while(t){
        node* pr = p[t];
        if(!pr)break;
        if(lev == k){cout << pr->data << " "; fnd=true;}
        lev++;
        if(pr->left == t)
            printkdistanceNodeDown(pr->right,k-lev);
        else
            printkdistanceNodeDown(pr->left,k-lev);
        t = pr;
    }
    if(!fnd)return -1;
}