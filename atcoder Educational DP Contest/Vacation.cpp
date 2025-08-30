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








void solve(int t){
    //cout<<"Case "<<t<<": ";
    int n,a,b,c;
    cin>>n;
    int dp[n+1][3];
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for (int i=1; i<=n; i++) {
        cin>>a>>b>>c;
        dp[i][0]=a+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=b+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=c+max(dp[i-1][1],dp[i-1][0]);
    
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));








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
