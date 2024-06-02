//Dinar Perseus 2.0
#include <bits/stdc++.h>
using namespace std;

using ll= long long;

//OR calculation from l to r
//l | l+1 | l+2 | l+3 |-------| r-3 | r-2 | r-1 | r
ll or_ltor(ll l, ll r){

    ll res=0, current_value=1;
    
    while(current_value<=r){
    
        
        if((current_value|l)>=l&& (current_value|l)<=r){
            res=res|current_value;
        }
        if((current_value&l)){
            l=l^current_value;
        }
        current_value*=2;
             
    }
    return res;

}



//X-OR calculation from 0 to n
//0 ^ 1 ^ 2 ^ 3 ^ -------- ^ n
ll xor_0ton(ll n){
    ll res=0, current_value=1;

    while(current_value<=n){
        ll next_current_value=current_value*2;

        int t=(n/next_current_value)*current_value+max((ll)0,((n%next_current_value)-current_value+1));
        if(t&1)res=res|current_value;
        current_value=next_current_value;

    }

    return res;

}




//X-OR calculation from l to r
//l ^ l+1 ^ l+2 ^ l+3 ^-------^ r-3 ^ r-2 ^ r-1 ^ r
ll xor_ltor(ll l, ll r){
    return xor_0ton(l-1)^xor_0ton(r);

}








int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cout<<or_ltor(5,9)<<'\n';
    cout<<xor_0ton(9)<<"\n";
    cout<<xor_ltor(5,9)<<"\n";
    
    
    
    return 0;
}