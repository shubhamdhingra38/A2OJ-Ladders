#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef long long int lli;
bool is_prime(int x){
	for(int i=2; i*i<=x; ++i){
		if(x%i == 0)
			return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n1, n2;
	cin>>n1>>n2;
	vector<int> primes;
	for(int i=n1; i<=n2; ++i){
		if(is_prime(i))
			primes.push_back(i);
	}
	set<int> s;
	for(int i=0; i<(int)primes.size(); ++i){
		for(int j=i+1; j<(int)primes.size(); ++j){
			s.insert(stoi(to_string(primes[i]) + to_string(primes[j])));
			s.insert(stoi(to_string(primes[j]) + to_string(primes[i])));
		}
	}
	primes.clear();
	for(auto& x: s){
		if(is_prime(x))
			primes.push_back(x);
	}
	sort(primes.begin(), primes.end());
	lli first = primes[0];
	lli second = primes[primes.size()-1];
	int count = primes.size();
	lli third;
	count--;
	while(count--){
		third = first + second;
		first = second;
		second = third;
	}
	cout<<first<<endl;
    return 0;
}
