#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#define LOCAL
using namespace std;

int main(){
	int count = 0;
	char buf[100], s[20];
	scanf("%s", s);
	for (int abc = 111; abc <= 999; abc ++){
		for (int de = 11; de <= 99; de ++){
			int x = abc * (de % 10), y = abc * (de / 10), z = abc * de;
			sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
			bool ok = true;
			for (int i = 0; buf[i]; i ++){
				if (strchr(s, buf[i]) == NULL) ok = false;
			}
			if (!ok) continue;
			printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%-5d\n-----\n%5d\n\n", ++ count,  abc, de, x, y, z);
		}
	}
	printf("The number of solutions = %d\n", count);
}
