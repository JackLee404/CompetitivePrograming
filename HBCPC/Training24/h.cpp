#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int mid[50], post[50], n;

typedef struct node {
    int data;
    struct node *lc, *rc;
}BiTree;

void rebuild(int mid[], int post[], int len, BiTree* &root) {
	if (len <= 0 || !mid || !post) return;
	int left;
	for (left = 0; left < len; left ++) {
		if (mid[left] == post[len - 1]) break;	
	}
	if (left >= len) return;
	root = new BiTree;
	root->data = mid[left], root->lc = root->rc = NULL;
	rebuild(mid, post, left, root->lc);
	rebuild(mid + left + 1, post + left, len - left - 1, root->rc);
}

int main() {
	int cnt = 0;
    auto bfs = [](BiTree *p) {
        queue<BiTree*> q1;
        q1.push(p);
       	cout << p << " \n"[++cnt == n];
        while (q1.size()) {
            auto t = q1.front(); q1.pop();
            if (t->lc) q1.push(t->lc);
            if (t->rc) q1.push(t->rc);
        }
    };
    cin >> n;
    for (int i = 0; i < n; i ++) {
    	cin >> mid[i];
    }
    for (int i = 0; i < n; i ++) {
    	cin >> post[i];
    }
    BiTree* root;
    rebuild(mid, post, n, root);
    bfs(root);
}