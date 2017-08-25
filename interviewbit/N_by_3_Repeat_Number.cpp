/*
Time : Thu Aug 25 2017 22:22:15 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/n3-repeat-number/
You’re given a read only array of n integers. Find out if any integer 
occurs more than n/3 times in the array in linear time and 
constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

For example,
Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::repeatedNumber(const vector<int> &a) {
    int n = a.size();
    pair<int,int> one(-1,0),two(-1,0); // pair<value,count>
    int count = 0;
    for(int i=0;i<n;i++){
        if(count < 2){
            if(one.first==a[i]) one.second++;
            else if(two.first==a[i]) two.second++;
            else if(one.first==-1){ one.first = a[i]; one.second = 1; count++;}
            else { two.first = a[i]; two.second = 1; count++;}
        }else if(one.first == a[i]){
            one.second++;
        }else if(two.first == a[i]){
            two.second++;
        }else{
            if(--one.second == 0){ one.first = -1; count--;}
            if(--two.second == 0){ two.first = -1; count--;}
        }
    }
    int totalone = 0, totaltwo = 0;
    for(int i=0;i<n;i++){
        if(a[i]==one.first)
            totalone++;
        else if(a[i]==two.first)
            totaltwo++;
    }
    if(totalone > n/3) return one.first;
    if(totaltwo > n/3) return two.first;
    return -1;
}

int main(){

	return 0;
}