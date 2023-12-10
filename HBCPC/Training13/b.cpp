#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

char a[N], b[N];

int l1, l2;

void gt() {
	cout << "Happy birthday to MFGG" << endl;
}

void lit() {
	cout << "Happy birthday to YXGG" << endl;
}

void eq() {
	cout << "PLMM" << endl;
}

int main() {
	cin >> a >> b;
	l1 = strlen(a), l2 = strlen(b);
    
	if (b[0] < '5') {
		if (b[0] == '0') {
			bool check = false;
			for (int i = 1; i < l2; i ++) {
				if (b[i] != '0')
					check = true;
			}
			if (!check)
				eq();
			else
				lit();
		} else {
			lit();
		}
        
	} else if (b[0] == '5') {
		bool check = false;
        
		for (int i = 1; i < l2; i ++) {
			if (b[i] != '0')
				check = true;	
		}
        
		if (!check) {
            int tag;
			if ((a[l1 - 1] - '0') % 2 == 0)
				lit();
			else
				gt();
		} else {
			gt();
		}
        
	} else {
		gt();
	}
}