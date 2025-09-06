//Dinar Perseüs 2.0
//never creat your alternative 
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <set>
#include <string>
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
        return a.first.second<b.first.second;
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


ll dp[100005][2];



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
    void dfs(int u, int p){
        dp[u][0]=dp[u][1]=1;

        for(auto& v:adj[u]){
            if(v!=p){
                dfs(v, u);
                dp[u][0]=(dp[u][0]*(dp[v][0]+dp[v][1]))%mod;
                dp[u][1]=(dp[u][1]*dp[v][0])%mod;
            } 
        }


    }

};






void solve(int t){
    //cout<<"Case "<<t<<": ";

    int n,u,v;
    cin>>n;

    Graph g(n+1);

    fo(i,n-1){
        cin>>u>>v;
        g.addEdge(u, v);
    }

    g.dfs(1, 0);
    cout<<(dp[1][0]+dp[1][1])%mod;















    




    
    



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
