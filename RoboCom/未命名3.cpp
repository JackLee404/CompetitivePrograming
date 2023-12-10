#include <bits/stdc++.h>

using namespace std; 

// desc Ϊ true ʱ ���򣬷��� ���� 
void sort1(vector<int> &v, bool desc) {
	int len = v.size();

	for (int i = 0; i < len - 1; i ++) {
		int maxId = 0, minId = 0;
		
		for (int j = 0; j < len - i; j ++) {
			if (v[j] > v[maxId]) {
				maxId = j;
			}
			
			if (v[j] < v[minId]) {
				minId = j;
			}
		}
		
		// ��Ϊ����͵����ŵ������޷��ǽ����������ֵ������Сֵ, ����������һ������desc�����ǵ����Ż���������
		if (desc) {
			swap(v[len - i - 1], v[minId]);
		} else {
			swap(v[len - i - 1], v[maxId]);
		}
	}
}

int main() {
	int n;
	
	cin >> n;
	
	vector<int> even, odd;
	
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		
		// x % 2 ����0 ���ʾΪ���� ����Ϊż�� 
		if (x % 2) odd.push_back(x);
		else even.push_back(x);
	}
	
	sort1(odd, true);
	sort1(even, false);
	
	for (int i = 0; i < odd.size(); i ++) {
		cout << odd[i] << " \n"[i == odd.size() - 1];
	}
	
	for (int i = 0; i < even.size(); i ++) {
		cout << even[i] << " \n"[i == even.size() - 1];
	}
} 
