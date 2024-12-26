//Dinar Perseus 2.0
#include <bits/stdc++.h>
using namespace std;
using ll= long long;

//X-OR calculation from 0 to n
//0 ^ 1 ^ 2 ^ 3 ^ -------- ^ n
ll xor_0ton(ll n){
    if(n%4==0){
        return n;
    }else if(n%4==1){
        return 1;
    }else if(n%4==2){
        return n+1;
    }else{
        return 0;
    }

}

//X-OR calculation from l to r
//l ^ l+1 ^ l+2 ^ l+3 ^-------^ r-3 ^ r-2 ^ r-1 ^ r
ll xor_ltor(ll l, ll r){
    return xor_0ton(l-1)^xor_0ton(r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll l, r;
    cin >> l >> r;
    cout << xor_ltor(l, r) << endl;
    return 0;
}