// Dinar Perseus 2.0
#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast,unroll-loops,-ffloat-store")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#define ll long long int
using namespace std;
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

// code gose here
void solve(int t)
{
    // cout<<"Case "<<t<<": ";
    ll n,m,max_currency=0;
    cin>>n>>m;

    //input all the currency
    ll a[m];
    for (int i = 0; i < m; i++)
    {
        cin>>a[i];
        max_currency=max(max_currency,a[i]);
    }

    //building the initial dp
    sort(a,a+m);
    ll dp[max_currency]{};
    for (int i = 0; i < max_currency; i++)
    {
        for(int j=0;j<m;j++){
            if(i-a[j]>=0)dp[i]=(dp[i]+dp[i-a[j]])%mod;
            else if (i-a[j]==-1)dp[i]=(dp[i]+1)%mod;
        }
    }
    reverse(dp,dp+max_currency);

    if(n<=max_currency){
        cout<<dp[max_currency-n]<<'\n';
        return;
    }

    //building the initial matrix
    vector<vector<ll>> A(max_currency,vector<ll>(max_currency,0));
    for(auto x:a)A[0][x-1]=1;
    for (int i = 1; i < max_currency; i++)A[i][i-1]=1;
    
    //building the final matrix
    A=matrix_pow(A,n-max_currency);

    //multiplying the final matrix with the initial dp
    ll ans=0;
    for (int i = 0; i < max_currency; i++)ans=(ans+A[0][i]*dp[i])%mod;
    cout<<ans<<'\n';
    
}



int main()
{
    fileio();
    fastio();
    // clock_t z = clock();
    int t = 1;
    //cin>>t;
    for (int i = 1; i <= t; i++)solve(i);
    // cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);
    return 0;
}
