#include <bits/stdc++.h>
#define siz(t) t.size()
using namespace std;

const char num[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

// 10 100 1000 10000 10000,0000

const char unit[] = {'S', 'B', 'Q', 'W', 'Y'};

string t;

void out4(string t) {
    reverse(t.begin(), t.end());
    vector<char> ans;
    if(siz(t) <= 4) {
        for(int i = siz(t) - 1; i >= 0; i --) {
            ans.push_back(num[t[i] - '0']);
            // cout << num[t[i] - '0'];
            if(i > 0 && t[i] != '0') {
                ans.push_back(unit[i - 1]);
                // cout << unit[i - 1];
            }
        }
    }
    while (ans.back() == 'a') ans.pop_back();
    for (auto &x: ans) {
        cout << x;
    }
}

int main() {
    cin >> t;
    string t2;
    if (t.size() == 9) {
        cout << num[t[0] - '0'];
        cout << "Y";
        t.erase(t.begin());
    }

    t2 = t;



    reverse(t.begin(), t.end());


    //3108  8013
    if (siz(t) <= 4) out4(t2);
    // for(int i = siz(t) - 1; i >= 0; i --) {
    //     cout << num[t[i] - '0'];
    //     if(i > 0 && t[i] != '0') {
    //         cout << unit[i - 1];
    //     }
    // }

    // out4("1322");

    if(siz(t) > 4 && siz(t) < 9) {
        // for (int i = siz(t) - 1; i >= 4; i --) {
        //     cout << num[t[i] - '0'];
        //     if(i > 0 && t[i] != '0') {
        //         cout << unit[i - 1];
        //     }
        // }
        string t1 = t2.substr(0, siz(t) - 4);
        // cout << "\n" << t1 << endl;
        out4(t1);
        cout << "W";
        string t3 = t2.substr(siz(t) - 4);
        out4(t3);
    }
}