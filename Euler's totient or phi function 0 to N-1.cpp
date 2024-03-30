// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;

//Euler's totient or phi function 0 to N-1
const int N=100005;
int phi[N];
void calculate_phi() {
    
    for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2; i < N; i++) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}


int main()
{
    calculate_phi();
    for(int i=0;i<=100;i++)cout<<phi[i]<<" ";
    return 0;
}