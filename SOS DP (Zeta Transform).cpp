// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
void fileio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
} 

int dp1[1<<20],dp2[1<<20];
//sos dp
void solve(int t){
    int n;
    cin>>n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        dp1[a[i]]++;
        dp2[a[i]]++;
    }



    for (int k = 0; k < 20; k++)
    {
        for (int mask = 0; mask < (1<<20); mask++)
        {
            if ((mask)&(1<<k))
            {
                //Submask DP (Zeta Transform)
                dp1[mask]+=dp1[(mask)^(1<<k)];
            }else{
                //Supermask DP (Zeta Transform)
                dp2[mask]+=dp2[(mask)|(1<<k)];
            }
            
        }
        
    }

    int mask=(1<<20)-1;


    for (int i = 0; i < n; i++)
    {
        cout<<dp1[a[i]]<<" "<<dp2[a[i]]<<" "<<n-dp1[mask^a[i]]<<'\n';
    }
    
    


}



int main()
{
    fileio();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // clock_t z = clock();
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)solve(i);
    // cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);
    return 0;
}
