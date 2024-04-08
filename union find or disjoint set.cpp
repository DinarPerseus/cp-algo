// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

//union find or disjoint set algorithm using path compression
//in this algorithm we have to initialize the parent array
//initialize parent[i]=i
int parent[N];

int Find(int x){
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}

void Union(int x, int y){
    parent[Find(x)]=Find(y);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //initialize the array
    for(int i=0;i<N;i++) parent[i]=i;
    
    Union(1,2);
    Union(3,4);
    if(Find(1)==Find(3))cout<<"they are in the same set\n";
    else cout<<"they are not in the same set\n";
    
    Union(2,4);
    
    if(Find(1)==Find(3))cout<<"they are in the same set\n";
    else cout<<"they are not in the same set\n";
    
    
    
   

    return 0;
}