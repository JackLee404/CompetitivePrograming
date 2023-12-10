#include<bits/stdc++.h>

using namespace std;
int n,num;
int a[20],b[20],c[200],d[200];

void dayin(){
	if(num<3){
		for(int i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	num++;
	return ;
}

void dfs(int x){
	if(x==n){
		dayin();
		return ;
	}
	for(int i=1;i<=n;i++){
		if((!b[i])&&(!c[i+x])&&(!d[x-i+n])){
			a[x]=i;
			b[i]=1;
			c[i+x]=1;
			d[x-i+n]=1;

			dfs(x+1);

			b[i]=0;
			c[i+x]=0;
			d[x-i+n]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	dfs(0);
	printf("%d",num);
	return 0;
}
