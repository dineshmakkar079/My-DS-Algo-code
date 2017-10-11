/*
Time : Sun Oct 08 2017 14:34:55 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/multiply-two-polynomals/0
Given two polynomials represented by two arrays that contains the coefficients of poynomials, print 
the polynomial in form of array formed after multiplication of given polynomials.

Input:

The first 
line contains an integer T, depicting total number of test cases. 
First line of each test case 
contains two integers M and N ,highest degree of the polynomial arr1 and arr2.

Next two line contains 
M and N integers , decribes the coefficients of polynomials

Output:

Print the coefficients of 
resultant poynomial.

Constraints:

1<=T<=100
1<=M,N<=100
1<=arr1[i],arr2[i]<=100

Example:

Input:

2
4 
3
1 0 3 2
2 0 4
5 4
1 9 3 4 7
4 0 2 5

Output:

2 0 10 4 12 8
4 36 14 39 79 23 34 35

Explanation:
First 
case:

First polynomial: 
1   0x^1   3x^2   2x^3
Second polynomial: 
2   0x^1   4x^2
Product polynomial:
2 
  0x^1   10x^2   4x^3   12x^4   8x^5

Second case:
First polynomial:
1   9x^1   3x^2   4x^3   7x^4
Second 
polynomial: 
4   0x^1   2x^2   5x^3
Product polynomial: 
4   36x^1   14x^2   39x^3   79x^4   23x^5 
  34x^6   35x^7

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
	    int m , n;
	    cin >> m >> n;
	    vi v1(m),v2(n);
	    int m1=0,m2=0;
	    for(int i=0;i<m;i++){
            cin >> v1[i];
            if(v1[i]!=0)m1=max(m1,i);
        }
        for(int i=0;i<n;i++){
            cin >> v2[i];
            if(v2[i]!=0)m2=max(m2,i);
        }
        vi ans(m+n-1);
        init(ans,m+n-1,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i+j] += v1[i]*v2[j];
            }
        }
        for(int i=0;i<m+n-1;i++){
            cout << ans[i] << " ";
        }
        cout << endl;
	}
	return 0;
}