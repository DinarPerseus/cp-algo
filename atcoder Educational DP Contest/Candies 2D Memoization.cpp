#include <bits/stdc++.h>
using namespace std;


using ll= long long;
int mod = 1000000007;

ll dp[101][100005];

ll fn(int n, int k,int a[]){
    if(n==0){
        if(k==0) return 1;
        else return 0;
    
    }
    if(k<0) return 0;
    else if(dp[n][k]!=-1) return dp[n][k];
    else {
        
        ll c=0;
        c=fn(n-1,k,a)-fn(n-1,k-a[n-1]-1,a)+fn(n,k-1,a);
        /*
        for(int i=0;i<=a[n-1];i++){
            c+=fn(n-1,k-i,a);
            c%=mod;
        
        }
        */
        return dp[n][k]=(c+mod)%mod;
    }
    

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    
    
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    
    cout<<fn(n,k,a);
    
    
    
    
	
}
    