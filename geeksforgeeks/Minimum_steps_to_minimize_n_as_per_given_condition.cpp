/*
Time : Tue Sep 05 2017 22:07:21 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition/0
Given a number n, count minimum steps to minimise it to 1 according to the following criteria:

If 
n is divisible by 2 then we may reduce n to n/2.
If n is divisible by 3 then you may reduce n to 
n/3.
Decrement n by 1.
 

Input:

The first line of input contains an integer T denoting the number 
of test cases. Then T test cases follow. The first line of each test case contains an integer N 
denoting the number n.

 

Output:

Output the minimum steps to minimise the number in a new line 
for each test case.


Constraints:

1<= T <=1000

1<= N <=10000


Example:

Input:

2

10

6

Output:

3

2

**For 
More Examples Use Expected Output**

*/

#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vi mem(n+1);
	    mem[0] = 0; mem[1]=0;mem[2]=1;mem[3]=1;
	    for(int i=4;i<=n;i++){
	        mem[i] = INT_MAX;
	        if(i%2==0)mem[i] = min(mem[i],1+mem[i/2]);
	        if(i%3==0)mem[i] = min(mem[i],1+mem[i/3]);
	        mem[i] = min(mem[i],1+mem[i-1]);
	    }
	    cout << mem[n] << endl;
	    mem.clear();
	}
	return 0;
}