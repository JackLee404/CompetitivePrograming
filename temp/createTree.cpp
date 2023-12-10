#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef struct node {
    int data;
    struct node *lc, *rc;
}BiTree;

int dep[100000];

// 根据后序和中序建立一颗二叉树
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
    int mid[7], post[7], last = 1;
    auto bfs = [&last](BiTree *p) {
        queue<BiTree*> q1;
        q1.push(p), dep[p->data] = 1;
        while (q1.size()) {
            auto t = q1.front(); q1.pop();
            if (dep[t->data] != last) {
                last = dep[t->data];
                cout << "\n";
            }
            cout << t->data << " ";
            if (t->lc) q1.push(t->lc), dep[t->lc->data] += dep[t->data] + 1;
            if (t->rc) q1.push(t->rc), dep[t->rc->data] += dep[t->data] + 1;
        }
    };
    for (int i = 0; i <= 6; i ++) {
        cin >> post[i];
    }
    for (int i = 0; i <= 6; i ++) {
        cin >> mid[i];
    }
    BiTree* root;
    rebuild(mid, post, 7, root);
    bfs(root);
}