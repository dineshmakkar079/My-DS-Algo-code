/*
Time : Wed Oct 04 2017 12:38:48 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size/0
Given an integer array of size n, find the maximum of the minimum’s of every window size in the 
array. Note that window size varies from 1 to n.

Input:
The first line contains an integer 'T' 
denoting the total number of test cases. In each test cases, the first line contains an integer 
'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., 
AN denoting the elements of the array.


Output:
In each seperate line print the array of numbers 
of size n for each of the considered window size 1,2,...,n respectively.


Constraints:
1<=T<=30
1<=N<=100
1<=A[I]<=5000


Example:
Input: 
2
7
10 
20 30 50 10 70 30
3
10 20 30

Output: 
70 30 20 10 10 10 10 
30 20 10

Explaination:
 

Input:  
arr[] = {10, 20, 30, 50, 10, 70, 30}
Output:         70, 30, 20, 10, 10, 10, 10

First element in 
output indicates maximum of minimums of all 
windows of size 1.
Minimums of windows of size 1 are 
{10}, {20}, {30}, {50}, {10},
{70} and {30}.  Maximum of these minimums is 70

Second element in 
output indicates maximum of minimums of all 
windows of size 2.
Minimums of windows of size 2 are 
{10}, {20}, {30}, {10}, {10},
and {30}.  Maximum of these minimums is 30

Third element in output 
indicates maximum of minimums of all 
windows of size 3.
Minimums of windows of size 3 are {10}, 
{20}, {10}, {10} and {10}. 
Maximum of these minimums is 20

Similarly other elements of output 
are computed.
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
	    vi A(n),left(n),right(n),ans(n+1);
	    int mini=INT_MAX;
	    for(int i=0;i<n;i++){
            cin>>A[i];
            ans[i]=INT_MIN;
            mini = min(mini,A[i]);
        }
        ans[n]=INT_MIN;
        // Compute next smaller element
        stack<int> s;
        for(int i=0;i<n;i++){
            if(s.empty() || A[s.top()]<=A[i])
                s.push(i);
            else{
                while(!s.empty() && A[s.top()]>A[i]){
                    right[s.top()] = i;
                    s.pop();
                }
                s.push(i);
            }
        }
        while(!s.empty()){
            right[s.top()]=n; s.pop();
        }
        // Compute previous smaller element
        for(int i=n-1;i>=0;i--){
            if(s.empty() || A[s.top()]<=A[i])
                s.push(i);
            else{
                while(!s.empty() && A[s.top()] > A[i]){
                    left[s.top()] = i; s.pop();
                }
                s.push(i);
            }
        }
        while(!s.empty()){
            left[s.top()]=-1; s.pop();
        }
        // A[i] is minimum from left[i] to right[i]
        // i.e. for window size (right[i]-left[i]-1) ,A[i] is the min element.
        for(int i=0;i<n;i++){
            int len = right[i]-left[i]-1;
            ans[len] = max(ans[len], A[i]);
        }
        // For window of size n, max of min element is overall minimum.
        ans[n]=mini;
        for(int i=n-1;i>=1;i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<< " ";
        cout << endl;
	}
	return 0;
}