#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef struct node {
	int data;
	struct node *lc, *rc;
}biTree;

biTree *root = NULL;
int dep[30], rs[30], ls[30], mxdep;


void rebuild(int *inlist,int *postlist,int n,biTree **t)
{
	if(!inlist || !postlist || n<=0 )		
		return;
	int i;

	for(i = 0; i < n; i++)
	{
		if(inlist[i] == postlist[n-1])			
			break;					 
	} 
	
	if(i>=n)
		return;
	
	*t = (biTree*)malloc(sizeof(biTree));
	if(!t)
		return;
	(*t)->lc = (*t)->rc = NULL;
	(*t)->data = postlist[n-1];
	rebuild(inlist,postlist,i,&(*t)->lc); 				
	rebuild(inlist+i+1,postlist+i,n-i-1,&(*t)->rc);			 
}

void bfs() {
	biTree *p = root;
	queue<biTree*> q1; q1.push(p);
	dep[p->data] = 1, ls[1] = p->data, rs[1] = p->data;
	while (q1.size()) {
		biTree* t = q1.front(); q1.pop();
		cout << t->data << "\n";
		if (p->lc) {
			q1.push(t->lc), dep[t->lc->data] = dep[t->data] + 1;
			if (!ls[dep[t->lc->data]]) ls[dep[t->lc->data]] = t->lc->data;
			ls[dep[t->lc->data]] = t->lc->data;
			mxdep = max(dep[t->data] +1, mxdep);
		}
		if (p->rc) {
			q1.push(t->rc), dep[t->lc->data] = dep[t->data] + 1;
			if (!rs[dep[t->rc->data]]) rs[dep[t->rc->data]] = t->rc->data;
			rs[dep[t->rc->data]] = t->rc->data;
			mxdep = max(dep[t->data] +1, mxdep);
		}
	}
}


int main() {
	int n, a[30], b[30]; cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int j = 0; j < n; j ++) {
		cin >> b[j];
	}
	rebuild(a, b, n, &root);

	bfs();

	cout << "R:";
	for (int i = 1; i <= mxdep; i ++) {
		cout << " " << ls[i];
	}
	cout << "L:";
	for (int i = 1; i <= mxdep; i ++) {
		cout << " " << rs[i];
	}
}