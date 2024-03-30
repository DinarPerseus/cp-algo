// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;

//being devisor calculation
const int N=100005;
vector<vector<int>> factors(N,{1});
void devisor(){

	for(long long i=2;i<N;i++){

		for(long long j=i;j<N;j+=i){
			factors[j].push_back(i);
		}

	}
    
}
//end devisor calculation



int main()
{
    devisor();
	for(auto x:factors[1000])cout<<x<<" "<<endl;
    return 0;
}