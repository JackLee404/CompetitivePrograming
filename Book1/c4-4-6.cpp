#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cctype>
// #define LOCAL
#define F(i, j, k) for (int i = j; i <= k; ++ i)
#define F1(i, j, k) for (int i = j; i >= k; -- i)

using namespace std;

const int maxn = 100;
const char message[200] = "Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n";
const char pattern[6][20] = {"", "Chinese", "Mathematics", "English", "Programming", "Overall:"};

int cnt, cnt2, ranks[maxn];

struct node{
        long long sid;
        int cid, sum;
        char name[21];
        int score[5];
        double ave;
        bool have = false;
}d[maxn], d2[maxn];

bool cmp(node a, node b){
        if (!a.have || !b.have){
                a.have > b.have;
        }
        else {
                a.ave > b.ave;
        }
        return true;
}

void search(int type, char target[]){
        if (isupper(target[0])){
                F(i, 1, cnt){
                        if (strcmp(d[i].name, target) == 0 && d[i].have){
                                if (type == 1)
                                cnt2 ++, d[i].have = false;
                                else {
                                        printf("%d %010lld %d %s %d %d %d %d %d %.2lf\n", ranks[i], d[i].sid, d[i].cid, d[i].name, d[i].score[1], d[i].score[2], d[i].score[3], d[i].score[4], d[i].sum, d[i].ave);
                                }
                        }
                }
        }
        else {
                int num = atoi(target);
                F(i, 1, cnt){
                        if (d[i].sid == num && d[i].have){
                                if (type == 1)
                                cnt2 ++, d[i].have = false;
                                else {
                                        printf("%d %010lld %d %s %d %d %d %d %d %.2lf\n", ranks[i], d[i].sid, d[i].cid, d[i].name, d[i].score[1], d[i].score[2], d[i].score[3], d[i].score[4], d[i].sum, d[i].ave);
                                }
                        }
                }
        }
}

void del(char target[]){
        search(1, target);
        printf("%d student(s) removed.\n", cnt2);
}

void init(){
        memset(ranks, 0, sizeof(ranks));
        memcpy(d2, d, sizeof(d));
        sort(d2 + 1, d2 + 1 + cnt, cmp);
        int last = -1, cnt3 = 1;
        F(i, 1, cnt){
                if (d2[i].have == false){
                        break;
                }
                else {
                        if (last == -1) last = i;
                   		else if (d[last].ave != d[i].ave) cnt3 ++, last = i;
                        ranks[i] = cnt3;
                }
        }
}

void query(char target[]){
        init();
        search(0, target);
}

void show(int cid){
        double ave[5];
        int ok[5], fail[5], cnt3 = 0, tot[5];
        F(i, 0, 4) ok[i] = 0, fail[i] = 0, tot[i] = 0, ave[i] = 0;
        F(i, 1, cnt){
        		if (d[i].have == 0) continue;
                if (d[i].cid != cid && cid != 0) continue;
                int cnt4 = 0;
                F(j, 1, 4){
                        d[i].score[j] >= 60 ? ok[j] ++, cnt4 ++ : fail[j] ++;
                        ave[j] += d[i].score[j];
                }
                F(i, 1, 4){
                        if (cnt4 >= i) tot[i] ++;
                }
                if (cnt4 == 0) tot[0] ++;
                cnt3 ++;
        }
        F(i, 1, 4) {
        	if (cnt3 == 0)
        	ave[i] = 0;
        	else
        	ave[i] /= cnt3 * 1.0;
        }
        F(i, 1, 4){
                puts(pattern[i]);
                printf("Average Score: %.2lf\n", ave[i]);
                printf("Number of passed students: %d\n", ok[i]);
                printf("Number of failed students: %d\n", fail[i]);
                puts("");
        }
        puts(pattern[5]);
        F(i, 0, 4){
                if(4 - i == 4)  printf("Number of students who passed all subjects: %d\n", tot[4 - i]);
                else if (4 - i == 0) printf("Number of students who failed all subjects: %d\n", tot[4 - i]);
                else printf("Number of students who passed %d or more subjects: %d\n", 4 - i, tot[4 - i]);
        }
        puts("");
}

int main(){
        #ifdef LOCAL
                freopen("data.in", "r", stdin);
                freopen("data.out", "w", stdout);
        #endif
        int num;
        puts(message);
        while (scanf("%d", &num) == 1 && num){
                if (num == 1){
                        puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
                        while (cin >> d[++cnt].sid && d[cnt].sid){
                                int sum = 0;
                                bool check = false;
                                F(i, 1, cnt - 1) {
                                        if (d[cnt].sid == d[i].sid) check = true;
                                }
                                cin >> d[cnt].cid >> d[cnt].name >> d[cnt].score[1] >> d[cnt].score[2] >> d[cnt].score[3] >> d[cnt].score[4];
                                if (check == true){
                                        puts("Duplicated SID."), -- cnt;
                                        puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
                                        continue;
                                }
                                F(i, 1, 4) sum += d[cnt].score[i];
                                d[cnt].ave = sum / 4.0, d[cnt].sum = sum;
                                d[cnt].have = true;
                                puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
                        }
                        cnt --;

                }
                else if (num == 2){
                        cnt2 = 0;
                        puts("Please enter SID or name. Enter 0 to finish.");
                        char target[25];
                        while (cin >> target){
                                if (!isupper(target[0]) && atoi(target) == 0) break;
                                del(target);
                                puts("Please enter SID or name. Enter 0 to finish.");
                        }
                } else if(num == 3){
                        puts("Please enter SID or name. Enter 0 to finish.");
                        char target[25];
                        while (cin >> target){
                                if (!isupper(target[0]) && atoi(target) == 0) break;
                                query(target);
                                puts("Please enter SID or name. Enter 0 to finish.");
                        }
                } else if (num == 4){
                        puts("Showing the ranklist hurts students’ self-esteem. Don’t do that.");
                } else if (num == 5){
                        puts("Please enter class ID, 0 for the whole statistics.");
                        int cid;
                        cin >> cid;
                        show(cid);
                }
                puts(message);
        }
        return 0;
}

\\ new code

#include <bits/stdc++.h>

#define F(i, j, k) for(int i = j; i <= k; ++ i)
using namespace std;

const int N = 500;
const string text[8] = {"Chinese", "Mathematics", "English", "Programming", "Overall:", "Please enter the SID, CID, name and four scores. Enter 0 to finish.", "Please enter SID or name. Enter 0 to finish."};

int tot, total_ave[N];

struct node{
	string sid, cid, name;
	int score[4], sum = 0, rank = 0;
	double ave = 0.0;
	bool exist = false;
}a[N], b[N];

void print_menu(){
	cout << "Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n" << endl;
}

bool cmp(node a, node b){
	if (!a.exist || !b.exist){
		return a.exist > b.exist;
	}
	else{
		return a.sum > b.sum;
	}
}

void calc_rank(){
	memcpy(b, a, sizeof(a));
	sort(b, b + tot, cmp);
	int num = 0, last = 0;
	F(i, 0, tot){
		if (b[i].exist == false) continue;
		if (b[i].sum != b[last].sum) last = i, num ++;
		b[i].rank = num;
	}
}

void out_put(int i){
	calc_rank();
	cout << b[i].sid << " " << b[i].cid << " " << b[i].name;
	F(j, 0, 3) cout << " " << b[i].score[j] << " " << b[i].sum;
	printf(" %.2lf\n", b[i].ave);
}

bool inputs(int i){
	cin >> a[i].sid;
	if (a[i].sid == "0") return false;
	cin >> a[i].cid >> a[i].name;
	F(j, 0, 3) cin >> a[i].score[j], a[i].sum += a[i].score[j];
	if (a[i].sum > 0) a[i].ave = a[i].sum / 4.0;
	a[i].exist = true;
	return true;
}

bool check_out(string sid){
	F(i, 0, tot - 1){
		if (a[i].exist == true && a[i].sid == sid) return true;
	}
	return false;
}

void add_fuc(){
	while(true){
		cout << text[6] << endl;
		if (inputs(tot) == false){
			tot --;
			break;
		}
		if (check_out(a[tot].sid)) tot --, cout << "Duplicated SID." << endl;
		tot ++;
	}
}

void remove_fuc(){
	int cnt;
	while(true){
		cout << text[7] << endl;
		cnt = 0;
		string t;
		cin >> t;
		if (t == "0") break;
		F(i, 0, tot){
			if (isupper(t[0]) && a[i].exist && a[i].name == t) a[i].exist = false, cnt ++;
			else if (a[i].exist && a[i].name == t) a[i].exist = false, cnt ++;
		}
		printf("%d student(s) removed.\n", cnt);
	}
}

void query_fuc(){
	while (true){
		cout << text[7] << endl;
		string t;
		cin >> t;
		if (t == "0") break;
		F(i, 0, tot){
			if (isupper(t[0]) && a[i].exist && a[i].name == t) out_put(i);
			else if(a[i].exist && a[i].sid == t) out_put(i);
		}
	}
}

void show_fuc(){
	double ave[4];
	int tot[4], tot2;
	F(i, 0, 3)  tot[i] = 0, ave[i] = 0;
	F(i, 0, tot){
		if (a[i].exist == false) continue;
		F(j, 0, 3){
			ave[j] += a[i].score[j];
			if (a[i].score[j] >= 60) tot[j] ++;
		}
	}
}


int main(){
	for (;;){
		print_menu();
		int n;
		cin >> n;
		if (!n) break;
		if (n == 1) add_fuc();
		else if(n == 2) remove_fuc();
		else if(n == 3) query_fuc();
		else if(n == 4) cout << "Showing the ranklist hurts students’ self-esteem. Don’t do that." << endl;
		else if(n == 5) show_func();
	}
}
