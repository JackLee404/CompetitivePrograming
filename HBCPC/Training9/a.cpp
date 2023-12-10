#include <iostream>
#include <map>
using namespace std;

map<string, int> mp;

int main() {
	int n;
	cin >> n;
	string a;
	for (int i = 1;i <= n; i ++) {
	    cin >> a;
	    mp[a] ++;
	}
	auto iter = mp.begin();
	if (mp.size() == 1) {
	    cout << (*iter).first;
	}
	else {
    	auto iter2 = mp.begin();
        iter2 ++;
        if ((*iter2).second > (*iter).second) {
            cout << (*iter2).first;
        } else   cout << (*iter).first;
	}
}