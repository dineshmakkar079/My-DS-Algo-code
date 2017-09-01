/*
Time : Fri Sep 01 2017 10:43:16 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/unique-bsts/0
Given an integer N, how many structurally unique binary search trees are there that store values 
1...N?

For example, for N = 2, there are 2 unique BSTs
     1               2  
      \            
/
       2         1
For N = 3, there are 5 possible BSTs
  1              3        3         2      
1
    \           /        /           /    \      \
     3        2         1        1    3      
2
    /       /                \                      \
   2      1               2                        
3

Input:
First line contains the test cases T.  1<=T<=15
Each test case have one line which is 
an interger N.  1<=N<=11

Example:
Input:
2
2
3

Output:
2
5

**For More Examples Use Expected Output**

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

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    cout << ubst(n) << endl;
	}
	return 0;
}