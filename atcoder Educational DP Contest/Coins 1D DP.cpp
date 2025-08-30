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






double dp[3000];



void solve(int t){
    //cout<<"Case "<<t<<": ";
    int n;
    cin>>n;

    double ph[n+1],sum=0;
    for(int i=1;i<=n;i++)cin>>ph[i];

    dp[0]=1;

    
    

    for(int i=1;i<=n;i++){
        for(int j=i; j>=0 ; j--){
            if(j==0){
                dp[j]=dp[j]*(1-ph[i]);
            }else dp[j]=dp[j]*(1-ph[i])+dp[j-1]*ph[i];
        }
       
    }
    cout << fixed << setprecision(10);


    for(int i=(n+1)/2; i<=n; i++)sum+=dp[i];
    cout<<sum<<endl;


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
