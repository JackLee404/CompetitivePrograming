#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> PII;

vector<string> a(9);

int main() {
    
    auto valid = [&](int x, int y){
        return (x >= 0 && x <= 8) and (y >= 0 && y <=8) and a[x][y] == '#';
    };
    
    for (auto& v: a) {
        cin >> v;
    }

    set<set<PII>> st;

    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            for (int dx = -8; dx <= 8; dx ++) {
                for (int dy = -8; dy <= 8; dy ++) {
                    if (!dx and !dy) continue;
                    
                    int i1 = i + dx, j1 = j + dy;
                    int i2 = i1 + dy, j2 = j1 - dx;
                    int i3 = i2 - dx, j3 = j2 - dy;

                    if (valid(i, j) && valid(i1, j1) && valid(i2, j2) && valid(i3, j3)) {
                        set<PII> tmp;
                        tmp.insert({i, j}), tmp.insert({i1, j1}), tmp.insert({i2, j2}), tmp.insert({i3, j3});
                        st.insert(tmp);
                    }
                }
            } 
        }
    }
    cout << st.size() << endl;
}