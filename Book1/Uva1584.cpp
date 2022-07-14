#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int maxn = 1010;

bool cmp(char* ch, int p, int q, int n){
	for (int i = 0; i < n; i ++){
		if (ch[(p + i) % n] != ch[(q + i) % n])
			return ch[(p + i) % n] < ch[(q + i) % n];
	}
	return false;
}

int main(){
	int T;
	char s[maxn];
	scanf ("%d", &T);
	while (T --){
		scanf("%s", s);
		int ans = 0, n = strlen(s);
		for (int i = 0; i < n; i ++){
			if (cmp(s, i, ans, n)) ans = i;
		}
		for (int i = 0; i < n; i ++){
			printf("%c", s[(ans + i) % n]);
		}
	}
}
