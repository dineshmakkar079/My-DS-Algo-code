/*
Time : Mon Oct 09 2017 02:09:00 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/c-stl-set-8-unordered-set/1/?ref=self
Implement different operations on an unordered set s .

Input:
The first line of input contains 
an integer T denoting the no of test cases . Then T test cases follow. The first line of input contains 
an integer Q denoting the no of queries . Then in the next line are Q space separated queries .
A 
query can be of four types 
1. a x (inserts an element x to the unordered set s)
2. b x (erases 
an element x from the unordered set s)
3. c x (prints 1 if the element x is present in the set else 
print -1)
4. d    (prints the size of the unordered set s)

Output:
The output for each test case 
will  be space separated integers denoting the results of each query . 

Constraints:
1<=T<=100
1<=Q<=100

Example(To 
be used only for only expected output):

Input
2
5
a 1 a 2 a 3 b 2 d
4
a 1 a 5 d c 2
 
Output
2
2 
-1

Explanation :
For the first test case
There are five queries. Queries are performed in this 
order
1. a 1     {inserts 1 to set now set has {1} }
2. a 2     {inserts 2 to set now set has {1,2} }
3. 
a 3     {inserts 3 to set now set has {1,2,3} }
4. b 2     {removes 2 from the set }
5. d       
 {prints the size of the unordered set ie 2}

For the second test case 
There are four queries. Queries are performed 
in this order
1. a 1    {inserts 1 to set now set has {1} }
2. a 5    {inserts 5 to set now set 
has {1,5} }
3. d       {prints the size of the set ie 2}
4. c 2    {since 2 is not present in the 
set prints -1}


Note:The Input/Output format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. As it is a function problem, hence a user 
should not read any input from stdin/console. The task is to complete the function specified, and 
not to write the full code.

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* You are required to complete below methods */
/*inserts an element x to the unordered set s */
void insert(unordered_set<int> &s,int x)
{
    if(s.find(x)==s.end())
	    s.insert(x);
}
/*erases an element x from the unordered set s */
void erase(unordered_set<int> &s,int x)
{
	unordered_set<int>::iterator it = s.find(x);
	if(it!=s.end())
	    s.erase(it);
}
/*returns the size of the unordered set s */
int size(unordered_set<int> &s)
{
    return s.size();
}
/*returns 1 if the element x is present
in unordered set s else returns -1 */
int find(unordered_set<int> &s,int x)
{
    return s.find(x)==s.end() ? -1 : 1;
}

int main(){

	return 0;
}
