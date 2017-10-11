/*
Time : Mon Oct 09 2017 16:49:00 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0
Given a list of non negative integers, arrange them in such a manner that they form the largest 
number possible.

The result is going to be very large, hence return the result in the form of a 
string.

Input:

The first line of input consists number of the test cases. The description of T 
test cases is as follows:

The first line of each test case contains the size of the array, and 
the second line has the elements of the array.


Output:

In each separate line print the largest 
number formed by arranging the elements of the array in the form of a string.


Constraints:

1 
≤ T ≤ 70
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 1000


Example:

Input:

2
5
3 30 34 5 9
4
54 546 548 60

Output:

9534330
6054854654

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

bool comp(int s1, int s2){
    return to_string(s1)+to_string(s2) > to_string(s2)+to_string(s1);
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vi v(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<n;i++)cout << v[i];
        cout << endl;
	}
	return 0;
}