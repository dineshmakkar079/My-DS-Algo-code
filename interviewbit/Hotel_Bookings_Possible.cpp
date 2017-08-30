/*
Time : Thu Aug 31 2017 01:25:11 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/hotel-bookings-possible/
A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K 
rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there 
are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in 
time O(N log N) .

Input:


First list for arrival time of booking.
Second list for departure time 
of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its 
possible to make a booking. 
Return 0/1 for C programs.
O -> No there are not enough rooms for N 
booking.
1 -> Yes there are enough rooms for N booking.
Example :

Input : 
        Arrivals :  
 [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 
2 guests in the hotel. But I have only one room.

*/

#include <bits/stdc++.h>

using namespace std;

bool Solution::hotel(vector<int> &arr, vector<int> &dep, int k) {
    sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());
	int n = arr.size();
	int currcount = 0;
	int i=0,j=0;
	for(; i<n&&j<n; ){
		if(arr[i] < dep[j]){
			currcount++;
			i++;
			if(currcount > k) return 0;
		}else{
			currcount = currcount<0?0:currcount-1;
			j++;
		}
	}
	while(i<n){
		currcount++; i++;
		if(currcount > k) return 0;
	}
	return 1;
}

int main(){

	return 0;
}
