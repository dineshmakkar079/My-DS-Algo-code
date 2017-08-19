/*
Time : Sat Aug 19 2017 17:38:36 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/gray-code/
The gray code is a binary numeral system where two successive values differ in only one bit.

Given 
a non-negative integer n representing the total number of bits in the code, print the sequence of 
gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. 
Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences 
possible for a given n.
Return any such sequence.

*/

#include <bits/stdc++.h>

using namespace std;

long long btd(string v){
    long long ans = 0;
    for(int i=v.length()-1;i>=0;i--)
        if(v[i]=='1')
            ans += pow(2,i);
    return ans;
}

vector<int> Solution::grayCode(int A) {
    vector<string> gray;
    vector<int> ans;
    ans.push_back(0); if(A == 0) return ans;
    ans.push_back(1); if(A == 1) return ans;
    gray.push_back("0"); gray.push_back("1");
    int counter = 2; long long LIMIT = pow(2,A);
    // Use the property of mirror symmetry of gray codes.
    while(counter <= LIMIT){
        int s = gray.size()-1;
        while(s >=0){
            gray.push_back("1" + gray[s]);
            gray[s] = "0" + gray[s];
            counter += 2;s--;
        }
    }
    ans.clear();
    for(int i=0;i<gray.size();i++){
        ans.push_back(btd(gray[i]));
    }
    return ans;
}

int main(){

	return 0;
}
