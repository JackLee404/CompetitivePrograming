#include <cstdio>
#include <iostream>
#include <cstdlib>
#define maxn 10100
#define ERROR -1

using namespace std;



struct LinkNode{
    int data;
    LinkNode *next;
};

/*
    540

    3a0
*/

typedef LinkNode* PtrNode;

void insert(PtrNode &L, int data) {
    PtrNode t = new LinkNode;

    t->data = data;
    t->next = L;

    L = t;
}


int main() {
    int n;

    cin >> n;

    PtrNode head = NULL;

    for (int i = 1; i <= n; i ++) {
        int x;

        cin >> x;

        insert(head, x);
    }

    PtrNode t = head;

    while (t != NULL) {
        cout << t->data << " Address:" << t << "\n";
        t = t->next;
    }
}

