#include <bits/stdc++.h>

using namespace std;
int hash_1[256];
int main(){
	int num;
	while (cin >> num && num != -1){
		int wa = 0, ok = 0, tot = 0;
		cout << "Round " << num << endl;
		memset(hash_1, 0, sizeof(hash_1));
		string a, b;
		cin >> a >> b;
		for (int i = 0; i < a.size(); i ++){
			if (!hash_1[a[i]]) tot ++;
			hash_1[a[i]] = 1;
		}
		for (int i = 0; i < b.size(); i ++){
			if (!hash_1[b[i]]) wa ++;
			else hash_1[b[i]] = 0, ok ++;
			if (wa > 6) break;
			else if (ok == tot) break;
		}
		if (wa > 6) puts("You lose.");
		else if (ok == tot) puts("You win.");
		else puts("You chickened out.");
	}
}
