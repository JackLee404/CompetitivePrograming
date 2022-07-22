#include <iostream>
#include <cstdio>
#include <cstring>

int code[8][1<<7];
int readchar(){
	for (;;){
		char ch = getchar();
		if (ch != '\n' && ch != '\r') return ch;
	}
}
int readcodes(){
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();
	for (int len = 2; len <= 7; len ++){
		for (int i = 0; i < (1 << len) - 1; i ++){
			char ch = getchar();
			if (ch == EOF) return 0;
			if (ch == '\n' || ch == '\r') return 1;
			code[len][i] = ch;
		}
	}
	return 1;
}
int readint(int c){
	int v = 0;
	while (c --)
		v = v * 2 + readchar() - '0';
	return v;
}

int main(){
	while (readcodes()){
		for (;;){
			int len = readint(3);
			if (len == 0) break;
			for (;;){
				int v = readint(len);
				if (v == (1 << len) - 1) break;
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
	return 0;
}

/*  a neat code found in vjudge
    and learn the scanf in https://qa.1r1g.com/sf/ask/3897045141/
*/
#include <bits/stdc++.h>
using namespace std;
char HEAD[1<<9];
int deBin(int len){
    int res=0;
    while(len){
        char ch=getchar();
        while(ch!='0'&&ch!='1') ch=getchar();
        res+=(1<<(--len))*(ch-'0');
    }
    return res;
}
char deCode(int len, int code){
    return HEAD[(1<<len)-len-1+code];
}
int main(){
    while(~scanf("%[^\n]%*c", HEAD)){
        for (int len=deBin(3); len; len=deBin(3))
            for (int code=deBin(len); code!=(1<<len)-1; code=deBin(len))
                putchar(deCode(len, code));
        putchar('\n');
        getchar();
        memset(HEAD, 0, sizeof(HEAD));
    }
    return 0;
}
