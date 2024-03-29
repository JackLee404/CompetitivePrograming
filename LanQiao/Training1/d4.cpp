#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
int d[1000001];
int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "rt", stdin);
//     freopen("output.txt", "wt", stdout);
// #endif
    int n;
    cin>>n;
    forn(i,1,10) d[i] = 1;
    forn(i,10,1000001) {
        int x = i;
        d[i] = 1e9;
        while(x > 0) {
            int r = x%10;
            x/=10;
            if(r>0) d[i] = min(d[i], d[i-r] + 1);
        }
    }
    cout<<d[n];
}


