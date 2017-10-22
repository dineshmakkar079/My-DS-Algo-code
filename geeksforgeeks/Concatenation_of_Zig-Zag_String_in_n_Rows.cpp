/*
Time : Sat Oct 21 2017 17:05:49 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/concatenation-of-zig-zag-string-in-n-rows/0
Input:

Given a string and number of rows ‘n’. Print the string formed by concatenating n rows when 
input string is written in row-wise Zig-Zag fashion.

Examples:

Input: str = "ABCDEFGH"
       
n = 2
Output: "ACEGBDFH"
Explanation: Let us write input string in Zig-Zag fashion
             
in 2 rows.
A   C   E   G   
  B   D   F   H
Now concatenate the two rows and ignore spaces 
in every 
row. We get "ACEGBDFH"

Input: str = "GEEKSFORGEEKS"
       n = 3
Output: GSGSEKFREKEOE
Explanation: 
Let us write input string in Zig-Zag fashion
             in 3 rows.
G       S       G       S
 
 E   K   F   R   E   K
    E       O       E
Now concatenate the two rows and ignore spaces 
in 
every row. We get "GSGSEKFREKEOE"
 

Input:

The first line of input consists number of the test 
cases. The description of T test cases is as follows:

The first line of each test case contains 
the string, and the second line has 'n' the number of rows.


Output:

In each separate line print 
the string after concatenating n rows in a zig zag form.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ size 
of string


Example:

Input:

2
qrrc
3
rfkqyuqfjkxy
2

Output:

qrcr
rkyqjxfqufky
 

** For More 
Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
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
#define pb push_back;
#define sz(a) (a).size()

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    string s; cin >>s; cin >> n;
	    int l = s.length();
	    vector<string> v(n,"");
	    int toadd = 1;
	    int j = 0;
	    if(n==1){
	        cout << s << endl; continue;
	    }
	    for(int i=0;i<l;i++){
	        v[j].push_back(s[i]);
            if(j==0)
                toadd = 1;
            else if(j+1==n)
                toadd = -1;
            j += toadd;
        }
        string ans = "";
        for(int i=0;i<n;i++)ans+=v[i];
        cout << ans << endl;
	}
	return 0;
}