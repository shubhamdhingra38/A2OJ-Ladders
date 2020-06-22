#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define SIZE 1000002
#define MAX 30005
#define MAX_Q 200005
using namespace std;
int n, q;
int l, r;
int arr[MAX];
int freq[SIZE];
int block_size;
struct Query{
	int left, right, idx;
};
bool cmp(Query& q1, Query& q2){
	int ax = q1.left/block_size;
	int bx = q2.left/block_size;
	if(ax != bx)
		return ax < bx;
	return q1.right < q2.right;
}
Query queries[MAX_Q];
int answers[MAX_Q];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &arr[i]);
    scanf("%d", &q);
    block_size = (int)sqrt(n);
    for(int i=0; i<q; ++i){
		scanf("%d %d", &l, &r);
		l--;
		r--;
		Query qr = {l, r, i};
		queries[i] = qr;
	}
	int curr_l, curr_r;
	curr_l = 0;
	curr_r = -1;
	sort(queries, queries+q, cmp);
	int sum = 0;
	memset(freq, 0, sizeof(freq));
	for(int i=0; i<q; ++i){
		Query qr = queries[i];
		//DEBUG(qr.left);
		//DEBUG(qr.right);
		for(int j=1; j<=3; ++j){
			DEBUG(j);
			DEBUG(freq[j]);
		}
		while(curr_l > qr.left){
			curr_l--;
			freq[arr[curr_l]]++;
			if(freq[arr[curr_l]] == 1)
				sum++;
		}
		while(curr_r < qr.right){
			curr_r++;
			freq[arr[curr_r]]++;
			if(freq[arr[curr_r]] == 1)
				sum++;			
		}
		while(curr_l < qr.left){
			freq[arr[curr_l]]--;
			if(freq[arr[curr_l]] == 0){
				sum--;
				DEBUG(arr[curr_l]);
				DEBUG(freq[arr[curr_l]]);
			}
			curr_l++;
		}
		while(curr_r > qr.right){
			freq[arr[curr_r]]--;
			if(freq[arr[curr_r]] == 0){
				sum--;
				DEBUG(arr[curr_r]);
				DEBUG(freq[arr[curr_r]]);
			}
			curr_r--;
		}
		answers[qr.idx] = sum;
	}
	for(int i=0; i<q; ++i)
		printf("%d\n", answers[i]);
	
    return 0;
}
