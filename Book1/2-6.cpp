#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#define LOCAL
const int MOD = 1e5;
using namespace std;
int main(){
	for (int i = 1; i <= 9; i ++)
		for (int j = 1; j <= 9; j ++)
			for (int k = 1; k <= 9; k ++){
				int m = i * 100 + j * 10 + k;
				if (3 * m > 999) break;
				int a[3] = {m, 2 * m, 3 * m};
				bool check = true;
				for (int i = 0; i < 3; i ++){
					for (int j = 0; j < 3; j ++){
						if (!(a[i] / (int)pow(10, j) % 10)) check = false;
					} 
				}
				if (check){
					for (int i = 0; i < 3; i ++){
						cout << a[i] << " ";
					}
					cout << endl;
				}
			}
}
