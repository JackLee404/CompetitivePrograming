#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
#include <numeric>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
typedef long long LL;
using namespace std;

const int N = 1e5 + 10;

int v1[N];


bool act1(LL &res, int s, int e, int c, int wh) {
  if (res == -1e9) return false;
  if (!wh) {
  	for (int i = s; i >= e; i --) {
  		if (v1[i] & 1) {
  		  res += v1[i] * c;
	      return true;
	    }
  	}
  } else {
  	for (int i = s; i < e; i ++) {
	  	if (v1[i] & 1) {
	  	  res += v1[i] * c;
	      return true;
	    }
  	}
  }
  res = -1e9;
  return false;
}

bool act2(LL &res, int s, int e, int c, int wh) {
  if (res == -1e9) return false;
  if (!wh) {
  	for (int i = s; i >= e; i --) {
  		if (!(v1[i] & 1) && v1[i]) {
  		  res += v1[i] * c;
	      return true;
	    }
  	}
  } else {
  	for (int i = s; i < e; i ++) {
	  	if (!(v1[i] & 1) && v1[i]) {
	  	  res += v1[i] * c;
	      return true;
	    }
  	}
  }
  res = -1e9;
  return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	rep (i, 0, n - 1) {
		cin >> v1[i];
	}
	
	sort(v1, v1 + n,greater<int>());
	
	while (m --) {
		int t;
		cin >> t;	


		LL res = 0;
		for (int i = 0; i < t; i ++) {
		  res += v1[i];
		}
		
		// if (t == 0) {
		//   cout << -1 << endl;
		//   continue;
		// }
		
		if (res & 1) {
		  cout << res << endl;
		} else {
		    LL res1, res2;

		    res1 = res2 = res;

		    bool check1 = act2(res2, t - 1, 0, -1, 0) && act1(res2, t, n, 1, 1);
		      
		    bool check2 = act1(res1, t - 1, 0, -1, 0) && act2(res1, t, n, 1, 1);

		    // cout << check1 << " " << check2 << endl;
		    
			if (!check1 && !check2)
			    cout << -1 << endl;
			else if (check1) {
			    cout << res1 << endl;
			} else {
			    cout << res2 << endl;
			}
		}
	}
}

// 4 3 2 1
// 10 - 2 = 8, true
// 8, t~v1.size() 4~4
// 16 - 4 + 1 = 13

// 18 - 2 + 1 = 17
// 15 - 1 + 0 = 14
// 15 - 2 + 0 = 13


// 7
// 5 4 4 3 2 1 0
// 1
// 1
// 3
// 2
// 7
// 7
// 15
// 6
// 15
// 5
// 13