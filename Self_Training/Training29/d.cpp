#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int M=1e9;

int t;
ll m,c1,c2;
ll ans1,ans2;
ll f1[N],f2[N];
int main(){
	cin>>t;
	while(t--){
		ans1=ans2=0;
		//每次都要初始化
		cin>>m>>c1>>c2;
		ll d;
		for(int i=1;i<=m;i++){
			cin>>f1[i]>>f2[i];
			d=c1*f1[i]/M;
			ans1+=min(d,c1);
			d=c2*f2[i]/M;
			ans2+=min(c2,d);
		}
		if(ans1<ans2){
			cout<<"Northy"<<endl;
		}
		else{
			cout<<"Rilly"<<endl;
		}
	}
	return 0;

}