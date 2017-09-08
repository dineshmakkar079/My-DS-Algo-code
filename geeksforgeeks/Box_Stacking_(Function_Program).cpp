/*
Time : Thu Sep 07 2017 15:48:14 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/box-stacking/1
You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w 
and length l. You task is to create a stack of boxes which is as tall as possible, but you can only 
stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly 
larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any 
side functions as its base.It is also allowable to use multiple instances of the same type of box. 
You task is to complete the function maxHeight which returns the height of the highest possible 
stack so formed.

Input:
The first line of input contains an integer T denoting the no of test cases 
then T test cases follow . Each test case contains an integer N denoting the total no of boxes available. 
In the next line are 3*N space separated values denoting the height width and length of the N boxes.

Output:
For 
each test case in a new line output will be the highest possible stack height which could be formed.

Constraints:
1<=T<=100
1<=N<=100
1<=l,w,h<=100

Example 
(To be used for expected output) :
Input:
2
4
4 6 7 1 2 3 4 5 6 10 12 32
3
1 2 3 4 5 6 3 4 1

Output
60
15


Note:The 
Input/Ouput format and Example given are used for system's internal purpose, and should be used 
by a user for Expected Output only. As it is a function problem, hence a user should not read any 
input from stdin/console. The task is to complete the function specified, and not to write the full 
code.

**For More Examples Use Expected Output**

*/

/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
#define vi vector<int>
#define vvi vector<vi>
#define ip pair<int,int>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vl vector<long long>
#define vvl vector<vl>
#define vr vector
#define init(a, n, v) for (int i=0;i<n;i++) a[i]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

struct st{
    int l;
    int w;
    int h;
};
typedef struct st box;
bool comp(box l,box r){
    return (l.l*l.w > r.l*r.w);
}

int maxHeight(int h[],int w[],int l[],int n)
{
    box v[3*n];
    for(int i=0;i<n;i++){
        v[3*i+0].l = max(l[i],w[i]); v[3*i+0].h = h[i]; v[3*i+0].w = min(l[i],w[i]);
        v[3*i+1].l = max(l[i],h[i]); v[3*i+1].h = w[i]; v[3*i+1].w = min(h[i],l[i]);
        v[3*i+2].l = max(h[i],w[i]); v[3*i+2].h = l[i]; v[3*i+2].w = min(h[i],w[i]);
    }
    sort (v, v+3*n,  comp);
    vr<int> mem(3*n);
    mem[0] = v[0].h;
    int ans = v[0].h;
    for(int i=1;i<3*n;i++){
        mem[i] = v[i].h;
        for(int j=0;j<i;j++){
            if(v[j].l>v[i].l&&v[j].w>v[i].w){
                mem[i] = max(mem[i], mem[j] + v[i].h);
            }
        }
        ans = max(ans, mem[i]);
    }
    mem.clear();
    return ans;
}