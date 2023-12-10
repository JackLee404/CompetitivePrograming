#include <bits/stdc++.h>

using namespace std;

int get_max(int a[], int n) {
	int i, max;
	for (int i = 1; i < n; i ++)
		if (a[i] > max)
			max = a[i];
	return max; 
}

void count_sort(int a[], int n, int expr) {
	int output[n];
	int i, buckets[10] = {0};
	
	for (int i = 0; i < n; i ++)
		buckets[(a[i] / exp) % 10] ++;
	
	for (int i = n - 1; i >= 0; i --) {
		output[buckets[ (a[i] / exp) % 10 ] - 1] = a[i];
		buckets[(a[i] / exp) % 10] --;
	}
	
	for (int i = 0; i < n; i ++)
		a[i] = output[i];
}

void radix_sort(int a[], int n) {
	int exp;
	int max = get_max(a, n);
	
	for (exp = 1; max / exp > 0; exp *= 10)
		count_sort(a, n, exp);
}

int main() {
	
} 
