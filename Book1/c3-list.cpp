// 3-1
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int maxn = 1010;

int main(){
	char a[maxn];
	int T;
	scanf ("%s", &T);
	while (T --){
		scanf("%s", a);
		int tot = 0, ans = 0;
		for (int i = 0; a[i]; i ++){
			if (a[i] == 'O') tot ++, ans += tot;
			else tot = 0;
		}
		printf("%d", ans);
	}
	return 0;	
}
// 3-2

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int maxn = 1010;

int main(){
	int T;
	char a[maxn];
	scanf ("%d", &T);
	double crt[26];
	crt['C' - 'A'] = 12.01, crt['H' - 'A'] = 1.008, crt['O' - 'A'] = 16.00, crt['N' - 'A'] = 14.01; 
	while (T --){
		double ans = 0;
		scanf ("%s", a);
		int n = strlen(a);
		for (int i = 0; i < n; i ++){
			if (isdigit(a[i])) continue;
			if (isdigit(a[i + 1])) ans += crt[a[i] - 'A'] * (a[i + 1] - '0');
			else ans += crt[a[i] - 'A'];
		}
		printf("%.3lfg/mol\n", ans);
	}
}

// 3-3
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int maxn = 1010;
int main(){
	char a[10][100], act[maxn];
	int kase = 0;
	while (true){
		bool ok = true;
		for (int i = 0; i < 5; i ++){
			cin.getline(a[i], 10);
			if (a[0][0] == 'Z') {
				return 0;
			}
		}
		cin.getline(act, maxn);
		int x, y;
		for (int i = 0; i < 5; i ++)
			for (int j = 0; j < 5; j ++)
				if (a[i][j] == ' ') {
					x = i, y = j;
					break;
				}
		for (int i = 0; act[i] != '0'; i ++){
			int ox = x, oy = y;
			if (act[i] == 'A') x ++;
			else if(act[i] == 'B') x --;
			else if (act[i] == 'L') y --;
			else y ++;
			if (x < 0 || x >= 5 || y < 0 || y >= 5){
				ok = false;
				break;
			}
			swap(a[ox][oy], a[x][y]);
		}
		printf("Puzzle #%d\n", ++ kase);
		if (!ok) puts("This puzzle has no final configuration.");
		else{
			for (int i = 0; i < 5; i ++){
				for (int j = 0; j < 5; j ++){
					printf("%c ", a[i][j]);
				}
				puts("");
			}
		}

	}
}
