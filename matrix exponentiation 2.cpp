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
template<typename K, typename V> using ordermap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
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


template <typename T>
struct comp
{
    bool operator()(const T & a, const T &b)const{
        return a < b;
    }
};


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

//lcm
ll lcm(ll a, ll b){
    return (a/gcd(a,b))*b;
}



vector<vector<ll>> matrix_mult(vector<vector<ll>> &a, vector<vector<ll>> &b){

    int n=a.size();
    int m=b[0].size();
    int p=a[0].size();
    vector<vector<ll>> res(n, vector<ll>(m,0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                res[i][j]=(res[i][j]+(a[i][k]*b[k][j])%mod)%mod;
            }
        }
        
    }


    return res;
}




vector<vector<ll>> matrix_pow(vector<vector<ll>> &a, ll n){

    int sz=a.size();
    vector<vector<ll>> res(sz, vector<ll>(sz,0));
    for (int i = 0; i < sz; i++)res[i][i]=1;

    while (n>0)
    {
        if (n&1)
        {
            res=matrix_mult(res,a);

        }
        a=matrix_mult(a,a);
        n>>=1;

    }

    return res;
}


// code gose here
void solve(int t)
{
    // cout<<"Case "<<t<<": ";


    ll n; cin>>n;
    vector<vector<ll>> a={
        {1, 1},
        {1, 0}
    };

    vector<vector<ll>> f={
        {1},
        {0}
    };
    

    if(n<2){
        cout<<f[1-n][0]<<'\n';
        return;
    }


    vector<vector<ll>> ans=matrix_pow(a,n-1);
    vector<vector<ll>> res=matrix_mult(ans,f);
    cout<<res[0][0]<<'\n';







    











    
}



int main()
{
    fileio();
    fastio();
    // clock_t z = clock();
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)solve(i);
    // cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);
    return 0;
}
