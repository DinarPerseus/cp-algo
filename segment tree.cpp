// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;


const int N=200005;
#define ll long long
 
//segment tree 
ll seg[N];
ll lazy[N];
 
//build segment tree 
void build(int p, int a[], int l, int r){
    //lazy[p]=0;

    if(l==r){

        seg[p]=0;
        return;
    }

    int mid=(l+r)>>1;
    build(2*p, a, l, mid);
    build(2*p+1, a, mid+1, r);
    seg[p]=seg[2*p]+seg[2*p+1];
 
}
 
//lazy propagation for range sum
void propagate(int p,int l,int r){
    int mid=(l+r)>>1;
    lazy[2*p] = lazy[2*p]+lazy[p];
    lazy[2*p+1] = lazy[2*p+1]+lazy[p];
    seg[2*p] = seg[2*p]+lazy[p]*(mid-l+1);
    seg[2*p+1] = seg[2*p+1]+lazy[p]*(r-(mid+1)+1);
    lazy[p] = 0;
    
}
 
//update segment
void update(int p, int l, int r, int s, int e, ll v){
    if(s>r||e<l) return;
    if(s<=l&&r<=e) {
        //lazy[p]=lazy[p]+v;
        seg[p]=(seg[p]+v)%1000000007;
        return;
    }
    
    //propagate(p,l,r);
    
    int mid=(l+r)>>1;
    update(2*p, l, mid, s, e, v);
    update(2*p+1, mid+1, r, s, e, v);
    seg[p]=(seg[2*p]+seg[2*p+1])%1000000007;
    
}
 
//query segment tree
ll query(int p, int l, int r, int s, int e){
    if(s>r||e<l) return 0;
    if(s<=l&&r<=e) return seg[p];
    
    //propagate(p,l,r);
    
    int mid=(l+r)>>1;
    ll x=query(2*p, l, mid, s, e);
    ll y=query(2*p+1, mid+1, r, s, e);
    return (x+y)%1000000007;
 
 
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"dinar";
   

    return 0;
}