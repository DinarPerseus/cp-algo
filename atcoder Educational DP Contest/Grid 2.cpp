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



ll fact[200005],inv_fact[200005];



ll ncr(int n, int r){
    return ((fact[n]*inv_fact[r])%mod*inv_fact[n-r])%mod;
}



void solve(int t){
    //cout<<"Case "<<t<<": ";
    int h,w,n,m;
    cin>>h>>w>>n;
    m=max(h,w);

    //calculation of fact and inv_fact
    fact[0]=inv_fact[0]=1;
    for(int i=1;i<=200005; i++){
        fact[i]=i*fact[i-1]%mod;
        inv_fact[i]=pow(fact[i],mod-2,mod);
    }

    vector<pair<int,int>> v(n+1);
    fo(i,n)cin>>v[i].first>>v[i].second;
    v[n]={h,w};
    sort(v.begin(),v.end(),comp<pair<int, int>>());

    ll dp[n+1];

    for(int i=0;i<=n;i++){
        auto [x,y]=v[i];
        dp[i]=ncr(x+y-2,x-1);
        for(int j=0;j<i; j++){
            auto [xx,yy]=v[j];
            if(xx<=x&&yy<=y){
                dp[i]=(dp[i] - dp[j]*ncr(x-xx+y-yy, x-xx)%mod +mod)%mod;
            }

        }
    }
    cout<<dp[n];















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
