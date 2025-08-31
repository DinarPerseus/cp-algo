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
    }




};

ll dp[1<<21][22];
bool a[22][22];

ll fn(int in, int mask, int n){
    if(in==0)return 1;
    if( dp[mask][in]!=-1)return  dp[mask][in];
    ll r=0;
    for(int i=0;i<n; i++){
        if((mask&(1<<i))==0&&a[in][i+1])r+=fn(in-1,(mask|(1<<i)),n);
    }
    return dp[mask][in]=r%mod;

}


void solve(int t){
    //cout<<"Case "<<t<<": ";
    int n;
    cin>>n;

    memset(dp,-1,sizeof(dp));

    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
    
    cout<<fn(n,0,n);












    




    
    



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
