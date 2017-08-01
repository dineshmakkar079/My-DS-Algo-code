/*
Time : Tue Aug 01 2017 19:36:29 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/colorfulnumber/
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can 
be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken 
into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of 
every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 


Output : 1

*/

#include <bits/stdc++.h>

using namespace std;

std::vector<int> digitise(int n){
	long long mult = 1;
	vector<int> v;
	while(n!=0){
	    v.push_back(n%10);
	    n -= n%10;
	    n /= 10;
	}
	vector<int> ret(v.rbegin(), v.rend());
	return ret;
}

int Solution::colorful(int A) {
	std::vector<int> v = digitise(A);
	std::map<int, bool> m;
	for (int i = 0; i < v.size() ; i++)
	{
		int mul = 1;
		for (int j = i; j < v.size() ; j++)
		{
			mul *= v[j];
			if(m.find(mul)!=m.end()){
				return 0;
			}else{
				m[mul] = true;
			}
		}
	}
	return 1;
}

int main(){

	return 0;
}
