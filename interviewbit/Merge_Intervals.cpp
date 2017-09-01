/*
Time : Thu Aug 31 2017 18:38:05 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/merge-intervals/
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You 
may assume that the intervals were initially sorted according to their start times.

Example 1:

Given 
intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], 
insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] 
overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool isoverlap(Interval one ,Interval two){
    if(one.start > two.end || two.start > one.end)
        return false;
    return true;
}

bool comp(Interval one ,Interval two);
vector<Interval> merge(vector<Interval> &A) {
    vector<Interval> ret;
    int n = A.size();
    for(int i=0;i<n;i++){
        Interval thisin(A[i].start,A[i].end);
        while(i+1<n&&isoverlap(thisin,A[i+1])){
            thisin.start = thisin.start < A[i+1].start ? thisin.start : A[i+1].start;
            thisin.end = thisin.end > A[i+1].end ? thisin.end : A[i+1].end;
            i++;
        }
        ret.push_back(thisin);
    }
    return ret;
}

vector<Interval> Solution::insert(vector<Interval> &A, Interval ni) {
    vector<Interval> ret;
    int n = A.size();
    vector<Interval> vec(n+1);
    vector<Interval>& v = vec;
    int i=0;
    while(i<n && A[i].start < ni.start){
        v[i] = A[i];i++;
    }
    v[i] = ni;
    while(i<n){
        v[i+1] = A[i];i++;
    }
    return merge(v);
}

int main(){

	return 0;
}
