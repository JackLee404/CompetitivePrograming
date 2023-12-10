#include <bits/stdc++.h>
#define debug(x) std::cerr << "#debug:" << x << "\n"; 
#define rep(i, j, k) for(int i = j; i <= k; i ++)
#define per(i, j, k) for(int i = j; i >= k; i--)
#define lowbit(x) x&(-x)
using i64 = long long;

/**
 * ���⣺
 * �����ַ���a, b�������滻a�е��ַ���������ָ���˿����滻���ַ���k
 * k��ȡֵ��Χ������10
 * ˼·��
 * 2^10 = 1024, ���ǿ���ö��2���ƣ���鵱ǰ2�����Ƿ񳬹�k, �Ϸ��Ļ����в�����һ�¹���
 * ����: m = r - l,  �����乱��Ϊ (m + 1)/ 2 * m
*/

int count(int x) {
	int cnt = 0;
	for(int i = 0; i < 10; i ++) {
		if(x >> i & 1) cnt ++;
	}
	return cnt;
}

int vis[300];

void solve() {
	memset(vis, 0, sizeof vis);
	int n, k, cnt;
	std::cin >> n >> k;

	std::string a, b;
	std::cin >> a >> b;

	std::map<char, int> mp;

	rep(i, 0, n - 1) {
		if(!mp.count(a[i])) mp[a[i]] = cnt ++;
	}

	if(cnt <= k) {
		std::cout << "1\n";
		return;
	}

	int ans = -1;

	for(int S = 0; S < (1ll<<cnt); S ++) {
		if(count(S) > k) continue;
		int res = 0;
		for (int i = 0; i < n; i++ ) {
             int j = i;
             while (j < n && (a[j] == b[j] || (mp[a[j]] && ((S >> mp[a[j]] & 1))))) j++;
             res += (j - i) * (j - i + 1) / 2;
             i = j;
         }
         ans = std::max(ans, res);
	}		

	std::cout << ans << "\n";
}

int main() {
    int _;
    std::cin >> _;
    while(_ --) {
        solve();
    }
}
