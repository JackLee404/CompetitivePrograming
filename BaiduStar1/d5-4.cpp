#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int head, e[N], ne[N], idx;

void init() {
	head = -1;
	idx = 0;
}

void add(int b) {
	ne[idx] = head, e[idx] = head, head = idx ++;
}

/*
	插入 1

	下标

	ne[0] = -1;

	head = 0, e[0] = 1;

	插入 2

	下标

	ne[1] = 0

	head = 1, e[1] = 2
*/	

int main() {
	init();
}