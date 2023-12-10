#include <bits/stdc++.h>
#define ff first
#define ss second

using i64 = long long;

const int N = 1e5 + 10;

typedef std::pair<int, int> PII;

int n, m, l, tim[N];

PII cust[N];

std::priority_queue<PII, std::vector<PII>, std::greater<PII>> heap;
std::priority_queue<int, std::vector<int>, std::greater<int>> bucket;

std::queue<PII> q1;

std::vector<PII> res;

int num[N], pt;

std::unordered_map<int, int> idx, where;

int main() {
	std::cin >> n >> m >> l;
	
	for (int i = 1; i <= m; i ++) bucket.push(i);
	
	for (int i = 1; i <= n; i ++) std::cin >> tim[i];
	
	for (int i = 1; i <= l; i ++) {
		PII t;
		
		std::cin >> t.ff;
	
		t.ff = tim[t.ff];
		t.ss = i;
		
		q1.push(t);
	}
	
	int tag = 0, now = 0, last_time = 0;
	
	while (q1.size() || heap.size()) {
		while (heap.size() != m && q1.size()) {
			auto t = q1.front(); q1.pop();
			idx[bucket.top()] ++, where[t.ss] = bucket.top(), bucket.pop();
			t.ff += last_time;
			heap.push(t);
		}
		
		if (heap.empty()) continue;
		
		auto t1 = heap.top(); heap.pop();
		bucket.push(where[t1.ss]);
		
//		std::cout << t1.ff << " "  << t1.ss << " " << last_time << "\n";
		
		last_time = t1.ff;
		
		res.push_back({t1.ss, t1.ff});
		
		while (heap.size() && heap.top().ff - last_time <= 0) {
			res.push_back({heap.top().ss, heap.top().ff});
			bucket.push(where[heap.top().ss]);
			heap.pop();
		}
	}
	
	for (int i = 0; i < (int) res.size(); i ++) {
		std::cout << res[i].ff << ":" << res[i].ss << " \n"[i == (int) res.size() - 1];
	}
	
	
	
	for (int i = 1; i <= m; i ++) {
		std::cout << idx[i] << " \n"[i == m];
	}
}
