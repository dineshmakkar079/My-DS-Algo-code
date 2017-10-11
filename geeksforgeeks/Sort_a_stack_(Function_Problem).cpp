/*
Time : Mon Oct 02 2017 21:55:38 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/sort-a-stack/1
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Input:
The 
first line of input will contains an integer T denoting the no of test cases . Then T test cases 
follow. Each test case contains an integer N denoting the size of the stack. Then in the next line 
are N space separated values which are pushed to the the stack. 

Output:
For each test case output 
will be the popped elements from the sorted stack.

Constraints:
1<=T<=100
1<=N<=100

Example(To 
be used only for expected output):
Input:
2
3
3 2 1
5
11 2 32 3 41

Output:
3 2 1
41 32 11 3 2

Explanation:
For 
first test case stack will be
1
2
3
After sorting 
3
2 
1

When elements  popped : 3 2 1

Note:The 
Input/Ouput format and Example given are used for system's internal purpose, and should be used 
by a user for Expected Output only. As it is a function problem, hence a user should not read any 
input from stdin/console. The task is to complete the function specified, and not to write the full 
code.

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
/* The below method sorts the stack s 
you are required to complete the below method */

void insert(SortedStack* st,int toin){
    if((st->s).empty()){
        (st->s).push(toin);
        return;
    }
    int t = (st->s).top();
    if(t <= toin){
        (st->s).push(toin);
        return;
    }else{
        (st->s).pop();
        insert(st,toin);
        (st->s).push(t);
        return;
    }
}

void SortedStack::sort()
{
    if(!((this->s).empty())){
        int t = (this->s).top();
        (this->s).pop();
        this->sort();
        insert(this,t);
    }
}

int main(){

	return 0;
}
