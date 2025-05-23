// Dinar Perseus 2.0
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <utility>
#include <vector>
#pragma GCC optimize ("Ofast,unroll-loops,-ffloat-store")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#define ll long long int
#define fo(i, n) for (int i = 0; i < n; i++)
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define nl cout<<'\n'
#define pu push_back
#define po pop_back
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define in insert
#define fi first
#define se second
#define dbg1(x) cerr << '#' << #x << " = " << x << '\n'
#define dbg2(x, y) cerr << '#' << #x << " = " << x << "    &    #" << #y << " = " << y << '\n'
#define dbg3(x, y, z) cerr << '#' << #x << " = " << x << "    &    #" << #y << " = " << y << "    &    #" << #z << " = " << z << '\n'
#define all(x) x.begin(), x.end()
using namespace __gnu_pbds;
using namespace std;
template<class T> using  oset= tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
ll left_shift[63]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656, 562949953421312, 1125899906842624, 2251799813685248, 4503599627370496, 9007199254740992, 18014398509481984, 36028797018963968, 72057594037927936, 144115188075855872, 288230376151711744, 576460752303423488, 1152921504606846976, 2305843009213693952, 4611686018427387904};
// constant
const int mod = 1e9 + 7;
void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void fileio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}



bool comp(pii x,pii y){
    return (x.first<y.first)||((x.first==y.first)&&(x.second>y.second));
}


//graph
class graph
{
    int n;
    //vector<int> *adj;
     vector<int> *adj;

public:
    graph(int v){
        n=v;
        //adj=new vector<int>[v];
        adj=new vector<int>[v];
    }

    void addedge(ll u, ll v){
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }

    // void addedge(int u, int v, int w){
    //     adj[u].push_back({v,w});
    //     //adj[v].push_back({u,w});
    // }


};



// Binary Exponentiation
ll pow(ll a,ll b,ll m){
    ll value=1;
    while (b>0)
    {
        if (b&1)
        {
            value=(value*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }

    return value;
}

//gcd
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}




ll dp[20][180][2][2];

ll fn(int p,int sum,int f1,int f2,string s1,string s2){
    if(p==s1.size())return sum;

    if(dp[p][sum][f1][f2]!=-1)return dp[p][sum][f1][f2];
    ll temp_sum=0;
    int start=(f1)?s1[p]-'0':0;
    int end=(f2)?s2[p]-'0':9;

    for(int i=start;i<=end;i++){
        temp_sum+=fn(p+1,sum+i,f1&(i==s1[p]-'0'),f2&(i==s2[p]-'0'),s1,s2);
    }

    return dp[p][sum][f1][f2]=temp_sum;

}



// code gose here
void solve(int t)
{
    // cout<<"Case "<<t<<": ";

    
}



int main()
{
    fileio();
    fastio();
    // clock_t z = clock();
    int t = 1;

    cin>>t;
    int k=1;


    while (t--)
        solve(k++);
    // cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);
    return 0;
}
