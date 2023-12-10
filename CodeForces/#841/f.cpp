#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int prefix[310], cnt = 0;
        auto act = [&](int &t)->int{
            if (t < 0) return 0;
            else {
                return prefix[t];
            }
        };
        for (int i = 0; i < arr.size(); i ++) {
            if (!i) prefix[i] = arr[i];
            else prefix[i] = arr[i] ^ prefix[i - 1];
        }
        for (int i = 0; i < arr.size(); i ++) {
            for (int j = i; j < arr.size(); j ++) {
                for (int k = j; k < arr.size(); k ++) {
                    if (act(i - 1) ^ act(j - 1) == act(k) ^ act(j - 1)) {
                        cnt ++;
                    }
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution a;
    vector<int> arr;
    a.countTriplets(arr);
}