#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8";
const char* msg[] = {"is not a palindrom", "is a regular palindrom", "is a mirrored string", "is a mirrored palindrome"};

char r(char ch){
	if (isalpha(ch)) return rev[ch - 'A'];
	else return rev[25 + ch - '0'];
}

int main(){
	char ch[30];
	while (scanf("%s", ch) == 1){
		bool con1 = true, con2 = true;
		for (int i = 0, j = strlen(ch) - 1; i < j; i ++, j --){
			if (ch[i] != ch[j]) con1 = false;
			if (r(ch[j]) != ch[i]) con2 = false;
		}
		if (con1 && con2) puts(msg[3]);
		else if(!con1 && !con2) puts(msg[0]);
		else if(!con1) puts(msg[2]);
		else puts(msg[1]);
	}
}

// The Author have a neat way to solve four if else distribution, and is very well program!

int main(){
	char ch[30];
	while (scanf("%s", ch) == 1){
		int m = 1, p = 1;
		for (int i = 0, j = strlen(ch) - 1; i < j; i ++, j --){
			if (ch[i] != ch[j]) p = 0;
			if (r(ch[j]) != ch[i]) m = 0;
		}
		puts(msg[2 * m + p]);
	}
}
