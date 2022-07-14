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

// 3-7
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int maxn = 1010;
int m, n, cnt[4][maxn];	
bool cmp(char* a, char* b){
	for (int i = 0; i < n; i ++){
		if (a[i] != b[i]) return a[i] < b[i];
	}
	return false;
}
int cal(char* a, char* b){
	int tot = 0;
	for (int i = 0; i < n; i ++){
		if (a[i] != b[i]) tot ++;
	}
	return tot;
}

int main(){
	char ch[500], ans[maxn];
	int T;
	cin >> T;
	while (T --){
		int ansn = 0;
		cin >> m >> n;
		for (int i = 0; i < m; i ++){
			scanf("%s", ch);
			for (int j = 0; j < n; j ++){
				if (ch[j] == 'A') cnt[0][j] ++;
				else if (ch[j] == 'C') cnt[1][j] ++;
				else if (ch[j] == 'G') cnt[2][j] ++;
				else cnt[3][j] ++;  
			}
		}
		for (int i = 0; i < n; i ++){
			int maxn = 0;
			for (int j = 0; j < 4; j ++){
				if (cnt[j][i] > cnt[maxn][i]) maxn = j;
			}
			if (maxn == 0) ans[i] = 'A';
			else if (maxn == 1) ans[i] = 'C';
			else if(maxn == 2) ans[i] = 'G';
			else if (maxn == 3) ans[i] = 'T';

			for (int j = 0; j < 4; j ++){
				if (j != maxn) ansn += cnt[j][i];
			}
		}	
		ans[n] = '\0';
		puts(ans);
		printf("%d\n", ansn);
	}
}
//3-8
#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;

bool a[30010];
int b[30010];
int main(){
	vector<int> res;
	int n, m, md;
	while (cin >> n >> m){
		int tn = n, tm = m;
		bool flag = false;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int cnt = 0;
		res.clear();
		int last;
		for (int i = 0;; i++){
			md = n % m;
			last = i;
			if (a[md] || md == 0) break;
			a[md] = 1;
			b[md] = i + 1;
			res.push_back(n / m);
			n = md * 10;
		}
		printf("%d/%d = ", tn, tm);
		if (res.size() - b[md] > 50) flag = true;
		if (!md){
			res.push_back(n / m);
			for (int i = 0; i < res.size(); i ++){
				printf("%d", res[i]);
				if (i == 0) printf(".");
			}
			printf("(0)\n");
			cnt = 1;
		}
		else{
			cnt = last - b[md] + 1;
			for (int i = 0; i < res.size(); i ++){
				if (i == b[md]) printf("(");
				if (i > 50){
					break;
				}
				printf("%d", res[i]);
				if (i == 0) printf(".");
			}
			if (flag)	printf("...");	
			printf(")\n");
		}
		printf("   %d = number of digits in repeating cycle\n\n", cnt);
	}
}
