#include <iostream>

using namespace std;


int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (c < a && d < a) {
        printf("%d-N %d-N\n", c, d);
		cout << "zhang da zai lai ba";
	} else if (c < a || d < a) {
		if (c < a && d < b) {
            printf("%d-N %d-Y\n", c, d);
			cout << "2:" << " huan ying ru guan";
		} else if (d < a && c < b){
            printf("%d-Y %d-N\n", c, d);
			cout << "1:" << " huan ying ru guan";
		} else if ((c < a && d >= b) || (d < a && c >= b)) {
            printf("%d-Y %d-Y\n", c, d);
			if ((c < a && d >= b)) {
				cout << "qing 2 zhao gu hao 1";
			} else {
				cout << "qing 1 zhao gu hao 2";
			}
		} 
	} else {
        printf("%d-Y %d-Y\n", c, d);
		cout << "huan ying ru guan";
	}
}