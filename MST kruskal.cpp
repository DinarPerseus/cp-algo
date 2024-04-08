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



//graph
class graph
{
    int n;
    vector<pair<int,int>> *adj;
public:
    graph(int v){
        n=v;
        adj=new vector<pair<int,int>>[v];
    }
    void addedge(int u, int v,int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    
    
    
    
    
    
    long long MST_kruskal(){
        
        
        //{w,{u,v}}
        set<pair<int,pair<int,int>>> edges;
        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                //this min , max function always insert the ordered edge..
                // edge 4-5 == 5-4 is same now..
                // always 4 will be the source and 5 will be the destination of an edge 
                edges.insert({j.second,{min(j.first,i),max(j.first,i)}});
            
            }
        
        }
        
        //for(auto x: edges)cout<<x.first<<' '<<x.second.first<<' '<<x.second.second<<'\n';
        long long cnt=0,cost=0;
        
        
        //{w,{u,v}}
        vector<pair<int,pair<int,int>>> mst;
        
        for(int i=0;i<n;i++) parent[i]=i;
        
        for(auto x: edges){
            int u=x.second.first;
            int v=x.second.second;
            int w=x.first;
            if(Find(u)==Find(v)) continue;
            cnt++;
            Union(u,v);
            cost+=w;
            mst.push_back({w,{u,v}});
            if(cnt==n-1) break;
        }
        
        
        
        //if want the MST cost then return cost;
        //if want the MST tree then return mst vector;
        //this vector element is {w, {u, v}}
        
        
        
        //if(cnt!=n-1)cout<<"IMPOSSIBLE\n";
        //else cout<<cost;
        return cost;
        
    
    
    }
 
 
 
};


void solve(int t){
    //cout<<"Case "<<t<<": \n";
    int n,m;
    cin>>n>>m;
    graph g(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addedge(u-1,v-1,w);
    
    }
    g.MST_kruskal();
    

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