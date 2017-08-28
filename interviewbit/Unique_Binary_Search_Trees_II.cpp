/*
Time : Mon Aug 28 2017 16:50:25 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/unique-binary-search-trees-ii/
Given A, how many structurally unique BST’s (binary search trees) that
store values 1...A?

Example 
:

Given A = 3, there are a total of 5 unique BST’s.


   1         3     3      2      1
    \    	/     /      / \      \
     3     2     1      1   3      2
    /     /       \            		\
   2     1         2                 3

*/

#include <bits/stdc++.h>

using namespace std;

int ubsthelper(vector<int>& uni,int n){
	if(n == 0 || n==1) return 1;
	if(n == 2) return 2;
	if(uni[n]!=-1)return uni[n];
	uni[n] = 0;
	for(int i=1;i<=n;i++){
		uni[n] += (ubsthelper(uni,i-1))*(ubsthelper(uni,n-i));
	}
	return uni[n];
}

int ubst(int n) {
	if(n==0) return 1;
	if(n==1) return 1;
	if(n==2) return 2;
	std::vector<int> uni(n+1);
	for(int i=0;i<n+1;i++) uni[i] = -1;
	uni[0] = 1;uni[1] = 1;uni[2] = 2;
	ubsthelper(uni,n);
	return uni[n];
}

int Solution::numTrees(int A) {
    return ubst(A);
}

int main(){

	return 0;
}
