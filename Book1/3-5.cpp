#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#define LOCAL
using namespace std;
const int N = 1e5 + 10;

int main(){
	char c;
	int q = 0;
	while ((c = getchar()) != EOF){
		if (c == '"') {printf("%s", q ? "``" : "''"); q = !q;}
		else printf("%c", c);
	}
}
