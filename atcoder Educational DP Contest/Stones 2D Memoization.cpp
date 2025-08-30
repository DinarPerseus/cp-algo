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



int dp[100005][2];


int fn(int k, int n,int op, int a[]){
    if(k==0)return (op+1)%2;
    if(k<0)return op;
    if(dp[k][op]!=-1)return dp[k][op];
    int c0=0,c1=0;
    for(int i=1;i<=n;i++){
        if(fn(k-a[i],n,(op+1)%2,a)==0)c0++;
        else c1++;
        if(c0>0&&c1>0)break;
    }
    if(c0>0&&c1>0){
        return dp[k][op]=op;
    }else if(c1==0){
        return dp[k][op]=0;
    }else return dp[k][op]=1;

    

    
    
}


void solve(int t){
    //cout<<"Case "<<t<<": ";
    int n,k;
    cin>>n>>k;
    int a[n+1];

    for(int i=1;i<=n;i++)cin>>a[i];
    memset(dp, -1, sizeof(dp));
    if(fn(k,n,1,a)==1){
        cout<<"First";
    }else{
        cout<<"Second";
    }

    




    
    



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
