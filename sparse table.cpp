// Dinar Perseüs 2.0
#include <bits/stdc++.h>
#define ll long long
using namespace std;

//sparse table used for static (no update) range query..
//this is a sparse table for range minimum value query
//this code used 1 based index
const int N = 1000006;
int st[N][20];



//this function used O(nlogn) to build 
void build_sparse(int a[], int n){
    //initialize the 2^0 segment 
    for(int i=1;i<=n;i++)st[i][0]=a[i];
    
    //calculate the rest of the sparse table
    //for calculation of st[i][k], 
    //we have to calculate the s[i][k-1]
    //here i= 1, 2, 3, 4, .......... , n
    int m=log2(n)+1;
    for(int k=1;k<m;k++){
        for(int i=1;i<= n-(1<<k)+1;i++){
            st[i][k]=min( st[i][k-1], st[i+ (1<<(k-1))][k-1]);
        }
    }


}


//this function works for any range query 
int query_sparse(int l, int r){
    
    int def=r-l+1;
    int k=0,m=1e9;
    
    //finding the results in O(logn)
    while(def){
        if(def&1){
            m=min(m,st[l][k]);
            l+=(1<<k);
        }
        k++;
        def>>=1;
    }
    
    return m;
}


//this function only work for min, max, gcd query
int query_const(int l, int r){
    int def=r-l+1, k=0;
    
    //finds the greatest 2^k that fits in the range difference
    while(def>=(1<<(k+1)))k++;
    
    return min( st[l][k], st[r-(1<<k)+1][k]);
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a[17]={0, 1 ,3 ,5 ,7 ,9, 2, 4, 6, 0, 8, 10, -19, 100, 99, 0 , 17};
    build_sparse(a,16);
    cout<<query_sparse(13,14)<<'\n';
    cout<<query_const(13,14)<<'\n';
   

    return 0;
}