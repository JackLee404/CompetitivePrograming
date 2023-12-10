#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 10;

int a[N];

int q1[N], q2[N], h1 = -1, t1, h2 = -1, t2;

/*
	假设某个数在一个另一个数的后面，并且该数小于这个数，那么它是解
*/

int main(){
	int n, k; cin >> n >> k;
	vector<int> v1, v2;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		while(h1 != -1 && a[i] < a[q1[h1]]) h1--;
		q1[++h1] = i;
		while(h2 != -1 && a[i] > a[q2[h2]]) h2--;
		q1[++h2] = i;
		if(i >= k) {
			cout << q1[h1] << " ";
		}
	}
}