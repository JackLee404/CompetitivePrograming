#include <bits/stdc++.h>

using i64 = long long;

int n, m, k;

/*
	小盒子 栈， 推送器 栈
	
	先取小盒子里面的， 如果小盒子没有或者不满足，就去取推送器上的

	每一步不能比前面的松针片大
		推送器上的不满足，放到小盒子里面，继续取推送器

	下面的情况会继续下一个：
		1. 小盒子满了，推送器头部不满足
		2. 小盒子不满足，推送器也没有了
		3. 松枝已经插满松条
*/

std::stack<int> s1, box;

std::vector<int> tree;


int pushbox() {
	if (box.empty()) return -1;
	int t = box.top();
	box.pop();
	return t;
}

int push2() {
	if (s1.empty()) return -1;
	int t = s1.top();
	s1.pop();
	return t;
}


// 1表示正常插入， 0表示下一个松枝，-1表示结束

int act() {
	if (tree.size() == k) return 0;

	int t1, t2;

	t1 = pushbox(), t2 = push2();

	// std::cout << t1 << " " << t2 << "\n";

	if (t1 == -1 && t2 == -1) {
		return -1;
	}
	
	//  如果该松枝为空 直接插	
	if (tree.size() == 0) {	
		if (t1 != -1) {
			tree.push_back(t1);
			if (t2 != -1) s1.push(t2);
		} else {
			tree.push_back(t2);
		}
		return 1;
	}

	// 盒子为空的情况
	if (t1 == -1) {
		// 先判断一下盒子是否已经满了
		if (box.size() == m) return	0;
		while (t2 != -1 && t2 > tree.back()) {
			box.push(t2);
			// 盒子满了
			if (box.size() == m) return	0;
			t2 = push2();
		}
		
		if (t2 == -1) {
			return 0;
		} else {
			tree.push_back(t2);
			return 1;
		}
	}

	// 盒子头部不满足
	if (t1 > tree.back()) {
		// 先把盒子里面的放回去
		box.push(t1);
		// 先判断一下盒子是否已经满了
		if (box.size() == m) return	0;
		while (t2 != -1 && t2 > tree.back()) {
			box.push(t2);
			// 盒子满了
			if (box.size() == m) return	0;
			t2 = push2();
		}
				
		if (t2 == -1) {
			return 0;
		} else {
			tree.push_back(t2);
			return 1;
		}
	}

	// 盒子头部满足
	tree.push_back(t1);
	if (t2 != -1) s1.push(t2);
	return 1;
}

void out() {
	for (int i = 0; i < tree.size(); i ++) {
		std::cout << tree[i] << " \n"[i == (int) tree.size() - 1];
	}
	tree.clear();
}

int main() {
	std::cin >> n >> m >> k;

	std::vector<int> arr1(n);

	for (auto &x: arr1) {
		std::cin >> x;
	}

	for (int i = n - 1; i >= 0; i --) {
		s1.push(arr1[i]);	
	}

	while (true) {
		int k = act();
		if (k == 0) {
			out();
		} else if (k == -1) {
			break;
		}
	}

	out();
}