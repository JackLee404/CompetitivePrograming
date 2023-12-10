#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using i64 = long long;

/*
	a_i 为奇数， 并且a_i 小于前面的任意数
*/

void solve() {
	int n;

	std::cin >> n;

	std::vector<int> a(n + 1);

	std::priority_queue<int, std::vector<int>, std::greater<int>> q1;

	std::priority_queue<int> q2;

	bool ok = false;


	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		
		if(a[i] % 2 != 0 && a[i] > a[1]) ok = true;	
	}
    
    if(a[1] % 2 != 0) {
    	puts("0");
        return;
    }

    if(ok) {
    	puts("1");
    	return;
    }

    for(int i = 1; i <= n; i ++) {

    	if(q1.size()) {
    		int k = q1.top(), k2 = INF;

    		if(q2.size()) k2 = q2.top();

    		if(k < k2) {
    			puts("2");
    			return;
    		}
    	}

    	(a[i] % 2 == 0)?q2.push(a[i]):q1.push(a[i]);
    }

    puts("-1");
}

int main(){
	int _;

	std::cin >> _;

	while(_ --) {
		solve();
	}
}