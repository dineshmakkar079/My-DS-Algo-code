/*
Time : Fri Oct 06 2017 22:37:42 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/first-repeating-element/0
Find the first repeating element in an array of integers, i.e., an element that occurs more than 
once and whose index of first occurrence is smallest.

Input :
The first line contains an integer 
'T' denoting the total number of test cases. In each test cases, First line is number of elements 
in array 'N' and second its values.

Output: 
In each separate line print the index of first repeating 
element, if there is not any repeating element then print “-1”. Use 1 Based Indexing.

Constraints:
1 
<= T <=500
1 <= N <=10000
0 <= a[i] <=10000

Example:
Input:
1
7
1 5 3 4 3 5 6

Output:
2

Explanation: 
5 
is appearing twice and its first appearence is at index 2 which is less than 3 whose first occuring 
index is 3.

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
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        map<int,int> m;
        map<int,int>::iterator it;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            it=m.find(v[i]);
            if(it==m.end()){
                m[v[i]]=i+1;
            }else{
                mini = min(mini, m[v[i]]);
            }
        }
        if(mini<100000)
            cout << mini << endl;
        else
            cout << "-1\n";
	}
	return 0;
}