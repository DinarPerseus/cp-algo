#include <bits/stdc++.h>
using namespace std;


//this is the solution of 
//https://atcoder.jp/contests/dp/tasks/dp_s

using ll= long long;
int mod = 1000000007;
int N;


//digit dp
int dp[10004][100][2];

//here f is a fixed value, if f==1 then 
//it's a fixed degit calculation 
//otherwise it's can go up to digit 9
int fn(int p,int sum,int f,string &s){
    if(p==s.size()){
        if(sum==0)return 1;
        else return 0;
    }
    if(dp[p][sum][f]!=-1)return dp[p][sum][f];
    if(f){
        ll tc=0;
        for(int i=0;i<=s[p]-'0';i++){
            if(i==s[p]-'0')tc+=fn(p+1,(sum+i)%N,1,s);
            else tc+=fn(p+1,(sum+i)%N,0,s);
        }
           return dp[p][sum][f]=tc%mod;
    }else {
        ll tc=0;
        for(int i=0;i<=9;i++){
            tc+=fn(p+1,(sum+i)%N,0,s);
        }
        return dp[p][sum][f]=tc%mod;
    }


}







int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    
    
    string s;
    cin>>s>>N;
    
    cout<<(fn(0,0,1,s)-1+mod)%mod<<'\n';
    
    
    
    
    
	
}
    
