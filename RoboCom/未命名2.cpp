#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	vector<int> v1(n);
	
	for (auto &x: v1) cin >> x;
	
	for (int i = 0; i < n - 1; i ++) {
		int minId = 0;
		
		for (int j = 0; j < n - i; j ++) {
			if (v1[j] < v1[minId]) minId = j;
		}
		
		swap(v1[n - i - 1], v1[minId]);
	}
	
	for (int i = 0; i < n; i ++) {
		cout << v1[i] << " \n"[i == n - 1];
	}
} 
