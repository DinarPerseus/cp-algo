//Dinar Perseüs 2.0
//never creat your alternative 
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <set>
#include <string>
#include <utility>
#include <vector>
#pragma GCC optimize ("Ofast,unroll-loops,-ffloat-store")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#define fo(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll=long long;
const int mod = 1e9+7;

template <typename T>
struct comp{
    bool operator()(const T &a, const T &b) const{
        return a.first+a.second<b.first+b.second;
    }
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








class Graph{
    private:
    int n;
    vector<int> *adj;

    public:
    Graph(int n){
        this->n = n;
        adj = new vector<int> [n];
    }
    void addEdge(int& u, int& v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


};




//matrix multiplication
vector<vector<ll>> matrix_mul(vector<vector<ll>> &a,vector<vector<ll>> &b){
    int n=a.size();
    vector<vector<ll>> c(n,vector<ll>(n,0));
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }
    return c;
}

//matrix exponentiation
vector<vector<ll>> matrix_pow(vector<vector<ll>> a,ll b){
    int n=a.size();
    vector<vector<ll>> res(n,vector<ll>(n,0));
    for (int i = 0; i < n; i++)
    {
        res[i][i]=1;
    }
    while (b>0)
    {
        if(b&1)res=matrix_mul(res,a);
        a=matrix_mul(a,a);
        b/=2;
    }
    return res;
}







void solve(int t){
    //cout<<"Case "<<t<<": ";
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> a(n, vector<ll>(n));
    
    fo(i,n)fo(j,n)cin>>a[i][j];
    vector<vector<ll>> ans=matrix_pow( a, k);

    ll v=0;
    fo(i,n)fo(j,n)v+=ans[i][j];

    cout<<v%mod;









    




















}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
