#include <iostream>

using namespace std;

int main()
{
	int power = 10000;
	int time = 0;
	int key = 1;
	while(power > 0)
	{
		if(key % 2 != 0)
		{
			power -= 600;
			time++;
		}
		else if(key % 2 == 0)
		{
			power += 300;
			time++;
		}
		key++;
	}
	cout << time * 60 <<endl;
	return 0;
 } 

// ————————————————
// 版权声明：本文为CSDN博主「passer__jw767」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/passer__jw767/article/details/110578518