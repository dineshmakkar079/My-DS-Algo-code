/*
Time : Wed Aug 16 2017 22:39:32 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/equal/
Given an array A of integers, find the index of values that satisfy A   B = C   D, where A,B,C

*/

#include <bits/stdc++.h>

using namespace std;

bool isLess(vector<int> a, vector<int> b){
    if(a[0]<b[0] )
        return true;
    else if(a[0]==b[0] && a[1]<b[1] )
        return true;
    else if(a[0]==b[0] && a[1]==b[1] && a[2]<b[2] )
        return true;
    else if(a[0]==b[0] && a[1]==b[1] && a[2]==b[2] && a[3]<b[3])
        return true;
    else
        return false;
}

vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    map<int, vector<pair<int,int> > > m;
    vector<bool> taken(n);
    for(int i=0;i<n;i++){
        taken[i] = false;
    }
    map<int, vector<pair<int,int> > >::iterator it;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            it = m.find(A[i]+A[j]);
            pair<int,int> p(i,j);
            if(it == m.end()){
                // taken[i] = 1; taken[j] = 1;
                vector<pair<int,int> > v;
                v.push_back(p);
                m[A[i]+A[j]] = v;
            }else{
                vector< pair<int,int> > vec = it->second;
                int o,t;
                o = vec[vec.size()-1].first;
                t = vec[vec.size()-1].second;
                if(o!=i && t!=i && t!=j )
                    (it->second).push_back(p);
            }
        }
    }
    vector<int> ans, thisans(4);
    for(it = m.begin(); it != m.end(); it++){
        if((it->second).size() < 2)
            m.erase(it);
        else{
            vector<pair<int,int> > v = it->second;
            thisans[0] = v[0].first;
            thisans[1] = v[0].second;
            thisans[2] = v[1].first;
            thisans[3] = v[1].second;
            // cout << "thisans = " <<  thisans[0] << " " <<thisans[1] << " " <<thisans[2] << " " <<thisans[3] << " " <<endl;
            if(ans.size() == 0)
                ans = vector<int>(thisans);
            else if(isLess(thisans, ans)){
                ans = vector<int>(thisans);
            }
            // cout << "ans = " << ans[0] << " " <<ans[1] << " " <<ans[2] << " " <<ans[3] << " " <<endl;
        }
    }
    return ans;
}

int main(){

	return 0;
}
