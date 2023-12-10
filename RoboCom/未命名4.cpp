#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int> &v1) {
	int len = v1.size();
	
	for (int i = 1; i < len; i ++) {
		int key = v1[i];
		int j = i - 1;
		
		while (j >= 0 && v1[j] > key) {
			v1[j + 1] = v1[j];
			j --;
		}
		
		v1[j + 1] = key;
	}
}

int main() {
	int n;
	
	cin >> n;
	
	vector<int> a(n);
	
	for (auto &x: a) cin >> x;
	
	insertion_sort(a);
	
	for (int i = 0; i < n; i ++) {
		cout << a[i] << " \n"[i == n - 1];
	}
}
