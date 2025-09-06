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






int N;


//digit dp
int dp[10004][100][2];


//here f is a fixed value, if f==1 then 
//it's a fixed degit calculation 
//otherwise it's can go up to digit 9
int fn(int p,int sum,int f,string &s){
    if(p==s.size()){
        if(sum==0)return 1;
        else return 0;
    }
    if(dp[p][sum][f]!=-1)return dp[p][sum][f];
    if(f){
        ll tc=0;
        for(int i=0;i<=s[p]-'0';i++){
            if(i==s[p]-'0')tc+=fn(p+1,(sum+i)%N,1,s);
            else tc+=fn(p+1,(sum+i)%N,0,s);
        }
           return dp[p][sum][f]=tc%mod;
    }else {
        ll tc=0;
        for(int i=0;i<=9;i++){
            tc+=fn(p+1,(sum+i)%N,0,s);
        }
        return dp[p][sum][f]=tc%mod;
    }


}






void solve(int t){
    //cout<<"Case "<<t<<": ";
    string s;
    cin>>s;
    cin>>N;
    memset(dp,-1,sizeof(dp));
    cout<<(fn(0,0,1,s)-1+mod)%mod;



















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
