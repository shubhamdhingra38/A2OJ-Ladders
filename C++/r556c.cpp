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
	int n;
	cin>>n;
	vector<int> v;
	int x;
	for(int i=0; i<n; ++i){
		cin>>x;
		v.push_back(x);
	}
	int num_one, num_two;
	num_one = count(v.begin(), v.end(), 1);
	num_two = count(v.begin(), v.end(), 2);
	if(num_one == 0){
		for(int i=0; i<n; ++i)
			cout<<2<<" ";
		cout<<endl;
	}
	else if(num_two == 0){
		for(int i=0; i<n; ++i)
			cout<<1<<" ";
		cout<<endl;
	}
	else{
		cout<<2<<" ";
		if(num_one%2 == 0){
			for(int i=0; i<num_one-1; ++i)
				cout<<1<<" ";
			for(int i=0; i<num_two-1; ++i)
				cout<<2<<" ";
			cout<<1<<" ";
			cout<<endl;
		}
		else{
			for(int i=0; i<num_one; ++i)
				cout<<1<<" ";
			for(int i=0; i<num_two-1; ++i)
				cout<<2<<" ";
			cout<<endl;
		}
	}
    return 0;
}

//2, 3, 5, 7, 11, 13, 17, 23, 31, 39, 41
//2, 1, 1, 1, 1, 1, 1, 1, 2
//2, 3, 4, 5, 6, 7, 8, 9, 11
