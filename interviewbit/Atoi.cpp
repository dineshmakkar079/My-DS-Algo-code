/*
Time : Sat Aug 19 2017 23:17:31 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/atoi/
Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: 
There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 
Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string 
have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found 
before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. 
Return INT_MAX if the number is positive, INT_MIN otherwise. 
Warning : DO NOT USE LIBRARY FUNCTION 
FOR ATOI.
If you do, we will disqualify your submission retroactively and give you penalty points.

*/

#include <bits/stdc++.h>

using namespace std;

int parse(string s,bool neg){
    long long ans = 0;
    int l = s.length() -1;
    int unit = 0;
    while(l>=0 && ans < INT_MAX){
        long long t = ((int)s[l]-(int)'0')*pow(10,unit);
        ans += t;
        unit++;
        l--;
    }
    if(ans >= INT_MAX){
        return neg ? INT_MIN : INT_MAX;
    }
    return neg ? -1*ans : ans;
}

int ai(string s,bool neg){
    int l = s.length();
    int i=0;
    while(s[i]==' ')i++;
    int le = i;
    while(i<l && s[i]>='0' && s[i]<='9'){
        i++;
    }
    string numberstr = s.substr(le,i-le);
    if(numberstr.length()==0)
        return 0;
    return parse(numberstr, neg);
}

int Solution::atoi(const string &A) {
    if(A[0]=='-'){
        string str = A.substr(1,A.length()-1);
        if(str.length()>=1 && str[0]!=' ')
            return ai(str,true);
        else
            return 0;
    }
    if(A[0]=='+'){
        string str = A.substr(1,A.length()-1);
        if(str.length()>=1 && str[0]!=' ')
            return ai(str,false);
        else
            return 0;
    }
    return ai(A,false);
}

int main(){

	return 0;
}
