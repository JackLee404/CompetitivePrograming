/*
  	Feeling sad about this contest, and know that my weakness that is "simulation", this contest doesn't have any graph about the most shortest road,
  and they giva a binary graph about tree;
  	All in all, The code is very foolish;
*/
#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#define f first
#define s second
#define rep(i, j, k) for (int i = j; i <= k; ++ i)
using namespace std;
const int N = 1e6 + 10;

stack<char> s1;
int cons = 0, ans[7], min1, max1;
vector<pair<int, int>> res1, res2;
void act(int type){
	int t1 = 0, t2 = 0;
	vector<int> a, b;
	if (type){
		while (s1.size() && s1.top() != 'd'){
			a.push_back(s1.top() - '0');
			s1.pop();
		}
		rep (i, 0, a.size() - 1){
			if (i == 0) t1 += a[i];
			else t1 += a[i] * i * 10;
		}
		if (s1.empty()){
			cons += t1;
			return;
		}
		s1.pop();
		if (s1.empty()){
			res1.push_back({1, t1});
			ans[t1] ++;
			return;
		}
		while (s1.size()){
			b.push_back(s1.top() - '0');
			s1.pop();
		}
		rep (i, 0, b.size() - 1){
			if (i == 0) t2 += b[i];
			else t1 += b[i] * i * 10;
		}
		res1.push_back({t2, t1});
		ans[t1] += t2;
	}
	else {
		while (s1.size() && s1.top() != 'd'){
			a.push_back(s1.top() - '0');
			s1.pop();
		}
		rep (i, 0, a.size() - 1){
			if (i == 0) t1 += a[i];
			else t1 += a[i] * i * 10;
		}
		if (s1.empty()){
			cons -= t1;
			return;
		}
		s1.pop();
		if (s1.empty()){
			res1.push_back({1, t1});
			ans[t1] ++;
			return;
		}
		while (s1.size()){
			b.push_back(s1.top() - '0');
			s1.pop();
		}
		rep (i, 0, b.size() - 1){
			if (i == 0) t2 += b[i];
			else t1 += b[i] * i * 10;
		}
		res2.push_back({t2, t1});
		ans[t1] += t2;
	}
}

int main(){
	string a;
	bool flag = false;
	char last;
	cin >> a;
	rep (i, 0, a.size() - 1){
		if ((a[i] == '+' || a[i] == '-') && flag == false){
			flag = true;
			act(1);
			last = a[i];
		}
		else if (a[i] == '+' || a[i] == '-' && flag == true){
			if (last == '+')
			act(1);
			else if(last == '-')
			act(0);
			last = a[i];
		}
		else s1.push(a[i]);
	}
	if (s1.size()){
		if (last == '+') act(1);
		else act(2);
	}
	rep (i, 1, 6){
		if (!ans[i]) continue;
		cout << i << " " << ans[i] << endl;
	}
	for (auto x : res1){
		int a = x.f, b = x.s;
		min1 += x.f;
		max1 += x.f * x.s;
	}
	for (auto x : res2){
		int a = x.f, b = x.s;
		min1 -= x.f * x.s;
		max1 -= x.f;
	}
	cout << min1 + cons << " " << max1 + c << endl;
} 
