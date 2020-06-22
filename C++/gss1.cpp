#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 50020
using namespace std;

struct node{
	int prefix, suffix, sum, best_sum;
	node(){
	}
	node(int prefix, int suffix, int sum, int best_sum): prefix(prefix), suffix(suffix), sum(sum), best_sum(best_sum){
	}
};

int arr[MAX];
node st[4*MAX];

node merge(node&a, node&b){
	node c;
	c.sum = a.sum + b.sum;
	c.prefix = max(a.prefix, a.sum + b.prefix);
	c.suffix = max(b.suffix, b.sum + a.suffix);
	c.best_sum = max(a.best_sum, b.best_sum);
	c.best_sum = max(c.best_sum, a.suffix + b.prefix);
	return c;
}

void build_segtree(int si, int ss, int se){
	if(ss == se)
		st[si] = {arr[ss], arr[ss], arr[ss], arr[ss]};
	else{
		int mid = (ss+se)/2;
		build_segtree(2*si, ss, mid);
		build_segtree(2*si+1, mid+1, se);
		node left = st[2*si];
		node right = st[2*si+1];
		node n = merge(left, right);
		st[si] = n;
	}
}

node query(int si, int ss, int se, int qs, int qe){
	if(qs > se || qe < ss)
		return {-MAX, -MAX, -MAX, -MAX};
	else if(ss >= qs && se <= qe)
		return st[si];
	else{
		node left, right;
		int mid = (ss + se)/2;
		left = query(2*si, ss, mid, qs, qe);
		right = query(2*si+1, mid+1, se, qs, qe);
		node result = merge(left, right);
		return result;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>arr[i];

	build_segtree(1, 1, n );
	int l, r;
	cin>>m;
	for(int i=0; i<m; ++i){
		cin>>l>>r;
		node res = query(1, 1, n, l, r);
		cout<<res.best_sum<<endl;
	}
	
    return 0;
}
