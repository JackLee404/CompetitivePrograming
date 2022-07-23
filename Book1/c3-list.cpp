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
using namespace std;
double mp[256];
void solve(){
	int k;
	double sum = 0;
	string a;
	cin >> a;
	for (int i = 0; i < (int)a.size(); i ++){
		if (isdigit(a[i])) continue;
		if (i + 1 < (int)a.size() && isdigit(a[i + 1])){
			int j = i + 1;
			k = 0;
			while (j < (int)a.size() && isdigit(a[j])){
				k = k * 10 + a[j ++] - '0';
			}
		}
		else k = 1;
		sum += k * mp[a[i]];
	}
	printf("%.3f\n", sum);
}

int main(){
	mp['C'] = 12.01, mp['H'] = 1.008, mp['O'] = 16.00, mp['N'] = 14.01;
	int _;
	cin >> _;
	while (_--){
		solve();
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

// 3-4
#include <iostream>

using namespace std;

void solve(){
	int ans = 1;
	string a;
	cin >> a;
	int i = 0, j = a.size() - 1;
	for (int len = 1; len <= a.size(); len ++){
		bool flag = true;
		if (a.size() % len == 0){
			for (int i = 0; i < a.size(); i += len){
				if (a.substr(0, len) != a.substr(i, len)) flag = false;
			}
			if (flag) {
				ans = len;
				break;
			}
		}
	}
	cout << ans << "\n\n";
}

int main(){
	int _;
	cin >> _;
	while (_ --){
		solve();
	}
}

// 3-5
#include <iostream>
#include <cstring>
#define LOCAL
using namespace std;
char a[10][10], b[10][10], act[10000];

bool go_legal(int x, int y){
	if (x < 5 && x >= 0 && y < 5 && y >= 0) return true;
	return false;
}

char readchar(){
	char ch;
	while (ch = getchar())
	if (ch != '\n' && ch != '\r') return ch;
}

void printcode(){
	for (int i = 0; i < 5; i ++){
		for (int j = 0; j < 5; j ++){
			printf("%c", a[i][j]);
			if (j != 4) printf(" ");
		}
		puts("");
	}
}

bool find_space(int &x, int &y){
	// printcode();
	bool ask = false;
	for (int i = 0; i < 5; i ++)
		for (int j = 0; j < 5; j ++)
			if (a[i][j] == '\0' || a[i][j] == ' ') x = i, y = j, ask = true;
	if (!ask) return 0;
	else return 1;
}

int solve(int num){
	memset(act, 0, sizeof(act));
	memset(a, 0, sizeof(a));
	int x, y;
	for (int i = 0; i < 5; i ++){
		bool eat = true;
		for (int j = 0; j < 5; j ++){
			if (scanf("%c", &a[i][j]) == EOF) return 0;
			if (a[i][j] == '\0' || a[i][j] == '\r' || a[i][j] == '\n') a[i][j] = ' ', eat = false;
 		}
 		if (eat)
		getchar();
	}
	if (!find_space(x, y)) return 1;
	else printf("Puzzle #%d:\n", num);
	for (int i = 0;; i ++){
		act[i] = readchar();
		if (act[i] == '0') break;
	}
	getchar();
	// cout << x << " " << y << endl;
	// puts(act);
	for (int i = 0; act[i] != '0'; i ++){
		int kx = 0, ky = 0;
		if (act[i] == 'A') kx --;
		else if (act[i] == 'B') kx ++;
		else if (act[i] == 'L') ky --;
		else if (act[i] == 'R') ky ++;
		if (!go_legal(x + kx, y + ky)){
			puts("This puzzle has no final configuration.");
			puts("");
			return 1;
		}
		swap(a[x][y], a[x + kx][y + ky]);
		x += kx, y += ky;
	}
	printcode();
	puts("");
	return 1;
}

int main(){
	#ifdef LOCAL
		freopen("data.in", "r", stdin);
		freopen("data.out", "w", stdout);
	#endif
	int k = 0;
	while (solve(++ k)){
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
		res.push_back(n / m);
		if (res.size() - b[md] > 50) flag = true;
		if (!md){
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

// 3-9
#include <iostream>

using namespace std;

int main(){
	string s, t;
	int tag;
	while (cin >> t >> s){
		tag = 0;
		for (int i = 0; i < s.size(); i ++){
			if (tag < t.size() && s[i] == t[tag]) tag ++;
		}
		if (tag == (int)t.size()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
