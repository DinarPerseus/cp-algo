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



double dp[301][301][301];


void solve(int t){
    //cout<<"Case "<<t<<": ";
    int n,x;
    cin>>n;
    int c[4]{};
    fo(i,n){
        cin>>x;
        c[1]+=x==1;
        c[2]+=x==2;
        c[3]+=x==3;
    }

    //here P(x2)=count the number of plate that contain 2 sushi/total number of plate
    //=>P(x2)=x2/n


    //E(x3,x2,x1)=1 + P(x3)*E(x3-1,x2+1,x1)+ P(x2)*E(x3,x2-1,x1+1)+ P(x1)*E(x3,x2,x1-1) + P(x0)*E(x3,x2,x1)
    //=>E(x3,x2,x1)={ 1 + P(x3)*E(x3-1,x2+1,x1) + P(x2)*E(x3,x2-1,x1+1) + P(x1)*E(x3,x2,x1-1)} / {1-P(x0)}
    //=>E(x3,x2,x1)={n + x3*E(x3-1,x2+1,x1) + x2*E(x3,x2-1,x1+1) + x1*E(x3,x2,x1-1)}/{x1+x2+x3}

    for(int i=0; i<= c[3];i++){
        for(int j=0;j<=c[2]+c[3];j++){
            for(int k=0;k<=c[1]+c[2]+c[3];k++){
                if(i==0&&j==0&&k==0)dp[i][j][k]=0;
                else{
                    double up=n;
                    if(i) up+=i*dp[i-1][j+1][k];
                    if(j) up+=j*dp[i][j-1][k+1];
                    if(k) up+=k*dp[i][j][k-1];
                    up/=(i+j+k);                 
                    dp[i][j][k]=up;
                    

                }
            }
        }
    }

    cout<<fixed<<setprecision(10);
    cout<<dp[c[3]][c[2]][c[1]];



    
    



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
