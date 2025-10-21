// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
void fileio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
} 


//kmp
vector<int> kmp(string &s){
    int n= s.size(), j=0;
    vector<int> pi(n);

    for (int i = 1; i < n; i++)
    {
        j=pi[i-1];
        while (j>0 && s[j]!=s[i])
        {
            j=pi[j-1];
        }

        if(s[j]==s[i])j++;
        pi[i]=j;
    }

    return pi;

}


void solve(int t){
    string n,m;

    int c=0;
    cin>>n>>m;
    m.push_back('#');
    vector<int> pi=kmp(m);

    int ans[n.size()+1]{};

    for (int i = 0; i < n.size(); i++)
    {
        int j=ans[i];
        while (j>0 && m[j]!=n[i])
        {
            j=pi[j-1];

        }
        if(m[j]==n[i])j++;
        ans[i+1]=j;
        if(j==m.size()-1)c++;

    }
   
    cout<<c;
    




    


}



int main()
{
    fileio();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // clock_t z = clock();
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)solve(i);
    // cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);
    return 0;
}