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


//trie initialization
const int alphabet = 26;
const int max_nodes = 1e6;
int trie[max_nodes][alphabet];  // stores child links
bool endmark[max_nodes];        // marks end of words
int nodeCount = 0;              // root is node 0
int cnt[max_nodes];             // number of words passing through a node


//trie insert
void trieInsert(const string& s){
    int curr=0, idx;
    for(auto c:s){
        idx=c-'a';
        if(trie[curr][idx]==0)trie[curr][idx]=++nodeCount;

        curr=trie[curr][idx];
        cnt[curr]++;
    }
    endmark[curr]=1;
}

//trie delete
void trieDelete(const string& s){
    int curr=0, idx;
    vector<int> path;  // store nodes to backtrack later
    path.push_back(0);

    for (auto c : s) {
        idx = c - 'a';
        if (trie[curr][idx] == 0)return; // word not found
        curr = trie[curr][idx];
        path.push_back(curr);
    }

    if (endmark[curr]==0) return; // word not found
    endmark[curr] = false;


    // Cleanup: decrease counts and remove unused links
    for (int i = (int)s.size(); i >= 1; i--) {
        int node = path[i];
        cnt[node]--;
        if (cnt[node] == 0) {
            trie[path[i - 1]][ s[i - 1] - 'a' ] = 0; // unlink
        } else {
            break; // stop if still used by another word
        }
    }


}


//trie word search
bool trieWordSearch(const string&s){
    int curr=0, idx;
    for(auto c:s){
        idx=c-'a';
        if(trie[curr][idx]==0)return 0;

        curr=trie[curr][idx];
    }
    return endmark[curr];
}


//trie prefix search
bool triePrefixSearch(const string&s){
    int curr=0, idx;
    for(auto c:s){
        idx=c-'a';
        if(trie[curr][idx]==0)return 0;

        curr=trie[curr][idx];
    }
    return 1;
}





void solve(int t){
    trieInsert("apple");
    trieInsert("app");
    trieInsert("bat");
    trieDelete("apple");

    cout << (trieWordSearch("app") ? "Found\n" : "Not Found\n");
    cout << (trieWordSearch("appl") ? "Found\n" : "Not Found\n");
    cout << (triePrefixSearch("appl") ? "Prefix Exists\n" : "Prefix Not Found\n");

    

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