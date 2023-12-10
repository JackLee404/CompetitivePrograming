#include <bits/stdc++.h>

const int N = 2e5 + 10;

using i64 = long long;

using namespace std;

int p[N];

i64 d[N];

int find(int x)
{
	if(x != p[x])
	{
		int r = find(p[x]);
		d[x] += d[p[x]];
		p[x] = r;
	}
	
	return p[x];
}

void merge(int x,int y,int t)
{
	int px = find(x),py = find(y);
	p[px] = py;
	d[px] = d[y] - d[x] + t;	
}

void solve()
{
	int n,m;
	cin>>n>>m;
	
	bool OK = true;
	
	for(int i = 1; i <= n; i ++ )	
	p[i] = i,d[i] = 0;
	
	while(m -- )
	{
		int a,b,c;
		cin>>a>>b>>c;
		int pa = find(a),pb = find(b);
		
		if(pa == pb)
		{
			if(d[a] - c != d[b])OK = false;
		}
		else merge(a,b,c);
	}
	
	cout<<(OK?"YES\n":"NO\n");
}

int main() {
	int _; std::cin >> _;
	while (_ --) {solve();}
}