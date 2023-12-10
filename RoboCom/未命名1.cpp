#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	vector<int> v(n);
	
	
	for (auto &x: v) cin >> x;
	
	/*
		0 - n - 1
		0 - n - 2
	*/
	for (int i = 0; i < n - 1; i ++) {
		int minId = 0;
		
		for (int j = 0; j <= n - i - 1; j ++) {
			
			if (v[j] < v[minId]) {
				minId = j;
			}	
		}
		
		swap(v[minId], v[n - i - 1]);
	}
	
	for (int i = 0; i < n; i ++) {
		cout << v[i];
		if (i != n - 1) cout << " ";
		else cout << "\n";
	}
}
