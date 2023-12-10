// 3 4 
// 6 2 3
// 5 1 2 取3只筷子
// 4 0 1 取3只筷子 三对筷子
// 3 0 0 2只筷子 现只有三对
// 2 0 0 1只筷子 4对
// 
// 二进制 110 10 11
// 10



// 3 114514
// 6 2 3


// 3 3 110
// 6 2 3
// 二进制 110 10 11
// 8 1000
// 

#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

LL f(LL a,LL b){
	LL res=1;
	while(b>0){
		res*=a;
		b>>=1;
		a*=a;
	}
	return res;
}

int main() {
	cout<<log(2.71828);
}
