//划分
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
ll t;
ll n,l,r;
ll a[N];
ll s[N];//前缀和
ll dp[N];//dp背包
/*
dp[i]表示选择不选择第i个字母，如果不选dp[i]=max(dp[i],dp[i-1]);
如果选第i个数，我们就需要在0-i之间找一个j使得i到j区间和满足在[l,r]区间里


*/
int main(){
	cin>>t;
	while(t--){
		cin>>n>>l>>r;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		memset(s,0,sizeof s);//每次都要初始化
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i];//前缀和;
		}
		for(int i=1;i<=n;i++){
			//这是选择第i个数字的时候
			for(int j=1;j<=i;j++){
				if(s[i]-s[j-1]>=l&&s[i]-s[j-1]<=r){
					dp[i]=max(dp[i],dp[j-1]+1);
				}
			}
			//这里更新完选的时候，我们才可以更新不选
			dp[i]=max(dp[i],dp[i-1]);
		}
		cout<<dp[n]<<endl;
	}
	return 0;

}