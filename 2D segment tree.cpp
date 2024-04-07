// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;


const int N=4005;
const int M=4005;

#define ll long long
 
//segment tree 
ll seg[N][M];
int a[N/4][M/4];

//build segment tree for a single row..
//pr=parent node of rows
//lr,rr is the is the node range for row
//pc=parent node of collum
//lc,rc is the node range for collum
void build(int pr, int lr, int rr, int pc, int lc, int rc){
    
    if(lc==rc){
        if(lr==rr){
            //abstract data from array..and build the leaf node of segment tree
            seg[pr][pc]=a[lr][lc];
            
        }else{
            //abstract data from child row ..and build the parent row
            seg[pr][pc]=seg[2*pr][pc]+ seg[2*pr+1][pc];
        }
        return;
    }
    
    int mid = (lc+rc)>>1;
    build(pr, lr, rr, 2*pc, lc, mid);
    build(pr, lr, rr, 2*pc+1, mid+1, rc);
    
    seg[pr][pc]=seg[pr][2*pc]+ seg[pr][2*pc+1];



}


//c = Collum size of the array,
//this will use when we call build in collum level 
//this will become rc
 
//build segment tree in row level
void build_r(int pr, int lr, int rr, int c){
    

    if(lr==rr){
        //thic build call for collum level call..
        //or a single row call..
        build(pr, lr, rr, 1, 1, c);
        return;
    }

    int mid=(lr+rr)>>1;
    build_r(2*pr, lr, mid, c);
    build_r(2*pr+1, mid+1, rr, c);
    
    //this call for generat the parent row from child rows
    build(pr, lr, rr, 1, 1, c);
    
 
}
 
 
 
void update_merge(int pr, int pc, int lc, int rc, int e1, int e2){
    if(e2<lc||rc<e1) return;
    if(e1<=lc&&rc<=e2){
        
        seg[pr][pc]=seg[2*pr][pc]+seg[2*pr+1][pc];
        return;
    }
    
    int mid=(lc+rc)>>1;
    
    update_merge(pr, 2*pc, lc, mid, e1, e2);
    update_merge(pr, 2*pc+1, mid+1, rc, e1, e2);
    
    seg[pr][pc]=seg[pr][2*pc]+seg[pr][2*pc+1];


}



//update segment tree for collum level..
//when the segment is between x1 and x2
void update(int pr, int lr, int rr, int pc, int lc, int rc, int e1, int e2, ll v){
    if(e2<lc||rc<e1) return;
    if(e1<=lc&&rc<=e2){
        seg[pr][pc]=(rr-lr+1)*(rc-lc+1)-seg[pr][pc];
        return;
    }
    
    int mid=(lc+rc)>>1;
    
    update(pr, lr, rr, 2*pc, lc, mid, e1, e2, v);
    update(pr, lr, rr, 2*pc+1, mid+1, rc, e1, e2, v);
    
    seg[pr][pc]=seg[pr][2*pc]+seg[pr][2*pc+1];

}
 


//update segment row level
// first find the x1-----x2 segment 
void update_r(int pr, int lr, int rr, int c, int s1, int e1, int s2, int e2, ll v){
    //outside the x1-----x2
    if(s2<lr||rr<s1) return;
    
    //inside the segment
    //now call the collum level update
    if(s1<=lr&&rr<=s2){
        update(pr, lr, rr, 1, 1, c, e1, e2, v);
        return;
    }
    
    int mid=(lr+rr)>>1;
    update_r(2*pr, lr, mid, c, s1, e1, s2, e2, v);
    update_r(2*pr+1, mid+1, rr, c, s1, e1, s2, e2, v);
    update_merge(pr, 1, 1, c, e1, e2);
    
    
}

 
 


//query segment tree for collum level..
//when the segment is between x1 and x2
ll query(int pr, int pc, int lc, int rc, int e1, int e2){
    if(e2<lc||rc<e1) return 0;
    if(e1<=lc&&rc<=e2) return seg[pr][pc];
    
    int mid=(lc+rc)>>1;
    
    ll x=query(pr, 2*pc, lc, mid, e1, e2);
    ll y=query(pr, 2*pc+1, mid+1, rc, e1, e2);

    return x+y;
}
 
 
 
 
 
//query segment tree in row level 
//find the x1-----x2 segment 
ll query_r(int pr, int lr, int rr,int c, int s1, int e1, int s2, int e2){
    
    //outside the x1-----x2
    if(s2<lr||rr<s1) return 0;
    
    //inside the segment
    //now call the collum level query 
    if(s1<=lr&&rr<=s2) return query(pr, 1, 1, c, e1, e2);
    
    
    
    
    int mid=(lr+rr)>>1;
    ll x=query_r(2*pr, lr, mid, c, s1, e1, s2, e2);
    ll y=query_r(2*pr+1, mid+1, rr, c, s1, e1, s2, e2);
    
    return x+y;
 
 
}





void solve(int t){
    //cout<<"Case "<<t<<": \n";
    int n,q;
    cin>>n>>q;
    char c;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        cin>>c;
        if(c=='*')a[i][j]=1;
    
    }
    build_r(1,1,n,n);
    
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int x1,y1;
            cin>>x1>>y1;
            update_r(1,1,n,n,x1,y1,x1,y1,1);
        }else{
              int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<query_r(1,1,n,n,x1,y1,x2,y2)<<'\n';
    
    
        
        }
        
    
    
    }



}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)solve(i);
   

    return 0;
}