#include <iostream>
#include <cctype>

using namespace std;

typedef long long LL;

int n, m, idx;

char a[200][200];

int sx, sy;

int search(int d) {
	bool flag1, flag2, flag3, flag4;
	flag1 = flag2 = flag3 = flag4 = true;
	int cnt = 0;
	if (d == 1) {
		for (int b = 2; b <= 100; b ++) {		
			if (sx - b < 1 || sy + b > m) {
				break;
			}
			flag1 = true;
			cout << b << endl;
			for (int i = 1; i < 2; i ++) {
				int x = sx - i, y = sy + i;
				printf("(%d, %d)", x, sy);
				printf("(%d, %d)", sx, y);
				if (a[x][sy] != a[sx][sy] || a[sx][y] != a[sx][sy]) {
					flag1 = false;		
				}
			}
			if (flag1) cnt ++;
		}
	} else if (d == 2) {
		for (int b = 2; b <= 100; b ++) {
			if (sx - (b - 1) >= n) {
				break;
			}	
		}
	} else if (d == 3) {

	} else if (d == 4) {

	}
	return cnt;
}

int main() {
	cin >> n >> m; 
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j];
		}
	}
	sx = 3, sy = 2;
	cout << search(1);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			sx = i, sy = j;
		}
	}
}

/*
4 4
AAAA
ABAA
ABBA
AAAA

4 4
ABAA
ABBA
ABBB
AAAA
*/


// 没做出来
/* 这里复制一下参考答案
参考答案
数据不大，直接暴力的话时间复杂度是O ( n 3 ) O(n^3)O(n 
3
 ) 不会超时。
使用双层循环遍历矩阵中每个元素，令每个遍历的元素为三角形的直角，并对上下左右不同大小的可能三角形进行判断并计数即可。

#include<iostream>
#include<string>
#include<stack>
#include <map>
#include<algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>

using namespace std;
typedef long long ll;
vector<string> a;

bool inline check(int i, int j, int n, int m, int dir) {
    if (dir == 1) {
        for (int ii = i, jj = j; ii <= n && jj <= m; ii++, jj++) {
            if (a[ii][jj] != a[i][j])return false;
        }
    } else if (dir == 2) {
        for (int ii = i, jj = j; ii <= n && jj >= m; ii++, jj--) {
            if (a[ii][jj] != a[i][j])return false;
        }
    } else if (dir == 3) {
        for (int ii = i, jj = j; ii >= n && jj >= m; ii--, jj--) {
            if (a[ii][jj] != a[i][j])return false;
        }
    } else if (dir == 4) {
        for (int ii = i, jj = j; ii >= n && jj <= m; ii--, jj++) {
            if (a[ii][jj] != a[i][j])return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        a.push_back(temp);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = 0, down = 0, left = 0, right = 0;
            while (i - up > 0 && a[i - up][j] == a[i][j])
                up++;
            while (i + down < n && a[i + down][j] == a[i][j])
                down++;
            while (j - left > 0 && a[i][j - left] == a[i][j])
                left++;
            while (j + right < m && a[i][j + right] == a[i][j])
                right++;

            for (int ii = 1; ii < min(up, right); ii++) {
                if (check(i - ii, j, i, j + ii, 1))
                    ans++;
            }
            for (int ii = 1; ii < min(down, right); ii++) {
                if (check(i, j + ii, i + ii, j, 2))
                    ans++;
            }
            for (int ii = 1; ii < min(down, left); ii++) {
                if (check(i + ii, j, i, j - ii, 3))
                    ans++;
            }
            for (int ii = 1; ii < min(up, left); ii++) {
                if (check(i, j - ii, i - ii, j, 4))
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
————————————————
版权声明：本文为CSDN博主「上山打老虎D」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/m0_46326495/article/details/127720544
*/