// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;

//if prime[i]==i, then it is a prime number
//being sieve
const int N=100005;
int prime[N];
void sieve(){

	prime[0]=prime[1]=1;
	for(long long i=2;i<N;i++){

		if(prime[i])continue;
        prime[i]=i;
		for(long long j=i*i;j<N;j+=i){
			if(prime[j]==0)prime[j]=i;
		}

	}
    
}

//end sieve



//being sieve prime_factorisation
vector<pair<int,int>> prime_factorisation(int n){
	
    vector<pair<int,int>> v;
	while(n!=1){
		int cnt=0;
		int p=prime[n];
		while(p==prime[n]){
			cnt++;
			n/=prime[n];
		}
		v.push_back({p,cnt});
		//cout<<p<<" "<<cnt<<endl;
	}
	return v;
}
//end prime_factorisation



int main()
{
    sieve();
	for(auto x:prime_factorisation(50))cout<<x.first<<" "<<x.second<<endl;
    return 0;
}