#include <bits/stdc++.h>


using i64 = long long;

int a[1000];

void insertion_sort(int arr[], int len) {
	arr[0] = -1e9; 
	for (int i = 1; i < len; i ++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j --;
		}

		arr[j + 1] = key;

		for (int i = 1; i <= len; i ++) {
			std::cout << arr[i] << " \n"[i == len];
		}
	}
}

int main() {
	int n; std::cin >> n;

	for (int i = 1; i <= n; i ++) std::cin >> a[i];

	insertion_sort(a, n);

	for (int i = 1; i <= n; i ++) {
		std::cout << a[i] << " \n"[i == n];
	}
}