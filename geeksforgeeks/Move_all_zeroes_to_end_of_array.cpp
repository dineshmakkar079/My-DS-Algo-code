/*
Time : Thu Oct 12 2017 22:33:03 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array/0/?ref=self
Given an array of random numbers, Push all the zero’s of a given array to the end of the array. For 
example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 
8, 4, 2, 7, 6, 0, 0, 0, 0}. 

Input:
The first line contains an integer 'T' denoting the total number 
of test cases. In each test cases, First line is number of elements in array 'N' and second its 
values.

Output:
Print the array after shifting all 0's at the end.​

Note: An extra space is expected 
at the end after output of every test case

Constraints:
1 <= T <=100
1 <= N <=1000
0 <= a[i] <=100

Example:
Input:
1
5
3 
5 0 0 4

Output:
3 5 4 0 0

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ip pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vl vector<long long>
#define vvl vector<vl>
#define vr vector
#define init(a, n, v) for (int schz=0;schz<n;schz++) a[schz]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vi v(n);
	    int zc=0;
	    for(int i=0;i<n;i++){
            cin >> v[i];
            zc += v[i]==0?1:0;
        }
        int j=0;
        for(int i=0;i<n && j<n;){
            if(v[i]!=0){
                v[j] = v[i];
                i++;
                j++;
            }else{
                while(i<n && v[i]==0){
                    i++;
                }
                if(i!=n)v[j++]=v[i++];
            }
        }
        for(int i=0;i<zc;i++)v[n-1-i]=0;
        for(int i=0;i<n;i++)cout<<v[i]<<" ";cout << endl;
	}
	return 0;
}