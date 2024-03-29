// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;

//if prime[i]==0, then it is a prime number
//begin sieve
bool prime[1000006];
void sieve(){

	prime[0]=prime[1]=1;
	for(int i=2;i*i<1000006;i++){

		if(prime[i])continue;
		for(int j=i*i;j<1000006;j+=i){
			prime[j]=1;
		}

	}
    
}
//end sieve


int main()
{
    sieve();
    return 0;
}
