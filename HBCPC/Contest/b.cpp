// 0~4, 7+(0~4)



#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N = 1e9 + 7;

double f(int n){
	int i;
	double sum=0;
	for(i=1;i<=n;i++){
		sum+=n*1.0/i;
		// if (sum >= N) {
		// 	LL tmp = sum;
		// 	double tmp2 = sum - tmp;
		// 	tmp %= N;
		// 	sum = tmp + tmp2;
		// }
	}
	return sum;
}

int main() {
	LL t,n;
	cin>>t;
	while(t--){
		cin>>n;
		// if(n>=1e7){
		puts("TEST1:");
			cout<<(LL)(n*log(n)+n)<<endl;
		// }
		// else{
			puts("TEST2:");
			cout<<(LL)f(n)<<endl;
		// }
	}

}