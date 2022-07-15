/*
      It's valuable to know that something your data range is in the range of C, but the mid of the action may be run out!
      The first program will be run out of integer while cal n = 25, m = 12 even though the ans = 5200300
      So, sometimes you shoud find the way of cal that  donesn't run out!
*/
#include <iostream>

using namespace std;

long long factorial(int n){
        long long res = 1;
        for (int i = 1; i <= n; i ++){
                res *= i;
        }
        return res;
}


long long cal(int n, int m){
        return factorial(n) / (factorial(n - m) * factorial(m));
}


int main(){
        int n, m;
        cin >> n >> m;
        cout << cal(n, m);
}    

// second
/*
   
*/
#include <iostream>

using namespace std;
const long long MOD = 1e10;
long long factorial(int n){
        long long res = 1;
        for (int i = 1; i <= n; i ++){
                res *= i;
        }
        return res;
}


long long cal(int n, int m){
	long long a = 1;
	if (m < n - m) m = n - m;
    for (int i = m + 1; i <= n; i ++)
   		a *= i;
   	for (int i = 1; i <= n - m; i ++)
   		a /= i;
   	return a;
}


int main(){
        int n, m;
        cin >> n >> m;
        cout << cal(n, m);
}                                                                      
