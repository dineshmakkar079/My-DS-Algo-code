/*
Time : Fri Oct 13 2017 00:08:35 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0/?ref=self
Given a sorted array of integers, every element appears twice except for one. Find that single one 
in linear time complexity and without using extra memory.

 

Input:

The first line of input consists 
number of the test cases. The description of T test cases is as follows:

The first line of each 
test case contains the size of the array, and the second line has the elements of the array.

 


Output:

In 
each separate line print the number that appears only once in the array.


Constraints:

1 ≤ T ≤ 
70
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100000


Example:

Input:

1
11
1 1 2 2 3 3 4 50 50 65 65

Output:

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
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int ts,ans = INT_MIN;
	    for(int i=0;i<n;i++){
            cin >> ts;
            ans = (ans==INT_MIN)?ts: ans^ts;
        }
        cout << ans << endl;
	}
	return 0;
}