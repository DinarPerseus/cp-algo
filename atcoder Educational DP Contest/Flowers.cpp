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





const int N=800005;
 
//segment tree 
ll seg[N];

 

 

//update segment
void update(int p, int l, int r, int s, int e, ll v){
    if(s>r||e<l) return;
    if(s<=l&&r<=e) {
        seg[p]=v;
        return;
    }
    
    int mid=(l+r)>>1;
    update(2*p, l, mid, s, e, v);
    update(2*p+1, mid+1, r, s, e, v);
    seg[p]=max(seg[2*p],seg[2*p+1]);
    
}
 
//query segment tree
ll query(int p, int l, int r, int s, int e){
    if(s>r||e<l) return 0;
    if(s<=l&&r<=e) return seg[p];
    
    int mid=(l+r)>>1;
    ll x=query(2*p, l, mid, s, e);
    ll y=query(2*p+1, mid+1, r, s, e);
    return max(x,y);
 
 
}





void solve(int t){
    //cout<<"Case "<<t<<": ";

    int n;
    cin>>n;
    int h[n+1], a[n+1];
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }


    for(int i=1;i<=n;i++){
        ll v=query(1,1,n, 1, h[i]);
        update(1,1,n,h[i],h[i],v+a[i]);

    }

    cout<<query(1,1,n,1,n);

















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
