/*
Time : Sat Jul 01 2017 23:19:26 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/min-stack/#
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x)
– Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top
element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have
to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do
on empty stack?
A: In this case, return -1.

Q: What should pop do on empty stack?
A: In this
case, nothing.

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If you
are using your own declared global variables, make sure to clear them out in the constructor.

*/

stack<int> mains;
stack<int> aux;

MinStack::MinStack() {
    while(!mains.empty()){mains.pop();aux.pop();}
}

void MinStack::push(int x) {
    mains.push(x);
    if(aux.empty()){
        aux.push(x);
    }else{
        aux.push(x < aux.top() ? x : aux.top());
    }
}

void MinStack::pop() {
    if(!mains.empty()){
        mains.pop();
        aux.pop();
    }
}

int MinStack::top() {
    if(!mains.empty()){
        return mains.top();
    }
    return -1;
}

int MinStack::getMin() {
    if(!mains.empty()){
        return aux.top();
    }
    return -1;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
