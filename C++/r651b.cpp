#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 2010
using namespace std;
typedef long long int lli;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	int arr[MAX];
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int o_count, e_count;
		o_count = e_count = 0;
		vector<int> odd;
		vector<int> even;
		for(int i=0; i<2*n; ++i){
			cin>>arr[i];
			if(arr[i]&1){
				o_count++;
				odd.push_back(i+1);
			}
			else{
				e_count++;
				even.push_back(i+1);
			}
		}
		int count = n-1;
		int till = o_count%2 == 0 ? 0 : 1;
		for(int i=0; i<odd.size()-till; i+=2){
			if(count == 0)
				break;
			cout<<odd[i]<<" "<<odd[i+1]<<endl;
			count--;
		}
		for(int i=0; i<even.size(); i+=2){
			if(count == 0)
				break;
			cout<<even[i]<<" "<<even[i+1]<<endl;
			count--;
		}

		
	}
	
    return 0;
}
