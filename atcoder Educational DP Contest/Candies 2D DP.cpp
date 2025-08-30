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

ll dp[100005][102];


void solve(int t){
    //cout<<"Case "<<t<<": ";

    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[0][i]=1;
    }
    dp[0][0]=1;

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            // for(int k=min(i,a[j]);k>=0;k--){
            //     dp[i][j]+=dp[i-k][j-1];
            // }
            int lowLimit=0;
            if(i-min(i,a[j])-1>=0)lowLimit=dp[i-min(i,a[j])-1][j-1];
            dp[i][j]=((dp[i][j-1]-lowLimit + dp[i-1][j])%mod+mod)%mod;
           
        }
    }
    cout<<dp[k][n];










    




    
    



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
