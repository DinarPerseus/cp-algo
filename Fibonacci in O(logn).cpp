// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;


//formula 
// F(n) = F(n-1) + F(n-2)
// F(n+1) = F(n) + F(n-1)
// F(n+k) = F(n)*F(k+1) + F(k)*F(n-1)
// F(2*n) = F(n) x {F(n+1) + F(n-1)}
//for even number F(2*n) = F(n) x {2*F(n+1) - F(n)}
//for odd number  F(2*n+1) = F(n+1)^2 + F(n)^2
//Fibonacci in O(logn)
// The above code returns F(n) and F(n+1) as a pair.
pair<long long, long long> fib (int n) {
    if (n == 0)
        return {0, 1};

    pair<long long, long long> p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}


int main()
{
    int n;
    cin>>n;
    cout<<fib(n).first;
    return 0;
}