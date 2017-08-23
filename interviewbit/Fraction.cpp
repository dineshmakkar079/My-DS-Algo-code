/*
Time : Wed Aug 23 2017 17:27:13 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/fraction/
Given two integers representing the numerator and denominator of a fraction, return the fraction 
in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 
:

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return 
"2"
Given numerator = 2, denominator = 3, return "0.(6)"

*/

#include <bits/stdc++.h>

using namespace std;

unsigned gcd(unsigned u, unsigned v) {
    while ( v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}

string Solution::fractionToDecimal(int ne, int de) {
    long long n = (long long)ne;
    long long d = (long long)de;
    bool neg = ((n<0) ^ (d<0))  ;
    if(n==0)
        return "0";
    n=abs(n); d=abs(d);
    string ans = neg ? "-" : "";
    if(n%d!=0){
        ans += to_string(n/d) + ".";
        n = n%d;
    }else{
        return to_string(n/d);
    }
    map<pair<long long,long long>,int> m ;
    map<pair<long long,long long>,int>::iterator it;
    string repf = "";
    int rem = 1;
    int i = 0;
    bool rept=false;
    while(rem){
        int z=0;
        if(n<d){
            n*=10;
        }
        pair<long long,long long> p(n,d);
        it = m.find(p);
        if(it!=m.end()){
            i = it->second;
            rept = true;
            break;
        }
        if(rept) break;
        m[p] = i;
        rem = n%d;
        repf += to_string(n/d);
        if(!rem) {
            return ans+repf;
        }
        n = n%d;
        i++;
    }
    for(int j=0;j<i;j++){
        ans += repf[j];
    }
    ans += "(";
    int l = repf.length();
    for(int j=i;j<l;j++){
        if(j>=0)
            ans += repf[j];
    }
    ans += ")";
    return ans;
}

int main(){

	return 0;
}
