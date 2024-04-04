// Dinar Perseüs 2.0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;



//array compression or index compression using map
// O(nlong(number of unique item))
void compress(int a[],int n){
    int cnt=0;
    map<int,int> mp;

    for(int i=0;i<n;i++) {
        if(mp[a[i]]) {
            a[i]=mp[a[i]];
            continue;
        }
        mp[a[i]]=++cnt;
        a[i]=cnt;
    }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=8;
    int a[n]={4, 251, 2, 4, 251, 1, 2, 8};
    compress(a,n);
    for(auto x:a)cout<<x<<" ";
    cout<<'\n';


    return 0;
}