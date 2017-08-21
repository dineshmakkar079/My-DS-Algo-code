/*
Time : Sun Aug 20 2017 00:51:17 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/fizzbuzz/
Given a positive integer N, print all the integers from 1 to N. But for multiples of 3 print “Fizz” 
instead of the number and for the multiples of 5 print “Buzz”. Also for number which are multiple 
of 3 and 5, prints “FizzBuzz”.

Example

N = 5
Return: [1 2 Fizz 4 Buzz]
Note: Instead of printing 
the answer, you have to return it as list of strings.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> Solution::fizzBuzz(int A) {
    vector<string> ans(A);
    for(int i=0;i<A;i++){
        string s = to_string(i+1);
        ans[i] = s;
        if((i+1)%15==0)
            ans[i] = "FizzBuzz";
        else if((i+1)%5==0)
            ans[i] = "Buzz";
        else if((i+1)%3==0)
            ans[i] = "Fizz";
    }
    return ans;
}

int main(){

	return 0;
}
