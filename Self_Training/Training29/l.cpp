#include<bits/stdc++.h>
using  namespace std;
typedef long long ll;
int t;
const int N = 1e8;
ll a,b,c,d;
std::vector<ll> v;
ll arr1[N], arr2[N], cnt;

bool check(ll x) {
	return ((a % x) * (b % x)) % x == c;
}

int main(){
	cin>>t;

	while(t--){
		cin>>a>>b>>c>>d;

		bool flag = false;

		for(int i=2;i*i<=d;i++){
		
			int l=0;
			ll t=1;

			while(d%i==0){
				d/=i;
				l++;
				t*=i;
			}

			if (check(t)) {
				cout << t << "\n";
				flag = true;
				break;	
			}	
		}

		if (flag) continue;

		if(d!=0){
			if (check(d)) {
				cout << d << "\n";
			}	
		}

	}
}