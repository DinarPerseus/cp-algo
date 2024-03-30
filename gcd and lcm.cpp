// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;


//gcd
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
//lcm
long long lcm(long long a, long long b){
    return (a/gcd(a,b))*b;
}


int main()
{
    cout<<lcm(8,12);
    return 0;
}