#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<map>
#include<set>
using namespace std;
const int N=1e5+10;
int shu[N];
int n;

unordered_map<long long, int> pos;

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first<b.first;
}
int low(int a){
	return a&-a;
}
void add(int a,int b){
	for(int i=a;i<=n;i+=low(i)){
		shu[i]+=b;
	}
}
int sum(int a){
	int ams=0;
	for(int i=a;i;i-=low(i))
		ams+=shu[i];
	return ams;
}
int main(){
	cin>>n;
	vector<pair<int,int>> cun;
	cun.resize(n+1);
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		pos[c] = i;
	}
	sort(cun.begin()+1,cun.end(),cmp);
	long long int ams=0;
	for(int i=1;i<cun.size();i++){
		add(cun[i].second,1);
		ams+=(i-sum(cun[i].second));
	}
	cout<<ams;
	getchar();
	getchar();
	return 0;
}