#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 10;

vector<vector<string>> v;

unordered_map<string, int> en;

bool f1;

unordered_map<string, vector<string>> g;

void bfs() {
    priority_queue<string, vector<string>, greater<string>> q1;
    for (auto &x: en) {
        if (!x.second) {
            q1.push(x.first);
        }
    }
    while (q1.size()) {
        string t = q1.top(); q1.pop();
        if (f1 != false)
            cout << ".";
        else
            f1 = true;
        cout << t;
        for (auto &x: g[t]) {
            if (!--en[x]) {
                q1.push(x);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;

    auto act = [](vector<string> &a, vector<string> &b) {
        if (a.size() != b.size()) return;
        for (int i = 0; i < a.size(); i ++) {
            if (a[i] == b[i]) continue;
            g[a[i]].push_back(b[i]);
            en[b[i]] ++;
            break;
        }
    };

    auto init = [](string &b) {
        vector<string> t;
        string s1;
        for (int i = 0; i < b.size(); i ++) {
            if (b[i] == '.') {
                t.push_back(s1);
                if (!en.count(s1)) en[s1] = 0;
                s1.clear();
            } else {
                s1.push_back(b[i]);
            }
        }
        if (s1.size()) {
            if (!en.count(s1)) en[s1] = 0;
            t.push_back(s1);
        }
        v.push_back(t);
    };

    for (int i = 1; i <= n; i ++) {
        string t; cin >> t; 
        init(t);
        if (i != 1) {
            int k = v.size();
            act(v[k - 2], v[k - 1]);
        }
    }
    
    bfs();
}