#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#include <set>
#include <cmath>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define siz(v) ((int) v.size())
#define judge(x, y) (x >= 1 && x <= n && y >= 1 && y <= m)
#define mahaton(x1, y1, x2, y2) (abs(x1 - x2) + abs(y1 - y2))
using namespace std;

typedef pair<int, int> PII ;
typedef long long LL;

const int N = 1e5 + 10;

const LL big = 1e12;

using namespace std;


int n, ec, et, p, s;

int a[N];

set<PII> s1;

// 1 money just enough for training
// 2 traning done 
// 3 occupied done

int main() {
	cin >> n >> ec >> et >> p >> s;

	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	if (s < ec) {
		puts("-1");
		return 0;
	}

	// pt表示已经占领了的油田数量
	LL pt = 0, money = s - ec, training = 1, ms = 0, last_time = 0, man = 0;

	// nxt 下一个需要占领的, 当然前面不一定全占领， 但是再时间线上是全占领的
	LL nxt = 1;

	s1.insert({et, 2});

	/*
		由于占领油田后金钱产生数量发生改变, 所以需要增加 1事件(最少需要钱来产生工程师)来维护其数值
	*/

	LL ans = -1;

	while (s1.size()) {

		auto t = (*s1.begin());
		// cout << "time:" << t.f << " action:" << t.s << " money:" << money << endl;
		s1.erase(s1.begin());

		money = min(money + min(ms * (t.f - last_time), big), big);

		if (t.s == 2) {

			// 预测下一次工程师时间
			if (ms && money < ec) {
				s1.insert({t.f + ceil((ec - money) * 1.0 / ms), 1});
			}
			training = 0;
			man ++;

		} else if (t.s == 3) {
			ms += p;
			pt ++;
			// 更新生产工程师最小需要时间
			if (ms && money < ec) {
				s1.insert({t.f + ceil((ec - money) * 1.0 / ms), 1});
			}
// 			if (pt >= n) {
// 				cout << t.f;
// 				return 0;
// 			}
		}

		if (nxt <= n && man) {
			s1.insert({t.f + a[nxt], 3});
			ans = max(ans, (LL)t.f + a[nxt]);
			nxt ++;
			man --;
		}

		if (!training && money >= ec) {
			s1.insert({t.f + et, 2});
			training = 1;
			money -= ec;
		}
		if (ms && money < ec) {
			s1.insert({t.f + ceil((ec - money) * 1.0 / ms), 1});
		}

		last_time = t.f;
        if (nxt == n + 1) break;
	}

	cout << ans;
}