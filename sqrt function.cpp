// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;

//sqrt function 
unsigned long long sqr(unsigned long long n){
    unsigned long long l=0,r=n,ans;
    while(l<=r){
        unsigned long long mid=(l+r)>>1;
        if(mid*mid<=n){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    long long n;
    cin>>n;
    cout<<sqr(n);

    return 0;
}