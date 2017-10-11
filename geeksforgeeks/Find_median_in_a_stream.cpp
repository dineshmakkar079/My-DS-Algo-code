/*
Time : Wed Oct 11 2017 21:17:09 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0
Given an input stream of n integers the task is to insert integers to stream and print the median 
of the new stream formed by each insertion of x to the stream.

Example

Flow in stream : 5, 15, 
1, 3 
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream 
--> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)

Input:
The first line of input 
contains an integer N denoting the no of elements of the stream. Then the next N lines contains 
integer x denoting the no to be inserted to the stream.

Output:
For each element added to the stream 
print the floor of the new median in a new line.

Constraints:
1<=N<=10^5 7
1<=x<=10^5 7

Example:
Input:
4
5
15
1 
3
Output:
5
10
5
4

** 
For More Input/Output Examples Use 'Expected Output' option **

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
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(i==0){
            cout << v[0] << endl;
            continue;
        }
        int j=i-1;
        while(v[i] < v[j]){
            j--;
        }
        int tem = v[i];
        for(int k=i-1;k>=j+1;k--){
            v[k+1] = v[k];
        }
        v[j+1]=tem;
        if(i%2==0){
            cout << v[i/2] << endl;
        }else{
            int a = (v[i/2] + v[i/2 + 1])/2;
            cout << a << endl;
        }
    }
	return 0;
}