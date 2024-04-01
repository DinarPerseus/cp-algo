// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;


const int N = 200005;
const long long prime = 31;
const int mod = 1e9+9;
long long p[N];

//prime power calculation with memoization
long long prime_power(int n){
    if(p[n]!=0) return p[n];
    if(n>0){
        return p[n]=(prime_power(n-1)*prime)%mod;
    }else {
        return p[n]=1;
    }
}



//hash calculation for each index of a string
vector<long long> Hash(string &s){
    
    
    int n = s.size();
    vector<long long> v(n);
    long long hash_value=0;
    
    for(int i=0;i<n;i++){
        v[i]=hash_value=(hash_value+(s[i]-'a'+1)*prime_power(i))%mod;
    }
    
    return v;

}




int main()
{
    string s="perseus";
    vector<long long> v=Hash(s);
    for(auto x:v)cout<<x<<" ";

    return 0;
}