/*
Time : Wed Aug 30 2017 13:34:10 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/reach-the-nth-point/0
There are N points on the road ,you can step ahead by 1 or 2 . Find the number of ways you can reach 
at point N. For example:  for n=4 we have 5 possible ways [1,1,1,1]  [1,1,2]  [1,2,1]  [2,1,1]  
[2 2].

Input:

The first line of input contains an integer T denoting the number of test cases.Next 
line of each input contains a single integer N.

Output:

Print the output of each test case in 
a new line.

Constraints:

1<=T<=100

1<=N<=90

Example:

Input:

2
4
5

Output:

5
8

 

**For 
More Examples Use Expected Output**

*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull climbStairs(int n) {
    ull one=1,two=2,ans;
    if(n==0)return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    for (int i = 3; i < n+1; i++){
        ans = one + two;
        int temp = ans;
        one = two; two = ans;
    }
    return ans;
}


int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    cout << climbStairs(n) << endl;
	}
	return 0;
}