/*
Time : Sat Sep 02 2017 16:04:51 GMT+0530 (IST)
URL : https://www.codechef.com/SEPT17/problems/CHEFSUM
Read problems statements in mandarin chinese and russian.
Our little chef is fond of doing additions/sums 
in his free time. Today, he has an array A consisting of N positive integers and he will compute 
prefix and suffix sums over this array.
He first defines two functions prefixSum(i) and suffixSum(i) 
for the array as follows. The function prefixSum(i) denotes the sum of first i numbers of the array. 
Similarly, he defines suffixSum(i) as the sum of last N - i   1 numbers of the array.
Little Chef 
is interested in finding the minimum index i for which the value prefixSum(i)   suffixSum(i) is 
the minimum. In other words, first you should minimize the value of prefixSum(i)   suffixSum(i), 
and then find the least index i for which this value is attained.
Since, he is very busy preparing 
the dishes for the guests, can you help him solve this problem?
Input
The first line of the input 
contains an integer T denoting the number of test cases.

The first line of each test case contains 
a single integer N denoting the number of integers in the array A.
The second line contains N space-separated 
integers A1, A2, ..., AN denoting the array A.
Output
For each test case, output a single line containing 
the answer.
Constraints
1 ≤ T ≤ 10
1 ≤ N, A[i] ≤ 105

Subtasks
Subtask #1 : (20 points) 1 ≤ N ≤ 
100
Subtask #2 : (80 points) Original constraints

Example
Input:
2
3
1 2 3
4
2 1 3 1

Output:
1
2

Explanation
Example 
case 1. Let's calculate prefixSum(i)   suffixSum(i) for all indexes i in the sample case.
prefixSum(1) 
  suffixSum(1) = 1   6 = 7
prefixSum(2)   suffixSum(2) = 3   5 = 8
prefixSum(3)   suffixSum(3) = 
6   3 = 9


The minimum value of the function is 7, which is attained at index 1, so the answer 
would be 1.
Example case 2. Let's calculate prefixSum(i)   suffixSum(i) for all indexes i in the 
sample case.
prefixSum(1)   suffixSum(1) = 2   7 = 9
prefixSum(2)   suffixSum(2) = 3   5 = 8
prefixSum(3) 
  suffixSum(3) = 6   4 = 10
prefixSum(4)   suffixSum(4) = 7   1 = 8


The minimum value of the function 
is 8, which is achieved for indices 2 and 4. The minimum of these two indices 2, 4 is index 2. Hence, 
the answer will be 2.

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ull;

ull solve(std::vector<ull> v){
	ull n = v.size();
	std::vector<ull> pre(n),suf(n);
	pre[0] = v[0];
	for(ull i=1;i<n;i++){
		pre[i] = pre[i-1] + v[i];
	}
	suf[0] = pre[n-1];
	for(ull i=1;i<n;i++){
		suf[i] = suf[i-1] - v[i-1];
	}
	ull minsum = pre[0]+suf[0], minind = 1;
	for (ull i = 1; i < n; i++){
		if(pre[i]+suf[i]<minsum){
			minsum= pre[i]+suf[i];
			minind=i+1;
		}
	}
	return minind;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		std::vector<ull> v(n);
		for(int i=0;i<n;i++)cin>>v[i];
		cout << solve(v) << endl;
	}
}