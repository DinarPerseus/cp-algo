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



//hash calculation for the string
long long Hash(string &s){
    
    
    int n = s.size();
    long long hash_value=0;
    
    for(int i=0;i<n;i++){
        hash_value=(hash_value+(s[i]-'a'+1)*prime_power(i))%mod;
    }
    
    return hash_value;

}







int main()
{
    string s="dinar";
    cout<<Hash(s);


    return 0;
}