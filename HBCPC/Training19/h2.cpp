#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
using namespace std;

/*
	1.身份证号可以唯一确定一个人
	能发放口罩的要求:
	1.身份证18位可以包含前导0
	2.同一个身份证i天成功 i + p + 1天才可以申请
	3.如果1和2符合时间顺序发放, 时间相同，则按列表先后顺序
*/

int d, p, now;

map<string, int> data1;
map<string, int> data2, data3;

struct info{
	string name, id, state, time;
	int lid;
// 	bool operator < (struct info b) {
// 		if (this->time == b.time) {
// 			return this->lid > b.lid;
// 		} else {
// 			return this->time > b.time;
// 		}
// 	}
};

vector<info> v;
vector<info> v2;
vector<info> gotv;

bool check(string a) {
   for (auto &x: a) {
       if (x > '9' || x < '0'){
           return false;
       }
   }
   return true;
}

void patient_state_record_check(info x) {
// 	for (auto &x: v) {
		if (x.state == "1" && data2[x.id] == 0){
			v2.push_back(x);
			data2[x.id] = 1;
		}
// 	}
}

void input(int list_id) {
    data3.clear();
	string a, b, c, d;
	cin >> a >> b >> c >> d;
    if (b.size() == 18 && check(b)) patient_state_record_check({a, b, c, d, list_id});
	if (b.size() == 18 && check(b) && ((now < data1[v[i].id]) || data1.find(b) == d) && !data3[b]) {
		v.push_back({a, b, c, d, list_id});
        data3[b] = 1;
	}
}

void distribute(int tot) {
	for (int i = 0; i < v.size() && tot > 0; i ++) {
		data1[v[i].id] = now + p + 1;
		tot --;
		gotv.push_back(v[i]);
	}
}

void close() {
	v.clear();
	gotv.clear();
}

void out() {
	for (auto &x: v2) {
		cout << x.name << " " << x.id << "\n";
	}
}

int main() {
	cin >> d >> p;
	rep(i, 1, d) {
		now ++;
		int t, s;
		cin >> t >> s;
		rep (i, 1, t) {
			input(i);
		}
// 		patient_state_record();
		sort(v.begin(), v.end(), [](info &a, info &b) {
            if (a.time == b.time) {
                return a.lid < b.lid;
            } else {
                return a.time < b.time;
            }
        });
		distribute(s);
		for (auto &x: gotv) {
			cout << x.name << " " << x.id << "\n";
		}
		close();
	}
	out();
}