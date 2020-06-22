#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl;
#endif
#define MAX 200010
using namespace std;
typedef long long int lli;
vector<int> graph[MAX];
vector<int> selected;
vector<lli> income, pops;
bool visited[MAX];

int bfs(int node, lli num, lli denom, bool f){
	vector<int> neighbors = graph[node];
	int cnt = 1;
	visited[node] = true;
	if(f)
		selected.push_back(node);
	for(int neighbor: neighbors){
		if(!visited[neighbor]){
			if(income[neighbor] * denom == num * pops[neighbor]){
				cnt += bfs(neighbor, num, denom, f);
			}
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		income.clear();
		pops.clear();
		selected.clear();
		int n, m;
		cin>>n>>m;
		for(int i=0; i<n; ++i)
			visited[i] = false;
		for(int i=0; i<n; ++i)
			graph[i].clear();
		int u, v;
		lli x;
		vector<pair<long double, int> > ratios;
		for(int i=0; i<n; ++i){
			cin>>x;
			income.push_back(x);
		}
		for(int i=0; i<n; ++i){
			cin>>x;
			pops.push_back(x);
		}
		for(int i=0; i<n; ++i){
			ratios.push_back({(long double)(income[i])/pops[i], i});
		}
		sort(ratios.begin(), ratios.end());
		for(int i=0; i<m; ++i){
			cin>>u>>v;
			u--;
			v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		pair<long double, int> p;
		long double prev_ratio = ratios[n-1].first;
		int best_idx, best_num;
		best_num = 0;
		best_idx = -1;
		for(int i=n-1; i>=0; --i){
			p = ratios[i];
			int idx = p.second;
			long double ratio = p.first;
			if(ratio < prev_ratio){
				break;
			}
			//memset(visited, false, sizeof(visited));
			int res = bfs(idx, income[idx], pops[idx], false);
			//DEBUG(res);
			if(res > best_num){
				best_num = res;
				best_idx = idx;
			}
			//DEBUG(res);
			//DEBUG(best_idx);
		}
		memset(visited, false, sizeof(visited));
		bfs(best_idx, income[best_idx], pops[best_idx], true);
		cout<<selected.size()<<endl;
		for(auto& y: selected){
			cout<<(y+1)<<" ";
		}
		cout<<endl;
	}
    return 0;
}
