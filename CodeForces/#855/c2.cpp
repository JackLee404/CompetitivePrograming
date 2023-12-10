#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define FASTIO                \
    std::ios ::sync_with_stdio(0); \
    std::cin.tie(0);               \
    std::cout.tie(0);

using i64 = long long;

const int MAXN = 1e5;

std::vector<i64> factors[MAXN + 10];

void init() {
        for(int i = 1; i <= MAXN; i ++) {
                for(int j = i; j <= MAXN; j += i) {
                        factors[j].push_back(i);
                }
        }
}

void solve() {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::pair<i64, i64>> vec;
        std::vector<int> frequency(m + 1, 0);

        for(int i = 0; i < n; i ++) {
                i64 val;
                std::cin >> val;
                vec.push_back({val, i});
        }

        std::sort(vec.begin(), vec.end());

        i64 global_ans = INF, curr_ans = 0, curr_count = 0;

        int j = 0;

        for(int i = 0; i < n; i ++) {

                for(auto x: factors[vec[i].first]) {
                        if(x > m)
                                break;
                        std::cout << "debug:" << x << "\n";
                        if(!frequency[x] ++) {
                                curr_count ++;
                        }
                }

                while(curr_count == m) {
                        curr_ans = vec[i].first - vec[j].first;
                        global_ans = std::min(global_ans, curr_ans);

                        for(auto x: factors[vec[j].first]) {
                                if(x > m)
                                        break;
                                if(!-- frequency[x]) {
                                        curr_count --;
                                }
                        }
                        j ++;
                }
        }

        std::cout << (global_ans >= INF? -1: global_ans) << "\n";
}

int main() {
    init();
        int _;
        std::cin >> _;
        while(_ --) {
                solve();
        }
}