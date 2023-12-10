#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	double x11,y11,x12,y12;
	cin>>x11>>y11>>x12>>y12;
	double x21,y21,x22,y22;
	cin>>x21>>y21>>x22>>y22;
	double rx1=(x11+x12)/2;
	double ry1=(y11+y12)/2;
	double rx2=(x21+x22)/2;
	double ry2=(y21+y22)/2;
	cout<<rx1<<" "<<ry1<<endl;
	cout<<rx2<<" "<<ry2<<endl;
	double s1=fabs(rx1-rx2)+fabs(ry1-ry2);
	cout<<s1<<endl;
	cout<<4.2639320225-s1<<endl;
	 
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	} 
	return 0;
	
}
