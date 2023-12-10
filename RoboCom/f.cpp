#include <iostream>

using namespace std;


void insertion_sort(int arr[], int n) {
	for (int i = 2; i <= n; i ++) {
		int key = arr[i];
		int j = i - 1;
		
		while (j >= 1 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j --;
		}
		arr[j + 1] = key;
	}
}

void insertion_sort(int arr[], int n) {
	for (int i = 2; i <= n; i ++) {
		int key = arr[i];
		int j = i - 1;
		
		while (j >= 1 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j --;
		}
		
		arr[j + 1] = key;
	}
}

int main() {
	int n; std::cin >> n;
	
	int a[n + 1];
	
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	insertion_sort(a, n);
	
	for (int i = 1; i <= n; i ++) {
		cout << a[i] << " \n"[i == n]; 
	}
}

