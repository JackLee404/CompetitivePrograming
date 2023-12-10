#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

int a[N], stk[N];

vector<int> record[N];

/*
    record小标记录的数单调递减， 下标也单调递增
    我们想要满足条件的最小下标
*/

int main() {
	int n, len = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	stk[0] = -1;
	for(int i = 1; i <= n; i ++) {
		int l = 0, r = len;
		while(l < r) {
			int mid = l + r + 1 >> 1;
			if(stk[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		len = max(l + 1, len);
		record[l + 1].push_back(i);
		stk[l + 1] = a[i];
	}
	cout << len << "\n";
    for(int i = 1; i <= len; i ++) {
        cout << "len: " << i << "->";
        for(int j = 0; j < record[i].size(); j ++) {
            cout << record[i][j] << " \n"[j == (int) record[i].size() - 1];
        }
    }
	vector<int> curr;
	for(int i = len; i >= 1; i --) {
		if(i == len) curr.push_back(record[i][0]);
		else {
			int pos = (int) record[i].size() - 1;
 			while(pos >= 0 && a[record[i][pos]] >= a[curr.back()]) pos --;
			curr.push_back(record[i][pos]);
		}	
	}
	for(int i = (int) curr.size() - 1; i >= 0; i --) {
		cout << curr[i] << " \n"[i == 0];
	}
}