// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;


// Binary Exponentiation
long long pow(long long a,long long b,long long m){
    long long value=1;
    while (b>0)
    {
        if (b&1)
        {
            value=(value*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return value;
}

int main()
{
    cout<<pow(2,3,100);
    return 0;
}