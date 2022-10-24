#include <iostream>


using namespace std;

int count(int x) {
	int res = 0;
	while (x!=0) {
		if (x & 1) {
			res ++;
		}
		x >>= 1;
	}
	return res;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int maxx=-1,pos=0,sum=0,n;
		cin>>n;
		int i;
		for(i=1;i<=n;i++){
			cin>>a[i];
			a[i]=count(a[i]);
			sum^=a[i];
		}
		for(i=1;i<=n;i++){
			if((sum^a[i])>maxx){
				maxx=a[i]^sum;
				pos=i;
			}
		}
		cout<<pos<<" "<<maxx<<endl;
	}
}
