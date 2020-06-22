#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef long long int lli;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, n;
	int arr[200];
	cin>>x>>n;
	if(n == 0){
		cout<<x<<endl;
	}
	else{
	
		set<int> s;
		for(int i=0; i<n; ++i){	
			cin>>arr[i];
			s.insert(arr[i]);
		}
		int nearest;
		int num = x;
		while(1){
			num--;
			if(s.find(num) == s.end()){
				nearest = num;
				break;
			}
		}
		//DEBUG(nearest);
		num = x;
		while(1){
			num++;
			if(s.find(num) == s.end()){
				if(abs(num-x) < abs(nearest-x))
					nearest = num;
				break;
			}
		}
		if(s.find(x) == s.end())
			nearest = x;
		cout<<nearest<<endl;
	}
	
    return 0;
}
