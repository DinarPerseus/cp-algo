// Dinar Perse�s 2.0
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void fileio(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

struct node
{
	ll val;
	node *left,*right;

	//constructors
	node(){
		val=0;
		left=nullptr;
		right=nullptr;
	}

	node (ll v, node *l, node *r){
		val=v;
		left=l;
		right=r;
	}

};


int a[200005];
node *roots[200005];


//build Persistent Segment Tree
void build(node *p, int l, int r){
	if(l==r){
		p->val=a[l];
		return;
	}
	ll mid=(l+r)>>1;

	p->left=new node;
	p->right=new node;
	build(p->left, l, mid);
	build(p->right, mid+1, r);
	p->val = p->left->val + p->right->val;
}


//update Persistent Segment Tree
void update(node *p0, node *p1, int l, int r, int idx, int v){
	if(idx<l||idx>r||l>r)return;
	if(l==r){
		// modification in new version
		p1->val=v;
		return;
	}

	ll mid=(l+r)>>1;

	if(idx<=mid){
		// link to right child of previous version
		p1->right=p0->right;
		// create new node in current version
        p1->left = new node;
		update(p0->left, p1->left, l, mid, idx, v);

	}else{
		// link to left child of previous version
		p1->left=p0->left;
		// create new node in current version
        p1->right = new node;
		update(p0->right, p1->right, mid+1, r, idx, v);

	}

	p1->val = p1->left->val + p1->right->val;
}


//query Persistent Segment Tree
ll query(node *p, int l, int r, int s, int e){
	if(s>r||e<l) return 0;
    if(s<=l&&r<=e) return p->val;

	ll mid=(l+r)>>1;
	return query(p->left, l, mid, s, e)+query(p->right, mid+1, r, s, e);

}






int main()
{
    fileio();
    fastio();
    // clock_t z = clock();
	
	int n,q,cnt=1;
	cin>>n>>q;
	

	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	roots[cnt]=new node;
	build(roots[cnt], 1, n);


	while (q--)
	{
		int op;
		cin>>op;

		if(op==1){
			int k,a,x;
			cin>>k>>a>>x;
			node *p1=new node;
			update(roots[k], p1, 1, n, a, x);
			roots[k]=p1;
		}else if(op==2){
			int k,a,b;
			cin>>k>>a>>b;
			cout<<query(roots[k], 1, n, a, b)<<'\n';
		}else{
			int k;
			cin>>k;
			roots[++cnt]=roots[k];
		}

	}
	
	
 
    // cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);
    return 0;
}



